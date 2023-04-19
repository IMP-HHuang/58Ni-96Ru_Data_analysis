#include <TMath.h>

#ifndef _PAR_H_
#define _PAR_H_

//input file
#define INPUTFILEPATH "../data/event/"
#define INPUTFILENAME "event"
//input tree
#define INPUTTREENAME "tree"

// output file
#define OUTPUTFILEPATH "../data/ggmatrix/"
#define OUTPUTFILENAME "ggmatrix"

//output tree
#define OUTPUTTREENAME "tree"

// MWPC
const Double_t MwpcTh = 0.0;

//DSSD x
const Double_t DSSDxETh  = 0.0;
#define DSSDxCutMargin 0
const Int_t DSSDxMargin0 = 0;
const Int_t DSSDxMargin1 = 119;
#define DSSDxCutBadStrip 0
//DSSD y
const Double_t DSSDyETh = 0.0;
const Long64_t DSSDyTime = 10;
#define DSSDyCutMargin 0
const Int_t DSSDyMargin0 = 0;
const Int_t DSSDyMargin1 = 39;
#define DSSDyCutBadStrip 0


//Ge
const Double_t GeETh = 0.0;
const Long64_t GeTime = 10;

//time window
#define OpenTimeWindow 1
const Long64_t DtxyMin = -100; //ns
const Long64_t DtxyMax = 100; //ns

//Strip cut
#define OpenStripCut 1
//Multi


#define OpenFrontBackE 0
#define FrontBackEHighLow 14000   //keV
#define dEFrontBackL 200   //keV 
#define dEFrontBackH 500   //keV

//position 
#define OpenCrosstalk 0
#define OpenOneEvent 1

//Recoil
#define Recoilxemin  9000 //keV
#define Recoilxemax 12000  //keV
#define RecoilMwpcmin 2000
#define RecoilMwpcmax 0  //0--close
// Decay
#define Decayxemin 100   //keV 0--close
#define Decayxemax 10000 //keV

// time window of decay A
#define DecayNt 0.5 //s
#define DecayPt 0.5 //s

//same position
const Double_t PositionDetx = 0.95;
const Double_t PositionDety = 0.95;

//Delayed gamma
const Double_t DelayedGammaTimeMin = 2; //us
const Double_t DelayedGammaTimeMax = 200; //us



#endif  /* end of par.h*/
