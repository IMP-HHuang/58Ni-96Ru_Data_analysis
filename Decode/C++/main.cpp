//troot.cpp

#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <TStyle.h>
#include "TString.h"
//#include <stringtodouble.h>
#include<TFile.h>
#include<TTree.h>
#include<time.h>
//#include "stringtobool.h"
using namespace std;
#pragma pack(push)
#pragma pack(1)

struct mwpc
{
	Bool_t fail;
	Bool_t piledup;
	Bool_t vaild;
	Bool_t vetoed;
    Double_t e; 
	Double_t x1; 
	Double_t x2;
	Double_t y1;
	Double_t y2;
   	Long64_t t;
};
struct dssd
{
    Int_t x_count;
	Int_t y_count;
    Double_t emax; 
	Double_t xmax;
	Double_t ymax;
    Double_t xe[500];
	Double_t xoe[500];
    Int_t xid[500];
    Long64_t xt[500];
    Bool_t xfail[500];
	Bool_t xpiledup[500];
	Bool_t xvaild[500];
	Bool_t xvetoed[500];
    Double_t ye[500];
	Double_t yoe[500];
    Int_t yid[500];
    Long64_t yt[500];
    Bool_t yfail[500];
	Bool_t ypiledup[500];
	Bool_t yvaild[500];
	Bool_t yvetoed[500];
};
struct Pin
{
    Int_t count;
    Double_t e[500];
	Double_t oe[500];
    Int_t id[500];
    Long64_t t[100];
    Bool_t fail[500];
	Bool_t piledup[500]; 
	Bool_t vaild[500]; 
	Bool_t vetoed[500];
};
struct Pge
{
    Int_t x_count;
	Int_t y_count;
    Double_t emax; 
	Double_t xmax;
	Double_t ymax;
    Double_t xe[500];
	Double_t xoe[500];
    Int_t xid[500];
    Long64_t xt[500];
    Bool_t xfail[500];
	Bool_t xpiledup[500];
	Bool_t xvaild[500];
	Bool_t xvetoed[500];
    Double_t ye[500];
	Double_t yoe[500];
    Int_t yid[500];
    Long64_t yt[500];
    Bool_t yfail[500];
	Bool_t ypiledup[500];
	Bool_t yvaild[500];
	Bool_t yvetoed[500];
};
struct Clover
{
    Int_t count;
    Double_t e[500];
	Double_t oe[500];
    Int_t id[500];
    Long64_t t[500];
    Double_t phi[500];
	Double_t theta[500];
    Int_t ring[500];
    Bool_t fail[500];
	Bool_t piledup[500];
	Bool_t vaild[500];
	Bool_t vetoed[500];
};
struct Gamma
{
    Int_t count;
    Double_t e[500];
	Double_t oe[500];
    Int_t id[500];
    Long64_t t[500];
    Double_t phi[500];
	Double_t theta[500];
    Int_t ring[500];
    Bool_t fail[500];
	Bool_t piledup[500];
	Bool_t vaild[500];
	Bool_t vetoed[500];
};

#pragma pack(pop)

int main(int argv, char* argc[])
{
	int run = atoi(argc[1]);
    time_t begin = clock(), end;
    string s1, s2, s3, s4, s5, s6;
    //	stringstream sstream1, sstream2, sstream3, sstream4, sstream5, sstream6;
    string name;
    Long64_t  stamp = 0;
    Double_t  tof = 0;
    Double_t rate = 0;
    mwpc MWPC;
    dssd DSSD;
    Pin pin;
    Pge pge;
    Clover clover;
    Gamma gamma;
    TFile* outfile;
    TTree* tree; 
    outfile = new TFile(Form("../data/root/root%03d.root", run), "RECREATE");
    tree = new TTree("tree", "data");

    tree->Branch("stamp", &stamp, "stamp/L");

    tree->Branch("tof", &tof, "tof/D");
    tree->Branch("rate", &rate, "rate/D");

	tree->Branch("MWPC_e", &MWPC.e, "MWPC_e/D");
	tree->Branch("MWPC_t", &MWPC.t, "MWPC_t/L");
    tree->Branch("MWPC_x1", &MWPC.x1, "MWPC_x1/D");
    tree->Branch("MWPC_x2", &MWPC.x2, "MWPC_x2/D");
    tree->Branch("MWPC_y1", &MWPC.y1, "MWPC_y1/D");
    tree->Branch("MWPC_y2", &MWPC.y2, "MWPC_y2/D");
    tree->Branch("MWPC_fail", &MWPC.fail, "MWPC_fail/O");
    tree->Branch("MWPC_piledup", &MWPC.piledup, "MWPC_piledup/O");
    tree->Branch("MWPC_vaild", &MWPC.vaild, "MWPC_vaild/O");
    tree->Branch("MWPC_vetoed", &MWPC.vetoed, "MWPC_vetoed/O");

	tree->Branch("DSSD_emax", &DSSD.emax, "DSSD_emax/D");
	tree->Branch("DSSD_xmax", &DSSD.xmax, "DSSD_xmax/D");
	tree->Branch("DSSD_ymax", &DSSD.ymax, "DSSD_ymax/D");
    tree->Branch("DSSD_xcount", &DSSD.x_count, "DSSD_xcount/I");
    tree->Branch("DSSD_xe", &DSSD.xe[0], "DSSD_xe[DSSD_xcount]/D");
	tree->Branch("DSSD_xoe", &DSSD.xoe[0], "DSSD_xoe[DSSD_xcount]/D");
	tree->Branch("DSSD_xid", &DSSD.xid[0], "DSSD_xid[DSSD_xcount]/I");
	tree->Branch("DSSD_xt", &DSSD.xt[0], "DSSD_xt[DSSD_xcount]/L");
	tree->Branch("DSSD_xfail", &DSSD.xfail[0], "DSSD_xfail[DSSD_xcount]/O");
	tree->Branch("DSSD_xpiledup", &DSSD.xpiledup[0], "DSSD_xpiledup[DSSD_xcount]/O");
	tree->Branch("DSSD_xvaild", &DSSD.xvaild[0], "DSSD_xvaild[DSSD_xcount]/O");
    tree->Branch("DSSD_xvetoed", &DSSD.xvetoed[0], "DSSD_xvetoed[DSSD_xcount]/O");
	tree->Branch("DSSD_ycount", &DSSD.y_count, "DSSD_ycount/I");
    tree->Branch("DSSD_ye", &DSSD.ye[0], "DSSD_ye[DSSD_ycount]/D");
    tree->Branch("DSSD_yoe", &DSSD.yoe[0], "DSSD_yoe[DSSD_ycount]/D");
    tree->Branch("DSSD_yid", &DSSD.yid[0], "DSSD_yid[DSSD_ycount]/I");
    tree->Branch("DSSD_yt", &DSSD.yt[0], "DSSD_yt[DSSD_ycount]/L");
    tree->Branch("DSSD_yfail", &DSSD.yfail[0], "DSSD_yfail[DSSD_ycount]/O");
    tree->Branch("DSSD_ypiledup", &DSSD.ypiledup[0], "DSSD_ypiledup[DSSD_ycount]/O");
    tree->Branch("DSSD_yvaild", &DSSD.yvaild[0], "DSSD_yvaild[DSSD_ycount]/O");
    tree->Branch("DSSD_yvetoed", &DSSD.yvetoed[0], "DSSD_yvetoed[DSSD_ycount]/O");
	tree->Branch("pin_count", &pin.count, "pin_count/I");
	tree->Branch("pin_e", &pin.e[0], "pin_e[pin_count]/D");
	tree->Branch("pin_oe", &pin.oe[0], "pin_oe[pin_count]/D");
	tree->Branch("pin_id", &pin.id[0], "pin_id[pin_count]/I");
	tree->Branch("pin_t", &pin.t[0], "pin_t[pin_count]/L");
    tree->Branch("pin_fail", &pin.fail[0], "pin_fail[pin_count]/O");
    tree->Branch("pin_piledup", &pin.piledup[0], "pin_piledup[pin_count]/O");
    tree->Branch("pin_vaild", &pin.vaild[0], "pin_vaild[pin_count]/O");
    tree->Branch("pin_vetoed", &pin.vetoed[0], "pin_vetoed[pin_count]/O");
    tree->Branch("pge_emax", &pge.emax, "pge_emax/D");
    tree->Branch("pge_xmax", &pge.xmax, "pge_xmax/D");
    tree->Branch("pge_ymax", &pge.ymax, "pge_ymax/D");
    tree->Branch("pge_xcount", &pge.x_count, "pge_xcount/I");
    tree->Branch("pge_xe", &pge.xe[0], "pge_xe[pge_xcount]/D");
    tree->Branch("pge_xoe", &pge.xoe[0], "pge_xoe[pge_xcount]/D");
    tree->Branch("pge_xid", &pge.xid[0], "pge_xid[pge_xcount]/I");
    tree->Branch("pge_xt", &pge.xt[0], "pge_xt[pge_xcount]/L");
    tree->Branch("pge_xfail", &pge.xfail[0], "pge_xfail[pge_xcount]/O");
    tree->Branch("pge_xpiledup", &pge.xpiledup[0], "pge_xpiledup[pge_xcount]/O");
    tree->Branch("pge_xvaild", &pge.xvaild[0], "pge_xvaild[pge_xcount]/O");
    tree->Branch("pge_xvetoed", &pge.xvetoed[0], "pge_xvetoed[pge_xcount]/O");
    tree->Branch("pge_ycount", &pge.y_count, "pge_ycount/I");
    tree->Branch("pge_ye", &pge.ye[0], "pge_ye[pge_ycount]/D");
    tree->Branch("pge_yoe", &pge.yoe[0], "pge_yoe[pge_ycount]/D");
    tree->Branch("pge_yid", &pge.yid[0], "pge_yid[pge_ycount]/I");
    tree->Branch("pge_yt", &pge.yt[0], "pge_yt[pge_ycount]/L");
    tree->Branch("pge_yfail", &pge.yfail[0], "pge_yfail[pge_ycount]/O");
    tree->Branch("pge_ypiledup", &pge.ypiledup[0], "pge_ypiledup[pge_ycount]/O");
    tree->Branch("pge_yvaild", &pge.yvaild[0], "pge_yvaild[pge_ycount]/O");
    tree->Branch("pge_yvetoed", &pge.yvetoed[0], "pge_yvetoed[pge_ycount]/O");

	tree->Branch("clover_count", &clover.count, "clover_count/I");
    tree->Branch("clover_e", &clover.e[0], "clover_e[clover_count]/D");
    tree->Branch("clover_oe", &clover.oe[0], "clover_oe[clover_count]/D");
    tree->Branch("clover_id", &clover.id[0], "clover_id[clover_count]/I");
    tree->Branch("clover_t", &clover.t[0], "clover_t[clover_count]/L");	
	tree->Branch("clover_phi", &clover.phi[0], "clover_phi[clover_count]/D");
	tree->Branch("clover_theta", &clover.theta[0], "clover_theta[clover_count]/D");
	tree->Branch("clover_ring", &clover.ring[0], "clover_ring[clover_count]/I");
    tree->Branch("clover_fail", &clover.fail[0], "clover_fail[clover_count]/O");
    tree->Branch("clover_piledup", &clover.piledup[0], "clover_piledup[clover_count]/O");
    tree->Branch("clover_vaild", &clover.vaild[0], "clover_vaild[clover_count]/O");
    tree->Branch("clover_vetoed", &clover.vetoed[0], "clover_vetoed[clover_count]/O");

    tree->Branch("gamma_count", &gamma.count, "gamma_count/I");
    tree->Branch("gamma_e", &gamma.e[0], "gamma_e[gamma_count]/D");
    tree->Branch("gamma_oe", &gamma.oe[0], "gamma_oe[gamma_count]/D");
    tree->Branch("gamma_id", &gamma.id[0], "gamma_id[gamma_count]/I");
    tree->Branch("gamma_t", &gamma.t[0], "gamma_t[gamma_count]/L");
    tree->Branch("gamma_phi", &gamma.phi[0], "gamma_phi[gamma_count]/D");
    tree->Branch("gamma_theta", &gamma.theta[0], "gamma_theta[gamma_count]/D");
    tree->Branch("gamma_ring", &gamma.ring[0], "gamma_ring[gamma_count]/I");
    tree->Branch("gamma_fail", &gamma.fail[0], "gamma_fail[gamma_count]/O");
    tree->Branch("gamma_piledup", &gamma.piledup[0], "gamma_piledup[gamma_count]/O");
    tree->Branch("gamma_vaild", &gamma.vaild[0], "gamma_vaild[gamma_count]/O");
    tree->Branch("gamma_vetoed", &gamma.vetoed[0], "gamma_vetoed[gamma_count]/O");

	ofstream timeoutfile(Form("./time%d.txt", run));	
    ifstream infile(Form("../data/txtNew/data%03d.txt", run));
    ULong64_t n = 0;

    if (infile.is_open())
    {
        while (!infile.eof())
        {
            n++;
	//		if(n > 10) break;
		//	continue;
					//cout << n << endl;
            stamp = 0;
            tof = 0;
            rate = 0;
            memset(&MWPC, 0, sizeof(MWPC));
            memset(&DSSD, 1, sizeof(DSSD));
            memset(&pin, 0, sizeof(pin));
            memset(&pge, 0, sizeof(pge));
            memset(&clover, 0, sizeof(clover));
            memset(&gamma, 0, sizeof(gamma));
          //  infile >> stamp >> rate >> tof;
            infile >> stamp >> tof;
            //infile>>s1>>s2>>s3;
            //sstream1 << s1 << endl;	  sstream2 << s2 << endl;   sstream3 << s3 << endl;
            //sstream1>>stamp;   		  sstream2>>rate;   	    sstream3>>tof;
         //   cout<<stamp<<"\t"<<rate<<"\t"<<fixed<<setprecision(12)<<tof<<endl;
            //MWPC
			if(infile.eof()) break;
//            infile >> name;
            	//		cout<<name<<endl;
			if(infile.eof()) break;
            infile >> MWPC.e;
			if(MWPC.e > 0)
            	infile >> MWPC.t >> MWPC.x1 >> MWPC.x2 >> MWPC.y1 >> MWPC.y2;
//			if(n % 160000 == 0) 
//			{
	//			cout << n << "   " << n/160000  << "   MWPC_t  " << MWPC.t << endl;
//			}
       //     cout<<"MWPC" << MWPC.e<<"\t"<<MWPC.t<<"\t"<<MWPC.x1<<"\t"<<MWPC.x2<<"\t"<<MWPC.y1<<"\t"<<MWPC.y2<<"\t"<<endl;
			if(infile.eof()) break;
			if(MWPC.e > 0)
			{
            	infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>MWPC.fail;
				istringstream(s2)>>boolalpha>>MWPC.piledup;
				istringstream(s3)>>boolalpha>>MWPC.vaild;
				istringstream(s4)>>boolalpha>>MWPC.vetoed;
			}
    //        MWPC.fail = stringtobool(s1);
   //         MWPC.piledup = stringtobool(s2);
     //       MWPC.vaild = stringtobool(s3);
       //     MWPC.vetoed = stringtobool(s4);
//            cout<<MWPC.fail<<"\t"<<MWPC.piledup<<"\t"<<MWPC.vaild<<"\t"<<MWPC.vetoed<<endl;
            //DSSD
			if(infile.eof()) break;
  //          infile >> name;
			if(infile.eof()) break;
 //         cout<<name<<endl;
          //  infile >> DSSD.emax >> DSSD.xmax >> DSSD.ymax >> DSSD.x_count;
            infile >> DSSD.x_count;
			if(infile.eof()) break;
			if(DSSD.x_count >= 100) cout << n << " DSSD.x_count   " << DSSD.x_count << endl;

     //      cout << " DSSD count : " <<DSSD.emax<<"\t"<<DSSD.xmax<<"\t"<<DSSD.ymax<<endl<<DSSD.x_count<<endl;
            
		for (int i = 0; i < DSSD.x_count; i++)
            {
				if(infile.eof()) break;
              //  infile >> DSSD.xe[i] >> DSSD.xoe[i] >> DSSD.xid[i] >> DSSD.xt[i];
                infile >> DSSD.xe[i] >> DSSD.xoe[i] >> DSSD.xid[i] >> DSSD.xt[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>DSSD.xfail[i];
				istringstream(s2)>>boolalpha>>DSSD.xpiledup[i];
				istringstream(s3)>>boolalpha>>DSSD.xvaild[i];
				istringstream(s4)>>boolalpha>>DSSD.xvetoed[i];

   //             DSSD.xfail[i] = stringtobool(s1);
     //           DSSD.xpiledup[i] = stringtobool(s2);
       //         DSSD.xvaild[i] = stringtobool(s3);
         //       DSSD.xvetoed[i] = stringtobool(s4);
     //           				cout<<"error : " << DSSD.xe[i]<<"\t"<<DSSD.xoe[i]<<"\t"<<DSSD.xid[i]<<"\t"<<DSSD.xt[i]<<endl;
                //				cout<<DSSD.xfail[i]<<"\t"<<DSSD.xpiledup[i]<<"\t"<<DSSD.xvaild[i]<<"\t"<<DSSD.xvetoed[i]<<endl;
            }

			if(infile.eof()) break;
            infile >> DSSD.y_count;
			if(infile.eof()) break;
   //         cout << "DSSD y count" << DSSD.y_count << endl;

            for (int i = 0; i < DSSD.y_count; i++)
            {
				if(infile.eof()) break;
               // infile >> DSSD.ye[i] >> DSSD.yoe[i] >> DSSD.yid[i] >> DSSD.yt[i];
                infile >> DSSD.ye[i] >> DSSD.yoe[i] >> DSSD.yid[i] >> DSSD.yt[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>DSSD.yfail[i];
				istringstream(s2)>>boolalpha>>DSSD.ypiledup[i];
				istringstream(s3)>>boolalpha>>DSSD.yvaild[i];
				istringstream(s4)>>boolalpha>>DSSD.yvetoed[i];
          //      DSSD.yfail[i] = stringtobool(s1);
            //    DSSD.ypiledup[i] = stringtobool(s2);
              //  DSSD.yvaild[i] = stringtobool(s3);
                //DSSD.yvetoed[i] = stringtobool(s4);
                //				cout<<DSSD.ye[i]<<"\t"<<DSSD.yoe[i]<<"\t"<<DSSD.yid[i]<<"\t"<<DSSD.yt[i]<<endl;
                //				cout<<DSSD.yfail[i]<<"\t"<<DSSD.ypiledup[i]<<"\t"<<DSSD.yvaild[i]<<"\t"<<DSSD.yvetoed[i]<<endl;
                //				cout<<i<<endl;
            }

            //Pin Diode
			if(infile.eof()) break;
          //  infile >> name;
//            cout<<name<<endl;
            double tmp = 1.0;
			if(infile.eof()) break;
            infile >> tmp;
            pin.count = static_cast<int>(tmp);

            //			cout<<pin.count<<endl;
            for (int i = 0; i < pin.count; i++)
            {
				if(infile.eof()) break;
                infile >> pin.e[i] >> pin.oe[i] >> pin.id[i] >> pin.t[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>pin.fail[i];
				istringstream(s2)>>boolalpha>>pin.piledup[i];
				istringstream(s3)>>boolalpha>>pin.vaild[i];
				istringstream(s4)>>boolalpha>>pin.vetoed[i];
            //    pin.fail[i] = stringtobool(s1);
            //    pin.piledup[i] = stringtobool(s2);
            //    pin.vaild[i] = stringtobool(s3);
            //    pin.vetoed[i] = stringtobool(s4);
  //              cout<<pin.e[i]<<"\t"<<pin.oe[i]<<"\t"<<pin.id[i]<<"\t"<<pin.t[i]<<endl;
                //				cout<<pin.fail[i]<<"\t"<<pin.piledup[i]<<"\t"<<pin.vaild[i]<<"\t"<<pin.vetoed[i]<<endl;
            }

            //Planar GE
			if(infile.eof()) break;
   //         infile >> name;
   //         cout<<name<<endl;
			if(infile.eof()) break;
          //  infile >> pge.emax >> pge.xmax >> pge.ymax >> pge.x_count;
            infile >> pge.x_count;
			if(pge.x_count >= 100) cout << n << " pge.x_count   " << pge.x_count << endl;

     //       cout<<pge.emax<<"\t"<<pge.xmax<<"\t"<<pge.ymax<<endl<<pge.x_count<<endl;
            for (int i = 0; i < pge.x_count; i++)
            {
				if(infile.eof()) break;
                infile >> pge.xe[i] >> pge.xoe[i] >> pge.xid[i] >> pge.xt[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>pge.xfail[i];
				istringstream(s2)>>boolalpha>>pge.xpiledup[i];
				istringstream(s3)>>boolalpha>>pge.xvaild[i];
				istringstream(s4)>>boolalpha>>pge.xvetoed[i];
            //   pge.xfail[i] = stringtobool(s1);
            //   pge.xpiledup[i] = stringtobool(s2);
            //   pge.xvaild[i] = stringtobool(s3);
            //   pge.xvetoed[i] = stringtobool(s4);
                //                cout<<pge.xe[i]<<"\t"<<pge.xoe[i]<<"\t"<<pge.xid[i]<<"\t"<<pge.xt[i]<<endl;
                //                cout<<pge.xfail[i]<<"\t"<<pge.xpiledup[i]<<"\t"<<pge.xvaild[i]<<"\t"<<pge.xvetoed[i]<<endl;
            }

			if(infile.eof()) break;
            infile >> pge.y_count;
			if(pge.y_count >= 100) cout << n << " pge.y_count   " << pge.y_count << endl;

            //          cout<<pge.y_count<<endl;
            for (int i = 0; i < pge.y_count; i++)
            {
				if(infile.eof()) break;
                infile >> pge.ye[i] >> pge.yoe[i] >> pge.yid[i] >> pge.yt[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>pge.yfail[i];
				istringstream(s2)>>boolalpha>>pge.ypiledup[i];
				istringstream(s3)>>boolalpha>>pge.yvaild[i];
				istringstream(s4)>>boolalpha>>pge.yvetoed[i];
      //         pge.yfail[i] = stringtobool(s1);
      //         pge.ypiledup[i] = stringtobool(s2);
      //         pge.yvaild[i] = stringtobool(s3);
      //         pge.yvetoed[i] = stringtobool(s4);
                //                cout<<pge.ye[i]<<"\t"<<pge.yoe[i]<<"\t"<<pge.yid[i]<<"\t"<<pge.yt[i]<<endl;
                //                cout<<pge.yfail[i]<<"\t"<<pge.ypiledup[i]<<"\t"<<pge.yvaild[i]<<"\t"<<pge.yvetoed[i]<<endl;
            }

            //Clover
			if(infile.eof()) break;
     //       infile >> name;
			if(infile.eof()) break;
       //     cout<<name<<endl;
            infile >> tmp;
            clover.count = static_cast<int>(tmp);
			if(clover.count >= 100) cout << n << " clover.count   " << clover.count << endl;

         //   cout<<clover.count<<endl;
            for (int i = 0; i < clover.count; i++)
            {
				if(infile.eof()) break;
               // infile >> clover.id[i] >> clover.e[i] >> clover.oe[i] >> clover.t[i] >> clover.phi[i] >> clover.theta[i] >> clover.ring[i];
                infile >> clover.id[i] >> clover.e[i] >> clover.oe[i] >> clover.t[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>clover.fail[i];
				istringstream(s2)>>boolalpha>>clover.piledup[i];
				istringstream(s3)>>boolalpha>>clover.vaild[i];
				istringstream(s4)>>boolalpha>>clover.vetoed[i];
           //    clover.fail[i] = stringtobool(s1);
           //    clover.piledup[i] = stringtobool(s2);
           //    clover.vaild[i] = stringtobool(s3);
           //    clover.vetoed[i] = stringtobool(s4);
                //                cout<<clover.e[i]<<"\t"<<clover.oe[i]<<"\t"<<clover.id[i]<<"\t"<<clover.t[i]<<endl;
                //                cout<<clover.fail[i]<<"\t"<<clover.piledup[i]<<"\t"<<clover.vaild[i]<<"\t"<<clover.vetoed[i]<<endl;
            }

            //juro gamma
			if(infile.eof()) break;
    //        infile >> name;
			if(infile.eof()) break;
      //      cout<<name<<endl;
            infile >> tmp;
            gamma.count = static_cast<int>(tmp);
			if(gamma.count >= 100) cout << n << " gamma.count   " << gamma.count << endl;
//            cout << gamma.count << endl;

            for (int i = 0; i < gamma.count; i++)
            {
				if(infile.eof()) break;
                infile >> gamma.id[i] >> gamma.e[i] >> gamma.oe[i] >> gamma.t[i] >> gamma.phi[i] >> gamma.theta[i] >> gamma.ring[i];
				if(infile.eof()) break;
                infile >> s1 >> s2 >> s3 >> s4;
				istringstream(s1)>>boolalpha>>gamma.fail[i];
				istringstream(s2)>>boolalpha>>gamma.piledup[i];
				istringstream(s3)>>boolalpha>>gamma.vaild[i];
				istringstream(s4)>>boolalpha>>gamma.vetoed[i];
           //    gamma.fail[i] = stringtobool(s1);
           //    gamma.piledup[i] = stringtobool(s2);
           //    gamma.vaild[i] = stringtobool(s3);
           //    gamma.vetoed[i] = stringtobool(s4);
         //       cout << gamma.e[i] << "\t" << std::fixed << gamma.oe[i] << "\t" << gamma.id[i] << "\t" << gamma.t[i] << endl;
           //     cout << gamma.fail[i] << "\t" << gamma.piledup[i] << "\t" << gamma.vaild[i] << "\t" << gamma.vetoed[i] << endl;
            }

//            getline(infile, name);
  //          cout << "*******************************************" << endl;
            tree->Fill();

//            if (n > 1.0E10) // return 0;
//                goto exit;
		}
  //          			cout<<Double_t(n)/1.0E16<<endl;;
    }
    else
        cout << "Cannot open the file" << endl;
//	cout << "end!" << endl;
//exit:
    infile.close();
    outfile->cd();
    outfile->Write();
    tree->Delete();
    outfile->Delete();
    end = clock();
//    cout << "run time : " << double(end - begin) << endl;
	timeoutfile<<"Run time is "<<double(end - begin)/CLOCKS_PER_SEC<<" S "<<endl;
	timeoutfile.close();
    return 0;
}
