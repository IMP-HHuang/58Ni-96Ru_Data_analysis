
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"

#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    if(argc != 2)
	{   
  		std::cout << "eg. ./xxx  [run number]" << std::endl;
        exit(1);
  	}   
	int run = atoi(argv[1]);
	auto ipf = new TFile(Form("../data/Recoil-isomer/Recoil%03d.root", run), "READ");
	auto ipt = (TTree*)ipf->Get("tree");

	//input data
	std::vector<double> *rGe, *rCe, *rPxE;
	std::vector<Long64_t> *rGts, *rCts, *rPxts;
	Int_t idecay;
	Double_t dxe =0.0;
	Double_t tdecay = 0.0;
	rGe = NULL;
    rCe = 0;
	rGts = 0;
	rCts = 0;
    rPxE = 0;
	rPxts = 0;
	idecay = 0;
	Long64_t rts;

	//Get branch
	ipt->SetBranchAddress("rts", &rts);
	ipt->SetBranchAddress("idecay", &idecay);
	ipt->SetBranchAddress("tdecay", &tdecay);
	ipt->SetBranchAddress("dxe", &dxe);
	ipt->SetBranchAddress("rGeE", &rGe);
	ipt->SetBranchAddress("rGets", &rGts);
	ipt->SetBranchAddress("rCloverE", &rCe);
	ipt->SetBranchAddress("rCloverts", &rCts);
	ipt->SetBranchAddress("rPgeXE", &rPxE);
	ipt->SetBranchAddress("rPgeXts", &rPxts);

	//output histgram
	
	TH1D *hCa = new TH1D("hCa", "hCa", 2000, 0, 2000);
	TH1D *hCb = new TH1D("hCb", "hCb", 2000, 0, 2000);
	TH1D *hC = new TH1D("hC", "hC", 2000, 0, 2000);
	TH2D *hggCa = new TH2D("hggCa", "hggCa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggCb = new TH2D("hggCb", "hggCb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggC = new TH2D("hggC", "hggC", 2000, 0, 2000, 2000, 0, 2000);

	TH1D *hPGeXa = new TH1D("hPGeXa", "hPGeXa", 1000, 0, 500);
	TH1D *hPGeXb = new TH1D("hPGeXb", "hPGeXb", 1000, 0, 500);
	TH1D *hPGeX = new TH1D("hPGeX", "hPGeX", 	1000, 0, 500);
	TH2D *hggPGeXa = new TH2D("hggPGeXa", "hggPGeXa", 1000, 0, 500, 1000, 0, 500);
	TH2D *hggPGeXb = new TH2D("hggPGeXb", "hggPGeXb", 1000, 0, 500, 1000, 0, 500);
	TH2D *hggPGeX = new TH2D("hggPGeX", "hggPGeX", 	  1000, 0, 500, 1000, 0, 500);


	TH2D *hggAll = new TH2D("hggAll", "hggAll", 2000, 0, 2000, 2000, 0, 2000);
	TH1D *hgAll = new TH1D("hgAll", "hgAll", 2000, 0, 2000);


	//152Yb
	
	Long64_t HalfLife = 30000;
	Long64_t tmin = 3000;
	Long64_t tmax = HalfLife*4;
	const	Int_t ng = 5;
	Double_t Emin[ng] =  {1529, 357, 310, 346, 137  };
	Double_t Emax[ng] =  {1535, 361, 315, 350, 142  };
	Double_t BLmin[ng] = {1520, 352, 300, 342, 133  };
	Double_t BLmax[ng] = {1525, 354, 305, 344, 135.5};
	Double_t BRmin[ng] = {1537,   0, 320, 352, 144  };
	Double_t BRmax[ng] = {1542,   0, 325, 354, 146.5};
	Long64_t Eval[ng] =  {1531, 358, 312, 347, 139  };
//	Int_t flag[ng] =     {0,      0, 1,     1,   1  };
	Double_t htmax = 300.0;
	Int_t Ntbin = 50;

	//151Yb
	/*
	Long64_t HalfLife = 20000;
	Long64_t tmin = 1500;;
	Long64_t tmax = HalfLife*4;
	const	Int_t ng = 4;
	Long64_t Emin[ng] =  {1528, 201, 256, 598};
	Long64_t Emax[ng] =  {1534, 204, 261, 603};
	Long64_t BLmin[ng] = {1515, 195, 250, 590};
	Long64_t BLmax[ng] = {1521, 199, 253, 595};
	Long64_t BRmin[ng] = {1538, 215, 265, 606};
	Long64_t BRmax[ng] = {1544, 219, 270, 611};
	Long64_t Eval[ng] =  {1531, 203, 259, 600};
	Double_t tmax = 300.0;
	Int_t tbin = 100;
*/	
	//149Er
	/*
	Long64_t HalfLife = 4.8E3;
	Long64_t tmin = 1500;;
	Long64_t tmax = HalfLife*4;
	const	Int_t ng = 3;
	Long64_t Emin[ng] =  {1567, 574, 165};
	Long64_t Emax[ng] =  {1571, 578, 169};
	Long64_t BLmin[ng] = {1560, 566, 157};
	Long64_t BLmax[ng] = {1565, 570, 161};
	Long64_t BRmin[ng] = {0,    585, 171};
	Long64_t BRmax[ng] = {0,    589, 175};
	Long64_t Eval[ng] =  {1569, 576, 167};
	Double_t htmax = 300.0;
	Int_t Ntbin = 600;
	*/
	/*
	//150Tm
	Long64_t HalfLife = 5.2E6;
	Long64_t tmin = 100000;;
	Long64_t tmax = HalfLife*4;
	const	Int_t ng = 1;
	Long64_t Emin[ng] =  {328};
	Long64_t Emax[ng] =  {334};
	Long64_t BLmin[ng] = {319};
	Long64_t BLmax[ng] = {325};
	Long64_t BRmin[ng] = {360};
	Long64_t BRmax[ng] = {366};
	Long64_t Eval[ng] =  {331};
	Double_t htmax = 50.0E3;
	Int_t Ntbin = 5000;
*/

	TH2D *hgg2ga[ng][ng];
	TH2D *hgg2gb[ng][ng];
	TH2D *hgg2g[ng][ng];
	TH1D *hg2ga[ng][ng];
	TH1D *hg2gb[ng][ng];
	TH1D *hg2g[ng][ng];

	for(int i=0; i<ng; i++)
	{
		for(int j=0; j<ng; j++)
		{
			hgg2ga[i][j] = new TH2D(Form("hgg%d_%da", int(Eval[i]), int(Eval[j])), Form("hgg%d_%da", int(Eval[i]), int(Eval[j])), 2000, 0, 2000, 2000, 0, 2000);
			hgg2gb[i][j] = new TH2D(Form("hgg%d_%db", int(Eval[i]), int(Eval[j])), Form("hgg%d_%db", int(Eval[i]), int(Eval[j])), 2000, 0, 2000, 2000, 0, 2000);
			hgg2g[i][j] = new TH2D(Form("hgg%d_%d", int(Eval[i]), int(Eval[j])), Form("hgg%d_%d", int(Eval[i]), int(Eval[j])), 2000, 0, 2000, 2000, 0, 2000);

			hg2ga[i][j] = new TH1D(Form("hg%d_%da", int(Eval[i]), int(Eval[j])), Form("hgg%d_%da", int(Eval[i]), int(Eval[j])), 2000, 0, 2000);
			hg2gb[i][j] = new TH1D(Form("hg%d_%db", int(Eval[i]), int(Eval[j])), Form("hgg%d_%db", int(Eval[i]), int(Eval[j])), 2000, 0, 2000);
			hg2g[i][j] = new TH1D(Form("hg%d_%d", int(Eval[i]), int(Eval[j])), Form("hgg%d_%d", int(Eval[i]), int(Eval[j])), 2000, 0, 2000);
		}
	}
	TH2D *hgg2gAlla = new TH2D("hgg2gAlla", "hgg2gAlla", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg2gAllb = new TH2D("hgg2gAllb", "hgg2gAllb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg2gAll = new TH2D("hgg2gAll", "hgg2gAll", 2000, 0, 2000, 2000, 0, 2000);
	TH1D *hg2gAlla = new TH1D("hg2gaAll", "hg2gaAll", 2000, 0, 2000);
	TH1D *hg2gAllb = new TH1D("hg2gbAll", "hg2gbAll", 2000, 0, 2000);
	TH1D *hg2gAll= new TH1D("hg2gAll", "hg2gAll", 2000, 0, 2000);

	TH1D *hdta[ng];
	TH1D *hdtb[ng];
	TH1D *hdt[ng];

	TH1D *hgaa[ng];
	TH1D *hgab[ng];
	TH1D *hgba[ng];
	TH1D *hgbb[ng];
	TH1D *hga[ng];
	TH1D *hgb[ng];
	TH1D *hg[ng];
	TH2D *hggaa[ng];
	TH2D *hggab[ng];
	TH2D *hggba[ng];
	TH2D *hggbb[ng];
	TH2D *hgga[ng];
	TH2D *hggb[ng];
	TH2D *hgg[ng];
	for(int i=0; i<ng; i++)
	{
		hdta[i] = new TH1D(Form("hdta_%d", int(Eval[i])), Form("hdta_%d", int(Eval[i])), Ntbin, -1.0*htmax, htmax);
		hdtb[i] = new TH1D(Form("hdtb_%d", int(Eval[i])), Form("hdtb_%d", int(Eval[i])), Ntbin, -1.0*htmax, htmax);
		hdt[i] = new TH1D(Form("hdt_%d", int(Eval[i])), Form("hdt_%d", int(Eval[i])), Ntbin, -1.0*htmax, htmax);

		hgaa[i] = new TH1D(Form("hgaa_%d", int(Eval[i])), Form("hgaa_%d", int(Eval[i])), 2000, 0, 2000);
		hgab[i] = new TH1D(Form("hgab_%d", int(Eval[i])), Form("hgab_%d", int(Eval[i])), 2000, 0, 2000);
		hgba[i] = new TH1D(Form("hgba_%d", int(Eval[i])), Form("hgba_%d", int(Eval[i])), 2000, 0, 2000);
		hgbb[i] = new TH1D(Form("hgbb_%d", int(Eval[i])), Form("hgbb_%d", int(Eval[i])), 2000, 0, 2000);
		hga[i] = new TH1D(Form("hga_%d", int(Eval[i])), Form("hga_%d", int(Eval[i])), 2000, 0, 2000);
		hgb[i] = new TH1D(Form("hgb_%d", int(Eval[i])), Form("hgb_%d", int(Eval[i])), 2000, 0, 2000);
		hg[i] = new TH1D(Form("hg_%d", int(Eval[i])), Form("hg_%d", int(Eval[i])), 2000, 0, 2000);

		hggaa[i] = new TH2D(Form("hggaa_%d", int(Eval[i])), Form("hggaa_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hggab[i] = new TH2D(Form("hggab_%d", int(Eval[i])), Form("hggab_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hggba[i] = new TH2D(Form("hggba_%d", int(Eval[i])), Form("hggba_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hggbb[i] = new TH2D(Form("hggbb_%d", int(Eval[i])), Form("hggbb_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hgga[i] = new TH2D(Form("hgga_%d", int(Eval[i])), Form("hgga_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hggb[i] = new TH2D(Form("hggb_%d", int(Eval[i])), Form("hggb_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
		hgg[i] = new TH2D(Form("hgg_%d", int(Eval[i])), Form("hgg_%d", int(Eval[i])), 2000, 0, 2000, 2000, 0, 2000);
	}
	ULong64_t nall = ipt->GetEntriesFast();
	for(ULong64_t i=0; i < nall; i++)
	{
    	ipt->GetEntry(i);

 	   	if(idecay != 0)  continue;
    	if( i%1000 == 0)
    	{
			std::cout << Form("Process %.2f %%, %lld  / %lld \r", Double_t(i)/Double_t(nall)*100.0, i, nall);
    	    std::cout << std::flush;
    	}
		for(int j=0; j<Int_t((*rPxE).size()); j++)
		{
			if((*rPxts)[j]- rts > tmin && (*rPxts)[j]- rts < tmax)
			{
				hPGeXa->Fill((*rPxE)[j]);
				for(int k=0; k<Int_t((*rPxE).size()); k++)
				{
					if(j==k)	continue;
					if(abs((*rPxts)[j] - (*rPxts)[k]) > 50) continue;
					hggPGeXa->Fill((*rPxE)[j], (*rPxE)[k]);
				}
			}
			if((*rPxts)[j]- rts > -1*tmax && (*rPxts)[j]- rts < -1*tmin)
			{
				hPGeXb->Fill((*rPxE)[j]);
				for(int k=0; k<Int_t((*rPxE).size()); k++)
				{
					if(j==k)	continue;
					if(abs((*rPxts)[j] - (*rPxts)[k]) > 50) continue;
					hggPGeXb->Fill((*rPxE)[j], (*rPxE)[k]);
				}
			}
		}
		for(int j=0; j<Int_t((*rCe).size()); j++)
		{
			for(int k=0; k<ng; k++)
			{	
				if((*rCe)[j] > Emin[k]&& (*rCe)[j] < Emax[k])
				{
					hdta[k]->Fill(Double_t((*rCts)[j]- rts)/1000.0);
				}
			}
			for(int k=0; k<ng; k++)
			{	
				if((((*rCe)[j] > BLmin[k] && (*rCe)[j] < BLmax[k])) || (((*rCe)[j] > BRmin[k] && (*rCe)[j] < BRmax[k])))	
				{
					hdtb[k]->Fill(Double_t((*rCts)[j]- rts)/1000.0);
				}
			}


			if((*rCts)[j]- rts > tmin && (*rCts)[j]- rts < tmax)
			{
				//Clover
				hCa->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)	continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCa->Fill((*rCe)[j], (*rCe)[k]);
				}
				//2g IDT
				int x = 0;
				int y = 0;
				bool bFill = false;
				for(int k=0; k<ng; k++)
				{
					if((*rCe)[j] > Emin[k] && (*rCe)[j] < Emax[k])
					{
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
							hgaa[k]->Fill((*rGe)[l]);
							for(int m=0; m<Int_t((*rGe).size()); m++)
							{
								if(l==m)    continue;
								if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
								hggaa[k]->Fill((*rGe)[l], (*rGe)[m]);
							}
						}
						for(int l=0; l<Int_t((*rCe).size()); l++)
						{
							if(bFill)	break;
							if(j==l)	continue;
							if(abs((*rCts)[j] - (*rCts)[l]) > 50) continue;
							for(int m=0; m<ng; m++)
							{
								if(m==k)	continue;
								if((*rCe)[l] > Emin[m] && (*rCe)[l] < Emax[m])
								{
									x = k;
									y = m;
									bFill = true;
									break;
								}
							}
						}
					}
				}
				if(bFill)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg2gAlla->Fill((*rGe)[k]);
						hg2ga[x][y]->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg2gAlla->Fill((*rGe)[k], (*rGe)[l]);
							hgg2ga[x][y]->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//background
				for(int k=0; k<ng; k++)
				{
					if((((*rCe)[j] > BLmin[k] && (*rCe)[j] < BLmax[k])) || (((*rCe)[j] > BRmin[k] && (*rCe)[j] < BRmax[k])))	
					{
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
							hgba[k]->Fill((*rGe)[l]);
							for(int m=0; m<Int_t((*rGe).size()); m++)
							{
								if(l==m)    continue;
								if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
								hggba[k]->Fill((*rGe)[l], (*rGe)[m]);
							}
						}
					}
				}
			}
			if((*rCts)[j]- rts > -1*tmax && (*rCts)[j]- rts < -1*tmin)
			{
				//Clover
				hCb->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)    continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCb->Fill((*rCe)[j], (*rCe)[k]);
				}
				int x = 0;
				int y = 0;
				bool bFill = false;
				for(int k=0; k<ng; k++)
				{
					if(bFill)	break;
					if((*rCe)[j] > Emin[k] && (*rCe)[j] < Emax[k])
					{
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
							hgab[k]->Fill((*rGe)[l]);
							for(int m=0; m<Int_t((*rGe).size()); m++)
							{
								if(l==m)    continue;
								if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
								hggab[k]->Fill((*rGe)[l], (*rGe)[m]);
							}
						}
						for(int l=0; l<Int_t((*rCe).size()); l++)
						{
							if(bFill)	break;
							if(j==l)	continue;
							if(abs((*rCts)[j] - (*rCts)[l]) > 50) continue;
							for(int m=0; m<ng; m++)
							{
								if(m==k)	continue;
								if((*rCe)[l] > Emin[m] && (*rCe)[l] < Emax[m])
								{
									x = k;
									y = m;
									bFill = true;
									break;
								}
							}
						}
					}
				}
				if(bFill)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg2gAllb->Fill((*rGe)[k]);
						hg2gb[x][y]->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg2gAllb->Fill((*rGe)[k], (*rGe)[l]);
							hgg2gb[x][y]->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//background
				for(int k=0; k<ng; k++)
				{
					if((((*rCe)[j] > BLmin[k] && (*rCe)[j] < BLmax[k])) || (((*rCe)[j] > BRmin[k] && (*rCe)[j] < BRmax[k])))	
					{
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
							hgbb[k]->Fill((*rGe)[l]);
							for(int m=0; m<Int_t((*rGe).size()); m++)
							{
								if(l==m)    continue;
								if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
								hggbb[k]->Fill((*rGe)[l], (*rGe)[m]);
							}
						}
					}
				}
			}
		}
		
	}
	
	for(int i=0; i<ng; i++)
	{
		hdtb[i]->Add(hdtb[i], (Double_t(Emax[i]-Emin[i])/Double_t(BLmax[i]-BLmin[i]+BRmax[i]-BRmin[i]) - 1.0));
		hdt[i]->Add(hdta[i], hdtb[i], 1.0, -1.0);

		hgga[i]->Add(hggaa[i], hggab[i], 1.0, -1.0);
		hggb[i]->Add(hggba[i], hggbb[i], 1.0, -1.0);
		hggb[i]->Add(hggb[i], (Double_t(Emax[i]-Emin[i])/Double_t(BLmax[i]-BLmin[i]+BRmax[i]-BRmin[i]) - 1.0));
		hgg[i]->Add(hgga[i], hggb[i], 1.0, -1.0);
		hggAll->Add(hgg[i], 1.0);

		hga[i]->Add(hgaa[i], hgab[i], 1.0, -1.0);
		hgb[i]->Add(hgba[i], hgbb[i], 1.0, -1.0);
		hgb[i]->Add(hgb[i], hgb[i], -1.0, (Double_t(Emax[i]-Emin[i])/Double_t(BLmax[i]-BLmin[i]+BRmax[i]-BRmin[i]) - 1.0));
		hg[i]->Add(hga[i], hgb[i], 1.0, -1.0);
		hgAll->Add(hg[i], 1.0);
	}
	for(int i=0; i<ng; i++)
	{
		for(int j=0; j<ng; j++)
		{
			hgg2g[i][j]->Add(hgg2ga[i][j], hgg2gb[i][j], 1.0, -1.0);
			hg2g[i][j]->Add(hg2ga[i][j], hg2gb[i][j], 1.0, -1.0);
		}
	}
	hgg2gAll->Add(hgg2gAlla, hgg2gAllb, 1.0, -1.0);
	hg2gAll->Add(hg2gAlla, hg2gAllb, 1.0, -1.0);


	hPGeX->Add(hPGeXa, hPGeXb, 1.0, -1.0);
	hggPGeX->Add(hggPGeXa, hggPGeXb, 1.0, -1.0);
	hC->Add(hCa, hCb, 1.0, -1.0);
	hggC->Add(hggCa, hggCb, 1.0, -1.0);
//	ipf->Close();
	TFile *opf = new TFile(Form("../data/IDT/IDT%03d.root", run), "RECREATE");

	hgAll->Write();
	hggAll->Write();

	hPGeX->Write();
	hggPGeX->Write();

	hCa->Write();
	hCb->Write();
	hC->Write();
	hggCa->Write();
	hggCb->Write();
	hggC->Write();
	for(int i=0; i<ng; i++)
	{
		hdta[i]->Write();
		hdtb[i]->Write();
		hdt[i]->Write();
		hggaa[i]->Write();
		hggab[i]->Write();
		hggba[i]->Write();
		hggbb[i]->Write();
		hgga[i]->Write();
		hggb[i]->Write();
		hgg[i]->Write();
		hgaa[i]->Write();
		hgab[i]->Write();
		hgba[i]->Write();
		hgbb[i]->Write();
		hga[i]->Write();
		hgb[i]->Write();
		hg[i]->Write();

	}
	for(int i=0; i<ng; i++)
	{
		for(int j=0; j<ng; j++)
		{
			if(i==j)	continue;
			hgg2ga[i][j]->Write();
			hgg2gb[i][j]->Write();
			hgg2g[i][j]->Write();
			hg2ga[i][j]->Write();
			hg2gb[i][j]->Write();
			hg2g[i][j]->Write();
		}
	}

	hgg2gAlla->Write();
	hgg2gAllb->Write();
	hgg2gAll->Write();
	hg2gAlla->Write();
	hg2gAllb->Write();
	hg2gAll->Write();

	opf->Close();
	opf->Delete();
	
	hPGeXa->Delete();
	hPGeXb->Delete();
	hPGeX->Delete();
	hggPGeXa->Delete();
	hggPGeXb->Delete();
	hggPGeX->Delete();

	hCa->Delete();
	hCb->Delete();
	hC->Delete();
	hggCa->Delete();
	hggCb->Delete();
	hggC->Delete();
	hgAll->Delete();
	hggAll->Delete();
	for(int i=0; i<ng; i++)
	{
		hdta[i]->Delete();
		hdtb[i]->Delete();
		hdt[i]->Delete();
		hggaa[i]->Delete();
		hggab[i]->Delete();
		hggba[i]->Delete();
		hggbb[i]->Delete();
		hgga[i]->Delete();
		hggb[i]->Delete();
		hgg[i]->Delete();
		hgaa[i]->Delete();
		hgab[i]->Delete();
		hgba[i]->Delete();
		hgbb[i]->Delete();
		hga[i]->Delete();
		hgb[i]->Delete();
		hg[i]->Delete();

	}
	for(int i=0; i<ng; i++)
	{
		for(int j=0; j<ng; j++)
		{
			hgg2ga[i][j]->Delete();
			hgg2gb[i][j]->Delete();
			hgg2g[i][j]->Delete();

			hg2ga[i][j]->Delete();
			hg2gb[i][j]->Delete();
			hg2g[i][j]->Delete();
		}
	}

	hgg2gAlla->Delete();
	hgg2gAllb->Delete();
	hgg2gAll->Delete();
	hg2gAlla->Delete();
	hg2gAllb->Delete();
	hg2gAll->Delete();

	return 0;
}
