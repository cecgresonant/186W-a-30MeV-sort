// Script to grab the m_nai_e_t_XX matrices for the 186W(a,p) data
// with gates on the 5/2+ level in 15N at Ex = 5270 keV. 
// Find and fit lines, e.g. at 1868 keV (from the 4648-keV level in 19F) 
// and 5269 keV (from 15N 1st Ex) to check the CACTUS calibration. 
// Cecilie, Aug 9, 2019
// Last update: August 10, 2019

#include <fstream>
#include <iostream>
#include "TSpectrum.h"

void check_CACTUScal(){
    // No stats shown
    gStyle->SetOptStat(0);

    // Grab input file
    TFile *file = TFile::Open("offline_186W_p_gate_15N_CACTUScalib.root");

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

    int npeaks = 10; // How many peaks to find
    // Use TSpectrum to find the peak candidates
    TSpectrum *s = new TSpectrum(2*npeaks);


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
    banana_NaI00->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI00->GetYaxis()->SetRangeUser(150,280);
    banana_NaI00->Draw();

    c1->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px00 = banana_NaI00->ProjectionX("px00",185,215);
    px00->GetYaxis()->SetTitle("Counts");
    px00->GetYaxis()->SetRangeUser(1,2400);
    px00->Rebin(4)->Draw();

    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_00: " << endl;
    int nfound = s->Search(px00,5,"",0.05);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    TH1 *hb = s->Background(px00,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    double *xpeaks = s->GetPositionX(); 
    double xp;
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;



    c1->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // NaI channel 01
    banana_NaI01->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI01->GetYaxis()->SetRangeUser(150,280);
    banana_NaI01->Draw();

    c1->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px01 = banana_NaI01->ProjectionX("px01",185,215);
    px01->GetYaxis()->SetTitle("Counts");
    px01->GetYaxis()->SetRangeUser(1,2000);
    px01->Rebin(4)->Draw();

    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_01: " << endl;
    nfound = s->Search(px01,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px01,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c1->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // NaI channel 02
    banana_NaI02->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI02->GetYaxis()->SetRangeUser(150,280);
    banana_NaI02->Draw();

    c1->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px02 = banana_NaI02->ProjectionX("px02",185,215);
    px02->GetYaxis()->SetTitle("Counts");
    px02->GetYaxis()->SetRangeUser(1,1800);
    px02->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_02: " << endl;
    nfound = s->Search(px02,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px02,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;



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
    banana_NaI03->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI03->GetYaxis()->SetRangeUser(150,280);
    banana_NaI03->Draw();

    c2->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px03 = banana_NaI03->ProjectionX("px03",185,215);
    px03->GetYaxis()->SetTitle("Counts");
    px03->GetYaxis()->SetRangeUser(1,1800);
    px03->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_03: " << endl;
    nfound = s->Search(px03,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px03,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c2->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 05
    banana_NaI05->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI05->GetYaxis()->SetRangeUser(150,280);
    banana_NaI05->Draw();

    c2->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px05 = banana_NaI05->ProjectionX("px05",185,215);
    px05->GetYaxis()->SetTitle("Counts");
    px05->GetYaxis()->SetRangeUser(1,1700);
    px05->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_05: " << endl;
    nfound = s->Search(px05,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px05,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c2->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 06
    banana_NaI06->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI06->GetYaxis()->SetRangeUser(150,280);
    banana_NaI06->Draw();

    c2->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px06 = banana_NaI06->ProjectionX("px06",185,215);
    px06->GetYaxis()->SetTitle("Counts");
    px06->GetYaxis()->SetRangeUser(1,1700);
    px06->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_06: " << endl;
    nfound = s->Search(px06,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px06,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;



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
    banana_NaI07->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI07->GetYaxis()->SetRangeUser(150,280);
    banana_NaI07->Draw();

    c3->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px07 = banana_NaI07->ProjectionX("px07",185,215);
    px07->GetYaxis()->SetTitle("Counts");
    px07->GetYaxis()->SetRangeUser(1,1800);
    px07->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_07: " << endl;
    nfound = s->Search(px07,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px07,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c3->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 10
    banana_NaI10->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI10->GetYaxis()->SetRangeUser(150,280);
    banana_NaI10->Draw();

    c3->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px10 = banana_NaI10->ProjectionX("px10",185,215);
    px10->GetYaxis()->SetTitle("Counts");
    px10->GetYaxis()->SetRangeUser(1,1800);
    px10->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_10: " << endl;
    nfound = s->Search(px10,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px10,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c3->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 11
    banana_NaI11->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI11->GetYaxis()->SetRangeUser(150,280);
    banana_NaI11->Draw();

    c3->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px11 = banana_NaI11->ProjectionX("px11",185,215);
    px11->GetYaxis()->SetTitle("Counts");
    px11->GetYaxis()->SetRangeUser(1,1800);
    px11->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_11: " << endl;
    nfound = s->Search(px11,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px11,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


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
    banana_NaI13->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI13->GetYaxis()->SetRangeUser(150,280);
    banana_NaI13->Draw();

    c4->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px13 = banana_NaI13->ProjectionX("px13",185,215);
    px13->GetYaxis()->SetTitle("Counts");
    px13->GetYaxis()->SetRangeUser(1,1700);
    px13->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_13: " << endl;
    nfound = s->Search(px13,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px13,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c4->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 14
    banana_NaI14->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI14->GetYaxis()->SetRangeUser(150,280);
    banana_NaI14->Draw();

    c4->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px14 = banana_NaI14->ProjectionX("px14",185,215);
    px14->GetYaxis()->SetTitle("Counts");
    px14->GetYaxis()->SetRangeUser(1,1700);
    px14->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_14: " << endl;
    nfound = s->Search(px14,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px14,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c4->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 15
    banana_NaI15->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI15->GetYaxis()->SetRangeUser(150,280);
    banana_NaI15->Draw();

    c4->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px15 = banana_NaI15->ProjectionX("px15",185,215);
    px15->GetYaxis()->SetTitle("Counts");
    px15->GetYaxis()->SetRangeUser(1,1700);
    px15->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_15: " << endl;
    nfound = s->Search(px15,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px15,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


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
    banana_NaI16->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI16->GetYaxis()->SetRangeUser(150,280);
    banana_NaI16->Draw();

    c5->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px16 = banana_NaI16->ProjectionX("px16",185,215);
    px16->GetYaxis()->SetTitle("Counts");
    px16->GetYaxis()->SetRangeUser(1,1700);
    px16->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_16: " << endl;
    nfound = s->Search(px16,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px16,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c5->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 17
    banana_NaI17->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI17->GetYaxis()->SetRangeUser(150,280);
    banana_NaI17->Draw();

    c5->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px17 = banana_NaI17->ProjectionX("px17",185,215);
    px17->GetYaxis()->SetTitle("Counts");
    px17->GetYaxis()->SetRangeUser(1,1700);
    px17->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_17: " << endl;
    nfound = s->Search(px17,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px17,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c5->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 18
    banana_NaI18->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI18->GetYaxis()->SetRangeUser(150,280);
    banana_NaI18->Draw();

    c5->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px18 = banana_NaI18->ProjectionX("px18",185,215);
    px18->GetYaxis()->SetTitle("Counts");
    px18->GetYaxis()->SetRangeUser(1,2200);
    px18->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_18: " << endl;
    nfound = s->Search(px18,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px18,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;



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
    banana_NaI19->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI19->GetYaxis()->SetRangeUser(150,280);
    banana_NaI19->Draw();

    c6->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px19 = banana_NaI19->ProjectionX("px19",185,215);
    px19->GetYaxis()->SetTitle("Counts");
    px19->GetYaxis()->SetRangeUser(1,1400);
    px19->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_19: " << endl;
    nfound = s->Search(px19,5,"",0.02);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px19,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;



    c6->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 20
    banana_NaI20->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI20->GetYaxis()->SetRangeUser(150,280);
    banana_NaI20->Draw();

    c6->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px20 = banana_NaI20->ProjectionX("px20",185,215);
    px20->GetYaxis()->SetTitle("Counts");
    px20->GetYaxis()->SetRangeUser(1,1900);
    px20->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_20: " << endl;
    nfound = s->Search(px20,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px20,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c6->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 21
    banana_NaI21->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI21->GetYaxis()->SetRangeUser(150,280);
    banana_NaI21->Draw();

    c6->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px21 = banana_NaI21->ProjectionX("px21",185,215);
    px21->GetYaxis()->SetTitle("Counts");
    px21->GetYaxis()->SetRangeUser(1,2100);
    px21->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_21: " << endl;
    nfound = s->Search(px21,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px21,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;

    
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
    banana_NaI22->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI22->GetYaxis()->SetRangeUser(150,280);
    banana_NaI22->Draw();

    c7->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px22 = banana_NaI22->ProjectionX("px22",185,215);
    px22->GetYaxis()->SetTitle("Counts");
    px22->GetYaxis()->SetRangeUser(1,1800);
    px22->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_22: " << endl;
    nfound = s->Search(px22,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px22,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c7->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 23
    banana_NaI23->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI23->GetYaxis()->SetRangeUser(150,280);
    banana_NaI23->Draw();

    c7->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px23 = banana_NaI23->ProjectionX("px23",185,215);
    px23->GetYaxis()->SetTitle("Counts");
    px23->GetYaxis()->SetRangeUser(1,1700);
    px23->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_23: " << endl;
    nfound = s->Search(px23,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px23,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;

    c7->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 24
    banana_NaI24->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI24->GetYaxis()->SetRangeUser(150,280);
    banana_NaI24->Draw();

    c7->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px24 = banana_NaI24->ProjectionX("px24",185,215);
    px24->GetYaxis()->SetTitle("Counts");
    px24->GetYaxis()->SetRangeUser(1,2000);
    px24->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_24: " << endl;
    nfound = s->Search(px24,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px24,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


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
    banana_NaI25->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI25->GetYaxis()->SetRangeUser(150,280);
    banana_NaI25->Draw();

    c8->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px25 = banana_NaI25->ProjectionX("px25",185,215);
    px25->GetYaxis()->SetTitle("Counts");
    px25->GetYaxis()->SetRangeUser(1,1800);
    px25->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_25: " << endl;
    nfound = s->Search(px25,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px25,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c8->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 26
    banana_NaI26->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI26->GetYaxis()->SetRangeUser(150,280);
    banana_NaI26->Draw();

    c8->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px26 = banana_NaI26->ProjectionX("px26",185,215);
    px26->GetYaxis()->SetTitle("Counts");
    px26->GetYaxis()->SetRangeUser(1,2500);
    px26->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_26: " << endl;
    nfound = s->Search(px26,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px26,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


    c8->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 27
    banana_NaI27->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI27->GetYaxis()->SetRangeUser(150,280);
    banana_NaI27->Draw();

    c8->cd(6);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px27 = banana_NaI27->ProjectionX("px27",185,215);
    px27->GetYaxis()->SetTitle("Counts");
    px27->GetYaxis()->SetRangeUser(1,2300);
    px27->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_27: " << endl;
    nfound = s->Search(px27,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px27,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;


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
    banana_NaI28->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI28->GetYaxis()->SetRangeUser(150,280);
    banana_NaI28->Draw();

    c9->cd(4);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px28 = banana_NaI28->ProjectionX("px28",185,215);
    px28->GetYaxis()->SetTitle("Counts");
    px28->GetYaxis()->SetRangeUser(1,2400);
    px28->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_28: " << endl;
    nfound = s->Search(px28,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px28,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;

    c9->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    
    // NaI channel 29
    banana_NaI29->GetXaxis()->SetRangeUser(0,6000);
    banana_NaI29->GetYaxis()->SetRangeUser(150,280);
    banana_NaI29->Draw();

    c9->cd(5);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    TH1D *px29 = banana_NaI29->ProjectionX("px29",185,215);
    px29->GetYaxis()->SetTitle("Counts");
    px29->GetYaxis()->SetRangeUser(1,2100);
    px29->Rebin(4)->Draw();
    cout << " **************************** " << endl;
    cout << " Peaks, m_nai_e_t_29: " << endl;
    nfound = s->Search(px29,5,"",0.03);
    printf(" Found %d candidate peaks to fit\n",nfound);
    // Estimate background using TSpectrum::Background
    hb = s->Background(px29,15,"same");
    if (hb) c1->Update();

    // get centroid of the sum peak
    xpeaks = s->GetPositionX(); 
    for(int p = 0;p<nfound;p++){
        xp = xpeaks[p];
        cout << " Centroid of peak no. " << p << " is " << xp << " keV" << endl;
    }
    cout << " **************************** " << endl;





}
