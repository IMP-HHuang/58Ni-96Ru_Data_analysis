#include <TMath.h>

#ifndef _PAR_H_
#define _PAR_H_

//input file
#define INPUTFILEPATH "../data/root/"
#define INPUTFILENAME "root"
//input tree
#define INPUTTREENAME "tree"

// output file
#define OUTPUTFILEPATH "../data/eventBHCal/"
#define OUTPUTFILENAME "event"

//output tree
#define OUTPUTTREENAME "tree"

//rate
const Long64_t AllTime = 10;

// MWPC
const Double_t MwpcTh = 0.0;
const Long64_t MwpcTime = 10;

#define  OpenFrontBackCalibration  1

//DSSD x
const Double_t DSSDxETh  = 0.0;
const Long64_t DSSDxTime = 10;
#define DSSDxMargin1 119

//DSSD y
const Double_t DSSDyETh = 0.0;
const Long64_t DSSDyTime = 10;
#define DSSDyMargin1 39

#define OpenEnergyCalibration 1
const Double_t DSSD_ke = 0.671643;
const Double_t DSSD_be = -245.433;
#define OpenEnergyCalibrationOut 0


//Ge
const Double_t GeETh = 0.0;
const Long64_t GeTime = 10;

const Long64_t EventWindow = 2;  //us


#endif  /* end of par.h*/
