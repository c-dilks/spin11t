#ifndef RunData12_
#define RunData12_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include "TSystem.h"
#include "TObject.h"
#include "TTree.h"
#include "TFile.h"


class RunData12 : public TObject
{
  public:
    RunData12();
    RunData12(char * spindir0);
    void Construct(char * spindir0);
    Int_t GetFill(Int_t runnum0);
    Int_t HashRun(Int_t runnum0);
    Float_t Rellum(Int_t runnum0, Int_t rellumi, char * detector);
    Float_t RellumErr(Int_t runnum0, Int_t rellumi, char * detector);
    Bool_t RellumConsistent(Int_t runnum0); // true if rellumi consistent (defined for R3)
    Float_t BluePol(Int_t runnum0);
    Float_t YellPol(Int_t runnum0);
    Float_t BluePolErr(Int_t runnum0);
    Float_t YellPolErr(Int_t runnum0);
    Int_t BlueSpin(Int_t runnum0, Int_t bXing);
    Int_t YellSpin(Int_t runnum0, Int_t bXing);
    Bool_t Kicked(Int_t runnum0, Int_t bXing);
    Int_t Pattern(Int_t runnum0);
    Float_t Scarat(Int_t runnum0, char * bit_combo, Int_t spinbit);

    char spindir[256];

    // loop maxes
    Int_t NRUNS;
    Int_t NFILLS;

    // branches -- rtree tree
    Int_t i_rtree; // run index
    Int_t runnum;
    Int_t fill_rtree;
    Double_t t; // run time
    Float_t R_bbc[10]; // rellum
    Float_t R_zdc[10];
    Float_t R_vpd[10];
    Float_t R_bbc_err[10]; // rellum uncertainty
    Float_t R_zdc_err[10];
    Float_t R_vpd_err[10];
    Bool_t isConsistent; // true iff zdc & vpd agree
    Float_t scarat_arr[3][4]; // scaler ratio zdc_mul / vpd_mul

    // branches -- counts tree
    Int_t i_counts; // run index
    Int_t bx; // bXing # @ STAR
    Int_t blue; // blue spin
    Int_t yell; // yellow spin
    Bool_t kicked; // true if bXing empty according to scaler data

    // branches -- pol tree
    Int_t fill_pol;
    Float_t b_pol,y_pol; // polarization
    Float_t b_pol_err,y_pol_err; // polarization uncertainty
    Int_t pattern_no;

    // data arrays
    Int_t fill_thou; // set to 15000 for run11
    Int_t blue_spin_map[2000][120]; // [max no. runs (assumed)] [no. bXings] 
    Int_t yell_spin_map[2000][120]; 
    Int_t kicked_bx_map[2000][120]; 
    Int_t runnum_map[2000];
    Float_t b_pol_map[1000]; // [max no. fills (assumed)]
    Float_t y_pol_map[1000];
    Float_t b_pol_err_map[1000];
    Float_t y_pol_err_map[1000];
    Int_t pattern_map[1000];


    // TFiles
    TFile * counts;
    TFile * rtree;
    TFile * pol;
    TTree * counts_tr;
    TTree * rtree_tr;
    TTree * pol_tr;
    ClassDef(RunData12,1);
};

#endif
