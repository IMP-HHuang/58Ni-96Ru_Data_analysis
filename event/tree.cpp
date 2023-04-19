#include "tree.h"
#include "par.h"
#include "iostream"
#include "fstream"
#include "string.h"
#include <TRandom3.h>

bool SortDS(const Energy &a, const Energy &b)
{
	return a.e > b.e;
}


tree::tree(TTree *ipt_)
{
	Init();
	ipt = ipt_;
	if(ipt == NULL)
	{
		std::cout << "Don't have the iuput tree!" << std::endl;
		return ;
	}
	GetBranch();
	opt = NULL;
}
tree::~tree()
{}


void tree::Init()
{
	ipt = NULL;
	opt = NULL;
	opf = NULL;

	for(int i=0; i<50; i++)
	{
		GeP0[i] = 0.0;
		GeP1[i] = 0.0;
		GeP2[i] = 0.0;
	}
	std::ifstream ing("Ge.txt");
	std::string tmp;
 	if(ing.is_open())
 	{   
 		getline(ing, tmp);
        Double_t t0, t1, t2; 
 		Int_t   tid;
 		while((ing >> tid >> t0 >> t1 >> t2))
 		{
 			GeP0[tid] = t0; 
 			GeP1[tid] = t1; 
  	    	GeP2[tid] = t2; 
 		}  
	}   
	else
		std::cout <<"Cannot open Ge.txt" << std::endl;
    ing.close();
 //pge calibration 
	std::ifstream inp("PgeY.txt");
 	if(inp.is_open())
 	{   
 		getline(inp, tmp);
        Double_t t0, t1, t2; 
 		Int_t   tid;
 		while((inp >> tid >> t0 >> t1 >> t2))
 		{
 			PGeYP0[tid] = t0; 
 			PGeYP1[tid] = t1; 
  	    	PGeYP2[tid] = t2; 
 		}  
	}   
	else
		std::cout <<"Cannot open PgeY.txt" << std::endl;
    inp.close();

	//Clover calibration
	std::ifstream inc("Clover.txt");
 	if(inc.is_open())
 	{   
 		getline(inc, tmp);
        Double_t t0, t1, t2; 
 		Int_t   tid;
 		while((inc >> tid >> t0 >> t1 >> t2))
 		{
 			CP0[tid] = t0; 
 			CP1[tid] = t1; 
  	    	CP2[tid] = t2; 
 		}  
	}   
	else
		std::cout <<"Cannot open PgeY.txt" << std::endl;
    inc.close();
	
	InitEvent();
//	EventMWPCe = new std::vector<Double_t>();
#if(OpenFrontBackCalibration)
	for(int i=0; i<DSSDxMargin1+1; i++)
	{
		kx[i] = 0.0;
		bx[i] = 0.0;
	}
	for(int i=0; i<DSSDyMargin1+1; i++)
	{
		ky[i] = 0.0;
		by[i] = 0.0;
	}
	std::ifstream inx("parx.txt", std::ios::in);
	if(inx.is_open())
	{
		std::string tmp;
		Int_t tid;
		Double_t tk, tb;
		getline(inx, tmp);
		while(inx >> tid >> tk >> tb)
		{
			kx[tid] = tk;
			bx[tid] = tb;
		//	std::cout << tid <<"   " << tk << "  " <<tb << std::endl;
		}
	}
	else
		std::cout << "Can not open parx.txt" << std::endl;
	inx.close();
	std::ifstream iny("pary.txt");
	if(iny.is_open())
	{
		std::string tmp;
		getline(iny, tmp);
		Int_t tid;
		Double_t tk, tb;
		while(iny >> tid >> tk >> tb)
		{
			ky[tid] = tk;
			by[tid] = tb;
		}
	}
	else
		std::cout << "Can not open pary.txt" << std::endl;
	iny.close();
#endif

	run = -1;
}

void tree::InitData(Data* data)
{
	data->det = -1;
	data->id = -1;
	data->e = 0.0;
	data->t = 0;
}

void tree::InitEnergy(Energy* data)
{
	data->id = -1;
	data->e = 0.0;
	data->t = 0;
}

void tree::GetBranch()
{
	if (ipt == NULL)
		return;
   ipt->SetBranchAddress("stamp", &stamp);
   ipt->SetBranchAddress("tof", &tof);
   ipt->SetBranchAddress("MWPC_e", &MWPC_e);
   ipt->SetBranchAddress("MWPC_t", &MWPC_t);
   ipt->SetBranchAddress("MWPC_x1", &MWPC_x1);
   ipt->SetBranchAddress("MWPC_x2", &MWPC_x2);
   ipt->SetBranchAddress("MWPC_y1", &MWPC_y1);
   ipt->SetBranchAddress("MWPC_y2", &MWPC_y2);
   ipt->SetBranchAddress("MWPC_fail", &MWPC_fail);
   ipt->SetBranchAddress("DSSD_xcount", &DSSD_xcount);
   ipt->SetBranchAddress("DSSD_xe", DSSD_xe);
   ipt->SetBranchAddress("DSSD_xoe", DSSD_xoe);
   ipt->SetBranchAddress("DSSD_xid", DSSD_xid);
   ipt->SetBranchAddress("DSSD_xt", DSSD_xt);
   ipt->SetBranchAddress("DSSD_ycount", &DSSD_ycount);
   ipt->SetBranchAddress("DSSD_ye", DSSD_ye);
   ipt->SetBranchAddress("DSSD_yoe", DSSD_yoe);
   ipt->SetBranchAddress("DSSD_yid", DSSD_yid);
   ipt->SetBranchAddress("DSSD_yt", DSSD_yt);
   ipt->SetBranchAddress("pin_count", &pin_count);
   ipt->SetBranchAddress("pin_e", pin_e);
   ipt->SetBranchAddress("pin_oe", pin_oe);
   ipt->SetBranchAddress("pin_id", pin_id);
   ipt->SetBranchAddress("pin_t", pin_t);
   ipt->SetBranchAddress("pge_emax", &pge_emax);
   ipt->SetBranchAddress("pge_xmax", &pge_xmax);
   ipt->SetBranchAddress("pge_ymax", &pge_ymax);
   ipt->SetBranchAddress("pge_xcount", &pge_xcount);
   ipt->SetBranchAddress("pge_xe", pge_xe);
   ipt->SetBranchAddress("pge_xoe", pge_xoe);
   ipt->SetBranchAddress("pge_xid", pge_xid);
   ipt->SetBranchAddress("pge_xt", pge_xt);
   ipt->SetBranchAddress("pge_ycount", &pge_ycount);
   ipt->SetBranchAddress("pge_ye", pge_ye);
   ipt->SetBranchAddress("pge_yoe", pge_yoe);
   ipt->SetBranchAddress("pge_yid", pge_yid);
   ipt->SetBranchAddress("pge_yt", pge_yt);
   ipt->SetBranchAddress("clover_count", &clover_count);
   ipt->SetBranchAddress("clover_e", clover_e);
   ipt->SetBranchAddress("clover_oe", clover_oe);
   ipt->SetBranchAddress("clover_id", clover_id);
   ipt->SetBranchAddress("clover_t", clover_t);
   ipt->SetBranchAddress("clover_ring", clover_ring);
   ipt->SetBranchAddress("gamma_count", &gamma_count);
   ipt->SetBranchAddress("gamma_e", gamma_e);
   ipt->SetBranchAddress("gamma_oe", gamma_oe);
   ipt->SetBranchAddress("gamma_id", gamma_id);
   ipt->SetBranchAddress("gamma_t", gamma_t);
   ipt->SetBranchAddress("gamma_theta", gamma_theta);

}
void tree::GetEvent()
{
	Long64_t nentries = ipt->GetEntries();
//	nentries = 1E7;
	Data datatmp;
	TRandom3 *rand = new TRandom3(0);
	for (Long64_t jentry = 0; jentry < nentries; jentry++)
	{
		if (jentry % 1000 == 0)
		{
			std::cout << TString::Format("Process %.2f %%, %lldk / %lldk\r", Double_t(jentry) / nentries * 100.0,
					jentry / 1000, nentries / 1000);
			std::cout << std::flush;
		}
	//	if(jentry > 1E8) break;
		ipt->GetEntry(jentry);
		//pick tof --> 0
		InitData(&datatmp);
		if(tof > 0)
		{
			datatmp.det = 0;
			datatmp.e = tof;
			datatmp.t = stamp * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		// mwpc
		InitData(&datatmp);
		if(MWPC_e > 0 && !MWPC_fail) //MWPC_fail 超界
		{
			//mwpc e
			datatmp.det = 1;
			datatmp.e = MWPC_e;
	//		std::cout << " e " << MWPC_e <<std::endl;
			datatmp.t  = MWPC_t * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
			datatmp.det = 2;
			datatmp.e = MWPC_x1;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
			datatmp.det = 3;
			datatmp.e = MWPC_x2;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
			datatmp.det = 4;
			datatmp.e = MWPC_y1;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
			datatmp.det = 5;
			datatmp.e = MWPC_y2;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		//DSSD x
		for(int i=0; i<DSSD_xcount; i++)
		{
			InitData(&datatmp);
			datatmp.det = 6;
			datatmp.id = DSSD_xid[i];
			datatmp.e = kx[datatmp.id] * DSSD_xoe[i] + bx[datatmp.id];
#if(OpenEnergyCalibration)
			datatmp.e = datatmp.e * DSSD_ke + DSSD_be;
#endif
			datatmp.e = DSSD_xe[i];
			datatmp.t = DSSDxTime * DSSD_xt[i];
			if(datatmp.e < DSSDxETh)	continue;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		//DSSD y
		for(int i=0; i<DSSD_ycount; i++)
		{
			InitData(&datatmp);
			datatmp.det = 7;
			datatmp.id = DSSD_yid[i];
			datatmp.e = ky[datatmp.id] * DSSD_yoe[i] + by[datatmp.id];
#if(OpenEnergyCalibration)
			datatmp.e = datatmp.e * DSSD_ke + DSSD_be;
#endif
			datatmp.e = DSSD_ye[i];
			datatmp.t = DSSDyTime * DSSD_yt[i];
			if(datatmp.e < DSSDyETh)    continue;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		// Pin
		for(int i=0; i<pin_count; i++)
		{
			InitData(&datatmp);
			datatmp.det = 8;
			datatmp.id = pin_id[i];
			datatmp.e = pin_oe[i];
			datatmp.t = pin_t[i] * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		//PGe X
		for(int i=0; i<pge_xcount; i++)
		{
			InitData(&datatmp);
			datatmp.det = 9;
			datatmp.id = pge_xid[i];
			datatmp.e = pge_xe[i];
			datatmp.t = pge_xt[i] * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		//PGe Y
		for(int i=0; i<pge_ycount; i++)
		{
			InitData(&datatmp);
			datatmp.det = 10;
			datatmp.id = pge_yid[i];
			pge_yoe[i] = pge_yoe[i] + rand->Rndm()-0.5;
			if(datatmp.id==0 || datatmp.id==11)
				datatmp.e = pge_ye[i];
			else
				datatmp.e = PGeYP0[datatmp.id] + PGeYP1[datatmp.id]*pge_yoe[i] + PGeYP2[datatmp.id]*pge_yoe[i]*pge_yoe[i];
			datatmp.t = pge_yt[i] * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		// Clover
		for(int i=0; i<clover_count; i++)
		{
			InitData(&datatmp);
			datatmp.det = 11;
			datatmp.id = clover_id[i];
			clover_oe[i] = clover_oe[i] + rand->Rndm()-0.5;
			datatmp.e = CP0[datatmp.id] + CP1[datatmp.id]*clover_oe[i] + CP2[datatmp.id]*clover_oe[i]*clover_oe[i];
			datatmp.t = clover_t[i] * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
		for(int i=0; i<gamma_count; i++)
		{
			InitData(&datatmp);
			datatmp.det = 12;
			datatmp.id = gamma_id[i];
			gamma_oe[i] = gamma_oe[i] + rand->Rndm()-0.5;
			datatmp.e = GeP0[gamma_id[i]] + GeP1[gamma_id[i]]*gamma_oe[i] + GeP2[gamma_id[i]]*gamma_oe[i]*gamma_oe[i];
			datatmp.e = gamma_e[i];
			Double_t beta = 0.0345; //0.0335;//0.0376;
			Double_t tmptheta = gamma_theta[i]*3.14/180.0;
			datatmp.e = datatmp.e/((1.0 - beta * TMath::Cos(tmptheta))/TMath::Sqrt(1.0 - beta * beta));
	//		datatmp.e = datatmp.e*(1.0 - beta * TMath::Cos(tmptheta))/TMath::Sqrt(1.0 - beta * beta);
			//std::cout << tmptheta << std::endl;
			datatmp.t = gamma_t[i] * AllTime;
			mdata.insert(std::pair<Long64_t, Data>(datatmp.t, datatmp));
		}
	}
}

void tree::Event(TTree *opt_, TFile *opf_, Int_t run_)
{
	if (opt_ == NULL || opf_ == NULL)
		return;
	opt = opt_;
	opf = opf_;
	run = run_;
	BranchOpt();
	std::cout << "making  map of evnts..." << std::endl;
	GetEvent();

	Long64_t us = 1000;
	Long64_t ms = 1000 * us;
	Long64_t sec = 1000 * ms;

	std::cout << "Build event................" << std::endl;
	Long64_t ntrigger = 0;
	Long64_t tbegin = mdata.begin()->second.t;
	InitEvent();
	Energy Energytmp;
	for (auto id = mdata.begin(); id != mdata.end(); id++)
	{
		if(id->second.t - tbegin > EventWindow*us)
		{
			EndEvent();
			tbegin = id->second.t;
		}
		if(id->second.det == 0)
		{
			EventTof.push_back(id->second.e);
		}
		if(id->second.det == 1)
		{
		//	std::cout << "EventMWPCe.Size() :  " << EventMWPCe.size()  << std::endl;	

//			EventMWPCe.push_back(id->second.e);
			EventMWPCe[EventMWPCeCount] = id->second.e;
			EventMWPCt[EventMWPCeCount] = id->second.t;
			EventMWPCeCount++;
//			EventMWPCt.push_back(id->second.t);
						
		}
		if(id->second.det == 2)
		{
			EventMWPCx1.push_back(id->second.e);
	//		EventMWPCx1[EventMWPCx1Count] = id->second.e;
	//		EventMWPCx1Count++;
		}
		if(id->second.det == 3)
			EventMWPCx2.push_back(id->second.e);
		if(id->second.det == 4)
			EventMWPCy1.push_back(id->second.e);
		if(id->second.det == 5)
		{
		//	std::cout << id->second.e << "    y2" << std::endl;
			EventMWPCy2.push_back(Double_t(id->second.e));
	//		EventMWPCy2[EventMWPCy2Count] = id->second.e;
	//		EventMWPCy2Count++;
		}
		
		if(id->second.det > 5)
		{
			InitEnergy(&Energytmp);
			Energytmp.id = id->second.id;
			Energytmp.e = id->second.e;
			Energytmp.t = id->second.t;

			if(id->second.det==  6)
			{
				EventDSSDx.push_back(Energytmp);
//				EventDSSDx[EventDSSDxCount] = Energytmp;
//				EventDSSDxCount++;
			}
			if(id->second.det==  7)
			{
				EventDSSDy.push_back(Energytmp);
//				EventDSSDy[EventDSSDyCount] = Energytmp;
//				EventDSSDyCount++;
			}
			
			if(id->second.det==  8)
			{
					Eventpin.push_back(Energytmp);
			}
			
			if(id->second.det==  9)
			{
					EventPGex.push_back(Energytmp);
			}
			
			if(id->second.det==  10)
			{
					EventPGey.push_back(Energytmp);
			}
			
			if(id->second.det==  11)
			{
					EventClover.push_back(Energytmp);
			}
			if(id->second.det==  12)
			{
					EventGamma.push_back(Energytmp);
			}
		}
		
		ntrigger++;
		if (ntrigger % 1000 == 0)
		{
			std::cout << TString::Format("Process %.2f %%, %lldK / %uK\r", Double_t(ntrigger) / mdata.size() * 100.,
					ntrigger/1000, mdata.size()/1000);
			std::cout << std::flush;
		}
	}
	EndEvent();
	std::cout << std::endl;
}
void tree::InitEvent()
{
	EventTof.clear();
//	EventMWPCe.clear();
	EventMWPCeCount = 0;
	EventMWPCx1.clear();
//	EventMWPCx1Count = 0;
	EventMWPCx2.clear();
	EventMWPCy1.clear();
	EventMWPCy2.clear();
//	EventMWPCy2Count = 0;
//	EventMWPCt.clear();
	EventDSSDx.clear();
//	EventDSSDxCount = 0;
	EventDSSDy.clear();
//	EventDSSDyCount = 0;
	Eventpin.clear();
	EventPGex.clear();
	EventPGey.clear();
	EventClover.clear();
	EventGamma.clear();
}
void tree::EndEvent()
{
	//if((EventTof.size() + EventMWPCeCount + EventMWPCx1.size() + EventMWPCx2.size() + EventMWPCy1.size() + EventMWPCy2.size() + EventMWPCt.size() + EventDSSDx.size() + EventDSSDy.size() + Eventpin.size() + EventPGex.size() + EventPGey.size() + EventClover.size() + EventGamma.size()) > 0)
	if((EventTof.size() + EventMWPCeCount + EventMWPCx1.size() + EventMWPCx2.size() + EventMWPCy1.size() + EventMWPCy2.size() + EventDSSDx.size() + EventDSSDy.size() + Eventpin.size() + EventPGex.size() + EventPGey.size() + EventClover.size() + EventGamma.size()) > 0)
	{
		opf->cd();
		opt->Fill();
	}
	InitEvent();
}

void tree::BranchOpt()
{
	opt->Branch("run", &run, "run/I");  //file number
	opt->Branch("tof", &EventTof);  //tof
//	opt->Branch("me", &EventMWPCe);
	opt->Branch("Nme", &EventMWPCeCount, "Nme/I");
	opt->Branch("me", EventMWPCe, "me[Nme]/D");
	opt->Branch("mt", EventMWPCt, "mt[Nme]/L");
//	opt->Branch("mt", &EventMWPCt);
	opt->Branch("mx1", &EventMWPCx1);
//	opt->Branch("Nmx1", &EventMWPCx1Count, "Nmx1/I");
//	opt->Branch("mx1", EventMWPCx1, "mx1[Nmx1]/D");
	opt->Branch("mx2", &EventMWPCx2);
	opt->Branch("my1", &EventMWPCy1);
	opt->Branch("my2", &EventMWPCy2);
//	opt->Branch("Nmy2", &EventMWPCy2Count, "Nmy2/I");
//	opt->Branch("my2", EventMWPCy2, "my2[Nmy2]/D");
	opt->Branch("dx", &EventDSSDx);
//	opt->Branch("Ndx", &EventDSSDxCount, "Ndx/I");
//	opt->Branch("dx", EventDSSDx, "dx[Ndx]");
	opt->Branch("dy", &EventDSSDy);
//	opt->Branch("Ndy", &EventDSSDyCount, "Ndy/I");
//	opt->Branch("dy", EventDSSDy);
	opt->Branch("pin", &Eventpin);
	opt->Branch("PGex", &EventPGex);
	opt->Branch("PGey", &EventPGey);
	opt->Branch("Clover", &EventClover);
	opt->Branch("Ge", &EventGamma);
}
