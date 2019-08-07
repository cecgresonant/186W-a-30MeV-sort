// Script to compare all h_ede_bXfX ring by ring to check the calibration
// Cecilie, July 31, 2019

#include <fstream>
#include <iostream>

void h_ede_comp_186W_aa(){
    // No stats or titles shown
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    // Grab data file for 186W(a,a')
    TFile *file = TFile::Open("offline_186W_aa.root");

    // Back detector 0
	TH2D *h_ede_b0f0  = (TH2D*)file->Get("h_ede_b0f0"); // Delta E + E histogram for b0f0
    TH2D *h_ede_b0f1  = (TH2D*)file->Get("h_ede_b0f1"); // Delta E + E histogram for b0f1
    TH2D *h_ede_b0f2  = (TH2D*)file->Get("h_ede_b0f2"); // Delta E + E histogram for b0f2
    TH2D *h_ede_b0f3  = (TH2D*)file->Get("h_ede_b0f3"); // Delta E + E histogram for b0f3
    TH2D *h_ede_b0f4  = (TH2D*)file->Get("h_ede_b0f4"); // Delta E + E histogram for b0f4
    TH2D *h_ede_b0f5  = (TH2D*)file->Get("h_ede_b0f5"); // Delta E + E histogram for b0f5
    TH2D *h_ede_b0f6  = (TH2D*)file->Get("h_ede_b0f6"); // Delta E + E histogram for b0f6
    TH2D *h_ede_b0f7  = (TH2D*)file->Get("h_ede_b0f7"); // Delta E + E histogram for b0f7

    // Back detector 1
    TH2D *h_ede_b1f0  = (TH2D*)file->Get("h_ede_b1f0"); // Delta E + E histogram for b1f0
    TH2D *h_ede_b1f1  = (TH2D*)file->Get("h_ede_b1f1"); // Delta E + E histogram for b1f1
    TH2D *h_ede_b1f2  = (TH2D*)file->Get("h_ede_b1f2"); // Delta E + E histogram for b1f2
    TH2D *h_ede_b1f3  = (TH2D*)file->Get("h_ede_b1f3"); // Delta E + E histogram for b1f3
    TH2D *h_ede_b1f4  = (TH2D*)file->Get("h_ede_b1f4"); // Delta E + E histogram for b1f4
    TH2D *h_ede_b1f5  = (TH2D*)file->Get("h_ede_b1f5"); // Delta E + E histogram for b1f5
    TH2D *h_ede_b1f6  = (TH2D*)file->Get("h_ede_b1f6"); // Delta E + E histogram for b1f6
    TH2D *h_ede_b1f7  = (TH2D*)file->Get("h_ede_b1f7"); // Delta E + E histogram for b1f7

    // Back detector 2
    TH2D *h_ede_b2f0  = (TH2D*)file->Get("h_ede_b2f0"); // Delta E + E histogram for b2f0
    TH2D *h_ede_b2f1  = (TH2D*)file->Get("h_ede_b2f1"); // Delta E + E histogram for b2f1
    TH2D *h_ede_b2f2  = (TH2D*)file->Get("h_ede_b2f2"); // Delta E + E histogram for b2f2
    TH2D *h_ede_b2f3  = (TH2D*)file->Get("h_ede_b2f3"); // Delta E + E histogram for b2f3
    TH2D *h_ede_b2f4  = (TH2D*)file->Get("h_ede_b2f4"); // Delta E + E histogram for b2f4
    TH2D *h_ede_b2f5  = (TH2D*)file->Get("h_ede_b2f5"); // Delta E + E histogram for b2f5
    TH2D *h_ede_b2f6  = (TH2D*)file->Get("h_ede_b2f6"); // Delta E + E histogram for b2f6
    TH2D *h_ede_b2f7  = (TH2D*)file->Get("h_ede_b2f7"); // Delta E + E histogram for b2f7

    // Back detector 3
    TH2D *h_ede_b3f0  = (TH2D*)file->Get("h_ede_b3f0"); // Delta E + E histogram for b3f0
    TH2D *h_ede_b3f1  = (TH2D*)file->Get("h_ede_b3f1"); // Delta E + E histogram for b3f1
    TH2D *h_ede_b3f2  = (TH2D*)file->Get("h_ede_b3f2"); // Delta E + E histogram for b3f2
    TH2D *h_ede_b3f3  = (TH2D*)file->Get("h_ede_b3f3"); // Delta E + E histogram for b3f3
    TH2D *h_ede_b3f4  = (TH2D*)file->Get("h_ede_b3f4"); // Delta E + E histogram for b3f4
    TH2D *h_ede_b3f5  = (TH2D*)file->Get("h_ede_b3f5"); // Delta E + E histogram for b3f5
    TH2D *h_ede_b3f6  = (TH2D*)file->Get("h_ede_b3f6"); // Delta E + E histogram for b3f6
    TH2D *h_ede_b3f7  = (TH2D*)file->Get("h_ede_b3f7"); // Delta E + E histogram for b3f7

    // Back detector 4
    TH2D *h_ede_b4f0  = (TH2D*)file->Get("h_ede_b4f0"); // Delta E + E histogram for b4f0
    TH2D *h_ede_b4f1  = (TH2D*)file->Get("h_ede_b4f1"); // Delta E + E histogram for b4f1
    TH2D *h_ede_b4f2  = (TH2D*)file->Get("h_ede_b4f2"); // Delta E + E histogram for b4f2
    TH2D *h_ede_b4f3  = (TH2D*)file->Get("h_ede_b4f3"); // Delta E + E histogram for b4f3
    TH2D *h_ede_b4f4  = (TH2D*)file->Get("h_ede_b4f4"); // Delta E + E histogram for b4f4
    TH2D *h_ede_b4f5  = (TH2D*)file->Get("h_ede_b4f5"); // Delta E + E histogram for b4f5
    TH2D *h_ede_b4f6  = (TH2D*)file->Get("h_ede_b4f6"); // Delta E + E histogram for b4f6
    TH2D *h_ede_b4f7  = (TH2D*)file->Get("h_ede_b4f7"); // Delta E + E histogram for b4f7

    // Back detector 5
    TH2D *h_ede_b5f0  = (TH2D*)file->Get("h_ede_b5f0"); // Delta E + E histogram for b5f0
    TH2D *h_ede_b5f1  = (TH2D*)file->Get("h_ede_b5f1"); // Delta E + E histogram for b5f1
    TH2D *h_ede_b5f2  = (TH2D*)file->Get("h_ede_b5f2"); // Delta E + E histogram for b5f2
    TH2D *h_ede_b5f3  = (TH2D*)file->Get("h_ede_b5f3"); // Delta E + E histogram for b5f3
    TH2D *h_ede_b5f4  = (TH2D*)file->Get("h_ede_b5f4"); // Delta E + E histogram for b5f4
    TH2D *h_ede_b5f5  = (TH2D*)file->Get("h_ede_b5f5"); // Delta E + E histogram for b5f5
    TH2D *h_ede_b5f6  = (TH2D*)file->Get("h_ede_b5f6"); // Delta E + E histogram for b5f6
    TH2D *h_ede_b5f7  = (TH2D*)file->Get("h_ede_b5f7"); // Delta E + E histogram for b5f7

    // Back detector 6
    TH2D *h_ede_b6f0  = (TH2D*)file->Get("h_ede_b6f0"); // Delta E + E histogram for b6f0
    TH2D *h_ede_b6f1  = (TH2D*)file->Get("h_ede_b6f1"); // Delta E + E histogram for b6f1
    TH2D *h_ede_b6f2  = (TH2D*)file->Get("h_ede_b6f2"); // Delta E + E histogram for b6f2
    TH2D *h_ede_b6f3  = (TH2D*)file->Get("h_ede_b6f3"); // Delta E + E histogram for b6f3
    TH2D *h_ede_b6f4  = (TH2D*)file->Get("h_ede_b6f4"); // Delta E + E histogram for b6f4
    TH2D *h_ede_b6f5  = (TH2D*)file->Get("h_ede_b6f5"); // Delta E + E histogram for b6f5
    TH2D *h_ede_b6f6  = (TH2D*)file->Get("h_ede_b6f6"); // Delta E + E histogram for b6f6
    TH2D *h_ede_b6f7  = (TH2D*)file->Get("h_ede_b6f7"); // Delta E + E histogram for b6f7

    // Back detector 7
    TH2D *h_ede_b7f0  = (TH2D*)file->Get("h_ede_b7f0"); // Delta E + E histogram for b7f0
    TH2D *h_ede_b7f1  = (TH2D*)file->Get("h_ede_b7f1"); // Delta E + E histogram for b7f1
    TH2D *h_ede_b7f2  = (TH2D*)file->Get("h_ede_b7f2"); // Delta E + E histogram for b7f2
    TH2D *h_ede_b7f3  = (TH2D*)file->Get("h_ede_b7f3"); // Delta E + E histogram for b7f3
    TH2D *h_ede_b7f4  = (TH2D*)file->Get("h_ede_b7f4"); // Delta E + E histogram for b7f4
    TH2D *h_ede_b7f5  = (TH2D*)file->Get("h_ede_b7f5"); // Delta E + E histogram for b7f5
    TH2D *h_ede_b7f6  = (TH2D*)file->Get("h_ede_b7f6"); // Delta E + E histogram for b7f6
    TH2D *h_ede_b7f7  = (TH2D*)file->Get("h_ede_b7f7"); // Delta E + E histogram for b7f7

    double centroid_Qkinz_f0 = 27256;
    double centroid_Qkinz_f1 = 27285;
    double centroid_Qkinz_f2 = 27315;
    double centroid_Qkinz_f3 = 27345;
    double centroid_Qkinz_f4 = 27375;
    double centroid_Qkinz_f5 = 27406;
    double centroid_Qkinz_f6 = 27437;
    double centroid_Qkinz_f7 = 27468;

    ///////////////////////////
    // Ring f0 = 140 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f0 = 140 degrees: " << endl;
    // Make canvas to plot the histograms
    TCanvas *c1 = new TCanvas("c1","c1:f0 histograms",1000,700);
    c1->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f0->Rebin(2);
    h_ede_b0f0->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f0->GetYaxis()->SetRangeUser(1,4000);
    h_ede_b0f0->GetYaxis()->SetTitle("counts");
    h_ede_b0f0->Draw();
    h_ede_b0f0->Fit("gaus","","",27000,27900);
    TF1 *fit = (TF1*)h_ede_b0f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b0f0 = fit->GetParameter(1);
    h_ede_b0f0->GetFunction("gaus")->Delete();

    h_ede_b1f0->Rebin(2);
    h_ede_b1f0->SetLineColor(kMagenta);
    h_ede_b1f0->Draw("same");
    h_ede_b1f0->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b1f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b1f0 = fit->GetParameter(1);
    h_ede_b1f0->GetFunction("gaus")->Delete();
   
    h_ede_b2f0->Rebin(2);
    h_ede_b2f0->SetLineColor(kGreen);
    h_ede_b2f0->Draw("same");
    h_ede_b2f0->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b2f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f0 = fit->GetParameter(1);
    h_ede_b2f0->GetFunction("gaus")->Delete();

    h_ede_b3f0->Rebin(2);
    h_ede_b3f0->SetLineColor(kCyan+1);
    h_ede_b3f0->Draw("same");
    h_ede_b3f0->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b3f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f0 = fit->GetParameter(1);
    h_ede_b3f0->GetFunction("gaus")->Delete();

    h_ede_b4f0->Rebin(2);
    h_ede_b4f0->SetLineColor(kBlue);
    h_ede_b4f0->Draw("same");
    h_ede_b4f0->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b4f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f0 = fit->GetParameter(1);
    h_ede_b4f0->GetFunction("gaus")->Delete();

    h_ede_b5f0->Rebin(2);
    h_ede_b5f0->SetLineColor(kPink+10);
    h_ede_b5f0->Draw("same");
    h_ede_b5f0->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b5f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f0 = fit->GetParameter(1);
    h_ede_b5f0->GetFunction("gaus")->Delete();    

    h_ede_b6f0->Rebin(2);
    h_ede_b6f0->SetLineColor(kYellow+1);
    h_ede_b6f0->Draw("same");
    h_ede_b6f0->Fit("gaus","","",27000,27900);    
    fit = (TF1*)h_ede_b6f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f0 = fit->GetParameter(1);
    h_ede_b6f0->GetFunction("gaus")->Delete();    


    h_ede_b7f0->Rebin(2);
    h_ede_b7f0->SetLineColor(kRed);
    h_ede_b7f0->Draw("same");
    h_ede_b7f0->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b7f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f0 = fit->GetParameter(1);
    h_ede_b7f0->GetFunction("gaus")->Delete();    

    TLegend *leg_f0 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f0->SetBorderSize(0);
    leg_f0->SetFillColor(0);
    leg_f0->SetTextFont(42);
    leg_f0->SetTextSize(0.03);
    leg_f0->AddEntry(h_ede_b0f0," h_ede_b0f0 ","L");
    leg_f0->AddEntry(h_ede_b1f0," h_ede_b1f0 ","L");
    leg_f0->AddEntry(h_ede_b2f0," h_ede_b2f0 ","L");
    leg_f0->AddEntry(h_ede_b3f0," h_ede_b3f0 ","L");
    leg_f0->AddEntry(h_ede_b4f0," h_ede_b4f0 ","L");
    leg_f0->AddEntry(h_ede_b5f0," h_ede_b5f0 ","L");
    leg_f0->AddEntry(h_ede_b6f0," h_ede_b6f0 ","L");
    leg_f0->AddEntry(h_ede_b7f0," h_ede_b7f0 ","L");
    leg_f0->Draw();

    c1->Update();
    //c1->Print("h_ede_f0.png");

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f0: " << endl;
    cout << " b0f0: " << centroid_Qkinz_f0-centroid_b0f0 << " keV " << endl;
    cout << " b1f0: " << centroid_Qkinz_f0-centroid_b1f0 << " keV " << endl;
    cout << " b2f0: " << centroid_Qkinz_f0-centroid_b2f0 << " keV " << endl;
    cout << " b3f0: " << centroid_Qkinz_f0-centroid_b3f0 << " keV " << endl;
    cout << " b4f0: " << centroid_Qkinz_f0-centroid_b4f0 << " keV " << endl;
    cout << " b5f0: " << centroid_Qkinz_f0-centroid_b5f0 << " keV " << endl;
    cout << " b6f0: " << centroid_Qkinz_f0-centroid_b6f0 << " keV " << endl;
    cout << " b7f0: " << centroid_Qkinz_f0-centroid_b7f0 << " keV " << endl;


    ///////////////////////////
    // Ring f1 = 138 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f1 = 138 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c2 = new TCanvas("c2","c2:f1 histograms",1000,700);
    c2->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f1->Rebin(2);
    h_ede_b0f1->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f1->GetYaxis()->SetRangeUser(1,5000);
    h_ede_b0f1->GetYaxis()->SetTitle("counts");
    h_ede_b0f1->Draw();
    h_ede_b0f1->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b0f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b0f1 = fit->GetParameter(1);
    h_ede_b0f1->GetFunction("gaus")->Delete();



    h_ede_b1f1->Rebin(2);
    h_ede_b1f1->SetLineColor(kMagenta);
    h_ede_b1f1->Draw("same");
    h_ede_b1f1->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b1f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b1f1 = fit->GetParameter(1);
    h_ede_b1f1->GetFunction("gaus")->Delete();
   
    h_ede_b2f1->Rebin(2);
    h_ede_b2f1->SetLineColor(kGreen);
    h_ede_b2f1->Draw("same");
    h_ede_b2f1->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b2f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f1 = fit->GetParameter(1);
    h_ede_b2f1->GetFunction("gaus")->Delete();

    h_ede_b3f1->Rebin(2);
    h_ede_b3f1->SetLineColor(kCyan+1);
    h_ede_b3f1->Draw("same");
    h_ede_b3f1->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b3f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f1 = fit->GetParameter(1);
    h_ede_b3f1->GetFunction("gaus")->Delete();

    h_ede_b4f1->Rebin(2);
    h_ede_b4f1->SetLineColor(kBlue);
    h_ede_b4f1->Draw("same");
    h_ede_b4f1->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b4f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f1 = fit->GetParameter(1);
    h_ede_b4f1->GetFunction("gaus")->Delete();

    h_ede_b5f1->Rebin(2);
    h_ede_b5f1->SetLineColor(kPink+10);
    h_ede_b5f1->Draw("same");
    h_ede_b5f1->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b5f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f1 = fit->GetParameter(1);
    h_ede_b5f1->GetFunction("gaus")->Delete();    

    h_ede_b6f1->Rebin(2);
    h_ede_b6f1->SetLineColor(kYellow+1);
    h_ede_b6f1->Draw("same");
    h_ede_b6f1->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b6f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f1 = fit->GetParameter(1);
    h_ede_b6f1->GetFunction("gaus")->Delete();    


    h_ede_b7f1->Rebin(2);
    h_ede_b7f1->SetLineColor(kRed);
    h_ede_b7f1->Draw("same");
    h_ede_b7f1->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b7f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f1 = fit->GetParameter(1);
    h_ede_b7f1->GetFunction("gaus")->Delete();    

    TLegend *leg_f1 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f1->SetBorderSize(0);
    leg_f1->SetFillColor(0);
    leg_f1->SetTextFont(42);
    leg_f1->SetTextSize(0.03);
    leg_f1->AddEntry(h_ede_b0f1," h_ede_b0f1 ","L");
    leg_f1->AddEntry(h_ede_b1f1," h_ede_b1f1 ","L");
    leg_f1->AddEntry(h_ede_b2f1," h_ede_b2f1 ","L");
    leg_f1->AddEntry(h_ede_b3f1," h_ede_b3f1 ","L");
    leg_f1->AddEntry(h_ede_b4f1," h_ede_b4f1 ","L");
    leg_f1->AddEntry(h_ede_b5f1," h_ede_b5f1 ","L");
    leg_f1->AddEntry(h_ede_b6f1," h_ede_b6f1 ","L");
    leg_f1->AddEntry(h_ede_b7f1," h_ede_b7f1 ","L");
    leg_f1->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f1: " << endl;
    cout << " b0f1: " << centroid_Qkinz_f1-centroid_b0f1 << " keV " << endl;
    cout << " b1f1: " << centroid_Qkinz_f1-centroid_b1f1 << " keV " << endl;
    cout << " b2f1: " << centroid_Qkinz_f1-centroid_b2f1 << " keV " << endl;
    cout << " b3f1: " << centroid_Qkinz_f1-centroid_b3f1 << " keV " << endl;
    cout << " b4f1: " << centroid_Qkinz_f1-centroid_b4f1 << " keV " << endl;
    cout << " b5f1: " << centroid_Qkinz_f1-centroid_b5f1 << " keV " << endl;
    cout << " b6f1: " << centroid_Qkinz_f1-centroid_b6f1 << " keV " << endl;
    cout << " b7f1: " << centroid_Qkinz_f1-centroid_b7f1 << " keV " << endl;


    ///////////////////////////
    // Ring f2 = 136 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f2 = 136 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c3 = new TCanvas("c3","c3:f2 histograms",1000,700);
    c3->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f2->Rebin(2);
    h_ede_b0f2->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f2->GetYaxis()->SetRangeUser(1,6000);
    h_ede_b0f2->GetYaxis()->SetTitle("counts");
    h_ede_b0f2->Draw();
    h_ede_b0f2->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b0f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b0f2 = fit->GetParameter(1);
    h_ede_b0f2->GetFunction("gaus")->Delete();


    h_ede_b1f2->Rebin(2);
    h_ede_b1f2->SetLineColor(kMagenta);
    h_ede_b1f2->Draw("same");
    h_ede_b1f2->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b1f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b1f2 = fit->GetParameter(1);
    h_ede_b1f2->GetFunction("gaus")->Delete();
   
    h_ede_b2f2->Rebin(2);
    h_ede_b2f2->SetLineColor(kGreen);
    h_ede_b2f2->Draw("same");
    h_ede_b2f2->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b2f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f2 = fit->GetParameter(1);
    h_ede_b2f2->GetFunction("gaus")->Delete();

    h_ede_b3f2->Rebin(2);
    h_ede_b3f2->SetLineColor(kCyan+1);
    h_ede_b3f2->Draw("same");
    h_ede_b3f2->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b3f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f2 = fit->GetParameter(1);
    h_ede_b3f2->GetFunction("gaus")->Delete();

    h_ede_b4f2->Rebin(2);
    h_ede_b4f2->SetLineColor(kBlue);
    h_ede_b4f2->Draw("same");
    h_ede_b4f2->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b4f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f2 = fit->GetParameter(1);
    h_ede_b4f2->GetFunction("gaus")->Delete();

    h_ede_b5f2->Rebin(2);
    h_ede_b5f2->SetLineColor(kPink+10);
    h_ede_b5f2->Draw("same");
    h_ede_b5f2->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b5f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f2 = fit->GetParameter(1);
    h_ede_b5f2->GetFunction("gaus")->Delete();    

    h_ede_b6f2->Rebin(2);
    h_ede_b6f2->SetLineColor(kYellow+1);
    h_ede_b6f2->Draw("same");
    h_ede_b6f2->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b6f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f2 = fit->GetParameter(1);
    h_ede_b6f2->GetFunction("gaus")->Delete();    


    h_ede_b7f2->Rebin(2);
    h_ede_b7f2->SetLineColor(kRed);
    h_ede_b7f2->Draw("same");
    h_ede_b7f2->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b7f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f2 = fit->GetParameter(1);
    h_ede_b7f2->GetFunction("gaus")->Delete();    

    TLegend *leg_f2 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f2->SetBorderSize(0);
    leg_f2->SetFillColor(0);
    leg_f2->SetTextFont(42);
    leg_f2->SetTextSize(0.03);
    leg_f2->AddEntry(h_ede_b0f2," h_ede_b0f2 ","L");
    leg_f2->AddEntry(h_ede_b1f2," h_ede_b1f2 ","L");
    leg_f2->AddEntry(h_ede_b2f2," h_ede_b2f2 ","L");
    leg_f2->AddEntry(h_ede_b3f2," h_ede_b3f2 ","L");
    leg_f2->AddEntry(h_ede_b4f2," h_ede_b4f2 ","L");
    leg_f2->AddEntry(h_ede_b5f2," h_ede_b5f2 ","L");
    leg_f2->AddEntry(h_ede_b6f2," h_ede_b6f2 ","L");
    leg_f2->AddEntry(h_ede_b7f2," h_ede_b7f2 ","L");
    leg_f2->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f2: " << endl;
    cout << " b0f2: " << centroid_Qkinz_f2-centroid_b0f2 << " keV " << endl;
    cout << " b1f2: " << centroid_Qkinz_f2-centroid_b1f2 << " keV " << endl;
    cout << " b2f2: " << centroid_Qkinz_f2-centroid_b2f2 << " keV " << endl;
    cout << " b3f2: " << centroid_Qkinz_f2-centroid_b3f2 << " keV " << endl;
    cout << " b4f2: " << centroid_Qkinz_f2-centroid_b4f2 << " keV " << endl;
    cout << " b5f2: " << centroid_Qkinz_f2-centroid_b5f2 << " keV " << endl;
    cout << " b6f2: " << centroid_Qkinz_f2-centroid_b6f2 << " keV " << endl;
    cout << " b7f2: " << centroid_Qkinz_f2-centroid_b7f2 << " keV " << endl;


    ///////////////////////////
    // Ring f3 = 134 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f3 = 134 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c4 = new TCanvas("c4","c4:f3 histograms",1000,700);
    c4->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f3->Rebin(2);
    h_ede_b0f3->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f3->GetYaxis()->SetRangeUser(1,7000);
    h_ede_b0f3->GetYaxis()->SetTitle("counts");
    h_ede_b0f3->Draw();
    h_ede_b0f3->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b0f3->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b0f3 = fit->GetParameter(1);
    h_ede_b0f3->GetFunction("gaus")->Delete();


    h_ede_b1f3->Rebin(2);
    h_ede_b1f3->SetLineColor(kMagenta);
    h_ede_b1f3->Draw("same");
    h_ede_b1f3->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b1f3->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b1f3 = fit->GetParameter(1);
    h_ede_b1f3->GetFunction("gaus")->Delete();
   
    h_ede_b2f3->Rebin(2);
    h_ede_b2f3->SetLineColor(kGreen);
    h_ede_b2f3->Draw("same");
    h_ede_b2f3->Fit("gaus","","",27100,27900);
    fit = (TF1*)h_ede_b2f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f3 = fit->GetParameter(1);
    h_ede_b2f3->GetFunction("gaus")->Delete();

    h_ede_b3f3->Rebin(2);
    h_ede_b3f3->SetLineColor(kCyan+1);
    h_ede_b3f3->Draw("same");
    h_ede_b3f3->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b3f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f3 = fit->GetParameter(1);
    h_ede_b3f3->GetFunction("gaus")->Delete();

    h_ede_b4f3->Rebin(2);
    h_ede_b4f3->SetLineColor(kBlue);
    h_ede_b4f3->Draw("same");
    h_ede_b4f3->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b4f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f3 = fit->GetParameter(1);
    h_ede_b4f3->GetFunction("gaus")->Delete();

    h_ede_b5f3->Rebin(2);
    h_ede_b5f3->SetLineColor(kPink+10);
    h_ede_b5f3->Draw("same");
    h_ede_b5f3->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b5f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f3 = fit->GetParameter(1);
    h_ede_b5f3->GetFunction("gaus")->Delete();    

    h_ede_b6f3->Rebin(2);
    h_ede_b6f3->SetLineColor(kYellow+1);
    h_ede_b6f3->Draw("same");
    h_ede_b6f3->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b6f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f3 = fit->GetParameter(1);
    h_ede_b6f3->GetFunction("gaus")->Delete();    


    h_ede_b7f3->Rebin(2);
    h_ede_b7f3->SetLineColor(kRed);
    h_ede_b7f3->Draw("same");
    h_ede_b7f3->Fit("gaus","","",27100,27900);    
    fit = (TF1*)h_ede_b7f3->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f3 = fit->GetParameter(1);
    h_ede_b7f3->GetFunction("gaus")->Delete();    

    TLegend *leg_f3 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f3->SetBorderSize(0);
    leg_f3->SetFillColor(0);
    leg_f3->SetTextFont(42);
    leg_f3->SetTextSize(0.03);
    leg_f3->AddEntry(h_ede_b0f3," h_ede_b0f3 ","L");
    leg_f3->AddEntry(h_ede_b1f3," h_ede_b1f3 ","L");
    leg_f3->AddEntry(h_ede_b2f3," h_ede_b2f3 ","L");
    leg_f3->AddEntry(h_ede_b3f3," h_ede_b3f3 ","L");
    leg_f3->AddEntry(h_ede_b4f3," h_ede_b4f3 ","L");
    leg_f3->AddEntry(h_ede_b5f3," h_ede_b5f3 ","L");
    leg_f3->AddEntry(h_ede_b6f3," h_ede_b6f3 ","L");
    leg_f3->AddEntry(h_ede_b7f3," h_ede_b7f3 ","L");
    leg_f3->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f3: " << endl;
    cout << " b0f3: " << centroid_Qkinz_f3-centroid_b0f3 << " keV " << endl;
    cout << " b1f3: " << centroid_Qkinz_f3-centroid_b1f3 << " keV " << endl;
    cout << " b2f3: " << centroid_Qkinz_f3-centroid_b2f3 << " keV " << endl;
    cout << " b3f3: " << centroid_Qkinz_f3-centroid_b3f3 << " keV " << endl;
    cout << " b4f3: " << centroid_Qkinz_f3-centroid_b4f3 << " keV " << endl;
    cout << " b5f3: " << centroid_Qkinz_f3-centroid_b5f3 << " keV " << endl;
    cout << " b6f3: " << centroid_Qkinz_f3-centroid_b6f3 << " keV " << endl;
    cout << " b7f3: " << centroid_Qkinz_f3-centroid_b7f3 << " keV " << endl;


    ///////////////////////////
    // Ring f4 = 132 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f4 = 132 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c5 = new TCanvas("c5","c5:f4 histograms",1000,700);
    c5->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f4->Rebin(2);
    h_ede_b0f4->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f4->GetYaxis()->SetRangeUser(1,8000);
    h_ede_b0f4->GetYaxis()->SetTitle("counts");
    h_ede_b0f4->Draw();
    h_ede_b0f4->Fit("gaus","","",27200,28000);
    fit = (TF1*)h_ede_b0f4->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b0f4 = fit->GetParameter(1);
    h_ede_b0f4->GetFunction("gaus")->Delete();


    h_ede_b1f4->Rebin(2);
    h_ede_b1f4->SetLineColor(kMagenta);
    h_ede_b1f4->Draw("same");
    h_ede_b1f4->Fit("gaus","","",27200,28000);
    fit = (TF1*)h_ede_b1f4->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b1f4 = fit->GetParameter(1);
    h_ede_b1f4->GetFunction("gaus")->Delete();
   
    h_ede_b2f4->Rebin(2);
    h_ede_b2f4->SetLineColor(kGreen);
    h_ede_b2f4->Draw("same");
    h_ede_b2f4->Fit("gaus","","",27200,28000);
    fit = (TF1*)h_ede_b2f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f4 = fit->GetParameter(1);
    h_ede_b2f4->GetFunction("gaus")->Delete();

    h_ede_b3f4->Rebin(2);
    h_ede_b3f4->SetLineColor(kCyan+1);
    h_ede_b3f4->Draw("same");
    h_ede_b3f4->Fit("gaus","","",27200,28000);    
    fit = (TF1*)h_ede_b3f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f4 = fit->GetParameter(1);
    h_ede_b3f4->GetFunction("gaus")->Delete();

    h_ede_b4f4->Rebin(2);
    h_ede_b4f4->SetLineColor(kBlue);
    h_ede_b4f4->Draw("same");
    h_ede_b4f4->Fit("gaus","","",27200,28000);    
    fit = (TF1*)h_ede_b4f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f4 = fit->GetParameter(1);
    h_ede_b4f4->GetFunction("gaus")->Delete();

    h_ede_b5f4->Rebin(2);
    h_ede_b5f4->SetLineColor(kPink+10);
    h_ede_b5f4->Draw("same");
    h_ede_b5f4->Fit("gaus","","",27200,28000);    
    fit = (TF1*)h_ede_b5f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f4 = fit->GetParameter(1);
    h_ede_b5f4->GetFunction("gaus")->Delete();    

    h_ede_b6f4->Rebin(2);
    h_ede_b6f4->SetLineColor(kYellow+1);
    h_ede_b6f4->Draw("same");
    h_ede_b6f4->Fit("gaus","","",27200,28000);    
    fit = (TF1*)h_ede_b6f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f4 = fit->GetParameter(1);
    h_ede_b6f4->GetFunction("gaus")->Delete();    


    h_ede_b7f4->Rebin(2);
    h_ede_b7f4->SetLineColor(kRed);
    h_ede_b7f4->Draw("same");
    h_ede_b7f4->Fit("gaus","","",27200,28000);    
    fit = (TF1*)h_ede_b7f4->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f4 = fit->GetParameter(1);
    h_ede_b7f4->GetFunction("gaus")->Delete();    

    TLegend *leg_f4 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f4->SetBorderSize(0);
    leg_f4->SetFillColor(0);
    leg_f4->SetTextFont(42);
    leg_f4->SetTextSize(0.03);
    leg_f4->AddEntry(h_ede_b0f4," h_ede_b0f4 ","L");
    leg_f4->AddEntry(h_ede_b1f4," h_ede_b1f4 ","L");
    leg_f4->AddEntry(h_ede_b2f4," h_ede_b2f4 ","L");
    leg_f4->AddEntry(h_ede_b3f4," h_ede_b3f4 ","L");
    leg_f4->AddEntry(h_ede_b4f4," h_ede_b4f4 ","L");
    leg_f4->AddEntry(h_ede_b5f4," h_ede_b5f4 ","L");
    leg_f4->AddEntry(h_ede_b6f4," h_ede_b6f4 ","L");
    leg_f4->AddEntry(h_ede_b7f4," h_ede_b7f4 ","L");
    leg_f4->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f4: " << endl;
    cout << " b0f4: " << centroid_Qkinz_f4-centroid_b0f4 << " keV " << endl;
    cout << " b1f4: " << centroid_Qkinz_f4-centroid_b1f4 << " keV " << endl;
    cout << " b2f4: " << centroid_Qkinz_f4-centroid_b2f4 << " keV " << endl;
    cout << " b3f4: " << centroid_Qkinz_f4-centroid_b3f4 << " keV " << endl;
    cout << " b4f4: " << centroid_Qkinz_f4-centroid_b4f4 << " keV " << endl;
    cout << " b5f4: " << centroid_Qkinz_f4-centroid_b5f4 << " keV " << endl;
    cout << " b6f4: " << centroid_Qkinz_f4-centroid_b6f4 << " keV " << endl;
    cout << " b7f4: " << centroid_Qkinz_f4-centroid_b7f4 << " keV " << endl;

    ///////////////////////////
    // Ring f5 = 130 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f5 = 130 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c6 = new TCanvas("c6","c6:f5 histograms",1000,700);
    c6->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f5->Rebin(2);
    h_ede_b0f5->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f5->GetYaxis()->SetRangeUser(1,8500);
    h_ede_b0f5->GetYaxis()->SetTitle("counts");
    h_ede_b0f5->Draw();
    h_ede_b0f5->Fit("gaus","","",27200,28200);
    fit = (TF1*)h_ede_b0f5->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b0f5 = fit->GetParameter(1);
    h_ede_b0f5->GetFunction("gaus")->Delete();


    h_ede_b1f5->Rebin(2);
    h_ede_b1f5->SetLineColor(kMagenta);
    h_ede_b1f5->Draw("same");
    h_ede_b1f5->Fit("gaus","","",27200,28200);
    fit = (TF1*)h_ede_b1f5->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b1f5 = fit->GetParameter(1);
    h_ede_b1f5->GetFunction("gaus")->Delete();
   
    h_ede_b2f5->Rebin(2);
    h_ede_b2f5->SetLineColor(kGreen);
    h_ede_b2f5->Draw("same");
    h_ede_b2f5->Fit("gaus","","",27200,28200);
    fit = (TF1*)h_ede_b2f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f5 = fit->GetParameter(1);
    h_ede_b2f5->GetFunction("gaus")->Delete();

    h_ede_b3f5->Rebin(2);
    h_ede_b3f5->SetLineColor(kCyan+1);
    h_ede_b3f5->Draw("same");
    h_ede_b3f5->Fit("gaus","","",27200,28200);    
    fit = (TF1*)h_ede_b3f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f5 = fit->GetParameter(1);
    h_ede_b3f5->GetFunction("gaus")->Delete();

    h_ede_b4f5->Rebin(2);
    h_ede_b4f5->SetLineColor(kBlue);
    h_ede_b4f5->Draw("same");
    h_ede_b4f5->Fit("gaus","","",27200,28200);    
    fit = (TF1*)h_ede_b4f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f5 = fit->GetParameter(1);
    h_ede_b4f5->GetFunction("gaus")->Delete();

    h_ede_b5f5->Rebin(2);
    h_ede_b5f5->SetLineColor(kPink+10);
    h_ede_b5f5->Draw("same");
    h_ede_b5f5->Fit("gaus","","",27200,28200);    
    fit = (TF1*)h_ede_b5f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f5 = fit->GetParameter(1);
    h_ede_b5f5->GetFunction("gaus")->Delete();    

    h_ede_b6f5->Rebin(2);
    h_ede_b6f5->SetLineColor(kYellow+1);
    h_ede_b6f5->Draw("same");
    h_ede_b6f5->Fit("gaus","","",27200,28200);    
    fit = (TF1*)h_ede_b6f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f5 = fit->GetParameter(1);
    h_ede_b6f5->GetFunction("gaus")->Delete();    


    h_ede_b7f5->Rebin(2);
    h_ede_b7f5->SetLineColor(kRed);
    h_ede_b7f5->Draw("same");
    h_ede_b7f5->Fit("gaus","","",27200,28200);    
    fit = (TF1*)h_ede_b7f5->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f5 = fit->GetParameter(1);
    h_ede_b7f5->GetFunction("gaus")->Delete();    

    TLegend *leg_f5 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f5->SetBorderSize(0);
    leg_f5->SetFillColor(0);
    leg_f5->SetTextFont(42);
    leg_f5->SetTextSize(0.03);
    leg_f5->AddEntry(h_ede_b0f5," h_ede_b0f5 ","L");
    leg_f5->AddEntry(h_ede_b1f5," h_ede_b1f5 ","L");
    leg_f5->AddEntry(h_ede_b2f5," h_ede_b2f5 ","L");
    leg_f5->AddEntry(h_ede_b3f5," h_ede_b3f5 ","L");
    leg_f5->AddEntry(h_ede_b4f5," h_ede_b4f5 ","L");
    leg_f5->AddEntry(h_ede_b5f5," h_ede_b5f5 ","L");
    leg_f5->AddEntry(h_ede_b6f5," h_ede_b6f5 ","L");
    leg_f5->AddEntry(h_ede_b7f5," h_ede_b7f5 ","L");
    leg_f5->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f5: " << endl;
    cout << " b0f5: " << centroid_Qkinz_f5-centroid_b0f5 << " keV " << endl;
    cout << " b1f5: " << centroid_Qkinz_f5-centroid_b1f5 << " keV " << endl;
    cout << " b2f5: " << centroid_Qkinz_f5-centroid_b2f5 << " keV " << endl;
    cout << " b3f5: " << centroid_Qkinz_f5-centroid_b3f5 << " keV " << endl;
    cout << " b4f5: " << centroid_Qkinz_f5-centroid_b4f5 << " keV " << endl;
    cout << " b5f5: " << centroid_Qkinz_f5-centroid_b5f5 << " keV " << endl;
    cout << " b6f5: " << centroid_Qkinz_f5-centroid_b6f5 << " keV " << endl;
    cout << " b7f5: " << centroid_Qkinz_f5-centroid_b7f5 << " keV " << endl;


    ///////////////////////////
    // Ring f6 = 128 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f6 = 128 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c7 = new TCanvas("c7","c7:f6 histograms",1000,700);
    c7->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f6->Rebin(2);
    h_ede_b0f6->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f6->GetYaxis()->SetRangeUser(1,9500);
    h_ede_b0f6->GetYaxis()->SetTitle("counts");
    h_ede_b0f6->Draw();
    h_ede_b0f6->Fit("gaus","","",27400,28200);
    fit = (TF1*)h_ede_b0f6->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b0f6 = fit->GetParameter(1);
    h_ede_b0f6->GetFunction("gaus")->Delete();


    h_ede_b1f6->Rebin(2);
    h_ede_b1f6->SetLineColor(kMagenta);
    h_ede_b1f6->Draw("same");
    h_ede_b1f6->Fit("gaus","","",27400,28200);
    fit = (TF1*)h_ede_b1f6->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b1f6 = fit->GetParameter(1);
    h_ede_b1f6->GetFunction("gaus")->Delete();
   
    h_ede_b2f6->Rebin(2);
    h_ede_b2f6->SetLineColor(kGreen);
    h_ede_b2f6->Draw("same");
    h_ede_b2f6->Fit("gaus","","",27300,28200);
    fit = (TF1*)h_ede_b2f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f6 = fit->GetParameter(1);
    h_ede_b2f6->GetFunction("gaus")->Delete();

    h_ede_b3f6->Rebin(2);
    h_ede_b3f6->SetLineColor(kCyan+1);
    h_ede_b3f6->Draw("same");
    h_ede_b3f6->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b3f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f6 = fit->GetParameter(1);
    h_ede_b3f6->GetFunction("gaus")->Delete();

    h_ede_b4f6->Rebin(2);
    h_ede_b4f6->SetLineColor(kBlue);
    h_ede_b4f6->Draw("same");
    h_ede_b4f6->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b4f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f6 = fit->GetParameter(1);
    h_ede_b4f6->GetFunction("gaus")->Delete();

    h_ede_b5f6->Rebin(2);
    h_ede_b5f6->SetLineColor(kPink+10);
    h_ede_b5f6->Draw("same");
    h_ede_b5f6->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b5f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f6 = fit->GetParameter(1);
    h_ede_b5f6->GetFunction("gaus")->Delete();    

    h_ede_b6f6->Rebin(2);
    h_ede_b6f6->SetLineColor(kYellow+1);
    h_ede_b6f6->Draw("same");
    h_ede_b6f6->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b6f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f6 = fit->GetParameter(1);
    h_ede_b6f6->GetFunction("gaus")->Delete();    


    h_ede_b7f6->Rebin(2);
    h_ede_b7f6->SetLineColor(kRed);
    h_ede_b7f6->Draw("same");
    h_ede_b7f6->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b7f6->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f6 = fit->GetParameter(1);
    h_ede_b7f6->GetFunction("gaus")->Delete();    

    TLegend *leg_f6 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f6->SetBorderSize(0);
    leg_f6->SetFillColor(0);
    leg_f6->SetTextFont(42);
    leg_f6->SetTextSize(0.03);
    leg_f6->AddEntry(h_ede_b0f6," h_ede_b0f6 ","L");
    leg_f6->AddEntry(h_ede_b1f6," h_ede_b1f6 ","L");
    leg_f6->AddEntry(h_ede_b2f6," h_ede_b2f6 ","L");
    leg_f6->AddEntry(h_ede_b3f6," h_ede_b3f6 ","L");
    leg_f6->AddEntry(h_ede_b4f6," h_ede_b4f6 ","L");
    leg_f6->AddEntry(h_ede_b5f6," h_ede_b5f6 ","L");
    leg_f6->AddEntry(h_ede_b6f6," h_ede_b6f6 ","L");
    leg_f6->AddEntry(h_ede_b7f6," h_ede_b7f6 ","L");
    leg_f6->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f6: " << endl;
    cout << " b0f6: " << centroid_Qkinz_f6-centroid_b0f6 << " keV " << endl;
    cout << " b1f6: " << centroid_Qkinz_f6-centroid_b1f6 << " keV " << endl;
    cout << " b2f6: " << centroid_Qkinz_f6-centroid_b2f6 << " keV " << endl;
    cout << " b3f6: " << centroid_Qkinz_f6-centroid_b3f6 << " keV " << endl;
    cout << " b4f6: " << centroid_Qkinz_f6-centroid_b4f6 << " keV " << endl;
    cout << " b5f6: " << centroid_Qkinz_f6-centroid_b5f6 << " keV " << endl;
    cout << " b6f6: " << centroid_Qkinz_f6-centroid_b6f6 << " keV " << endl;
    cout << " b7f6: " << centroid_Qkinz_f6-centroid_b7f6 << " keV " << endl;


    ///////////////////////////
    // Ring f7 = 126 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fits of the elastic peak for ring f7 = 126 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c8 = new TCanvas("c8","c8:f7 histograms",1000,700);
    c8->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ede_b0f7->Rebin(2);
    h_ede_b0f7->GetXaxis()->SetRangeUser(12500,29000);
    h_ede_b0f7->GetYaxis()->SetRangeUser(1,9500);
    h_ede_b0f7->GetYaxis()->SetTitle("counts");
    h_ede_b0f7->Draw();
    h_ede_b0f7->Fit("gaus","","",27400,28200);
    fit = (TF1*)h_ede_b0f7->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b0f7 = fit->GetParameter(1);
    h_ede_b0f7->GetFunction("gaus")->Delete();


    h_ede_b1f7->Rebin(2);
    h_ede_b1f7->SetLineColor(kMagenta);
    h_ede_b1f7->Draw("same");
    h_ede_b1f7->Fit("gaus","","",27400,28200);
    fit = (TF1*)h_ede_b1f7->GetListOfFunctions()->FindObject("gaus");
    double   centroid_b1f7 = fit->GetParameter(1);
    h_ede_b1f7->GetFunction("gaus")->Delete();
   
    h_ede_b2f7->Rebin(2);
    h_ede_b2f7->SetLineColor(kGreen);
    h_ede_b2f7->Draw("same");
    h_ede_b2f7->Fit("gaus","","",27300,28200);
    fit = (TF1*)h_ede_b2f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b2f7 = fit->GetParameter(1);
    h_ede_b2f7->GetFunction("gaus")->Delete();

    h_ede_b3f7->Rebin(2);
    h_ede_b3f7->SetLineColor(kCyan+1);
    h_ede_b3f7->Draw("same");
    h_ede_b3f7->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b3f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b3f7 = fit->GetParameter(1);
    h_ede_b3f7->GetFunction("gaus")->Delete();

    h_ede_b4f7->Rebin(2);
    h_ede_b4f7->SetLineColor(kBlue);
    h_ede_b4f7->Draw("same");
    h_ede_b4f7->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b4f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b4f7 = fit->GetParameter(1);
    h_ede_b4f7->GetFunction("gaus")->Delete();

    h_ede_b5f7->Rebin(2);
    h_ede_b5f7->SetLineColor(kPink+10);
    h_ede_b5f7->Draw("same");
    h_ede_b5f7->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b5f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b5f7 = fit->GetParameter(1);
    h_ede_b5f7->GetFunction("gaus")->Delete();    

    h_ede_b6f7->Rebin(2);
    h_ede_b6f7->SetLineColor(kYellow+1);
    h_ede_b6f7->Draw("same");
    h_ede_b6f7->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b6f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b6f7 = fit->GetParameter(1);
    h_ede_b6f7->GetFunction("gaus")->Delete();    


    h_ede_b7f7->Rebin(2);
    h_ede_b7f7->SetLineColor(kRed);
    h_ede_b7f7->Draw("same");
    h_ede_b7f7->Fit("gaus","","",27300,28200);    
    fit = (TF1*)h_ede_b7f7->GetListOfFunctions()->FindObject("gaus");
    double centroid_b7f7 = fit->GetParameter(1);
    h_ede_b7f7->GetFunction("gaus")->Delete();    

    TLegend *leg_f7 = new TLegend(0.2,0.60,0.4,0.9);
    leg_f7->SetBorderSize(0);
    leg_f7->SetFillColor(0);
    leg_f7->SetTextFont(42);
    leg_f7->SetTextSize(0.03);
    leg_f7->AddEntry(h_ede_b0f7," h_ede_b0f7 ","L");
    leg_f7->AddEntry(h_ede_b1f7," h_ede_b1f7 ","L");
    leg_f7->AddEntry(h_ede_b2f7," h_ede_b2f7 ","L");
    leg_f7->AddEntry(h_ede_b3f7," h_ede_b3f7 ","L");
    leg_f7->AddEntry(h_ede_b4f7," h_ede_b4f7 ","L");
    leg_f7->AddEntry(h_ede_b5f7," h_ede_b5f7 ","L");
    leg_f7->AddEntry(h_ede_b6f7," h_ede_b6f7 ","L");
    leg_f7->AddEntry(h_ede_b7f7," h_ede_b7f7 ","L");
    leg_f7->Draw();

    // Calculate difference, could be included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids for f7: " << endl;
    cout << " b0f7: " << centroid_Qkinz_f7-centroid_b0f7 << " keV " << endl;
    cout << " b1f7: " << centroid_Qkinz_f7-centroid_b1f7 << " keV " << endl;
    cout << " b2f7: " << centroid_Qkinz_f7-centroid_b2f7 << " keV " << endl;
    cout << " b3f7: " << centroid_Qkinz_f7-centroid_b3f7 << " keV " << endl;
    cout << " b4f7: " << centroid_Qkinz_f7-centroid_b4f7 << " keV " << endl;
    cout << " b5f7: " << centroid_Qkinz_f7-centroid_b5f7 << " keV " << endl;
    cout << " b6f7: " << centroid_Qkinz_f7-centroid_b6f7 << " keV " << endl;
    cout << " b7f7: " << centroid_Qkinz_f7-centroid_b7f7 << " keV " << endl;

} // End of script
