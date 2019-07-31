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
    c1->Print("comparison_QKinz_data_f0.png");


    ///////////////////////////
    // Ring f1 = 138 degrees //
    ///////////////////////////
/*
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
        //cout << i << " " << f0_delta_e_energy[i] << " " << f0_delta_e_energy_err[i] << " " << f0_e_energy[i] << " " << f0_e_energy_err[i] << endl;
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
        //cout << i << " " << f0_delta_e_energy[i] << " " << f0_delta_e_energy_err[i] << " " << f0_e_energy[i] << " " << f0_e_energy_err[i] << endl;
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
*/

}
