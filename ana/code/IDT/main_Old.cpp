
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
	
	TH1D *hdtC = new TH1D("hdtC", "hdtC", 200, -1000, 1000);
	TH1D *hdtGe = new TH1D("hdtGe", "hdtGe", 200, -1000, 1000);
	TH1D *hdtCr = new TH1D("hdtCr", "hdtCr", 60000, -30000000, 30000000);

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

	TH2D *hgg331aa = new TH2D("hgg331aa", "hgg331aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331ab = new TH2D("hgg331ab", "hgg331ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331a = new TH2D("hgg331a", "hgg331a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331ba = new TH2D("hgg331ba", "hgg331ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331bb = new TH2D("hgg331bb", "hgg331bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331b = new TH2D("hgg331b", "hgg331b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg331 = new TH2D("hgg331", "hgg331", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg331aa = new TH1D("hg331aa", "hg331aa", 2000, 0, 2000);
	TH1D *hg331ab = new TH1D("hg331ab", "hg331ab", 2000, 0, 2000);
	TH1D *hg331a = new TH1D("hg331a", "hg331a", 2000, 0, 2000);	
	TH1D *hg331ba = new TH1D("hg331ba", "hg331ba", 2000, 0, 2000);
	TH1D *hg331bb = new TH1D("hg331bb", "hg331bb", 2000, 0, 2000);
	TH1D *hg331b = new TH1D("hg331b", "hg331b", 2000, 0, 2000);
	TH1D *hg331 = new TH1D("hg331", "hg331", 2000, 0, 2000);

	TH1D *hCTm150a = new TH1D("hCTm150a", "hCTm150a", 2000, 0, 2000);
	TH1D *hCTm150b = new TH1D("hCTm150b", "hCTm150b", 2000, 0, 2000);
	TH1D *hCTm150 = new TH1D("hCTm150", "hCTm150", 2000, 0, 2000);

	TH1D *hCYb151a = new TH1D("hCYb151a", "hCYb151a", 2000, 0, 2000);
	TH1D *hCYb151b = new TH1D("hCYb151b", "hCYb151b", 2000, 0, 2000);
	TH1D *hCYb151 = new TH1D("hCYb151", "hCYb151", 2000, 0, 2000);

	TH1D *hCEr149a = new TH1D("hCEr149a", "hCEr149a", 2000, 0, 2000);
	TH1D *hCEr149b = new TH1D("hCEr149b", "hCEr149b", 2000, 0, 2000);
	TH1D *hCEr149 = new TH1D("hCEr149", "hCEr149", 2000, 0, 2000);
	TH1D *hg576a = new TH1D("hg576a", "hg576a", 2000, 0, 2000);
	TH1D *hg576b = new TH1D("hg576b", "hg576b", 2000, 0, 2000);
	TH1D *hg576 = new TH1D("hg576", "hg576", 2000, 0, 2000);

	Long64_t Yb151_tmin = 1500;
	Long64_t Yb151_tmax = 100000;
	Long64_t Tm150_tmin = 100000;
//	Long64_t Tm150_tmax = 26000000;
	Long64_t Tm150_tmax = 15600000;
	Long64_t Er149_tmin = 1500;
	Long64_t Er149_tmax = 20000;

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
			//pick Er149
			if((*rCts)[j]- rts > Er149_tmin && (*rCts)[j]- rts < Er149_tmax)
			{
				hCEr149a->Fill((*rCe)[j]);
				//576
				if(((*rCe)[j] > 574 && (*rCe)[j] < 578))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576a->Fill((*rGe)[k]);
					}
				}
			}
			if((*rCts)[j]- rts > -1*Er149_tmax && (*rCts)[j]- rts < -1*Er149_tmin)
			{
				hCEr149b->Fill((*rCe)[j]);
				//576
				if(((*rCe)[j] > 574 && (*rCe)[j] < 578))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576b->Fill((*rGe)[k]);
					}
				}
			}
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
			//pick Tm150
			if((*rCts)[j]- rts > Tm150_tmin && (*rCts)[j]- rts < Tm150_tmax)
				hCTm150a->Fill((*rCe)[j]);
			if((*rCts)[j]- rts > -1*Tm150_tmax && (*rCts)[j]- rts < -1*Tm150_tmin)
				hCTm150b->Fill((*rCe)[j]);
			// 331 keV
			if(((*rCe)[j] > 328 && (*rCe)[j] < 334))
			{
				if((*rCts)[j]- rts > Tm150_tmin && (*rCts)[j]- rts < Tm150_tmax)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg331aa->Fill((*rGe)[k]);
					}
				}
				if((*rCts)[j]- rts > -1*Tm150_tmax && (*rCts)[j]- rts < -1*Tm150_tmin)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg331ab->Fill((*rGe)[k]);
					}
				}
			}
			if(((*rCe)[j] > 319 && (*rCe)[j] < 325) || ((*rCe)[j] > 360 && (*rCe)[j] < 366))
			{
				if((*rCts)[j]- rts > Tm150_tmin && (*rCts)[j]- rts < Tm150_tmax)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg331ba->Fill((*rGe)[k]);
					}
				}
				if((*rCts)[j]- rts > -1*Tm150_tmax && (*rCts)[j]- rts < -1*Tm150_tmin)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg331bb->Fill((*rGe)[k]);
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

	hgg331a->Add(hgg331aa, hgg331ab, 1.0, -1.0);
	hgg331b->Add(hgg331ba, hgg331bb, 1.0, -1.0);
	hgg331->Add(hgg331a, hgg331b, 1.0, -1.0);
	hg331a->Add(hg331aa, hg331ab, 1.0, -1.0);
	hg331b->Add(hg331ba, hg331bb, 1.0, -1.0);
	hg331->Add(hg331a, hg331b, 1.0, -0.5);
	hCTm150->Add(hCTm150a, hCTm150b, 1.0, -1.0);
	hCYb151->Add(hCYb151a, hCYb151b, 1.0, -1.0);
	hCEr149->Add(hCEr149a, hCEr149b, 1.0, -1.0);
	hg576->Add(hg576a, hg576b, 1.0, -1.0);
//	ipf->Close();
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
	hg331aa->Write();
	hg331ab->Write();
	hg331ba->Write();
	hg331bb->Write();
	hg331a->Write();
	hg331b->Write();
	hg331->Write();
	hgg331aa->Write();
	hgg331ab->Write();
	hgg331ba->Write();
	hgg331bb->Write();
	hgg331a->Write();
	hgg331b->Write();
	hgg331->Write();
	hCTm150a->Write();
	hCTm150b->Write();
	hCTm150->Write();
	hCYb151a->Write();
	hCYb151b->Write();
	hCYb151->Write();
	hCEr149a->Write();
	hCEr149b->Write();
	hCEr149->Write();
	hg576a->Write();
	hg576b->Write();
	hg576->Write();


//	hdtC->Write();
//	hdtGe->Write();
//	hdtCr->Write();

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
	hg331a->Delete();
	hg331b->Delete();
	hg331->Delete();
	hgg331a->Delete();
	hgg331b->Delete();
	hgg331->Delete();
	hdtC->Delete();
	hdtGe->Delete();
	hdtCr->Delete();
	hCTm150a->Delete();
	hCTm150b->Delete();
	hCTm150->Delete();
	hCYb151a->Delete();
	hCYb151b->Delete();
	hCYb151->Delete();
	hCEr149a->Delete();
	hCEr149b->Delete();
	hCEr149->Delete();
	hg576a->Delete();
	hg576b->Delete();
	hg576->Delete();

	return 0;
}
