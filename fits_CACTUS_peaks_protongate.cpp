// Script to grab the m_nai_e_t_XX matrices for the 186W(a,p) data
// with gates on the 5/2+ level in 15N at Ex = 5270 keV, 
// and fit the line at 1598 keV (from the 4377-keV level in 19F) and 5269 keV (from 15N 1st Ex).
// This is to get the CACTUS calibration. 
// Cecilie, Aug 9, 2019
// Last update: August 10, 2019

#include <fstream>
#include <iostream>

void fits_CACTUS_peaks_protongate(){
    // No stats shown
    gStyle->SetOptStat(0);

    // Open file to write centroids 
    ofstream gainfile("cactus_gains.txt");

    // Grab input file
    TFile *file = TFile::Open("offline_186W_p_gate_15N_plainCACTUScal.root");

    // All NaI versus time matrices
	TH2D *banana_NaI00  = (TH2D*)file->Get("m_nai_e_t_00"); 
    TH2D *banana_NaI01  = (TH2D*)file->Get("m_nai_e_t_01"); 
    TH2D *banana_NaI02  = (TH2D*)file->Get("m_nai_e_t_02"); 
    TH2D *banana_NaI03  = (TH2D*)file->Get("m_nai_e_t_03"); 
    TH2D *banana_NaI04  = (TH2D*)file->Get("m_nai_e_t_04"); // empty channel
    TH2D *banana_NaI05  = (TH2D*)file->Get("m_nai_e_t_05"); 
    TH2D *banana_NaI06  = (TH2D*)file->Get("m_nai_e_t_06"); 
    TH2D *banana_NaI07  = (TH2D*)file->Get("m_nai_e_t_07"); 
    TH2D *banana_NaI08  = (TH2D*)file->Get("m_nai_e_t_08"); // empty channel
    TH2D *banana_NaI09  = (TH2D*)file->Get("m_nai_e_t_09"); // empty channel
    TH2D *banana_NaI10  = (TH2D*)file->Get("m_nai_e_t_10"); 
    TH2D *banana_NaI11  = (TH2D*)file->Get("m_nai_e_t_11"); 
    TH2D *banana_NaI12  = (TH2D*)file->Get("m_nai_e_t_12"); // empty channel
    TH2D *banana_NaI13  = (TH2D*)file->Get("m_nai_e_t_13"); 
    TH2D *banana_NaI14  = (TH2D*)file->Get("m_nai_e_t_14"); 
    TH2D *banana_NaI15  = (TH2D*)file->Get("m_nai_e_t_15"); 
    TH2D *banana_NaI16  = (TH2D*)file->Get("m_nai_e_t_16"); 
    TH2D *banana_NaI17  = (TH2D*)file->Get("m_nai_e_t_17"); 
    TH2D *banana_NaI18  = (TH2D*)file->Get("m_nai_e_t_18"); 
    TH2D *banana_NaI19  = (TH2D*)file->Get("m_nai_e_t_19"); 
    TH2D *banana_NaI20  = (TH2D*)file->Get("m_nai_e_t_20"); 
    TH2D *banana_NaI21  = (TH2D*)file->Get("m_nai_e_t_21"); 
    TH2D *banana_NaI22  = (TH2D*)file->Get("m_nai_e_t_22"); 
    TH2D *banana_NaI23  = (TH2D*)file->Get("m_nai_e_t_23"); 
    TH2D *banana_NaI24  = (TH2D*)file->Get("m_nai_e_t_24"); 
    TH2D *banana_NaI25  = (TH2D*)file->Get("m_nai_e_t_25"); 
    TH2D *banana_NaI26  = (TH2D*)file->Get("m_nai_e_t_26"); 
    TH2D *banana_NaI27  = (TH2D*)file->Get("m_nai_e_t_27"); 
    TH2D *banana_NaI28  = (TH2D*)file->Get("m_nai_e_t_28"); 
    TH2D *banana_NaI29  = (TH2D*)file->Get("m_nai_e_t_29"); 
    TH2D *banana_NaI30  = (TH2D*)file->Get("m_nai_e_t_30"); // empty channel
    TH2D *banana_NaI31  = (TH2D*)file->Get("m_nai_e_t_31"); // empty channel


    // START THE FITS
    // Make canvas to plot the 2D banana plots, nai_00-nai_02
    TCanvas *c1 = new TCanvas("c1","c1: NaI peaks, nai_00-nai_02 ",1400,800);
    c1->Divide(3,2,0,0);
    c1->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 00
    banana_NaI00->GetXaxis()->SetRangeUser(0,8000);
    banana_NaI00->GetYaxis()->SetRangeUser(150,280);
    banana_NaI00->Draw();

    c1->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px00 = banana_NaI00->ProjectionX("px00",185,215);
    px00->GetYaxis()->SetTitle("Counts");
    px00->GetYaxis()->SetRangeUser(1,2000);
    px00->Rebin(4)->Draw();
    TF1 *peakfit1 = new TF1("peakfit1","gaus",2180,2490);
    px00->Fit("peakfit1","R");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_00 = peakfit1->GetParameter(1); // centroid of 1st peak

    TF1 *peakfit2 = new TF1("peakfit2","gaus",6100,6650);
    px00->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_00 = peakfit2->GetParameter(1); // centroid of 2nd peak

    cout << " Centroids, m_e_t_00 = " << centroid1_00 << " " << centroid2_00 << endl;
    gainfile << centroid1_00 << '\t'<< centroid2_00 << endl;


    c1->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // NaI channel 01
    banana_NaI01->GetXaxis()->SetRangeUser(0,8000);
    banana_NaI01->GetYaxis()->SetRangeUser(150,280);
    banana_NaI01->Draw();

    c1->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px01 = banana_NaI01->ProjectionX("px01",185,215);
    px01->GetYaxis()->SetTitle("Counts");
    px01->GetYaxis()->SetRangeUser(1,1800);
    px01->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2250,2560);
    px01->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_01 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6190,6730);
    px01->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_01 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_01 = " << centroid1_01 << " " << centroid2_01 << endl;
    gainfile << centroid1_01 << '\t'<< centroid2_01 << endl;


    c1->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);


    // NaI channel 02
    banana_NaI02->GetXaxis()->SetRangeUser(0,8500);
    banana_NaI02->GetYaxis()->SetRangeUser(150,280);
    banana_NaI02->Draw();

    c1->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px02 = banana_NaI02->ProjectionX("px02",185,215);
    px02->GetYaxis()->SetTitle("Counts");
    px02->GetYaxis()->SetRangeUser(1,1600);
    px02->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2350,2620);
    px02->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_02 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6610,7225);
    px02->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_02 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_02 = " << centroid1_02 << " " << centroid2_02 << endl;
    gainfile << centroid1_02 << '\t'<< centroid2_02 << endl;



   // Make canvas to plot the 2D banana plots, nai_03, nai_05, nai_06 (nai_04 is empty)
    TCanvas *c2 = new TCanvas("c2","c2: NaI peaks, nai_03, nai_05, nai_06 ",1400,800);
    c2->Divide(3,2,0,0);
    c2->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 03
    banana_NaI03->GetXaxis()->SetRangeUser(0,8500);
    banana_NaI03->GetYaxis()->SetRangeUser(150,280);
    banana_NaI03->Draw();

    c2->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px03 = banana_NaI03->ProjectionX("px03",185,215);
    px03->GetYaxis()->SetTitle("Counts");
    px03->GetYaxis()->SetRangeUser(1,1400);
    px03->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2350,2660);
    px03->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_03 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6670,7350);
    px03->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_03 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_03 = " << centroid1_03 << " " << centroid2_03 << endl;
    gainfile << centroid1_03 << '\t'<< centroid2_03 << endl;
    gainfile << 0.00 << '\t'<< 0.00 << endl; // Empty ch 4

    c2->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 05
    banana_NaI05->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI05->GetYaxis()->SetRangeUser(150,280);
    banana_NaI05->Draw();

    c2->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px05 = banana_NaI05->ProjectionX("px05",185,215);
    px05->GetYaxis()->SetTitle("Counts");
    px05->GetYaxis()->SetRangeUser(1,1400);
    px05->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2370,2690);
    px05->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_05 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6875,7670);
    px05->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_05 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_05 = " << centroid1_05 << " " << centroid2_05 << endl;
    gainfile << centroid1_05 << '\t'<< centroid2_05 << endl;


    c2->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 06
    banana_NaI06->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI06->GetYaxis()->SetRangeUser(150,280);
    banana_NaI06->Draw();

    c2->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px06 = banana_NaI06->ProjectionX("px06",185,215);
    px06->GetYaxis()->SetTitle("Counts");
    px06->GetYaxis()->SetRangeUser(1,1400);
    px06->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2400,2720);
    px06->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_06 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6930,7600);
    px06->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_06 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_06 = " << centroid1_06 << " " << centroid2_06 << endl;
    gainfile << centroid1_06 << '\t'<< centroid2_06 << endl;



   // Make canvas to plot the 2D banana plots, nai_07, nai_10, nai_11 (nai_08 and nai_09 are empty)
    TCanvas *c3 = new TCanvas("c3","c3: NaI peaks, nai_07, nai_10, nai_11 ",1400,800);
    c3->Divide(3,2,0,0);
    c3->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 07
    banana_NaI07->GetXaxis()->SetRangeUser(0,8500);
    banana_NaI07->GetYaxis()->SetRangeUser(150,280);
    banana_NaI07->Draw();

    c3->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px07 = banana_NaI07->ProjectionX("px07",185,215);
    px07->GetYaxis()->SetTitle("Counts");
    px07->GetYaxis()->SetRangeUser(1,1400);
    px07->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2370,2660);
    px07->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_07 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6810,7380);
    px07->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_07 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_07 = " << centroid1_07 << " " << centroid2_07 << endl;
    gainfile << centroid1_07 << '\t'<< centroid2_07 << endl;
    gainfile << 0.00 << '\t'<< 0.00 << endl; // Empty ch 8
    gainfile << 0.00 << '\t'<< 0.00 << endl; // Empty ch 9


    c3->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 10
    banana_NaI10->GetXaxis()->SetRangeUser(0,8500);
    banana_NaI10->GetYaxis()->SetRangeUser(150,280);
    banana_NaI10->Draw();

    c3->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px10 = banana_NaI10->ProjectionX("px10",185,215);
    px10->GetYaxis()->SetTitle("Counts");
    px10->GetYaxis()->SetRangeUser(1,1400);
    px10->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2420,2690);
    px10->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_10 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6850,7400);
    px10->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_10 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_10 = " << centroid1_10 << " " << centroid2_10 << endl;
    gainfile << centroid1_10 << '\t'<< centroid2_10 << endl;


    c3->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 11
    banana_NaI11->GetXaxis()->SetRangeUser(0,8500);
    banana_NaI11->GetYaxis()->SetRangeUser(150,280);
    banana_NaI11->Draw();

    c3->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px11 = banana_NaI11->ProjectionX("px11",185,215);
    px11->GetYaxis()->SetTitle("Counts");
    px11->GetYaxis()->SetRangeUser(1,1400);
    px11->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2420,2660);
    px11->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_11 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6900,7400);
    px11->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_11 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_11 = " << centroid1_11 << " " << centroid2_11 << endl;
    gainfile << centroid1_11 << '\t'<< centroid2_11 << endl;
    gainfile << 0.00 << '\t'<< 0.00 << endl; // Empty ch 12


   // Make canvas to plot the 2D banana plots, nai_13, nai_14, nai_15 (nai_12 is empty)
    TCanvas *c4 = new TCanvas("c4","c4: NaI peaks, nai_13, nai_14, nai_15 ",1400,800);
    c4->Divide(3,2,0,0);
    c4->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 13
    banana_NaI13->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI13->GetYaxis()->SetRangeUser(150,280);
    banana_NaI13->Draw();

    c4->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px13 = banana_NaI13->ProjectionX("px13",185,215);
    px13->GetYaxis()->SetTitle("Counts");
    px13->GetYaxis()->SetRangeUser(1,1200);
    px13->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2440,2720);
    px13->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_13 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7090,7660);
    px13->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_13 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_13 = " << centroid1_13 << " " << centroid2_13 << endl;
    gainfile << centroid1_13 << '\t'<< centroid2_13 << endl;


    c4->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 14
    banana_NaI14->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI14->GetYaxis()->SetRangeUser(150,280);
    banana_NaI14->Draw();

    c4->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px14 = banana_NaI14->ProjectionX("px14",185,215);
    px14->GetYaxis()->SetTitle("Counts");
    px14->GetYaxis()->SetRangeUser(1,1400);
    px14->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2400,2620);
    px14->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_14 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6830,7350);
    px14->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_14 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_14 = " << centroid1_14 << " " << centroid2_14 << endl;
    gainfile << centroid1_14 << '\t'<< centroid2_14 << endl;


    c4->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 15
    banana_NaI15->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI15->GetYaxis()->SetRangeUser(150,280);
    banana_NaI15->Draw();

    c4->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px15 = banana_NaI15->ProjectionX("px15",185,215);
    px15->GetYaxis()->SetTitle("Counts");
    px15->GetYaxis()->SetRangeUser(1,1200);
    px15->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2460,2750);
    px15->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_15 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",6990,7540);
    px15->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_15 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_15 = " << centroid1_15 << " " << centroid2_15 << endl;
    gainfile << centroid1_15 << '\t'<< centroid2_15 << endl;


    // Make canvas to plot the 2D banana plots, nai_16, nai_17, nai_18
    TCanvas *c5 = new TCanvas("c5","c5: NaI peaks, nai_16, nai_17, nai_18 ",1400,800);
    c5->Divide(3,2,0,0);
    c5->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 16
    banana_NaI16->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI16->GetYaxis()->SetRangeUser(150,280);
    banana_NaI16->Draw();

    c5->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px16 = banana_NaI16->ProjectionX("px16",185,215);
    px16->GetYaxis()->SetTitle("Counts");
    px16->GetYaxis()->SetRangeUser(1,1100);
    px16->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2500,2810);
    px16->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_16 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7030,7640);
    px16->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_16 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_16 = " << centroid1_16 << " " << centroid2_16 << endl;
    gainfile << centroid1_16 << '\t'<< centroid2_16 << endl;


    c5->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 17
    banana_NaI17->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI17->GetYaxis()->SetRangeUser(150,280);
    banana_NaI17->Draw();

    c5->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px17 = banana_NaI17->ProjectionX("px17",185,215);
    px17->GetYaxis()->SetTitle("Counts");
    px17->GetYaxis()->SetRangeUser(1,1100);
    px17->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2365,2670);
    px17->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_17 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7640,8180);
    px17->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_17 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_17 = " << centroid1_17 << " " << centroid2_17 << endl;
    gainfile << centroid1_17 << '\t'<< centroid2_17 << endl;


    c5->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 18
    banana_NaI18->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI18->GetYaxis()->SetRangeUser(150,280);
    banana_NaI18->Draw();

    c5->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px18 = banana_NaI18->ProjectionX("px18",185,215);
    px18->GetYaxis()->SetTitle("Counts");
    px18->GetYaxis()->SetRangeUser(1,1400);
    px18->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2490,2760);
    px18->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_18 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7160,7790);
    px18->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_18 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_18 = " << centroid1_18 << " " << centroid2_18 << endl;
    gainfile << centroid1_18 << '\t'<< centroid2_18 << endl;


    // Make canvas to plot the 2D banana plots, nai_19, nai_20, nai_21
    TCanvas *c6 = new TCanvas("c6","c6: NaI peaks, nai_19, nai_20, nai_21 ",1400,800);
    c6->Divide(3,2,0,0);
    c6->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 19
    banana_NaI19->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI19->GetYaxis()->SetRangeUser(150,280);
    banana_NaI19->Draw();

    c6->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px19 = banana_NaI19->ProjectionX("px19",185,215);
    px19->GetYaxis()->SetTitle("Counts");
    px19->GetYaxis()->SetRangeUser(1,1100);
    px19->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2570,2950);
    px19->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_19 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7460,8220);
    px19->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_19 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_19 = " << centroid1_19 << " " << centroid2_19 << endl;
    gainfile << centroid1_19 << '\t'<< centroid2_19 << endl;


    c6->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 20
    banana_NaI20->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI20->GetYaxis()->SetRangeUser(150,280);
    banana_NaI20->Draw();

    c6->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px20 = banana_NaI20->ProjectionX("px20",185,215);
    px20->GetYaxis()->SetTitle("Counts");
    px20->GetYaxis()->SetRangeUser(1,1400);
    px20->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2430,2680);
    px20->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_20 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7130,7550);
    px20->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_20 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_20 = " << centroid1_20 << " " << centroid2_20 << endl;
    gainfile << centroid1_20 << '\t'<< centroid2_20 << endl;


    c6->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 21
    banana_NaI21->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI21->GetYaxis()->SetRangeUser(150,280);
    banana_NaI21->Draw();

    c6->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px21 = banana_NaI21->ProjectionX("px21",185,215);
    px21->GetYaxis()->SetTitle("Counts");
    px21->GetYaxis()->SetRangeUser(1,1400);
    px21->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2520,2770);
    px21->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_21 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7350,7830);
    px21->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_21 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_21 = " << centroid1_21 << " " << centroid2_21 << endl;
    gainfile << centroid1_21 << '\t'<< centroid2_21 << endl;

    // Make canvas to plot the 2D banana plots, nai_22, nai_23, nai_24
    TCanvas *c7 = new TCanvas("c7","c7: NaI peaks, nai_22, nai_23, nai_24 ",1400,800);
    c7->Divide(3,2,0,0);
    c7->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 22
    banana_NaI22->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI22->GetYaxis()->SetRangeUser(150,280);
    banana_NaI22->Draw();

    c7->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px22 = banana_NaI22->ProjectionX("px22",185,215);
    px22->GetYaxis()->SetTitle("Counts");
    px22->GetYaxis()->SetRangeUser(1,1500);
    px22->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2450,2690);
    px22->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_22 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7100,7540);
    px22->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_22 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_22 = " << centroid1_22 << " " << centroid2_22 << endl;
    gainfile << centroid1_22 << '\t'<< centroid2_22 << endl;


    c7->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 23
    banana_NaI23->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI23->GetYaxis()->SetRangeUser(150,280);
    banana_NaI23->Draw();

    c7->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px23 = banana_NaI23->ProjectionX("px23",185,215);
    px23->GetYaxis()->SetTitle("Counts");
    px23->GetYaxis()->SetRangeUser(1,1300);
    px23->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2450,2710);
    px23->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_23 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7150,7710);
    px23->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_23 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_23 = " << centroid1_23 << " " << centroid2_23 << endl;
    gainfile << centroid1_23 << '\t'<< centroid2_23 << endl;

    c7->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 24
    banana_NaI24->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI24->GetYaxis()->SetRangeUser(150,280);
    banana_NaI24->Draw();

    c7->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px24 = banana_NaI24->ProjectionX("px24",185,215);
    px24->GetYaxis()->SetTitle("Counts");
    px24->GetYaxis()->SetRangeUser(1,1600);
    px24->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2700,3000);
    px24->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_24 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7680,8360);
    px24->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_24 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_24 = " << centroid1_24 << " " << centroid2_24 << endl;
    gainfile << centroid1_24 << '\t'<< centroid2_24 << endl;


    // Make canvas to plot the 2D banana plots, nai_25, nai_26, nai_27
    TCanvas *c8 = new TCanvas("c8","c8: NaI peaks, nai_25, nai_26, nai_27 ",1400,800);
    c8->Divide(3,2,0,0);
    c8->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 25
    banana_NaI25->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI25->GetYaxis()->SetRangeUser(150,280);
    banana_NaI25->Draw();

    c8->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px25 = banana_NaI25->ProjectionX("px25",185,215);
    px25->GetYaxis()->SetTitle("Counts");
    px25->GetYaxis()->SetRangeUser(1,1300);
    px25->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2560,2840);
    px25->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_25 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7330,7940);
    px25->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_25 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_25 = " << centroid1_25 << " " << centroid2_25 << endl;
    gainfile << centroid1_25 << '\t'<< centroid2_25 << endl;


    c8->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 26
    banana_NaI26->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI26->GetYaxis()->SetRangeUser(150,280);
    banana_NaI26->Draw();

    c8->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px26 = banana_NaI26->ProjectionX("px26",185,215);
    px26->GetYaxis()->SetTitle("Counts");
    px26->GetYaxis()->SetRangeUser(1,1800);
    px26->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2575,2810);
    px26->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_26 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7390,7790);
    px26->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_26 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_26 = " << centroid1_26 << " " << centroid2_26 << endl;
    gainfile << centroid1_26 << '\t'<< centroid2_26 << endl;


    c8->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 27
    banana_NaI27->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI27->GetYaxis()->SetRangeUser(150,280);
    banana_NaI27->Draw();

    c8->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px27 = banana_NaI27->ProjectionX("px27",185,215);
    px27->GetYaxis()->SetTitle("Counts");
    px27->GetYaxis()->SetRangeUser(1,1600);
    px27->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2600,2880);
    px27->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_27 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7300,7750);
    px27->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_27 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_27 = " << centroid1_27 << " " << centroid2_27 << endl;
    gainfile << centroid1_27 << '\t'<< centroid2_27 << endl;


    // Make canvas to plot the 2D banana plots, nai_28, nai_29 (nai_30 and nai_31 are empty)
    TCanvas *c9 = new TCanvas("c9","c9: NaI peaks, nai_28, nai_29 ",1400,800);
    c9->Divide(3,2,0,0);
    c9->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 28
    banana_NaI28->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI28->GetYaxis()->SetRangeUser(150,280);
    banana_NaI28->Draw();

    c9->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px28 = banana_NaI28->ProjectionX("px28",185,215);
    px28->GetYaxis()->SetTitle("Counts");
    px28->GetYaxis()->SetRangeUser(1,1800);
    px28->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2440,2690);
    px28->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_28 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7160,7660);
    px28->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_28 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_28 = " << centroid1_28 << " " << centroid2_28 << endl;
    gainfile << centroid1_28 << '\t'<< centroid2_28 << endl;

    c9->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 29
    banana_NaI29->GetXaxis()->SetRangeUser(0,8900);
    banana_NaI29->GetYaxis()->SetRangeUser(150,280);
    banana_NaI29->Draw();

    c9->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px29 = banana_NaI29->ProjectionX("px29",185,215);
    px29->GetYaxis()->SetTitle("Counts");
    px29->GetYaxis()->SetRangeUser(1,1600);
    px29->Rebin(4)->Draw();
    peakfit1 = new TF1("peakfit1","gaus",2470,2770);
    px29->Fit("peakfit1","R+");
    peakfit1->SetLineColor(kRed);
    peakfit1->Draw("same");
    double centroid1_29 = peakfit1->GetParameter(1); // centroid of 1st peak

    peakfit2 = new TF1("peakfit2","gaus",7240,7840);
    px29->Fit("peakfit2","R+");
    peakfit2->SetLineColor(kRed);
    peakfit2->Draw("same");
    double centroid2_29 = peakfit2->GetParameter(1); // centroid of 2nd peak
    cout << " Centroids, m_e_t_29 = " << centroid1_29 << " " << centroid2_29 << endl;
    gainfile << centroid1_29 << '\t'<< centroid2_29 << endl;


    gainfile.close();




}
