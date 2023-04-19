
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
	
	TH1D *hCEr149a = new TH1D("hCEr149a", "hCEr149a", 2000, 0, 2000);
	TH1D *hCEr149b = new TH1D("hCEr149b", "hCEr149b", 2000, 0, 2000);
	TH1D *hCEr149 = new TH1D("hCEr149", "hCEr149", 2000, 0, 2000);
	TH2D *hggCEr149a = new TH2D("hggCEr149a", "hggCEr149a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggCEr149b = new TH2D("hggCEr149b", "hggCEr149b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggCEr149 = new TH2D("hggCEr149", "hggCEr149", 2000, 0, 2000, 2000, 0, 2000);

	TH2D *hgg576aa = new TH2D("hgg576aa", "hgg576aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576ab = new TH2D("hgg576ab", "hgg576ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576a = new TH2D("hgg576a", "hgg576a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576ba = new TH2D("hgg576ba", "hgg576ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576bb = new TH2D("hgg576bb", "hgg576bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576b = new TH2D("hgg576b", "hgg576b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg576 = new TH2D("hgg576", "hgg576", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg576aa = new TH1D("hg576aa", "hg576aa", 2000, 0, 2000);
	TH1D *hg576ab = new TH1D("hg576ab", "hg576ab", 2000, 0, 2000);
	TH1D *hg576a = new TH1D("hg576a", "hg576a", 2000, 0, 2000);	
	TH1D *hg576ba = new TH1D("hg576ba", "hg576ba", 2000, 0, 2000);
	TH1D *hg576bb = new TH1D("hg576bb", "hg576bb", 2000, 0, 2000);
	TH1D *hg576b = new TH1D("hg576b", "hg576b", 2000, 0, 2000);
	TH1D *hg576 = new TH1D("hg576", "hg576", 2000, 0, 2000);

	TH1D *hg167aa = new TH1D("hg167aa", "hg167aa", 2000, 0, 2000);
	TH1D *hg167ab = new TH1D("hg167ab", "hg167ab", 2000, 0, 2000);
	TH1D *hg167a = new TH1D("hg167a", "hg167a", 2000, 0, 2000);	
	TH1D *hg167ba = new TH1D("hg167ba", "hg167ba", 2000, 0, 2000);
	TH1D *hg167bb = new TH1D("hg167bb", "hg167bb", 2000, 0, 2000);
	TH1D *hg167b = new TH1D("hg167b", "hg167b", 2000, 0, 2000);
	TH1D *hg167 = new TH1D("hg167", "hg167", 2000, 0, 2000);
	TH2D *hgg167aa = new TH2D("hgg167aa", "hgg167aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167ab = new TH2D("hgg167ab", "hgg167ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167a = new TH2D("hgg167a", "hgg167a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167ba = new TH2D("hgg167ba", "hgg167ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167bb = new TH2D("hgg167bb", "hgg167bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167b = new TH2D("hgg167b", "hgg167b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg167 = new TH2D("hgg167", "hgg167", 2000, 0, 2000, 2000, 0, 2000);

	TH2D *hgg = new TH2D("hgg", "hgg", 2000, 0, 2000, 2000, 0, 2000);
	TH1D *hg = new TH1D("hg", "hg", 2000, 0, 2000);

	TH1D *hdt576a = new TH1D("hdt576a", "hdt576a", 600, -300.0, 300.0);	
	TH1D *hdt576b = new TH1D("hdt576b", "hdt576b", 600, -300.0, 300.0);
	TH1D *hdt576 = new TH1D("hdt576", "hdt576", 600, -300.0, 300.0);
	
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
			if(((*rCe)[j] > 574 && (*rCe)[j] < 578))
				hdt576a->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			if((((*rCe)[j] > 566 && (*rCe)[j] < 570)) || (((*rCe)[j] > 585 && (*rCe)[j] < 589)))
				hdt576b->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			if((*rCts)[j]- rts > Er149_tmin && (*rCts)[j]- rts < Er149_tmax)
			{
				hCEr149a->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)	continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCEr149a->Fill((*rCe)[j], (*rCe)[k]);
				}
				//576-all
				if(((*rCe)[j] > 574 && (*rCe)[j] < 578))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576aa->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg576aa->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//576 background 566 - 570
				if((((*rCe)[j] > 566 && (*rCe)[j] < 570)) || (((*rCe)[j] > 585 && (*rCe)[j] < 589)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576ba->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg576ba->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//167-all
				if(((*rCe)[j] > 165 && (*rCe)[j] < 169))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg167aa->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg167aa->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//167 background 566 - 570
				if((((*rCe)[j] > 157 && (*rCe)[j] < 161)) || (((*rCe)[j] > 171 && (*rCe)[j] < 175)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg167ba->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg167ba->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
			}
			if((*rCts)[j]- rts > -1*Er149_tmax && (*rCts)[j]- rts < -1*Er149_tmin)
			{
				hCEr149b->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)    continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCEr149b->Fill((*rCe)[j], (*rCe)[k]);
				}
				//576-all
				if(((*rCe)[j] > 574 && (*rCe)[j] < 578))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576ab->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg576ab->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//576 background 566 - 570
				if((((*rCe)[j] > 566 && (*rCe)[j] < 570)) || (((*rCe)[j] > 585 && (*rCe)[j] < 589)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg576bb->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg576bb->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//167
				if(((*rCe)[j] > 165 && (*rCe)[j] < 169))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg167ab->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg167ab->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//167 background 566 - 570
				if((((*rCe)[j] > 157 && (*rCe)[j] < 161)) || (((*rCe)[j] > 171 && (*rCe)[j] < 175)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg167bb->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg167bb->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
			}
		}
		
	}

	hgg576a->Add(hgg576aa, hgg576ab, 1.0, -1.0);
	hgg576b->Add(hgg576ba, hgg576bb, 1.0, -1.0);
	hgg576b->Add(hgg576b, -0.5);
	hgg576->Add(hgg576a, hgg576b, 1.0, -1.0);
	hg576a->Add(hg576aa, hg576ab, 1.0, -1.0);
	hg576b->Add(hg576ba, hg576bb, 1.0, -1.0);
	hg576b->Add(hg576b, -0.5);
	hg576->Add(hg576a, hg576b, 1.0, -1.0);

	hgg167a->Add(hgg167aa, hgg167ab, 1.0, -1.0);
	hgg167b->Add(hgg167ba, hgg167bb, 1.0, -1.0);
	hgg167b->Add(hgg167b, -0.5);
	hgg167->Add(hgg167a, hgg167b, 1.0, -1.0);
	hg167a->Add(hg576aa, hg576ab, 1.0, -1.0);
	hg167b->Add(hg576ba, hg576bb, 1.0, -1.0);
	hg167b->Add(hg576b, -0.5);
	hg167->Add(hg576a, hg576b, 1.0, -1.0);

	hg->Add(hg576, hg167, 1.0, 1.0);
	hgg->Add(hgg576, hgg167, 1.0, 1.0);

	hCEr149->Add(hCEr149a, hCEr149b, 1.0, -1.0);
	hggCEr149->Add(hggCEr149a, hggCEr149b, 1.0, -1.0);
	hdt576->Add(hdt576a, hdt576b, 1.0, -1.0);
//	ipf->Close();
	TFile *opf = new TFile(Form("../data/IDT/IDT%03d.root", run), "RECREATE");
	hg576aa->Write();
	hg576ab->Write();
	hg576ba->Write();
	hg576bb->Write();
	hg576a->Write();
	hg576b->Write();
	hg576->Write();
	hgg576aa->Write();
	hgg576ab->Write();
	hgg576ba->Write();
	hgg576bb->Write();
	hgg576a->Write();
	hgg576b->Write();
	hgg576->Write();

	hg167aa->Write();
	hg167ab->Write();
	hg167ba->Write();
	hg167bb->Write();
	hg167a->Write();
	hg167b->Write();
	hg167->Write();
	hgg167aa->Write();
	hgg167ab->Write();
	hgg167ba->Write();
	hgg167bb->Write();
	hgg167a->Write();
	hgg167b->Write();
	hgg167->Write();
	hg->Write();
	hgg->Write();

	hCEr149a->Write();
	hCEr149b->Write();
	hCEr149->Write();
	hggCEr149a->Write();
	hggCEr149b->Write();
	hggCEr149->Write();
	hdt576a->Write();
	hdt576b->Write();
	hdt576->Write();

	opf->Close();
	opf->Delete();
	
	hg576aa->Delete();
	hg576ab->Delete();
	hg576ba->Delete();
	hg576bb->Delete();
	hg576a->Delete();
	hg576b->Delete();
	hg576->Delete();
	hgg576aa->Delete();
	hgg576ab->Delete();
	hgg576ba->Delete();
	hgg576bb->Delete();
	hgg576a->Delete();
	hgg576b->Delete();
	hgg576->Delete();
	hCEr149a->Delete();
	hCEr149b->Delete();
	hCEr149->Delete();
	hggCEr149a->Delete();
	hggCEr149b->Delete();
	hggCEr149->Delete();
	hdt576a->Delete();
	hdt576b->Delete();
	hdt576->Delete();
	hg167aa->Delete();
	hg167ab->Delete();
	hg167ba->Delete();
	hg167bb->Delete();
	hg167a->Delete();
	hg167b->Delete();
	hg167->Delete();
	hgg167aa->Delete();
	hgg167ab->Delete();
	hgg167ba->Delete();
	hgg167bb->Delete();
	hgg167a->Delete();
	hgg167b->Delete();
	hgg167->Delete();
	hg->Delete();
	hgg->Delete();

	return 0;
}
