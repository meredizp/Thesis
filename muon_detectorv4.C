#include <iostream>
#include <TFile.h>
#include <TString.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
using namespace std;





void muon_detectorv4() 
{
     // File Inputs
    TString input_csv           = "Coincidence_data/w100001.csv";
    TString csv_column_headers  = "C1:C2:C3:C4";
    TString output_filename     = "test_coinc2.root";


    // Creates a new .ROOT file as well as a TTree
    TFile *f = new TFile(output_filename,"RECREATE");
    // TH1F *h1 = new TH1F("h1", "coincidence histo", 100,0,100);
    TTree *T = new TTree("T","data from ascii file");

   // Loop through each CSV file
    for (const auto& filename : filenames) {
        // Read the CSV file and fill the TTree
        T->ReadFile(filename.c_str(), csv_column_headers);
    }



    // Loads .csv data to that TTree
    Long64_t nlines = T->ReadFile(input_csv, csv_column_headers, ',');
    printf("Found %lld entries, and loaed them into the tree\n",nlines);
    
    T->Write();
}