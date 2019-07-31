// Script to grab the m_e_de_b0fX matrices for the 60Ni(a,a) calibration data
// and compare to the QKinz calculated values to check the calibration
// Cecilie, July 30, 2019

#include <fstream>
#include <iostream>

void SiRi_QKinz_186W_aa(){
    // No stats shown
    //gStyle->SetOptStat(0);
    
    // Grab data file for 186W(a,a')
    TFile *file = TFile::Open("offline_186W_aa.root");

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




    ///////////////////////////
    // Ring f0 = 140 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f0, 140 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c1 = new TCanvas("c1","c1:f0 bananas",1400,800);
    c1->Divide(4,2,0,0);
    c1->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f0 186W(a,a') banana
    banana_b0f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f0->Draw();

    QKinz_f0_graph->SetMarkerStyle(2);
    QKinz_f0_graph->SetMarkerSize(1.);
    QKinz_f0_graph->Draw("same");

    c1->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f0 186W(a,a') banana
    banana_b1f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f0->Draw();

    QKinz_f0_graph->Draw("same");


    c1->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f0 186W(a,a') banana
    banana_b2f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f0->Draw();

    QKinz_f0_graph->Draw("same");

    c1->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f0 186W(a,a') banana
    banana_b3f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f0->Draw();

    QKinz_f0_graph->Draw("same");


    c1->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f0 186W(a,a') banana
    banana_b4f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f0->Draw();

    QKinz_f0_graph->Draw("same");


    c1->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f0 186W(a,a') banana
    banana_b5f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f0->Draw();

    QKinz_f0_graph->Draw("same");


    c1->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f0 186W(a,a') banana
    banana_b6f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f0->Draw();

    QKinz_f0_graph->Draw("same");


    c1->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f0 186W(a,a') banana
    banana_b7f0->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f0->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f0->Draw();

    QKinz_f0_graph->Draw("same");

    c1->Update();
    //c1->Print("comparison_QKinz_data_f0.png");


    ///////////////////////////
    // Ring f1 = 138 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f1, 138 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c2 = new TCanvas("c2","c2:f1 bananas",1400,800);
    c2->Divide(4,2,0,0);
    c2->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f1 186W(a,a') banana
    banana_b0f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f1->Draw();

    QKinz_f1_graph->SetMarkerStyle(2);
    QKinz_f1_graph->SetMarkerSize(1.);
    QKinz_f1_graph->Draw("same");

    c2->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f1 186W(a,a') banana
    banana_b1f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f1->Draw();

    QKinz_f1_graph->Draw("same");


    c2->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f1 186W(a,a') banana
    banana_b2f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f1->Draw();

    QKinz_f1_graph->Draw("same");

    c2->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f1 186W(a,a') banana
    banana_b3f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f1->Draw();

    QKinz_f1_graph->Draw("same");


    c2->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f1 186W(a,a') banana
    banana_b4f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f1->Draw();

    QKinz_f1_graph->Draw("same");


    c2->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f1 186W(a,a') banana
    banana_b5f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f1->Draw();

    QKinz_f1_graph->Draw("same");


    c2->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f1 186W(a,a') banana
    banana_b6f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f1->Draw();

    QKinz_f1_graph->Draw("same");


    c2->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f1 186W(a,a') banana
    banana_b7f1->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f1->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f1->Draw();

    QKinz_f1_graph->Draw("same");


    ///////////////////////////
    // Ring f2 = 136 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f2, 136 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c3 = new TCanvas("c3","c3:f2 bananas",1400,800);
    c3->Divide(4,2,0,0);
    c3->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f2 186W(a,a') banana
    banana_b0f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f2->Draw();

    QKinz_f2_graph->SetMarkerStyle(2);
    QKinz_f2_graph->SetMarkerSize(1.);
    QKinz_f2_graph->Draw("same");

    c3->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f2 186W(a,a') banana
    banana_b1f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f2->Draw();

    QKinz_f2_graph->Draw("same");


    c3->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f2 186W(a,a') banana
    banana_b2f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f2->Draw();

    QKinz_f2_graph->Draw("same");

    c3->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f2 186W(a,a') banana
    banana_b3f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f2->Draw();

    QKinz_f2_graph->Draw("same");


    c3->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f2 186W(a,a') banana
    banana_b4f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f2->Draw();

    QKinz_f2_graph->Draw("same");


    c3->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f2 186W(a,a') banana
    banana_b5f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f2->Draw();

    QKinz_f2_graph->Draw("same");


    c3->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f2 186W(a,a') banana
    banana_b6f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f2->Draw();

    QKinz_f2_graph->Draw("same");


    c3->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f2 186W(a,a') banana
    banana_b7f2->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f2->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f2->Draw();

    QKinz_f2_graph->Draw("same");


    ///////////////////////////
    // Ring f3 = 134 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f3, 134 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c4 = new TCanvas("c4","c4:f3 bananas",1400,800);
    c4->Divide(4,2,0,0);
    c4->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f3 186W(a,a') banana
    banana_b0f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f3->Draw();

    QKinz_f3_graph->SetMarkerStyle(2);
    QKinz_f3_graph->SetMarkerSize(1.);
    QKinz_f3_graph->Draw("same");

    c4->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f3 186W(a,a') banana
    banana_b1f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f3->Draw();

    QKinz_f3_graph->Draw("same");


    c4->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f3 186W(a,a') banana
    banana_b2f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f3->Draw();

    QKinz_f3_graph->Draw("same");

    c4->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f3 186W(a,a') banana
    banana_b3f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f3->Draw();

    QKinz_f3_graph->Draw("same");


    c4->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f3 186W(a,a') banana
    banana_b4f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f3->Draw();

    QKinz_f3_graph->Draw("same");


    c4->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f3 186W(a,a') banana
    banana_b5f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f3->Draw();

    QKinz_f3_graph->Draw("same");


    c4->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f3186W(a,a') banana
    banana_b6f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f3->Draw();

    QKinz_f3_graph->Draw("same");


    c4->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f3 186W(a,a') banana
    banana_b7f3->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f3->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f3->Draw();

    QKinz_f3_graph->Draw("same");


    ///////////////////////////
    // Ring f4 = 132 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f4, 132 degrees
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
        //cout << i << " " << f0_delta_e_energy[i] << " " << f0_delta_e_energy_err[i] << " " << f0_e_energy[i] << " " << f0_e_energy_err[i] << endl;
        i++;
    }
    f4_QKinzfile.close();

    // Make a graph for the f4 QKinz values
    TGraphErrors *QKinz_f4_graph = new TGraphErrors(67,f4_e_energy,f4_delta_e_energy,f4_e_energy_err,f4_delta_e_energy_err);

    // Make canvas to plot the 2D banana plots
    TCanvas *c5 = new TCanvas("c5","c5:f4 bananas",1400,800);
    c5->Divide(4,2,0,0);
    c5->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f4 186W(a,a') banana
    banana_b0f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f4->Draw();

    QKinz_f4_graph->SetMarkerStyle(2);
    QKinz_f4_graph->SetMarkerSize(1.);
    QKinz_f4_graph->Draw("same");

    c5->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f4 186W(a,a') banana
    banana_b1f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f4->Draw();

    QKinz_f4_graph->Draw("same");


    c5->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f4 186W(a,a') banana
    banana_b2f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f4->Draw();

    QKinz_f4_graph->Draw("same");

    c5->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f4 186W(a,a') banana
    banana_b3f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f4->Draw();

    QKinz_f4_graph->Draw("same");


    c5->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f4 186W(a,a') banana
    banana_b4f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f4->Draw();

    QKinz_f4_graph->Draw("same");


    c5->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f4 186W(a,a') banana
    banana_b5f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f4->Draw();

    QKinz_f4_graph->Draw("same");


    c5->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f4 186W(a,a') banana
    banana_b6f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f4->Draw();

    QKinz_f4_graph->Draw("same");


    c5->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f4 186W(a,a') banana
    banana_b7f4->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f4->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f4->Draw();

    QKinz_f4_graph->Draw("same");


    ///////////////////////////
    // Ring f5 = 130 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f5, 130 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c6 = new TCanvas("c6","c6:f5 bananas",1400,800);
    c6->Divide(4,2,0,0);
    c6->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f5 186W(a,a') banana
    banana_b0f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f5->Draw();

    QKinz_f5_graph->SetMarkerStyle(2);
    QKinz_f5_graph->SetMarkerSize(1.);
    QKinz_f5_graph->Draw("same");

    c6->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f5 186W(a,a') banana
    banana_b1f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f5->Draw();

    QKinz_f5_graph->Draw("same");


    c6->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f5 186W(a,a') banana
    banana_b2f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f5->Draw();

    QKinz_f5_graph->Draw("same");

    c6->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f5 186W(a,a') banana
    banana_b3f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f5->Draw();

    QKinz_f5_graph->Draw("same");


    c6->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f5 186W(a,a') banana
    banana_b4f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f5->Draw();

    QKinz_f5_graph->Draw("same");


    c6->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f5 186W(a,a') banana
    banana_b5f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f5->Draw();

    QKinz_f5_graph->Draw("same");


    c6->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f5 186W(a,a') banana
    banana_b6f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f5->Draw();

    QKinz_f5_graph->Draw("same");


    c6->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f5 186W(a,a') banana
    banana_b7f5->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f5->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f5->Draw();

    QKinz_f5_graph->Draw("same");


    ///////////////////////////
    // Ring f6 = 128 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f6, 128 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c7 = new TCanvas("c7","c7:f6 bananas",1400,800);
    c7->Divide(4,2,0,0);
    c7->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f6 186W(a,a') banana
    banana_b0f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f6->Draw();

    QKinz_f6_graph->SetMarkerStyle(2);
    QKinz_f6_graph->SetMarkerSize(1.);
    QKinz_f6_graph->Draw("same");

    c7->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f6 186W(a,a') banana
    banana_b1f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f6->Draw();

    QKinz_f6_graph->Draw("same");


    c7->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f6 186W(a,a') banana
    banana_b2f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f6->Draw();

    QKinz_f6_graph->Draw("same");

    c7->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f6 186W(a,a') banana
    banana_b3f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f6->Draw();

    QKinz_f6_graph->Draw("same");


    c7->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f6 186W(a,a') banana
    banana_b4f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f6->Draw();

    QKinz_f6_graph->Draw("same");


    c7->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f6 186W(a,a') banana
    banana_b5f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f6->Draw();

    QKinz_f6_graph->Draw("same");


    c7->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f6 186W(a,a') banana
    banana_b6f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f6->Draw();

    QKinz_f6_graph->Draw("same");


    c7->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f6 186W(a,a') banana
    banana_b7f6->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f6->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f6->Draw();

    QKinz_f6_graph->Draw("same");


    ///////////////////////////
    // Ring f7 = 126 degrees //
    ///////////////////////////

    // Get QKinz calculations, ring f7, 126 degrees
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

    // Make canvas to plot the 2D banana plots
    TCanvas *c8 = new TCanvas("c8","c8:f7 bananas",1400,800);
    c8->Divide(4,2,0,0);
    c8->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b0f7 186W(a,a') banana
    banana_b0f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b0f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b0f7->Draw();

    QKinz_f7_graph->SetMarkerStyle(2);
    QKinz_f7_graph->SetMarkerSize(1.);
    QKinz_f7_graph->Draw("same");

    c8->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.06);

    // The b1f7 186W(a,a') banana
    banana_b1f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b1f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b1f7->Draw();

    QKinz_f7_graph->Draw("same");


    c8->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f7 186W(a,a') banana
    banana_b2f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b2f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b2f7->Draw();

    QKinz_f7_graph->Draw("same");

    c8->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f7 186W(a,a') banana
    banana_b3f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b3f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b3f7->Draw();

    QKinz_f7_graph->Draw("same");


    c8->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f7 186W(a,a') banana
    banana_b4f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b4f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b4f7->Draw();

    QKinz_f7_graph->Draw("same");


    c8->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f7 186W(a,a') banana
    banana_b5f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b5f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b5f7->Draw();

    QKinz_f7_graph->Draw("same");


    c8->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f7 186W(a,a') banana
    banana_b6f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b6f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b6f7->Draw();

    QKinz_f7_graph->Draw("same");


    c8->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f7 186W(a,a') banana
    banana_b7f7->GetXaxis()->SetRangeUser(9500,23000);
    banana_b7f7->GetYaxis()->SetRangeUser(5600,9500);
    banana_b7f7->Draw();

    QKinz_f7_graph->Draw("same");



} // End of script
