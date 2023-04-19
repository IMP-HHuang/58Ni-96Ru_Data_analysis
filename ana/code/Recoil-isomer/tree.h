#include <TTree.h>
#include <TFile.h>
#include <TCutG.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "par.h"
typedef struct Energy_
{
	Int_t id;
	Double_t e;
	Long64_t t;
} Energy;
typedef Energy Data;
typedef std::vector<Energy> Ge;
typedef std::vector<Energy> DSSD;
typedef std::multimap<Long64_t, Energy> mData;

typedef struct Imp 
{
	Int_t flag;
	Long64_t ts;		
	Double_t MWPC_e;
	Double_t MWPC_x1;
	Double_t MWPC_x2;
	Float_t x;
	Float_t y;
	Double_t xe;
	Double_t ye;
	DSSD xdata;
	DSSD ydata;
	Ge ge;
	Ge clover;
	Ge pgex;
	Ge pgey;
}Imp;
typedef struct Decay
{
	Long64_t ts;
	Float_t x;
	Float_t y;
	Double_t xe;
	Double_t ye;
	DSSD xdata;
	DSSD ydata;
	Ge clover;
	Ge pgex;
	Ge pgey;
}Decay;


class tree 
{
 public:

  	tree(TTree *ipt_);
	virtual ~tree();
	void GetBranch();   //SetBranchAddress
  	void Init();  
  	void InitEnergy(Data* data);
  	void InitImp(Imp* imp);
  	void InitDecay(Decay* decay);
	void StripCut(std::vector<Energy> &a);	
  	void Loop(TTree *opt_, Int_t run_);
  	void BranchOpt();
  	void GetEvent();


  	TTree *ipt;
  	TTree *opt;

	std::vector<Energy> xv;
	std::vector<Energy> yv;

	TCutG *cutEVR1;
	TCutG *cutEVR2;


	//output tree
  	Int_t run;
	Int_t irecoil;
	Int_t flag;
	Long64_t rts;
	Double_t rx;
	Double_t ry;
	Double_t rxe;
	Double_t rye;
	std::vector<Energy> rxData;
	std::vector<Energy> ryData;
	std::vector<Double_t> rGeE;
	std::vector<Int_t> rGeid;
	std::vector<Long64_t> rGets;
	std::vector<Double_t> rCloverE;
	std::vector<Int_t> rCloverid;
	std::vector<Long64_t> rCloverts;

	std::vector<Double_t> rPgeXE;
	std::vector<Int_t> rPgeXid;
	std::vector<Long64_t> rPgeXts;
	std::vector<Double_t> rPgeYE;
	std::vector<Int_t> rPgeYid;
	std::vector<Long64_t> rPgeYts;

	Int_t idecay;
	Double_t tdecay;
	Long64_t dts;
	Double_t dx;
	Double_t dy;
	Double_t dxe;
	Double_t dye;
	std::vector<Energy> dxData;
	std::vector<Energy> dyData;
	std::vector<Double_t> dCloverE;
	std::vector<Int_t> dCloverid;
	std::vector<Long64_t> dCloverts;
	std::vector<Double_t> dPgeXE;
	std::vector<Int_t> dPgeXid;
	std::vector<Long64_t> dPgeXts;
	std::vector<Double_t> dPgeYE;
	std::vector<Int_t> dPgeYid;
	std::vector<Long64_t> dPgeYts;

	Long64_t DeltaT;

	// analyze
	std::map<Long64_t, Imp> mr;//recoil
	std::map<Long64_t, Decay> md;//decay
	std::multimap<Long64_t, mData> mGe;
	std::multimap<Long64_t, mData> mClover;
	std::multimap<Long64_t, mData> mPGeX;
	std::multimap<Long64_t, mData> mPGeY;
	//  Input tree
	std::vector<Double_t> *tofEvent;
	Int_t NmeEvent;
	Double_t meEvent[1000];
	Long64_t mtEvent[1000];
	std::vector<Double_t> *mx1Event;
	std::vector<Double_t> *mx2Event;
	std::vector<Double_t> *my1Event;
	std::vector<Double_t> *my2Event;
	std::vector<Energy> *dxEvent;
	std::vector<Energy> *dyEvent;
	std::vector<Energy> *pinEvent;
	std::vector<Energy> *PGexEvent;
	std::vector<Energy> *PGeyEvent;
	std::vector<Energy> *CloverEvent;
	std::vector<Energy> *GeEvent;
};
