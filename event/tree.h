#include <TTree.h>
#include <TFile.h>
#include <TCutG.h>
#include <TVector.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "par.h"


typedef struct Data_
{
	Int_t det;
	Int_t id; 
	Double_t e;
	Long64_t t;
} Data;
typedef struct Energy_
{
	Int_t id; 
	Double_t e;
	Long64_t t;
} Energy;



class tree 
{
 public:

  	tree(TTree *ipt_);
	virtual ~tree();
	void GetBranch();   //SetBranchAddress
  	void Init();  
  	void InitData(Data* data);
	void InitEnergy(Energy* data);
	void InitEvent();
  	void Event(TTree *opt_, TFile *opf_, Int_t run_);
	void EndEvent();
  	void BranchOpt();
  	void GetEvent();

  	TTree *ipt;
  	TTree *opt;
	TFile *opf;

	Double_t GeP0[50];
	Double_t GeP1[50];
	Double_t GeP2[50];

	Double_t PGeYP0[50];
	Double_t PGeYP1[50];
	Double_t PGeYP2[50];

	Double_t CP0[50];
	Double_t CP1[50];
	Double_t CP2[50];

	Double_t Threx[DSSDxMargin1+1];

#if(OpenFrontBackCalibration)
	Double_t kx[DSSDxMargin1+1];
	Double_t bx[DSSDxMargin1+1];	
	Double_t ky[DSSDyMargin1+1];
	Double_t by[DSSDyMargin1+1];	
#endif


	// analyze
	std::multimap<Long64_t, Data> mdata; //detector

	//Event
	//output tree
  	Int_t run;
	std::vector<Double_t> EventTof;   //0
//	std::vector<Double_t> EventMWPCe; //1
	Int_t EventMWPCeCount;
	Double_t EventMWPCe[1000];
//	std::vector<Long64_t> EventMWPCt;
	Long64_t EventMWPCt[1000];
	std::vector<Double_t> EventMWPCx1;//2
//	Int_t EventMWPCx1Count;
//	Double_t EventMWPCx1[1000];
	std::vector<Double_t> EventMWPCx2;//3
	std::vector<Double_t> EventMWPCy1;//4
	std::vector<Double_t> EventMWPCy2;//5
//	Int_t EventMWPCy2Count;
//	Double_t EventMWPCy2[1000];
	std::vector<Energy> EventDSSDx;  // 6
//	Int_t EventDSSDxCount;
//	Energy EventDSSDx[1000];
	std::vector<Energy> EventDSSDy;  // 7
//	Int_t EventDSSDyCount;
//	Energy EventDSSDy[1000];
	std::vector<Energy> Eventpin; // 8
	std::vector<Energy> EventPGex;  //9
	std::vector<Energy> EventPGey; //10
	std::vector<Energy> EventClover; //11
	std::vector<Energy> EventGamma; //12

	//  Input tree
   	Long64_t        stamp;
   	Double_t        tof;
    Double_t        rate;
    Double_t        MWPC_e;
    Long64_t        MWPC_t;
    Double_t        MWPC_x1;
    Double_t        MWPC_x2;
    Double_t        MWPC_y1;
    Double_t        MWPC_y2;
	Bool_t          MWPC_fail;
    Double_t        DSSD_emax;
    Double_t        DSSD_xmax;
    Double_t        DSSD_ymax;
    Int_t           DSSD_xcount;
    Double_t        DSSD_xe[580];   //[DSSD_xcount]
    Double_t        DSSD_xoe[580];   //[DSSD_xcount]
    Int_t           DSSD_xid[580];   //[DSSD_xcount]
    Long64_t        DSSD_xt[580];   //[DSSD_xcount]
    Int_t           DSSD_ycount;
    Double_t        DSSD_ye[460];   //[DSSD_ycount]
    Double_t        DSSD_yoe[460];   //[DSSD_ycount]
    Int_t           DSSD_yid[460];   //[DSSD_ycount]
    Long64_t        DSSD_yt[460];   //[DSSD_ycount]
    Int_t           pin_count;
    Double_t        pin_e[100];   //[pin_count]
    Double_t        pin_oe[100];   //[pin_count]
    Int_t           pin_id[100];   //[pin_count]
    Long64_t        pin_t[100];   //[pin_count]
    Double_t        pge_emax;
    Double_t        pge_xmax;
    Double_t        pge_ymax;
    Int_t           pge_xcount;
    Double_t        pge_xe[240];   //[pge_xcount]
    Double_t        pge_xoe[240];   //[pge_xcount]
    Int_t           pge_xid[240];   //[pge_xcount]
    Long64_t        pge_xt[240];   //[pge_xcount]
    Int_t           pge_ycount;
    Double_t        pge_ye[120];   //[pge_ycount]
    Double_t        pge_yoe[120];   //[pge_ycount]
    Int_t           pge_yid[120];   //[pge_ycount]
    Long64_t        pge_yt[120];   //[pge_ycount]
    Int_t           clover_count;
    Double_t        clover_e[120];   //[clover_count]
    Double_t        clover_oe[120];   //[clover_count]
    Int_t           clover_id[120];   //[clover_count]
    Long64_t        clover_t[120];   //[clover_count]
    Double_t        clover_phi[120];   //[clover_count]
    Double_t        clover_theta[120];   //[clover_count]
    Int_t           clover_ring[120];   //[clover_count]
    Int_t           gamma_count;
    Double_t        gamma_eDop[100];   //[gamma_count]
    Double_t        gamma_e[100];   //[gamma_count]
    Double_t        gamma_oe[100];   //[gamma_count]
    Int_t           gamma_id[100];   //[gamma_count]
    Long64_t        gamma_t[100];   //[gamma_count]
    Double_t        gamma_phi[100];   //[gamma_count]
    Double_t        gamma_theta[100];   //[gamma_count]
    Int_t           gamma_ring[100];   //[gamma_count]
};
