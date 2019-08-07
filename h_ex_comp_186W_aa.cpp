// Script to compare all h_ex_fX ring by ring to check the calibration
// Cecilie, Aug 7, 2019

#include <fstream>
#include <iostream>

void h_ex_comp_186W_aa(){
    // No stats or titles shown
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);

    // Grab data file for 186W(a,a')
    TFile *file = TFile::Open("offline_186W_aa.root");

    // All h_ex_fX rings
	TH1D *h_ex_f0  = (TH1D*)file->Get("h_ex_f0"); // Ex histogram for f0
    TH1D *h_ex_f1  = (TH1D*)file->Get("h_ex_f1"); // Ex histogram for f1
    TH1D *h_ex_f2  = (TH1D*)file->Get("h_ex_f2"); // Ex histogram for f2
    TH1D *h_ex_f3  = (TH1D*)file->Get("h_ex_f3"); // Ex histogram for f3
    TH1D *h_ex_f4  = (TH1D*)file->Get("h_ex_f4"); // Ex histogram for f4
    TH1D *h_ex_f5  = (TH1D*)file->Get("h_ex_f5"); // Ex histogram for f5
    TH1D *h_ex_f6  = (TH1D*)file->Get("h_ex_f6"); // Ex histogram for f6
    TH1D *h_ex_f7  = (TH1D*)file->Get("h_ex_f7"); // Ex histogram for f7

    // The ground state should now be centered at zero excitation energy
    double centroid_Qkinz_f0 = 0;
    double centroid_Qkinz_f1 = 0;
    double centroid_Qkinz_f2 = 0;
    double centroid_Qkinz_f3 = 0;
    double centroid_Qkinz_f4 = 0;
    double centroid_Qkinz_f5 = 0;
    double centroid_Qkinz_f6 = 0;
    double centroid_Qkinz_f7 = 0;

    ///////////////////////////
    // Ring f0 = 140 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f0 = 140 degrees: " << endl;
    // Make canvas to plot the histograms
    TCanvas *c1 = new TCanvas("c1","c1:f0 histogram",1000,700);
    c1->cd(1);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f0->GetXaxis()->SetRangeUser(-500,3000);
    //h_ex_f0->GetYaxis()->SetRangeUser(1,4000);
    h_ex_f0->GetYaxis()->SetTitle("counts");
    h_ex_f0->Draw();
    h_ex_f0->Fit("gaus","","",-500,200);
    TF1 *fit = (TF1*)h_ex_f0->GetListOfFunctions()->FindObject("gaus");
    double centroid_f0 = fit->GetParameter(1);



    ///////////////////////////
    // Ring f1 = 138 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f1 = 138 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c2 = new TCanvas("c2","c2:f1 histogram",1000,700);
    c2->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f1->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f1->GetYaxis()->SetTitle("counts");
    h_ex_f1->Draw();
    h_ex_f1->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f1->GetListOfFunctions()->FindObject("gaus");
    double centroid_f1 = fit->GetParameter(1);


    ///////////////////////////
    // Ring f2 = 136 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f2 = 136 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c3 = new TCanvas("c3","c3:f2 histogram",1000,700);
    c3->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f2->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f2->GetYaxis()->SetTitle("counts");
    h_ex_f2->Draw();
    h_ex_f2->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f2->GetListOfFunctions()->FindObject("gaus");
    double centroid_f2 = fit->GetParameter(1);


    ///////////////////////////
    // Ring f3 = 134 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f3 = 134 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c4 = new TCanvas("c4","c4:f3 histogram",1000,700);
    c4->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f3->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f3->GetYaxis()->SetTitle("counts");
    h_ex_f3->Draw();
    h_ex_f3->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f3->GetListOfFunctions()->FindObject("gaus");
    double   centroid_f3 = fit->GetParameter(1);


    ///////////////////////////
    // Ring f4 = 132 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f4 = 132 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c5 = new TCanvas("c5","c5:f4 histogram",1000,700);
    c5->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f4->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f4->GetYaxis()->SetTitle("counts");
    h_ex_f4->Draw();
    h_ex_f4->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f4->GetListOfFunctions()->FindObject("gaus");
    double   centroid_f4 = fit->GetParameter(1);

    ///////////////////////////
    // Ring f5 = 130 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f5 = 130 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c6 = new TCanvas("c6","c6:f5 histogram",1000,700);
    c6->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f5->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f5->GetYaxis()->SetTitle("counts");
    h_ex_f5->Draw();
    h_ex_f5->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f5->GetListOfFunctions()->FindObject("gaus");
    double   centroid_f5 = fit->GetParameter(1);


    ///////////////////////////
    // Ring f6 = 128 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f6 = 128 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c7 = new TCanvas("c7","c7:f6 histogram",1000,700);
    c7->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f6->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f6->GetYaxis()->SetTitle("counts");
    h_ex_f6->Draw();
    h_ex_f6->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f6->GetListOfFunctions()->FindObject("gaus");
    double   centroid_f6 = fit->GetParameter(1);



    ///////////////////////////
    // Ring f7 = 126 degrees //
    ///////////////////////////

    cout << endl;
    cout << " *************************************************** " << endl;
    cout << " Fit of the elastic peak for ring f7 = 126 degrees: " << endl;

    // Make canvas to plot the histograms
    TCanvas *c8 = new TCanvas("c8","c8:f7 histogram",1000,700);
    c8->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f7->GetXaxis()->SetRangeUser(-500,3000);
    h_ex_f7->GetYaxis()->SetTitle("counts");
    h_ex_f7->Draw();
    h_ex_f7->Fit("gaus","","",-500,200);
    fit = (TF1*)h_ex_f7->GetListOfFunctions()->FindObject("gaus");
    double   centroid_f7 = fit->GetParameter(1);

    // Make canvas to plot all the histograms
    TCanvas *c9 = new TCanvas("c9","c9: All histograms",1000,700);
    c9->cd();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    h_ex_f6->Draw();
    h_ex_f7->Draw("same");
    h_ex_f5->Draw("same");
    h_ex_f4->Draw("same");
    h_ex_f3->Draw("same");
    h_ex_f2->Draw("same");
    h_ex_f1->Draw("same");
    h_ex_f0->Draw("same");

    // Calculate difference, included as an additional shift in
    // run_186W_alphagate.batch
    cout << " Qkinz value - fitted centroids: " << endl;
    cout << " f0: " << centroid_Qkinz_f0-centroid_f0 << " keV " << endl;
    cout << " f1: " << centroid_Qkinz_f1-centroid_f1 << " keV " << endl;
    cout << " f2: " << centroid_Qkinz_f2-centroid_f2 << " keV " << endl;
    cout << " f3: " << centroid_Qkinz_f3-centroid_f3 << " keV " << endl;
    cout << " f4: " << centroid_Qkinz_f4-centroid_f4 << " keV " << endl;
    cout << " f5: " << centroid_Qkinz_f5-centroid_f5 << " keV " << endl;
    cout << " f6: " << centroid_Qkinz_f6-centroid_f6 << " keV " << endl;
    cout << " f7: " << centroid_Qkinz_f7-centroid_f7 << " keV " << endl;


} // End of script
