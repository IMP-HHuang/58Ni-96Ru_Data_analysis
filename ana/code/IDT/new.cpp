
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
	Long64_t dts;

	//Get branch
	ipt->SetBranchAddress("rts", &rts);
	ipt->SetBranchAddress("dts", &dts);
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
	
	TH1D *h646A877dt1a = new TH1D("h646A877dt1a", "h646A877dt1a", 100, 0, 10000);
	TH1D *h646A877dt1b = new TH1D("h646A877dt1b", "h646A877dt1b", 100, 0, 10000);
	TH1D *h646A877dt1 = new TH1D("h646A877dt1", "h646A877dt1", 100, 0, 10000);

	TH1D *h646A877de1aa = new TH1D("h646A877de1aa", "h646A877de1aa", 1000, 0, 10000);
	TH1D *h646A877de1ab = new TH1D("h646A877de1ab", "h646A877de1ab", 1000, 0, 10000);
	TH1D *h646A877de1ba = new TH1D("h646A877de1ba", "h646A877de1ba", 1000, 0, 10000);
	TH1D *h646A877de1bb = new TH1D("h646A877de1bb", "h646A877de1bb", 1000, 0, 10000);
	TH1D *h646A877de1a = new TH1D("h646A877de1a", "h646A877de1a", 1000, 0, 10000);
	TH1D *h646A877de1b = new TH1D("h646A877de1b", "h646A877de1b", 1000, 0, 10000);
	TH1D *h646A877de1 = new TH1D("h646A877de1", "h646A877de1", 1000, 0, 10000);

	TH1D *hCa = new TH1D("hCa", "hCa", 2000, 0, 2000);
	TH1D *hCb = new TH1D("hCb", "hCb", 2000, 0, 2000);
	TH1D *hC = new TH1D("hC", "hC", 2000, 0, 2000);
	TH2D *hggCa = new TH2D("hggCa", "hggCa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggCb = new TH2D("hggCb", "hggCb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hggC = new TH2D("hggC", "hggC", 2000, 0, 2000, 2000, 0, 2000);

	TH2D *hgg1002aa = new TH2D("hgg1002aa", "hgg1002aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002ab = new TH2D("hgg1002ab", "hgg1002ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002a = new TH2D("hgg1002a", "hgg1002a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002ba = new TH2D("hgg1002ba", "hgg1002ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002bb = new TH2D("hgg1002bb", "hgg1002bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002b = new TH2D("hgg1002b", "hgg1002b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg1002 = new TH2D("hgg1002", "hgg1002", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hg1002aa = new TH1D("hg1002aa", "hg1002aa", 2000, 0, 2000);
	TH1D *hg1002ab = new TH1D("hg1002ab", "hg1002ab", 2000, 0, 2000);
	TH1D *hg1002a = new TH1D("hg1002a", "hg1002a", 2000, 0, 2000);	
	TH1D *hg1002ba = new TH1D("hg1002ba", "hg1002ba", 2000, 0, 2000);
	TH1D *hg1002bb = new TH1D("hg1002bb", "hg1002bb", 2000, 0, 2000);
	TH1D *hg1002b = new TH1D("hg1002b", "hg1002b", 2000, 0, 2000);
	TH1D *hg1002 = new TH1D("hg1002", "hg1002", 2000, 0, 2000);


	TH1D *hdt1002a = new TH1D("hdt1002a", "hdt1002a", 1000, -300.0, 300.0);	
	TH1D *hdt1002b = new TH1D("hdt1002b", "hdt1002b", 1000, -300.0, 300.0);
	TH1D *hdt1002 = new TH1D("hdt1002", "hdt1002", 	  1000, -300.0, 300.0);

	TH1D *hg877aa = new TH1D("hg877aa", "hg877aa", 2000, 0, 2000);
	TH1D *hg877ab = new TH1D("hg877ab", "hg877ab", 2000, 0, 2000);
	TH1D *hg877ba = new TH1D("hg877ba", "hg877ba", 2000, 0, 2000);
	TH1D *hg877bb = new TH1D("hg877bb", "hg877bb", 2000, 0, 2000);
	TH1D *hg877b = new TH1D("hg877b", "hg877b", 2000, 0, 2000);
	TH1D *hg877a = new TH1D("hg877a", "hg877a", 2000, 0, 2000);
	TH1D *hg877 = new TH1D("hg877", "hg877", 2000, 0, 2000);
	TH2D *hgg877aa = new TH2D("hgg877aa", "hgg877aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877ab = new TH2D("hgg877ab", "hgg877ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877a = new TH2D("hgg877a", "hgg877a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877ba = new TH2D("hgg877ba", "hgg877ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877bb = new TH2D("hgg877bb", "hgg877bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877b = new TH2D("hgg877b", "hgg877b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg877 = new TH2D("hgg877", "hgg877", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hdt877a = new TH1D("hdt877a", "hdt877a", 1000, -300.0, 300.0);	
	TH1D *hdt877b = new TH1D("hdt877b", "hdt877b", 1000, -300.0, 300.0);
	TH1D *hdt877 = new TH1D("hdt877", "hdt877",    1000, -300.0, 300.0);

	TH1D *hg646aa = new TH1D("hg646aa", "hg646aa", 2000, 0, 2000);
	TH1D *hg646ab = new TH1D("hg646ab", "hg646ab", 2000, 0, 2000);
	TH1D *hg646ba = new TH1D("hg646ba", "hg646ba", 2000, 0, 2000);
	TH1D *hg646bb = new TH1D("hg646bb", "hg646bb", 2000, 0, 2000);
	TH1D *hg646b = new TH1D("hg646b", "hg646b", 2000, 0, 2000);
	TH1D *hg646a = new TH1D("hg646a", "hg646a", 2000, 0, 2000);
	TH1D *hg646 = new TH1D("hg646", "hg646", 2000, 0, 2000);
	TH2D *hgg646aa = new TH2D("hgg646aa", "hgg646aa", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646ab = new TH2D("hgg646ab", "hgg646ab", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646a = new TH2D("hgg646a", "hgg646a", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646ba = new TH2D("hgg646ba", "hgg646ba", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646bb = new TH2D("hgg646bb", "hgg646bb", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646b = new TH2D("hgg646b", "hgg646b", 2000, 0, 2000, 2000, 0, 2000);
	TH2D *hgg646 = new TH2D("hgg646", "hgg646", 2000, 0, 2000, 2000, 0, 2000);
	
	TH1D *hdt646a = new TH1D("hdt646a", "hdt646a", 1000, -300.0, 300.0);	
	TH1D *hdt646b = new TH1D("hdt646b", "hdt646b", 1000, -300.0, 300.0);
	TH1D *hdt646 = new TH1D("hdt646", "hdt646", 	  1000, -300.0, 300.0);
	TH2D *hgg = new TH2D("hgg", "hgg", 2000, 0, 2000, 2000, 0, 2000);
	TH1D *hg = new TH1D("hg", "hg", 2000, 0, 2000);

	Long64_t tmin = 500;
	Long64_t tmax = 35000;

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
			//1002
			if(((*rCe)[j] > 1000 && (*rCe)[j] < 1005))
				hdt1002a->Fill(Double_t((*rCts)[j]- rts)/1000.0);   //us
			if((((*rCe)[j] > 980 && (*rCe)[j] < 985)) || (((*rCe)[j] > 1010 && (*rCe)[j] < 1015)))
				hdt1002b->Fill(Double_t((*rCts)[j]- rts)/1000.0); //us
			//877
			if(((*rCe)[j] > 875 && (*rCe)[j] < 880))
				 hdt877a->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			if(((*rCe)[j] > 865 && (*rCe)[j] < 870) || ((*rCe)[j] > 885 && (*rCe)[j] < 890))
				hdt877b->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			//646
			if(((*rCe)[j] > 644 && (*rCe)[j] < 649))
				 hdt646a->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			if((((*rCe)[j] > 635 && (*rCe)[j] < 640)) || (((*rCe)[j] > 652 && (*rCe)[j] < 657)))
				hdt646b->Fill(Double_t((*rCts)[j]- rts)/1000.0);
			if((*rCts)[j]- rts > tmin && (*rCts)[j]- rts < tmax)
			{
				hCa->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)	continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCa->Fill((*rCe)[j], (*rCe)[k]);
				}
				//1002-all
				if(((*rCe)[j] > 1000 && (*rCe)[j] < 1005))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1002aa->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg1002aa->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//1002 background 
				if((((*rCe)[j] > 980 && (*rCe)[j] < 985)) || (((*rCe)[j] > 1010 && (*rCe)[j] < 1015)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1002ba->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg1002ba->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//877-all
				if(((*rCe)[j] > 875 && (*rCe)[j] < 880))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877aa->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877aa->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//877 background 
				if((((*rCe)[j] > 865 && (*rCe)[j] < 870)) || (((*rCe)[j] > 885 && (*rCe)[j] < 890)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877ba->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877ba->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//646-all
				if(((*rCe)[j] > 644 && (*rCe)[j] < 649))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg646aa->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg646aa->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
					for(int k=0; k<Int_t((*rCe).size()); k++)
					{
						if(j==k || abs((*rCts)[j] - (*rCts)[k]) > 60)	continue;
						if(((*rCe)[k] > 875 && (*rCe)[k] < 880) || ((*rCe)[k] > 1001 && (*rCe)[k] < 1005)||
							((*rCe)[k] > 644 && (*rCe)[k] < 649))
						{
							Long64_t inow = i;
							while(1)
							{
								if(dts-(*rCts)[j]>0 && dts-(*rCts)[j] < 1E10)
								{
									h646A877dt1a->Fill(Double_t(dts-(*rCts)[j])/1E6);
									h646A877de1a->Fill(dxe);
								}
								inow++;
								ipt->GetEntry(inow);
								if(idecay == 0)		break;
							}
						}
					}
				}
				//646 background 
				if((((*rCe)[j] > 635 && (*rCe)[j] < 640)) || (((*rCe)[j] > 652 && (*rCe)[j] < 657)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877ba->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877ba->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
			}
			if((*rCts)[j]- rts > -1*tmax && (*rCts)[j]- rts < -1*tmin)
			{
				hCb->Fill((*rCe)[j]);
				for(int k=0; k<Int_t((*rCe).size()); k++)
				{
					if(j==k)    continue;
					if(abs((*rCts)[j] - (*rCts)[k]) > 50) continue;
					hggCb->Fill((*rCe)[j], (*rCe)[k]);
				}
				//1002-all
				if((*rCe)[j] > 1000 && (*rCe)[j] < 1005)
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1002ab->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg1002ab->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//1002 background 
				if((((*rCe)[j] > 980 && (*rCe)[j] < 985)) || (((*rCe)[j] > 1010 && (*rCe)[j] < 1015)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg1002bb->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg1002bb->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//877-all
				if(((*rCe)[j] > 875 && (*rCe)[j] < 880))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877ab->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877ab->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//877 background 
				if((((*rCe)[j] > 865 && (*rCe)[j] < 870)) || (((*rCe)[j] > 885 && (*rCe)[j] < 890)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877bb->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877bb->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
				//646-all
				if(((*rCe)[j] > 644 && (*rCe)[j] < 649))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg646ab->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg646ab->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
					for(int k=0; k<Int_t((*rCe).size()); k++)
					{
						if(j==k || abs((*rCts)[j] - (*rCts)[k]) > 60)	continue;
						if(((*rCe)[k] > 875 && (*rCe)[k] < 880) || ((*rCe)[k] > 1001 && (*rCe)[k] < 1005)||
							((*rCe)[k] > 644 && (*rCe)[k] < 649))
						{
							Long64_t inow = i;
							while(1)
							{
								if(dts-(*rCts)[j]>0 && dts-(*rCts)[j] < 1E10)
								{
									h646A877dt1b->Fill(Double_t(dts-(*rCts)[j])/1E6);
									h646A877de1b->Fill(dxe);
								}
								inow++;
								ipt->GetEntry(inow);
								if(idecay == 0)		break;
							}
						}
					}
				}
				//646 background 
				if((((*rCe)[j] > 635 && (*rCe)[j] < 640)) || (((*rCe)[j] > 652 && (*rCe)[j] < 657)))
				{
					for(int k=0; k<Int_t((*rGe).size()); k++)
					{
						if((*rGts)[k] - rts < -510 || (*rGts)[k] - rts > -410)  continue;
						hg877bb->Fill((*rGe)[k]);
						for(int l=0; l<Int_t((*rGe).size()); l++)
						{
							if(k==l)    continue;
							if(abs((*rGts)[k] - (*rGts)[l]) > 60)   continue;
							hgg877bb->Fill((*rGe)[k], (*rGe)[l]);
						}
					}
				}
			}
		}
		
	}

//	h646de1a->Add(h646de1aa, h646de1ab, 1.0, -1.0);
//	h646de1b->Add(h646de1ba, h646de1bb, 1.0, -1.0);
	h646A877de1->Add(h646A877de1a, h646A877de1b, 1.0, -1.0);

	h646A877dt1->Add(h646A877dt1a, h646A877dt1b, 1.0, -1.0);

	hgg1002a->Add(hgg1002aa, hgg1002ab, 1.0, -1.0);
	hgg1002b->Add(hgg1002ba, hgg1002bb, 1.0, -1.0);
	hgg1002b->Add(hgg1002b, -0.5);
	hgg1002->Add(hgg1002a, hgg1002b, 1.0, -1.0);
	hg1002a->Add(hg1002aa, hg1002ab, 1.0, -1.0);
	hg1002b->Add(hg1002ba, hg1002bb, 1.0, -1.0);
	hg1002b->Add(hg1002b, -0.5);
	hg1002->Add(hg1002a, hg1002b, 1.0, -1.0);

	hgg877a->Add(hgg877aa, hgg877ab, 1.0, -1.0);
	hgg877b->Add(hgg877ba, hgg877bb, 1.0, -1.0);
	hgg877b->Add(hgg877b, -0.5);
	hgg877->Add(hgg877a, hgg877b, 1.0, -1.0);
	hg877a->Add(hg877aa, hg877ab, 1.0, -1.0);
	hg877b->Add(hg877ba, hg877bb, 1.0, -1.0);
	hg877b->Add(hg877b, -0.5);
	hg877->Add(hg877a, hg877b, 1.0, -1.0);

	hgg646a->Add(hgg646aa, hgg646ab, 1.0, -1.0);
	hgg646b->Add(hgg646ba, hgg646bb, 1.0, -1.0);
	hgg646b->Add(hgg646b, -0.5);
	hgg646->Add(hgg646a, hgg646b, 1.0, -1.0);
	hg646a->Add(hg646aa, hg646ab, 1.0, -1.0);
	hg646b->Add(hg646ba, hg646bb, 1.0, -1.0);
	hg646b->Add(hg646b, -0.5);
	hg646->Add(hg646a, hg646b, 1.0, -1.0);
	hg->Add(hg1002, hg877, 1.0, 1.0);
	hg->Add(hg646, 1.0);
	hgg->Add(hgg1002, hgg877, 1.0, 1.0);
	hgg->Add(hgg646, 1.0);

	hC->Add(hCa, hCb, 1.0, -1.0);
	hggC->Add(hggCa, hggCb, 1.0, -1.0);
	hdt1002b->Add(hdt1002b, -0.5);
	hdt1002->Add(hdt1002a, hdt1002b, 1.0, -1.0);
	hdt877b->Add(hdt877b, -0.5);
	hdt877->Add(hdt877a, hdt877b, 1.0, -1.0);
	hdt646b->Add(hdt646b, -0.5);
	hdt646->Add( hdt646a, hdt646b, 1.0, -1.0);
//	ipf->Close();
	TFile *opf = new TFile(Form("../data/IDT/IDT%03d.root", run), "RECREATE");
	h646A877dt1a->Write();
	h646A877dt1b->Write();
	h646A877dt1->Write();
	h646A877de1aa->Write();
	h646A877de1ab->Write();
	h646A877de1ba->Write();
	h646A877de1bb->Write();
	h646A877de1a->Write();
	h646A877de1b->Write();
	h646A877de1->Write();
	hg1002aa->Write();
	hg1002ab->Write();
	hg1002ba->Write();
	hg1002bb->Write();
	hg1002a->Write();
	hg1002b->Write();
	hg1002->Write();
	hgg1002aa->Write();
	hgg1002ab->Write();
	hgg1002ba->Write();
	hgg1002bb->Write();
	hgg1002a->Write();
	hgg1002b->Write();
	hgg1002->Write();

	hg877aa->Write();
	hg877ab->Write();
	hg877ba->Write();
	hg877bb->Write();
	hg877a->Write();
	hg877b->Write();
	hg877->Write();
	hgg877aa->Write();
	hgg877ab->Write();
	hgg877ba->Write();
	hgg877bb->Write();
	hgg877a->Write();
	hgg877b->Write();
	hgg877->Write();
	hg646aa->Write();
	hg646ab->Write();
	hg646ba->Write();
	hg646bb->Write();
	hg646a->Write();
	hg646b->Write();
	hg646->Write();
	hgg646aa->Write();
	hgg646ab->Write();
	hgg646ba->Write();
	hgg646bb->Write();
	hgg646a->Write();
	hgg646b->Write();
	hgg646->Write();

	hg->Write();
	hgg->Write();

	hCa->Write();
	hCb->Write();
	hC->Write();
	hggCa->Write();
	hggCb->Write();
	hggC->Write();
	hdt1002a->Write();
	hdt1002b->Write();
	hdt1002->Write();
	hdt877a->Write();
	hdt877b->Write();
	hdt877->Write();
	hdt646a->Write();
	hdt646b->Write();
	hdt646->Write();

	opf->Close();
	opf->Delete();
	
	h646A877dt1a->Delete();
	h646A877dt1b->Delete();
	h646A877dt1->Delete();
	h646A877de1aa->Delete();
	h646A877de1ab->Delete();
	h646A877de1ba->Delete();
	h646A877de1bb->Delete();
	h646A877de1a->Delete();
	h646A877de1b->Delete();
	h646A877de1->Delete();
	hg1002aa->Delete();
	hg1002ab->Delete();
	hg1002ba->Delete();
	hg1002bb->Delete();
	hg1002a->Delete();
	hg1002b->Delete();
	hg1002->Delete();
	hgg1002aa->Delete();
	hgg1002ab->Delete();
	hgg1002ba->Delete();
	hgg1002bb->Delete();
	hgg1002a->Delete();
	hgg1002b->Delete();
	hgg1002->Delete();
	hg877aa->Delete();
	hg877ab->Delete();
	hg877ba->Delete();
	hg877bb->Delete();
	hg877a->Delete();
	hg877b->Delete();
	hg877->Delete();
	hgg877aa->Delete();
	hgg877ab->Delete();
	hgg877ba->Delete();
	hgg877bb->Delete();
	hgg877a->Delete();
	hgg877b->Delete();
	hgg877->Delete();
	hg646aa->Delete();
	hg646ab->Delete();
	hg646ba->Delete();
	hg646bb->Delete();
	hg646a->Delete();
	hg646b->Delete();
	hg646->Delete();
	hgg646aa->Delete();
	hgg646ab->Delete();
	hgg646ba->Delete();
	hgg646bb->Delete();
	hgg646a->Delete();
	hgg646b->Delete();
	hgg646->Delete();
	hCa->Delete();
	hCb->Delete();
	hC->Delete();
	hggCa->Delete();
	hggCb->Delete();
	hggC->Delete();
	hdt1002a->Delete();
	hdt1002b->Delete();
	hdt1002->Delete();
	hdt877a->Delete();
	hdt877b->Delete();
	hdt877->Delete();
	hdt646a->Delete();
	hdt646b->Delete();
	hdt646->Delete();
	hg->Delete();
	hgg->Delete();

	return 0;
}
