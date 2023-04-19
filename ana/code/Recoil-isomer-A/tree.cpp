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
			// find the time range
			auto iCTmp = mClover.find(cloverTmp.t/DeltaT);
			if(iCTmp == mClover.end()) //Do not find the range make a new one
			{
				mData mDataTmp;
				mDataTmp.clear();
				mDataTmp.insert(std::pair<Long64_t, Data>(cloverTmp.t, cloverTmp));
				mClover.insert(std::pair<Long64_t, mData>(cloverTmp.t/DeltaT, mDataTmp));
			}
			else // // Do find the range, insert it
				iCTmp ->second.insert(std::pair<Long64_t, Data>(cloverTmp.t, cloverTmp));
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
			auto iPTmp = mPGeX.find(pgexTmp.t/DeltaT);
			if(iPTmp== mPGeX.end())
			{
				mData mDataTmp;
				mDataTmp.clear();
				mDataTmp.insert(std::pair<Long64_t, Data>(pgexTmp.t, pgexTmp));
				mPGeX.insert(std::pair<Long64_t, mData>(pgexTmp.t/DeltaT, mDataTmp));
			}
			else
				iPTmp ->second.insert(std::pair<Long64_t, Data>(pgexTmp.t, pgexTmp));
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


void tree::Loop(TTree *opt_, Int_t run_)
{
	time_t begin = clock(), end;
	if (opt_ == NULL)
	{
		std::cout << "\033[31m void tree::Loop(TTree *opt_, Int_t run_): Cannot get the output tree! \033[0m" << std::endl;
		return;
	}
	opt = opt_;
	run = run_;
	BranchOpt();
	std::cout << "making recoil/decay evnts..." << std::endl;
	GetEvent();
	Long64_t us = 1000;
	Long64_t ms = 1000 * us;
	Long64_t sec = 1000 * ms;
	irecoil = 0;
	std::cout << "recoil-decay correlation using Method B ..." << std::endl;
	for (auto ir = mr.begin(); ir != mr.end(); ir++)
	{//recoil
		rts = ir->second.ts;
		rx = ir->second.x;
		ry = ir->second.y;
		rxe = ir->second.xe;
		rye = ir->second.ye;
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

		flag = ir->second.flag;

		rxData.assign(ir->second.xdata.begin(), ir->second.xdata.end());
		ryData.assign(ir->second.ydata.begin(), ir->second.ydata.end());

		// Recoil-gamma (Ge) prompt correlation  -680 ~ -300 ns
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
		//Recoil-gamma (Clover) delayed correlation -200ns ~ 10 us
		auto iC11 = mClover.lower_bound((ir->first - DelayedGammaTimeMin * us)/DeltaT);
		for (auto iC1 = iC11; iC1 != mClover.end(); iC1++)
		{
			if(iC1->first > ((ir->first - DelayedGammaTimeMin * us)/DeltaT + 1))
				break;
			auto iC22 = iC1->second.lower_bound(ir->first - DelayedGammaTimeMin * us);
			for(auto iC2 = iC22; iC2 != iC1->second.end(); iC2++)
			{
				if (iC2->first >= ir->first + DelayedGammaTimeMax * us)
					break;
				rCloverE.push_back(iC2->second.e);
				rCloverid.push_back(iC2->second.id);
				rCloverts.push_back(iC2->second.t);
			}
		}
		//Recoil-gamma (PGeX) delayed correlation -200ns ~ 10us
		auto iP11 = mPGeX.lower_bound((ir->first - DelayedGammaTimeMin * us)/DeltaT);
		for(auto iP1 = iP11; iP1 != mPGeX.end(); iP1++)
		{
			if(iP1->first > ((ir->first - DelayedGammaTimeMin * us)/DeltaT + 1))
				break;
			auto iP22 = iP1->second.lower_bound(ir->first - DelayedGammaTimeMin * us);
			for(auto iP2 = iP22; iP2 != iP1->second.end(); iP2++)
			{
				if (iP2->first >= ir->first + DelayedGammaTimeMax * us)
					break;
				rPgeXE.push_back(iP2->second.e);
				rPgeXid.push_back(iP2->second.id);
				rPgeXts.push_back(iP2->second.t);
			}
		}
		//search next recoil in the same pixel
		auto ir1 = mr.upper_bound(ir->first);
		while (ir1 != mr.end())
		{
			double delx = abs(ir->second.x - ir1->second.x);
			double dely = abs(ir->second.y - ir1->second.y);
			if (delx < PositionDetx && dely < PositionDety)
			{
				break;
			}
			ir1++;
		}
		//decay events
//		auto id = md.upper_bound(ir->first);
		Long64_t twindow1 = -10E9;
		Long64_t twindow2 = 10E9;
		auto id = md.lower_bound(ir->first + twindow1);
		Long64_t t0 = 0;
		idecay = 0;
		while (id != md.end())
		{
			// the decay befor next recoil in the same pixel
	//		if (id->first > ir1->first)
			if (id->first > ir->first + twindow1)
				break;
			if(idecay>0)
			{
				rxData.clear();
				ryData.clear();
//				rGe.clear();
				rGeE.clear();
				rGeid.clear();
				rGets.clear();

//				rClover.clear();
				rCloverE.clear();
				rCloverid.clear();
				rCloverts.clear();

//				rPgeX.clear();
				rPgeXE.clear();
				rPgeXid.clear();
				rPgeXts.clear();

//				rPgeY.clear();
				rPgeYE.clear();
				rPgeYid.clear();
				rPgeYts.clear();
			}

			double delx = abs(id->second.x - ir->second.x);
			double dely = abs(id->second.y - ir->second.y);
			if (delx > PositionDetx || dely > PositionDety)
			{
				id++;
				continue;
			}
			//decay
			dts = id->second.ts;
			dx = id->second.x;
			dy = id->second.y;
			dxe = id->second.xe;
			dye = id->second.ye;
			dxData.clear();
			dyData.clear();
	//		dClover.clear();
			dCloverE.clear();
			dCloverid.clear();
			dCloverts.clear();

	//		dPgeX.clear();
			dPgeXE.clear();
			dPgeXid.clear();
			dPgeXts.clear();

//			dPgeY.clear();
			dPgeYE.clear();
			dPgeYid.clear();
			dPgeYts.clear();

			for(int i=0; i<id->second.clover.size(); i++)
			{
				dCloverE.push_back(id->second.clover.at(i).e);
				dCloverid.push_back(id->second.clover.at(i).id);
				dCloverts.push_back(id->second.clover.at(i).t);
			}
			for(int i=0; i<id->second.pgex.size(); i++)
			{
				dPgeXE.push_back(id->second.pgex.at(i).e);
				dPgeXid.push_back(id->second.pgex.at(i).id);
				dPgeXts.push_back(id->second.pgex.at(i).t);
			}
//			dPgeY.assign(id->second.pgey.begin(), id->second.pgey.end());
			for(int i=0; i<id->second.pgey.size(); i++)
			{
				dPgeYE.push_back(id->second.pgey.at(i).e);
				dPgeYid.push_back(id->second.pgey.at(i).id);
				dPgeYts.push_back(id->second.pgey.at(i).t);
			}
			if(idecay==0)
				tdecay = Double_t(id->first - ir->first) / Double_t(ms); //ms
			else
				tdecay = Double_t(id->first - t0) / Double_t(ms); //ms
			t0 = dts;
			opt->Fill();
			idecay++;
			id++;
		}
		irecoil++;
		if (irecoil % 500 == 0)
		{
			std::cout << TString::Format("Decay B: %.2f %%, %d / %ld\r", Double_t(irecoil) / mr.size() * 100.,
					irecoil, mr.size());
			std::cout << std::flush;
		}
	}
	std::cout << std::endl;
		end = clock();
		std::cout<<"Run time is "<<double(end - begin)<<" us    size = " <<rGeE.size() <<std::endl;
}

void tree::BranchOpt()
{
	opt->Branch("run", &run, "run/I");  //file
	opt->Branch("irecoil", &irecoil, "irecoil/I");
	opt->Branch("flag", &flag, "flag/I");
	opt->Branch("rts", &rts, "rts/L");
	opt->Branch("rGeE", &rGeE);
//	opt->Branch("rGeid", &rGeid);
	opt->Branch("rGets", &rGets);
	opt->Branch("rCloverE", &rCloverE);
//	opt->Branch("rCloverid", &rCloverid);
	opt->Branch("rCloverts", &rCloverts);
	opt->Branch("rPgeXE", &rPgeXE);
//	opt->Branch("rPgeXid", &rPgeXid);
	opt->Branch("rPgeXts", &rPgeXts);
//	opt->Branch("rPgeYE", &rPgeYE);
//	opt->Branch("rPgeYid", &rPgeYid);
//	opt->Branch("rPgeYts", &rPgeYts);

	opt->Branch("idecay", &idecay, "idecay/I");
	opt->Branch("tdecay", &tdecay, "tdecay/D");  //ms
	opt->Branch("dts", &dts, "dts/L");
	opt->Branch("dxe", &dxe, "dxe/D");
//	opt->Branch("dye", &dye, "dye/D");
}
