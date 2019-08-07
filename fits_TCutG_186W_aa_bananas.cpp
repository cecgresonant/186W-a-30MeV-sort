// Script to grab the m_e_de_b0fX matrices for the 186W(a,a')  data
// and make graphical cuts around the alpha channel. 
// This is for calibration of the alpha particles. 
// Must first fix the energy of the ground state peak, and then check the maximum "ridge"
// along the banana to see that the gains are okay. 
// These should then be compared to the Qkinz calculations to check the calibration coefficients
// of the 186W(a,a') data set, with SiRi_QKinz_186W_aa.cpp
// NOTE: the E detectors are sometimes quite bad and instead of a Gaussian fit,
// I just took the bin with the maximum value.
// Cecilie, July 31, 2019
// Last update: August 6, 2019

#include <fstream>
#include <iostream>

void fits_TCutG_186W_aa_bananas(){
    // No stats shown
    gStyle->SetOptStat(0);

    // Grab input file
    TFile *file = TFile::Open("offline_186W_plain.root");

    // Back detector 0
	TH2D *banana_b0f0  = (TH2D*)file->Get("m_e_de_b0f0"); // Delta E - E matrix for b0f0
    TH2D *banana_b0f1  = (TH2D*)file->Get("m_e_de_b0f1"); // Delta E - E matrix for b0f1
    TH2D *banana_b0f2  = (TH2D*)file->Get("m_e_de_b0f2"); // Delta E - E matrix for b0f2
    TH2D *banana_b0f3  = (TH2D*)file->Get("m_e_de_b0f3"); // Delta E - E matrix for b0f3
    TH2D *banana_b0f4  = (TH2D*)file->Get("m_e_de_b0f4"); // Delta E - E matrix for b0f4
    TH2D *banana_b0f5  = (TH2D*)file->Get("m_e_de_b0f5"); // Delta E - E matrix for b0f5
    TH2D *banana_b0f6  = (TH2D*)file->Get("m_e_de_b0f6"); // Delta E - E matrix for b0f6
    TH2D *banana_b0f7  = (TH2D*)file->Get("m_e_de_b0f7"); // Delta E - E matrix for b0f7

    // Back detector 1
    TH2D *banana_b1f0  = (TH2D*)file->Get("m_e_de_b1f0"); // Delta E - E matrix for b1f0
    TH2D *banana_b1f1  = (TH2D*)file->Get("m_e_de_b1f1"); // Delta E - E matrix for b1f1
    TH2D *banana_b1f2  = (TH2D*)file->Get("m_e_de_b1f2"); // Delta E - E matrix for b1f2
    TH2D *banana_b1f3  = (TH2D*)file->Get("m_e_de_b1f3"); // Delta E - E matrix for b1f3
    TH2D *banana_b1f4  = (TH2D*)file->Get("m_e_de_b1f4"); // Delta E - E matrix for b1f4
    TH2D *banana_b1f5  = (TH2D*)file->Get("m_e_de_b1f5"); // Delta E - E matrix for b1f5
    TH2D *banana_b1f6  = (TH2D*)file->Get("m_e_de_b1f6"); // Delta E - E matrix for b1f6
    TH2D *banana_b1f7  = (TH2D*)file->Get("m_e_de_b1f7"); // Delta E - E matrix for b1f7

    // Back detector 2
    TH2D *banana_b2f0  = (TH2D*)file->Get("m_e_de_b2f0"); // Delta E - E matrix for b2f0
    TH2D *banana_b2f1  = (TH2D*)file->Get("m_e_de_b2f1"); // Delta E - E matrix for b2f1
    TH2D *banana_b2f2  = (TH2D*)file->Get("m_e_de_b2f2"); // Delta E - E matrix for b2f2
    TH2D *banana_b2f3  = (TH2D*)file->Get("m_e_de_b2f3"); // Delta E - E matrix for b2f3
    TH2D *banana_b2f4  = (TH2D*)file->Get("m_e_de_b2f4"); // Delta E - E matrix for b2f4
    TH2D *banana_b2f5  = (TH2D*)file->Get("m_e_de_b2f5"); // Delta E - E matrix for b2f5
    TH2D *banana_b2f6  = (TH2D*)file->Get("m_e_de_b2f6"); // Delta E - E matrix for b2f6
    TH2D *banana_b2f7  = (TH2D*)file->Get("m_e_de_b2f7"); // Delta E - E matrix for b2f7

    // Back detector 3
    TH2D *banana_b3f0  = (TH2D*)file->Get("m_e_de_b3f0"); // Delta E - E matrix for b3f0
    TH2D *banana_b3f1  = (TH2D*)file->Get("m_e_de_b3f1"); // Delta E - E matrix for b3f1
    TH2D *banana_b3f2  = (TH2D*)file->Get("m_e_de_b3f2"); // Delta E - E matrix for b3f2
    TH2D *banana_b3f3  = (TH2D*)file->Get("m_e_de_b3f3"); // Delta E - E matrix for b3f3
    TH2D *banana_b3f4  = (TH2D*)file->Get("m_e_de_b3f4"); // Delta E - E matrix for b3f4
    TH2D *banana_b3f5  = (TH2D*)file->Get("m_e_de_b3f5"); // Delta E - E matrix for b3f5
    TH2D *banana_b3f6  = (TH2D*)file->Get("m_e_de_b3f6"); // Delta E - E matrix for b3f6
    TH2D *banana_b3f7  = (TH2D*)file->Get("m_e_de_b3f7"); // Delta E - E matrix for b3f7

    // Back detector 4
    TH2D *banana_b4f0  = (TH2D*)file->Get("m_e_de_b4f0"); // Delta E - E matrix for b4f0
    TH2D *banana_b4f1  = (TH2D*)file->Get("m_e_de_b4f1"); // Delta E - E matrix for b4f1
    TH2D *banana_b4f2  = (TH2D*)file->Get("m_e_de_b4f2"); // Delta E - E matrix for b4f2
    TH2D *banana_b4f3  = (TH2D*)file->Get("m_e_de_b4f3"); // Delta E - E matrix for b4f3
    TH2D *banana_b4f4  = (TH2D*)file->Get("m_e_de_b4f4"); // Delta E - E matrix for b4f4
    TH2D *banana_b4f5  = (TH2D*)file->Get("m_e_de_b4f5"); // Delta E - E matrix for b4f5
    TH2D *banana_b4f6  = (TH2D*)file->Get("m_e_de_b4f6"); // Delta E - E matrix for b4f6
    TH2D *banana_b4f7  = (TH2D*)file->Get("m_e_de_b4f7"); // Delta E - E matrix for b4f7

    // Back detector 5
    TH2D *banana_b5f0  = (TH2D*)file->Get("m_e_de_b5f0"); // Delta E - E matrix for b5f0
    TH2D *banana_b5f1  = (TH2D*)file->Get("m_e_de_b5f1"); // Delta E - E matrix for b5f1
    TH2D *banana_b5f2  = (TH2D*)file->Get("m_e_de_b5f2"); // Delta E - E matrix for b5f2
    TH2D *banana_b5f3  = (TH2D*)file->Get("m_e_de_b5f3"); // Delta E - E matrix for b5f3
    TH2D *banana_b5f4  = (TH2D*)file->Get("m_e_de_b5f4"); // Delta E - E matrix for b5f4
    TH2D *banana_b5f5  = (TH2D*)file->Get("m_e_de_b5f5"); // Delta E - E matrix for b5f5
    TH2D *banana_b5f6  = (TH2D*)file->Get("m_e_de_b5f6"); // Delta E - E matrix for b5f6
    TH2D *banana_b5f7  = (TH2D*)file->Get("m_e_de_b5f7"); // Delta E - E matrix for b5f7

    // Back detector 6
    TH2D *banana_b6f0  = (TH2D*)file->Get("m_e_de_b6f0"); // Delta E - E matrix for b6f0
    TH2D *banana_b6f1  = (TH2D*)file->Get("m_e_de_b6f1"); // Delta E - E matrix for b6f1
    TH2D *banana_b6f2  = (TH2D*)file->Get("m_e_de_b6f2"); // Delta E - E matrix for b6f2
    TH2D *banana_b6f3  = (TH2D*)file->Get("m_e_de_b6f3"); // Delta E - E matrix for b6f3
    TH2D *banana_b6f4  = (TH2D*)file->Get("m_e_de_b6f4"); // Delta E - E matrix for b6f4
    TH2D *banana_b6f5  = (TH2D*)file->Get("m_e_de_b6f5"); // Delta E - E matrix for b6f5
    TH2D *banana_b6f6  = (TH2D*)file->Get("m_e_de_b6f6"); // Delta E - E matrix for b6f6
    TH2D *banana_b6f7  = (TH2D*)file->Get("m_e_de_b6f7"); // Delta E - E matrix for b6f7

    // Back detector 7
    TH2D *banana_b7f0  = (TH2D*)file->Get("m_e_de_b7f0"); // Delta E - E matrix for b7f0
    TH2D *banana_b7f1  = (TH2D*)file->Get("m_e_de_b7f1"); // Delta E - E matrix for b7f1
    TH2D *banana_b7f2  = (TH2D*)file->Get("m_e_de_b7f2"); // Delta E - E matrix for b7f2
    TH2D *banana_b7f3  = (TH2D*)file->Get("m_e_de_b7f3"); // Delta E - E matrix for b7f3
    TH2D *banana_b7f4  = (TH2D*)file->Get("m_e_de_b7f4"); // Delta E - E matrix for b7f4
    TH2D *banana_b7f5  = (TH2D*)file->Get("m_e_de_b7f5"); // Delta E - E matrix for b7f5
    TH2D *banana_b7f6  = (TH2D*)file->Get("m_e_de_b7f6"); // Delta E - E matrix for b7f6
    TH2D *banana_b7f7  = (TH2D*)file->Get("m_e_de_b7f7"); // Delta E - E matrix for b7f7


    // Read Qkinz files to get the 186W(a,a') values
    // Ring f0 = 140 degrees
    ifstream f0_QKinzfile("QKinz_runs/186W-a-30MeV-strip0.txt");
    string line;
    line.resize(512);
    double f0_delta_e_energy[100], f0_delta_e_energy_err[100], f0_e_energy[100], f0_e_energy_err[100];
    int i = 0; 
    double dummy1, dummy2, dummy3, dummy4, dummy5, dummy6;
    for(i=0;i<103;i++){
        getline(f0_QKinzfile,line); 
    }
    i=0;
    while(f0_QKinzfile){
        f0_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f0_delta_e_energy[i] = dummy2;
        f0_delta_e_energy_err[i] = dummy3;
        f0_e_energy[i] = dummy4;
        f0_e_energy_err[i] = dummy5;
        //cout << i << " " << f0_delta_e_energy[i] << " " << f0_delta_e_energy_err[i] << " " << f0_e_energy[i] << " " << f0_e_energy_err[i] << endl;
        i++;
    }
    f0_QKinzfile.close();

    // Make a graph for the f0 QKinz values
    TGraphErrors *QKinz_f0_graph = new TGraphErrors(67,f0_e_energy,f0_delta_e_energy,f0_e_energy_err,f0_delta_e_energy_err);
    QKinz_f0_graph->SetMarkerStyle(2);
    QKinz_f0_graph->SetMarkerSize(0.8);

    // Ring f1 = 138 degrees
    ifstream f1_QKinzfile("QKinz_runs/186W-a-30MeV-strip1.txt");
    double f1_delta_e_energy[100], f1_delta_e_energy_err[100], f1_e_energy[100], f1_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f1_QKinzfile,line); 
    }
    i=0;
    while(f1_QKinzfile){
        f1_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f1_delta_e_energy[i] = dummy2;
        f1_delta_e_energy_err[i] = dummy3;
        f1_e_energy[i] = dummy4;
        f1_e_energy_err[i] = dummy5;
        i++;
    }
    f1_QKinzfile.close();

    // Make a graph for the f1 QKinz values
    TGraphErrors *QKinz_f1_graph = new TGraphErrors(67,f1_e_energy,f1_delta_e_energy,f1_e_energy_err,f1_delta_e_energy_err);
    QKinz_f1_graph->SetMarkerStyle(2);
    QKinz_f1_graph->SetMarkerSize(0.8);

    // Ring f2 = 136 degrees
    ifstream f2_QKinzfile("QKinz_runs/186W-a-30MeV-strip2.txt");
    double f2_delta_e_energy[100], f2_delta_e_energy_err[100], f2_e_energy[100], f2_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f2_QKinzfile,line); 
    }
    i=0;
    while(f2_QKinzfile){
        f2_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f2_delta_e_energy[i] = dummy2;
        f2_delta_e_energy_err[i] = dummy3;
        f2_e_energy[i] = dummy4;
        f2_e_energy_err[i] = dummy5;
        i++;
    }
    f2_QKinzfile.close();

    // Make a graph for the f2 QKinz values
    TGraphErrors *QKinz_f2_graph = new TGraphErrors(67,f2_e_energy,f2_delta_e_energy,f2_e_energy_err,f2_delta_e_energy_err);
    QKinz_f2_graph->SetMarkerStyle(2);
    QKinz_f2_graph->SetMarkerSize(0.8);

    // Ring f3 = 134 degrees
    ifstream f3_QKinzfile("QKinz_runs/186W-a-30MeV-strip3.txt");
    double f3_delta_e_energy[100], f3_delta_e_energy_err[100], f3_e_energy[100], f3_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f3_QKinzfile,line); 
    }
    i=0;
    while(f3_QKinzfile){
        f3_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f3_delta_e_energy[i] = dummy2;
        f3_delta_e_energy_err[i] = dummy3;
        f3_e_energy[i] = dummy4;
        f3_e_energy_err[i] = dummy5;
        i++;
    }
    f3_QKinzfile.close();

    // Make a graph for the f3 QKinz values
    TGraphErrors *QKinz_f3_graph = new TGraphErrors(67,f3_e_energy,f3_delta_e_energy,f3_e_energy_err,f3_delta_e_energy_err);
    QKinz_f3_graph->SetMarkerStyle(2);
    QKinz_f3_graph->SetMarkerSize(0.8);

    // Ring f4 = 132 degrees
    ifstream f4_QKinzfile("QKinz_runs/186W-a-30MeV-strip4.txt");
    double f4_delta_e_energy[100], f4_delta_e_energy_err[100], f4_e_energy[100], f4_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f4_QKinzfile,line); 
    }
    i=0;
    while(f4_QKinzfile){
        f4_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f4_delta_e_energy[i] = dummy2;
        f4_delta_e_energy_err[i] = dummy3;
        f4_e_energy[i] = dummy4;
        f4_e_energy_err[i] = dummy5;
        i++;
    }
    f4_QKinzfile.close();

    // Make a graph for the f4 QKinz values
    TGraphErrors *QKinz_f4_graph = new TGraphErrors(67,f4_e_energy,f4_delta_e_energy,f4_e_energy_err,f4_delta_e_energy_err);
    QKinz_f4_graph->SetMarkerStyle(2);
    QKinz_f4_graph->SetMarkerSize(0.8);

    // Ring f5 = 130 degrees
    ifstream f5_QKinzfile("QKinz_runs/186W-a-30MeV-strip5.txt");
    double f5_delta_e_energy[100], f5_delta_e_energy_err[100], f5_e_energy[100], f5_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f5_QKinzfile,line); 
    }
    i=0;
    while(f5_QKinzfile){
        f5_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f5_delta_e_energy[i] = dummy2;
        f5_delta_e_energy_err[i] = dummy3;
        f5_e_energy[i] = dummy4;
        f5_e_energy_err[i] = dummy5;
        i++;
    }
    f5_QKinzfile.close();

    // Make a graph for the f5 QKinz values
    TGraphErrors *QKinz_f5_graph = new TGraphErrors(67,f5_e_energy,f5_delta_e_energy,f5_e_energy_err,f5_delta_e_energy_err);
    QKinz_f5_graph->SetMarkerStyle(2);
    QKinz_f5_graph->SetMarkerSize(0.8);

    // Ring f6 = 128 degrees
    ifstream f6_QKinzfile("QKinz_runs/186W-a-30MeV-strip6.txt");
    double f6_delta_e_energy[100], f6_delta_e_energy_err[100], f6_e_energy[100], f6_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f6_QKinzfile,line); 
    }
    i=0;
    while(f6_QKinzfile){
        f6_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f6_delta_e_energy[i] = dummy2;
        f6_delta_e_energy_err[i] = dummy3;
        f6_e_energy[i] = dummy4;
        f6_e_energy_err[i] = dummy5;
        i++;
    }
    f6_QKinzfile.close();

    // Make a graph for the f6 QKinz values
    TGraphErrors *QKinz_f6_graph = new TGraphErrors(67,f6_e_energy,f6_delta_e_energy,f6_e_energy_err,f6_delta_e_energy_err);
    QKinz_f6_graph->SetMarkerStyle(2);
    QKinz_f6_graph->SetMarkerSize(0.8);

    // Ring f7 = 126 degrees
    ifstream f7_QKinzfile("QKinz_runs/186W-a-30MeV-strip7.txt");
    double f7_delta_e_energy[100], f7_delta_e_energy_err[100], f7_e_energy[100], f7_e_energy_err[100];
    for(i=0;i<103;i++){
        getline(f7_QKinzfile,line); 
    }
    i=0;
    while(f7_QKinzfile){
        f7_QKinzfile >> dummy1 >> dummy2 >> dummy3 >> dummy4 >> dummy5 >> dummy6;
        f7_delta_e_energy[i] = dummy2;
        f7_delta_e_energy_err[i] = dummy3;
        f7_e_energy[i] = dummy4;
        f7_e_energy_err[i] = dummy5;
        i++;
    }
    f7_QKinzfile.close();

    // Make a graph for the f7 QKinz values
    TGraphErrors *QKinz_f7_graph = new TGraphErrors(67,f7_e_energy,f7_delta_e_energy,f7_e_energy_err,f7_delta_e_energy_err);
    QKinz_f7_graph->SetMarkerStyle(2);
    QKinz_f7_graph->SetMarkerSize(0.8);

    // START THE FITS

    /////////////////////
    // Back detector 0 //
    /////////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c1 = new TCanvas("c1","c1:f0 bananas",1400,800);
    c1->Divide(8,3,0,0);
    c1->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    

    // The b0f0 186W(a,a') channel
    banana_b0f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f0->Draw();
    QKinz_f0_graph->Draw("p same");

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f0 = new TCutG("cutg_b0f0",17);
    cutg_b0f0->SetVarX(" E detector 0 strip 0");
    cutg_b0f0->SetVarY("#DeltaE ");
    cutg_b0f0->SetTitle("Graphb0f0");
    cutg_b0f0->SetFillStyle(1000);
    cutg_b0f0->SetPoint(0,15008.2,3643.85);
    cutg_b0f0->SetPoint(1,15161.2,3565.84);
    cutg_b0f0->SetPoint(2,15325.9,3504.09);
    cutg_b0f0->SetPoint(3,15567.1,3448.83);
    cutg_b0f0->SetPoint(4,15811.2,3448.83);
    cutg_b0f0->SetPoint(5,15878.8,3504.09);
    cutg_b0f0->SetPoint(6,15875.9,3686.11);
    cutg_b0f0->SetPoint(7,15802.4,3816.12);
    cutg_b0f0->SetPoint(8,15611.2,3965.64);
    cutg_b0f0->SetPoint(9,15375.9,4017.64);
    cutg_b0f0->SetPoint(10,15187.6,4056.65);
    cutg_b0f0->SetPoint(11,15008.2,4050.15);
    cutg_b0f0->SetPoint(12,14949.4,3936.38);
    cutg_b0f0->SetPoint(13,14940.6,3770.62);
    cutg_b0f0->SetPoint(14,15002.4,3650.35);
    cutg_b0f0->SetPoint(15,15005.3,3647.1);
    cutg_b0f0->SetPoint(16,15008.2,3643.85);
    cutg_b0f0->Draw("same");


    int bin_max_counts = banana_b0f0->GetMaximumBin();
    int binx, biny, binz;
    banana_b0f0->GetBinXYZ(bin_max_counts, binx, biny, binz);
    double maxcounts = banana_b0f0->GetBinContent(binx,biny);
    cout << " Pixel with the most counts: "<< endl;
    cout << " binx = " << binx << ", biny = " << biny << endl;
    cout << " energy_x = " << banana_b0f0->GetXaxis()->GetBinCenter(binx) << " keV" << endl;
    cout << " energy_y = " << banana_b0f0->GetYaxis()->GetBinCenter(biny) << " keV" << endl;
    cout << " Counts = " << maxcounts << endl;



    c1->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    // Make the projection on the E detector axis (x axis)
    TH1D *projx_cutg_b0f0 = banana_b0f0->ProjectionX("projx_cutg_b0f0",1,banana_b0f0->GetNbinsX(),"[cutg_b0f0]");              
    projx_cutg_b0f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f0->Draw();
    // Now finding the bin with the maximum number of counts, and use that as the peak
    int binmax = projx_cutg_b0f0->GetMaximumBin(); 
    double centroidx = projx_cutg_b0f0->GetXaxis()->GetBinCenter(binmax);


    c1->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    // Make the projection on the Delta E detector axis (y axis)
    TH1D *projy_cutg_b0f0 = banana_b0f0->ProjectionY("projy_cutg_b0f0",1,banana_b0f0->GetNbinsY(),"[cutg_b0f0]");              
    projy_cutg_b0f0->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f0->Draw();
    projy_cutg_b0f0->Fit("gaus");
    TF1 *fity = (TF1*)projy_cutg_b0f0->GetListOfFunctions()->FindObject("gaus");
    double centroidy = fity->GetParameter(1);


    cout << " b0f0 centroids: " << endl;
    cout << " E detector: " << centroidx << " keV " << endl;
    cout << " Delta E detector: " << centroidy << " keV " << endl;

    // Now calculate the needed gain to get the elastic peak where it should be
    // The number 5 and 2.5 come from the gainshifts_plain.txt file, the first approximative gain.
    double gainb0f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb0f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f0_E = " << gainb0f0_E << " keV/ch" << endl;
    cout << " gainb0f0_dE = " << gainb0f0_dE << " keV/ch"<< endl;
    cout << endl;


    c1->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f1 186W(a,a') channel
    banana_b0f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f1->Draw();
    QKinz_f1_graph->Draw("p same");

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f1 = new TCutG("cutg_b0f1",17);
    cutg_b0f1->SetVarX(" E detector 0 strip 1");
    cutg_b0f1->SetVarY("#DeltaE ");
    cutg_b0f1->SetTitle("Graph");
    cutg_b0f1->SetFillStyle(1000);
    cutg_b0f1->SetPoint(0,15030.6,3737.48);
    cutg_b0f1->SetPoint(1,15334.4,3612.16);
    cutg_b0f1->SetPoint(2,15625.3,3554.09);
    cutg_b0f1->SetPoint(3,15794.8,3535.75);
    cutg_b0f1->SetPoint(4,15941.9,3544.92);
    cutg_b0f1->SetPoint(5,15999.4,3648.84);
    cutg_b0f1->SetPoint(6,15833.2,3896.41);
    cutg_b0f1->SetPoint(7,15650.9,3975.88);
    cutg_b0f1->SetPoint(8,15417.5,4058.4);
    cutg_b0f1->SetPoint(9,15248.1,4079.8);
    cutg_b0f1->SetPoint(10,15091.4,4088.97);
    cutg_b0f1->SetPoint(11,14953.9,4046.18);
    cutg_b0f1->SetPoint(12,14905.9,3930.03);
    cutg_b0f1->SetPoint(13,14934.7,3829.17);
    cutg_b0f1->SetPoint(14,15014.7,3743.59);
    cutg_b0f1->SetPoint(15,15040.2,3734.42);
    cutg_b0f1->SetPoint(16,15030.6,3737.48);
    cutg_b0f1->Draw("same");


    c1->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Make the projection on the E detector axis (x axis)
    TH1D *projx_cutg_b0f1 = banana_b0f1->ProjectionX("projx_cutg_b0f1",1,banana_b0f1->GetNbinsX(),"[cutg_b0f1]");              
    projx_cutg_b0f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f1->Fit("gaus");
    // Grab the centroid for the E detector
    TF1 *fitx = (TF1*)projx_cutg_b0f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax = projx_cutg_b0f1->GetMaximumBin(); 
    centroidx = projx_cutg_b0f1->GetXaxis()->GetBinCenter(binmax);

    c1->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Make the projection on the Delta E detector axis (y axis)
    TH1D *projy_cutg_b0f1 = banana_b0f1->ProjectionY("projy_cutg_b0f1",1,banana_b0f1->GetNbinsY(),"[cutg_b0f1]");              
    projy_cutg_b0f1->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f1->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Now calculate the needed gain to get the elastic peak where it should be
    // The number 5 and 2.5 come from the gainshifts_plain.txt file, the first approximative gain.
    double gainb0f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb0f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f1_E = " << gainb0f1_E << " keV/ch" << endl;
    cout << " gainb0f1_dE = " << gainb0f1_dE << " keV/ch"<< endl;
    cout << endl;


    c1->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f2 186W(a,a') channel
    banana_b0f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f2->Draw();
    QKinz_f2_graph->Draw("p same");

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f2 = new TCutG("cutg_b0f2",17);
    cutg_b0f2->SetVarX(" E detector 0 strip 2");
    cutg_b0f2->SetVarY("#DeltaE ");
    cutg_b0f2->SetTitle("Graph");
    cutg_b0f2->SetFillStyle(1000);
    cutg_b0f2->SetPoint(0,15120.7,3675.51);
    cutg_b0f2->SetPoint(1,15263.5,3604.39);
    cutg_b0f2->SetPoint(2,15397.4,3563.21);
    cutg_b0f2->SetPoint(3,15549.2,3514.55);
    cutg_b0f2->SetPoint(4,15754.5,3495.83);
    cutg_b0f2->SetPoint(5,15924.1,3510.8);
    cutg_b0f2->SetPoint(6,16004.5,3555.72);
    cutg_b0f2->SetPoint(7,15995.5,3675.51);
    cutg_b0f2->SetPoint(8,15861.6,3772.83);
    cutg_b0f2->SetPoint(9,15709.9,3843.96);
    cutg_b0f2->SetPoint(10,15567,3900.11);
    cutg_b0f2->SetPoint(11,15388.5,3933.8);
    cutg_b0f2->SetPoint(12,15147.5,3937.54);
    cutg_b0f2->SetPoint(13,15004.7,3915.08);
    cutg_b0f2->SetPoint(14,14977.9,3855.19);
    cutg_b0f2->SetPoint(15,14995.7,3769.09);
    cutg_b0f2->SetPoint(16,15049.3,3724.17);
    cutg_b0f2->SetPoint(17,15111.8,3686.74);
    cutg_b0f2->SetPoint(18,15138.6,3671.76);
    cutg_b0f2->SetPoint(19,15120.7,3675.51);
    cutg_b0f2->Draw("same");


    c1->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Make the projection on the E detector axis (x axis)
    TH1D *projx_cutg_b0f2 = banana_b0f2->ProjectionX("projx_cutg_b0f2",1,banana_b0f2->GetNbinsX(),"[cutg_b0f2]");              
    projx_cutg_b0f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f2->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax = projx_cutg_b0f2->GetMaximumBin(); 
    centroidx = projx_cutg_b0f2->GetXaxis()->GetBinCenter(binmax);

    c1->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Make the projection on the Delta E detector axis (y axis)
    TH1D *projy_cutg_b0f2 = banana_b0f2->ProjectionY("projy_cutg_b0f2",1,banana_b0f2->GetNbinsY(),"[cutg_b0f2]");              
    projy_cutg_b0f2->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f2->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Now calculate the needed gain to get the elastic peak where it should be
    // The number 5 and 2.5 come from the gainshifts_plain.txt file, the first approximative gain.
    double gainb0f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb0f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f2_E = " <<  gainb0f2_E << " keV/ch" << endl;
    cout << " gainb0f2_dE = " << gainb0f2_dE << " keV/ch"<< endl;
    cout << endl;

    c1->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f3 186W(a,a') channel
    banana_b0f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f3->Draw();
    QKinz_f3_graph->Draw("p same");

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f3 = new TCutG("cutg_b0f3",18);
    cutg_b0f3->SetVarX(" E detector 0 strip 3");
    cutg_b0f3->SetVarY("#DeltaE ");
    cutg_b0f3->SetTitle("Graph");
    cutg_b0f3->SetFillStyle(1000);
    cutg_b0f3->SetPoint(0,15070.2,3787.11);
    cutg_b0f3->SetPoint(1,15303.5,3699.41);
    cutg_b0f3->SetPoint(2,15572.7,3661.04);
    cutg_b0f3->SetPoint(3,15770.2,3617.19);
    cutg_b0f3->SetPoint(4,15973.6,3630.9);
    cutg_b0f3->SetPoint(5,16105.2,3680.23);
    cutg_b0f3->SetPoint(6,16063.3,3776.15);
    cutg_b0f3->SetPoint(7,15985.6,3866.59);
    cutg_b0f3->SetPoint(8,15806.1,3943.33);
    cutg_b0f3->SetPoint(9,15626.6,4028.29);
    cutg_b0f3->SetPoint(10,15405.2,4102.29);
    cutg_b0f3->SetPoint(11,15183.8,4124.21);
    cutg_b0f3->SetPoint(12,14998.4,4099.55);
    cutg_b0f3->SetPoint(13,14962.5,4025.55);
    cutg_b0f3->SetPoint(14,15028.3,3921.4);
    cutg_b0f3->SetPoint(15,15076.2,3806.3);
    cutg_b0f3->SetPoint(16,15094.1,3778.89);
    cutg_b0f3->SetPoint(17,15070.2,3787.11);
    cutg_b0f3->Draw("same");


    c1->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Make the projection on the E detector axis (x axis)
    TH1D *projx_cutg_b0f3 = banana_b0f3->ProjectionX("projx_cutg_b0f3",1,banana_b0f3->GetNbinsX(),"[cutg_b0f3]");              
    projx_cutg_b0f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f3->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b0f3->GetMaximumBin(); 
    centroidx = projx_cutg_b0f3->GetXaxis()->GetBinCenter(binmax);

    c1->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);  
    // Make the projection on the Delta E detector axis (y axis)
    TH1D *projy_cutg_b0f3 = banana_b0f3->ProjectionY("projy_cutg_b0f3",1,banana_b0f3->GetNbinsY(),"[cutg_b0f3]");              
    projy_cutg_b0f3->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f3->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Now calculate the needed gain to get the elastic peak where it should be
    // The number 5 and 2.5 come from the gainshifts_plain.txt file, the first approximative gain.
    double gainb0f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb0f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f3_E = " <<  gainb0f3_E << " keV/ch" << endl;
    cout << " gainb0f3_dE = " << gainb0f3_dE << " keV/ch"<< endl;
    cout << endl;

    c1->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f4 186W(a,a') channel
    banana_b0f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f4->Draw();
    QKinz_f4_graph->Draw("p same");

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f4 = new TCutG("cutg_b0f4",18);
    cutg_b0f4->SetVarX(" E detector 0 strip 4");
    cutg_b0f4->SetVarY("#DeltaE ");
    cutg_b0f4->SetTitle("Graph");
    cutg_b0f4->SetFillStyle(1000);
    cutg_b0f4->SetPoint(0,15023.4,3811.82);
    cutg_b0f4->SetPoint(1,15247.5,3730);
    cutg_b0f4->SetPoint(2,15346.2,3695.91);
    cutg_b0f4->SetPoint(3,15543.8,3627.73);
    cutg_b0f4->SetPoint(4,15726.1,3602.73);
    cutg_b0f4->SetPoint(5,15874.3,3580);
    cutg_b0f4->SetPoint(6,15988.2,3564.09);
    cutg_b0f4->SetPoint(7,16060.4,3591.36);
    cutg_b0f4->SetPoint(8,16106,3661.82);
    cutg_b0f4->SetPoint(9,16102.2,3777.73);
    cutg_b0f4->SetPoint(10,15969.2,3864.09);
    cutg_b0f4->SetPoint(11,15881.9,3916.36);
    cutg_b0f4->SetPoint(12,15756.5,3993.64);
    cutg_b0f4->SetPoint(13,15608.4,4048.18);
    cutg_b0f4->SetPoint(14,15494.4,4080);
    cutg_b0f4->SetPoint(15,15376.6,4116.36);
    cutg_b0f4->SetPoint(16,15194.3,4139.09);
    cutg_b0f4->SetPoint(17,15084.1,4132.27);
    cutg_b0f4->SetPoint(18,14996.8,4080);
    cutg_b0f4->SetPoint(19,14951.2,4032.27);
    cutg_b0f4->SetPoint(20,14951.2,3923.18);
    cutg_b0f4->SetPoint(21,14977.8,3875.45);
    cutg_b0f4->SetPoint(22,15015.8,3820.91);
    cutg_b0f4->SetPoint(23,15031,3805);
    cutg_b0f4->SetPoint(24,15023.4,3811.82);
    cutg_b0f4->Draw("same");


    c1->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f4 = banana_b0f4->ProjectionX("projx_cutg_b0f4",1,banana_b0f4->GetNbinsX(),"[cutg_b0f4]");              
    projx_cutg_b0f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f4->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b0f4->GetMaximumBin(); 
    centroidx = projx_cutg_b0f4->GetXaxis()->GetBinCenter(binmax);
 
    c1->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f4 = banana_b0f4->ProjectionY("projy_cutg_b0f4",1,banana_b0f4->GetNbinsY(),"[cutg_b0f4]");              
    projy_cutg_b0f4->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f4->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb0f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb0f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f4_E = " <<  gainb0f4_E << " keV/ch" << endl;
    cout << " gainb0f4_dE = " << gainb0f4_dE << " keV/ch"<< endl;
    cout << endl;

    c1->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f5 186W(a,a') channel
    banana_b0f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b0f5 = new TCutG("cutg_b0f5",23);
    cutg_b0f5->SetVarX(" E detector 0 strip 5");
    cutg_b0f5->SetVarY("#DeltaE ");
    cutg_b0f5->SetTitle("Graph");
    cutg_b0f5->SetFillStyle(1000);
    cutg_b0f5->SetPoint(0,14934.6,3854.01);
    cutg_b0f5->SetPoint(1,15055.7,3773.53);
    cutg_b0f5->SetPoint(2,15244.6,3716.04);
    cutg_b0f5->SetPoint(3,15418.9,3641.31);
    cutg_b0f5->SetPoint(4,15724.1,3598.2);
    cutg_b0f5->SetPoint(5,15927.5,3592.45);
    cutg_b0f5->SetPoint(6,16101.9,3612.57);
    cutg_b0f5->SetPoint(7,16150.3,3681.55);
    cutg_b0f5->SetPoint(8,16135.8,3776.4);
    cutg_b0f5->SetPoint(9,16019.5,3874.13);
    cutg_b0f5->SetPoint(10,15917.8,3934.49);
    cutg_b0f5->SetPoint(11,15728.9,4029.34);
    cutg_b0f5->SetPoint(12,15598.1,4112.7);
    cutg_b0f5->SetPoint(13,15409.3,4175.94);
    cutg_b0f5->SetPoint(14,15268.8,4184.56);
    cutg_b0f5->SetPoint(15,15075.1,4175.94);
    cutg_b0f5->SetPoint(16,14949.1,4147.19);
    cutg_b0f5->SetPoint(17,14862,4106.95);
    cutg_b0f5->SetPoint(18,14862,4029.34);
    cutg_b0f5->SetPoint(19,14866.8,3934.49);
    cutg_b0f5->SetPoint(20,14900.7,3891.38);
    cutg_b0f5->SetPoint(21,14934.6,3851.14);
    cutg_b0f5->SetPoint(22,14934.6,3854.01);
    cutg_b0f5->Draw("same");


    c1->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f5 = banana_b0f5->ProjectionX("projx_cutg_b0f5",1,banana_b0f5->GetNbinsX(),"[cutg_b0f5]");              
    projx_cutg_b0f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f5->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b0f5->GetMaximumBin(); 
    centroidx = projx_cutg_b0f5->GetXaxis()->GetBinCenter(binmax);

    c1->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f5 = banana_b0f5->ProjectionY("projy_cutg_b0f5",1,banana_b0f5->GetNbinsY(),"[cutg_b0f5]");              
    projy_cutg_b0f5->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f5->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb0f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb0f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f5_E = " <<  gainb0f5_E << " keV/ch" << endl;
    cout << " gainb0f5_dE = " << gainb0f5_dE << " keV/ch"<< endl;
    cout << endl;

    c1->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f6 186W(a,a') channel
    banana_b0f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b0f6 = new TCutG("cutg_b0f6",19);
    cutg_b0f6->SetVarX(" E detector 0 strip 6");
    cutg_b0f6->SetVarY("#DeltaE ");
    cutg_b0f6->SetTitle("Graph");
    cutg_b0f6->SetFillStyle(1000);
    cutg_b0f6->SetPoint(0,15388.4,4113.25);
    cutg_b0f6->SetPoint(1,15563.1,4063.92);
    cutg_b0f6->SetPoint(2,15825.2,3940.59);
    cutg_b0f6->SetPoint(3,16026.2,3814.52);
    cutg_b0f6->SetPoint(4,16048,3688.45);
    cutg_b0f6->SetPoint(5,16008.7,3600.75);
    cutg_b0f6->SetPoint(6,15921.3,3587.05);
    cutg_b0f6->SetPoint(7,15742.2,3617.19);
    cutg_b0f6->SetPoint(8,15471.4,3661.04);
    cutg_b0f6->SetPoint(9,15261.7,3702.15);
    cutg_b0f6->SetPoint(10,15108.8,3792.59);
    cutg_b0f6->SetPoint(11,15065.1,3894);
    cutg_b0f6->SetPoint(12,15017.1,4039.25);
    cutg_b0f6->SetPoint(13,15056.4,4105.03);
    cutg_b0f6->SetPoint(14,15170,4146.14);
    cutg_b0f6->SetPoint(15,15314.1,4151.62);
    cutg_b0f6->SetPoint(16,15375.3,4137.91);
    cutg_b0f6->SetPoint(17,15419,4105.03);
    cutg_b0f6->SetPoint(18,15388.4,4113.25);
    cutg_b0f6->Draw("same");

    c1->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f6 = banana_b0f6->ProjectionX("projx_cutg_b0f6",1,banana_b0f6->GetNbinsX(),"[cutg_b0f6]");              
    projx_cutg_b0f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f6->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b0f6->GetMaximumBin(); 
    centroidx = projx_cutg_b0f6->GetXaxis()->GetBinCenter(binmax);

    c1->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f6 = banana_b0f6->ProjectionY("projy_cutg_b0f6",1,banana_b0f6->GetNbinsY(),"[cutg_b0f6]");              
    projy_cutg_b0f6->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f6->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);
    
    double gainb0f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb0f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f6_E = " <<  gainb0f6_E << " keV/ch" << endl;
    cout << " gainb0f6_dE = " << gainb0f6_dE << " keV/ch"<< endl;
    cout << endl;


    c1->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.07);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f7 186W(a,a') channel
    banana_b0f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b0f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b0f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b0f7 = new TCutG("cutg_b0f7",19);
    cutg_b0f7->SetPoint(0,15156.3,3663.96);
    cutg_b0f7->SetPoint(1,15405.5,3593.37);
    cutg_b0f7->SetPoint(2,15697.5,3503.53);
    cutg_b0f7->SetPoint(3,15954.5,3532.41);
    cutg_b0f7->SetPoint(4,16098.5,3561.28);
    cutg_b0f7->SetPoint(5,16098.5,3641.5);
    cutg_b0f7->SetPoint(6,16075.2,3724.92);
    cutg_b0f7->SetPoint(7,15950.6,3856.47);
    cutg_b0f7->SetPoint(8,15833.8,3911.02);
    cutg_b0f7->SetPoint(9,15740.3,3962.35);
    cutg_b0f7->SetPoint(10,15600.2,4007.27);
    cutg_b0f7->SetPoint(11,15479.5,4052.19);
    cutg_b0f7->SetPoint(12,15378.2,4081.07);
    cutg_b0f7->SetPoint(13,15206.9,4090.7);
    cutg_b0f7->SetPoint(14,15101.8,4084.28);
    cutg_b0f7->SetPoint(15,15020,4048.98);
    cutg_b0f7->SetPoint(16,14965.5,4004.06);
    cutg_b0f7->SetPoint(17,14946,3891.76);
    cutg_b0f7->SetPoint(18,14981.1,3821.18);
    cutg_b0f7->SetPoint(19,15020,3747.38);
    cutg_b0f7->SetPoint(20,15109.6,3692.83);
    cutg_b0f7->SetPoint(21,15156.3,3663.96);
    cutg_b0f7->SetPoint(22,15156.3,3663.96);
    cutg_b0f7->Draw("same");

  
    c1->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f7 = banana_b0f7->ProjectionX("projx_cutg_b0f7",1,banana_b0f7->GetNbinsX(),"[cutg_b0f7]");              
    projx_cutg_b0f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b0f7->Fit("gaus");
    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b0f7->GetMaximumBin(); 
    centroidx = projx_cutg_b0f7->GetXaxis()->GetBinCenter(binmax);

    c1->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);   
    TH1D *projy_cutg_b0f7 = banana_b0f7->ProjectionY("projy_cutg_b0f7",1,banana_b0f7->GetNbinsY(),"[cutg_b0f7]");              
    projy_cutg_b0f7->GetXaxis()->SetRangeUser(2000,5000);
    projy_cutg_b0f7->Fit("gaus");
    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb0f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb0f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb0f7_E = " <<  gainb0f7_E << " keV/ch" << endl;
    cout << " gainb0f7_dE = " << gainb0f7_dE << " keV/ch"<< endl;
    cout << endl;


    ///////////////////
    // E DETECTOR b1 //
    ///////////////////
  
    TCanvas *c2 = new TCanvas("c2","c2:b1 bananas",1400,800);
    c2->Divide(8,3,0,0);
    c2->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f0 186Ni(a,a') channel
    banana_b1f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b1f0 = new TCutG("cutg_b1f0",17);
    cutg_b1f0->SetVarX(" E detector 1 strip 0");
    cutg_b1f0->SetVarY("#DeltaE ");
    cutg_b1f0->SetTitle("Graph");
    cutg_b1f0->SetFillStyle(1000);
    cutg_b1f0->SetVarX(" E detector 1 strip 0");
   	cutg_b1f0->SetVarY("#DeltaE ");
   	cutg_b1f0->SetTitle("Graph");
   	cutg_b1f0->SetFillStyle(1000);
   	cutg_b1f0->SetPoint(0,14620.3,3702.05);
   	cutg_b1f0->SetPoint(1,14977,3619.31);
   	cutg_b1f0->SetPoint(2,15289.8,3576.69);
   	cutg_b1f0->SetPoint(3,15440,3579.2);
   	cutg_b1f0->SetPoint(4,15615.2,3611.79);
   	cutg_b1f0->SetPoint(5,15615.2,3742.16);
   	cutg_b1f0->SetPoint(6,15358.6,3892.59);
   	cutg_b1f0->SetPoint(7,15152.2,4000.4);
   	cutg_b1f0->SetPoint(8,14920.7,4053.05);
   	cutg_b1f0->SetPoint(9,14614.1,4050.54);
   	cutg_b1f0->SetPoint(10,14507.7,4022.97);
   	cutg_b1f0->SetPoint(11,14476.4,3965.3);
   	cutg_b1f0->SetPoint(12,14476.4,3885.07);
   	cutg_b1f0->SetPoint(13,14545.3,3799.83);
   	cutg_b1f0->SetPoint(14,14607.8,3732.13);
   	cutg_b1f0->SetPoint(15,14632.9,3699.54);
   	cutg_b1f0->SetPoint(16,14620.3,3702.05);
    cutg_b1f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f0
    c2->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f0 = banana_b1f0->ProjectionX("projx_cutg_b1f0",1,banana_b1f0->GetNbinsX(),"[cutg_b1f0]");              
    projx_cutg_b1f0->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f0->GetMaximumBin(); 
    centroidx = projx_cutg_b1f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f0 = banana_b1f0->ProjectionY("projy_cutg_b1f0",1,banana_b1f0->GetNbinsY(),"[cutg_b1f0]");              
    projy_cutg_b1f0->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb1f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f0_E = " <<  gainb1f0_E << " keV/ch" << endl;
    cout << " gainb1f0_dE = " << gainb1f0_dE << " keV/ch"<< endl;
    cout << endl;


    c2->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f1 186W(a,a') channel
    banana_b1f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f1->Draw();
    QKinz_f1_graph->Draw("p same");

    TCutG *cutg_b1f1 = new TCutG("cutg_b1f1",21);
    cutg_b1f1->SetVarX(" E detector 1 strip 1");
    cutg_b1f1->SetVarY("#DeltaE ");
    cutg_b1f1->SetTitle("Graph");
    cutg_b1f1->SetFillStyle(1000);
    cutg_b1f1->SetPoint(0,14480.1,3646.16);
   	cutg_b1f1->SetPoint(1,14673.6,3617.79);
   	cutg_b1f1->SetPoint(2,14858.7,3570.52);
   	cutg_b1f1->SetPoint(3,15077.5,3542.15);
   	cutg_b1f1->SetPoint(4,15372,3542.15);
   	cutg_b1f1->SetPoint(5,15607.6,3627.25);
   	cutg_b1f1->SetPoint(6,15674.9,3726.53);
   	cutg_b1f1->SetPoint(7,15548.7,3863.64);
   	cutg_b1f1->SetPoint(8,15422.5,4005.47);
   	cutg_b1f1->SetPoint(9,15279.4,4048.02);
   	cutg_b1f1->SetPoint(10,15043.8,4133.12);
   	cutg_b1f1->SetPoint(11,14791.4,4166.22);
   	cutg_b1f1->SetPoint(12,14597.9,4170.95);
   	cutg_b1f1->SetPoint(13,14370.7,4147.31);
   	cutg_b1f1->SetPoint(14,14278.1,4095.3);
   	cutg_b1f1->SetPoint(15,14278.1,3967.65);
   	cutg_b1f1->SetPoint(16,14320.2,3816.36);
   	cutg_b1f1->SetPoint(17,14429.6,3740.72);
   	cutg_b1f1->SetPoint(18,14480.1,3669.8);
   	cutg_b1f1->SetPoint(19,14513.7,3641.43);
   	cutg_b1f1->SetPoint(20,14480.1,3646.16);
    cutg_b1f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f1
    c2->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f1 = banana_b1f1->ProjectionX("projx_cutg_b1f1",1,banana_b1f1->GetNbinsX(),"[cutg_b1f1]");              
    projx_cutg_b1f1->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f1->GetMaximumBin(); 
    centroidx = projx_cutg_b1f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f1 = banana_b1f1->ProjectionY("projy_cutg_b1f1",1,banana_b1f1->GetNbinsY(),"[cutg_b1f1]");              
    projy_cutg_b1f1->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb1f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f1_E = " <<  gainb1f1_E << " keV/ch" << endl;
    cout << " gainb1f1_dE = " << gainb1f1_dE << " keV/ch"<< endl;
    cout << endl;

    c2->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f2 186W(a,a') channel
    banana_b1f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b1f2 = new TCutG("cutg_b1f2",17);
    cutg_b1f2->SetVarX(" E detector 1 strip 2");
    cutg_b1f2->SetVarY("#DeltaE ");
    cutg_b1f2->SetTitle("Graph");
    cutg_b1f2->SetFillStyle(1000);
    cutg_b1f2->SetPoint(0,14972,3646.05);
   	cutg_b1f2->SetPoint(1,15179.2,3591.89);
   	cutg_b1f2->SetPoint(2,15386.3,3591.89);
   	cutg_b1f2->SetPoint(3,15535.1,3614.46);
   	cutg_b1f2->SetPoint(4,15625.8,3804);
   	cutg_b1f2->SetPoint(5,15528.7,3912.31);
   	cutg_b1f2->SetPoint(6,15315.1,4061.23);
   	cutg_b1f2->SetPoint(7,14991.5,4165.03);
   	cutg_b1f2->SetPoint(8,14609.6,4165.03);
   	cutg_b1f2->SetPoint(9,14583.7,4119.9);
   	cutg_b1f2->SetPoint(10,14616.1,3998.05);
   	cutg_b1f2->SetPoint(11,14641.9,3894.26);
   	cutg_b1f2->SetPoint(12,14784.3,3763.38);
   	cutg_b1f2->SetPoint(13,14887.9,3695.69);
   	cutg_b1f2->SetPoint(14,14978.5,3650.56);
   	cutg_b1f2->SetPoint(15,14991.5,3641.53);
   	cutg_b1f2->SetPoint(16,14972,3646.05);
    cutg_b1f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f2
    c2->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f2 = banana_b1f2->ProjectionX("projx_cutg_b1f2",1,banana_b1f2->GetNbinsX(),"[cutg_b1f2]");              
    projx_cutg_b1f2->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f2->GetMaximumBin(); 
    centroidx = projx_cutg_b1f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f2 = banana_b1f2->ProjectionY("projy_cutg_b1f2",1,banana_b1f2->GetNbinsY(),"[cutg_b1f2]");              
    projy_cutg_b1f2->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb1f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f2_E = " <<  gainb1f2_E << " keV/ch" << endl;
    cout << " gainb1f2_dE = " << gainb1f2_dE << " keV/ch"<< endl;
    cout << endl;

    c2->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f3 60Ni(a,a) elastic peak
    banana_b1f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b1f3 = new TCutG("cutg_b1f3",18);
    cutg_b1f3->SetVarX(" E detector 1 strip 3");
    cutg_b1f3->SetVarY("#DeltaE ");
    cutg_b1f3->SetTitle("Graph");
    cutg_b1f3->SetFillStyle(1000);
    cutg_b1f3->SetPoint(0,14641.5,3728.34);
   	cutg_b1f3->SetPoint(1,14756.5,3665.01);
   	cutg_b1f3->SetPoint(2,14924.5,3630.92);
   	cutg_b1f3->SetPoint(3,15181.1,3582.21);
   	cutg_b1f3->SetPoint(4,15388.9,3552.98);
   	cutg_b1f3->SetPoint(5,15517.2,3552.98);
   	cutg_b1f3->SetPoint(6,15627.8,3565.16);
   	cutg_b1f3->SetPoint(7,15698.5,3665.01);
   	cutg_b1f3->SetPoint(8,15583.5,3786.79);
   	cutg_b1f3->SetPoint(9,15322.6,3935.36);
   	cutg_b1f3->SetPoint(10,14968.8,4103.41);
   	cutg_b1f3->SetPoint(11,14849.4,4103.41);
   	cutg_b1f3->SetPoint(12,14584,4076.62);
   	cutg_b1f3->SetPoint(13,14557.4,3974.33);
   	cutg_b1f3->SetPoint(14,14539.8,3874.47);
   	cutg_b1f3->SetPoint(15,14601.7,3760);
   	cutg_b1f3->SetPoint(16,14645.9,3728.34);
   	cutg_b1f3->SetPoint(17,14641.5,3728.34);
    cutg_b1f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f3
    c2->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f3 = banana_b1f3->ProjectionX("projx_cutg_b1f3",1,banana_b1f3->GetNbinsX(),"[cutg_b1f3]");              
    projx_cutg_b1f3->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f3->GetMaximumBin(); 
    centroidx = projx_cutg_b1f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f3 = banana_b1f3->ProjectionY("projy_cutg_b1f3",1,banana_b1f3->GetNbinsY(),"[cutg_b1f3]");              
    projy_cutg_b1f3->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb1f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f3_E = " <<  gainb1f3_E << " keV/ch" << endl;
    cout << " gainb1f3_dE = " << gainb1f3_dE << " keV/ch"<< endl;
    cout << endl;
    

    c2->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f4 60Ni(a,a) elastic peak
    banana_b1f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b1f4 = new TCutG("cutg_b1f4",19);
    cutg_b1f4->SetVarX(" E detector 1 strip 4");
    cutg_b1f4->SetVarY("#DeltaE ");
    cutg_b1f4->SetTitle("Graph");
    cutg_b1f4->SetFillStyle(1000);
    cutg_b1f4->SetPoint(0,14749.3,3748.28);
   	cutg_b1f4->SetPoint(1,15007.6,3661.17);
   	cutg_b1f4->SetPoint(2,15256.8,3604.01);
   	cutg_b1f4->SetPoint(3,15465.2,3604.01);
   	cutg_b1f4->SetPoint(4,15650.9,3609.46);
   	cutg_b1f4->SetPoint(5,15782.3,3674.79);
   	cutg_b1f4->SetPoint(6,15777.8,3753.72);
   	cutg_b1f4->SetPoint(7,15678.1,3843.55);
   	cutg_b1f4->SetPoint(8,15551.3,3949.71);
   	cutg_b1f4->SetPoint(9,15329.3,4053.15);
   	cutg_b1f4->SetPoint(10,15152.6,4134.81);
   	cutg_b1f4->SetPoint(11,14944.1,4178.37);
   	cutg_b1f4->SetPoint(12,14812.8,4164.76);
   	cutg_b1f4->SetPoint(13,14735.7,4115.76);
   	cutg_b1f4->SetPoint(14,14749.3,3957.88);
   	cutg_b1f4->SetPoint(15,14772,3865.33);
   	cutg_b1f4->SetPoint(16,14772,3778.22);
   	cutg_b1f4->SetPoint(17,14772,3748.28);
   	cutg_b1f4->SetPoint(18,14749.3,3748.28);
    cutg_b1f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f4
    c2->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f4 = banana_b1f4->ProjectionX("projx_cutg_b1f4",1,banana_b1f4->GetNbinsX(),"[cutg_b1f4]");              
    projx_cutg_b1f4->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f4->GetMaximumBin(); 
    centroidx = projx_cutg_b1f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f4 = banana_b1f4->ProjectionY("projy_cutg_b1f4",1,banana_b1f4->GetNbinsY(),"[cutg_b1f4]");              
    projy_cutg_b1f4->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb1f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f4_E = " <<  gainb1f4_E << " keV/ch" << endl;
    cout << " gainb1f4_dE = " << gainb1f4_dE << " keV/ch"<< endl;
    cout << endl;


    c2->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f5 186W(a,a') channel
    banana_b1f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b1f5 = new TCutG("cutg_b1f5",23);
    cutg_b1f5->SetVarX(" E detector 1 strip 5");
    cutg_b1f5->SetVarY("#DeltaE ");
    cutg_b1f5->SetTitle("Graph");
    cutg_b1f5->SetFillStyle(1000);
    cutg_b1f5->SetPoint(0,14832.5,3577.08);
   	cutg_b1f5->SetPoint(1,15104.4,3501.43);
   	cutg_b1f5->SetPoint(2,15240.3,3461.25);
   	cutg_b1f5->SetPoint(3,15371.4,3456.52);
   	cutg_b1f5->SetPoint(4,15575.2,3456.52);
   	cutg_b1f5->SetPoint(5,15682,3480.16);
   	cutg_b1f5->SetPoint(6,15720.9,3541.62);
   	cutg_b1f5->SetPoint(7,15735.4,3614.9);
   	cutg_b1f5->SetPoint(8,15691.7,3690.54);
   	cutg_b1f5->SetPoint(9,15594.7,3752.01);
   	cutg_b1f5->SetPoint(10,15487.9,3822.92);
   	cutg_b1f5->SetPoint(11,15351.9,3900.93);
   	cutg_b1f5->SetPoint(12,15225.7,3919.84);
   	cutg_b1f5->SetPoint(13,15099.5,3938.75);
   	cutg_b1f5->SetPoint(14,14953.9,3929.3);
   	cutg_b1f5->SetPoint(15,14808.3,3922.21);
   	cutg_b1f5->SetPoint(16,14720.9,3884.38);
   	cutg_b1f5->SetPoint(17,14696.6,3822.92);
   	cutg_b1f5->SetPoint(18,14706.3,3742.55);
   	cutg_b1f5->SetPoint(19,14779.1,3664.54);
   	cutg_b1f5->SetPoint(20,14837.4,3612.54);
   	cutg_b1f5->SetPoint(21,14842.2,3579.44);
   	cutg_b1f5->SetPoint(22,14832.5,3577.08);
    cutg_b1f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f5
    c2->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f5 = banana_b1f5->ProjectionX("projx_cutg_b1f5",1,banana_b1f5->GetNbinsX(),"[cutg_b1f5]");              
    projx_cutg_b1f5->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f5->GetMaximumBin(); 
    centroidx = projx_cutg_b1f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f5 = banana_b1f5->ProjectionY("projy_cutg_b1f5",1,banana_b1f5->GetNbinsY(),"[cutg_b1f5]");              
    projy_cutg_b1f5->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb1f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f5_E = " <<  gainb1f5_E << " keV/ch" << endl;
    cout << " gainb1f5_dE = " << gainb1f5_dE << " keV/ch"<< endl;
    cout << endl;


    c2->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f6 186W(a,a') channel
    banana_b1f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b1f6 = new TCutG("cutg_b1f6",23);
    cutg_b1f6->SetVarX(" E detector 1 strip 6");
    cutg_b1f6->SetVarY("#DeltaE ");
    cutg_b1f6->SetTitle("Graph");
    cutg_b1f6->SetFillStyle(1000);
    cutg_b1f6->SetPoint(0,14909.7,3767.97);
   	cutg_b1f6->SetPoint(1,15002.2,3729);
   	cutg_b1f6->SetPoint(2,15141.1,3680.29);
   	cutg_b1f6->SetPoint(3,15212.6,3675.42);
   	cutg_b1f6->SetPoint(4,15351.4,3655.93);
   	cutg_b1f6->SetPoint(5,15477.6,3655.93);
   	cutg_b1f6->SetPoint(6,15637.5,3670.54);
   	cutg_b1f6->SetPoint(7,15730.1,3697.34);
   	cutg_b1f6->SetPoint(8,15805.8,3797.19);
   	cutg_b1f6->SetPoint(9,15776.3,3850.77);
   	cutg_b1f6->SetPoint(10,15658.5,3936.02);
   	cutg_b1f6->SetPoint(11,15523.9,4040.74);
   	cutg_b1f6->SetPoint(12,15284.1,4135.73);
   	cutg_b1f6->SetPoint(13,15107.4,4191.75);
   	cutg_b1f6->SetPoint(14,14913.9,4223.41);
   	cutg_b1f6->SetPoint(15,14728.8,4213.67);
   	cutg_b1f6->SetPoint(16,14665.7,4130.86);
   	cutg_b1f6->SetPoint(17,14636.2,4048.05);
   	cutg_b1f6->SetPoint(18,14707.7,3931.15);
   	cutg_b1f6->SetPoint(19,14787.7,3848.34);
   	cutg_b1f6->SetPoint(20,14871.8,3797.19);
   	cutg_b1f6->SetPoint(21,14918.1,3765.53);
   	cutg_b1f6->SetPoint(22,14909.7,3767.97);
    cutg_b1f6->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f6
    c2->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f6 = banana_b1f6->ProjectionX("projx_cutg_b1f6",1,banana_b1f6->GetNbinsX(),"[cutg_b1f6]");              
    projx_cutg_b1f6->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f6->GetMaximumBin(); 
    centroidx = projx_cutg_b1f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f6 = banana_b1f6->ProjectionY("projy_cutg_b1f6",1,banana_b1f6->GetNbinsY(),"[cutg_b1f6]");              
    projy_cutg_b1f6->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb1f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f6_E = " <<  gainb1f6_E << " keV/ch" << endl;
    cout << " gainb1f6_dE = " << gainb1f6_dE << " keV/ch"<< endl;
    cout << endl;


    c2->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f7 186(a,a') channel
    banana_b1f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b1f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b1f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b1f7 = new TCutG("cutg_b1f7",21);
    cutg_b1f7->SetVarX(" E detector 1 strip 7");
    cutg_b1f7->SetVarY("#DeltaE ");
    cutg_b1f7->SetTitle("Graph");
    cutg_b1f7->SetFillStyle(1000);
    cutg_b1f7->SetPoint(0,14660.7,3757.19);
   	cutg_b1f7->SetPoint(1,14831.5,3693.87);
   	cutg_b1f7->SetPoint(2,14997.7,3654.9);
   	cutg_b1f7->SetPoint(3,15197,3625.67);
   	cutg_b1f7->SetPoint(4,15410.6,3606.19);
   	cutg_b1f7->SetPoint(5,15562.5,3611.06);
   	cutg_b1f7->SetPoint(6,15709.6,3650.03);
   	cutg_b1f7->SetPoint(7,15752.4,3706.05);
   	cutg_b1f7->SetPoint(8,15733.4,3788.85);
   	cutg_b1f7->SetPoint(9,15610,3922.81);
   	cutg_b1f7->SetPoint(10,15415.4,3993.44);
   	cutg_b1f7->SetPoint(11,15230.2,4066.5);
   	cutg_b1f7->SetPoint(12,15068.9,4127.39);
   	cutg_b1f7->SetPoint(13,14817.3,4183.41);
   	cutg_b1f7->SetPoint(14,14489.8,4185.85);
   	cutg_b1f7->SetPoint(15,14409.1,4137.13);
   	cutg_b1f7->SetPoint(16,14418.6,4039.71);
   	cutg_b1f7->SetPoint(17,14518.3,3922.81);
   	cutg_b1f7->SetPoint(18,14618,3788.85);
   	cutg_b1f7->SetPoint(19,14670.2,3757.19);
   	cutg_b1f7->SetPoint(20,14660.7,3757.19);
    cutg_b1f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f7
    c2->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f7 = banana_b1f7->ProjectionX("projx_cutg_b1f7",1,banana_b1f7->GetNbinsX(),"[cutg_b1f7]");              
    projx_cutg_b1f7->GetXaxis()->SetRangeUser(13000,16500);
    projx_cutg_b1f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b1f7->GetMaximumBin(); 
    centroidx = projx_cutg_b1f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f7 = banana_b1f7->ProjectionY("projy_cutg_b1f7",1,banana_b1f7->GetNbinsY(),"[cutg_b1f7]");              
    projy_cutg_b1f7->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b1f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb1f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb1f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb1f7_E = " <<  gainb1f7_E << " keV/ch" << endl;
    cout << " gainb1f7_dE = " << gainb1f7_dE << " keV/ch"<< endl;
    cout << endl;


    ///////////////////
    // E DETECTOR b2 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c3 = new TCanvas("c3","c3:b2 bananas",1400,800);
    c3->Divide(8,3,0,0);
    c3->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b2f0 60Ni(a,a) elastic peak
    banana_b2f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b2f0 = new TCutG("cutg_b2f0",20);
    cutg_b2f0->SetVarX(" E detector 2 strip 0");
    cutg_b2f0->SetVarY("#DeltaE ");
    cutg_b2f0->SetTitle("Graph");
    cutg_b2f0->SetFillStyle(1000);
    cutg_b2f0->SetPoint(0,15464.6,3599.48);
   	cutg_b2f0->SetPoint(1,15644.1,3564.03);
   	cutg_b2f0->SetPoint(2,15802.9,3567.25);
   	cutg_b2f0->SetPoint(3,15941,3602.71);
   	cutg_b2f0->SetPoint(4,16010,3670.4);
   	cutg_b2f0->SetPoint(5,15947.9,3789.67);
   	cutg_b2f0->SetPoint(6,15865,3863.81);
   	cutg_b2f0->SetPoint(7,15747.7,3944.4);
   	cutg_b2f0->SetPoint(8,15575.1,4012.09);
   	cutg_b2f0->SetPoint(9,15388.7,4089.46);
   	cutg_b2f0->SetPoint(10,15195.3,4108.8);
   	cutg_b2f0->SetPoint(11,15008.9,4099.13);
   	cutg_b2f0->SetPoint(12,14891.6,4070.11);
   	cutg_b2f0->SetPoint(13,14891.6,3979.86);
   	cutg_b2f0->SetPoint(14,14933,3870.26);
   	cutg_b2f0->SetPoint(15,15022.7,3744.54);
   	cutg_b2f0->SetPoint(16,15174.6,3680.07);
   	cutg_b2f0->SetPoint(17,15326.5,3631.72);
   	cutg_b2f0->SetPoint(18,15464.6,3602.71);
   	cutg_b2f0->SetPoint(19,15464.6,3599.48);
    cutg_b2f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f0
    c3->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f0 = banana_b2f0->ProjectionX("projx_cutg_b2f0",1,banana_b2f0->GetNbinsX(),"[cutg_b2f0]");              
    projx_cutg_b2f0->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f0->GetMaximumBin(); 
    centroidx = projx_cutg_b2f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f0 = banana_b2f0->ProjectionY("projy_cutg_b2f0",1,banana_b2f0->GetNbinsY(),"[cutg_b2f0]");              
    projy_cutg_b2f0->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb2f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f0_E = " <<  gainb2f0_E << " keV/ch" << endl;
    cout << " gainb2f0_dE = " << gainb2f0_dE << " keV/ch"<< endl;
    cout << endl;

    c3->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f1 186W(a,a') channel
    banana_b2f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f1->Draw();
    QKinz_f1_graph->Draw("p same");
  
    TCutG *cutg_b2f1 = new TCutG("cutg_b2f1",20);
    cutg_b2f1->SetVarX(" E detector 2 strip 1");
    cutg_b2f1->SetVarY("#DeltaE ");
    cutg_b2f1->SetTitle("Graph");
    cutg_b2f1->SetFillStyle(1000);
    cutg_b2f1->SetPoint(0,15116.2,3863.94);
   	cutg_b2f1->SetPoint(1,15215.2,3828.48);
   	cutg_b2f1->SetPoint(2,15352.8,3773.32);
   	cutg_b2f1->SetPoint(3,15583.9,3698.47);
   	cutg_b2f1->SetPoint(4,15715.9,3655.13);
   	cutg_b2f1->SetPoint(5,15897.4,3643.31);
   	cutg_b2f1->SetPoint(6,16007.5,3678.77);
   	cutg_b2f1->SetPoint(7,16002,3781.2);
   	cutg_b2f1->SetPoint(8,15891.9,3875.76);
   	cutg_b2f1->SetPoint(9,15754.4,3966.38);
   	cutg_b2f1->SetPoint(10,15561.8,4056.99);
   	cutg_b2f1->SetPoint(11,15336.3,4159.43);
   	cutg_b2f1->SetPoint(12,15121.7,4210.64);
   	cutg_b2f1->SetPoint(13,14945.7,4190.95);
   	cutg_b2f1->SetPoint(14,14863.1,4135.79);
   	cutg_b2f1->SetPoint(15,14901.7,4037.29);
   	cutg_b2f1->SetPoint(16,14973.2,3946.68);
   	cutg_b2f1->SetPoint(17,15066.7,3895.46);
   	cutg_b2f1->SetPoint(18,15121.7,3867.88);
   	cutg_b2f1->SetPoint(19,15116.2,3863.94);
    cutg_b2f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f1
    c3->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f1 = banana_b2f1->ProjectionX("projx_cutg_b2f1",1,banana_b2f1->GetNbinsX(),"[cutg_b2f1]");              
    projx_cutg_b2f1->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f1->GetMaximumBin(); 
    centroidx = projx_cutg_b2f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f1 = banana_b2f1->ProjectionY("projy_cutg_b2f1",1,banana_b2f1->GetNbinsY(),"[cutg_b2f1]");              
    projy_cutg_b2f1->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb2f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f1_E = " <<  gainb2f1_E << " keV/ch" << endl;
    cout << " gainb2f1_dE = " << gainb2f1_dE << " keV/ch"<< endl;
    cout << endl;
    

    c3->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f2 186W(a,a') channel
    banana_b2f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b2f2 = new TCutG("cutg_b2f2",20);
    cutg_b2f2->SetVarX(" E detector 2 strip 2");
    cutg_b2f2->SetVarY("#DeltaE ");
    cutg_b2f2->SetTitle("Graph");
    cutg_b2f2->SetFillStyle(1000);
    cutg_b2f2->SetPoint(0,15122.8,3827.74);
   	cutg_b2f2->SetPoint(1,15273,3773.58);
   	cutg_b2f2->SetPoint(2,15495.7,3713.41);
   	cutg_b2f2->SetPoint(3,15733.9,3667.28);
   	cutg_b2f2->SetPoint(4,15909.9,3659.26);
   	cutg_b2f2->SetPoint(5,16075.6,3699.37);
   	cutg_b2f2->SetPoint(6,16065.2,3765.56);
   	cutg_b2f2->SetPoint(7,15961.7,3843.78);
   	cutg_b2f2->SetPoint(8,15873.7,3917.99);
   	cutg_b2f2->SetPoint(9,15728.7,3996.22);
   	cutg_b2f2->SetPoint(10,15594,4062.41);
   	cutg_b2f2->SetPoint(11,15433.5,4126.59);
   	cutg_b2f2->SetPoint(12,15273,4154.67);
   	cutg_b2f2->SetPoint(13,15107.3,4160.69);
   	cutg_b2f2->SetPoint(14,14905.4,4118.57);
   	cutg_b2f2->SetPoint(15,14900.2,4048.37);
   	cutg_b2f2->SetPoint(16,14920.9,3962.12);
   	cutg_b2f2->SetPoint(17,15040,3879.89);
   	cutg_b2f2->SetPoint(18,15128,3827.74);
   	cutg_b2f2->SetPoint(19,15122.8,3827.74);
    cutg_b2f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f2
    c3->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f2 = banana_b2f2->ProjectionX("projx_cutg_b2f2",1,banana_b2f2->GetNbinsX(),"[cutg_b2f2]");              
    projx_cutg_b2f2->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f2->GetMaximumBin(); 
    centroidx = projx_cutg_b2f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f2 = banana_b2f2->ProjectionY("projy_cutg_b2f2",1,banana_b2f2->GetNbinsY(),"[cutg_b2f2]");              
    projy_cutg_b2f2->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb2f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f2_E = " <<  gainb2f2_E << " keV/ch" << endl;
    cout << " gainb2f2_dE = " << gainb2f2_dE << " keV/ch"<< endl;
    cout << endl;

    c3->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f3 186W(a,a') channel
    banana_b2f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b2f3 = new TCutG("cutg_b2f3",19);
    cutg_b2f3->SetVarX(" E detector 2 strip 3");
    cutg_b2f3->SetVarY("#DeltaE ");
    cutg_b2f3->SetTitle("Graph");
    cutg_b2f3->SetFillStyle(1000);
    cutg_b2f3->SetPoint(0,15250.4,3896.85);
   	cutg_b2f3->SetPoint(1,15373.9,3853.87);
   	cutg_b2f3->SetPoint(2,15596.9,3810.89);
   	cutg_b2f3->SetPoint(3,15767.8,3797.99);
   	cutg_b2f3->SetPoint(4,15990.9,3819.48);
   	cutg_b2f3->SetPoint(5,16052.6,3886.1);
   	cutg_b2f3->SetPoint(6,16005.1,3982.81);
   	cutg_b2f3->SetPoint(7,15886.5,4053.72);
   	cutg_b2f3->SetPoint(8,15729.8,4148.28);
   	cutg_b2f3->SetPoint(9,15554.2,4229.94);
   	cutg_b2f3->SetPoint(10,15378.6,4272.92);
   	cutg_b2f3->SetPoint(11,15207.7,4298.71);
   	cutg_b2f3->SetPoint(12,15036.9,4272.92);
   	cutg_b2f3->SetPoint(13,14998.9,4189.11);
   	cutg_b2f3->SetPoint(14,15046.3,4088.11);
   	cutg_b2f3->SetPoint(15,15079.6,4006.45);
   	cutg_b2f3->SetPoint(16,15160.3,3935.53);
   	cutg_b2f3->SetPoint(17,15259.9,3894.7);
   	cutg_b2f3->SetPoint(18,15250.4,3896.85);
    cutg_b2f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f3
    c3->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f3 = banana_b2f3->ProjectionX("projx_cutg_b2f3",1,banana_b2f3->GetNbinsX(),"[cutg_b2f3]");              
    projx_cutg_b2f3->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f3->GetMaximumBin(); 
    centroidx = projx_cutg_b2f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f3 = banana_b2f3->ProjectionY("projy_cutg_b2f3",1,banana_b2f3->GetNbinsY(),"[cutg_b2f3]");              
    projy_cutg_b2f3->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb2f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f3_E = " <<  gainb2f3_E << " keV/ch" << endl;
    cout << " gainb2f3_dE = " << gainb2f3_dE << " keV/ch"<< endl;
    cout << endl;

 
    c3->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f4 186W(a,a') channel
    banana_b2f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b2f4 = new TCutG("cutg_b2f4",22);
    cutg_b2f4->SetVarX(" E detector 2 strip 4");
    cutg_b2f4->SetVarY("#DeltaE ");
    cutg_b2f4->SetTitle("Graph");
    cutg_b2f4->SetFillStyle(1000);
    cutg_b2f4->SetPoint(0,15139.2,3790.03);
   	cutg_b2f4->SetPoint(1,15279,3745.33);
   	cutg_b2f4->SetPoint(2,15496.4,3709.01);
   	cutg_b2f4->SetPoint(3,15641.4,3675.49);
   	cutg_b2f4->SetPoint(4,15833,3669.9);
   	cutg_b2f4->SetPoint(5,15978,3681.07);
   	cutg_b2f4->SetPoint(6,16045.3,3731.36);
   	cutg_b2f4->SetPoint(7,16045.3,3812.38);
   	cutg_b2f4->SetPoint(8,15946.9,3887.81);
   	cutg_b2f4->SetPoint(9,15817.5,3974.41);
   	cutg_b2f4->SetPoint(10,15724.3,4047.05);
   	cutg_b2f4->SetPoint(11,15548.2,4114.1);
   	cutg_b2f4->SetPoint(12,15320.4,4175.56);
   	cutg_b2f4->SetPoint(13,15128.8,4192.32);
   	cutg_b2f4->SetPoint(14,15014.9,4144.83);
   	cutg_b2f4->SetPoint(15,14968.3,4077.78);
   	cutg_b2f4->SetPoint(16,14968.3,4013.52);
   	cutg_b2f4->SetPoint(17,15035.6,3915.74);
   	cutg_b2f4->SetPoint(18,15082.2,3854.28);
   	cutg_b2f4->SetPoint(19,15144.3,3795.62);
   	cutg_b2f4->SetPoint(20,15159.9,3784.44);
   	cutg_b2f4->SetPoint(21,15139.2,3790.03);
    cutg_b2f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f4
    c3->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f4 = banana_b2f4->ProjectionX("projx_cutg_b2f4",1,banana_b2f4->GetNbinsX(),"[cutg_b2f4]");              
    projx_cutg_b2f4->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f4->GetMaximumBin(); 
    centroidx = projx_cutg_b2f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f4 = banana_b2f4->ProjectionY("projy_cutg_b2f4",1,banana_b2f4->GetNbinsY(),"[cutg_b2f4]");              
    projy_cutg_b2f4->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb2f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f4_E = " <<  gainb2f4_E << " keV/ch" << endl;
    cout << " gainb2f4_dE = " << gainb2f4_dE << " keV/ch"<< endl;
    cout << endl;

    
    c3->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f5 186W(a,a') channel
    banana_b2f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b2f5 = new TCutG("cutg_b2f5",19);
    cutg_b2f5->SetVarX(" E detector 2 strip 5");
    cutg_b2f5->SetVarY("#DeltaE ");
    cutg_b2f5->SetTitle("Graph");
    cutg_b2f5->SetFillStyle(1000);
    cutg_b2f5->SetPoint(0,15762.8,3648.94);
   	cutg_b2f5->SetPoint(1,15980.3,3663.98);
   	cutg_b2f5->SetPoint(2,16078.7,3734.18);
   	cutg_b2f5->SetPoint(3,16047.6,3824.44);
   	cutg_b2f5->SetPoint(4,15840.5,3959.83);
   	cutg_b2f5->SetPoint(5,15690.4,4037.55);
   	cutg_b2f5->SetPoint(6,15498.8,4120.29);
   	cutg_b2f5->SetPoint(7,15193.3,4205.53);
   	cutg_b2f5->SetPoint(8,14981,4147.87);
   	cutg_b2f5->SetPoint(9,14892.9,4082.68);
   	cutg_b2f5->SetPoint(10,14892.9,3982.39);
   	cutg_b2f5->SetPoint(11,14882.6,3872.08);
   	cutg_b2f5->SetPoint(12,15012,3789.34);
   	cutg_b2f5->SetPoint(13,15126,3764.27);
   	cutg_b2f5->SetPoint(14,15276.1,3729.17);
   	cutg_b2f5->SetPoint(15,15478.1,3679.03);
   	cutg_b2f5->SetPoint(16,15664.5,3653.95);
   	cutg_b2f5->SetPoint(17,15773.2,3648.94);
   	cutg_b2f5->SetPoint(18,15762.8,3648.94);
    cutg_b2f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f5
    c3->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f5 = banana_b2f5->ProjectionX("projx_cutg_b2f5",1,banana_b2f5->GetNbinsX(),"[cutg_b2f5]");              
    projx_cutg_b2f5->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f5->GetMaximumBin(); 
    centroidx = projx_cutg_b2f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f5 = banana_b2f5->ProjectionY("projy_cutg_b2f5",1,banana_b2f5->GetNbinsY(),"[cutg_b2f5]");              
    projy_cutg_b2f5->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb2f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f5_E = " <<  gainb2f5_E << " keV/ch" << endl;
    cout << " gainb2f5_dE = " << gainb2f5_dE << " keV/ch"<< endl;
    cout << endl;


    c3->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f6 186W(a,a') channel
    banana_b2f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b2f6 = new TCutG("cutg_b2f6",21);
    cutg_b2f6->SetVarX(" E detector 2 strip 6");
    cutg_b2f6->SetVarY("#DeltaE ");
    cutg_b2f6->SetTitle("Graph");
    cutg_b2f6->SetFillStyle(1000);
    cutg_b2f6->SetPoint(0,15954.2,3784.44);
   	cutg_b2f6->SetPoint(1,15916.4,3824.56);
   	cutg_b2f6->SetPoint(2,15848.5,3897.26);
   	cutg_b2f6->SetPoint(3,15727.7,3964.96);
   	cutg_b2f6->SetPoint(4,15591.7,4017.61);
   	cutg_b2f6->SetPoint(5,15395.4,4052.71);
   	cutg_b2f6->SetPoint(6,15206.6,4052.71);
   	cutg_b2f6->SetPoint(7,15048,4020.11);
   	cutg_b2f6->SetPoint(8,15017.8,3962.45);
   	cutg_b2f6->SetPoint(9,15048,3884.73);
   	cutg_b2f6->SetPoint(10,15161.3,3804.5);
   	cutg_b2f6->SetPoint(11,15267,3754.36);
   	cutg_b2f6->SetPoint(12,15493.6,3646.55);
   	cutg_b2f6->SetPoint(13,15644.6,3623.98);
   	cutg_b2f6->SetPoint(14,15856,3618.97);
   	cutg_b2f6->SetPoint(15,15961.7,3626.49);
   	cutg_b2f6->SetPoint(16,16075,3651.56);
   	cutg_b2f6->SetPoint(17,16075,3699.2);
   	cutg_b2f6->SetPoint(18,16014.6,3744.33);
   	cutg_b2f6->SetPoint(19,15954.2,3794.47);
   	cutg_b2f6->SetPoint(20,15954.2,3784.44);
    cutg_b2f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b2f6
    c3->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f6 = banana_b2f6->ProjectionX("projx_cutg_b2f6",1,banana_b2f6->GetNbinsX(),"[cutg_b2f6]");              
    projx_cutg_b2f6->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f6->GetMaximumBin(); 
    centroidx = projx_cutg_b2f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f6 = banana_b2f6->ProjectionY("projy_cutg_b2f6",1,banana_b2f6->GetNbinsY(),"[cutg_b2f6]");              
    projy_cutg_b2f6->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb2f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f6_E = " <<  gainb2f6_E << " keV/ch" << endl;
    cout << " gainb2f6_dE = " << gainb2f6_dE << " keV/ch"<< endl;
    cout << endl;
    

    c3->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f7 186W(a,a') channel
    banana_b2f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b2f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b2f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b2f7 = new TCutG("cutg_b2f7",26);
    cutg_b2f7->SetVarX(" E detector 2 strip 7");
    cutg_b2f7->SetVarY("#DeltaE ");
    cutg_b2f7->SetTitle("Graph");
    cutg_b2f7->SetFillStyle(1000);
    cutg_b2f7->SetPoint(0,15991.8,3978.57);
   	cutg_b2f7->SetPoint(1,15954.8,4047.34);
   	cutg_b2f7->SetPoint(2,15928.4,4110.37);
   	cutg_b2f7->SetPoint(3,15828,4147.62);
   	cutg_b2f7->SetPoint(4,15685.2,4230.72);
   	cutg_b2f7->SetPoint(5,15558.4,4282.29);
   	cutg_b2f7->SetPoint(6,15447.4,4331);
   	cutg_b2f7->SetPoint(7,15320.5,4391.17);
   	cutg_b2f7->SetPoint(8,15161.9,4405.5);
   	cutg_b2f7->SetPoint(9,15050.9,4405.5);
   	cutg_b2f7->SetPoint(10,14924.1,4373.98);
   	cutg_b2f7->SetPoint(11,14865.9,4336.73);
   	cutg_b2f7->SetPoint(12,14844.8,4270.83);
   	cutg_b2f7->SetPoint(13,14860.6,4213.52);
   	cutg_b2f7->SetPoint(14,14897.6,4153.35);
   	cutg_b2f7->SetPoint(15,15003.4,4047.34);
   	cutg_b2f7->SetPoint(16,15177.8,3992.89);
   	cutg_b2f7->SetPoint(17,15341.7,3941.32);
   	cutg_b2f7->SetPoint(18,15447.4,3889.74);
   	cutg_b2f7->SetPoint(19,15584.8,3866.82);
   	cutg_b2f7->SetPoint(20,15753.9,3858.22);
   	cutg_b2f7->SetPoint(21,15902,3875.42);
   	cutg_b2f7->SetPoint(22,15954.8,3898.34);
   	cutg_b2f7->SetPoint(23,15981.2,3947.05);
   	cutg_b2f7->SetPoint(24,15986.5,3992.89);
   	cutg_b2f7->SetPoint(25,15991.8,3978.57);
    cutg_b2f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f7
    c3->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f7 = banana_b2f7->ProjectionX("projx_cutg_b2f7",1,banana_b2f7->GetNbinsX(),"[cutg_b2f7]");              
    projx_cutg_b2f7->GetXaxis()->SetRangeUser(13500,17000);
    projx_cutg_b2f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b2f7->GetMaximumBin(); 
    centroidx = projx_cutg_b2f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f7 = banana_b2f7->ProjectionY("projy_cutg_b2f7",1,banana_b2f7->GetNbinsY(),"[cutg_b2f7]");              
    projy_cutg_b2f7->GetXaxis()->SetRangeUser(3000,4500);
    projy_cutg_b2f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb2f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb2f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb2f7_E = " <<  gainb2f7_E << " keV/ch" << endl;
    cout << " gainb2f7_dE = " << gainb2f7_dE << " keV/ch"<< endl;
    cout << endl;
    

    ///////////////////
    // E DETECTOR b3 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c4 = new TCanvas("c4","c4:b3 bananas",1400,800);
    c4->Divide(8,3,0,0);
    c4->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b3f0 186W(a,a') channel
    banana_b3f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b3f0 = new TCutG("cutg_b3f0",22);
    cutg_b3f0->SetVarX(" E detector 3 strip 0");
    cutg_b3f0->SetVarY("#DeltaE ");
    cutg_b3f0->SetTitle("Graph");
    cutg_b3f0->SetFillStyle(1000);
    cutg_b3f0->SetPoint(0,16288.7,4029.66);
   	cutg_b3f0->SetPoint(1,16198.6,4164.83);
   	cutg_b3f0->SetPoint(2,16092,4237.89);
   	cutg_b3f0->SetPoint(3,16014.1,4285.39);
   	cutg_b3f0->SetPoint(4,15862.4,4391.33);
   	cutg_b3f0->SetPoint(5,15743.5,4442.48);
   	cutg_b3f0->SetPoint(6,15645.2,4457.09);
   	cutg_b3f0->SetPoint(7,15518.1,4457.09);
   	cutg_b3f0->SetPoint(8,15444.3,4438.83);
   	cutg_b3f0->SetPoint(9,15378.7,4384.03);
   	cutg_b3f0->SetPoint(10,15370.5,4281.73);
   	cutg_b3f0->SetPoint(11,15391,4164.83);
   	cutg_b3f0->SetPoint(12,15485.3,4084.46);
   	cutg_b3f0->SetPoint(13,15587.8,4015.04);
   	cutg_b3f0->SetPoint(14,15723,3949.28);
   	cutg_b3f0->SetPoint(15,15919.8,3883.52);
   	cutg_b3f0->SetPoint(16,16051,3872.56);
   	cutg_b3f0->SetPoint(17,16153.5,3868.91);
   	cutg_b3f0->SetPoint(18,16215,3912.75);
   	cutg_b3f0->SetPoint(19,16255.9,3967.55);
   	cutg_b3f0->SetPoint(20,16280.5,4051.58);
   	cutg_b3f0->SetPoint(21,16288.7,4029.66);
    cutg_b3f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f0
    c4->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f0 = banana_b3f0->ProjectionX("projx_cutg_b3f0",1,banana_b3f0->GetNbinsX(),"[cutg_b3f0]");              
    projx_cutg_b3f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f0->GetMaximumBin(); 
    centroidx = projx_cutg_b3f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f0 = banana_b3f0->ProjectionY("projy_cutg_b3f0",1,banana_b3f0->GetNbinsY(),"[cutg_b3f0]");              
    projy_cutg_b3f0->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb3f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f0_E = " <<  gainb3f0_E << " keV/ch" << endl;
    cout << " gainb3f0_dE = " << gainb3f0_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f1 186W(a,a') channel
    banana_b3f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f1->Draw();
    QKinz_f1_graph->Draw("p same");
   
    TCutG *cutg_b3f1 = new TCutG("cutg_b3f1",22);
    cutg_b3f1->SetVarX(" E detector 3 strip 1");
    cutg_b3f1->SetVarY("#DeltaE ");
    cutg_b3f1->SetTitle("Graph");
    cutg_b3f1->SetFillStyle(1000);
    cutg_b3f1->SetPoint(0,16296.9,4003.55);
   	cutg_b3f1->SetPoint(1,16247.1,4071.6);
   	cutg_b3f1->SetPoint(2,16115.7,4158.71);
   	cutg_b3f1->SetPoint(3,15939,4275.76);
   	cutg_b3f1->SetPoint(4,15812.1,4308.42);
   	cutg_b3f1->SetPoint(5,15676.2,4324.76);
   	cutg_b3f1->SetPoint(6,15513.1,4346.53);
   	cutg_b3f1->SetPoint(7,15395.3,4322.03);
   	cutg_b3f1->SetPoint(8,15313.7,4229.48);
   	cutg_b3f1->SetPoint(9,15309.2,4161.43);
   	cutg_b3f1->SetPoint(10,15340.9,4101.55);
   	cutg_b3f1->SetPoint(11,15399.8,4028.05);
   	cutg_b3f1->SetPoint(12,15508.5,3960);
   	cutg_b3f1->SetPoint(13,15649,3911);
   	cutg_b3f1->SetPoint(14,15807.6,3859.28);
   	cutg_b3f1->SetPoint(15,15952.6,3815.73);
   	cutg_b3f1->SetPoint(16,16061.3,3815.73);
   	cutg_b3f1->SetPoint(17,16224.4,3815.73);
   	cutg_b3f1->SetPoint(18,16296.9,3862.01);
   	cutg_b3f1->SetPoint(19,16337.7,3930.06);
   	cutg_b3f1->SetPoint(20,16292.4,4014.44);
   	cutg_b3f1->SetPoint(21,16296.9,4003.55);
    cutg_b3f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f1
    c4->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f1 = banana_b3f1->ProjectionX("projx_cutg_b3f1",1,banana_b3f1->GetNbinsX(),"[cutg_b3f1]");              
    projx_cutg_b3f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f1->GetMaximumBin(); 
    centroidx = projx_cutg_b3f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f1 = banana_b3f1->ProjectionY("projy_cutg_b3f1",1,banana_b3f1->GetNbinsY(),"[cutg_b3f1]");              
    projy_cutg_b3f1->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb3f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f1_E = " <<  gainb3f1_E << " keV/ch" << endl;
    cout << " gainb3f1_dE = " << gainb3f1_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f2 186W(a,a') channel
    banana_b3f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b3f2 = new TCutG("cutg_b3f2",19);
    cutg_b3f2->SetVarX(" E detector 3 strip 2");
    cutg_b3f2->SetVarY("#DeltaE ");
    cutg_b3f2->SetTitle("Graph");
    cutg_b3f2->SetFillStyle(1000);
    cutg_b3f2->SetPoint(0,16280.7,3878.04);
   	cutg_b3f2->SetPoint(1,16227.6,3954.4);
   	cutg_b3f2->SetPoint(2,16086.1,4045.44);
   	cutg_b3f2->SetPoint(3,15962.2,4115.93);
   	cutg_b3f2->SetPoint(4,15767.6,4177.61);
   	cutg_b3f2->SetPoint(5,15612.8,4189.36);
   	cutg_b3f2->SetPoint(6,15400.5,4186.42);
   	cutg_b3f2->SetPoint(7,15351.9,4089.5);
   	cutg_b3f2->SetPoint(8,15404.9,3992.58);
   	cutg_b3f2->SetPoint(9,15489,3913.28);
   	cutg_b3f2->SetPoint(10,15612.8,3833.98);
   	cutg_b3f2->SetPoint(11,15758.8,3757.62);
   	cutg_b3f2->SetPoint(12,15935.7,3698.88);
   	cutg_b3f2->SetPoint(13,16068.4,3684.2);
   	cutg_b3f2->SetPoint(14,16236.4,3693.01);
   	cutg_b3f2->SetPoint(15,16302.8,3731.19);
   	cutg_b3f2->SetPoint(16,16302.8,3819.3);
   	cutg_b3f2->SetPoint(17,16271.8,3901.53);
   	cutg_b3f2->SetPoint(18,16280.7,3878.04);
    cutg_b3f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f2
    c4->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f2 = banana_b3f2->ProjectionX("projx_cutg_b3f2",1,banana_b3f2->GetNbinsX(),"[cutg_b3f2]");              
    projx_cutg_b3f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f2->GetMaximumBin(); 
    centroidx = projx_cutg_b3f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f2 = banana_b3f2->ProjectionY("projy_cutg_b3f2",1,banana_b3f2->GetNbinsY(),"[cutg_b3f2]");              
    projy_cutg_b3f2->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb3f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f2_E = " <<  gainb3f2_E << " keV/ch" << endl;
    cout << " gainb3f2_dE = " << gainb3f2_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f3 186W(a,a') channel
    banana_b3f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b3f3 = new TCutG("cutg_b3f3",20);
    cutg_b3f3->SetVarX(" E detector 3 strip 3");
    cutg_b3f3->SetVarY("#DeltaE ");
    cutg_b3f3->SetTitle("Graph");
    cutg_b3f3->SetFillStyle(1000);
    cutg_b3f3->SetPoint(0,16323.1,3932.54);
   	cutg_b3f3->SetPoint(1,16249.8,4015.27);
   	cutg_b3f3->SetPoint(2,16064.2,4114.56);
   	cutg_b3f3->SetPoint(3,15926.1,4183.11);
   	cutg_b3f3->SetPoint(4,15757.8,4242.21);
   	cutg_b3f3->SetPoint(5,15611.1,4272.94);
   	cutg_b3f3->SetPoint(6,15468.7,4270.57);
   	cutg_b3f3->SetPoint(7,15304.8,4237.48);
   	cutg_b3f3->SetPoint(8,15287.5,4142.92);
   	cutg_b3f3->SetPoint(9,15309.1,4079.1);
   	cutg_b3f3->SetPoint(10,15391.1,3996.36);
   	cutg_b3f3->SetPoint(11,15524.8,3915.99);
   	cutg_b3f3->SetPoint(12,15740.6,3833.25);
   	cutg_b3f3->SetPoint(13,15921.8,3767.06);
   	cutg_b3f3->SetPoint(14,16081.5,3750.52);
   	cutg_b3f3->SetPoint(15,16271.3,3748.15);
   	cutg_b3f3->SetPoint(16,16340.4,3783.61);
   	cutg_b3f3->SetPoint(17,16374.9,3863.98);
   	cutg_b3f3->SetPoint(18,16318.8,3939.63);
   	cutg_b3f3->SetPoint(19,16323.1,3932.54);
    cutg_b3f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f3
    c4->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f3 = banana_b3f3->ProjectionX("projx_cutg_b3f3",1,banana_b3f3->GetNbinsX(),"[cutg_b3f3]");              
    projx_cutg_b3f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f3->GetMaximumBin(); 
    centroidx = projx_cutg_b3f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f3 = banana_b3f3->ProjectionY("projy_cutg_b3f3",1,banana_b3f3->GetNbinsY(),"[cutg_b3f3]");              
    projy_cutg_b3f3->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb3f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f3_E = " <<  gainb3f3_E << " keV/ch" << endl;
    cout << " gainb3f3_dE = " << gainb3f3_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f4 186W(a,a') channel
    banana_b3f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b3f4 = new TCutG("cutg_b3f4",21);
    cutg_b3f4->SetVarX(" E detector 3 strip 4");
    cutg_b3f4->SetVarY("#DeltaE ");
    cutg_b3f4->SetTitle("Graph");
    cutg_b3f4->SetFillStyle(1000);
    cutg_b3f4->SetPoint(0,16393.8,3823.62);
   	cutg_b3f4->SetPoint(1,16324.2,3919.04);
   	cutg_b3f4->SetPoint(2,16231.4,4001.2);
   	cutg_b3f4->SetPoint(3,16120.1,4046.26);
   	cutg_b3f4->SetPoint(4,15916,4141.68);
   	cutg_b3f4->SetPoint(5,15744.4,4184.08);
   	cutg_b3f4->SetPoint(6,15600.6,4189.38);
   	cutg_b3f4->SetPoint(7,15424.3,4178.78);
   	cutg_b3f4->SetPoint(8,15350.1,4136.38);
   	cutg_b3f4->SetPoint(9,15308.3,4054.21);
   	cutg_b3f4->SetPoint(10,15364,3961.45);
   	cutg_b3f4->SetPoint(11,15480,3895.19);
   	cutg_b3f4->SetPoint(12,15651.6,3807.72);
   	cutg_b3f4->SetPoint(13,15837.1,3744.11);
   	cutg_b3f4->SetPoint(14,16027.3,3701.7);
   	cutg_b3f4->SetPoint(15,16189.7,3693.75);
   	cutg_b3f4->SetPoint(16,16282.4,3712.31);
   	cutg_b3f4->SetPoint(17,16356.7,3767.97);
   	cutg_b3f4->SetPoint(18,16370.6,3820.97);
   	cutg_b3f4->SetPoint(19,16393.8,3834.23);
   	cutg_b3f4->SetPoint(20,16393.8,3823.62);
    cutg_b3f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f4
    c4->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f4 = banana_b3f4->ProjectionX("projx_cutg_b3f4",1,banana_b3f4->GetNbinsX(),"[cutg_b3f4]");              
    projx_cutg_b3f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f4->GetMaximumBin(); 
    centroidx = projx_cutg_b3f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f4 = banana_b3f4->ProjectionY("projy_cutg_b3f4",1,banana_b3f4->GetNbinsY(),"[cutg_b3f4]");              
    projy_cutg_b3f4->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb3f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f4_E = " <<  gainb3f4_E << " keV/ch" << endl;
    cout << " gainb3f4_dE = " << gainb3f4_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f5 186W(a,a') channel
    banana_b3f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b3f5 = new TCutG("cutg_b3f5",20);
    cutg_b3f5->SetVarX(" E detector 3 strip 5");
    cutg_b3f5->SetVarY("#DeltaE ");
    cutg_b3f5->SetTitle("Graph");
    cutg_b3f5->SetFillStyle(1000);
    cutg_b3f5->SetPoint(0,16415.9,3946.16);
   	cutg_b3f5->SetPoint(1,16346.3,4038.57);
   	cutg_b3f5->SetPoint(2,16227.4,4115.57);
   	cutg_b3f5->SetPoint(3,16010.1,4229.54);
   	cutg_b3f5->SetPoint(4,15866.6,4318.87);
   	cutg_b3f5->SetPoint(5,15686.3,4358.91);
   	cutg_b3f5->SetPoint(6,15473.1,4374.31);
   	cutg_b3f5->SetPoint(7,15362.4,4312.71);
   	cutg_b3f5->SetPoint(8,15333.7,4226.46);
   	cutg_b3f5->SetPoint(9,15354.2,4130.97);
   	cutg_b3f5->SetPoint(10,15456.7,4035.49);
   	cutg_b3f5->SetPoint(11,15620.7,3958.48);
   	cutg_b3f5->SetPoint(12,15895.3,3847.59);
   	cutg_b3f5->SetPoint(13,16071.6,3816.79);
   	cutg_b3f5->SetPoint(14,16243.8,3801.39);
   	cutg_b3f5->SetPoint(15,16362.7,3826.03);
   	cutg_b3f5->SetPoint(16,16432.3,3881.48);
   	cutg_b3f5->SetPoint(17,16432.3,3924.6);
   	cutg_b3f5->SetPoint(18,16407.7,3958.48);
   	cutg_b3f5->SetPoint(19,16415.9,3946.16);
    cutg_b3f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f5
    c4->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f5 = banana_b3f5->ProjectionX("projx_cutg_b3f5",1,banana_b3f5->GetNbinsX(),"[cutg_b3f5]");              
    projx_cutg_b3f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f5->GetMaximumBin(); 
    centroidx = projx_cutg_b3f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f5 = banana_b3f5->ProjectionY("projy_cutg_b3f5",1,banana_b3f5->GetNbinsY(),"[cutg_b3f5]");              
    projy_cutg_b3f5->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb3f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f5_E = " <<  gainb3f5_E << " keV/ch" << endl;
    cout << " gainb3f5_dE = " << gainb3f5_dE << " keV/ch"<< endl;
    cout << endl;


    c4->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f6 186W(a,a') channel
    banana_b3f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b3f6 = new TCutG("cutg_b3f6",21);
    cutg_b3f6->SetVarX(" E detector 3 strip 6");
    cutg_b3f6->SetVarY("#DeltaE ");
    cutg_b3f6->SetTitle("Graph");
    cutg_b3f6->SetFillStyle(1000);
    cutg_b3f6->SetPoint(0,16427.4,3974.67);
   	cutg_b3f6->SetPoint(1,16339.4,4072.66);
   	cutg_b3f6->SetPoint(2,16229.4,4140.72);
   	cutg_b3f6->SetPoint(3,16108.3,4192.44);
   	cutg_b3f6->SetPoint(4,15954.3,4268.65);
   	cutg_b3f6->SetPoint(5,15690.2,4350.32);
   	cutg_b3f6->SetPoint(6,15508.6,4372.09);
   	cutg_b3f6->SetPoint(7,15288.6,4358.48);
   	cutg_b3f6->SetPoint(8,15239.1,4244.15);
   	cutg_b3f6->SetPoint(9,15360.1,4140.72);
   	cutg_b3f6->SetPoint(10,15448.1,4045.44);
   	cutg_b3f6->SetPoint(11,15596.7,3966.5);
   	cutg_b3f6->SetPoint(12,15778.2,3898.45);
   	cutg_b3f6->SetPoint(13,15921.3,3830.4);
   	cutg_b3f6->SetPoint(14,16058.8,3781.4);
   	cutg_b3f6->SetPoint(15,16245.9,3784.13);
   	cutg_b3f6->SetPoint(16,16383.4,3819.51);
   	cutg_b3f6->SetPoint(17,16460.4,3876.68);
   	cutg_b3f6->SetPoint(18,16454.9,3952.89);
   	cutg_b3f6->SetPoint(19,16416.4,3982.84);
   	cutg_b3f6->SetPoint(20,16427.4,3974.67);
    cutg_b3f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b3f6
    c4->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f6 = banana_b3f6->ProjectionX("projx_cutg_b3f6",1,banana_b3f6->GetNbinsX(),"[cutg_b3f6]");              
    projx_cutg_b3f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f6->GetMaximumBin(); 
    centroidx = projx_cutg_b3f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f6 = banana_b3f6->ProjectionY("projy_cutg_b3f6",1,banana_b3f6->GetNbinsY(),"[cutg_b3f6]");              
    projy_cutg_b3f6->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb3f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f6_E = " <<  gainb3f6_E << " keV/ch" << endl;
    cout << " gainb3f6_dE = " << gainb3f6_dE << " keV/ch"<< endl;
    cout << endl;

    c4->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f7 186W(a,a') channel
    banana_b3f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b3f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b3f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b3f7 = new TCutG("cutg_b3f7",18);
    cutg_b3f7->SetVarX(" E detector 3 strip 7");
    cutg_b3f7->SetVarY("#DeltaE ");
    cutg_b3f7->SetTitle("Graph");
    cutg_b3f7->SetFillStyle(1000);
    cutg_b3f7->SetPoint(0,16424,4007.01);
   	cutg_b3f7->SetPoint(1,16333.8,4149.91);
   	cutg_b3f7->SetPoint(2,16182.2,4245.19);
   	cutg_b3f7->SetPoint(3,16005.9,4363.02);
   	cutg_b3f7->SetPoint(4,15809.1,4435.73);
   	cutg_b3f7->SetPoint(5,15583.7,4498.41);
   	cutg_b3f7->SetPoint(6,15374.6,4498.41);
   	cutg_b3f7->SetPoint(7,15272.1,4410.66);
   	cutg_b3f7->SetPoint(8,15276.2,4285.3);
   	cutg_b3f7->SetPoint(9,15325.4,4197.55);
   	cutg_b3f7->SetPoint(10,15448.4,4079.71);
   	cutg_b3f7->SetPoint(11,15678,3986.95);
   	cutg_b3f7->SetPoint(12,15977.2,3914.24);
   	cutg_b3f7->SetPoint(13,16239.5,3879.14);
   	cutg_b3f7->SetPoint(14,16362.5,3904.21);
   	cutg_b3f7->SetPoint(15,16424,3961.88);
   	cutg_b3f7->SetPoint(16,16415.8,4024.56);
   	cutg_b3f7->SetPoint(17,16424,4007.01);
    cutg_b3f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f7
    c4->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f7 = banana_b3f7->ProjectionX("projx_cutg_b3f7",1,banana_b3f7->GetNbinsX(),"[cutg_b3f7]");              
    projx_cutg_b3f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b3f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b3f7->GetMaximumBin(); 
    centroidx = projx_cutg_b3f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f7 = banana_b3f7->ProjectionY("projy_cutg_b3f7",1,banana_b3f7->GetNbinsY(),"[cutg_b3f7]");              
    projy_cutg_b3f7->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b3f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb3f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb3f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb3f7_E = " <<  gainb3f7_E << " keV/ch" << endl;
    cout << " gainb3f7_dE = " << gainb3f7_dE << " keV/ch"<< endl;
    cout << endl;


    ///////////////////
    // E DETECTOR b4 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c5 = new TCanvas("c5","c5:b4 bananas",1400,800);
    c5->Divide(8,3,0,0);
    c5->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b4f0 186W(a,a') channel
    banana_b4f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b4f0 = new TCutG("cutg_b4f0",17);
    cutg_b4f0->SetVarX(" E detector 4 strip 0");
    cutg_b4f0->SetVarY("#DeltaE ");
    cutg_b4f0->SetTitle("Graph");
    cutg_b4f0->SetFillStyle(1000);
    cutg_b4f0->SetPoint(0,16381.7,3988.42);
   	cutg_b4f0->SetPoint(1,16234.6,4114.79);
   	cutg_b4f0->SetPoint(2,16021.7,4207.62);
   	cutg_b4f0->SetPoint(3,15818.9,4292.72);
   	cutg_b4f0->SetPoint(4,15590.7,4313.35);
   	cutg_b4f0->SetPoint(5,15408.2,4292.72);
   	cutg_b4f0->SetPoint(6,15382.8,4210.2);
   	cutg_b4f0->SetPoint(7,15382.8,4094.15);
   	cutg_b4f0->SetPoint(8,15469,3954.9);
   	cutg_b4f0->SetPoint(9,15626.2,3893.01);
   	cutg_b4f0->SetPoint(10,15910.1,3831.12);
   	cutg_b4f0->SetPoint(11,16112.9,3813.07);
   	cutg_b4f0->SetPoint(12,16325.9,3813.07);
   	cutg_b4f0->SetPoint(13,16452.6,3874.96);
   	cutg_b4f0->SetPoint(14,16452.6,3934.27);
   	cutg_b4f0->SetPoint(15,16376.6,3998.74);
   	cutg_b4f0->SetPoint(16,16381.7,3988.42);
    cutg_b4f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f0
    c5->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f0 = banana_b4f0->ProjectionX("projx_cutg_b4f0",1,banana_b4f0->GetNbinsX(),"[cutg_b4f0]");              
    projx_cutg_b4f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f0->GetMaximumBin(); 
    centroidx = projx_cutg_b4f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f0 = banana_b4f0->ProjectionY("projy_cutg_b4f0",1,banana_b4f0->GetNbinsY(),"[cutg_b4f0]");              
    projy_cutg_b4f0->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb4f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f0_E = " <<  gainb4f0_E << " keV/ch" << endl;
    cout << " gainb4f0_dE = " << gainb4f0_dE << " keV/ch"<< endl;
    cout << endl;


    c5->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f1 186W(a,a') channel
    banana_b4f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f1->Draw();
    QKinz_f1_graph->Draw("p same");
   
    TCutG *cutg_b4f1 = new TCutG("cutg_b4f1",17);
    cutg_b4f1->SetVarX(" E detector 4 strip 1");
    cutg_b4f1->SetVarY("#DeltaE ");
    cutg_b4f1->SetTitle("Graph");
    cutg_b4f1->SetFillStyle(1000);
    cutg_b4f1->SetPoint(0,16426.2,3982.58);
   	cutg_b4f1->SetPoint(1,16326.5,4106.79);
   	cutg_b4f1->SetPoint(2,16169.9,4226.13);
   	cutg_b4f1->SetPoint(3,15913.6,4330.86);
   	cutg_b4f1->SetPoint(4,15733.2,4401.49);
   	cutg_b4f1->SetPoint(5,15410.4,4408.8);
   	cutg_b4f1->SetPoint(6,15329.8,4289.46);
   	cutg_b4f1->SetPoint(7,15348.7,4155.5);
   	cutg_b4f1->SetPoint(8,15438.9,4062.95);
   	cutg_b4f1->SetPoint(9,15628.8,3972.84);
   	cutg_b4f1->SetPoint(10,15809.1,3916.82);
   	cutg_b4f1->SetPoint(11,16089.2,3848.62);
   	cutg_b4f1->SetPoint(12,16260.1,3831.58);
   	cutg_b4f1->SetPoint(13,16487.9,3872.98);
   	cutg_b4f1->SetPoint(14,16478.4,3960.66);
   	cutg_b4f1->SetPoint(15,16421.4,3994.76);
   	cutg_b4f1->SetPoint(16,16426.2,3982.58);
    cutg_b4f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f1
    c5->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f1 = banana_b4f1->ProjectionX("projx_cutg_b4f1",1,banana_b4f1->GetNbinsX(),"[cutg_b4f1]");              
    projx_cutg_b4f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f1->GetMaximumBin(); 
    centroidx = projx_cutg_b4f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f1 = banana_b4f1->ProjectionY("projy_cutg_b4f1",1,banana_b4f1->GetNbinsY(),"[cutg_b4f1]");              
    projy_cutg_b4f1->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb4f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f1_E = " <<  gainb4f1_E << " keV/ch" << endl;
    cout << " gainb4f1_dE = " << gainb4f1_dE << " keV/ch"<< endl;
    cout << endl;
    

    c5->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f2 186W(a,a') channel
    banana_b4f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b4f2 = new TCutG("cutg_b4f2",17);
    cutg_b4f2->SetVarX(" E detector 4 strip 2");
    cutg_b4f2->SetVarY("#DeltaE ");
    cutg_b4f2->SetTitle("Graph");
    cutg_b4f2->SetFillStyle(1000);
    cutg_b4f2->SetPoint(0,16344.4,3969.64);
   	cutg_b4f2->SetPoint(1,16246.1,4062.41);
   	cutg_b4f2->SetPoint(2,16092.3,4149.87);
   	cutg_b4f2->SetPoint(3,15852.5,4239.99);
   	cutg_b4f2->SetPoint(4,15625,4322.15);
   	cutg_b4f2->SetPoint(5,15379.1,4322.15);
   	cutg_b4f2->SetPoint(6,15311.4,4239.99);
   	cutg_b4f2->SetPoint(7,15311.4,4112.77);
   	cutg_b4f2->SetPoint(8,15372.9,4006.75);
   	cutg_b4f2->SetPoint(9,15471.3,3951.09);
   	cutg_b4f2->SetPoint(10,15643.5,3887.48);
   	cutg_b4f2->SetPoint(11,15932.5,3815.92);
   	cutg_b4f2->SetPoint(12,16178.4,3821.22);
   	cutg_b4f2->SetPoint(13,16362.9,3853.02);
   	cutg_b4f2->SetPoint(14,16399.8,3895.43);
   	cutg_b4f2->SetPoint(15,16344.4,3972.29);
   	cutg_b4f2->SetPoint(16,16344.4,3969.64);
    cutg_b4f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f2
    c5->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f2 = banana_b4f2->ProjectionX("projx_cutg_b4f2",1,banana_b4f2->GetNbinsX(),"[cutg_b4f2]");              
    projx_cutg_b4f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f2->GetMaximumBin(); 
    centroidx = projx_cutg_b4f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f2 = banana_b4f2->ProjectionY("projy_cutg_b4f2",1,banana_b4f2->GetNbinsY(),"[cutg_b4f2]");              
    projy_cutg_b4f2->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb4f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f2_E = " <<  gainb4f2_E << " keV/ch" << endl;
    cout << " gainb4f2_dE = " << gainb4f2_dE << " keV/ch"<< endl;
    cout << endl;


    c5->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f3 186W(a,a') channel
    banana_b4f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b4f3 = new TCutG("cutg_b4f3",17);
    cutg_b4f3->SetVarX(" E detector 4 strip 3");
    cutg_b4f3->SetVarY("#DeltaE ");
    cutg_b4f3->SetTitle("Graph");
    cutg_b4f3->SetFillStyle(1000);
    cutg_b4f3->SetPoint(0,16359.9,3969.91);
   	cutg_b4f3->SetPoint(1,16199.4,4081.66);
   	cutg_b4f3->SetPoint(2,16025.5,4180.52);
   	cutg_b4f3->SetPoint(3,15778,4253.58);
   	cutg_b4f3->SetPoint(4,15584.1,4253.58);
   	cutg_b4f3->SetPoint(5,15436.9,4206.3);
   	cutg_b4f3->SetPoint(6,15396.8,4090.26);
   	cutg_b4f3->SetPoint(7,15430.2,3995.7);
   	cutg_b4f3->SetPoint(8,15523.9,3901.15);
   	cutg_b4f3->SetPoint(9,15731.2,3832.38);
   	cutg_b4f3->SetPoint(10,15958.6,3763.61);
   	cutg_b4f3->SetPoint(11,16232.8,3746.42);
   	cutg_b4f3->SetPoint(12,16366.6,3776.5);
   	cutg_b4f3->SetPoint(13,16420.1,3879.66);
   	cutg_b4f3->SetPoint(14,16380,3952.72);
   	cutg_b4f3->SetPoint(15,16339.8,3987.11);
   	cutg_b4f3->SetPoint(16,16359.9,3969.91);
    cutg_b4f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f3
    c5->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f3 = banana_b4f3->ProjectionX("projx_cutg_b4f3",1,banana_b4f3->GetNbinsX(),"[cutg_b4f3]");              
    projx_cutg_b4f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f3->GetMaximumBin(); 
    centroidx = projx_cutg_b4f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f3 = banana_b4f3->ProjectionY("projy_cutg_b4f3",1,banana_b4f3->GetNbinsY(),"[cutg_b4f3]");              
    projy_cutg_b4f3->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb4f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f3_E = " <<  gainb4f3_E << " keV/ch" << endl;
    cout << " gainb4f3_dE = " << gainb4f3_dE << " keV/ch"<< endl;
    cout << endl;


    c5->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f4 186W(a,a') channel
    banana_b4f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f4->Draw();
    QKinz_f4_graph->Draw("p same");


    TCutG *cutg_b4f4 = new TCutG("cutg_b4f4",19);
    cutg_b4f4->SetVarX(" E detector 4 strip 4");
    cutg_b4f4->SetVarY("#DeltaE ");
    cutg_b4f4->SetTitle("Graph");
    cutg_b4f4->SetFillStyle(1000);
    cutg_b4f4->SetPoint(0,16383,3884.27);
   	cutg_b4f4->SetPoint(1,16247.1,4035.27);
   	cutg_b4f4->SetPoint(2,16061.3,4141.86);
   	cutg_b4f4->SetPoint(3,15866.5,4230.69);
   	cutg_b4f4->SetPoint(4,15685.2,4252.89);
   	cutg_b4f4->SetPoint(5,15531.2,4230.69);
   	cutg_b4f4->SetPoint(6,15449.6,4159.63);
   	cutg_b4f4->SetPoint(7,15427,4088.57);
   	cutg_b4f4->SetPoint(8,15427,3946.45);
   	cutg_b4f4->SetPoint(9,15513.1,3830.97);
   	cutg_b4f4->SetPoint(10,15630.9,3773.24);
   	cutg_b4f4->SetPoint(11,15703.4,3742.15);
   	cutg_b4f4->SetPoint(12,15816.6,3706.62);
   	cutg_b4f4->SetPoint(13,16025,3697.74);
   	cutg_b4f4->SetPoint(14,16238,3702.18);
   	cutg_b4f4->SetPoint(15,16301.4,3751.03);
   	cutg_b4f4->SetPoint(16,16355.8,3822.09);
   	cutg_b4f4->SetPoint(17,16378.4,3888.71);
   	cutg_b4f4->SetPoint(18,16383,3884.27);
    cutg_b4f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f4
    c5->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f4 = banana_b4f4->ProjectionX("projx_cutg_b4f4",1,banana_b4f4->GetNbinsX(),"[cutg_b4f4]");              
    projx_cutg_b4f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f4->GetMaximumBin(); 
    centroidx = projx_cutg_b4f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f4 = banana_b4f4->ProjectionY("projy_cutg_b4f4",1,banana_b4f4->GetNbinsY(),"[cutg_b4f4]");              
    projy_cutg_b4f4->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb4f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f4_E = " <<  gainb4f4_E << " keV/ch" << endl;
    cout << " gainb4f4_dE = " << gainb4f4_dE << " keV/ch"<< endl;
    cout << endl;


    c5->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f5 186(a,a') channel
    banana_b4f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b4f5 = new TCutG("cutg_b4f5",18);
    cutg_b4f5->SetVarX(" E detector 4 strip 5");
    cutg_b4f5->SetVarY("#DeltaE ");
    cutg_b4f5->SetTitle("Graph");
    cutg_b4f5->SetFillStyle(1000);
    cutg_b4f5->SetPoint(0,16364.5,4052.21);
   	cutg_b4f5->SetPoint(1,16235.5,4160.52);
   	cutg_b4f5->SetPoint(2,16050.4,4268.83);
   	cutg_b4f5->SetPoint(3,15887.7,4359.08);
   	cutg_b4f5->SetPoint(4,15668.9,4413.24);
   	cutg_b4f5->SetPoint(5,15500.6,4422.26);
   	cutg_b4f5->SetPoint(6,15382.8,4368.11);
   	cutg_b4f5->SetPoint(7,15354.8,4246.26);
   	cutg_b4f5->SetPoint(8,15354.8,4110.87);
   	cutg_b4f5->SetPoint(9,15422.1,4029.64);
   	cutg_b4f5->SetPoint(10,15579.2,3939.38);
   	cutg_b4f5->SetPoint(11,15820.4,3867.18);
   	cutg_b4f5->SetPoint(12,15943.8,3862.66);
   	cutg_b4f5->SetPoint(13,16190.6,3876.2);
   	cutg_b4f5->SetPoint(14,16291.6,3943.9);
   	cutg_b4f5->SetPoint(15,16364.5,4007.08);
   	cutg_b4f5->SetPoint(16,16358.9,4074.77);
   	cutg_b4f5->SetPoint(17,16364.5,4052.21);
    cutg_b4f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f5
    c5->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f5 = banana_b4f5->ProjectionX("projx_cutg_b4f5",1,banana_b4f5->GetNbinsX(),"[cutg_b4f5]");              
    projx_cutg_b4f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f5->GetMaximumBin(); 
    centroidx = projx_cutg_b4f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f5 = banana_b4f5->ProjectionY("projy_cutg_b4f5",1,banana_b4f5->GetNbinsY(),"[cutg_b4f5]");              
    projy_cutg_b4f5->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb4f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f5_E = " <<  gainb4f5_E << " keV/ch" << endl;
    cout << " gainb4f5_dE = " << gainb4f5_dE << " keV/ch"<< endl;
    cout << endl;

    c5->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f6 186W(a,a') channel
    banana_b4f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b4f6 = new TCutG("cutg_b4f6",19);
    cutg_b4f6->SetVarX(" E detector 4 strip 6");
    cutg_b4f6->SetVarY("#DeltaE ");
    cutg_b4f6->SetTitle("Graph");
    cutg_b4f6->SetFillStyle(1000);
    cutg_b4f6->SetPoint(0,16336.4,4040);
   	cutg_b4f6->SetPoint(1,16166.5,4206.33);
   	cutg_b4f6->SetPoint(2,16016,4295.3);
   	cutg_b4f6->SetPoint(3,15758.7,4419.08);
   	cutg_b4f6->SetPoint(4,15588.8,4422.95);
   	cutg_b4f6->SetPoint(5,15423.8,4415.21);
   	cutg_b4f6->SetPoint(6,15341.3,4310.77);
   	cutg_b4f6->SetPoint(7,15341.3,4221.81);
   	cutg_b4f6->SetPoint(8,15355.8,4113.5);
   	cutg_b4f6->SetPoint(9,15496.6,4016.79);
   	cutg_b4f6->SetPoint(10,15681.1,3900.74);
   	cutg_b4f6->SetPoint(11,15865.5,3842.72);
   	cutg_b4f6->SetPoint(12,16045.1,3819.51);
   	cutg_b4f6->SetPoint(13,16185.9,3811.78);
   	cutg_b4f6->SetPoint(14,16317,3838.85);
   	cutg_b4f6->SetPoint(15,16365.5,3904.61);
   	cutg_b4f6->SetPoint(16,16365.5,3993.58);
   	cutg_b4f6->SetPoint(17,16326.7,4051.6);
   	cutg_b4f6->SetPoint(18,16336.4,4040);
    cutg_b4f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b4f6
    c5->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f6 = banana_b4f6->ProjectionX("projx_cutg_b4f6",1,banana_b4f6->GetNbinsX(),"[cutg_b4f6]");              
    projx_cutg_b4f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f6->GetMaximumBin(); 
    centroidx = projx_cutg_b4f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f6 = banana_b4f6->ProjectionY("projy_cutg_b4f6",1,banana_b4f6->GetNbinsY(),"[cutg_b4f6]");              
    projy_cutg_b4f6->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb4f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f6_E = " <<  gainb4f6_E << " keV/ch" << endl;
    cout << " gainb4f6_dE = " << gainb4f6_dE << " keV/ch"<< endl;
    cout << endl;


    c5->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f7 186W(a,a') channel
    banana_b4f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b4f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b4f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b4f7 = new TCutG("cutg_b4f7",19);
    cutg_b4f7->SetVarX(" E detector 4 strip 7");
    cutg_b4f7->SetVarY("#DeltaE ");
    cutg_b4f7->SetTitle("Graph");
    cutg_b4f7->SetFillStyle(1000);
    cutg_b4f7->SetPoint(0,16280.1,4213.75);
   	cutg_b4f7->SetPoint(1,16139.8,4344.41);
   	cutg_b4f7->SetPoint(2,15982.8,4433.81);
   	cutg_b4f7->SetPoint(3,15685.5,4543.84);
   	cutg_b4f7->SetPoint(4,15517.2,4557.59);
   	cutg_b4f7->SetPoint(5,15354.5,4557.59);
   	cutg_b4f7->SetPoint(6,15264.8,4444.13);
   	cutg_b4f7->SetPoint(7,15281.6,4323.78);
   	cutg_b4f7->SetPoint(8,15354.5,4237.82);
   	cutg_b4f7->SetPoint(9,15427.4,4162.18);
   	cutg_b4f7->SetPoint(10,15612.6,4059.03);
   	cutg_b4f7->SetPoint(11,15775.2,4004.01);
   	cutg_b4f7->SetPoint(12,16016.4,3942.12);
   	cutg_b4f7->SetPoint(13,16173.5,3945.56);
   	cutg_b4f7->SetPoint(14,16341.8,3973.07);
   	cutg_b4f7->SetPoint(15,16403.5,4021.2);
   	cutg_b4f7->SetPoint(16,16364.2,4151.86);
   	cutg_b4f7->SetPoint(17,16274.5,4230.95);
   	cutg_b4f7->SetPoint(18,16280.1,4213.75);
    cutg_b4f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f7
    c5->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f7 = banana_b4f7->ProjectionX("projx_cutg_b4f7",1,banana_b4f7->GetNbinsX(),"[cutg_b4f7]");              
    projx_cutg_b4f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b4f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b4f7->GetMaximumBin(); 
    centroidx = projx_cutg_b4f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f7 = banana_b4f7->ProjectionY("projy_cutg_b4f7",1,banana_b4f7->GetNbinsY(),"[cutg_b4f7]");              
    projy_cutg_b4f7->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b4f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb4f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb4f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb4f7_E = " <<  gainb4f7_E << " keV/ch" << endl;
    cout << " gainb4f7_dE = " << gainb4f7_dE << " keV/ch"<< endl;
    cout << endl;
 
    ///////////////////
    // E DETECTOR b5 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c6 = new TCanvas("c6","c6:b5 bananas",1400,800);
    c6->Divide(8,3,0,0);
    c6->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b5f0 186W(a,a') channel
    banana_b5f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b5f0 = new TCutG("cutg_b5f0",17);
    cutg_b5f0->SetVarX(" E detector 5 strip 0");
    cutg_b5f0->SetVarY("#DeltaE ");
    cutg_b5f0->SetTitle("Graph");
    cutg_b5f0->SetFillStyle(1000);
    cutg_b5f0->SetPoint(0,16194.4,4156.42);
   	cutg_b5f0->SetPoint(1,16081.1,4256.7);
   	cutg_b5f0->SetPoint(2,15936.1,4371.32);
   	cutg_b5f0->SetPoint(3,15736.8,4435.79);
   	cutg_b5f0->SetPoint(4,15528.3,4446.53);
   	cutg_b5f0->SetPoint(5,15324.5,4439.37);
   	cutg_b5f0->SetPoint(6,15265.6,4346.25);
   	cutg_b5f0->SetPoint(7,15292.8,4185.07);
   	cutg_b5f0->SetPoint(8,15369.8,4088.37);
   	cutg_b5f0->SetPoint(9,15623.5,3995.24);
   	cutg_b5f0->SetPoint(10,15800.2,3945.1);
   	cutg_b5f0->SetPoint(11,16026.7,3923.61);
   	cutg_b5f0->SetPoint(12,16158.1,3930.77);
   	cutg_b5f0->SetPoint(13,16198.9,3995.24);
   	cutg_b5f0->SetPoint(14,16198.9,4081.2);
   	cutg_b5f0->SetPoint(15,16185.3,4163.58);
   	cutg_b5f0->SetPoint(16,16194.4,4156.42);
    cutg_b5f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f0
    c6->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f0 = banana_b5f0->ProjectionX("projx_cutg_b5f0",1,banana_b5f0->GetNbinsX(),"[cutg_b5f0]");              
    projx_cutg_b5f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f0->GetMaximumBin(); 
    centroidx = projx_cutg_b5f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f0 = banana_b5f0->ProjectionY("projy_cutg_b5f0",1,banana_b5f0->GetNbinsY(),"[cutg_b5f0]");              
    projy_cutg_b5f0->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb5f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f0_E = " <<  gainb5f0_E << " keV/ch" << endl;
    cout << " gainb5f0_dE = " << gainb5f0_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f1 186W(a,a') channel
    banana_b5f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f1->Draw();
    QKinz_f1_graph->Draw("p same");
   
    TCutG *cutg_b5f1 = new TCutG("cutg_b5f1",19);
    cutg_b5f1->SetVarX(" E detector 5 strip 1");
    cutg_b5f1->SetVarY("#DeltaE ");
    cutg_b5f1->SetTitle("Graph");
    cutg_b5f1->SetFillStyle(1000);
    cutg_b5f1->SetPoint(0,16204.9,4085.67);
   	cutg_b5f1->SetPoint(1,16068.9,4214.18);
   	cutg_b5f1->SetPoint(2,15887.7,4306.45);
   	cutg_b5f1->SetPoint(3,15733.7,4372.35);
   	cutg_b5f1->SetPoint(4,15538.8,4395.42);
   	cutg_b5f1->SetPoint(5,15407.4,4378.94);
   	cutg_b5f1->SetPoint(6,15257.9,4345.99);
   	cutg_b5f1->SetPoint(7,15235.3,4253.72);
   	cutg_b5f1->SetPoint(8,15235.3,4144.99);
   	cutg_b5f1->SetPoint(9,15276.1,4052.72);
   	cutg_b5f1->SetPoint(10,15416.5,3953.87);
   	cutg_b5f1->SetPoint(11,15588.7,3894.56);
   	cutg_b5f1->SetPoint(12,15896.8,3831.95);
   	cutg_b5f1->SetPoint(13,16050.8,3838.54);
   	cutg_b5f1->SetPoint(14,16209.4,3881.38);
   	cutg_b5f1->SetPoint(15,16241.1,3993.41);
   	cutg_b5f1->SetPoint(16,16227.5,4056.02);
   	cutg_b5f1->SetPoint(17,16182.2,4108.74);
   	cutg_b5f1->SetPoint(18,16204.9,4085.67);
    cutg_b5f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f1
    c6->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f1 = banana_b5f1->ProjectionX("projx_cutg_b5f1",1,banana_b5f1->GetNbinsX(),"[cutg_b5f1]");              
    projx_cutg_b5f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f1->GetMaximumBin(); 
    centroidx = projx_cutg_b5f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f1 = banana_b5f1->ProjectionY("projy_cutg_b5f1",1,banana_b5f1->GetNbinsY(),"[cutg_b5f1]");              
    projy_cutg_b5f1->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb5f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f1_E = " <<  gainb5f1_E << " keV/ch" << endl;
    cout << " gainb5f1_dE = " << gainb5f1_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f2 186W(a,a') channel
    banana_b5f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b5f2 = new TCutG("cutg_b5f2",18);
    cutg_b5f2->SetVarX(" E detector 5 strip 2");
    cutg_b5f2->SetVarY("#DeltaE ");
    cutg_b5f2->SetTitle("Graph");
    cutg_b5f2->SetFillStyle(1000);
    cutg_b5f2->SetPoint(0,16324,4120.34);
   	cutg_b5f2->SetPoint(1,16167.6,4236.68);
   	cutg_b5f2->SetPoint(2,16029.9,4340.97);
   	cutg_b5f2->SetPoint(3,15867.2,4393.12);
   	cutg_b5f2->SetPoint(4,15648.3,4437.25);
   	cutg_b5f2->SetPoint(5,15416.8,4473.35);
   	cutg_b5f2->SetPoint(6,15304.1,4421.2);
   	cutg_b5f2->SetPoint(7,15304.1,4304.87);
   	cutg_b5f2->SetPoint(8,15354.2,4144.41);
   	cutg_b5f2->SetPoint(9,15498.1,4048.14);
   	cutg_b5f2->SetPoint(10,15754.6,3935.82);
   	cutg_b5f2->SetPoint(11,15911,3915.76);
   	cutg_b5f2->SetPoint(12,16148.8,3867.62);
   	cutg_b5f2->SetPoint(13,16261.4,3923.78);
   	cutg_b5f2->SetPoint(14,16349,3987.97);
   	cutg_b5f2->SetPoint(15,16336.5,4084.24);
   	cutg_b5f2->SetPoint(16,16311.5,4132.38);
   	cutg_b5f2->SetPoint(17,16324,4120.34);
    cutg_b5f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f2
    c6->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f2 = banana_b5f2->ProjectionX("projx_cutg_b5f2",1,banana_b5f2->GetNbinsX(),"[cutg_b5f2]");              
    projx_cutg_b5f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f2->GetMaximumBin(); 
    centroidx = projx_cutg_b5f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f2 = banana_b5f2->ProjectionY("projy_cutg_b5f2",1,banana_b5f2->GetNbinsY(),"[cutg_b5f2]");              
    projy_cutg_b5f2->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb5f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f2_E = " <<  gainb5f2_E << " keV/ch" << endl;
    cout << " gainb5f2_dE = " << gainb5f2_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f3 186W(a,a') elastic peak
    banana_b5f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b5f3 = new TCutG("cutg_b5f3",18);
    cutg_b5f3->SetVarX(" E detector 5 strip 3");
    cutg_b5f3->SetVarY("#DeltaE ");
    cutg_b5f3->SetTitle("Graph");
    cutg_b5f3->SetFillStyle(1000);
    cutg_b5f3->SetPoint(0,16379.9,4030.89);
   	cutg_b5f3->SetPoint(1,16217.2,4190.77);
   	cutg_b5f3->SetPoint(2,16006.9,4330.03);
   	cutg_b5f3->SetPoint(3,15833,4389.34);
   	cutg_b5f3->SetPoint(4,15566.5,4446.07);
   	cutg_b5f3->SetPoint(5,15403.9,4402.23);
   	cutg_b5f3->SetPoint(6,15283.3,4342.92);
   	cutg_b5f3->SetPoint(7,15277.6,4219.14);
   	cutg_b5f3->SetPoint(8,15350.6,4066.99);
   	cutg_b5f3->SetPoint(9,15636.7,3891.63);
   	cutg_b5f3->SetPoint(10,15875.1,3811.69);
   	cutg_b5f3->SetPoint(11,16051.8,3783.32);
   	cutg_b5f3->SetPoint(12,16225.7,3731.75);
   	cutg_b5f3->SetPoint(13,16326.6,3749.8);
   	cutg_b5f3->SetPoint(14,16382.7,3852.95);
   	cutg_b5f3->SetPoint(15,16371.5,3953.52);
   	cutg_b5f3->SetPoint(16,16374.3,4036.05);
   	cutg_b5f3->SetPoint(17,16379.9,4030.89);
    cutg_b5f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f3
    c6->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f3 = banana_b5f3->ProjectionX("projx_cutg_b5f3",1,banana_b5f3->GetNbinsX(),"[cutg_b5f3]");              
    projx_cutg_b5f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f3->GetMaximumBin(); 
    centroidx = projx_cutg_b5f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f3 = banana_b5f3->ProjectionY("projy_cutg_b5f3",1,banana_b5f3->GetNbinsY(),"[cutg_b5f3]");              
    projy_cutg_b5f3->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb5f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f3_E = " <<  gainb5f3_E << " keV/ch" << endl;
    cout << " gainb5f3_dE = " << gainb5f3_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f4 186(a,a') channel
    banana_b5f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b5f4 = new TCutG("cutg_b5f4",20);
    cutg_b5f4->SetVarX(" E detector 5 strip 4");
    cutg_b5f4->SetVarY("#DeltaE ");
    cutg_b5f4->SetTitle("Graph");
    cutg_b5f4->SetFillStyle(1000);
    cutg_b5f4->SetPoint(0,16367.1,4267.18);
   	cutg_b5f4->SetPoint(1,16292,4377.49);
   	cutg_b5f4->SetPoint(2,16084.9,4485.3);
   	cutg_b5f4->SetPoint(3,15952.9,4573.05);
   	cutg_b5f4->SetPoint(4,15748.3,4668.32);
   	cutg_b5f4->SetPoint(5,15572.3,4670.83);
   	cutg_b5f4->SetPoint(6,15463.6,4653.28);
   	cutg_b5f4->SetPoint(7,15424.7,4618.18);
   	cutg_b5f4->SetPoint(8,15354.8,4515.39);
   	cutg_b5f4->SetPoint(9,15357.4,4382.51);
   	cutg_b5f4->SetPoint(10,15404,4287.23);
   	cutg_b5f4->SetPoint(11,15644.8,4154.36);
   	cutg_b5f4->SetPoint(12,15952.9,4008.94);
   	cutg_b5f4->SetPoint(13,16157.4,3983.87);
   	cutg_b5f4->SetPoint(14,16305,3971.33);
   	cutg_b5f4->SetPoint(15,16369.7,4039.03);
   	cutg_b5f4->SetPoint(16,16408.5,4129.28);
   	cutg_b5f4->SetPoint(17,16390.4,4207.01);
   	cutg_b5f4->SetPoint(18,16361.9,4279.71);
   	cutg_b5f4->SetPoint(19,16367.1,4267.18);
    cutg_b5f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f4
    c6->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f4 = banana_b5f4->ProjectionX("projx_cutg_b5f4",1,banana_b5f4->GetNbinsX(),"[cutg_b5f4]");              
    projx_cutg_b5f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f4->GetMaximumBin(); 
    centroidx = projx_cutg_b5f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f4 = banana_b5f4->ProjectionY("projy_cutg_b5f4",1,banana_b5f4->GetNbinsY(),"[cutg_b5f4]");              
    projy_cutg_b5f4->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb5f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f4_E = " <<  gainb5f4_E << " keV/ch" << endl;
    cout << " gainb5f4_dE = " << gainb5f4_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f5 186W(a,a') channel
    banana_b5f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b5f5 = new TCutG("cutg_b5f5",19);
    cutg_b5f5->SetVarX(" E detector 5 strip 5");
    cutg_b5f5->SetVarY("#DeltaE ");
    cutg_b5f5->SetTitle("Graph");
    cutg_b5f5->SetFillStyle(1000);
    cutg_b5f5->SetPoint(0,16420.7,4095.79);
   	cutg_b5f5->SetPoint(1,16280.5,4223.65);
   	cutg_b5f5->SetPoint(2,16113.3,4336.91);
   	cutg_b5f5->SetPoint(3,15924.5,4439.2);
   	cutg_b5f5->SetPoint(4,15719.5,4515.92);
   	cutg_b5f5->SetPoint(5,15546.9,4526.88);
   	cutg_b5f5->SetPoint(6,15406.7,4523.22);
   	cutg_b5f5->SetPoint(7,15336.6,4450.16);
   	cutg_b5f5->SetPoint(8,15336.6,4377.09);
   	cutg_b5f5->SetPoint(9,15336.6,4238.27);
   	cutg_b5f5->SetPoint(10,15471.4,4125.01);
   	cutg_b5f5->SetPoint(11,15671,4044.64);
   	cutg_b5f5->SetPoint(12,15843.6,3989.84);
   	cutg_b5f5->SetPoint(13,16086.3,3924.08);
   	cutg_b5f5->SetPoint(14,16269.7,3942.35);
   	cutg_b5f5->SetPoint(15,16383,3956.96);
   	cutg_b5f5->SetPoint(16,16415.3,4019.07);
   	cutg_b5f5->SetPoint(17,16420.7,4095.79);
   	cutg_b5f5->SetPoint(18,16420.7,4095.79);
    cutg_b5f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f5
    c6->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f5 = banana_b5f5->ProjectionX("projx_cutg_b5f5",1,banana_b5f5->GetNbinsX(),"[cutg_b5f5]");              
    projx_cutg_b5f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f5->GetMaximumBin(); 
    centroidx = projx_cutg_b5f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f5 = banana_b5f5->ProjectionY("projy_cutg_b5f5",1,banana_b5f5->GetNbinsY(),"[cutg_b5f5]");              
    projy_cutg_b5f5->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb5f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f5_E = " <<  gainb5f5_E << " keV/ch" << endl;
    cout << " gainb5f5_dE = " << gainb5f5_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f6 186W(a,a') channel
    banana_b5f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b5f6 = new TCutG("cutg_b5f6",16);
    cutg_b5f6->SetVarX(" E detector 5 strip 6");
    cutg_b5f6->SetVarY("#DeltaE ");
    cutg_b5f6->SetTitle("Graph");
    cutg_b5f6->SetFillStyle(1000);
    cutg_b5f6->SetPoint(0,16361.9,4109.66);
   	cutg_b5f6->SetPoint(1,16210.4,4255.07);
   	cutg_b5f6->SetPoint(2,16092.6,4367.25);
   	cutg_b5f6->SetPoint(3,15831.8,4471.12);
   	cutg_b5f6->SetPoint(4,15621.4,4558.37);
   	cutg_b5f6->SetPoint(5,15419.5,4558.37);
   	cutg_b5f6->SetPoint(6,15234.4,4404.64);
   	cutg_b5f6->SetPoint(7,15251.2,4309.08);
   	cutg_b5f6->SetPoint(8,15385.8,4180.29);
   	cutg_b5f6->SetPoint(9,15613,4055.64);
   	cutg_b5f6->SetPoint(10,15865.4,3951.78);
   	cutg_b5f6->SetPoint(11,16159.9,3935.16);
   	cutg_b5f6->SetPoint(12,16412.4,3976.7);
   	cutg_b5f6->SetPoint(13,16429.2,4047.34);
   	cutg_b5f6->SetPoint(14,16361.9,4126.28);
   	cutg_b5f6->SetPoint(15,16361.9,4109.66);
    cutg_b5f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b5f6
    c6->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f6 = banana_b5f6->ProjectionX("projx_cutg_b5f6",1,banana_b5f6->GetNbinsX(),"[cutg_b5f6]");              
    projx_cutg_b5f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f6->GetMaximumBin(); 
    centroidx = projx_cutg_b5f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f6 = banana_b5f6->ProjectionY("projy_cutg_b5f6",1,banana_b5f6->GetNbinsY(),"[cutg_b5f6]");              
    projy_cutg_b5f6->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb5f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f6_E = " <<  gainb5f6_E << " keV/ch" << endl;
    cout << " gainb5f6_dE = " << gainb5f6_dE << " keV/ch"<< endl;
    cout << endl;

    c6->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f7 186W(a,a') channel
    banana_b5f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b5f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b5f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b5f7 = new TCutG("cutg_b5f7",20);
    cutg_b5f7->SetVarX(" E detector 5 strip 7");
    cutg_b5f7->SetVarY("#DeltaE ");
    cutg_b5f7->SetTitle("Graph");
    cutg_b5f7->SetFillStyle(1000);
    cutg_b5f7->SetPoint(0,16276.4,3939.91);
   	cutg_b5f7->SetPoint(1,16058,4063.12);
   	cutg_b5f7->SetPoint(2,15872.9,4164.77);
   	cutg_b5f7->SetPoint(3,15668.8,4266.42);
   	cutg_b5f7->SetPoint(4,15398.3,4291.06);
   	cutg_b5f7->SetPoint(5,15217.9,4275.66);
   	cutg_b5f7->SetPoint(6,15142,4232.54);
   	cutg_b5f7->SetPoint(7,15123,4133.97);
   	cutg_b5f7->SetPoint(8,15208.4,4038.48);
   	cutg_b5f7->SetPoint(9,15331.8,3967.64);
   	cutg_b5f7->SetPoint(10,15483.7,3872.15);
   	cutg_b5f7->SetPoint(11,15664.1,3813.62);
   	cutg_b5f7->SetPoint(12,15934.6,3745.86);
   	cutg_b5f7->SetPoint(13,16153,3724.3);
   	cutg_b5f7->SetPoint(14,16304.9,3730.46);
   	cutg_b5f7->SetPoint(15,16357.1,3795.14);
   	cutg_b5f7->SetPoint(16,16366.6,3869.07);
   	cutg_b5f7->SetPoint(17,16300.1,3921.43);
   	cutg_b5f7->SetPoint(18,16257.4,3946.07);
   	cutg_b5f7->SetPoint(19,16276.4,3939.91);
    cutg_b5f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f7
    c6->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f7 = banana_b5f7->ProjectionX("projx_cutg_b5f7",1,banana_b5f7->GetNbinsX(),"[cutg_b5f7]");              
    projx_cutg_b5f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b5f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b5f7->GetMaximumBin(); 
    centroidx = projx_cutg_b5f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f7 = banana_b5f7->ProjectionY("projy_cutg_b5f7",1,banana_b5f7->GetNbinsY(),"[cutg_b5f7]");              
    projy_cutg_b5f7->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b5f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb5f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb5f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb5f7_E = " <<  gainb5f7_E << " keV/ch" << endl;
    cout << " gainb5f7_dE = " << gainb5f7_dE << " keV/ch"<< endl;
    cout << endl;


    ///////////////////
    // E DETECTOR b6 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c7 = new TCanvas("c7","c7:b6 bananas",1400,800);
    c7->Divide(8,3,0,0);
    c7->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f0 186W(a,a') channel
    banana_b6f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b6f0 = new TCutG("cutg_b6f0",16);
    cutg_b6f0->SetVarX(" E detector 6 strip 0");
    cutg_b6f0->SetVarY("#DeltaE ");
    cutg_b6f0->SetTitle("Graph");
    cutg_b6f0->SetFillStyle(1000);
    cutg_b6f0->SetPoint(0,16418,3709.86);
   	cutg_b6f0->SetPoint(1,16266.2,3849.54);
   	cutg_b6f0->SetPoint(2,16042.1,3964.15);
   	cutg_b6f0->SetPoint(3,15839.8,3999.97);
   	cutg_b6f0->SetPoint(4,15594,4014.3);
   	cutg_b6f0->SetPoint(5,15485.6,4014.3);
   	cutg_b6f0->SetPoint(6,15413.3,3931.92);
   	cutg_b6f0->SetPoint(7,15449.5,3792.23);
   	cutg_b6f0->SetPoint(8,15543.4,3699.11);
   	cutg_b6f0->SetPoint(9,15760.2,3638.22);
   	cutg_b6f0->SetPoint(10,16013.2,3573.75);
   	cutg_b6f0->SetPoint(11,16193.9,3548.68);
   	cutg_b6f0->SetPoint(12,16331.2,3563.01);
   	cutg_b6f0->SetPoint(13,16410.7,3613.15);
   	cutg_b6f0->SetPoint(14,16410.7,3734.93);
   	cutg_b6f0->SetPoint(15,16418,3709.86);
    cutg_b6f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f0
    c7->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f0 = banana_b6f0->ProjectionX("projx_cutg_b6f0",1,banana_b6f0->GetNbinsX(),"[cutg_b6f0]");              
    projx_cutg_b6f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f0->GetMaximumBin(); 
    centroidx = projx_cutg_b6f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f0 = banana_b6f0->ProjectionY("projy_cutg_b6f0",1,banana_b6f0->GetNbinsY(),"[cutg_b6f0]");              
    projy_cutg_b6f0->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb6f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f0_E = " <<  gainb6f0_E << " keV/ch" << endl;
    cout << " gainb6f0_dE = " << gainb6f0_dE << " keV/ch"<< endl;
    cout << endl;

    c7->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f1 186W(a,a') elastic peak
    banana_b6f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f1->Draw();
    QKinz_f1_graph->Draw("p same");
   
    TCutG *cutg_b6f1 = new TCutG("cutg_b6f1",20);
    cutg_b6f1->SetVarX(" E detector 6 strip 1");
    cutg_b6f1->SetVarY("#DeltaE ");
    cutg_b6f1->SetTitle("Graph");
    cutg_b6f1->SetFillStyle(1000);
    cutg_b6f1->SetPoint(0,16409.1,3920);
   	cutg_b6f1->SetPoint(1,16314.7,3979.89);
   	cutg_b6f1->SetPoint(2,16224,4083.32);
   	cutg_b6f1->SetPoint(3,16099.4,4148.65);
   	cutg_b6f1->SetPoint(4,15929.5,4222.15);
   	cutg_b6f1->SetPoint(5,15669,4279.31);
   	cutg_b6f1->SetPoint(6,15487.8,4257.54);
   	cutg_b6f1->SetPoint(7,15431.2,4170.43);
   	cutg_b6f1->SetPoint(8,15446.3,4075.16);
   	cutg_b6f1->SetPoint(9,15487.8,3960.83);
   	cutg_b6f1->SetPoint(10,15597.3,3873.72);
   	cutg_b6f1->SetPoint(11,15789.8,3794.79);
   	cutg_b6f1->SetPoint(12,15952.2,3718.57);
   	cutg_b6f1->SetPoint(13,16186.3,3666.85);
   	cutg_b6f1->SetPoint(14,16329.8,3675.01);
   	cutg_b6f1->SetPoint(15,16439.3,3718.57);
   	cutg_b6f1->SetPoint(16,16473.2,3819.28);
   	cutg_b6f1->SetPoint(17,16431.7,3892.78);
   	cutg_b6f1->SetPoint(18,16397.7,3930.89);
   	cutg_b6f1->SetPoint(19,16409.1,3920);
    cutg_b6f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f1
    c7->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f1 = banana_b6f1->ProjectionX("projx_cutg_b6f1",1,banana_b6f1->GetNbinsX(),"[cutg_b6f1]");              
    projx_cutg_b6f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f1->GetMaximumBin(); 
    centroidx = projx_cutg_b6f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f1 = banana_b6f1->ProjectionY("projy_cutg_b6f1",1,banana_b6f1->GetNbinsY(),"[cutg_b6f1]");              
    projy_cutg_b6f1->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb6f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f1_E = " <<  gainb6f1_E << " keV/ch" << endl;
    cout << " gainb6f1_dE = " << gainb6f1_dE << " keV/ch"<< endl;
    cout << endl;


    c7->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f2 186W(a,a') channel
    banana_b6f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b6f2 = new TCutG("cutg_b6f2",18);
    cutg_b6f2->SetVarX(" E detector 6 strip 2");
    cutg_b6f2->SetVarY("#DeltaE ");
    cutg_b6f2->SetTitle("Graph");
    cutg_b6f2->SetFillStyle(1000);
    cutg_b6f2->SetPoint(0,16507.2,3912.06);
   	cutg_b6f2->SetPoint(1,16413.2,4009.84);
   	cutg_b6f2->SetPoint(2,16239.8,4121.59);
   	cutg_b6f2->SetPoint(3,16008.5,4247.31);
   	cutg_b6f2->SetPoint(4,15806.1,4303.18);
   	cutg_b6f2->SetPoint(5,15596.5,4345.09);
   	cutg_b6f2->SetPoint(6,15408.6,4303.18);
   	cutg_b6f2->SetPoint(7,15386.9,4140.21);
   	cutg_b6f2->SetPoint(8,15495.3,3991.22);
   	cutg_b6f2->SetPoint(9,15639.9,3921.38);
   	cutg_b6f2->SetPoint(10,15885.6,3823.6);
   	cutg_b6f2->SetPoint(11,16044.6,3786.35);
   	cutg_b6f2->SetPoint(12,16203.6,3763.07);
   	cutg_b6f2->SetPoint(13,16355.4,3786.35);
   	cutg_b6f2->SetPoint(14,16492.7,3828.25);
   	cutg_b6f2->SetPoint(15,16499.9,3874.81);
   	cutg_b6f2->SetPoint(16,16485.5,3949.31);
   	cutg_b6f2->SetPoint(17,16507.2,3912.06);
    cutg_b6f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f2
    c7->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f2 = banana_b6f2->ProjectionX("projx_cutg_b6f2",1,banana_b6f2->GetNbinsX(),"[cutg_b6f2]");              
    projx_cutg_b6f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f2->GetMaximumBin(); 
    centroidx = projx_cutg_b6f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f2 = banana_b6f2->ProjectionY("projy_cutg_b6f2",1,banana_b6f2->GetNbinsY(),"[cutg_b6f2]");              
    projy_cutg_b6f2->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb6f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f2_E = " <<  gainb6f2_E << " keV/ch" << endl;
    cout << " gainb6f2_dE = " << gainb6f2_dE << " keV/ch"<< endl;
    cout << endl;


    c7->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f3 186W(a,a') channel
    banana_b6f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b6f3 = new TCutG("cutg_b6f3",21);
    cutg_b6f3->SetVarX(" E detector 6 strip 3");
    cutg_b6f3->SetVarY("#DeltaE ");
    cutg_b6f3->SetTitle("Graph");
    cutg_b6f3->SetFillStyle(1000);
    cutg_b6f3->SetPoint(0,16555.3,3822.12);
   	cutg_b6f3->SetPoint(1,16482.8,3895.83);
   	cutg_b6f3->SetPoint(2,16353.4,3980.07);
   	cutg_b6f3->SetPoint(3,16208.4,4039.74);
   	cutg_b6f3->SetPoint(4,16042.7,4095.9);
   	cutg_b6f3->SetPoint(5,15887.4,4116.96);
   	cutg_b6f3->SetPoint(6,15726.9,4127.49);
   	cutg_b6f3->SetPoint(7,15581.9,4095.9);
   	cutg_b6f3->SetPoint(8,15561.2,3983.58);
   	cutg_b6f3->SetPoint(9,15576.7,3892.32);
   	cutg_b6f3->SetPoint(10,15654.4,3794.04);
   	cutg_b6f3->SetPoint(11,15804.5,3730.86);
   	cutg_b6f3->SetPoint(12,15975.4,3660.66);
   	cutg_b6f3->SetPoint(13,16125.6,3604.5);
   	cutg_b6f3->SetPoint(14,16275.7,3597.48);
   	cutg_b6f3->SetPoint(15,16451.8,3608.01);
   	cutg_b6f3->SetPoint(16,16508.7,3643.11);
   	cutg_b6f3->SetPoint(17,16560.5,3720.33);
   	cutg_b6f3->SetPoint(18,16565.7,3783.51);
   	cutg_b6f3->SetPoint(19,16555.3,3832.65);
   	cutg_b6f3->SetPoint(20,16555.3,3822.12);
    cutg_b6f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f3
    c7->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f3 = banana_b6f3->ProjectionX("projx_cutg_b6f3",1,banana_b6f3->GetNbinsX(),"[cutg_b6f3]");              
    projx_cutg_b6f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f3->GetMaximumBin(); 
    centroidx = projx_cutg_b6f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f3 = banana_b6f3->ProjectionY("projy_cutg_b6f3",1,banana_b6f3->GetNbinsY(),"[cutg_b6f3]");              
    projy_cutg_b6f3->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb6f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f3_E = " <<  gainb6f3_E << " keV/ch" << endl;
    cout << " gainb6f3_dE = " << gainb6f3_dE << " keV/ch"<< endl;
    cout << endl;


    c7->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f4 186W(a,a') channel
    banana_b6f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b6f4 = new TCutG("cutg_b6f4",20);
    cutg_b6f4->SetVarX(" E detector 6 strip 4");
    cutg_b6f4->SetVarY("#DeltaE ");
    cutg_b6f4->SetTitle("Graph");
    cutg_b6f4->SetFillStyle(1000);
    cutg_b6f4->SetPoint(0,16540.3,3976.92);
   	cutg_b6f4->SetPoint(1,16460.2,4047.77);
   	cutg_b6f4->SetPoint(2,16368.7,4121.69);
   	cutg_b6f4->SetPoint(3,16202.9,4211.02);
   	cutg_b6f4->SetPoint(4,16020,4260.3);
   	cutg_b6f4->SetPoint(5,15825.6,4294.18);
   	cutg_b6f4->SetPoint(6,15636.9,4291.1);
   	cutg_b6f4->SetPoint(7,15511.1,4204.86);
   	cutg_b6f4->SetPoint(8,15528.3,4093.97);
   	cutg_b6f4->SetPoint(9,15614.1,3998.48);
   	cutg_b6f4->SetPoint(10,15797,3896.83);
   	cutg_b6f4->SetPoint(11,15980,3816.75);
   	cutg_b6f4->SetPoint(12,16208.7,3761.3);
   	cutg_b6f4->SetPoint(13,16420.2,3730.5);
   	cutg_b6f4->SetPoint(14,16586,3764.38);
   	cutg_b6f4->SetPoint(15,16637.5,3850.63);
   	cutg_b6f4->SetPoint(16,16603.2,3918.4);
   	cutg_b6f4->SetPoint(17,16528.8,3989.24);
   	cutg_b6f4->SetPoint(18,16528.8,3989.24);
   	cutg_b6f4->SetPoint(19,16540.3,3976.92);
    cutg_b6f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f4
    c7->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f4 = banana_b6f4->ProjectionX("projx_cutg_b6f4",1,banana_b6f4->GetNbinsX(),"[cutg_b6f4]");              
    projx_cutg_b6f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f4->GetMaximumBin(); 
    centroidx = projx_cutg_b6f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f4 = banana_b6f4->ProjectionY("projy_cutg_b6f4",1,banana_b6f4->GetNbinsY(),"[cutg_b6f4]");              
    projy_cutg_b6f4->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb6f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f4_E = " <<  gainb6f4_E << " keV/ch" << endl;
    cout << " gainb6f4_dE = " << gainb6f4_dE << " keV/ch"<< endl;
    cout << endl;
  
    c7->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f5 186W(a,a') channel
    banana_b6f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b6f5 = new TCutG("cutg_b6f5",17);
    cutg_b6f5->SetVarX(" E detector 6 strip 5");
    cutg_b6f5->SetVarY("#DeltaE ");
    cutg_b6f5->SetTitle("Graph");
    cutg_b6f5->SetFillStyle(1000);
    cutg_b6f5->SetPoint(0,16612.4,3964.1);
   	cutg_b6f5->SetPoint(1,16508.8,4056.86);
   	cutg_b6f5->SetPoint(2,16282.3,4202.64);
   	cutg_b6f5->SetPoint(3,16055.7,4332.51);
   	cutg_b6f5->SetPoint(4,15842.1,4372.26);
   	cutg_b6f5->SetPoint(5,15599.4,4351.06);
   	cutg_b6f5->SetPoint(6,15515.3,4213.24);
   	cutg_b6f5->SetPoint(7,15547.6,4083.37);
   	cutg_b6f5->SetPoint(8,15631.8,3950.85);
   	cutg_b6f5->SetPoint(9,15793.6,3879.28);
   	cutg_b6f5->SetPoint(10,16110.7,3752.06);
   	cutg_b6f5->SetPoint(11,16337.3,3661.95);
   	cutg_b6f5->SetPoint(12,16515.3,3712.31);
   	cutg_b6f5->SetPoint(13,16648,3781.22);
   	cutg_b6f5->SetPoint(14,16622.1,3903.14);
   	cutg_b6f5->SetPoint(15,16596.2,3982.65);
   	cutg_b6f5->SetPoint(16,16612.4,3964.1);
    cutg_b6f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f5
    c7->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f5 = banana_b6f5->ProjectionX("projx_cutg_b6f5",1,banana_b6f5->GetNbinsX(),"[cutg_b6f5]");              
    projx_cutg_b6f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f5->GetMaximumBin(); 
    centroidx = projx_cutg_b6f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f5 = banana_b6f5->ProjectionY("projy_cutg_b6f5",1,banana_b6f5->GetNbinsY(),"[cutg_b6f5]");              
    projy_cutg_b6f5->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb6f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f5_E = " <<  gainb6f5_E << " keV/ch" << endl;
    cout << " gainb6f5_dE = " << gainb6f5_dE << " keV/ch"<< endl;
    cout << endl;


    c7->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f6 186W(a,a') channel
    banana_b6f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b6f6 = new TCutG("cutg_b6f6",16);
    cutg_b6f6->SetVarX(" E detector 6 strip 6");
    cutg_b6f6->SetVarY("#DeltaE ");
    cutg_b6f6->SetTitle("Graph");
    cutg_b6f6->SetFillStyle(1000);
    cutg_b6f6->SetPoint(0,16643,3958.17);
   	cutg_b6f6->SetPoint(1,16404.5,4135.46);
   	cutg_b6f6->SetPoint(2,16231,4233.95);
   	cutg_b6f6->SetPoint(3,15978.1,4320.63);
   	cutg_b6f6->SetPoint(4,15761.2,4371.85);
   	cutg_b6f6->SetPoint(5,15558.9,4320.63);
   	cutg_b6f6->SetPoint(6,15515.5,4190.62);
   	cutg_b6f6->SetPoint(7,15580.6,4064.54);
   	cutg_b6f6->SetPoint(8,15746.8,3938.47);
   	cutg_b6f6->SetPoint(9,16028.7,3859.67);
   	cutg_b6f6->SetPoint(10,16202.1,3812.39);
   	cutg_b6f6->SetPoint(11,16433.4,3788.75);
   	cutg_b6f6->SetPoint(12,16599.6,3832.09);
   	cutg_b6f6->SetPoint(13,16650.2,3910.89);
   	cutg_b6f6->SetPoint(14,16628.6,3966.05);
   	cutg_b6f6->SetPoint(15,16643,3958.17);
    cutg_b6f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b6f6
    c7->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f6 = banana_b6f6->ProjectionX("projx_cutg_b6f6",1,banana_b6f6->GetNbinsX(),"[cutg_b6f6]");              
    projx_cutg_b6f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f6->GetMaximumBin(); 
    centroidx = projx_cutg_b6f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f6 = banana_b6f6->ProjectionY("projy_cutg_b6f6",1,banana_b6f6->GetNbinsY(),"[cutg_b6f6]");              
    projy_cutg_b6f6->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb6f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f6_E = " <<  gainb6f6_E << " keV/ch" << endl;
    cout << " gainb6f6_dE = " << gainb6f6_dE << " keV/ch"<< endl;
    cout << endl;


    c7->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f7 186W(a,a') channel
    banana_b6f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b6f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b6f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b6f7 = new TCutG("cutg_b6f7",18);
    cutg_b6f7->SetVarX(" E detector 6 strip 7");
    cutg_b6f7->SetVarY("#DeltaE ");
    cutg_b6f7->SetTitle("Graph");
    cutg_b6f7->SetFillStyle(1000);
    cutg_b6f7->SetPoint(0,16511.9,3910.99);
   	cutg_b6f7->SetPoint(1,16366,4021.23);
   	cutg_b6f7->SetPoint(2,16164.1,4156.62);
   	cutg_b6f7->SetPoint(3,16029.4,4212.71);
   	cutg_b6f7->SetPoint(4,15810.7,4278.47);
   	cutg_b6f7->SetPoint(5,15656.4,4280.4);
   	cutg_b6f7->SetPoint(6,15575.1,4235.92);
   	cutg_b6f7->SetPoint(7,15507.8,4094.73);
   	cutg_b6f7->SetPoint(8,15577.9,3953.54);
   	cutg_b6f7->SetPoint(9,15698.5,3874.24);
   	cutg_b6f7->SetPoint(10,15956.5,3769.8);
   	cutg_b6f7->SetPoint(11,16200.5,3704.04);
   	cutg_b6f7->SetPoint(12,16335.2,3702.11);
   	cutg_b6f7->SetPoint(13,16472.6,3729.18);
   	cutg_b6f7->SetPoint(14,16506.3,3771.73);
   	cutg_b6f7->SetPoint(15,16520.3,3849.1);
   	cutg_b6f7->SetPoint(16,16509.1,3922.59);
   	cutg_b6f7->SetPoint(17,16511.9,3910.99);
    cutg_b6f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f7
    c7->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f7 = banana_b6f7->ProjectionX("projx_cutg_b6f7",1,banana_b6f7->GetNbinsX(),"[cutg_b6f7]");              
    projx_cutg_b6f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b6f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b6f7->GetMaximumBin(); 
    centroidx = projx_cutg_b6f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f7 = banana_b6f7->ProjectionY("projy_cutg_b6f7",1,banana_b6f7->GetNbinsY(),"[cutg_b6f7]");              
    projy_cutg_b6f7->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b6f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb6f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb6f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb6f7_E = " <<  gainb6f7_E << " keV/ch" << endl;
    cout << " gainb6f7_dE = " << gainb6f7_dE << " keV/ch"<< endl;
    cout << endl;


    ///////////////////
    // E DETECTOR b7 //
    ///////////////////

    // Make canvas to plot the 2D banana plots 
    TCanvas *c8 = new TCanvas("c8","c8:b7 bananas",1400,800);
    c8->Divide(8,3,0,0);
    c8->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f0 186W(a,a') channel
    banana_b7f0->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f0->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f0->Draw();
    QKinz_f0_graph->Draw("p same");

    TCutG *cutg_b7f0 = new TCutG("cutg_b7f0",16);
    cutg_b7f0->SetVarX(" E detector 7 strip 0");
    cutg_b7f0->SetVarY("#DeltaE ");
    cutg_b7f0->SetTitle("Graph");
    cutg_b7f0->SetFillStyle(1000);
    cutg_b7f0->SetPoint(0,15938.4,4176.72);
   	cutg_b7f0->SetPoint(1,15773.9,4253.44);
   	cutg_b7f0->SetPoint(2,15648.8,4326.5);
   	cutg_b7f0->SetPoint(3,15484.3,4395.92);
   	cutg_b7f0->SetPoint(4,15181.6,4443.41);
   	cutg_b7f0->SetPoint(5,15004,4388.61);
   	cutg_b7f0->SetPoint(6,15017.1,4275.36);
   	cutg_b7f0->SetPoint(7,15221.1,4100);
   	cutg_b7f0->SetPoint(8,15392.2,4030.59);
   	cutg_b7f0->SetPoint(9,15668.6,3939.26);
   	cutg_b7f0->SetPoint(10,15846.2,3913.68);
   	cutg_b7f0->SetPoint(11,16004.2,3968.48);
   	cutg_b7f0->SetPoint(12,16056.8,4056.16);
   	cutg_b7f0->SetPoint(13,15964.7,4132.88);
   	cutg_b7f0->SetPoint(14,15905.5,4187.68);
   	cutg_b7f0->SetPoint(15,15938.4,4176.72);
    cutg_b7f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f0
    c8->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f0 = banana_b7f0->ProjectionX("projx_cutg_b7f0",1,banana_b7f0->GetNbinsX(),"[cutg_b7f0]");              
    projx_cutg_b7f0->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f0->GetMaximumBin(); 
    centroidx = projx_cutg_b7f0->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f0 = banana_b7f0->ProjectionY("projy_cutg_b7f0",1,banana_b7f0->GetNbinsY(),"[cutg_b7f0]");              
    projy_cutg_b7f0->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f0_E  = 5.0*f0_e_energy[0]/centroidx;
    double gainb7f0_dE = 2.5*f0_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f0_E = " <<  gainb7f0_E << " keV/ch" << endl;
    cout << " gainb7f0_dE = " << gainb7f0_dE << " keV/ch"<< endl;
    cout << endl;


    c8->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f1 186W(a,a') channel
    banana_b7f1->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f1->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f1->Draw();
    QKinz_f1_graph->Draw("p same");
   
    TCutG *cutg_b7f1 = new TCutG("cutg_b7f1",15);
    cutg_b7f1->SetVarX(" E detector 7 strip 1");
    cutg_b7f1->SetVarY("#DeltaE ");
    cutg_b7f1->SetTitle("Graph");
    cutg_b7f1->SetFillStyle(1000);
    cutg_b7f1->SetPoint(0,15947.4,4127.68);
   	cutg_b7f1->SetPoint(1,15805,4227.97);
   	cutg_b7f1->SetPoint(2,15577.2,4364.36);
   	cutg_b7f1->SetPoint(3,15356.4,4452.61);
   	cutg_b7f1->SetPoint(4,15128.6,4480.69);
   	cutg_b7f1->SetPoint(5,14972,4452.61);
   	cutg_b7f1->SetPoint(6,15021.8,4256.05);
   	cutg_b7f1->SetPoint(7,15114.4,4143.72);
   	cutg_b7f1->SetPoint(8,15263.9,4031.4);
   	cutg_b7f1->SetPoint(9,15491.7,3963.21);
   	cutg_b7f1->SetPoint(10,15733.8,3955.19);
   	cutg_b7f1->SetPoint(11,15947.4,3987.28);
   	cutg_b7f1->SetPoint(12,15961.6,4087.56);
   	cutg_b7f1->SetPoint(13,15926,4143.72);
   	cutg_b7f1->SetPoint(14,15947.4,4127.68);
    cutg_b7f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f1
    c8->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f1 = banana_b7f1->ProjectionX("projx_cutg_b7f1",1,banana_b7f1->GetNbinsX(),"[cutg_b7f1]");              
    projx_cutg_b7f1->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f1->GetMaximumBin(); 
    centroidx = projx_cutg_b7f1->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f1 = banana_b7f1->ProjectionY("projy_cutg_b7f1",1,banana_b7f1->GetNbinsY(),"[cutg_b7f1]");              
    projy_cutg_b7f1->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f1_E  = 5.0*f1_e_energy[0]/centroidx;
    double gainb7f1_dE = 2.5*f1_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f1_E = " <<  gainb7f1_E << " keV/ch" << endl;
    cout << " gainb7f1_dE = " << gainb7f1_dE << " keV/ch"<< endl;
    cout << endl;


    c8->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f2 186W(a,a') channel
    banana_b7f2->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f2->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f2->Draw();
    QKinz_f2_graph->Draw("p same");

    TCutG *cutg_b7f2 = new TCutG("cutg_b7f2",17);
    cutg_b7f2->SetVarX(" E detector 7 strip 2");
    cutg_b7f2->SetVarY("#DeltaE ");
    cutg_b7f2->SetTitle("Graph");
    cutg_b7f2->SetFillStyle(1000);
    cutg_b7f2->SetPoint(0,15967.7,4230.97);
   	cutg_b7f2->SetPoint(1,15811.3,4390.86);
   	cutg_b7f2->SetPoint(2,15665.7,4457.48);
   	cutg_b7f2->SetPoint(3,15428.3,4546.3);
   	cutg_b7f2->SetPoint(4,15174.8,4572.95);
   	cutg_b7f2->SetPoint(5,15040,4546.3);
   	cutg_b7f2->SetPoint(6,14975.3,4417.51);
   	cutg_b7f2->SetPoint(7,14991.4,4270.95);
   	cutg_b7f2->SetPoint(8,15142.5,4146.59);
   	cutg_b7f2->SetPoint(9,15449.9,4000.03);
   	cutg_b7f2->SetPoint(10,15671,3920.09);
   	cutg_b7f2->SetPoint(11,15854.4,3920.09);
   	cutg_b7f2->SetPoint(12,16043.2,4000.03);
   	cutg_b7f2->SetPoint(13,16037.8,4097.74);
   	cutg_b7f2->SetPoint(14,16005.5,4191);
   	cutg_b7f2->SetPoint(15,15951.5,4248.74);
   	cutg_b7f2->SetPoint(16,15967.7,4230.97);
    cutg_b7f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f2
    c8->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f2 = banana_b7f2->ProjectionX("projx_cutg_b7f2",1,banana_b7f2->GetNbinsX(),"[cutg_b7f2]");              
    projx_cutg_b7f2->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f2->GetMaximumBin(); 
    centroidx = projx_cutg_b7f2->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f2 = banana_b7f2->ProjectionY("projy_cutg_b7f2",1,banana_b7f2->GetNbinsY(),"[cutg_b7f2]");              
    projy_cutg_b7f2->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f2_E  = 5.0*f2_e_energy[0]/centroidx;
    double gainb7f2_dE = 2.5*f2_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f2_E = " <<  gainb7f2_E << " keV/ch" << endl;
    cout << " gainb7f2_dE = " << gainb7f2_dE << " keV/ch"<< endl;
    cout << endl;


    c8->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f3 186W(a,a') elastic peak
    banana_b7f3->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f3->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f3->Draw();
    QKinz_f3_graph->Draw("p same");

    TCutG *cutg_b7f3 = new TCutG("cutg_b7f3",15);
    cutg_b7f3->SetVarX(" E detector 7 strip 3");
    cutg_b7f3->SetVarY("#DeltaE ");
    cutg_b7f3->SetTitle("Graph");
    cutg_b7f3->SetFillStyle(1000);
    cutg_b7f3->SetPoint(0,16034.5,3956.68);
   	cutg_b7f3->SetPoint(1,15856.5,4102.81);
   	cutg_b7f3->SetPoint(2,15692.8,4197.36);
   	cutg_b7f3->SetPoint(3,15429.3,4322.01);
   	cutg_b7f3->SetPoint(4,15137.4,4334.9);
   	cutg_b7f3->SetPoint(5,14973.7,4261.83);
   	cutg_b7f3->SetPoint(6,14980.8,4115.7);
   	cutg_b7f3->SetPoint(7,15059.1,3978.17);
   	cutg_b7f3->SetPoint(8,15279.8,3875.01);
   	cutg_b7f3->SetPoint(9,15621.6,3793.35);
   	cutg_b7f3->SetPoint(10,15763.9,3776.16);
   	cutg_b7f3->SetPoint(11,15984.7,3823.44);
   	cutg_b7f3->SetPoint(12,16048.7,3905.1);
   	cutg_b7f3->SetPoint(13,16027.4,3973.87);
   	cutg_b7f3->SetPoint(14,16034.5,3956.68);
    cutg_b7f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f3
    c8->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f3 = banana_b7f3->ProjectionX("projx_cutg_b7f3",1,banana_b7f3->GetNbinsX(),"[cutg_b7f3]");              
    projx_cutg_b7f3->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f3->GetMaximumBin(); 
    centroidx = projx_cutg_b7f3->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f3 = banana_b7f3->ProjectionY("projy_cutg_b7f3",1,banana_b7f3->GetNbinsY(),"[cutg_b7f3]");              
    projy_cutg_b7f3->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f3_E  = 5.0*f3_e_energy[0]/centroidx;
    double gainb7f3_dE = 2.5*f3_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f3_E = " <<  gainb7f3_E << " keV/ch" << endl;
    cout << " gainb7f3_dE = " << gainb7f3_dE << " keV/ch"<< endl;
    cout << endl;

    c8->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f4 186W(a,a') channel
    banana_b7f4->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f4->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f4->Draw();
    QKinz_f4_graph->Draw("p same");

    TCutG *cutg_b7f4 = new TCutG("cutg_b7f4",18);
    cutg_b7f4->SetVarX(" E detector 7 strip 4");
    cutg_b7f4->SetVarY("#DeltaE ");
    cutg_b7f4->SetTitle("Graph");
    cutg_b7f4->SetFillStyle(1000);
    cutg_b7f4->SetPoint(0,15974.2,4206.98);
   	cutg_b7f4->SetPoint(1,15879.1,4305.47);
   	cutg_b7f4->SetPoint(2,15752.2,4376.39);
   	cutg_b7f4->SetPoint(3,15598.9,4439.43);
   	cutg_b7f4->SetPoint(4,15524.9,4467.01);
   	cutg_b7f4->SetPoint(5,15350.5,4510.34);
   	cutg_b7f4->SetPoint(6,15154.9,4498.52);
   	cutg_b7f4->SetPoint(7,15006.9,4403.97);
   	cutg_b7f4->SetPoint(8,14996.3,4313.35);
   	cutg_b7f4->SetPoint(9,15038.6,4199.1);
   	cutg_b7f4->SetPoint(10,15160.2,4057.26);
   	cutg_b7f4->SetPoint(11,15487.9,3962.71);
   	cutg_b7f4->SetPoint(12,15630.6,3931.19);
   	cutg_b7f4->SetPoint(13,15815.7,3935.13);
   	cutg_b7f4->SetPoint(14,15963.7,3982.41);
   	cutg_b7f4->SetPoint(15,16011.2,4073.02);
   	cutg_b7f4->SetPoint(16,15968.9,4226.68);
   	cutg_b7f4->SetPoint(17,15974.2,4206.98);
    cutg_b7f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f4
    c8->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f4 = banana_b7f4->ProjectionX("projx_cutg_b7f4",1,banana_b7f4->GetNbinsX(),"[cutg_b7f4]");              
    projx_cutg_b7f4->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f4->GetMaximumBin(); 
    centroidx = projx_cutg_b7f4->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f4 = banana_b7f4->ProjectionY("projy_cutg_b7f4",1,banana_b7f4->GetNbinsY(),"[cutg_b7f4]");              
    projy_cutg_b7f4->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f4_E  = 5.0*f4_e_energy[0]/centroidx;
    double gainb7f4_dE = 2.5*f4_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f4_E = " <<  gainb7f4_E << " keV/ch" << endl;
    cout << " gainb7f4_dE = " << gainb7f4_dE << " keV/ch"<< endl;
    cout << endl;


    c8->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f5 60Ni(a,a) elastic peak
    banana_b7f5->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f5->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f5->Draw();
    QKinz_f5_graph->Draw("p same");

    TCutG *cutg_b7f5 = new TCutG("cutg_b7f5",18);
    cutg_b7f5->SetVarX(" E detector 7 strip 5");
    cutg_b7f5->SetVarY("#DeltaE ");
    cutg_b7f5->SetTitle("Graph");
    cutg_b7f5->SetFillStyle(1000);
    cutg_b7f5->SetPoint(0,16012.7,3991.86);
   	cutg_b7f5->SetPoint(1,15807.7,4170.66);
   	cutg_b7f5->SetPoint(2,15667.5,4225.67);
   	cutg_b7f5->SetPoint(3,15521.8,4301.32);
   	cutg_b7f5->SetPoint(4,15252.1,4387.28);
   	cutg_b7f5->SetPoint(5,15165.8,4387.28);
   	cutg_b7f5->SetPoint(6,15009.4,4342.58);
   	cutg_b7f5->SetPoint(7,14987.9,4291);
   	cutg_b7f5->SetPoint(8,14987.9,4201.6);
   	cutg_b7f5->SetPoint(9,15084.9,4050.32);
   	cutg_b7f5->SetPoint(10,15262.9,3954.04);
   	cutg_b7f5->SetPoint(11,15521.8,3874.96);
   	cutg_b7f5->SetPoint(12,15732.2,3819.94);
   	cutg_b7f5->SetPoint(13,15899.4,3833.7);
   	cutg_b7f5->SetPoint(14,15969.5,3892.15);
   	cutg_b7f5->SetPoint(15,16007.3,3964.36);
   	cutg_b7f5->SetPoint(16,15991.1,4015.93);
   	cutg_b7f5->SetPoint(17,16012.7,3991.86);
    cutg_b7f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f5
    c8->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f5 = banana_b7f5->ProjectionX("projx_cutg_b7f5",1,banana_b7f5->GetNbinsX(),"[cutg_b7f5]");              
    projx_cutg_b7f5->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f5->GetMaximumBin(); 
    centroidx = projx_cutg_b7f5->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f5 = banana_b7f5->ProjectionY("projy_cutg_b7f5",1,banana_b7f5->GetNbinsY(),"[cutg_b7f5]");              
    projy_cutg_b7f5->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f5_E  = 5.0*f5_e_energy[0]/centroidx;
    double gainb7f5_dE = 2.5*f5_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f5_E = " <<  gainb7f5_E << " keV/ch" << endl;
    cout << " gainb7f5_dE = " << gainb7f5_dE << " keV/ch"<< endl;
    cout << endl;


    c8->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f6 186W(a,a') channel
    banana_b7f6->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f6->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f6->Draw();
    QKinz_f6_graph->Draw("p same");

    TCutG *cutg_b7f6 = new TCutG("cutg_b7f6",21);
    cutg_b7f6->SetVarX(" E detector 7 strip 6");
    cutg_b7f6->SetVarY("#DeltaE ");
    cutg_b7f6->SetTitle("Graph");
    cutg_b7f6->SetFillStyle(1000);
    cutg_b7f6->SetPoint(0,15898.5,4319.93);
   	cutg_b7f6->SetPoint(1,15801.8,4400.52);
   	cutg_b7f6->SetPoint(2,15658.7,4481.1);
   	cutg_b7f6->SetPoint(3,15494.7,4561.69);
   	cutg_b7f6->SetPoint(4,15334.8,4616.49);
   	cutg_b7f6->SetPoint(5,15204.4,4629.38);
   	cutg_b7f6->SetPoint(6,15065.5,4603.6);
   	cutg_b7f6->SetPoint(7,14977.2,4558.47);
   	cutg_b7f6->SetPoint(8,14935.1,4487.55);
   	cutg_b7f6->SetPoint(9,14951.9,4377.95);
   	cutg_b7f6->SetPoint(10,14994,4294.14);
   	cutg_b7f6->SetPoint(11,15187.5,4168.42);
   	cutg_b7f6->SetPoint(12,15326.4,4107.18);
   	cutg_b7f6->SetPoint(13,15570.4,4016.92);
   	cutg_b7f6->SetPoint(14,15831.2,3975.01);
   	cutg_b7f6->SetPoint(15,15919.6,4016.92);
   	cutg_b7f6->SetPoint(16,16020.6,4113.62);
   	cutg_b7f6->SetPoint(17,16003.7,4207.11);
   	cutg_b7f6->SetPoint(18,15936.4,4284.47);
   	cutg_b7f6->SetPoint(19,15890.1,4326.38);
   	cutg_b7f6->SetPoint(20,15898.5,4319.93);
    cutg_b7f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b7f6
    c8->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f6 = banana_b7f6->ProjectionX("projx_cutg_b7f6",1,banana_b7f6->GetNbinsX(),"[cutg_b7f6]");              
    projx_cutg_b7f6->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f6->GetMaximumBin(); 
    centroidx = projx_cutg_b7f6->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f6 = banana_b7f6->ProjectionY("projy_cutg_b7f6",1,banana_b7f6->GetNbinsY(),"[cutg_b7f6]");              
    projy_cutg_b7f6->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f6_E  = 5.0*f6_e_energy[0]/centroidx;
    double gainb7f6_dE = 2.5*f6_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f6_E = " <<  gainb7f6_E << " keV/ch" << endl;
    cout << " gainb7f6_dE = " << gainb7f6_dE << " keV/ch"<< endl;
    cout << endl;

    c8->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f7 186W(a,a') channel
    banana_b7f7->GetXaxis()->SetRangeUser(0,24000);
    banana_b7f7->GetYaxis()->SetRangeUser(2000,10000);
    banana_b7f7->Draw();
    QKinz_f7_graph->Draw("p same");

    TCutG *cutg_b7f7 = new TCutG("cutg_b7f7",19);
    cutg_b7f7->SetVarX(" E detector 7 strip 7");
    cutg_b7f7->SetVarY("#DeltaE ");
    cutg_b7f7->SetTitle("Graph");
    cutg_b7f7->SetFillStyle(1000);
    cutg_b7f7->SetPoint(0,15960,4083.24);
   	cutg_b7f7->SetPoint(1,15839.6,4186.6);
   	cutg_b7f7->SetPoint(2,15657.1,4368.19);
   	cutg_b7f7->SetPoint(3,15486.2,4396.13);
   	cutg_b7f7->SetPoint(4,15342.5,4460.39);
   	cutg_b7f7->SetPoint(5,15226,4482.74);
   	cutg_b7f7->SetPoint(6,14965.8,4535.82);
   	cutg_b7f7->SetPoint(7,14818.3,4530.23);
   	cutg_b7f7->SetPoint(8,14690.1,4401.72);
   	cutg_b7f7->SetPoint(9,14666.8,4276);
   	cutg_b7f7->SetPoint(10,14791.1,4155.87);
   	cutg_b7f7->SetPoint(11,14973.6,4041.33);
   	cutg_b7f7->SetPoint(12,15303.7,3932.38);
   	cutg_b7f7->SetPoint(13,15606.6,3868.12);
   	cutg_b7f7->SetPoint(14,15870.7,3856.95);
   	cutg_b7f7->SetPoint(15,16037.7,3926.79);
   	cutg_b7f7->SetPoint(16,16026,4016.19);
   	cutg_b7f7->SetPoint(17,15956.1,4091.62);
   	cutg_b7f7->SetPoint(18,15960,4083.24);
    cutg_b7f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f7
    c8->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f7 = banana_b7f7->ProjectionX("projx_cutg_b7f7",1,banana_b7f7->GetNbinsX(),"[cutg_b7f7]");              
    projx_cutg_b7f7->GetXaxis()->SetRangeUser(14000,17000);
    projx_cutg_b7f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
    // Now finding the bin with the maximum number of counts, and use that as the peak instead
    binmax    = projx_cutg_b7f7->GetMaximumBin(); 
    centroidx = projx_cutg_b7f7->GetXaxis()->GetBinCenter(binmax);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f7 = banana_b7f7->ProjectionY("projy_cutg_b7f7",1,banana_b7f7->GetNbinsY(),"[cutg_b7f7]");              
    projy_cutg_b7f7->GetXaxis()->SetRangeUser(3000,5000);
    projy_cutg_b7f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    double gainb7f7_E  = 5.0*f7_e_energy[0]/centroidx;
    double gainb7f7_dE = 2.5*f7_delta_e_energy[0]/centroidy;

    cout << " First gains, Delta E and E: " << endl;
    cout << " gainb7f7_E = " <<  gainb7f7_E << " keV/ch" << endl;
    cout << " gainb7f7_dE = " << gainb7f7_dE << " keV/ch"<< endl;
    cout << endl;

    // Open output file to write the gains
    ofstream newgainsfile("newgains.txt");

    newgainsfile << gainb0f0_E << '\t' << gainb0f1_E << '\t' << gainb0f2_E << '\t' << gainb0f3_E << '\t' << gainb0f4_E << '\t' << gainb0f5_E << '\t' << gainb0f6_E << '\t' << gainb0f7_E << endl;
    newgainsfile << gainb1f0_E << '\t' << gainb1f1_E << '\t' << gainb1f2_E << '\t' << gainb1f3_E << '\t' << gainb1f4_E << '\t' << gainb1f5_E << '\t' << gainb1f6_E << '\t' << gainb1f7_E << endl;
    newgainsfile << gainb2f0_E << '\t' << gainb2f1_E << '\t' << gainb2f2_E << '\t' << gainb2f3_E << '\t' << gainb2f4_E << '\t' << gainb2f5_E << '\t' << gainb2f6_E << '\t' << gainb2f7_E << endl;
    newgainsfile << gainb3f0_E << '\t' << gainb3f1_E << '\t' << gainb3f2_E << '\t' << gainb3f3_E << '\t' << gainb3f4_E << '\t' << gainb3f5_E << '\t' << gainb3f6_E << '\t' << gainb3f7_E << endl;
    newgainsfile << gainb4f0_E << '\t' << gainb4f1_E << '\t' << gainb4f2_E << '\t' << gainb4f3_E << '\t' << gainb4f4_E << '\t' << gainb4f5_E << '\t' << gainb4f6_E << '\t' << gainb4f7_E << endl;
    newgainsfile << gainb5f0_E << '\t' << gainb5f1_E << '\t' << gainb5f2_E << '\t' << gainb5f3_E << '\t' << gainb5f4_E << '\t' << gainb5f5_E << '\t' << gainb5f6_E << '\t' << gainb5f7_E << endl;
    newgainsfile << gainb6f0_E << '\t' << gainb6f1_E << '\t' << gainb6f2_E << '\t' << gainb6f3_E << '\t' << gainb6f4_E << '\t' << gainb6f5_E << '\t' << gainb6f6_E << '\t' << gainb6f7_E << endl;
    newgainsfile << gainb7f0_E << '\t' << gainb7f1_E << '\t' << gainb7f2_E << '\t' << gainb7f3_E << '\t' << gainb7f4_E << '\t' << gainb7f5_E << '\t' << gainb7f6_E << '\t' << gainb7f7_E << endl;
    newgainsfile << endl;
    newgainsfile << gainb0f0_dE << '\t' << gainb0f1_dE << '\t' << gainb0f2_dE << '\t' << gainb0f3_dE << '\t' << gainb0f4_dE << '\t' << gainb0f5_dE << '\t' << gainb0f6_dE << '\t' << gainb0f7_dE << endl;
    newgainsfile << gainb1f0_dE << '\t' << gainb1f1_dE << '\t' << gainb1f2_dE << '\t' << gainb1f3_dE << '\t' << gainb1f4_dE << '\t' << gainb1f5_dE << '\t' << gainb1f6_dE << '\t' << gainb1f7_dE << endl;
    newgainsfile << gainb2f0_dE << '\t' << gainb2f1_dE << '\t' << gainb2f2_dE << '\t' << gainb2f3_dE << '\t' << gainb2f4_dE << '\t' << gainb2f5_dE << '\t' << gainb2f6_dE << '\t' << gainb2f7_dE << endl;
    newgainsfile << gainb3f0_dE << '\t' << gainb3f1_dE << '\t' << gainb3f2_dE << '\t' << gainb3f3_dE << '\t' << gainb3f4_dE << '\t' << gainb3f5_dE << '\t' << gainb3f6_dE << '\t' << gainb3f7_dE << endl;
    newgainsfile << gainb4f0_dE << '\t' << gainb4f1_dE << '\t' << gainb4f2_dE << '\t' << gainb4f3_dE << '\t' << gainb4f4_dE << '\t' << gainb4f5_dE << '\t' << gainb4f6_dE << '\t' << gainb4f7_dE << endl;
    newgainsfile << gainb5f0_dE << '\t' << gainb5f1_dE << '\t' << gainb5f2_dE << '\t' << gainb5f3_dE << '\t' << gainb5f4_dE << '\t' << gainb5f5_dE << '\t' << gainb5f6_dE << '\t' << gainb5f7_dE << endl;
    newgainsfile << gainb6f0_dE << '\t' << gainb6f1_dE << '\t' << gainb6f2_dE << '\t' << gainb6f3_dE << '\t' << gainb6f4_dE << '\t' << gainb6f5_dE << '\t' << gainb6f6_dE << '\t' << gainb6f7_dE << endl;
    newgainsfile << gainb7f0_dE << '\t' << gainb7f1_dE << '\t' << gainb7f2_dE << '\t' << gainb7f3_dE << '\t' << gainb7f4_dE << '\t' << gainb7f5_dE << '\t' << gainb7f6_dE << '\t' << gainb7f7_dE << endl;

    newgainsfile.close();


}
