
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

	TH1D *hCTm150a = new TH1D("hCTm150a", "hCTm150a", 2000, 0, 2000);
	TH1D *hCTm150b = new TH1D("hCTm150b", "hCTm150b", 2000, 0, 2000);
	TH1D *hCTm150 = new TH1D("hCTm150", "hCTm150", 2000, 0, 2000);

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


	Long64_t Tm150_tmin = 100000;
//	Long64_t Tm150_tmax = 26000000;
	Long64_t Tm150_tmax = 15600000;

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

	hgg331a->Add(hgg331aa, hgg331ab, 1.0, -1.0);
	hgg331b->Add(hgg331ba, hgg331bb, 1.0, -1.0);
	hgg331->Add(hgg331a, hgg331b, 1.0, -1.0);
	hg331a->Add(hg331aa, hg331ab, 1.0, -1.0);
	hg331b->Add(hg331ba, hg331bb, 1.0, -1.0);
	hg331b->Add(hg331b, -0.5);
	hg331->Add(hg331a, hg331b, 1.0, -1.0);
	hCTm150->Add(hCTm150a, hCTm150b, 1.0, -1.0);
//	ipf->Close();
	TFile *opf = new TFile(Form("../data/IDT/IDT%03d.root", run), "RECREATE");
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

	opf->Close();
	hg331a->Delete();
	hg331b->Delete();
	hg331->Delete();
	hgg331a->Delete();
	hgg331b->Delete();
	hgg331->Delete();
	hCTm150a->Delete();
	hCTm150b->Delete();
	hCTm150->Delete();

	return 0;
}
