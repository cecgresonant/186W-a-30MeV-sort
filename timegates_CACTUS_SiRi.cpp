// Script to show the time gates used for the E(NaI)-time(NaI) matrix, 
// and the resulting level density and gamma strength for the various gates.
// Cecilie, Jan 3, 2020
// Last update: Jan 6, 2020

#include <fstream>
#include <iostream>

void timegates_CACTUS_SiRi(){
    // No stats shown
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    gStyle->SetPalette(kBird);

    // Grab input file with the E(NaI)-time matrix
    TFile *file = TFile::Open("offline_186W_aa_rnpeak_twoafter_prompt.root");

    // The NaI versus time matrix
	TH2D *timebanana_NaI  = (TH2D*)file->Get("m_nai_e_t_c"); 

    // Now, let's calibrate the time axis, and use MeV for the NaI energy
    double e_shift_x = (timebanana_NaI->GetXaxis()->GetBinLowEdge(1))/1000.; 
    double e_bin_x   = (timebanana_NaI->GetXaxis()->GetBinWidth(1))/1000.;
    int nbinsx       = timebanana_NaI->GetNbinsX();

    // The range in channels is 500, and the TDC range is 1.2 us = 1200 ns
    // Time zero is at the prompt peak, which is placed in channel 200.
    // With a dispersion 1200 ns/500 ch = 2.4 ns/ch, the shift is 
    // calculated from the prompt-peak position at time zero:
    // time = shift + dispersion*channel
    // 0 = shift + 2.4 ns *200 => shift = -2.4 ns*200 = -480 ns
    double e_shift_y = (timebanana_NaI->GetYaxis()->GetBinLowEdge(1))-480.; 
    double e_bin_y   = (timebanana_NaI->GetYaxis()->GetBinWidth(1))*1200./500.;
    int nbinsy       = timebanana_NaI->GetNbinsY();
    cout << " Shift time = " << e_shift_y << endl;
    cout << " Dispersion time = " << e_bin_y << endl;

    TH2D *timebanana_NaI_MeVtimeaxis  = new TH2D("timebanana_NaI_MeVtimeaxis","",nbinsx,e_shift_x,e_shift_x+(e_bin_x*nbinsx),nbinsy,e_shift_y,e_shift_y+(e_bin_y*nbinsy));

    // Put data into new matrix with MeV range instead of keV range
    for(int i = 0; i<nbinsx;i++){
        for(int j = 0; j<nbinsy; j++){
            double value = timebanana_NaI->GetBinContent(i,j);
            timebanana_NaI_MeVtimeaxis->SetBinContent(i,j,value);
        }
    }

    // Make canvas to plot the 2D banana plots, nai_00-nai_02
    TCanvas *c1 = new TCanvas("c1","c1: Time gates ",1400,530);
    c1->Divide(3,1,0,0);
    c1->cd(1);
    gPad->SetGrid(0,0);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.10);
    gPad->SetTopMargin(0.02);
    
    // NaI corrected time
    timebanana_NaI_MeVtimeaxis->GetXaxis()->SetTitle("E_{#gamma} (MeV)");
    timebanana_NaI_MeVtimeaxis->GetXaxis()->SetTitleSize(0.05);
    timebanana_NaI_MeVtimeaxis->GetXaxis()->SetLabelSize(0.045);
    timebanana_NaI_MeVtimeaxis->GetXaxis()->SetRangeUser(0,8.200);
    timebanana_NaI_MeVtimeaxis->GetYaxis()->SetRangeUser(-150,200);
    timebanana_NaI_MeVtimeaxis->GetYaxis()->SetTitle("#Delta t (ns)");
    timebanana_NaI_MeVtimeaxis->GetYaxis()->SetTitleSize(0.05);
    timebanana_NaI_MeVtimeaxis->GetYaxis()->SetTitleOffset(1.3);
    timebanana_NaI_MeVtimeaxis->GetYaxis()->SetLabelSize(0.045);
    timebanana_NaI_MeVtimeaxis->GetZaxis()->SetLabelSize(0.04);
    timebanana_NaI_MeVtimeaxis->Draw("colz");

    c1->Update();

    TPaletteAxis *palette = (TPaletteAxis*)timebanana_NaI_MeVtimeaxis->GetListOfFunctions()->FindObject("palette");
    if(!palette) cout << "nono." << endl;
    palette->SetX1NDC(0.905);
    palette->SetX2NDC(0.93);
    palette->Draw();    

    TLatex t;
    t.SetTextFont(42);
    t.DrawLatex(0.3,180,"(a)");

    TLine *prompt1 = new TLine(0,e_shift_y + (e_bin_y*191.),8.000,e_shift_y + (e_bin_y*191.));
    prompt1->SetLineWidth(3);
    prompt1->Draw();
    TLine *prompt2 = new TLine(0,e_shift_y + (e_bin_y*209.),8.000,e_shift_y + (e_bin_y*209.));
    prompt2->SetLineWidth(3);
    prompt2->Draw();

    TLine *random1_1 = new TLine(0,e_shift_y + (e_bin_y*246.),8.000,e_shift_y + (e_bin_y*246.));
    random1_1->SetLineColor(kBlue);
    //random1_1->SetLineStyle(2);
    random1_1->SetLineWidth(2);
    random1_1->Draw();

    TLine *random1_2 = new TLine(0,e_shift_y + (e_bin_y*264.),8.000,e_shift_y + (e_bin_y*264.));
    random1_2->SetLineColor(kBlue);
    //random1_2->SetLineStyle(2);
    random1_2->SetLineWidth(2);
    random1_2->Draw();

    TLine *random2_1 = new TLine(0,e_shift_y + (e_bin_y*221.),8.000,e_shift_y + (e_bin_y*221.));
    random2_1->SetLineColor(kRed+1);
    //random2_1->SetLineStyle(2);
    random2_1->SetLineWidth(2);
    random2_1->Draw();

    TLine *random2_2 = new TLine(0,e_shift_y + (e_bin_y*239.),8.000,e_shift_y + (e_bin_y*239.));
    random2_2->SetLineColor(kRed+1);
    //random2_2->SetLineStyle(2);
    random2_2->SetLineWidth(2);
    random2_2->Draw();

    TLine *random3_1 = new TLine(0,e_shift_y + (e_bin_y*161.),8.000,e_shift_y + (e_bin_y*161.));
    random3_1->SetLineColor(kMagenta+3);
    //random3_1->SetLineStyle(2);
    random3_1->SetLineWidth(2);
    random3_1->Draw();

    TLine *random3_2 = new TLine(0,e_shift_y + (e_bin_y*179.),8.000,e_shift_y + (e_bin_y*179.));
    random3_2->SetLineColor(kMagenta+3);
    //random3_2->SetLineStyle(2);
    random3_2->SetLineWidth(2);
    random3_2->Draw();


    TPaveLabel *label1 = new TPaveLabel(0.73,0.47,0.88,0.53,"prompt","NDC");
    label1->SetFillColor(0);
    label1->SetBorderSize(5);
    label1->SetTextSize(0.65);
    label1->SetTextFont(42);
    label1->Draw();

    TPaveLabel *label2 = new TPaveLabel(0.73,0.789,0.88,0.849,"random1","NDC");
    label2->SetFillColor(0);
    label2->SetBorderSize(5);
    label2->SetTextSize(0.6);
    label2->SetTextFont(42);
    label2->Draw();

    TPaveLabel *label3 = new TPaveLabel(0.73,0.645,0.88,0.705,"random2","NDC");
    label3->SetFillColor(0);
    label3->SetBorderSize(5);
    label3->SetTextSize(0.6);
    label3->SetTextFont(42);
    label3->Draw();

    TPaveLabel *label4 = new TPaveLabel(0.73,0.295,0.88,0.355,"random3","NDC");
    label4->SetFillColor(0);
    label4->SetBorderSize(5);
    label4->SetTextSize(0.59);
    label4->SetTextFont(42);
    label4->Draw();

    // Now, grabbing the level density for the three different random-subtraction gates
    // Read input files. The reference calculation ("base line") is 
    // EB06_RMI0.85 for the time gate with random subtraction two peaks after the prompt peak
    ifstream rholev("../186W_aa_OsloMethod/analysis_rndpeak_twoafter_prompt/EB06_RMI0.85/rholev.cnt"), 
    rhopaw("../186W_aa_OsloMethod/analysis_rndpeak_twoafter_prompt/EB06_RMI0.85/rhopaw.cnt"), fermi("../186W_aa_OsloMethod/analysis_rndpeak_twoafter_prompt/EB06_RMI0.85/fermigas.cnt");

    // Random subtraction after the prompt peak
    ifstream rhopaw_rdp_after("../186W_aa_OsloMethod/analysis_rndpeak_after_prompt/EB06_RMI0.85/rhopaw.cnt");

    // Random subtraction before the prompt peak
    ifstream rhopaw_rdp_before("../186W_aa_OsloMethod/analysis_rndpeak_before_prompt/EB06_RMI0.85/rhopaw.cnt");

    // Declaring vectors, variables etc
    double levels[40],rho[40],rhoerr[40],energy[448],energyerr[448],fermigas[448];
    double rho_rdp_after[40],rhoerr_rdp_after[40];
    double rho_rdp_before[40],rhoerr_rdp_before[40];

    double Bn[1]={7.192200};
    double Bnerr[1]={0.001};
    double rho_Bn[1]={2652000.000000};
    double rho_Bnerrup[1]={976700.000000}; // 3.6287E+06 (from RMI*1+dRMI*1) -2.652E+06 (from the reference calc).
    double rho_Bnerrdown[1]={823800.000000}; // 2.652E+06 (from the reference calc.) - 1.8282E+06(from RMI*0.7-dRMI*0.7) 
    
    int i = 0;
    double a0 =  -1.1170;
    double a1 =   0.2238;
    double x,y,z;

    // Histogram for known, discrete levels - nicer than a TGraph...
    TH1F *h_level = new TH1F("h_level"," ",40,a0 + (a1/2.),a0 + (a1/2.) + a1*40);

    // Read files
    i = 0;
    while(fermi){ // Actually not Fermi gas - this is the CT model extrapolation
     fermi >> x;
     fermigas[i]=x;
     energy[i]=a0+(a1*i);
     energyerr[i]=0.0;
       i++;
    }
    fermi.close();
    
    i=0;
    while(rhopaw){ // Oslo data, reference normalization
     rhopaw >> y;
     if(i<39){
         rho[i]=y;
     }
     else{rhoerr[i-39]=y;}
     i++;
    }
    rhopaw.close();
    
     i=0;
     while(rholev){// Known levels
         rholev >> z;
         levels[i]=z;
       h_level->SetBinContent(i,z);
         i++;
    }
    rholev.close();

    i=0;
    while(rhopaw_rdp_after){ // Oslo data, random subtraction one peak after the prompt
       rhopaw_rdp_after >> y;
       if(i<39){
          rho_rdp_after[i]=y;
       }
       else{rhoerr_rdp_after[i-39]=y;}
       i++;
    }
    rhopaw_rdp_after.close();
    
    i=0;
    while(rhopaw_rdp_before){ // Oslo data, random subtraction one peak before the prompt
       rhopaw_rdp_before >> y;
       if(i<39){
          rho_rdp_before[i]=y;
       }
       else{rhoerr_rdp_before[i-39]=y;}
       i++;
    }
    rhopaw_rdp_before.close();

    // Make graphs and histogram for plotting nice axes
    TGraphErrors *rhoexp = new TGraphErrors(33,energy,rho,energyerr,rhoerr);
    TGraphErrors *rhoexp_rdp_after = new TGraphErrors(33,energy,rho_rdp_after,energyerr,rhoerr_rdp_after);
    TGraphErrors *rhoexp_rdp_before = new TGraphErrors(33,energy,rho_rdp_before,energyerr,rhoerr_rdp_before);
    TH2F *h = new TH2F("h"," ",100,-0.437248,7.167836,100,0.708400,2012000.000000);

    c1->cd(2);
    gPad->SetGrid(0,0);
    gPad->SetLogy();
    gPad->SetLeftMargin(0.14);
    gPad->SetBottomMargin(0.13);
    gPad->SetRightMargin(0.01);
    gPad->SetTopMargin(0.02);
    //h->GetXaxis()->CenterTitle();
    h->GetXaxis()->SetTitleFont(42);
    h->GetXaxis()->SetLabelFont(42);
    h->GetXaxis()->SetTitleSize(0.05);
    h->GetXaxis()->SetLabelSize(0.045);
    h->GetXaxis()->SetTitleOffset(1.);
    h->GetXaxis()->SetTitle("E_{x} (MeV)");
    //h->GetYaxis()->CenterTitle();
    h->GetYaxis()->SetTitleFont(42);
    h->GetYaxis()->SetLabelFont(42);
    h->GetYaxis()->SetTitleSize(0.05);
    h->GetYaxis()->SetLabelSize(0.045);
    h->GetYaxis()->SetTitleOffset(1.4);
    h->GetYaxis()->SetTitle("#rho (E_{x}) (MeV^{-1})");
    h->Draw();
    
    h_level->SetLineColor(kGray+2);
    h_level->Draw("same");
    
    rhoexp->SetMarkerStyle(21);   
    rhoexp->SetMarkerSize(0.6);
    rhoexp->Draw("P");
    
    rhoexp_rdp_after->SetMarkerStyle(25);
    rhoexp_rdp_after->SetMarkerSize(0.7);
    //rhoexp_rdp_after->SetMarkerColor(kPink+10);
    //rhoexp_rdp_after->SetLineColor(kPink+10);
    rhoexp_rdp_after->Draw("p");

    rhoexp_rdp_before->SetMarkerStyle(2);
    rhoexp_rdp_before->SetMarkerColor(kBlue+1);
    rhoexp_rdp_before->SetLineColor(kBlue+1);
    rhoexp_rdp_before->Draw("p");
    
    TLegend *leg = new TLegend(0.19,0.66,0.60,0.91);
    leg->SetBorderSize(0);
    leg->SetFillColor(0);
    leg->SetTextFont(42);
    leg->SetTextSize(0.035);
    leg->AddEntry(rhoexp," prompt-random1 ","P");
    leg->AddEntry(rhoexp_rdp_after," prompt-random2 ","P");
    leg->AddEntry(rhoexp_rdp_before," prompt-random3 ","P");
    leg->AddEntry(h_level," Known levels ","L");
    leg->Draw();

    t.DrawLatex(0.25,7.E+05,"(b)");


    // Now, grabbing the gamma strength for the three different random-subtraction gates
    // Read input files. Again, the reference calculation ("base line") is 
    // EB06_RMI0.85 for the time gate with random subtraction two peaks after the prompt peak
    ifstream strengthfile("../186W_aa_OsloMethod/analysis_rndpeak_twoafter_prompt/EB06_RMI0.85/strength.nrm");

    // Random subtraction after the prompt peak
    ifstream strengthfile_rdp_after("../186W_aa_OsloMethod/analysis_rndpeak_after_prompt/EB06_RMI0.85/strength.nrm");
    
    // Random subtraction before the prompt peak
    ifstream strengthfile_rdp_before("../186W_aa_OsloMethod/analysis_rndpeak_before_prompt/EB06_RMI0.85/strength.nrm");

    double strength[40],strengtherr[40];
    double strength_rdp_after[40],strengtherr_rdp_after[40];
    double strength_rdp_before[40],strengtherr_rdp_before[40];

    // Read files. 
    // EB06_RMI0.85 - reference case
    i=0;
    while(strengthfile){
        strengthfile >> x;
        if(i<39){
            strength[i] = x;
        }   
        else{strengtherr[i-39] = x;}
        i++;
    }
    strengthfile.close();

    // EB06_RMI0.85, random subtraction one peak after the prompt
    i=0;
    while(strengthfile_rdp_after){
        strengthfile_rdp_after >> x;
        if(i<39){
            strength_rdp_after[i] = x;
        }   
        else{strengtherr_rdp_after[i-39] = x;}
        i++;
    }
    strengthfile_rdp_after.close();

    // EB06_RMI0.85, random subtraction one peak before the prompt
    i=0;
    while(strengthfile_rdp_before){
        strengthfile_rdp_before >> x;
        if(i<39){
            strength_rdp_before[i] = x;
        }   
        else{strengtherr_rdp_before[i-39] = x;}
        i++;
    }
    strengthfile_rdp_before.close();


    // Make graphs
    TGraphErrors *strengthexp = new TGraphErrors(39,energy,strength,energyerr,strengtherr);
    TGraphErrors *strengthexp_rdp_after = new TGraphErrors(39,energy,strength_rdp_after,energyerr,strengtherr_rdp_after);
    TGraphErrors *strengthexp_rdp_before = new TGraphErrors(39,energy,strength_rdp_before,energyerr,strengtherr_rdp_before);

    TH2F *h2 = new TH2F("h2"," ",10,0.0,   7.888,10,1.449e-09,1.432e-05);
    
    c1->cd(3);
    gPad->SetGrid(0,0);
    gPad->SetLogy();
    gPad->SetLeftMargin(0.15);
    gPad->SetBottomMargin(0.13);
    gPad->SetRightMargin(0.005);
    gPad->SetTopMargin(0.02);

    //h2->GetXaxis()->CenterTitle();
    h2->GetXaxis()->SetTitleOffset(1.1);
    h2->GetXaxis()->SetTitle("#gamma-ray energy E_{#gamma} (MeV)");
    h2->GetXaxis()->SetTitleFont(42);
    h2->GetXaxis()->SetLabelFont(42);
    h2->GetXaxis()->SetTitleSize(0.048);
    h2->GetXaxis()->SetLabelSize(0.045);
    //h2->GetYaxis()->CenterTitle();
    h2->GetYaxis()->SetTitleOffset(1.4);
    h2->GetYaxis()->SetTitleFont(42);
    h2->GetYaxis()->SetLabelFont(42);
    h2->GetYaxis()->SetTitleSize(0.048);
    h2->GetYaxis()->SetLabelSize(0.045);
    h2->GetYaxis()->SetTitle("#gamma-ray strength function f(E_{#gamma}) (MeV^{-3})");
    h2->Draw();

    strengthexp->SetMarkerStyle(21);
    strengthexp->SetMarkerSize(0.6);
    strengthexp->Draw("P");

    strengthexp_rdp_after->SetMarkerStyle(25);
    strengthexp_rdp_after->SetMarkerSize(0.7);
    //strengthexp_rdp_after->SetMarkerColor(kPink+10);
    //strengthexp_rdp_after->SetLineColor(kPink+10);
    strengthexp_rdp_after->Draw("p");

    strengthexp_rdp_before->SetMarkerStyle(2);
    strengthexp_rdp_before->SetMarkerColor(kBlue+1);
    strengthexp_rdp_before->SetLineColor(kBlue+1);
    strengthexp_rdp_before->Draw("p");

    TLegend *leg2 = new TLegend(0.19,0.72,0.60,0.91);
    leg2->SetBorderSize(0);
    leg2->SetFillColor(0);
    leg2->SetTextFont(42);
    leg2->SetTextSize(0.035);
    leg2->AddEntry(strengthexp," prompt-random1 ","P");
    leg2->AddEntry(strengthexp_rdp_after," prompt-random2 ","P");
    leg2->AddEntry(strengthexp_rdp_before," prompt-random3 ","P");
    leg2->Draw();

    t.DrawLatex(0.64,7.E-06,"(c)");

    c1->Print("timegates_nld_gsf.pdf");
    c1->Print("timegates_nld_gsf.eps");
    c1->Print("timegates_nld_gsf.png");



}
