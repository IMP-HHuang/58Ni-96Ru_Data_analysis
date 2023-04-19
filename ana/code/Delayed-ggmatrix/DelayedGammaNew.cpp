

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


void DelayedGamma(TString fname)
{
//	TFile *ipf = new TFile("../data/bdecay-Recoil-isomer-LongTime.root");
	TFile *ipf = new TFile(fname);
	TTree *tree = (TTree*)gROOT->FindObject("tree");
	vector<double> *rGe, *rCe, *rPxE, *rPyE;
	vector<Long64_t> *rGts, *rCts, *dCts, *rPxts, *rPyts;
	vector<double> *dCe;
	Int_t idecay;
	Double_t dxe =0.0;
	Double_t tdecay = 0.0;
	rGe = NULL;
	rCe = 0;
	rGts = 0;
	dCts = 0;
	rCts = 0;
	rPxE = 0;
	rPxts = 0;
	idecay = 0;
	Long64_t rts;
	tree->SetBranchAddress("rts", &rts);
	tree->SetBranchAddress("idecay", &idecay);
//	tree->SetBranchAddress("tdecay", &tdecay);
//	tree->SetBranchAddress("dxe", &dxe);
//	tree->SetBranchAddress("rGeE", &rGe);
//	tree->SetBranchAddress("rGets", &rGts);
	tree->SetBranchAddress("rCloverE", &rCe);
	tree->SetBranchAddress("rCloverts", &rCts);
	tree->SetBranchAddress("rPgeXE", &rPxE);
	tree->SetBranchAddress("rPgeXts", &rPxts);

	ULong64_t nall =tree->GetEntriesFast();
	Int_t  flag = 0;
	for(ULong64_t i=0; i < nall; i++)
	{
	//    cout << i << endl;
//	cout <<"\033[31m bg  "<<  i <<"\033[0m" << endl;
//	if(i>10)  break;
    	tree->GetEntry(i);
//	cout <<"\033[31m bg1  "<<  i  << "  " << (*rPxE).size() <<"  " << (*rPxts).size()<< "\033[0m" << endl;
 	   if(idecay != 0)  continue;
	//    bool bfill = false;
//	cout <<"\033[31m bg1  "<<  i <<"\033[0m" << endl;

	   //Clover
    	for(int j=0; j<(*rCe).size(); j++)
    	{
			//if((*rCts)[j]- rts < -100000 || (*rCts)[j]- rts > 100000)	continue;
	   		flag = 0;
            if((*rCts)[j]- rts > 1500 && (*rCts)[j]- rts < 100000)
			{
                hgClovera->Fill((*rCe)[j]);
				flag = 1;
			}
            if((*rCts)[j]- rts < -1500 && (*rCts)[j]- rts > -100000)
			{
				flag = 2;
                hgCloverb->Fill((*rCe)[j]);
			}
			if(flag == 0)	continue;
        	for(int k=0; k<(*rCe).size(); k++)
        	{
            	if(abs((*rCts)[j] -(*rCts)[k]) > 100)  continue;
            	if(j==k)  continue;
				if(flag == 1)
            	    hggClovera->Fill((*rCe)[j], (*rCe)[k]);
            	else if(flag == 2)
            	    hggCloverb->Fill((*rCe)[j], (*rCe)[k]);
        	}
    	}
/*
		//PGe X 
    	for(int j=0; j<(*rPxE).size(); j++)
    	{
            if((*rPxts)[j]- rts > 1500 && (*rPxts)[j]- rts < 100000)
           	    hgPGeXa->Fill((*rPxE)[j]);
           	else if((*rPxts)[j]- rts < -1500 && (*rPxts)[j]- rts > -100000)
           	    hgPGeXb->Fill((*rPxE)[j]);
        	for(int k=0; k<(*rPxE).size(); k++)
        	{
            	if(j==k)  continue;
            	if(abs((*rPxts)[j] -(*rPxts)[k]) > 100)  continue;
            	if((*rPxts)[j]- rts > 1500 && (*rPxts)[j]- rts < 100000)
            	    hggPGeXa->Fill((*rPxE)[j], (*rPxE)[k]);
            	else if((*rPxts)[j]- rts < -1500 && (*rPxts)[j]- rts > -100000)
            	    hggPGeXb->Fill((*rPxE)[j], (*rPxE)[k]);
        	}
    	}
		*/
    	if( i%1000 == 0)
    	{
    	    //cout << i << endl;
    	    cout << Form("Process %.2f %%, %lld  / %lld \r", Double_t(i)/Double_t(nall)*100.0, i, nall);
    	    std::cout << std::flush;
    	}
	}
}

void DelayedGammaNew()
{
	for(int i=7; i<=8; i++)
	{
		cout << "\033[31m  Run   " << i <<"        \033[0m" << endl;
		DelayedGamma(Form("/home/huanghao/data/58Ni+96Ru/data/Recoil%03d.root", i));
	}
	hggClover->Add(hggClovera, hggCloverb, 1.0, -1.0);
	hgClover->Add(hgClovera, hgCloverb, 1.0, -1.0);
	hggPGeX->Add(hggPGeXa, hggPGeXb, 1.0, -1.0);
	hgPGeX->Add(hgPGeXa, hgPGeXb, 1.0, -1.0);
	TFile *opf = new TFile("f.root", "RECREATE");
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
	opf->Close();
}
