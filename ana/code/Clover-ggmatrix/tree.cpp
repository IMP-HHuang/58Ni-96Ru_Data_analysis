#include "tree.h"
#include "par.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include<time.h>

bool SortDS(const Data &a, const Data &b)
{
	return a.e > b.e;
}


tree::tree(TTree *ipt_)
{
	Init();
	DeltaT = 1000000000;
	ipt = ipt_;
	if(ipt == NULL)
	{
		std::cout << "\033[31mDon't have the iuput tree!\033[0m" << std::endl;
		return ;
	}
	GetBranch();

	cutEVR1 = new TCutG("cutEVR1", 21);
   	cutEVR1->SetPoint(0, 7319.34,  2173.58);
    cutEVR1->SetPoint(1, 7260.69,  2007.77);
	cutEVR1->SetPoint(2, 7234.62,  1893.78);
	cutEVR1->SetPoint(3, 7234.62,  1810.88);
	cutEVR1->SetPoint(4, 7195.52,  1479.27);
	cutEVR1->SetPoint(5, 7189,     1303.11);
	cutEVR1->SetPoint(6, 7208.55,  1132.12);
	cutEVR1->SetPoint(7, 7228.1,   919.689);
	cutEVR1->SetPoint(8, 7286.76,  748.705);
	cutEVR1->SetPoint(9, 7351.93,  717.617);
	cutEVR1->SetPoint(10, 7410.58, 759.067);
	cutEVR1->SetPoint(11, 7436.65, 831.606);
	cutEVR1->SetPoint(12, 7488.79, 940.414);
	cutEVR1->SetPoint(13, 7508.34, 1038.86);
	cutEVR1->SetPoint(14, 7508.34, 1334.2);
	cutEVR1->SetPoint(15, 7469.24, 1541.45);
	cutEVR1->SetPoint(16, 7456.2,  1707.25);
	cutEVR1->SetPoint(17, 7410.58, 1961.14);
	cutEVR1->SetPoint(18, 7378,    2132.12);
	cutEVR1->SetPoint(19, 7325.86, 2194.3);
	cutEVR1->SetPoint(20, 7319.34, 2173.58);

	cutEVR2 = new TCutG("cutEVR2",13);
   	cutEVR2->SetPoint(0,8208.41,774.611);
    cutEVR2->SetPoint(1,8165.38,551.813);
	cutEVR2->SetPoint(2,8165.38,354.922);
	cutEVR2->SetPoint(3,8215.58,240.933);
	cutEVR2->SetPoint(4,8301.64,194.3);
	cutEVR2->SetPoint(5,8373.35,266.839);
	cutEVR2->SetPoint(6,8394.87,463.731);
	cutEVR2->SetPoint(7,8351.84,665.803);
	cutEVR2->SetPoint(8,8265.78,867.876);
	cutEVR2->SetPoint(9,8222.75,805.699);
	cutEVR2->SetPoint(10,8222.75,748.705);
	cutEVR2->SetPoint(11,8215.58,748.705);
	cutEVR2->SetPoint(12,8208.41,774.611);

}
tree::~tree()
{}

void tree::StripCut(std::vector<Data> &a)
{
	for(auto it = a.begin(); it != a.end(); )
	{
		if(TMath::Abs(it->id - a[0].id) > 1)
			it = a.erase(it);
		else
			++it;
	}
}

void tree::Init()
{
	ipt = NULL;
	opt = NULL;
	xv.clear();
	yv.clear();
	cutEVR1 = NULL;
	cutEVR2 = NULL;

	run = -1;
	irecoil = -1;
	flag = -1;
	rts = -1;
	rx = -1.0;
	ry = -1.0;
	rxData.clear();
	ryData.clear();
	rGeE.clear();
	rGeid.clear();
	rGets.clear();
	rCloverE.clear();
	rCloverid.clear();
	rCloverts.clear();
	rPgeXE.clear();
	rPgeXid.clear();
	rPgeXts.clear();
	rPgeYE.clear();
	rPgeYid.clear();
	rPgeYts.clear();

	idecay = 0;
	tdecay = 0.0;
	dts = -1;
	dx = -1.0;
	dy = -1.0;
	dxe = -1.0;
	dye = -1.0;
	dxData.clear();
	dyData.clear();
	dCloverE.clear();
	dCloverid.clear();
	dCloverts.clear();
	dPgeXE.clear();
	dPgeXid.clear();
	dPgeXts.clear();
	dPgeYE.clear();
	dPgeYid.clear();
	dPgeYts.clear();

	mr.clear();
	md.clear();
	mGe.clear();
	mClover.clear();
	mPGeX.clear();
	//Initial the branchs of input tree
	tofEvent = NULL;
	NmeEvent = 0;
	mx1Event = NULL;
	mx2Event = NULL;
	my1Event = NULL;
	my2Event = NULL;
	dxEvent = NULL;
	dyEvent = NULL;
	pinEvent = NULL;
	PGexEvent = NULL;
	PGeyEvent = NULL;
	CloverEvent = NULL;
	GeEvent = NULL;
}

void tree::InitEnergy(Data* data)
{
	data->e = 0.0;
	data->id = -1;
	data->t = 0;
}

void tree::InitImp(Imp* imp)
{
	imp->flag = 0;
	imp->MWPC_e = 0.0;
	imp->MWPC_x1 = -1.0;
	imp->MWPC_x2 = -1.0;
	imp->x = -1.0;
	imp->y = -1.0;
	imp->xdata.clear();
	imp->ydata.clear();
	imp->ge.clear();
	imp->clover.clear();
	imp->pgex.clear();
	imp->pgey.clear();
}

void tree::InitDecay(Decay* decay)
{
	decay->x = -1.0;
	decay->y = -1.0;
	decay->xdata.clear();
	decay->ydata.clear();
	decay->clover.clear();
	decay->pgex.clear();
	decay->pgey.clear();
}

void tree::GetBranch()
{
	if(ipt == NULL)
	{
		std::cout << "\033[31mDon't have the iuput tree!\033[0m" << std::endl;
		return ;
	}
	ipt->SetBranchAddress("run", &run);
	ipt->SetBranchAddress("tof", &tofEvent);
	ipt->SetBranchAddress("Nme", &NmeEvent);
	ipt->SetBranchAddress("me", meEvent);
	ipt->SetBranchAddress("mt", mtEvent);
	ipt->SetBranchAddress("mx1", &mx1Event);
	ipt->SetBranchAddress("mx2", &mx2Event);
	ipt->SetBranchAddress("my1", &my1Event);
	ipt->SetBranchAddress("my2", &my2Event);
	ipt->SetBranchAddress("dx", &dxEvent);
	ipt->SetBranchAddress("dy", &dyEvent);
	ipt->SetBranchAddress("pin", &pinEvent);
	ipt->SetBranchAddress("PGex", &PGexEvent);
	ipt->SetBranchAddress("PGey", &PGeyEvent);
	ipt->SetBranchAddress("Clover", &CloverEvent);
	ipt->SetBranchAddress("Ge", &GeEvent);
}
void tree::GetEvent()
{
	mr.clear();
	md.clear();
	mGe.clear();
	mClover.clear();
	mPGeX.clear();
	Long64_t nentries = ipt->GetEntries();
	for (Long64_t jentry = 0; jentry < nentries; jentry++)
	{
		// Process
		if (jentry % 1000 == 0)
		{
			std::cout << TString::Format("Get Event : %.2f %%, %lldk / %lldk\r", Double_t(jentry) / nentries * 100.0,
					jentry / 1000, nentries / 1000);
			std::cout << std::flush;
		}
		ipt->GetEntry(jentry);
//		if(jentry > 1E6)	break;
		// make Ge map(map)
		for(int i=0; i<GeEvent->size(); i++)
		{
			Data GammaTmp;
			//threshold
			if(GeEvent->at(i).e < 20 || GeEvent->at(i).e > 1980) continue;
			// Get Ge information e id t
			InitEnergy(&GammaTmp);
			GammaTmp.e = GeEvent->at(i).e;
			GammaTmp.id = GeEvent->at(i).id;
			GammaTmp.t = GeEvent->at(i).t;
			// find the time range
			auto iGeTmp = mGe.find(GammaTmp.t/DeltaT);
			if(iGeTmp == mGe.end()) // Do not find the range make a new one
			{
				mData mDataTmp;
				mDataTmp.clear();
				mDataTmp.insert(std::pair<Long64_t, Energy>(GammaTmp.t, GammaTmp));
				mGe.insert(std::pair<Long64_t, mData>(GammaTmp.t/DeltaT, mDataTmp));
			}
			else // Do find the range, insert it
			{
				iGeTmp->second.insert(std::pair<Long64_t, Data>(GammaTmp.t, GammaTmp));
			}
		}
		// make Clover map
		for(int i=0; i<CloverEvent->size(); i++)
		{
			//threshold
			if(CloverEvent->at(i).e < 30 || CloverEvent->at(i).e>1980)	continue;
			//// Get Clover information e id t
			Data cloverTmp;
			InitEnergy(&cloverTmp);
			cloverTmp.e = CloverEvent->at(i).e;
			cloverTmp.id = CloverEvent->at(i).id;
			cloverTmp.t = CloverEvent->at(i).t;
			mClover.insert(std::pair<Long64_t, Data>(cloverTmp.t, cloverTmp));
		}
		// the same as Ge Clover
		for(int i=0; i<PGexEvent->size(); i++)
		{
			if(PGexEvent->at(i).e < 10 || PGexEvent->at(i).e > 480)	continue;
			Data pgexTmp;
			InitEnergy(&pgexTmp);
			pgexTmp.e = PGexEvent->at(i).e;
			pgexTmp.id = PGexEvent->at(i).id;
			pgexTmp.t = PGexEvent->at(i).t;
			mPGeX.insert(std::pair<Long64_t, Data>(pgexTmp.t, pgexTmp));
		}
		xv.clear();
		for(int i=0; i<dxEvent->size(); i++)
		{
			Data xtmp;
			InitEnergy(&xtmp);
			xtmp.e = dxEvent->at(i).e;
			xtmp.id = dxEvent->at(i).id;
			xtmp.t = dxEvent->at(i).t;
			xv.push_back(xtmp);
		}
		yv.clear();
		for(int i=0; i<dyEvent->size(); i++)
		{
			Data ytmp;
			InitEnergy(&ytmp);
			ytmp.e = dyEvent->at(i).e;
			ytmp.id = dyEvent->at(i).id;
			ytmp.t = dyEvent->at(i).t;
			yv.push_back(ytmp);
		}

		sort(xv.begin(), xv.end(), SortDS);
		sort(yv.begin(), yv.end(), SortDS);

		if (xv.size() == 0 || yv.size() == 0)
			continue;

#if(OpenTimeWindow)
		//DSSD x - y 时间关联
		for(auto it = yv.begin(); it != yv.end(); )
		{
			bool ber = false;
			ber = ((xv.at(0).t - it->t) < DtxyMin || (xv.at(0).t - it->t) > DtxyMax);
			if(ber)
				it = yv.erase(it);
			else
				++it;
		}
#endif
#if(OpenStripCut)
		StripCut(yv);
		StripCut(xv);
#endif
		if (xv.size() == 0 || yv.size() == 0)
			continue;
		
		//calculate x,y positions
		double x = -1.0;
		double y = -1.0;
		double xeid = 0.0;
		double xse = 0.0;
		for (int i = 0; i < xv.size(); i++)
		{
			xeid += double(xv.at(i).id) * xv.at(i).e;
			xse += xv.at(i).e;
		}
		x = xeid / xse;
		double yeid = 0.0;
		double yse = 0.0;
		for (int i = 0; i < yv.size(); i++)
		{
			yeid += double(yv.at(i).id) * yv.at(i).e;
			yse += yv.at(i).e;
		}
		y = yeid / yse;


		if (NmeEvent>0 && tofEvent->size()>0 && xse > Recoilxemin && xse < Recoilxemax)
		{//recoil
//		 	std::cout << " Recoil" << std::endl;
			Imp ImpTmp;
			InitImp(&ImpTmp);
			if(cutEVR2->IsInside(tofEvent->at(0), meEvent[0]))
				continue;
		//		ImpTmp.flag = 2;
			if(cutEVR1->IsInside(tofEvent->at(0), meEvent[0]))
				ImpTmp.flag = 1;
			ImpTmp.ts = xv.at(0).t;
			ImpTmp.MWPC_e = meEvent[0];
			ImpTmp.MWPC_x1 = mx1Event->at(0);
			ImpTmp.MWPC_x2 = mx2Event->at(0);
			#if(OpenCrosstalk)
				ImpTmp.x = x;
				ImpTmp.y = y;
				ImpTmp.xe = xse;
				ImpTmp.ye = yse;
			#endif
			#if(OpenOneEvent)
				ImpTmp.x = xv.at(0).id;
				ImpTmp.y = yv.at(0).id;
				ImpTmp.xe = xv.at(0).e;
				ImpTmp.ye = yv.at(0).e;
			#endif
			for(int i=0; i<xv.size(); i++)
			{
				ImpTmp.xdata.push_back(xv.at(i));
			}
			for(int i=0; i<yv.size(); i++)
			{
				ImpTmp.ydata.push_back(yv.at(i));
			}
			mr[xv.at(0).t] = ImpTmp;
		}
		
		if (NmeEvent==0  && xse > Decayxemin && xse < Decayxemax)
		{ //decay
			Decay DecayTmp;
			InitDecay(&DecayTmp);
			DecayTmp.ts = xv.at(0).t;
			#if(OpenCrosstalk)
				DecayTmp.x = x;
				DecayTmp.y = y;
				DecayTmp.xe = xse;
				DecayTmp.ye = yse;
			#endif
			#if(OpenOneEvent)
				DecayTmp.x = xv.at(0).id;
				DecayTmp.xe = xv.at(0).e;
				DecayTmp.ye = yv.at(0).e;
				DecayTmp.y = yv.at(0).id;
			#endif
			for(int i=0; i<xv.size(); i++)
			{
				DecayTmp.xdata.push_back(xv.at(i));
			}
			for(int i=0; i<yv.size(); i++)
			{
				DecayTmp.ydata.push_back(yv.at(i));
			}
				md[xv.at(0).t] = DecayTmp;
		}
	}
	std::cout << "The number of recoil/decay : " << mr.size() << "  " << md.size() << std::endl;
}


void tree::Loop(TFile *opf_, Int_t run_)
{
	time_t begin = clock(), end;
	if (opf_ == NULL)
	{
		std::cout << "\033[31m void tree::Loop(TTree *opf_, Int_t run_): Cannot get the output tree! \033[0m" << std::endl;
		return;
	}
	opf = opf_;
	run = run_;
	MakeHistogram();
	GetEvent();
	Long64_t us = 1000;
	Long64_t ms = 1000 * us;
	Long64_t sec = 1000 * ms;
	irecoil = 0;
	std::cout << "recoil-decay correlation using Method B ..." << std::endl;
/*
		auto iG11 = mGe.lower_bound((ir->first - 680)/DeltaT);
		for(auto iG1 = iG11; iG1 != mGe.end(); iG1++)
		{
			if(iG1->first > ((ir->first - 680)/DeltaT + 1))
				break;
			auto iG22 = iG1->second.lower_bound(ir->first - 680);
			for (auto iG2 = iG22; iG2 != iG1->second.end(); iG2++)
			{
				if (iG2->first >= ir->first - 300)
					break;
				rGeE.push_back(iG2->second.e);
				rGeid.push_back(iG2->second.id);
				rGets.push_back(iG2->second.t);

			}

		}
*/
	//Make Clover g-g matrix
	Long64_t No = 0;
	Long64_t CloverTbegin = mClover.begin()->first;
	std::vector<Double_t> vCEvent;
	vCEvent.clear();
	for (auto iC = mClover.begin(); iC != mClover.end(); iC++)
	{
		if(iC->first > CloverTbegin + 100)
		{
			for(int i=0; i<vCEvent.size(); i++)
				for(int j=0; j<vCEvent.size(); j++)
				{
					if(i==j)	continue;
					if(abs(vCEvent[i]-511.0) < 3 && abs(vCEvent[j]-511.0) < 3)
						continue;
					hggClover->Fill(vCEvent[i], vCEvent[j]);
				}
			vCEvent.clear();
			CloverTbegin = iC->first;
		}
		vCEvent.push_back(iC->second.e);
		No++;
		if (No % 500 == 0)
		{
			std::cout << TString::Format("Clover: %.2f %%, %d / %ld\r", Double_t(No) / mClover.size() * 100.,
					No, mClover.size());
			std::cout << std::flush;
		}
	}
	//Make g-g matrix (PGeX)
	Long64_t PGeXTbegin = mPGeX.begin()->first;
	std::vector<Double_t> vPXEvent;
	vPXEvent.clear();
	No = 0;
	for (auto iP = mPGeX.begin(); iP!= mPGeX.end(); iP++)
	{
		if(iP->first > PGeXTbegin + 100)
		{
			for(int i=0; i<vPXEvent.size(); i++)
				for(int j=0; j<vPXEvent.size(); j++)
				{
					if(i==j)    continue;
					hggPGeX->Fill(vPXEvent[i], vPXEvent[j]);
				}
			vPXEvent.clear();
			PGeXTbegin = iP->first;
		}
		vPXEvent.push_back(iP->second.e);
		No++;
		if (No % 500 == 0)
		{
			std::cout << TString::Format("PGeX: %.2f %%, %d / %ld\r", Double_t(No) / mPGeX.size() * 100.,
					No, mPGeX.size());
			std::cout << std::flush;
		}
	}
	opf->cd();
	hggClover->Write();
	hggPGeX->Write();
		/*
		if (irecoil % 500 == 0)
		{
			std::cout << TString::Format("Decay B: %.2f %%, %d / %ld\r", Double_t(irecoil) / mr.size() * 100.,
					irecoil, mr.size());
			std::cout << std::flush;
		}
		*/
	//	end = clock();
	//	std::cout<<"Run time is "<<double(end - begin)<<" us    size = " <<rGeE.size() <<std::endl;
}

void tree::MakeHistogram()
{
	hggClover = new TH2D("hggClover", "hggClover", 2000, 0, 2000, 2000, 0, 2000);
	hggPGeX = new TH2D("hggPGeX", "hggPGeX", 500, 0, 500, 500, 0, 500);
}
