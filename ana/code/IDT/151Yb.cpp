
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
	
	TH2D *hgg1531a = new TH2D("hgg1531a", "hgg1531a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531b = new TH2D("hgg1531b", "hgg1531b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531 = new TH2D("hgg1531", "hgg1531", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg1531a = new TH1D("hg1531a", "hg1531a", 2000, 0, 2000);
	TH1D *hg1531b = new TH1D("hg1531b", "hg1531b", 2000, 0, 2000);
	TH1D *hg1531 = new TH1D("hg1531", "hg1531", 2000, 0, 2000);
	
	
	TH2D *hgg1531A203a = new TH2D("hgg1531A203a", "hgg1531A203a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531A203b = new TH2D("hgg1531A203b", "hgg1531A203b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531A203 = new TH2D("hgg1531A203", "hgg1531A203", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg1531A203a = new TH1D("hg1531A203a", "hg1531A203a", 2000, 0, 2000);
	TH1D *hg1531A203b = new TH1D("hg1531A203b", "hg1531A203b", 2000, 0, 2000);
	TH1D *hg1531A203 = new TH1D("hg1531A203", "hg1531A203", 2000, 0, 2000);
	
	TH2D *hgg1531O203a = new TH2D("hgg1531O203a", "hgg1531O203a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531O203b = new TH2D("hgg1531O203b", "hgg1531O203b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1531O203 = new TH2D("hgg1531O203", "hgg1531O203", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg1531O203a = new TH1D("hg1531O203a", "hg1531O203a", 2000, 0, 2000);
	TH1D *hg1531O203b = new TH1D("hg1531O203b", "hg1531O203b", 2000, 0, 2000);
	TH1D *hg1531O203 = new TH1D("hg1531O203", "hg1531O203", 2000, 0, 2000);


	TH1D *hCYb151a = new TH1D("hCYb151a", "hCYb151a", 2000, 0, 2000);
	TH1D *hCYb151b = new TH1D("hCYb151b", "hCYb151b", 2000, 0, 2000);
	TH1D *hCYb151 = new TH1D("hCYb151", "hCYb151", 2000, 0, 2000);


	Long64_t Yb151_tmin = 1500;
	Long64_t Yb151_tmax = 100000;

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
		for(int j=0; j<Int_t((*rCe).size()); j++)
		{
			//Pick Yb151
			// 1531 keV
			if((*rCts)[j]- rts > Yb151_tmin && (*rCts)[j]- rts < Yb151_tmax)
				hCYb151a->Fill((*rCe)[j]);
			if((*rCts)[j]- rts > -1*Yb151_tmax && (*rCts)[j]- rts < -1*Yb151_tmin)
				hCYb151b->Fill((*rCe)[j]);
			if(((*rCe)[j] > 1528 && (*rCe)[j] < 1534))
			{
				if((*rCts)[j]- rts > Yb151_tmin && (*rCts)[j]- rts < Yb151_tmax)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1531a->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)	continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)	continue;
							hgg1531a->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
					// 1531 && 203 keV
					for(int k=0; k<Int_t((*rCe).size()); k++)
					{
						if(j==k)	continue;
						if(abs((*rCts)[j] -(*rCts)[k]) > 100 || (*rCe)[k] < 201 || (*rCe)[k] > 206)  continue;
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
							hg1531A203a->Fill((*rGe)[l]);
							for(int m=0; m<Int_t((*rGe).size()); m++)
							{
								if(l==m)	continue;
								if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
								hgg1531A203a->Fill((*rGe)[l], (*rGe)[m]);
							}
						}

					}
				}
				if((*rCts)[j]- rts > -1*Yb151_tmax && (*rCts)[j]- rts < -1*Yb151_tmin)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1531b->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)	continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)	continue;
							hgg1531b->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
					for(int k=0; k<Int_t((*rCe).size()); k++)
					{
						if(j==k)	continue;
						if(abs((*rCts)[j] -(*rCts)[k]) > 100 || (*rCe)[k] < 201 || (*rCe)[k] > 206)  continue;
						{
							for(int l=0; l<Int_t((*rGe).size()); l++)
							{
								if((*rGts)[l] - rts < -510 || (*rGts)[l] - rts > -410)  continue;
								hg1531A203b->Fill((*rGe)[l]);
								for(int m=0; m<Int_t((*rGe).size()); m++)
								{
									if(l==m)    continue;
									if(abs((*rGts)[l] - (*rGts)[m]) > 60)   continue;
									hgg1531A203b->Fill((*rGe)[l], (*rGe)[m]);
								}
							}
						}
					}
				}			
			}
			if(((*rCe)[j] > 1528 && (*rCe)[j] < 1534) || ((*rCe)[j] > 201 && (*rCe)[j] <206))
			{
				if((*rCts)[j]- rts > Yb151_tmin && (*rCts)[j]- rts < Yb151_tmax)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1531O203a->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)	continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)	continue;
							hgg1531O203a->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				if((*rCts)[j]- rts > -1*Yb151_tmax && (*rCts)[j]- rts < -1*Yb151_tmin)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1531O203b->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)	continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)	continue;
							hgg1531O203b->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
			}
		}
		
	}
	hgg1531->Add(hgg1531a, hgg1531b, 1.0, -1.0);
	hgg1531A203->Add(hgg1531A203a, hgg1531A203b, 1.0, -1.0);
	hgg1531O203->Add(hgg1531O203a, hgg1531O203b, 1.0, -1.0);
	hg1531->Add(hg1531a, hg1531b, 1.0, -1.0);
	hg1531A203->Add(hg1531A203a, hg1531A203b, 1.0, -1.0);
	hg1531O203->Add(hg1531O203a, hg1531O203b, 1.0, -1.0);

	hCYb151->Add(hCYb151a, hCYb151b, 1.0, -1.0);
	TFile *opf = new TFile(Form("../data/IDT/IDT%03d.root", run), "RECREATE");
	hgg1531a->Write();
	hgg1531b->Write();
	hgg1531->Write();
	hg1531a->Write();
	hg1531b->Write();
	hg1531->Write();
	hgg1531A203a->Write();
	hgg1531A203b->Write();
	hgg1531A203->Write();
	hg1531A203a->Write();
	hg1531A203b->Write();
	hg1531A203->Write();
	hgg1531O203a->Write();
	hgg1531O203b->Write();
	hgg1531O203->Write();
	hg1531O203a->Write();
	hg1531O203b->Write();
	hg1531O203->Write();
	hCYb151a->Write();
	hCYb151b->Write();
	hCYb151->Write();

	opf->Close();
	hgg1531a->Delete();
	hgg1531b->Delete();
	hgg1531->Delete();
	hg1531a->Delete();
	hg1531b->Delete();
	hg1531->Delete();
	hgg1531A203a->Delete();
	hgg1531A203b->Delete();
	hgg1531A203->Delete();
	hg1531A203a->Delete();
	hg1531A203b->Delete();
	hg1531A203->Delete();
	hgg1531O203a->Delete();
	hgg1531O203b->Delete();
	hgg1531O203->Delete();
	hg1531O203a->Delete();
	hg1531O203b->Delete();
	hg1531O203->Delete();
	hCYb151a->Delete();
	hCYb151b->Delete();
	hCYb151->Delete();

	return 0;
}
