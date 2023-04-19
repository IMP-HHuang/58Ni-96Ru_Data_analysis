
#include "par.h"
#include "tree.h"
#include <TTree.h>
#include <TFile.h>
#include <TMath.h>
#include <TString.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

//using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2)
    {
      std::cout << "eg. ./xxx  [run number]" << std::endl;
      exit(1);
    }
  
  	int run = atoi(argv[1]);
	TString InputFilePath = INPUTFILEPATH;
	TString InputFileName = INPUTFILENAME;
    auto ipf = new TFile(Form("%s%s%03d.root", InputFilePath.Data(), InputFileName.Data(), run), "READ");
	if(ipf==0)
		std::cout << "Can not open the input file :"<< Form("%s%s-%03d.root", InputFilePath.Data(), InputFileName.Data(), run) << std::endl;
	TString InputTreeName = INPUTTREENAME; 
  	auto ipt = (TTree*)ipf->Get(InputTreeName.Data());
    TString OutputFilePath = OUTPUTFILEPATH;
    TString OutputFileName = OUTPUTFILENAME;

  	auto opf = new TFile(Form("%s%s%03d.root", OutputFilePath.Data(), OutputFileName.Data(), run), "RECREATE");
	TString OutTreeName = OUTPUTTREENAME;
  	auto opt = new TTree(OutTreeName.Data(), OutTreeName.Data());
  	auto it = new tree(ipt);
	it->Loop(opt,run);
  	opt->Write();
  	opf->Close();
  
  	return 0;
}

