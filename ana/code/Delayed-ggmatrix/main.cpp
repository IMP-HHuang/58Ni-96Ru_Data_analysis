
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
	TH2D *hggClovera = new TH2D("hggClovera", "hggClovera", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggCloverb = new TH2D("hggCloverb", "hggCloverb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggClover = new TH2D("hggClover", "hggClover", 2000, 0, 2000, 2000, 0, 2000);
	TH1D *hgClovera = new TH1D("hgClovera", "hgClovera", 2000, 0, 2000);
	TH1D *hgCloverb = new TH1D("hgCloverb", "hgCloverb", 2000, 0, 2000);
	TH1D *hgClover = new TH1D("hgClover", "hgClover", 2000, 0, 2000);

	TH2D *hggPGeXa = new TH2D("hggPGeXa", "hggPGeXa", 500, 0, 500, 500, 0, 500);
	TH2D *hggPGeXb = new TH2D("hggPGeXb", "hggPGeXb", 500, 0, 500, 500, 0, 500);
	TH2D *hggPGeX = new TH2D("hggPGeX", "hggPGeX", 500, 0, 500, 500, 0, 500);
	TH1D *hgPGeXa = new TH1D("hgPGeXa", "hgPGeXa", 500, 0, 500);
	TH1D *hgPGeXb = new TH1D("hgPGeXb", "hgPGeXb", 500, 0, 500);
	TH1D *hgPGeX = new TH1D("hgPGeX", "hgPGeX", 500, 0, 500);

	Long64_t tmin = 100000; // 1500 ns
	Long64_t tmax = 26000000; //100000 ns

	ULong64_t nall = ipt->GetEntriesFast();
	Int_t  flag = 0;
	for(ULong64_t i=0; i < nall; i++)
	{
    	ipt->GetEntry(i);
//		if(i>10)	break;
 	   	if(idecay != 0)  continue;
//	cout <<"\033[31m bg1  "<<  i <<"\033[0m" << endl;

	   	//Clover
    	for(int j=0; j<int((*rCe).size()); j++)
    	{
	   		flag = 0;
            if((*rCts)[j]- rts > tmin && (*rCts)[j]- rts < tmax)
			{
                hgClovera->Fill((*rCe)[j]);
				flag = 1;
			}
            if((*rCts)[j]- rts < (-1*tmin) && (*rCts)[j]- rts > (-1*tmax))
			{
				flag = 2;
                hgCloverb->Fill((*rCe)[j]);
			}
			if(flag == 0)	continue;
        	for(int k=0; k<int((*rCe).size()); k++)
        	{
            	if(abs((*rCts)[j] -(*rCts)[k]) > 50)  continue;
            	if(j==k)  continue;
				if(flag == 1)
            	    hggClovera->Fill((*rCe)[j], (*rCe)[k]);
            	else if(flag == 2)
            	    hggCloverb->Fill((*rCe)[j], (*rCe)[k]);
        	}
    	}
		//PGe X 
    	for(int j=0; j<int((*rPxE).size()); j++)
    	{
	   		flag = 0;
            if((*rPxts)[j]- rts > tmin && (*rPxts)[j]- rts < tmax)
			{
           	    hgPGeXa->Fill((*rPxE)[j]);
				flag = 1;
			}
           	if((*rPxts)[j]- rts < (-1*tmin) && (*rPxts)[j]- rts > (-1*tmax))
			{
           	    hgPGeXb->Fill((*rPxE)[j]);
				flag = 2;
			}
			if(flag == 0)   continue;
        	for(int k=0; k<int((*rPxE).size()); k++)
        	{
            	if(j==k)  continue;
            	if(abs((*rPxts)[j] -(*rPxts)[k]) > 50)  continue;
            	if(flag == 1)
            	    hggPGeXa->Fill((*rPxE)[j], (*rPxE)[k]);
            	if(flag == 2)
            	    hggPGeXb->Fill((*rPxE)[j], (*rPxE)[k]);
        	}
    	}
	
    	if( i%1000 == 0)
    	{
    	    //cout << i << endl;
			std::cout << Form("Process %.2f %%, %lld  / %lld \r", Double_t(i)/Double_t(nall)*100.0, i, nall);
    	    std::cout << std::flush;
    	}
	}
//	ipf->Close();
	hggClover->Add(hggClovera, hggCloverb, 1.0, -1.0);
	hgClover->Add(hgClovera, hgCloverb, 1.0, -1.0);
	hggPGeX->Add(hggPGeXa, hggPGeXb, 1.0, -1.0);
	hgPGeX->Add(hgPGeXa, hgPGeXb, 1.0, -1.0);
	TFile *opf = new TFile(Form("../data/Delayed-ggmatrix/Delayed-ggmatrix%03d.root", run), "RECREATE");
	opf->cd();
	hggClovera->Write();
	hggCloverb->Write();
	hggClover->Write();
	hgClovera->Write();
	hgCloverb->Write();
	hgClover->Write();
	hggPGeXa->Write();
	hggPGeXb->Write();
	hggPGeX->Write();
	hgPGeXa->Write();
	hgPGeXb->Write();
	hgPGeX->Write();

//	std::cout <<"\033[31m    bg \033[0m" << std::endl;
	opf->Close();
//	std::cout <<"\033[31m    bg1 \033[0m" << std::endl;
	hggClovera->Delete();
	hggCloverb->Delete();
	hggClover->Delete();
	hgClovera->Delete();
	hgCloverb->Delete();
	hgClover->Delete();

	hggPGeXa->Delete();
	hggPGeXb->Delete();
	hggPGeX->Delete();
	hgPGeXa->Delete();
	hgPGeXb->Delete();
	hgPGeX->Delete();
	return 0;
}
