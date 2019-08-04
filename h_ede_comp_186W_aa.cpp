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
    h_ede_b0f0->Fit("gaus","","",27100,27900);
    h_ede_b0f0->GetFunction("gaus")->Delete();

    h_ede_b1f0->Rebin(2);
    h_ede_b1f0->SetLineColor(kMagenta);
    h_ede_b1f0->Draw("same");
    h_ede_b1f0->Fit("gaus","","",27100,27900);
    h_ede_b1f0->GetFunction("gaus")->Delete();
   
    h_ede_b2f0->Rebin(2);
    h_ede_b2f0->SetLineColor(kGreen);
    h_ede_b2f0->Draw("same");
    h_ede_b2f0->Fit("gaus","","",27100,27900);
    h_ede_b2f0->GetFunction("gaus")->Delete();

    h_ede_b3f0->Rebin(2);
    h_ede_b3f0->SetLineColor(kCyan+1);
    h_ede_b3f0->Draw("same");
    h_ede_b3f0->Fit("gaus","","",27100,27900);    
    h_ede_b3f0->GetFunction("gaus")->Delete();

    h_ede_b4f0->Rebin(2);
    h_ede_b4f0->SetLineColor(kBlue);
    h_ede_b4f0->Draw("same");
    h_ede_b4f0->Fit("gaus","","",27100,27900);    
    h_ede_b4f0->GetFunction("gaus")->Delete();

    h_ede_b5f0->Rebin(2);
    h_ede_b5f0->SetLineColor(kPink+10);
    h_ede_b5f0->Draw("same");
    h_ede_b5f0->Fit("gaus","","",27100,27900);    
    h_ede_b5f0->GetFunction("gaus")->Delete();    

    h_ede_b6f0->Rebin(2);
    h_ede_b6f0->SetLineColor(kYellow+1);
    h_ede_b6f0->Draw("same");
    h_ede_b6f0->Fit("gaus","","",27100,27900);    
    h_ede_b6f0->GetFunction("gaus")->Delete();    


    h_ede_b7f0->Rebin(2);
    h_ede_b7f0->SetLineColor(kRed);
    h_ede_b7f0->Draw("same");
    h_ede_b7f0->Fit("gaus","","",27100,27900);    
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

    ///////////////////////////
    // Ring f1 = 138 degrees //
    ///////////////////////////
/*
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
    h_ede_b0f1->Fit("gaus","","",27200,27900);
    h_ede_b0f1->GetFunction("gaus")->Delete();


    h_ede_b1f1->Rebin(2);
    h_ede_b1f1->SetLineColor(kMagenta);
    h_ede_b1f1->Draw("same");
    h_ede_b1f1->Fit("gaus","","",27200,27900);
    h_ede_b1f1->GetFunction("gaus")->Delete();
   
    h_ede_b2f1->Rebin(2);
    h_ede_b2f1->SetLineColor(kGreen);
    h_ede_b2f1->Draw("same");
    h_ede_b2f1->Fit("gaus","","",27200,27900);
    h_ede_b2f1->GetFunction("gaus")->Delete();

    h_ede_b3f1->Rebin(2);
    h_ede_b3f1->SetLineColor(kCyan+1);
    h_ede_b3f1->Draw("same");
    h_ede_b3f1->Fit("gaus","","",27200,27900);    
    h_ede_b3f1->GetFunction("gaus")->Delete();

    h_ede_b4f1->Rebin(2);
    h_ede_b4f1->SetLineColor(kBlue);
    h_ede_b4f1->Draw("same");
    h_ede_b4f1->Fit("gaus","","",27200,27900);    
    h_ede_b4f1->GetFunction("gaus")->Delete();

    h_ede_b5f1->Rebin(2);
    h_ede_b5f1->SetLineColor(kPink+10);
    h_ede_b5f1->Draw("same");
    h_ede_b5f1->Fit("gaus","","",27200,27900);    
    h_ede_b5f1->GetFunction("gaus")->Delete();    

    h_ede_b6f1->Rebin(2);
    h_ede_b6f1->SetLineColor(kYellow+1);
    h_ede_b6f1->Draw("same");
    h_ede_b6f1->Fit("gaus","","",27200,27900);    
    h_ede_b6f1->GetFunction("gaus")->Delete();    


    h_ede_b7f1->Rebin(2);
    h_ede_b7f1->SetLineColor(kRed);
    h_ede_b7f1->Draw("same");
    h_ede_b7f1->Fit("gaus","","",27200,27900);    
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
    h_ede_b0f2->Fit("gaus","","",27200,27900);
    h_ede_b0f2->GetFunction("gaus")->Delete();


    h_ede_b1f2->Rebin(2);
    h_ede_b1f2->SetLineColor(kMagenta);
    h_ede_b1f2->Draw("same");
    h_ede_b1f2->Fit("gaus","","",27200,27900);
    h_ede_b1f2->GetFunction("gaus")->Delete();
   
    h_ede_b2f2->Rebin(2);
    h_ede_b2f2->SetLineColor(kGreen);
    h_ede_b2f2->Draw("same");
    h_ede_b2f2->Fit("gaus","","",27200,27900);
    h_ede_b2f2->GetFunction("gaus")->Delete();

    h_ede_b3f2->Rebin(2);
    h_ede_b3f2->SetLineColor(kCyan+1);
    h_ede_b3f2->Draw("same");
    h_ede_b3f2->Fit("gaus","","",27200,27900);    
    h_ede_b3f2->GetFunction("gaus")->Delete();

    h_ede_b4f2->Rebin(2);
    h_ede_b4f2->SetLineColor(kBlue);
    h_ede_b4f2->Draw("same");
    h_ede_b4f2->Fit("gaus","","",27200,27900);    
    h_ede_b4f2->GetFunction("gaus")->Delete();

    h_ede_b5f2->Rebin(2);
    h_ede_b5f2->SetLineColor(kPink+10);
    h_ede_b5f2->Draw("same");
    h_ede_b5f2->Fit("gaus","","",27200,27900);    
    h_ede_b5f2->GetFunction("gaus")->Delete();    

    h_ede_b6f2->Rebin(2);
    h_ede_b6f2->SetLineColor(kYellow+1);
    h_ede_b6f2->Draw("same");
    h_ede_b6f2->Fit("gaus","","",27200,27900);    
    h_ede_b6f2->GetFunction("gaus")->Delete();    


    h_ede_b7f2->Rebin(2);
    h_ede_b7f2->SetLineColor(kRed);
    h_ede_b7f2->Draw("same");
    h_ede_b7f2->Fit("gaus","","",27200,27900);    
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


*/

} // End of script
