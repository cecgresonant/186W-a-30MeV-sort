// Script to grab the m_e_de_b0fX matrices for the 60Ni(a,a) calibration data
// and make graphical cuts of the ground-state peak, and fit the energy 
// deposited in the E and Delta E detectors to be used for calibration
// of the 186W(a,a') data set. This is for all the detectors.
// Cecilie, July 16, 2019

#include <fstream>
#include <iostream>

void TCutG_60Ni_aa_SiRi(){
    // No stats shown
    //gStyle->SetOptStat(0);

    // Create output file to write the centroids of the 60Ni(a,a) peak in the Delta E and E detectors
    ofstream outfile("alpha_peaks_60Ni.csv");
    outfile << " Ground-state peak positions for the elastic alpha scattering off 60Ni" << endl;
    
    // Grab input file
    TFile *file = TFile::Open("offline_60Ni_plain.root");

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

    ///////////////////
    // E DETECTOR b0 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c1 = new TCanvas("c1","c1:b0 bananas",1400,800);
    c1->Divide(8,3,0,0);
    c1->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f0 60Ni(a,a) elastic peak
    banana_b0f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b0f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f0->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f0 = new TCutG("cutg_b0f0",18);
    cutg_b0f0->SetVarX(" E detector 0 strip 0");
    cutg_b0f0->SetVarY("#DeltaE ");
    cutg_b0f0->SetTitle("Graphb0f0");
    cutg_b0f0->SetFillStyle(1000);
    cutg_b0f0->SetPoint(0,10662.9,4884.22);
    cutg_b0f0->SetPoint(1,10508.9,4798.8);
    cutg_b0f0->SetPoint(2,10520.7,4654.95);
    cutg_b0f0->SetPoint(3,10615.5,4506.59);
    cutg_b0f0->SetPoint(4,10793.3,4398.7);
    cutg_b0f0->SetPoint(5,10988.9,4331.27);
    cutg_b0f0->SetPoint(6,11303,4254.85);
    cutg_b0f0->SetPoint(7,11628.9,4223.38);
    cutg_b0f0->SetPoint(8,11836.4,4263.84);
    cutg_b0f0->SetPoint(9,11984.5,4425.67);
    cutg_b0f0->SetPoint(10,11860.1,4560.54);
    cutg_b0f0->SetPoint(11,11670.4,4650.45);
    cutg_b0f0->SetPoint(12,11397.8,4758.34);
    cutg_b0f0->SetPoint(13,11089.6,4825.77);
    cutg_b0f0->SetPoint(14,10823,4884.22);
    cutg_b0f0->SetPoint(15,10704.4,4884.22);
    cutg_b0f0->SetPoint(16,10651.1,4884.22);
    cutg_b0f0->SetPoint(17,10662.9,4884.22);
    cutg_b0f0->Draw("same");

    c1->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f1 60Ni(a,a) elastic peak
    banana_b0f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b0f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f1->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f1 = new TCutG("cutg_b0f1",15);
    cutg_b0f1->SetVarX(" E detector 0 strip 1");
    cutg_b0f1->SetVarY("#DeltaE ");
    cutg_b0f1->SetTitle("Graph");
    cutg_b0f1->SetFillStyle(1000);
    cutg_b0f1->SetPoint(0,11957.9,4622.33);
    cutg_b0f1->SetPoint(1,11730.5,4780.73);
    cutg_b0f1->SetPoint(2,11342.6,4866.72);
    cutg_b0f1->SetPoint(3,10954.7,4911.98);
    cutg_b0f1->SetPoint(4,10680.5,4862.2);
    cutg_b0f1->SetPoint(5,10606.9,4753.58);
    cutg_b0f1->SetPoint(6,10660.4,4663.06);
    cutg_b0f1->SetPoint(7,10974.8,4513.71);
    cutg_b0f1->SetPoint(8,11329.2,4328.15);
    cutg_b0f1->SetPoint(9,11777.3,4278.36);
    cutg_b0f1->SetPoint(10,11984.6,4305.52);
    cutg_b0f1->SetPoint(11,12058.2,4441.29);
    cutg_b0f1->SetPoint(12,12024.8,4536.34);
    cutg_b0f1->SetPoint(13,11937.8,4635.91);
    cutg_b0f1->SetPoint(14,11957.9,4622.33);
    cutg_b0f1->Draw("same");

    c1->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f2 60Ni(a,a) elastic peak
    banana_b0f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b0f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f2->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f2 = new TCutG("cutg_b0f2",16);
    cutg_b0f2->SetVarX(" E detector 0 strip 2");
    cutg_b0f2->SetVarY("#DeltaE ");
    cutg_b0f2->SetTitle("Graph");
    cutg_b0f2->SetFillStyle(1000);
    cutg_b0f2->SetPoint(0,11455,4743.74);
    cutg_b0f2->SetPoint(1,11214.5,4823.63);
    cutg_b0f2->SetPoint(2,10848.4,4823.63);
    cutg_b0f2->SetPoint(3,10722.9,4613);
    cutg_b0f2->SetPoint(4,10796.1,4424.16);
    cutg_b0f2->SetPoint(5,10942.6,4315.21);
    cutg_b0f2->SetPoint(6,11319.1,4235.32);
    cutg_b0f2->SetPoint(7,11695.6,4140.89);
    cutg_b0f2->SetPoint(8,11967.5,4155.42);
    cutg_b0f2->SetPoint(9,12040.7,4286.16);
    cutg_b0f2->SetPoint(10,12103.4,4445.95);
    cutg_b0f2->SetPoint(11,11957,4547.63);
    cutg_b0f2->SetPoint(12,11726.9,4627.53);
    cutg_b0f2->SetPoint(13,11549.1,4700.16);
    cutg_b0f2->SetPoint(14,11455,4736.47);
    cutg_b0f2->SetPoint(15,11455,4743.74);
    cutg_b0f2->Draw("same");   

    c1->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f3 60Ni(a,a) elastic peak
    banana_b0f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b0f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f3->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f3 = new TCutG("cutg_b0f3",17);
    cutg_b0f3->SetVarX(" E detector 0 strip 3");
    cutg_b0f3->SetVarY("#DeltaE ");
    cutg_b0f3->SetTitle("Graph");
    cutg_b0f3->SetFillStyle(1000);
    cutg_b0f3->SetPoint(0,11691.3,4825.11);
    cutg_b0f3->SetPoint(1,11450.8,4881);
    cutg_b0f3->SetPoint(2,11210.3,4899.63);
    cutg_b0f3->SetPoint(3,11011.5,4856.16);
    cutg_b0f3->SetPoint(4,10938.3,4769.21);
    cutg_b0f3->SetPoint(5,10948.8,4539.42);
    cutg_b0f3->SetPoint(6,11032.5,4464.89);
    cutg_b0f3->SetPoint(7,11273,4415.21);
    cutg_b0f3->SetPoint(8,11628.6,4353.11);
    cutg_b0f3->SetPoint(9,11931.9,4284.79);
    cutg_b0f3->SetPoint(10,12235.2,4334.47);
    cutg_b0f3->SetPoint(11,12329.3,4520.79);
    cutg_b0f3->SetPoint(12,12162,4657.42);
    cutg_b0f3->SetPoint(13,11900.5,4744.37);
    cutg_b0f3->SetPoint(14,11795.9,4781.63);
    cutg_b0f3->SetPoint(15,11680.9,4825.11);
    cutg_b0f3->SetPoint(16,11691.3,4825.11);
    cutg_b0f3->Draw("same");


    c1->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f4 60Ni(a,a) elastic peak
    banana_b0f4->GetXaxis()->SetRangeUser(8000,14000);
    banana_b0f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f4->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f4 = new TCutG("cutg_b0f4",18);
    cutg_b0f4->SetVarX(" E detector 0 strip 4");
    cutg_b0f4->SetVarY("#DeltaE ");
    cutg_b0f4->SetTitle("Graph");
    cutg_b0f4->SetFillStyle(1000);
    cutg_b0f4->SetPoint(0,11440,4877);
    cutg_b0f4->SetPoint(1,11123.7,4877);
    cutg_b0f4->SetPoint(2,11041.1,4817.32);
    cutg_b0f4->SetPoint(3,11041.1,4691.32);
    cutg_b0f4->SetPoint(4,11041.1,4578.58);
    cutg_b0f4->SetPoint(5,11398.7,4406.16);
    cutg_b0f4->SetPoint(6,11701.3,4333.21);
    cutg_b0f4->SetPoint(7,12017.7,4293.42);
    cutg_b0f4->SetPoint(8,12416.5,4379.63);
    cutg_b0f4->SetPoint(9,12485.3,4445.95);
    cutg_b0f4->SetPoint(10,12375.2,4565.32);
    cutg_b0f4->SetPoint(11,12168.9,4664.79);
    cutg_b0f4->SetPoint(12,12017.7,4724.47);
    cutg_b0f4->SetPoint(13,11797.6,4784.16);
    cutg_b0f4->SetPoint(14,11605,4837.21);
    cutg_b0f4->SetPoint(15,11508.8,4857.11);
    cutg_b0f4->SetPoint(16,11412.5,4877);
    cutg_b0f4->SetPoint(17,11440,4877);
    cutg_b0f4->Draw("same");

    c1->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f5 60Ni(a,a) elastic peak
    banana_b0f5->GetXaxis()->SetRangeUser(8000,14000);
    banana_b0f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f5->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f5 = new TCutG("cutg_b0f5",15);
    cutg_b0f5->SetVarX(" E detector 0 strip 5");
    cutg_b0f5->SetVarY("#DeltaE ");
    cutg_b0f5->SetTitle("Graph");
    cutg_b0f5->SetFillStyle(1000);
    cutg_b0f5->SetPoint(0,11857.8,4404.74);
    cutg_b0f5->SetPoint(1,12072.7,4382.63);
    cutg_b0f5->SetPoint(2,12359.2,4419.47);
    cutg_b0f5->SetPoint(3,12459.5,4588.95);
    cutg_b0f5->SetPoint(4,12130,4751.05);
    cutg_b0f5->SetPoint(5,11542.6,4861.58);
    cutg_b0f5->SetPoint(6,11256,4905.79);
    cutg_b0f5->SetPoint(7,11055.5,4868.95);
    cutg_b0f5->SetPoint(8,11012.5,4699.47);
    cutg_b0f5->SetPoint(9,11012.5,4611.05);
    cutg_b0f5->SetPoint(10,11170.1,4515.26);
    cutg_b0f5->SetPoint(11,11413.6,4448.95);
    cutg_b0f5->SetPoint(12,11743.2,4419.47);
    cutg_b0f5->SetPoint(13,11857.8,4412.11);
    cutg_b0f5->SetPoint(14,11857.8,4404.74);
    cutg_b0f5->Draw("same");

    c1->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f6 60Ni(a,a) elastic peak
    banana_b0f6->GetXaxis()->SetRangeUser(8000,14000);
    banana_b0f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f6->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f6 = new TCutG("cutg_b0f6",19);
    cutg_b0f6->SetVarX(" E detector 0 strip 6");
    cutg_b0f6->SetVarY("#DeltaE ");
    cutg_b0f6->SetTitle("Graph");
    cutg_b0f6->SetFillStyle(1000);
    cutg_b0f6->SetPoint(0,12491,4663.74);
    cutg_b0f6->SetPoint(1,12136.4,4780.58);
    cutg_b0f6->SetPoint(2,11859.2,4839);
    cutg_b0f6->SetPoint(3,11627.1,4889.63);
    cutg_b0f6->SetPoint(4,11246.7,4940.26);
    cutg_b0f6->SetPoint(5,11092,4854.58);
    cutg_b0f6->SetPoint(6,11014.6,4741.63);
    cutg_b0f6->SetPoint(7,11034,4620.89);
    cutg_b0f6->SetPoint(8,11156.5,4515.74);
    cutg_b0f6->SetPoint(9,11317.7,4453.42);
    cutg_b0f6->SetPoint(10,11788.3,4317.11);
    cutg_b0f6->SetPoint(11,12091.3,4266.47);
    cutg_b0f6->SetPoint(12,12329.8,4274.26);
    cutg_b0f6->SetPoint(13,12503.9,4324.89);
    cutg_b0f6->SetPoint(14,12581.3,4398.89);
    cutg_b0f6->SetPoint(15,12594.2,4469);
    cutg_b0f6->SetPoint(16,12607,4617);
    cutg_b0f6->SetPoint(17,12484.6,4667.63);
    cutg_b0f6->SetPoint(18,12491,4663.74);
    cutg_b0f6->Draw("same");

    c1->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b0f7 60Ni(a,a) elastic peak
    banana_b0f7->GetXaxis()->SetRangeUser(8000,14000);
    banana_b0f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b0f7->Draw();

    // Make a graphical cut around the elastic peak
    TCutG *cutg_b0f7 = new TCutG("cutg_b0f7",24);
    cutg_b0f7->SetVarX(" E detector 0 strip 7");
    cutg_b0f7->SetVarY("#DeltaE ");
    cutg_b0f7->SetTitle("Graph");
    cutg_b0f7->SetFillStyle(1000);
    cutg_b0f7->SetPoint(0,12246.4,4696.89);
    cutg_b0f7->SetPoint(1,12020.8,4836.16);
    cutg_b0f7->SetPoint(2,11827.4,4856.05);
    cutg_b0f7->SetPoint(3,11526.5,4915.74);
    cutg_b0f7->SetPoint(4,11322.3,4922.37);
    cutg_b0f7->SetPoint(5,11053.7,4895.84);
    cutg_b0f7->SetPoint(6,10914,4869.32);
    cutg_b0f7->SetPoint(7,10881.8,4776.47);
    cutg_b0f7->SetPoint(8,10871.1,4617.32);
    cutg_b0f7->SetPoint(9,10903.3,4517.84);
    cutg_b0f7->SetPoint(10,10935.5,4431.63);
    cutg_b0f7->SetPoint(11,11086,4345.42);
    cutg_b0f7->SetPoint(12,11236.4,4285.74);
    cutg_b0f7->SetPoint(13,11354.6,4265.84);
    cutg_b0f7->SetPoint(14,11741.4,4199.53);
    cutg_b0f7->SetPoint(15,12053,4173);
    cutg_b0f7->SetPoint(16,12257.2,4212.79);
    cutg_b0f7->SetPoint(17,12418.3,4279.11);
    cutg_b0f7->SetPoint(18,12472.1,4444.89);
    cutg_b0f7->SetPoint(19,12439.8,4544.37);
    cutg_b0f7->SetPoint(20,12343.1,4617.32);
    cutg_b0f7->SetPoint(21,12278.7,4677);
    cutg_b0f7->SetPoint(22,12235.7,4710.16);
    cutg_b0f7->SetPoint(23,12246.4,4696.89);
    cutg_b0f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b0f0
    c1->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f0 = banana_b0f0->ProjectionX("projx_cutg_b0f0",1,banana_b0f0->GetNbinsX(),"[cutg_b0f0]");              
    projx_cutg_b0f0->Rebin(2);
    projx_cutg_b0f0->Draw("");
    projx_cutg_b0f0->Fit("gaus");

    // Grab the centroid for the E detector
    TF1 *fitx = (TF1*)projx_cutg_b0f0->GetListOfFunctions()->FindObject("gaus");
    double centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c1->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projy_cutg_b0f0 = banana_b0f0->ProjectionY("projy_cutg_b0f0",1,banana_b0f0->GetNbinsY(),"[cutg_b0f0]");              
    projy_cutg_b0f0->Rebin(2);
    projy_cutg_b0f0->Draw("");
    projy_cutg_b0f0->Fit("gaus");

    // Grab the centroid for the Delta E detector
    TF1 *fity = (TF1*)projy_cutg_b0f0->GetListOfFunctions()->FindObject("gaus");
    double centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c1->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f1 = banana_b0f1->ProjectionX("projx_cutg_b0f1",1,banana_b0f1->GetNbinsX(),"[cutg_b0f1]");              
    projx_cutg_b0f1->Rebin(2);
    projx_cutg_b0f1->Draw("");
    projx_cutg_b0f1->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projy_cutg_b0f1 = banana_b0f1->ProjectionY("projy_cutg_b0f1",1,banana_b0f1->GetNbinsY(),"[cutg_b0f1]");              
    projy_cutg_b0f1->Rebin(2);
    projy_cutg_b0f1->Draw("");
    projy_cutg_b0f1->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c1->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f2 = banana_b0f2->ProjectionX("projx_cutg_b0f2",1,banana_b0f2->GetNbinsX(),"[cutg_b0f2]");              
    projx_cutg_b0f2->Rebin(2);
    projx_cutg_b0f2->Draw("");
    projx_cutg_b0f2->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projy_cutg_b0f2 = banana_b0f2->ProjectionY("projy_cutg_b0f2",1,banana_b0f2->GetNbinsY(),"[cutg_b0f2]");              
    projy_cutg_b0f2->Rebin(2);
    projy_cutg_b0f2->Draw("");
    projy_cutg_b0f2->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c1->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f3 = banana_b0f3->ProjectionX("projx_cutg_b0f3",1,banana_b0f3->GetNbinsX(),"[cutg_b0f3]");              
    projx_cutg_b0f3->Rebin(2);
    projx_cutg_b0f3->Draw("");
    projx_cutg_b0f3->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);  
    TH1D *projy_cutg_b0f3 = banana_b0f3->ProjectionY("projy_cutg_b0f3",1,banana_b0f3->GetNbinsY(),"[cutg_b0f3]");              
    projy_cutg_b0f3->Rebin(2);
    projy_cutg_b0f3->Draw("");
    projy_cutg_b0f3->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c1->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f4 = banana_b0f4->ProjectionX("projx_cutg_b0f4",1,banana_b0f4->GetNbinsX(),"[cutg_b0f4]");              
    projx_cutg_b0f4->Rebin(2);
    projx_cutg_b0f4->Draw("");
    projx_cutg_b0f4->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);
 
    c1->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f4 = banana_b0f4->ProjectionY("projy_cutg_b0f4",1,banana_b0f4->GetNbinsY(),"[cutg_b0f4]");              
    projy_cutg_b0f4->Rebin(2);
    projy_cutg_b0f4->Draw("");
    projy_cutg_b0f4->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c1->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f5 = banana_b0f5->ProjectionX("projx_cutg_b0f5",1,banana_b0f5->GetNbinsX(),"[cutg_b0f5]");              
    projx_cutg_b0f5->Rebin(2);
    projx_cutg_b0f5->Draw("");
    projx_cutg_b0f5->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f5 = banana_b0f5->ProjectionY("projy_cutg_b0f5",1,banana_b0f5->GetNbinsY(),"[cutg_b0f5]");              
    projy_cutg_b0f5->Rebin(2);
    projy_cutg_b0f5->Draw("");
    projy_cutg_b0f5->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c1->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f6 = banana_b0f6->ProjectionX("projx_cutg_b0f6",1,banana_b0f6->GetNbinsX(),"[cutg_b0f6]");              
    projx_cutg_b0f6->Rebin(2);
    projx_cutg_b0f6->Draw("");
    projx_cutg_b0f6->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);    
    TH1D *projy_cutg_b0f6 = banana_b0f6->ProjectionY("projy_cutg_b0f6",1,banana_b0f6->GetNbinsY(),"[cutg_b0f6]");              
    projy_cutg_b0f6->Rebin(2);
    projy_cutg_b0f6->Draw("");
    projy_cutg_b0f6->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c1->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    TH1D *projx_cutg_b0f7 = banana_b0f7->ProjectionX("projx_cutg_b0f7",1,banana_b0f7->GetNbinsX(),"[cutg_b0f7]");              
    projx_cutg_b0f7->Rebin(2);
    projx_cutg_b0f7->Draw("");
    projx_cutg_b0f7->Fit("gaus");

    // Grab the centroid for the E detector
    fitx = (TF1*)projx_cutg_b0f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    c1->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);   
    TH1D *projy_cutg_b0f7 = banana_b0f7->ProjectionY("projy_cutg_b0f7",1,banana_b0f7->GetNbinsY(),"[cutg_b0f7]");              
    projy_cutg_b0f7->Rebin(2);
    projy_cutg_b0f7->Draw("");
    projy_cutg_b0f7->Fit("gaus");

    // Grab the centroid for the Delta E detector
    fity = (TF1*)projy_cutg_b0f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b0f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    ///////////////////
    // E DETECTOR b1 //
    ///////////////////
  
    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c2 = new TCanvas("c2","c2:b1 bananas",1400,800);
    c2->Divide(8,3,0,0);
    c2->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f0 60Ni(a,a) elastic peak
    banana_b1f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f0->Draw();
    TCutG *cutg_b1f0 = new TCutG("cutg_b1f0",21);
    cutg_b1f0->SetVarX(" E detector 1 strip 0");
    cutg_b1f0->SetVarY("#DeltaE ");
    cutg_b1f0->SetTitle("Graph");
    cutg_b1f0->SetFillStyle(1000);
    cutg_b1f0->SetPoint(0,10044.4,4448.77);
    cutg_b1f0->SetPoint(1,10210.6,4386.56);
    cutg_b1f0->SetPoint(2,10493,4324.34);
    cutg_b1f0->SetPoint(3,10941.6,4273.44);
    cutg_b1f0->SetPoint(4,11373.6,4273.44);
    cutg_b1f0->SetPoint(5,11689.3,4346.97);
    cutg_b1f0->SetPoint(6,11714.2,4522.3);
    cutg_b1f0->SetPoint(7,11622.8,4675);
    cutg_b1f0->SetPoint(8,11489.9,4737.21);
    cutg_b1f0->SetPoint(9,11273.9,4827.7);
    cutg_b1f0->SetPoint(10,11041.3,4889.92);
    cutg_b1f0->SetPoint(11,10833.6,4957.79);
    cutg_b1f0->SetPoint(12,10592.7,4963.44);
    cutg_b1f0->SetPoint(13,10335.2,4974.75);
    cutg_b1f0->SetPoint(14,10069.4,4918.2);
    cutg_b1f0->SetPoint(15,10002.9,4810.74);
    cutg_b1f0->SetPoint(16,9928.14,4686.31);
    cutg_b1f0->SetPoint(17,9928.14,4573.2);
    cutg_b1f0->SetPoint(18,9977.99,4510.98);
    cutg_b1f0->SetPoint(19,10069.4,4443.11);
    cutg_b1f0->SetPoint(20,10044.4,4448.77);
    cutg_b1f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f0
    c2->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f0 = banana_b1f0->ProjectionX("projx_cutg_b1f0",1,banana_b1f0->GetNbinsX(),"[cutg_b1f0]");              
    projx_cutg_b1f0->Rebin(2);
    projx_cutg_b1f0->Draw("");
    projx_cutg_b1f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f0 = banana_b1f0->ProjectionY("projy_cutg_b1f0",1,banana_b1f0->GetNbinsY(),"[cutg_b1f0]");              
    projy_cutg_b1f0->Rebin(2);
    projy_cutg_b1f0->Draw("");
    projy_cutg_b1f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f1 60Ni(a,a) elastic peak
    banana_b1f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f1->Draw();

    TCutG *cutg_b1f1 = new TCutG("cutg_b1f1",18);
    cutg_b1f1->SetVarX(" E detector 1 strip 1");
    cutg_b1f1->SetVarY("#DeltaE ");
    cutg_b1f1->SetTitle("Graph");
    cutg_b1f1->SetFillStyle(1000);
    cutg_b1f1->SetPoint(0,10407.6,4952.63);
    cutg_b1f1->SetPoint(1,10687.4,4990.53);
    cutg_b1f1->SetPoint(2,11084.5,4990.53);
    cutg_b1f1->SetPoint(3,11472.6,4895.79);
    cutg_b1f1->SetPoint(4,11626.1,4700);
    cutg_b1f1->SetPoint(5,11626.1,4529.47);
    cutg_b1f1->SetPoint(6,11472.6,4340);
    cutg_b1f1->SetPoint(7,11111.6,4340);
    cutg_b1f1->SetPoint(8,10786.7,4377.89);
    cutg_b1f1->SetPoint(9,10380.5,4434.74);
    cutg_b1f1->SetPoint(10,10281.2,4516.84);
    cutg_b1f1->SetPoint(11,10245.1,4586.32);
    cutg_b1f1->SetPoint(12,10218.1,4681.05);
    cutg_b1f1->SetPoint(13,10227.1,4718.95);
    cutg_b1f1->SetPoint(14,10254.2,4813.68);
    cutg_b1f1->SetPoint(15,10290.3,4914.74);
    cutg_b1f1->SetPoint(16,10425.6,4958.95);
    cutg_b1f1->SetPoint(17,10407.6,4952.63);
    cutg_b1f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f1
    c2->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f1 = banana_b1f1->ProjectionX("projx_cutg_b1f1",1,banana_b1f1->GetNbinsX(),"[cutg_b1f1]");              
    projx_cutg_b1f1->Rebin(2);
    projx_cutg_b1f1->Draw("");
    projx_cutg_b1f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f1 = banana_b1f1->ProjectionY("projy_cutg_b1f1",1,banana_b1f1->GetNbinsY(),"[cutg_b1f1]");              
    projy_cutg_b1f1->Rebin(2);
    projy_cutg_b1f1->Draw("");
    projy_cutg_b1f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f2 60Ni(a,a) elastic peak
    banana_b1f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f2->Draw();

    TCutG *cutg_b1f2 = new TCutG("cutg_b1f2",23);
    cutg_b1f2->SetVarX(" E detector 1 strip 2");
    cutg_b1f2->SetVarY("#DeltaE ");
    cutg_b1f2->SetTitle("Graph");
    cutg_b1f2->SetFillStyle(1000);
    cutg_b1f2->SetPoint(0,11598.3,4725.84);
    cutg_b1f2->SetPoint(1,11439.9,4827.53);
    cutg_b1f2->SetPoint(2,11224.8,4921.95);
    cutg_b1f2->SetPoint(3,10840,4972.79);
    cutg_b1f2->SetPoint(4,10579.7,4972.79);
    cutg_b1f2->SetPoint(5,10421.2,4907.42);
    cutg_b1f2->SetPoint(6,10342,4842.05);
    cutg_b1f2->SetPoint(7,10262.8,4747.63);
    cutg_b1f2->SetPoint(8,10262.8,4587.84);
    cutg_b1f2->SetPoint(9,10274.1,4515.21);
    cutg_b1f2->SetPoint(10,10466.5,4348.16);
    cutg_b1f2->SetPoint(11,10670.2,4304.58);
    cutg_b1f2->SetPoint(12,10806,4282.79);
    cutg_b1f2->SetPoint(13,10998.5,4239.21);
    cutg_b1f2->SetPoint(14,11338,4231.95);
    cutg_b1f2->SetPoint(15,11519.1,4253.74);
    cutg_b1f2->SetPoint(16,11654.9,4311.84);
    cutg_b1f2->SetPoint(17,11756.8,4420.79);
    cutg_b1f2->SetPoint(18,11756.8,4522.47);
    cutg_b1f2->SetPoint(19,11688.9,4638.68);
    cutg_b1f2->SetPoint(20,11609.6,4718.58);
    cutg_b1f2->SetPoint(21,11575.7,4740.37);
    cutg_b1f2->SetPoint(22,11598.3,4725.84);
    cutg_b1f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f2
    c2->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f2 = banana_b1f2->ProjectionX("projx_cutg_b1f2",1,banana_b1f2->GetNbinsX(),"[cutg_b1f2]");              
    projx_cutg_b1f2->Rebin(2);
    projx_cutg_b1f2->Draw("");
    projx_cutg_b1f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f2 = banana_b1f2->ProjectionY("projy_cutg_b1f2",1,banana_b1f2->GetNbinsY(),"[cutg_b1f2]");              
    projy_cutg_b1f2->Rebin(2);
    projy_cutg_b1f2->Draw("");
    projy_cutg_b1f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f3 60Ni(a,a) elastic peak
    banana_b1f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f3->Draw();

    TCutG *cutg_b1f3 = new TCutG("cutg_b1f3",19);
    cutg_b1f3->SetVarX(" E detector 1 strip 3");
    cutg_b1f3->SetVarY("#DeltaE ");
    cutg_b1f3->SetTitle("Graph");
    cutg_b1f3->SetFillStyle(1000);
    cutg_b1f3->SetPoint(0,11135.2,4782.58);
    cutg_b1f3->SetPoint(1,10865.9,4849.11);
    cutg_b1f3->SetPoint(2,10704.3,4849.11);
    cutg_b1f3->SetPoint(3,10650.4,4782.58);
    cutg_b1f3->SetPoint(4,10650.4,4682.79);
    cutg_b1f3->SetPoint(5,10663.9,4491.53);
    cutg_b1f3->SetPoint(6,10744.7,4416.68);
    cutg_b1f3->SetPoint(7,10960.2,4341.84);
    cutg_b1f3->SetPoint(8,11189.1,4300.26);
    cutg_b1f3->SetPoint(9,11512.3,4300.26);
    cutg_b1f3->SetPoint(10,11754.7,4300.26);
    cutg_b1f3->SetPoint(11,11875.9,4366.79);
    cutg_b1f3->SetPoint(12,11889.4,4466.58);
    cutg_b1f3->SetPoint(13,11835.5,4566.37);
    cutg_b1f3->SetPoint(14,11660.5,4632.89);
    cutg_b1f3->SetPoint(15,11471.9,4691.11);
    cutg_b1f3->SetPoint(16,11256.4,4741);
    cutg_b1f3->SetPoint(17,11121.8,4790.89);
    cutg_b1f3->SetPoint(18,11135.2,4782.58);
    cutg_b1f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f3
    c2->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f3 = banana_b1f3->ProjectionX("projx_cutg_b1f3",1,banana_b1f3->GetNbinsX(),"[cutg_b1f3]");              
    projx_cutg_b1f3->Rebin(2);
    projx_cutg_b1f3->Draw("");
    projx_cutg_b1f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f3 = banana_b1f3->ProjectionY("projy_cutg_b1f3",1,banana_b1f3->GetNbinsY(),"[cutg_b1f3]");              
    projy_cutg_b1f3->Rebin(2);
    projy_cutg_b1f3->Draw("");
    projy_cutg_b1f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f4 60Ni(a,a) elastic peak
    banana_b1f4->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f4->Draw();

    TCutG *cutg_b1f4 = new TCutG("cutg_b1f4",17);
    cutg_b1f4->SetVarX(" E detector 1 strip 4");
    cutg_b1f4->SetVarY("#DeltaE ");
    cutg_b1f4->SetTitle("Graph");
    cutg_b1f4->SetFillStyle(1000);
    cutg_b1f4->SetPoint(0,11675.6,4828.37);
    cutg_b1f4->SetPoint(1,11293.7,4965.74);
    cutg_b1f4->SetPoint(2,10973.4,4956.58);
    cutg_b1f4->SetPoint(3,10837.8,4819.21);
    cutg_b1f4->SetPoint(4,10837.8,4654.37);
    cutg_b1f4->SetPoint(5,10862.5,4507.84);
    cutg_b1f4->SetPoint(6,10936.4,4397.95);
    cutg_b1f4->SetPoint(7,11293.7,4306.37);
    cutg_b1f4->SetPoint(8,11540.1,4260.58);
    cutg_b1f4->SetPoint(9,11811.2,4260.58);
    cutg_b1f4->SetPoint(10,12033,4343);
    cutg_b1f4->SetPoint(11,12033,4526.16);
    cutg_b1f4->SetPoint(12,11971.3,4636.05);
    cutg_b1f4->SetPoint(13,11885.1,4745.95);
    cutg_b1f4->SetPoint(14,11774.2,4819.21);
    cutg_b1f4->SetPoint(15,11663.3,4837.53);
    cutg_b1f4->SetPoint(16,11675.6,4828.37);
    cutg_b1f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f4
    c2->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f4 = banana_b1f4->ProjectionX("projx_cutg_b1f4",1,banana_b1f4->GetNbinsX(),"[cutg_b1f4]");              
    projx_cutg_b1f4->Rebin(2);
    projx_cutg_b1f4->Draw("");
    projx_cutg_b1f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f4 = banana_b1f4->ProjectionY("projy_cutg_b1f4",1,banana_b1f4->GetNbinsY(),"[cutg_b1f4]");              
    projy_cutg_b1f4->Rebin(2);
    projy_cutg_b1f4->Draw("");
    projy_cutg_b1f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f5 60Ni(a,a) elastic peak
    banana_b1f5->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f5->Draw();

    TCutG *cutg_b1f5 = new TCutG("cutg_b1f5",18);
    cutg_b1f5->SetVarX(" E detector 1 strip 5");
    cutg_b1f5->SetVarY("#DeltaE ");
    cutg_b1f5->SetTitle("Graph");
    cutg_b1f5->SetFillStyle(1000);
    cutg_b1f5->SetPoint(0,11714.7,4588.89);
    cutg_b1f5->SetPoint(1,11480,4698.79);
    cutg_b1f5->SetPoint(2,11284.5,4707.95);
    cutg_b1f5->SetPoint(3,11023.7,4744.58);
    cutg_b1f5->SetPoint(4,10867.3,4707.95);
    cutg_b1f5->SetPoint(5,10749.9,4598.05);
    cutg_b1f5->SetPoint(6,10671.7,4488.16);
    cutg_b1f5->SetPoint(7,10710.8,4359.95);
    cutg_b1f5->SetPoint(8,10893.4,4250.05);
    cutg_b1f5->SetPoint(9,11049.8,4158.47);
    cutg_b1f5->SetPoint(10,11440.9,4121.84);
    cutg_b1f5->SetPoint(11,11727.7,4121.84);
    cutg_b1f5->SetPoint(12,11962.4,4204.26);
    cutg_b1f5->SetPoint(13,11975.4,4387.42);
    cutg_b1f5->SetPoint(14,11884.2,4533.95);
    cutg_b1f5->SetPoint(15,11740.8,4579.74);
    cutg_b1f5->SetPoint(16,11675.6,4598.05);
    cutg_b1f5->SetPoint(17,11714.7,4588.89);
    cutg_b1f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f5
    c2->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f5 = banana_b1f5->ProjectionX("projx_cutg_b1f5",1,banana_b1f5->GetNbinsX(),"[cutg_b1f5]");              
    projx_cutg_b1f5->Rebin(2);
    projx_cutg_b1f5->Draw("");
    projx_cutg_b1f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f5 = banana_b1f5->ProjectionY("projy_cutg_b1f5",1,banana_b1f5->GetNbinsY(),"[cutg_b1f5]");              
    projy_cutg_b1f5->Rebin(2);
    projy_cutg_b1f5->Draw("");
    projy_cutg_b1f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c2->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f6 60Ni(a,a) elastic peak
    banana_b1f6->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f6->Draw();

    TCutG *cutg_b1f6 = new TCutG("cutg_b1f6",21);
    cutg_b1f6->SetVarX(" E detector 1 strip 6");
    cutg_b1f6->SetVarY("#DeltaE ");
    cutg_b1f6->SetTitle("Graph");
    cutg_b1f6->SetFillStyle(1000);
    cutg_b1f6->SetPoint(0,11985.7,4820.26);
    cutg_b1f6->SetPoint(1,11814,4891.32);
    cutg_b1f6->SetPoint(2,11517.2,4962.37);
    cutg_b1f6->SetPoint(3,11173.7,5025.53);
    cutg_b1f6->SetPoint(4,10845.8,5041.32);
    cutg_b1f6->SetPoint(5,10658.4,4954.47);
    cutg_b1f6->SetPoint(6,10642.8,4851.84);
    cutg_b1f6->SetPoint(7,10642.8,4749.21);
    cutg_b1f6->SetPoint(8,10689.6,4599.21);
    cutg_b1f6->SetPoint(9,10783.3,4520.26);
    cutg_b1f6->SetPoint(10,10939.5,4465);
    cutg_b1f6->SetPoint(11,11204.9,4370.26);
    cutg_b1f6->SetPoint(12,11407.9,4338.68);
    cutg_b1f6->SetPoint(13,11782.7,4338.68);
    cutg_b1f6->SetPoint(14,12095,4370.26);
    cutg_b1f6->SetPoint(15,12282.4,4465);
    cutg_b1f6->SetPoint(16,12266.8,4583.42);
    cutg_b1f6->SetPoint(17,12173.1,4709.74);
    cutg_b1f6->SetPoint(18,12048.2,4780.79);
    cutg_b1f6->SetPoint(19,11970.1,4828.16);
    cutg_b1f6->SetPoint(20,11985.7,4820.26);
    cutg_b1f6->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f6
    c2->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f6 = banana_b1f6->ProjectionX("projx_cutg_b1f6",1,banana_b1f6->GetNbinsX(),"[cutg_b1f6]");              
    projx_cutg_b1f6->Rebin(2);
    projx_cutg_b1f6->Draw("");
    projx_cutg_b1f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f6 = banana_b1f6->ProjectionY("projy_cutg_b1f6",1,banana_b1f6->GetNbinsY(),"[cutg_b1f6]");              
    projy_cutg_b1f6->Rebin(2);
    projy_cutg_b1f6->Draw("");
    projy_cutg_b1f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c2->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b1f7 60Ni(a,a) elastic peak
    banana_b1f7->GetXaxis()->SetRangeUser(8000,13000);
    banana_b1f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b1f7->Draw();

    TCutG *cutg_b1f7 = new TCutG("cutg_b1f7",21);
    cutg_b1f7->SetVarX(" E detector 1 strip 7");
    cutg_b1f7->SetVarY("#DeltaE ");
    cutg_b1f7->SetTitle("Graph");
    cutg_b1f7->SetFillStyle(1000);
    cutg_b1f7->SetPoint(0,12358.1,4568.95);
    cutg_b1f7->SetPoint(1,12144,4650);
    cutg_b1f7->SetPoint(2,11913.3,4738.42);
    cutg_b1f7->SetPoint(3,11682.6,4782.63);
    cutg_b1f7->SetPoint(4,11484.9,4863.68);
    cutg_b1f7->SetPoint(5,11237.8,4930);
    cutg_b1f7->SetPoint(6,11007.1,4944.74);
    cutg_b1f7->SetPoint(7,10825.9,4930);
    cutg_b1f7->SetPoint(8,10661.1,4812.11);
    cutg_b1f7->SetPoint(9,10611.7,4657.37);
    cutg_b1f7->SetPoint(10,10628.2,4532.11);
    cutg_b1f7->SetPoint(11,10809.4,4465.79);
    cutg_b1f7->SetPoint(12,11056.6,4399.47);
    cutg_b1f7->SetPoint(13,11369.6,4333.16);
    cutg_b1f7->SetPoint(14,11633.2,4303.68);
    cutg_b1f7->SetPoint(15,11979.2,4311.05);
    cutg_b1f7->SetPoint(16,12176.9,4355.26);
    cutg_b1f7->SetPoint(17,12325.2,4451.05);
    cutg_b1f7->SetPoint(18,12374.6,4524.74);
    cutg_b1f7->SetPoint(19,12325.2,4576.32);
    cutg_b1f7->SetPoint(20,12358.1,4568.95);
    cutg_b1f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b1f7
    c2->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b1f7 = banana_b1f7->ProjectionX("projx_cutg_b1f7",1,banana_b1f7->GetNbinsX(),"[cutg_b1f7]");              
    projx_cutg_b1f7->Rebin(2);
    projx_cutg_b1f7->Draw("");
    projx_cutg_b1f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b1f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c2->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b1f7 = banana_b1f7->ProjectionY("projy_cutg_b1f7",1,banana_b1f7->GetNbinsY(),"[cutg_b1f7]");              
    projy_cutg_b1f7->Rebin(2);
    projy_cutg_b1f7->Draw("");
    projy_cutg_b1f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b1f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b1f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    ///////////////////
    // E DETECTOR b2 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c3 = new TCanvas("c3","c3:b2 bananas",1400,800);
    c3->Divide(8,3,0,0);
    c3->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b2f0 60Ni(a,a) elastic peak
    banana_b2f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f0->Draw();
    TCutG *cutg_b2f0 = new TCutG("cutg_b2f0",22);
    cutg_b2f0->SetVarX(" E detector 2 strip 0");
    cutg_b2f0->SetVarY("#DeltaE ");
    cutg_b2f0->SetTitle("Graph");
    cutg_b2f0->SetFillStyle(1000);
    cutg_b2f0->SetPoint(0,10569.3,4970.68);
    cutg_b2f0->SetPoint(1,10447.1,4926.58);
    cutg_b2f0->SetPoint(2,10390.7,4831.03);
    cutg_b2f0->SetPoint(3,10362.5,4713.42);
    cutg_b2f0->SetPoint(4,10456.5,4529.66);
    cutg_b2f0->SetPoint(5,10672.8,4441.46);
    cutg_b2f0->SetPoint(6,10964.2,4331.21);
    cutg_b2f0->SetPoint(7,11331,4287.11);
    cutg_b2f0->SetPoint(8,11613,4265.05);
    cutg_b2f0->SetPoint(9,11923.3,4279.75);
    cutg_b2f0->SetPoint(10,12017.4,4390.01);
    cutg_b2f0->SetPoint(11,12017.4,4537.01);
    cutg_b2f0->SetPoint(12,11951.5,4632.57);
    cutg_b2f0->SetPoint(13,11810.5,4706.07);
    cutg_b2f0->SetPoint(14,11622.4,4794.27);
    cutg_b2f0->SetPoint(15,11359.2,4867.78);
    cutg_b2f0->SetPoint(16,11095.9,4911.88);
    cutg_b2f0->SetPoint(17,10917.2,4985.38);
    cutg_b2f0->SetPoint(18,10804.4,4985.38);
    cutg_b2f0->SetPoint(19,10644.5,4985.38);
    cutg_b2f0->SetPoint(20,10559.9,4978.03);
    cutg_b2f0->SetPoint(21,10569.3,4970.68);
    cutg_b2f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f0
    c3->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f0 = banana_b2f0->ProjectionX("projx_cutg_b2f0",1,banana_b2f0->GetNbinsX(),"[cutg_b2f0]");              
    projx_cutg_b2f0->Rebin(2);
    projx_cutg_b2f0->Draw("");
    projx_cutg_b2f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f0 = banana_b2f0->ProjectionY("projy_cutg_b2f0",1,banana_b2f0->GetNbinsY(),"[cutg_b2f0]");              
    projy_cutg_b2f0->Rebin(2);
    projy_cutg_b2f0->Draw("");
    projy_cutg_b2f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f1 60Ni(a,a) elastic peak
    banana_b2f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f1->Draw();
   
    TCutG *cutg_b2f1 = new TCutG("cutg_b2f1",21);
    cutg_b2f1->SetVarX(" E detector 2 strip 1");
    cutg_b2f1->SetVarY("#DeltaE ");
    cutg_b2f1->SetTitle("Graph");
    cutg_b2f1->SetFillStyle(1000);
    cutg_b2f1->SetPoint(0,11918.5,4733.06);
    cutg_b2f1->SetPoint(1,11664.6,4906.47);
    cutg_b2f1->SetPoint(2,11453.1,4947.76);
    cutg_b2f1->SetPoint(3,11142.8,5013.82);
    cutg_b2f1->SetPoint(4,10818.4,5079.88);
    cutg_b2f1->SetPoint(5,10606.8,5071.62);
    cutg_b2f1->SetPoint(6,10451.7,5022.08);
    cutg_b2f1->SetPoint(7,10381.2,4922.99);
    cutg_b2f1->SetPoint(8,10381.2,4782.6);
    cutg_b2f1->SetPoint(9,10494,4625.71);
    cutg_b2f1->SetPoint(10,10663.2,4493.58);
    cutg_b2f1->SetPoint(11,10973.5,4377.98);
    cutg_b2f1->SetPoint(12,11269.7,4245.85);
    cutg_b2f1->SetPoint(13,11636.4,4196.31);
    cutg_b2f1->SetPoint(14,12003.1,4212.82);
    cutg_b2f1->SetPoint(15,12257,4295.4);
    cutg_b2f1->SetPoint(16,12257,4501.84);
    cutg_b2f1->SetPoint(17,12101.9,4625.71);
    cutg_b2f1->SetPoint(18,12045.5,4683.51);
    cutg_b2f1->SetPoint(19,11904.4,4757.83);
    cutg_b2f1->SetPoint(20,11918.5,4733.06);
    cutg_b2f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f1
    c3->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f1 = banana_b2f1->ProjectionX("projx_cutg_b2f1",1,banana_b2f1->GetNbinsX(),"[cutg_b2f1]");              
    projx_cutg_b2f1->Rebin(2);
    projx_cutg_b2f1->Draw("");
    projx_cutg_b2f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f1 = banana_b2f1->ProjectionY("projy_cutg_b2f1",1,banana_b2f1->GetNbinsY(),"[cutg_b2f1]");              
    projy_cutg_b2f1->Rebin(2);
    projy_cutg_b2f1->Draw("");
    projy_cutg_b2f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f2 60Ni(a,a) elastic peak
    banana_b2f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f2->Draw();

    TCutG *cutg_b2f2 = new TCutG("cutg_b2f2",16);
    cutg_b2f2->SetVarX(" E detector 2 strip 2");
    cutg_b2f2->SetVarY("#DeltaE ");
    cutg_b2f2->SetTitle("Graph");
    cutg_b2f2->SetFillStyle(1000);
    cutg_b2f2->SetPoint(0,10773.6,5109.26);
    cutg_b2f2->SetPoint(1,10642.7,4898.73);
    cutg_b2f2->SetPoint(2,10642.7,4753.54);
    cutg_b2f2->SetPoint(3,10629.6,4630.13);
    cutg_b2f2->SetPoint(4,10852.1,4513.97);
    cutg_b2f2->SetPoint(5,11218.5,4376.04);
    cutg_b2f2->SetPoint(6,11846.7,4238.11);
    cutg_b2f2->SetPoint(7,12147.8,4259.89);
    cutg_b2f2->SetPoint(8,12213.2,4463.16);
    cutg_b2f2->SetPoint(9,12108.5,4775.32);
    cutg_b2f2->SetPoint(10,11846.7,4949.55);
    cutg_b2f2->SetPoint(11,11545.7,5022.14);
    cutg_b2f2->SetPoint(12,11270.9,5029.4);
    cutg_b2f2->SetPoint(13,10839,5072.96);
    cutg_b2f2->SetPoint(14,10747.4,5072.96);
    cutg_b2f2->SetPoint(15,10773.6,5109.26);
    cutg_b2f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f2
    c3->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f2 = banana_b2f2->ProjectionX("projx_cutg_b2f2",1,banana_b2f2->GetNbinsX(),"[cutg_b2f2]");              
    projx_cutg_b2f2->Rebin(2);
    projx_cutg_b2f2->Draw("");
    projx_cutg_b2f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f2 = banana_b2f2->ProjectionY("projy_cutg_b2f2",1,banana_b2f2->GetNbinsY(),"[cutg_b2f2]");              
    projy_cutg_b2f2->Rebin(2);
    projy_cutg_b2f2->Draw("");
    projy_cutg_b2f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f3 60Ni(a,a) elastic peak
    banana_b2f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f3->Draw();

    TCutG *cutg_b2f3 = new TCutG("cutg_b2f3",15);
    cutg_b2f3->SetVarX(" E detector 2 strip 3");
    cutg_b2f3->SetVarY("#DeltaE ");
    cutg_b2f3->SetTitle("Graph");
    cutg_b2f3->SetFillStyle(1000);
    cutg_b2f3->SetPoint(0,11965.4,5020);
    cutg_b2f3->SetPoint(1,11579.6,5198.95);
    cutg_b2f3->SetPoint(2,11147.1,5209.47);
    cutg_b2f3->SetPoint(3,10889.9,5167.37);
    cutg_b2f3->SetPoint(4,10714.6,5104.21);
    cutg_b2f3->SetPoint(5,10714.6,4904.21);
    cutg_b2f3->SetPoint(6,10761.3,4746.32);
    cutg_b2f3->SetPoint(7,10983.4,4672.63);
    cutg_b2f3->SetPoint(8,11404.3,4567.37);
    cutg_b2f3->SetPoint(9,11801.7,4567.37);
    cutg_b2f3->SetPoint(10,12058.9,4630.53);
    cutg_b2f3->SetPoint(11,12129,4767.37);
    cutg_b2f3->SetPoint(12,12035.5,4883.16);
    cutg_b2f3->SetPoint(13,11942,5030.53);
    cutg_b2f3->SetPoint(14,11965.4,5020);
    cutg_b2f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f3
    c3->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f3 = banana_b2f3->ProjectionX("projx_cutg_b2f3",1,banana_b2f3->GetNbinsX(),"[cutg_b2f3]");              
    projx_cutg_b2f3->Rebin(2);
    projx_cutg_b2f3->Draw("");
    projx_cutg_b2f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f3 = banana_b2f3->ProjectionY("projy_cutg_b2f3",1,banana_b2f3->GetNbinsY(),"[cutg_b2f3]");              
    projy_cutg_b2f3->Rebin(2);
    projy_cutg_b2f3->Draw("");
    projy_cutg_b2f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f4 60Ni(a,a) elastic peak
    banana_b2f4->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f4->Draw();

    TCutG *cutg_b2f4 = new TCutG("cutg_b2f4",21);
    cutg_b2f4->SetVarX(" E detector 2 strip 4");
    cutg_b2f4->SetVarY("#DeltaE ");
    cutg_b2f4->SetTitle("Graph");
    cutg_b2f4->SetFillStyle(1000);
    cutg_b2f4->SetPoint(0,11162.3,5001.87);
    cutg_b2f4->SetPoint(1,10948.5,5009.31);
    cutg_b2f4->SetPoint(2,10759.8,4949.78);
    cutg_b2f4->SetPoint(3,10709.5,4823.28);
    cutg_b2f4->SetPoint(4,10734.6,4689.35);
    cutg_b2f4->SetPoint(5,10784.9,4607.5);
    cutg_b2f4->SetPoint(6,11074.3,4473.56);
    cutg_b2f4->SetPoint(7,11413.9,4369.38);
    cutg_b2f4->SetPoint(8,11741,4332.18);
    cutg_b2f4->SetPoint(9,12118.4,4347.06);
    cutg_b2f4->SetPoint(10,12294.5,4451.23);
    cutg_b2f4->SetPoint(11,12432.8,4562.85);
    cutg_b2f4->SetPoint(12,12420.3,4748.87);
    cutg_b2f4->SetPoint(13,12307.1,4897.7);
    cutg_b2f4->SetPoint(14,12080.6,4927.46);
    cutg_b2f4->SetPoint(15,11803.9,5001.87);
    cutg_b2f4->SetPoint(16,11514.5,5039.07);
    cutg_b2f4->SetPoint(17,11263,5031.63);
    cutg_b2f4->SetPoint(18,11099.4,5016.75);
    cutg_b2f4->SetPoint(19,11036.5,5001.87);
    cutg_b2f4->SetPoint(20,11162.3,5001.87);
    cutg_b2f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f4
    c3->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f4 = banana_b2f4->ProjectionX("projx_cutg_b2f4",1,banana_b2f4->GetNbinsX(),"[cutg_b2f4]");              
    projx_cutg_b2f4->Rebin(2);
    projx_cutg_b2f4->Draw("");
    projx_cutg_b2f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f4 = banana_b2f4->ProjectionY("projy_cutg_b2f4",1,banana_b2f4->GetNbinsY(),"[cutg_b2f4]");              
    projy_cutg_b2f4->Rebin(2);
    projy_cutg_b2f4->Draw("");
    projy_cutg_b2f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f5 60Ni(a,a) elastic peak
    banana_b2f5->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f5->Draw();

    TCutG *cutg_b2f5 = new TCutG("cutg_b2f5",24);
    cutg_b2f5->SetVarX(" E detector 2 strip 5");
    cutg_b2f5->SetVarY("#DeltaE ");
    cutg_b2f5->SetTitle("Graph");
    cutg_b2f5->SetFillStyle(1000);
    cutg_b2f5->SetPoint(0,11961.8,4770.99);
    cutg_b2f5->SetPoint(1,11862.2,4873.53);
    cutg_b2f5->SetPoint(2,11691.4,4976.07);
    cutg_b2f5->SetPoint(3,11506.4,5017.09);
    cutg_b2f5->SetPoint(4,11250.2,5058.1);
    cutg_b2f5->SetPoint(5,11136.4,5047.85);
    cutg_b2f5->SetPoint(6,10965.6,5006.83);
    cutg_b2f5->SetPoint(7,10880.2,4863.28);
    cutg_b2f5->SetPoint(8,10837.5,4760.74);
    cutg_b2f5->SetPoint(9,10866,4637.69);
    cutg_b2f5->SetPoint(10,10880.2,4565.91);
    cutg_b2f5->SetPoint(11,11136.4,4453.11);
    cutg_b2f5->SetPoint(12,11321.4,4381.33);
    cutg_b2f5->SetPoint(13,11534.8,4350.57);
    cutg_b2f5->SetPoint(14,11719.8,4309.56);
    cutg_b2f5->SetPoint(15,11990.2,4299.3);
    cutg_b2f5->SetPoint(16,12061.4,4340.32);
    cutg_b2f5->SetPoint(17,12232.2,4483.87);
    cutg_b2f5->SetPoint(18,12217.9,4565.91);
    cutg_b2f5->SetPoint(19,12161,4688.96);
    cutg_b2f5->SetPoint(20,12089.9,4740.23);
    cutg_b2f5->SetPoint(21,12004.5,4781.24);
    cutg_b2f5->SetPoint(22,11976,4781.24);
    cutg_b2f5->SetPoint(23,11961.8,4770.99);
    cutg_b2f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f5
    c3->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f5 = banana_b2f5->ProjectionX("projx_cutg_b2f5",1,banana_b2f5->GetNbinsX(),"[cutg_b2f5]");              
    projx_cutg_b2f5->Rebin(2);
    projx_cutg_b2f5->Draw("");
    projx_cutg_b2f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f5 = banana_b2f5->ProjectionY("projy_cutg_b2f5",1,banana_b2f5->GetNbinsY(),"[cutg_b2f5]");              
    projy_cutg_b2f5->Rebin(2);
    projy_cutg_b2f5->Draw("");
    projy_cutg_b2f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f6 60Ni(a,a) elastic peak
    banana_b2f6->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f6->Draw();

    TCutG *cutg_b2f6 = new TCutG("cutg_b2f6",25);
    cutg_b2f6->SetVarX(" E detector 2 strip 6");
    cutg_b2f6->SetVarY("#DeltaE ");
    cutg_b2f6->SetTitle("Graph");
    cutg_b2f6->SetFillStyle(1000);
    cutg_b2f6->SetPoint(0,11022,4456.71);
    cutg_b2f6->SetPoint(1,11264.9,4374.13);
    cutg_b2f6->SetPoint(2,11611.8,4315.15);
    cutg_b2f6->SetPoint(3,11866.1,4297.45);
    cutg_b2f6->SetPoint(4,12155.2,4285.65);
    cutg_b2f6->SetPoint(5,12270.8,4321.04);
    cutg_b2f6->SetPoint(6,12340.2,4380.03);
    cutg_b2f6->SetPoint(7,12340.2,4515.69);
    cutg_b2f6->SetPoint(8,12213,4633.66);
    cutg_b2f6->SetPoint(9,12051.1,4716.23);
    cutg_b2f6->SetPoint(10,11912.4,4787.01);
    cutg_b2f6->SetPoint(11,11658,4887.29);
    cutg_b2f6->SetPoint(12,11415.2,4934.47);
    cutg_b2f6->SetPoint(13,11241.7,4934.47);
    cutg_b2f6->SetPoint(14,11033.6,4928.58);
    cutg_b2f6->SetPoint(15,10860.2,4887.29);
    cutg_b2f6->SetPoint(16,10756.1,4846);
    cutg_b2f6->SetPoint(17,10709.8,4757.52);
    cutg_b2f6->SetPoint(18,10663.6,4669.05);
    cutg_b2f6->SetPoint(19,10652,4568.77);
    cutg_b2f6->SetPoint(20,10721.4,4527.49);
    cutg_b2f6->SetPoint(21,10813.9,4468.5);
    cutg_b2f6->SetPoint(22,10964.2,4421.32);
    cutg_b2f6->SetPoint(23,11126.1,4421.32);
    cutg_b2f6->SetPoint(24,11022,4456.71);
    cutg_b2f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b2f6
    c3->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f6 = banana_b2f6->ProjectionX("projx_cutg_b2f6",1,banana_b2f6->GetNbinsX(),"[cutg_b2f6]");              
    projx_cutg_b2f6->Rebin(2);
    projx_cutg_b2f6->Draw("");
    projx_cutg_b2f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f6 = banana_b2f6->ProjectionY("projy_cutg_b2f6",1,banana_b2f6->GetNbinsY(),"[cutg_b2f6]");              
    projy_cutg_b2f6->Rebin(2);
    projy_cutg_b2f6->Draw("");
    projy_cutg_b2f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c3->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b2f7 60Ni(a,a) elastic peak
    banana_b2f7->GetXaxis()->SetRangeUser(8000,13000);
    banana_b2f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b2f7->Draw();

    TCutG *cutg_b2f7 = new TCutG("cutg_b2f7",21);
    cutg_b2f7->SetVarX(" E detector 2 strip 7");
    cutg_b2f7->SetVarY("#DeltaE ");
    cutg_b2f7->SetTitle("Graph");
    cutg_b2f7->SetFillStyle(1000);
    cutg_b2f7->SetPoint(0,10713.4,4882.01);
    cutg_b2f7->SetPoint(1,10842,4811.78);
    cutg_b2f7->SetPoint(2,11134.3,4733.74);
    cutg_b2f7->SetPoint(3,11485,4655.7);
    cutg_b2f7->SetPoint(4,11812.3,4608.87);
    cutg_b2f7->SetPoint(5,12127.9,4608.87);
    cutg_b2f7->SetPoint(6,12361.7,4718.13);
    cutg_b2f7->SetPoint(7,12326.7,4913.23);
    cutg_b2f7->SetPoint(8,12163,5045.9);
    cutg_b2f7->SetPoint(9,11929.2,5123.94);
    cutg_b2f7->SetPoint(10,11555.1,5233.19);
    cutg_b2f7->SetPoint(11,11239.5,5303.43);
    cutg_b2f7->SetPoint(12,10970.6,5350.25);
    cutg_b2f7->SetPoint(13,10818.7,5350.25);
    cutg_b2f7->SetPoint(14,10666.7,5319.04);
    cutg_b2f7->SetPoint(15,10561.5,5233.19);
    cutg_b2f7->SetPoint(16,10514.7,5108.33);
    cutg_b2f7->SetPoint(17,10514.7,4967.86);
    cutg_b2f7->SetPoint(18,10608.2,4913.23);
    cutg_b2f7->SetPoint(19,10713.4,4882.01);
    cutg_b2f7->SetPoint(20,10713.4,4882.01);
    cutg_b2f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b2f7
    c3->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b2f7 = banana_b2f7->ProjectionX("projx_cutg_b2f7",1,banana_b2f7->GetNbinsX(),"[cutg_b2f7]");              
    projx_cutg_b2f7->Rebin(2);
    projx_cutg_b2f7->Draw("");
    projx_cutg_b2f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b2f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c3->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b2f7 = banana_b2f7->ProjectionY("projy_cutg_b2f7",1,banana_b2f7->GetNbinsY(),"[cutg_b2f7]");              
    projy_cutg_b2f7->Rebin(2);
    projy_cutg_b2f7->Draw("");
    projy_cutg_b2f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b2f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b2f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    ///////////////////
    // E DETECTOR b3 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c4 = new TCanvas("c4","c4:b3 bananas",1400,800);
    c4->Divide(8,3,0,0);
    c4->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b3f0 60Ni(a,a) elastic peak
    banana_b3f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f0->Draw();
    TCutG *cutg_b3f0 = new TCutG("cutg_b3f0",22);
    cutg_b3f0->SetVarX(" E detector 3 strip 0");
    cutg_b3f0->SetVarY("#DeltaE ");
    cutg_b3f0->SetTitle("Graph");
    cutg_b3f0->SetFillStyle(1000);
    cutg_b3f0->SetPoint(0,12002.9,5023.41);
    cutg_b3f0->SetPoint(1,11847.6,5132.3);
    cutg_b3f0->SetPoint(2,11560.9,5250.27);
    cutg_b3f0->SetPoint(3,11274.3,5322.87);
    cutg_b3f0->SetPoint(4,10999.6,5377.31);
    cutg_b3f0->SetPoint(5,10772.6,5404.54);
    cutg_b3f0->SetPoint(6,10665.1,5331.94);
    cutg_b3f0->SetPoint(7,10581.5,5250.27);
    cutg_b3f0->SetPoint(8,10581.5,5132.3);
    cutg_b3f0->SetPoint(9,10641.2,5005.26);
    cutg_b3f0->SetPoint(10,10748.7,4950.82);
    cutg_b3f0->SetPoint(11,10856.2,4878.22);
    cutg_b3f0->SetPoint(12,11095.1,4814.7);
    cutg_b3f0->SetPoint(13,11274.3,4742.11);
    cutg_b3f0->SetPoint(14,11537.1,4660.44);
    cutg_b3f0->SetPoint(15,11835.7,4578.77);
    cutg_b3f0->SetPoint(16,12050.6,4596.91);
    cutg_b3f0->SetPoint(17,12146.2,4696.73);
    cutg_b3f0->SetPoint(18,12134.3,4832.85);
    cutg_b3f0->SetPoint(19,12062.6,5005.26);
    cutg_b3f0->SetPoint(20,11979,5041.56);
    cutg_b3f0->SetPoint(21,12002.9,5023.41);
    cutg_b3f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f0
    c4->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f0 = banana_b3f0->ProjectionX("projx_cutg_b3f0",1,banana_b3f0->GetNbinsX(),"[cutg_b3f0]");              
    projx_cutg_b3f0->Rebin(2);
    projx_cutg_b3f0->Draw("");
    projx_cutg_b3f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f0 = banana_b3f0->ProjectionY("projy_cutg_b3f0",1,banana_b3f0->GetNbinsY(),"[cutg_b3f0]");              
    projy_cutg_b3f0->Rebin(2);
    projy_cutg_b3f0->Draw("");
    projy_cutg_b3f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f1 60Ni(a,a) elastic peak
    banana_b3f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f1->Draw();
   
    TCutG *cutg_b3f1 = new TCutG("cutg_b3f1",20);
    cutg_b3f1->SetVarX(" E detector 3 strip 1");
    cutg_b3f1->SetVarY("#DeltaE ");
    cutg_b3f1->SetTitle("Graph");
    cutg_b3f1->SetFillStyle(1000);
    cutg_b3f1->SetPoint(0,10892.6,5320.83);
    cutg_b3f1->SetPoint(1,10744.9,5311.76);
    cutg_b3f1->SetPoint(2,10618.4,5257.31);
    cutg_b3f1->SetPoint(3,10576.2,5066.75);
    cutg_b3f1->SetPoint(4,10702.8,4930.64);
    cutg_b3f1->SetPoint(5,11029.7,4821.74);
    cutg_b3f1->SetPoint(6,11303.9,4740.07);
    cutg_b3f1->SetPoint(7,11694.1,4667.48);
    cutg_b3f1->SetPoint(8,11926.1,4613.03);
    cutg_b3f1->SetPoint(9,12073.8,4594.88);
    cutg_b3f1->SetPoint(10,12200.3,4640.25);
    cutg_b3f1->SetPoint(11,12200.3,4785.44);
    cutg_b3f1->SetPoint(12,12137.1,4948.78);
    cutg_b3f1->SetPoint(13,12021.1,5057.68);
    cutg_b3f1->SetPoint(14,11831.2,5157.5);
    cutg_b3f1->SetPoint(15,11599.2,5257.31);
    cutg_b3f1->SetPoint(16,11398.8,5284.54);
    cutg_b3f1->SetPoint(17,11145.7,5293.61);
    cutg_b3f1->SetPoint(18,10977,5320.83);
    cutg_b3f1->SetPoint(19,10882,5320.83);
    cutg_b3f1->SetPoint(20,10892.6,5320.83);
    cutg_b3f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f1
    c4->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f1 = banana_b3f1->ProjectionX("projx_cutg_b3f1",1,banana_b3f1->GetNbinsX(),"[cutg_b3f1]");              
    projx_cutg_b3f1->Rebin(2);
    projx_cutg_b3f1->Draw("");
    projx_cutg_b3f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f1 = banana_b3f1->ProjectionY("projy_cutg_b3f1",1,banana_b3f1->GetNbinsY(),"[cutg_b3f1]");              
    projy_cutg_b3f1->Rebin(2);
    projy_cutg_b3f1->Draw("");
    projy_cutg_b3f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f2 60Ni(a,a) elastic peak
    banana_b3f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f2->Draw();

    TCutG *cutg_b3f2 = new TCutG("cutg_b3f2",25);
    cutg_b3f2->SetVarX(" E detector 3 strip 2");
    cutg_b3f2->SetVarY("#DeltaE ");
    cutg_b3f2->SetTitle("Graph");
    cutg_b3f2->SetFillStyle(1000);
    cutg_b3f2->SetPoint(0,10875.7,4772.99);
    cutg_b3f2->SetPoint(1,10991.3,4681.52);
    cutg_b3f2->SetPoint(2,11178.1,4609.66);
    cutg_b3f2->SetPoint(3,11409.4,4498.58);
    cutg_b3f2->SetPoint(4,11614,4433.25);
    cutg_b3f2->SetPoint(5,11774.1,4407.11);
    cutg_b3f2->SetPoint(6,12005.3,4413.65);
    cutg_b3f2->SetPoint(7,12218.8,4452.85);
    cutg_b3f2->SetPoint(8,12298.8,4550.85);
    cutg_b3f2->SetPoint(9,12298.8,4661.92);
    cutg_b3f2->SetPoint(10,12245.5,4766.46);
    cutg_b3f2->SetPoint(11,12058.7,4884.07);
    cutg_b3f2->SetPoint(12,11925.3,4955.93);
    cutg_b3f2->SetPoint(13,11738.5,5008.2);
    cutg_b3f2->SetPoint(14,11542.8,5086.61);
    cutg_b3f2->SetPoint(15,11347.1,5119.27);
    cutg_b3f2->SetPoint(16,11169.2,5119.27);
    cutg_b3f2->SetPoint(17,11026.9,5106.21);
    cutg_b3f2->SetPoint(18,10938,5060.47);
    cutg_b3f2->SetPoint(19,10902.4,4995.14);
    cutg_b3f2->SetPoint(20,10875.7,4890.6);
    cutg_b3f2->SetPoint(21,10884.6,4825.26);
    cutg_b3f2->SetPoint(22,10884.6,4772.99);
    cutg_b3f2->SetPoint(23,10884.6,4753.39);
    cutg_b3f2->SetPoint(24,10875.7,4772.99);
    cutg_b3f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f2
    c4->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f2 = banana_b3f2->ProjectionX("projx_cutg_b3f2",1,banana_b3f2->GetNbinsX(),"[cutg_b3f2]");              
    projx_cutg_b3f2->Rebin(2);
    projx_cutg_b3f2->Draw("");
    projx_cutg_b3f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f2 = banana_b3f2->ProjectionY("projy_cutg_b3f2",1,banana_b3f2->GetNbinsY(),"[cutg_b3f2]");              
    projy_cutg_b3f2->Rebin(2);
    projy_cutg_b3f2->Draw("");
    projy_cutg_b3f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f3 60Ni(a,a) elastic peak
    banana_b3f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f3->Draw();

    TCutG *cutg_b3f3 = new TCutG("cutg_b3f3",19);
    cutg_b3f3->SetVarX(" E detector 3 strip 3");
    cutg_b3f3->SetVarY("#DeltaE ");
    cutg_b3f3->SetTitle("Graph");
    cutg_b3f3->SetFillStyle(1000);
    cutg_b3f3->SetPoint(0,10993,4824.33);
    cutg_b3f3->SetPoint(1,11214.1,4738.21);
    cutg_b3f3->SetPoint(2,11357.8,4691.84);
    cutg_b3f3->SetPoint(3,11601,4632.22);
    cutg_b3f3->SetPoint(4,11866.3,4585.85);
    cutg_b3f3->SetPoint(5,12043.2,4565.98);
    cutg_b3f3->SetPoint(6,12142.7,4605.73);
    cutg_b3f3->SetPoint(7,12220.1,4698.47);
    cutg_b3f3->SetPoint(8,12220.1,4817.7);
    cutg_b3f3->SetPoint(9,12065.3,4903.82);
    cutg_b3f3->SetPoint(10,11877.4,4976.69);
    cutg_b3f3->SetPoint(11,11645.2,5049.56);
    cutg_b3f3->SetPoint(12,11457.3,5089.3);
    cutg_b3f3->SetPoint(13,11225.2,5135.67);
    cutg_b3f3->SetPoint(14,11059.4,5076.05);
    cutg_b3f3->SetPoint(15,10982,4983.31);
    cutg_b3f3->SetPoint(16,10970.9,4870.7);
    cutg_b3f3->SetPoint(17,11004.1,4817.7);
    cutg_b3f3->SetPoint(18,10993,4824.33);
    cutg_b3f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f3
    c4->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f3 = banana_b3f3->ProjectionX("projx_cutg_b3f3",1,banana_b3f3->GetNbinsX(),"[cutg_b3f3]");              
    projx_cutg_b3f3->Rebin(2);
    projx_cutg_b3f3->Draw("");
    projx_cutg_b3f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f3 = banana_b3f3->ProjectionY("projy_cutg_b3f3",1,banana_b3f3->GetNbinsY(),"[cutg_b3f3]");              
    projy_cutg_b3f3->Rebin(2);
    projy_cutg_b3f3->Draw("");
    projy_cutg_b3f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f4 60Ni(a,a) elastic peak
    banana_b3f4->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f4->Draw();

    TCutG *cutg_b3f4 = new TCutG("cutg_b3f4",21);
    cutg_b3f4->SetVarX(" E detector 3 strip 4");
    cutg_b3f4->SetVarY("#DeltaE ");
    cutg_b3f4->SetTitle("Graph");
    cutg_b3f4->SetFillStyle(1000);
    cutg_b3f4->SetPoint(0,11017.6,4726.85);
    cutg_b3f4->SetPoint(1,11140.6,4597.99);
    cutg_b3f4->SetPoint(2,11386.6,4527.12);
    cutg_b3f4->SetPoint(3,11571.1,4482.02);
    cutg_b3f4->SetPoint(4,11694.1,4456.25);
    cutg_b3f4->SetPoint(5,12032.3,4449.81);
    cutg_b3f4->SetPoint(6,12293.7,4475.58);
    cutg_b3f4->SetPoint(7,12631.9,4578.67);
    cutg_b3f4->SetPoint(8,12662.7,4681.75);
    cutg_b3f4->SetPoint(9,12524.3,4842.82);
    cutg_b3f4->SetPoint(10,12139.9,4920.14);
    cutg_b3f4->SetPoint(11,11863.2,4991.01);
    cutg_b3f4->SetPoint(12,11632.6,5016.78);
    cutg_b3f4->SetPoint(13,11355.8,5042.55);
    cutg_b3f4->SetPoint(14,11125.2,5048.99);
    cutg_b3f4->SetPoint(15,10971.4,5016.78);
    cutg_b3f4->SetPoint(16,10971.4,4920.14);
    cutg_b3f4->SetPoint(17,10925.3,4842.82);
    cutg_b3f4->SetPoint(18,10956.1,4765.51);
    cutg_b3f4->SetPoint(19,11017.6,4720.41);
    cutg_b3f4->SetPoint(20,11017.6,4726.85);
    cutg_b3f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f4
    c4->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f4 = banana_b3f4->ProjectionX("projx_cutg_b3f4",1,banana_b3f4->GetNbinsX(),"[cutg_b3f4]");              
    projx_cutg_b3f4->Rebin(2);
    projx_cutg_b3f4->Draw("");
    projx_cutg_b3f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f4 = banana_b3f4->ProjectionY("projy_cutg_b3f4",1,banana_b3f4->GetNbinsY(),"[cutg_b3f4]");              
    projy_cutg_b3f4->Rebin(2);
    projy_cutg_b3f4->Draw("");
    projy_cutg_b3f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f5 60Ni(a,a) elastic peak
    banana_b3f5->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f5->Draw();

    TCutG *cutg_b3f5 = new TCutG("cutg_b3f5",23);
    cutg_b3f5->SetVarX(" E detector 3 strip 5");
    cutg_b3f5->SetVarY("#DeltaE ");
    cutg_b3f5->SetTitle("Graph");
    cutg_b3f5->SetFillStyle(1000);
    cutg_b3f5->SetPoint(0,11181.2,4808.16);
    cutg_b3f5->SetPoint(1,11350.4,4723.77);
    cutg_b3f5->SetPoint(2,11618.4,4681.57);
    cutg_b3f5->SetPoint(3,11971,4605.62);
    cutg_b3f5->SetPoint(4,12351.8,4588.74);
    cutg_b3f5->SetPoint(5,12619.8,4614.06);
    cutg_b3f5->SetPoint(6,12690.3,4715.33);
    cutg_b3f5->SetPoint(7,12591.6,4867.23);
    cutg_b3f5->SetPoint(8,12408.2,4976.94);
    cutg_b3f5->SetPoint(9,12281.3,5027.58);
    cutg_b3f5->SetPoint(10,12140.2,5078.21);
    cutg_b3f5->SetPoint(11,11886.4,5120.41);
    cutg_b3f5->SetPoint(12,11688.9,5171.04);
    cutg_b3f5->SetPoint(13,11449.1,5221.68);
    cutg_b3f5->SetPoint(14,11251.7,5255.44);
    cutg_b3f5->SetPoint(15,11082.4,5247);
    cutg_b3f5->SetPoint(16,10997.8,5187.92);
    cutg_b3f5->SetPoint(17,10997.8,5069.77);
    cutg_b3f5->SetPoint(18,11026,4934.75);
    cutg_b3f5->SetPoint(19,11096.5,4875.67);
    cutg_b3f5->SetPoint(20,11167.1,4816.6);
    cutg_b3f5->SetPoint(21,11223.5,4799.72);
    cutg_b3f5->SetPoint(22,11181.2,4808.16);
    cutg_b3f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f5
    c4->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f5 = banana_b3f5->ProjectionX("projx_cutg_b3f5",1,banana_b3f5->GetNbinsX(),"[cutg_b3f5]");              
    projx_cutg_b3f5->Rebin(2);
    projx_cutg_b3f5->Draw("");
    projx_cutg_b3f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f5 = banana_b3f5->ProjectionY("projy_cutg_b3f5",1,banana_b3f5->GetNbinsY(),"[cutg_b3f5]");              
    projy_cutg_b3f5->Rebin(2);
    projy_cutg_b3f5->Draw("");
    projy_cutg_b3f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f6 60Ni(a,a) elastic peak
    banana_b3f6->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f6->Draw();

    TCutG *cutg_b3f6 = new TCutG("cutg_b3f6",23);
    cutg_b3f6->SetVarX(" E detector 3 strip 6");
    cutg_b3f6->SetVarY("#DeltaE ");
    cutg_b3f6->SetTitle("Graph");
    cutg_b3f6->SetFillStyle(1000);
    cutg_b3f6->SetPoint(0,11149.6,4831.5);
    cutg_b3f6->SetPoint(1,11257.4,4747.65);
    cutg_b3f6->SetPoint(2,11378.6,4698.74);
    cutg_b3f6->SetPoint(3,11540.2,4642.84);
    cutg_b3f6->SetPoint(4,11755.7,4607.9);
    cutg_b3f6->SetPoint(5,11998.1,4558.99);
    cutg_b3f6->SetPoint(6,12146.3,4558.99);
    cutg_b3f6->SetPoint(7,12361.8,4593.93);
    cutg_b3f6->SetPoint(8,12469.6,4677.78);
    cutg_b3f6->SetPoint(9,12496.5,4817.52);
    cutg_b3f6->SetPoint(10,12415.7,4957.27);
    cutg_b3f6->SetPoint(11,12281,5048.1);
    cutg_b3f6->SetPoint(12,12052,5138.94);
    cutg_b3f6->SetPoint(13,11782.6,5229.77);
    cutg_b3f6->SetPoint(14,11607.5,5250.74);
    cutg_b3f6->SetPoint(15,11365.1,5264.71);
    cutg_b3f6->SetPoint(16,11203.5,5243.75);
    cutg_b3f6->SetPoint(17,11109.2,5152.91);
    cutg_b3f6->SetPoint(18,11068.8,5034.13);
    cutg_b3f6->SetPoint(19,11055.3,4929.32);
    cutg_b3f6->SetPoint(20,11095.7,4859.45);
    cutg_b3f6->SetPoint(21,11149.6,4831.5);
    cutg_b3f6->SetPoint(22,11149.6,4831.5);
    cutg_b3f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b3f6
    c4->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f6 = banana_b3f6->ProjectionX("projx_cutg_b3f6",1,banana_b3f6->GetNbinsX(),"[cutg_b3f6]");              
    projx_cutg_b3f6->Rebin(2);
    projx_cutg_b3f6->Draw("");
    projx_cutg_b3f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f6 = banana_b3f6->ProjectionY("projy_cutg_b3f6",1,banana_b3f6->GetNbinsY(),"[cutg_b3f6]");              
    projy_cutg_b3f6->Rebin(2);
    projy_cutg_b3f6->Draw("");
    projy_cutg_b3f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c4->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b3f7 60Ni(a,a) elastic peak
    banana_b3f7->GetXaxis()->SetRangeUser(8000,13000);
    banana_b3f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b3f7->Draw();

    TCutG *cutg_b3f7 = new TCutG("cutg_b3f7",26);
    cutg_b3f7->SetVarX(" E detector 3 strip 7");
    cutg_b3f7->SetVarY("#DeltaE ");
    cutg_b3f7->SetTitle("Graph");
    cutg_b3f7->SetFillStyle(1000);
    cutg_b3f7->SetPoint(0,11054.1,4967.69);
    cutg_b3f7->SetPoint(1,11218.8,4858.25);
    cutg_b3f7->SetPoint(2,11392.6,4791.37);
    cutg_b3f7->SetPoint(3,11639.6,4724.49);
    cutg_b3f7->SetPoint(4,11868.4,4669.77);
    cutg_b3f7->SetPoint(5,12106.2,4608.97);
    cutg_b3f7->SetPoint(6,12298.3,4608.97);
    cutg_b3f7->SetPoint(7,12463,4627.21);
    cutg_b3f7->SetPoint(8,12554.5,4718.41);
    cutg_b3f7->SetPoint(9,12554.5,4840.01);
    cutg_b3f7->SetPoint(10,12444.7,5016.32);
    cutg_b3f7->SetPoint(11,12289.2,5137.92);
    cutg_b3f7->SetPoint(12,12161.1,5192.64);
    cutg_b3f7->SetPoint(13,11914.1,5265.6);
    cutg_b3f7->SetPoint(14,11758.6,5320.32);
    cutg_b3f7->SetPoint(15,11529.9,5332.48);
    cutg_b3f7->SetPoint(16,11374.3,5393.28);
    cutg_b3f7->SetPoint(17,11237.1,5381.12);
    cutg_b3f7->SetPoint(18,11127.3,5368.96);
    cutg_b3f7->SetPoint(19,11072.4,5308.16);
    cutg_b3f7->SetPoint(20,11017.5,5210.88);
    cutg_b3f7->SetPoint(21,10980.9,5119.68);
    cutg_b3f7->SetPoint(22,11026.7,5028.48);
    cutg_b3f7->SetPoint(23,11045,4985.93);
    cutg_b3f7->SetPoint(24,11072.4,4961.61);
    cutg_b3f7->SetPoint(25,11054.1,4967.69);
    cutg_b3f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b3f7
    c4->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b3f7 = banana_b3f7->ProjectionX("projx_cutg_b3f7",1,banana_b3f7->GetNbinsX(),"[cutg_b3f7]");              
    projx_cutg_b3f7->Rebin(2);
    projx_cutg_b3f7->Draw("");
    projx_cutg_b3f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b3f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c4->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b3f7 = banana_b3f7->ProjectionY("projy_cutg_b3f7",1,banana_b3f7->GetNbinsY(),"[cutg_b3f7]");              
    projy_cutg_b3f7->Rebin(2);
    projy_cutg_b3f7->Draw("");
    projy_cutg_b3f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b3f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b3f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    ///////////////////
    // E DETECTOR b4 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c5 = new TCanvas("c5","c5:b4 bananas",1400,800);
    c5->Divide(8,3,0,0);
    c5->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b4f0 60Ni(a,a) elastic peak
    banana_b4f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f0->Draw();

    TCutG *cutg_b4f0 = new TCutG("cutg_b4f0",22);
    cutg_b4f0->SetVarX(" E detector 4 strip 0");
    cutg_b4f0->SetVarY("#DeltaE ");
    cutg_b4f0->SetTitle("Graph");
    cutg_b4f0->SetFillStyle(1000);
    cutg_b4f0->SetPoint(0,10981.3,4843.17);
    cutg_b4f0->SetPoint(1,11158.6,4710.86);
    cutg_b4f0->SetPoint(2,11430.4,4607.96);
    cutg_b4f0->SetPoint(3,11643.1,4527.11);
    cutg_b4f0->SetPoint(4,11879.4,4468.3);
    cutg_b4f0->SetPoint(5,12068.5,4468.3);
    cutg_b4f0->SetPoint(6,12281.2,4505.05);
    cutg_b4f0->SetPoint(7,12375.7,4593.26);
    cutg_b4f0->SetPoint(8,12375.7,4725.56);
    cutg_b4f0->SetPoint(9,12363.9,4821.12);
    cutg_b4f0->SetPoint(10,12222.1,4946.07);
    cutg_b4f0->SetPoint(11,11926.7,5078.38);
    cutg_b4f0->SetPoint(12,11690.4,5122.48);
    cutg_b4f0->SetPoint(13,11465.8,5218.03);
    cutg_b4f0->SetPoint(14,11264.9,5240.08);
    cutg_b4f0->SetPoint(15,11099.5,5269.48);
    cutg_b4f0->SetPoint(16,10957.7,5240.08);
    cutg_b4f0->SetPoint(17,10863.2,5129.83);
    cutg_b4f0->SetPoint(18,10851.3,5019.57);
    cutg_b4f0->SetPoint(19,10910.4,4850.52);
    cutg_b4f0->SetPoint(20,10993.2,4835.82);
    cutg_b4f0->SetPoint(21,10981.3,4843.17);
    cutg_b4f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f0
    c5->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f0 = banana_b4f0->ProjectionX("projx_cutg_b4f0",1,banana_b4f0->GetNbinsX(),"[cutg_b4f0]");              
    projx_cutg_b4f0->Rebin(2);
    projx_cutg_b4f0->Draw("");
    projx_cutg_b4f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f0 = banana_b4f0->ProjectionY("projy_cutg_b4f0",1,banana_b4f0->GetNbinsY(),"[cutg_b4f0]");              
    projy_cutg_b4f0->Rebin(2);
    projy_cutg_b4f0->Draw("");
    projy_cutg_b4f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c5->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f1 60Ni(a,a) elastic peak
    banana_b4f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f1->Draw();
   
    TCutG *cutg_b4f1 = new TCutG("cutg_b4f1",23);
    cutg_b4f1->SetVarX(" E detector 4 strip 1");
    cutg_b4f1->SetVarY("#DeltaE ");
    cutg_b4f1->SetTitle("Graph");
    cutg_b4f1->SetFillStyle(1000);
    cutg_b4f1->SetPoint(0,10929.5,4924.36);
    cutg_b4f1->SetPoint(1,11126.1,4845.51);
    cutg_b4f1->SetPoint(2,11288,4780.99);
    cutg_b4f1->SetPoint(3,11530.8,4680.63);
    cutg_b4f1->SetPoint(4,11843,4601.77);
    cutg_b4f1->SetPoint(5,12109,4573.09);
    cutg_b4f1->SetPoint(6,12444.3,4558.76);
    cutg_b4f1->SetPoint(7,12571.5,4616.11);
    cutg_b4f1->SetPoint(8,12571.5,4730.81);
    cutg_b4f1->SetPoint(9,12421.2,4953.04);
    cutg_b4f1->SetPoint(10,12294,5067.74);
    cutg_b4f1->SetPoint(11,12155.2,5139.43);
    cutg_b4f1->SetPoint(12,11970.2,5203.95);
    cutg_b4f1->SetPoint(13,11738.9,5268.47);
    cutg_b4f1->SetPoint(14,11484.6,5304.31);
    cutg_b4f1->SetPoint(15,11253.3,5311.48);
    cutg_b4f1->SetPoint(16,11045.2,5332.99);
    cutg_b4f1->SetPoint(17,10918,5282.8);
    cutg_b4f1->SetPoint(18,10837,5189.61);
    cutg_b4f1->SetPoint(19,10837,5096.42);
    cutg_b4f1->SetPoint(20,10860.2,4988.88);
    cutg_b4f1->SetPoint(21,10929.5,4931.53);
    cutg_b4f1->SetPoint(22,10929.5,4924.36);
    cutg_b4f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f1
    c5->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f1 = banana_b4f1->ProjectionX("projx_cutg_b4f1",1,banana_b4f1->GetNbinsX(),"[cutg_b4f1]");              
    projx_cutg_b4f1->Rebin(2);
    projx_cutg_b4f1->Draw("");
    projx_cutg_b4f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f1 = banana_b4f1->ProjectionY("projy_cutg_b4f1",1,banana_b4f1->GetNbinsY(),"[cutg_b4f1]");              
    projy_cutg_b4f1->Rebin(2);
    projy_cutg_b4f1->Draw("");
    projy_cutg_b4f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c5->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f2 60Ni(a,a) elastic peak
    banana_b4f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f2->Draw();

    TCutG *cutg_b4f2 = new TCutG("cutg_b4f2",23);
    cutg_b4f2->SetVarX(" E detector 4 strip 2");
    cutg_b4f2->SetVarY("#DeltaE ");
    cutg_b4f2->SetTitle("Graph");
    cutg_b4f2->SetFillStyle(1000);
    cutg_b4f2->SetPoint(0,11361.7,4682.74);
    cutg_b4f2->SetPoint(1,11523.4,4603.97);
    cutg_b4f2->SetPoint(2,11829.9,4525.21);
    cutg_b4f2->SetPoint(3,12051.3,4519.58);
    cutg_b4f2->SetPoint(4,12332.2,4530.83);
    cutg_b4f2->SetPoint(5,12511,4592.72);
    cutg_b4f2->SetPoint(6,12545,4682.74);
    cutg_b4f2->SetPoint(7,12536.5,4784.01);
    cutg_b4f2->SetPoint(8,12383.3,4947.17);
    cutg_b4f2->SetPoint(9,12204.5,4986.55);
    cutg_b4f2->SetPoint(10,12008.7,5042.81);
    cutg_b4f2->SetPoint(11,11838.4,5065.32);
    cutg_b4f2->SetPoint(12,11574.5,5127.21);
    cutg_b4f2->SetPoint(13,11378.7,5127.21);
    cutg_b4f2->SetPoint(14,11293.6,5110.33);
    cutg_b4f2->SetPoint(15,11208.4,5042.81);
    cutg_b4f2->SetPoint(16,11131.8,4947.17);
    cutg_b4f2->SetPoint(17,11123.3,4868.4);
    cutg_b4f2->SetPoint(18,11148.9,4795.26);
    cutg_b4f2->SetPoint(19,11225.5,4744.63);
    cutg_b4f2->SetPoint(20,11319.1,4699.62);
    cutg_b4f2->SetPoint(21,11370.2,4682.74);
    cutg_b4f2->SetPoint(22,11361.7,4682.74);
    cutg_b4f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f2
    c5->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f2 = banana_b4f2->ProjectionX("projx_cutg_b4f2",1,banana_b4f2->GetNbinsX(),"[cutg_b4f2]");              
    projx_cutg_b4f2->Rebin(2);
    projx_cutg_b4f2->Draw("");
    projx_cutg_b4f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f2 = banana_b4f2->ProjectionY("projy_cutg_b4f2",1,banana_b4f2->GetNbinsY(),"[cutg_b4f2]");              
    projy_cutg_b4f2->Rebin(2);
    projy_cutg_b4f2->Draw("");
    projy_cutg_b4f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c5->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f3 60Ni(a,a) elastic peak
    banana_b4f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f3->Draw();

    TCutG *cutg_b4f3 = new TCutG("cutg_b4f3",19);
    cutg_b4f3->SetVarX(" E detector 4 strip 3");
    cutg_b4f3->SetVarY("#DeltaE ");
    cutg_b4f3->SetTitle("Graph");
    cutg_b4f3->SetFillStyle(1000);
    cutg_b4f3->SetPoint(0,11099.7,4771.36);
    cutg_b4f3->SetPoint(1,11193,4666.46);
    cutg_b4f3->SetPoint(2,11459.9,4573.9);
    cutg_b4f3->SetPoint(3,11700,4530.71);
    cutg_b4f3->SetPoint(4,12247.1,4444.32);
    cutg_b4f3->SetPoint(5,12487.2,4506.03);
    cutg_b4f3->SetPoint(6,12620.6,4623.27);
    cutg_b4f3->SetPoint(7,12540.6,4796.04);
    cutg_b4f3->SetPoint(8,12313.8,4913.28);
    cutg_b4f3->SetPoint(9,12046.9,5061.38);
    cutg_b4f3->SetPoint(10,11660,5098.4);
    cutg_b4f3->SetPoint(11,11366.5,5098.4);
    cutg_b4f3->SetPoint(12,11179.7,5073.72);
    cutg_b4f3->SetPoint(13,11073,5024.36);
    cutg_b4f3->SetPoint(14,11032.9,4937.97);
    cutg_b4f3->SetPoint(15,11006.3,4870.09);
    cutg_b4f3->SetPoint(16,11019.6,4796.04);
    cutg_b4f3->SetPoint(17,11099.7,4752.85);
    cutg_b4f3->SetPoint(18,11099.7,4771.36);
    cutg_b4f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f3
    c5->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f3 = banana_b4f3->ProjectionX("projx_cutg_b4f3",1,banana_b4f3->GetNbinsX(),"[cutg_b4f3]");              
    projx_cutg_b4f3->Rebin(2);
    projx_cutg_b4f3->Draw("");
    projx_cutg_b4f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f3 = banana_b4f3->ProjectionY("projy_cutg_b4f3",1,banana_b4f3->GetNbinsY(),"[cutg_b4f3]");              
    projy_cutg_b4f3->Rebin(2);
    projy_cutg_b4f3->Draw("");
    projy_cutg_b4f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c5->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f4 60Ni(a,a) elastic peak
    banana_b4f4->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f4->Draw();

    TCutG *cutg_b4f4 = new TCutG("cutg_b4f4",19);
    cutg_b4f4->SetVarX(" E detector 4 strip 4");
    cutg_b4f4->SetVarY("#DeltaE ");
    cutg_b4f4->SetTitle("Graph");
    cutg_b4f4->SetFillStyle(1000);
    cutg_b4f4->SetPoint(0,11359.7,4644.17);
    cutg_b4f4->SetPoint(1,11663.9,4467.21);
    cutg_b4f4->SetPoint(2,11953.6,4420.03);
    cutg_b4f4->SetPoint(3,12286.7,4425.93);
    cutg_b4f4->SetPoint(4,12634.4,4514.4);
    cutg_b4f4->SetPoint(5,12706.8,4697.25);
    cutg_b4f4->SetPoint(6,12547.5,4838.81);
    cutg_b4f4->SetPoint(7,12243.3,5021.66);
    cutg_b4f4->SetPoint(8,11852.2,5080.64);
    cutg_b4f4->SetPoint(9,11591.4,5092.44);
    cutg_b4f4->SetPoint(10,11243.8,5080.64);
    cutg_b4f4->SetPoint(11,11113.4,5045.25);
    cutg_b4f4->SetPoint(12,11070,4950.88);
    cutg_b4f4->SetPoint(13,11070,4891.9);
    cutg_b4f4->SetPoint(14,11098.9,4797.52);
    cutg_b4f4->SetPoint(15,11171.4,4738.54);
    cutg_b4f4->SetPoint(16,11258.3,4691.35);
    cutg_b4f4->SetPoint(17,11345.2,4632.37);
    cutg_b4f4->SetPoint(18,11359.7,4644.17);
    cutg_b4f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f4
    c5->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f4 = banana_b4f4->ProjectionX("projx_cutg_b4f4",1,banana_b4f4->GetNbinsX(),"[cutg_b4f4]");              
    projx_cutg_b4f4->Rebin(2);
    projx_cutg_b4f4->Draw("");
    projx_cutg_b4f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f4 = banana_b4f4->ProjectionY("projy_cutg_b4f4",1,banana_b4f4->GetNbinsY(),"[cutg_b4f4]");              
    projy_cutg_b4f4->Rebin(2);
    projy_cutg_b4f4->Draw("");
    projy_cutg_b4f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c5->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f5 60Ni(a,a) elastic peak
    banana_b4f5->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f5->Draw();

    TCutG *cutg_b4f5 = new TCutG("cutg_b4f5",22);
    cutg_b4f5->SetVarX(" E detector 4 strip 5");
    cutg_b4f5->SetVarY("#DeltaE ");
    cutg_b4f5->SetTitle("Graph");
    cutg_b4f5->SetFillStyle(1000);
    cutg_b4f5->SetPoint(0,11129.2,4863.07);
    cutg_b4f5->SetPoint(1,11392.5,4752.18);
    cutg_b4f5->SetPoint(2,11655.7,4701);
    cutg_b4f5->SetPoint(3,11890.8,4666.88);
    cutg_b4f5->SetPoint(4,12172.9,4624.23);
    cutg_b4f5->SetPoint(5,12408,4615.7);
    cutg_b4f5->SetPoint(6,12511.4,4658.35);
    cutg_b4f5->SetPoint(7,12530.2,4828.95);
    cutg_b4f5->SetPoint(8,12464.4,4939.84);
    cutg_b4f5->SetPoint(9,12351.5,5016.61);
    cutg_b4f5->SetPoint(10,12182.3,5101.91);
    cutg_b4f5->SetPoint(11,12069.5,5161.62);
    cutg_b4f5->SetPoint(12,11843.8,5212.79);
    cutg_b4f5->SetPoint(13,11627.5,5281.03);
    cutg_b4f5->SetPoint(14,11345.4,5315.15);
    cutg_b4f5->SetPoint(15,11204.4,5315.15);
    cutg_b4f5->SetPoint(16,11110.4,5255.44);
    cutg_b4f5->SetPoint(17,11072.8,5161.62);
    cutg_b4f5->SetPoint(18,11054,4991.02);
    cutg_b4f5->SetPoint(19,11063.4,4897.19);
    cutg_b4f5->SetPoint(20,11110.4,4871.6);
    cutg_b4f5->SetPoint(21,11129.2,4863.07);
    cutg_b4f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f5
    c5->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f5 = banana_b4f5->ProjectionX("projx_cutg_b4f5",1,banana_b4f5->GetNbinsX(),"[cutg_b4f5]");              
    projx_cutg_b4f5->Rebin(2);
    projx_cutg_b4f5->Draw("");
    projx_cutg_b4f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f5 = banana_b4f5->ProjectionY("projy_cutg_b4f5",1,banana_b4f5->GetNbinsY(),"[cutg_b4f5]");              
    projy_cutg_b4f5->Rebin(2);
    projy_cutg_b4f5->Draw("");
    projy_cutg_b4f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c5->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f6 60Ni(a,a) elastic peak
    banana_b4f6->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f6->Draw();

    TCutG *cutg_b4f6 = new TCutG("cutg_b4f6",23);
    cutg_b4f6->SetVarX(" E detector 4 strip 6");
    cutg_b4f6->SetVarY("#DeltaE ");
    cutg_b4f6->SetTitle("Graph");
    cutg_b4f6->SetFillStyle(1000);
    cutg_b4f6->SetPoint(0,11155.4,4843.94);
    cutg_b4f6->SetPoint(1,11396.5,4755.74);
    cutg_b4f6->SetPoint(2,11813.9,4638.13);
    cutg_b4f6->SetPoint(3,12110.8,4594.03);
    cutg_b4f6->SetPoint(4,12342.7,4598.93);
    cutg_b4f6->SetPoint(5,12658,4628.33);
    cutg_b4f6->SetPoint(6,12862.1,4696.93);
    cutg_b4f6->SetPoint(7,12862.1,4799.84);
    cutg_b4f6->SetPoint(8,12825,4927.24);
    cutg_b4f6->SetPoint(9,12593.1,5064.45);
    cutg_b4f6->SetPoint(10,12324.1,5142.85);
    cutg_b4f6->SetPoint(11,12064.4,5216.35);
    cutg_b4f6->SetPoint(12,11795.4,5299.66);
    cutg_b4f6->SetPoint(13,11582,5329.06);
    cutg_b4f6->SetPoint(14,11405.8,5329.06);
    cutg_b4f6->SetPoint(15,11331.6,5324.16);
    cutg_b4f6->SetPoint(16,11173.9,5255.55);
    cutg_b4f6->SetPoint(17,11146.1,5177.15);
    cutg_b4f6->SetPoint(18,11136.8,5113.45);
    cutg_b4f6->SetPoint(19,11081.2,4976.24);
    cutg_b4f6->SetPoint(20,11090.4,4932.14);
    cutg_b4f6->SetPoint(21,11118.3,4878.24);
    cutg_b4f6->SetPoint(22,11164.6,4839.04);
    cutg_b4f6->SetPoint(23,11155.4,4843.94);
    cutg_b4f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b4f6
    c5->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f6 = banana_b4f6->ProjectionX("projx_cutg_b4f6",1,banana_b4f6->GetNbinsX(),"[cutg_b4f6]");              
    projx_cutg_b4f6->Rebin(2);
    projx_cutg_b4f6->Draw("");
    projx_cutg_b4f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f6 = banana_b4f6->ProjectionY("projy_cutg_b4f6",1,banana_b4f6->GetNbinsY(),"[cutg_b4f6]");              
    projy_cutg_b4f6->Rebin(2);
    projy_cutg_b4f6->Draw("");
    projy_cutg_b4f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c5->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b4f7 60Ni(a,a) elastic peak
    banana_b4f7->GetXaxis()->SetRangeUser(8000,13000);
    banana_b4f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b4f7->Draw();

    TCutG *cutg_b4f7 = new TCutG("cutg_b4f7",20);
    cutg_b4f7->SetVarX(" E detector 4 strip 7");
    cutg_b4f7->SetVarY("#DeltaE ");
    cutg_b4f7->SetTitle("Graph");
    cutg_b4f7->SetFillStyle(1000);
    cutg_b4f7->SetPoint(0,11379.4,4891.59);
    cutg_b4f7->SetPoint(1,11660.2,4785.6);
    cutg_b4f7->SetPoint(2,12146.2,4699.48);
    cutg_b4f7->SetPoint(3,12772.7,4725.98);
    cutg_b4f7->SetPoint(4,12794.3,4891.59);
    cutg_b4f7->SetPoint(5,12621.5,5090.32);
    cutg_b4f7->SetPoint(6,12448.7,5169.81);
    cutg_b4f7->SetPoint(7,12275.8,5255.93);
    cutg_b4f7->SetPoint(8,12059.8,5348.67);
    cutg_b4f7->SetPoint(9,11854.6,5395.04);
    cutg_b4f7->SetPoint(10,11649.4,5461.28);
    cutg_b4f7->SetPoint(11,11487.4,5481.15);
    cutg_b4f7->SetPoint(12,11239,5461.28);
    cutg_b4f7->SetPoint(13,11087.8,5361.91);
    cutg_b4f7->SetPoint(14,11077,5262.55);
    cutg_b4f7->SetPoint(15,11087.8,5176.43);
    cutg_b4f7->SetPoint(16,11163.4,5050.57);
    cutg_b4f7->SetPoint(17,11260.6,4957.83);
    cutg_b4f7->SetPoint(18,11411.8,4884.96);
    cutg_b4f7->SetPoint(19,11379.4,4891.59);
    cutg_b4f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b4f7
    c5->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b4f7 = banana_b4f7->ProjectionX("projx_cutg_b4f7",1,banana_b4f7->GetNbinsX(),"[cutg_b4f7]");              
    projx_cutg_b4f7->Rebin(2);
    projx_cutg_b4f7->Draw("");
    projx_cutg_b4f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b4f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c5->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b4f7 = banana_b4f7->ProjectionY("projy_cutg_b4f7",1,banana_b4f7->GetNbinsY(),"[cutg_b4f7]");              
    projy_cutg_b4f7->Rebin(2);
    projy_cutg_b4f7->Draw("");
    projy_cutg_b4f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b4f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b4f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;    

    ///////////////////
    // E DETECTOR b5 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c6 = new TCanvas("c6","c6:b5 bananas",1400,800);
    c6->Divide(8,3,0,0);
    c6->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

     // The b5f0 60Ni(a,a) elastic peak
    banana_b5f0->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f0->Draw();

    TCutG *cutg_b5f0 = new TCutG("cutg_b5f0",22);
    cutg_b5f0->SetVarX(" E detector 5 strip 0");
    cutg_b5f0->SetVarY("#DeltaE ");
    cutg_b5f0->SetTitle("Graph");
    cutg_b5f0->SetFillStyle(1000);
    cutg_b5f0->SetPoint(0,11004.4,4860.61);
    cutg_b5f0->SetPoint(1,11342.4,4731.39);
    cutg_b5f0->SetPoint(2,11620,4699.08);
    cutg_b5f0->SetPoint(3,11801.1,4666.78);
    cutg_b5f0->SetPoint(4,11958,4666.78);
    cutg_b5f0->SetPoint(5,12175.3,4731.39);
    cutg_b5f0->SetPoint(6,12211.5,4860.61);
    cutg_b5f0->SetPoint(7,12139.1,5054.44);
    cutg_b5f0->SetPoint(8,12042.5,5224.04);
    cutg_b5f0->SetPoint(9,11861.4,5288.65);
    cutg_b5f0->SetPoint(10,11559.7,5409.79);
    cutg_b5f0->SetPoint(11,11282,5434.02);
    cutg_b5f0->SetPoint(12,11052.7,5425.94);
    cutg_b5f0->SetPoint(13,10871.6,5442.1);
    cutg_b5f0->SetPoint(14,10726.7,5345.18);
    cutg_b5f0->SetPoint(15,10630.2,5240.19);
    cutg_b5f0->SetPoint(16,10666.4,5135.2);
    cutg_b5f0->SetPoint(17,10775,4997.9);
    cutg_b5f0->SetPoint(18,10883.7,4925.22);
    cutg_b5f0->SetPoint(19,10956.1,4884.84);
    cutg_b5f0->SetPoint(20,10980.2,4868.68);
    cutg_b5f0->SetPoint(21,11004.4,4860.61);
    cutg_b5f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f0
    c6->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f0 = banana_b5f0->ProjectionX("projx_cutg_b5f0",1,banana_b5f0->GetNbinsX(),"[cutg_b5f0]");              
    projx_cutg_b5f0->Rebin(2);
    projx_cutg_b5f0->Draw("");
    projx_cutg_b5f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f0 = banana_b5f0->ProjectionY("projy_cutg_b5f0",1,banana_b5f0->GetNbinsY(),"[cutg_b5f0]");              
    projy_cutg_b5f0->Rebin(2);
    projy_cutg_b5f0->Draw("");
    projy_cutg_b5f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f1 60Ni(a,a) elastic peak
    banana_b5f1->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f1->Draw();
   
    TCutG *cutg_b5f1 = new TCutG("cutg_b5f1",22);
    cutg_b5f1->SetVarX(" E detector 5 strip 1");
    cutg_b5f1->SetVarY("#DeltaE ");
    cutg_b5f1->SetTitle("Graph");
    cutg_b5f1->SetFillStyle(1000);
    cutg_b5f1->SetPoint(0,10797.1,4880.74);
    cutg_b5f1->SetPoint(1,10957.3,4786.73);
    cutg_b5f1->SetPoint(2,11105.2,4739.73);
    cutg_b5f1->SetPoint(3,11438,4618.86);
    cutg_b5f1->SetPoint(4,11659.9,4585.28);
    cutg_b5f1->SetPoint(5,11906.4,4618.86);
    cutg_b5f1->SetPoint(6,12239.1,4692.72);
    cutg_b5f1->SetPoint(7,12251.5,4874.03);
    cutg_b5f1->SetPoint(8,12140.5,4947.89);
    cutg_b5f1->SetPoint(9,12029.6,5075.48);
    cutg_b5f1->SetPoint(10,11857.1,5162.78);
    cutg_b5f1->SetPoint(11,11548.9,5243.36);
    cutg_b5f1->SetPoint(12,11228.5,5270.22);
    cutg_b5f1->SetPoint(13,10982,5283.65);
    cutg_b5f1->SetPoint(14,10710.8,5283.65);
    cutg_b5f1->SetPoint(15,10636.9,5229.93);
    cutg_b5f1->SetPoint(16,10624.5,5102.34);
    cutg_b5f1->SetPoint(17,10636.9,5001.62);
    cutg_b5f1->SetPoint(18,10710.8,4907.6);
    cutg_b5f1->SetPoint(19,10784.8,4880.74);
    cutg_b5f1->SetPoint(20,10784.8,4880.74);
    cutg_b5f1->SetPoint(21,10797.1,4880.74);
    cutg_b5f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f1
    c6->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f1 = banana_b5f1->ProjectionX("projx_cutg_b5f1",1,banana_b5f1->GetNbinsX(),"[cutg_b5f1]");              
    projx_cutg_b5f1->Rebin(2);
    projx_cutg_b5f1->Draw("");
    projx_cutg_b5f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f1 = banana_b5f1->ProjectionY("projy_cutg_b5f1",1,banana_b5f1->GetNbinsY(),"[cutg_b5f1]");              
    projy_cutg_b5f1->Rebin(2);
    projy_cutg_b5f1->Draw("");
    projy_cutg_b5f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f2 60Ni(a,a) elastic peak
    banana_b5f2->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f2->Draw();

    TCutG *cutg_b5f2 = new TCutG("cutg_b5f2",22);
    cutg_b5f2->SetVarX(" E detector 5 strip 2");
    cutg_b5f2->SetVarY("#DeltaE ");
    cutg_b5f2->SetTitle("Graph");
    cutg_b5f2->SetFillStyle(1000);
    cutg_b5f2->SetPoint(0,11155.1,4943.27);
    cutg_b5f2->SetPoint(1,11319.1,4838.37);
    cutg_b5f2->SetPoint(2,11603.2,4770.49);
    cutg_b5f2->SetPoint(3,11821.7,4721.13);
    cutg_b5f2->SetPoint(4,12073.1,4671.76);
    cutg_b5f2->SetPoint(5,12280.7,4653.25);
    cutg_b5f2->SetPoint(6,12411.8,4677.93);
    cutg_b5f2->SetPoint(7,12455.5,4789);
    cutg_b5f2->SetPoint(8,12400.9,4881.56);
    cutg_b5f2->SetPoint(9,12346.3,4992.63);
    cutg_b5f2->SetPoint(10,12193.3,5054.34);
    cutg_b5f2->SetPoint(11,11941.9,5159.24);
    cutg_b5f2->SetPoint(12,11668.7,5251.8);
    cutg_b5f2->SetPoint(13,11330,5294.99);
    cutg_b5f2->SetPoint(14,11122.4,5313.5);
    cutg_b5f2->SetPoint(15,11034.9,5276.48);
    cutg_b5f2->SetPoint(16,10980.3,5190.09);
    cutg_b5f2->SetPoint(17,10958.4,5097.53);
    cutg_b5f2->SetPoint(18,11024,4986.46);
    cutg_b5f2->SetPoint(19,11089.6,4949.44);
    cutg_b5f2->SetPoint(20,11177,4930.93);
    cutg_b5f2->SetPoint(21,11155.1,4943.27);
    cutg_b5f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f2
    c6->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f2 = banana_b5f2->ProjectionX("projx_cutg_b5f2",1,banana_b5f2->GetNbinsX(),"[cutg_b5f2]");              
    projx_cutg_b5f2->Rebin(2);
    projx_cutg_b5f2->Draw("");
    projx_cutg_b5f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f2 = banana_b5f2->ProjectionY("projy_cutg_b5f2",1,banana_b5f2->GetNbinsY(),"[cutg_b5f2]");              
    projy_cutg_b5f2->Rebin(2);
    projy_cutg_b5f2->Draw("");
    projy_cutg_b5f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f3 60Ni(a,a) elastic peak
    banana_b5f3->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f3->Draw();

    TCutG *cutg_b5f3 = new TCutG("cutg_b5f3",18);
    cutg_b5f3->SetVarX(" E detector 5 strip 3");
    cutg_b5f3->SetVarY("#DeltaE ");
    cutg_b5f3->SetTitle("Graph");
    cutg_b5f3->SetFillStyle(1000);
    cutg_b5f3->SetPoint(0,11292.3,4784.63);
    cutg_b5f3->SetPoint(1,11522.1,4714.75);
    cutg_b5f3->SetPoint(2,11866.7,4625.83);
    cutg_b5f3->SetPoint(3,12225.6,4536.9);
    cutg_b5f3->SetPoint(4,12498.4,4536.9);
    cutg_b5f3->SetPoint(5,12656.4,4587.71);
    cutg_b5f3->SetPoint(6,12685.1,4689.35);
    cutg_b5f3->SetPoint(7,12555.9,4841.8);
    cutg_b5f3->SetPoint(8,12326.1,4975.19);
    cutg_b5f3->SetPoint(9,11967.2,5083.18);
    cutg_b5f3->SetPoint(10,11737.4,5153.05);
    cutg_b5f3->SetPoint(11,11335.4,5159.4);
    cutg_b5f3->SetPoint(12,11191.8,5127.64);
    cutg_b5f3->SetPoint(13,11120,4987.89);
    cutg_b5f3->SetPoint(14,11105.7,4854.5);
    cutg_b5f3->SetPoint(15,11191.8,4816.39);
    cutg_b5f3->SetPoint(16,11278,4784.63);
    cutg_b5f3->SetPoint(17,11292.3,4784.63);
    cutg_b5f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f3
    c6->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f3 = banana_b5f3->ProjectionX("projx_cutg_b5f3",1,banana_b5f3->GetNbinsX(),"[cutg_b5f3]");              
    projx_cutg_b5f3->Rebin(2);
    projx_cutg_b5f3->Draw("");
    projx_cutg_b5f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f3 = banana_b5f3->ProjectionY("projy_cutg_b5f3",1,banana_b5f3->GetNbinsY(),"[cutg_b5f3]");              
    projy_cutg_b5f3->Rebin(2);
    projy_cutg_b5f3->Draw("");
    projy_cutg_b5f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f4 60Ni(a,a) elastic peak
    banana_b5f4->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f4->Draw();

    TCutG *cutg_b5f4 = new TCutG("cutg_b5f4",18);
    cutg_b5f4->SetVarX(" E detector 5 strip 4");
    cutg_b5f4->SetVarY("#DeltaE ");
    cutg_b5f4->SetTitle("Graph");
    cutg_b5f4->SetFillStyle(1000);
    cutg_b5f4->SetPoint(0,11405.7,5093.99);
    cutg_b5f4->SetPoint(1,11722.6,4960.05);
    cutg_b5f4->SetPoint(2,12028.5,4818.68);
    cutg_b5f4->SetPoint(3,12312.7,4781.47);
    cutg_b5f4->SetPoint(4,12454.7,4826.12);
    cutg_b5f4->SetPoint(5,12520.3,4937.73);
    cutg_b5f4->SetPoint(6,12476.6,5079.11);
    cutg_b5f4->SetPoint(7,12345.4,5294.9);
    cutg_b5f4->SetPoint(8,11963,5495.81);
    cutg_b5f4->SetPoint(9,11733.5,5495.81);
    cutg_b5f4->SetPoint(10,11482.2,5473.48);
    cutg_b5f4->SetPoint(11,11329.2,5391.63);
    cutg_b5f4->SetPoint(12,11252.7,5302.34);
    cutg_b5f4->SetPoint(13,11252.7,5213.05);
    cutg_b5f4->SetPoint(14,11296.4,5131.2);
    cutg_b5f4->SetPoint(15,11372.9,5116.32);
    cutg_b5f4->SetPoint(16,11427.5,5093.99);
    cutg_b5f4->SetPoint(17,11405.7,5093.99);
    cutg_b5f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f4
    c6->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f4 = banana_b5f4->ProjectionX("projx_cutg_b5f4",1,banana_b5f4->GetNbinsX(),"[cutg_b5f4]");              
    projx_cutg_b5f4->Rebin(2);
    projx_cutg_b5f4->Draw("");
    projx_cutg_b5f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f4 = banana_b5f4->ProjectionY("projy_cutg_b5f4",1,banana_b5f4->GetNbinsY(),"[cutg_b5f4]");              
    projy_cutg_b5f4->Rebin(2);
    projy_cutg_b5f4->Draw("");
    projy_cutg_b5f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f5 60Ni(a,a) elastic peak
    banana_b5f5->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f5->Draw();

    TCutG *cutg_b5f5 = new TCutG("cutg_b5f5",20);
    cutg_b5f5->SetVarX(" E detector 5 strip 5");
    cutg_b5f5->SetVarY("#DeltaE ");
    cutg_b5f5->SetTitle("Graph");
    cutg_b5f5->SetFillStyle(1000);
    cutg_b5f5->SetPoint(0,11220.3,5004.1);
    cutg_b5f5->SetPoint(1,11435.6,4899.2);
    cutg_b5f5->SetPoint(2,11773.8,4825.15);
    cutg_b5f5->SetPoint(3,11989.1,4806.64);
    cutg_b5f5->SetPoint(4,12281.2,4775.79);
    cutg_b5f5->SetPoint(5,12557.9,4800.47);
    cutg_b5f5->SetPoint(6,12696.3,4880.69);
    cutg_b5f5->SetPoint(7,12696.3,4973.25);
    cutg_b5f5->SetPoint(8,12465.7,5115.17);
    cutg_b5f5->SetPoint(9,12035.2,5287.95);
    cutg_b5f5->SetPoint(10,11835.3,5343.48);
    cutg_b5f5->SetPoint(11,11527.8,5362);
    cutg_b5f5->SetPoint(12,11327.9,5337.31);
    cutg_b5f5->SetPoint(13,11204.9,5287.95);
    cutg_b5f5->SetPoint(14,11158.8,5226.24);
    cutg_b5f5->SetPoint(15,11158.8,5133.68);
    cutg_b5f5->SetPoint(16,11189.6,5071.98);
    cutg_b5f5->SetPoint(17,11235.7,5004.1);
    cutg_b5f5->SetPoint(18,11266.4,4985.59);
    cutg_b5f5->SetPoint(19,11220.3,5004.1);
    cutg_b5f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f5
    c6->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f5 = banana_b5f5->ProjectionX("projx_cutg_b5f5",1,banana_b5f5->GetNbinsX(),"[cutg_b5f5]");              
    projx_cutg_b5f5->Rebin(2);
    projx_cutg_b5f5->Draw("");
    projx_cutg_b5f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f5 = banana_b5f5->ProjectionY("projy_cutg_b5f5",1,banana_b5f5->GetNbinsY(),"[cutg_b5f5]");              
    projy_cutg_b5f5->Rebin(2);
    projy_cutg_b5f5->Draw("");
    projy_cutg_b5f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f6 60Ni(a,a) elastic peak
    banana_b5f6->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f6->Draw();

    TCutG *cutg_b5f6 = new TCutG("cutg_b5f6",22);
    cutg_b5f6->SetVarX(" E detector 5 strip 6");
    cutg_b5f6->SetVarY("#DeltaE ");
    cutg_b5f6->SetTitle("Graph");
    cutg_b5f6->SetFillStyle(1000);
    cutg_b5f6->SetPoint(0,11184.9,4985.37);
    cutg_b5f6->SetPoint(1,11333.3,4912.13);
    cutg_b5f6->SetPoint(2,11500.3,4851.1);
    cutg_b5f6->SetPoint(3,11945.6,4710.74);
    cutg_b5f6->SetPoint(4,12214.6,4710.74);
    cutg_b5f6->SetPoint(5,12548.6,4741.25);
    cutg_b5f6->SetPoint(6,12697.1,4808.38);
    cutg_b5f6->SetPoint(7,12706.3,4924.34);
    cutg_b5f6->SetPoint(8,12678.5,5064.71);
    cutg_b5f6->SetPoint(9,12530.1,5137.94);
    cutg_b5f6->SetPoint(10,12261,5247.79);
    cutg_b5f6->SetPoint(11,12149.7,5302.72);
    cutg_b5f6->SetPoint(12,11927.1,5412.57);
    cutg_b5f6->SetPoint(13,11695.1,5424.78);
    cutg_b5f6->SetPoint(14,11472.5,5406.47);
    cutg_b5f6->SetPoint(15,11379.7,5382.06);
    cutg_b5f6->SetPoint(16,11277.6,5327.13);
    cutg_b5f6->SetPoint(17,11231.3,5253.9);
    cutg_b5f6->SetPoint(18,11184.9,5131.84);
    cutg_b5f6->SetPoint(19,11175.6,5034.19);
    cutg_b5f6->SetPoint(20,11184.9,4985.37);
    cutg_b5f6->SetPoint(21,11184.9,4985.37);
    cutg_b5f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b5f6
    c6->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f6 = banana_b5f6->ProjectionX("projx_cutg_b5f6",1,banana_b5f6->GetNbinsX(),"[cutg_b5f6]");              
    projx_cutg_b5f6->Rebin(2);
    projx_cutg_b5f6->Draw("");
    projx_cutg_b5f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f6 = banana_b5f6->ProjectionY("projy_cutg_b5f6",1,banana_b5f6->GetNbinsY(),"[cutg_b5f6]");              
    projy_cutg_b5f6->Rebin(2);
    projy_cutg_b5f6->Draw("");
    projy_cutg_b5f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c6->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b5f7 60Ni(a,a) elastic peak
    banana_b5f7->GetXaxis()->SetRangeUser(8000,13000);
    banana_b5f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b5f7->Draw();

    TCutG *cutg_b5f7 = new TCutG("cutg_b5f7",25);
    cutg_b5f7->SetVarX(" E detector 5 strip 7");
    cutg_b5f7->SetVarY("#DeltaE ");
    cutg_b5f7->SetTitle("Graph");
    cutg_b5f7->SetFillStyle(1000);
    cutg_b5f7->SetPoint(0,11229.4,4644.41);
    cutg_b5f7->SetPoint(1,11450.6,4567.21);
    cutg_b5f7->SetPoint(2,11742.5,4505.44);
    cutg_b5f7->SetPoint(3,11972.4,4474.56);
    cutg_b5f7->SetPoint(4,12255.5,4443.68);
    cutg_b5f7->SetPoint(5,12512,4474.56);
    cutg_b5f7->SetPoint(6,12609.3,4536.32);
    cutg_b5f7->SetPoint(7,12627,4659.85);
    cutg_b5f7->SetPoint(8,12512,4803.97);
    cutg_b5f7->SetPoint(9,12405.9,4876.03);
    cutg_b5f7->SetPoint(10,12193.6,4973.82);
    cutg_b5f7->SetPoint(11,12025.5,5045.88);
    cutg_b5f7->SetPoint(12,11839.8,5087.06);
    cutg_b5f7->SetPoint(13,11583.2,5143.68);
    cutg_b5f7->SetPoint(14,11326.7,5143.68);
    cutg_b5f7->SetPoint(15,11211.7,5107.65);
    cutg_b5f7->SetPoint(16,11114.4,5030.44);
    cutg_b5f7->SetPoint(17,11061.3,4922.35);
    cutg_b5f7->SetPoint(18,11043.6,4845.15);
    cutg_b5f7->SetPoint(19,11034.8,4767.94);
    cutg_b5f7->SetPoint(20,11052.5,4711.32);
    cutg_b5f7->SetPoint(21,11105.6,4665);
    cutg_b5f7->SetPoint(22,11167.5,4654.71);
    cutg_b5f7->SetPoint(23,11238.3,4634.12);
    cutg_b5f7->SetPoint(24,11229.4,4644.41);
    cutg_b5f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b5f7
    c6->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b5f7 = banana_b5f7->ProjectionX("projx_cutg_b5f7",1,banana_b5f7->GetNbinsX(),"[cutg_b5f7]");              
    projx_cutg_b5f7->Rebin(2);
    projx_cutg_b5f7->Draw("");
    projx_cutg_b5f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b5f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c6->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b5f7 = banana_b5f7->ProjectionY("projy_cutg_b5f7",1,banana_b5f7->GetNbinsY(),"[cutg_b5f7]");              
    projy_cutg_b5f7->Rebin(2);
    projy_cutg_b5f7->Draw("");
    projy_cutg_b5f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b5f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b5f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;    


    ///////////////////
    // E DETECTOR b6 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c7 = new TCanvas("c7","c7:b6 bananas",1400,800);
    c7->Divide(8,3,0,0);
    c7->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f0 60Ni(a,a) elastic peak
    banana_b6f0->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f0->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f0->Draw();

    TCutG *cutg_b6f0 = new TCutG("cutg_b6f0",25);
    cutg_b6f0->SetVarX(" E detector 6 strip 0");
    cutg_b6f0->SetVarY("#DeltaE ");
    cutg_b6f0->SetTitle("Graph");
    cutg_b6f0->SetFillStyle(1000);
    cutg_b6f0->SetPoint(0,11272.7,4379.19);
    cutg_b6f0->SetPoint(1,11502.5,4300.37);
    cutg_b6f0->SetPoint(2,11739.9,4251.1);
    cutg_b6f0->SetPoint(3,12031,4216.62);
    cutg_b6f0->SetPoint(4,12253.1,4182.13);
    cutg_b6f0->SetPoint(5,12459.9,4191.99);
    cutg_b6f0->SetPoint(6,12544.2,4226.47);
    cutg_b6f0->SetPoint(7,12620.7,4329.93);
    cutg_b6f0->SetPoint(8,12613.1,4462.94);
    cutg_b6f0->SetPoint(9,12528.8,4551.62);
    cutg_b6f0->SetPoint(10,12452.2,4645.22);
    cutg_b6f0->SetPoint(11,12322,4704.34);
    cutg_b6f0->SetPoint(12,12061.6,4753.6);
    cutg_b6f0->SetPoint(13,11801.2,4788.09);
    cutg_b6f0->SetPoint(14,11571.4,4802.87);
    cutg_b6f0->SetPoint(15,11402.9,4797.94);
    cutg_b6f0->SetPoint(16,11226.8,4783.16);
    cutg_b6f0->SetPoint(17,11111.9,4738.82);
    cutg_b6f0->SetPoint(18,11096.6,4605.81);
    cutg_b6f0->SetPoint(19,11119.6,4517.13);
    cutg_b6f0->SetPoint(20,11173.2,4418.6);
    cutg_b6f0->SetPoint(21,11234.4,4389.04);
    cutg_b6f0->SetPoint(22,11280.4,4379.19);
    cutg_b6f0->SetPoint(23,11280.4,4379.19);
    cutg_b6f0->SetPoint(24,11272.7,4379.19);
    cutg_b6f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f0
    c7->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f0 = banana_b6f0->ProjectionX("projx_cutg_b6f0",1,banana_b6f0->GetNbinsX(),"[cutg_b6f0]");              
    projx_cutg_b6f0->Rebin(2);
    projx_cutg_b6f0->Draw("");
    projx_cutg_b6f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f0 = banana_b6f0->ProjectionY("projy_cutg_b6f0",1,banana_b6f0->GetNbinsY(),"[cutg_b6f0]");              
    projy_cutg_b6f0->Rebin(2);
    projy_cutg_b6f0->Draw("");
    projy_cutg_b6f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f1 60Ni(a,a) elastic peak
    banana_b6f1->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f1->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f1->Draw();
   
    TCutG *cutg_b6f1 = new TCutG("cutg_b6f1",20);
    cutg_b6f1->SetVarX(" E detector 6 strip 1");
    cutg_b6f1->SetVarY("#DeltaE ");
    cutg_b6f1->SetTitle("Graph");
    cutg_b6f1->SetFillStyle(1000);
    cutg_b6f1->SetPoint(0,11154.1,4792.94);
    cutg_b6f1->SetPoint(1,11315.9,4672.5);
    cutg_b6f1->SetPoint(2,11612.5,4557.79);
    cutg_b6f1->SetPoint(3,11882.2,4483.24);
    cutg_b6f1->SetPoint(4,12286.7,4460.29);
    cutg_b6f1->SetPoint(5,12556.4,4488.97);
    cutg_b6f1->SetPoint(6,12677.8,4580.74);
    cutg_b6f1->SetPoint(7,12623.9,4741.32);
    cutg_b6f1->SetPoint(8,12462,4856.03);
    cutg_b6f1->SetPoint(9,12246.3,4987.94);
    cutg_b6f1->SetPoint(10,11990.1,5056.76);
    cutg_b6f1->SetPoint(11,11787.8,5085.44);
    cutg_b6f1->SetPoint(12,11585.6,5091.18);
    cutg_b6f1->SetPoint(13,11396.8,5079.71);
    cutg_b6f1->SetPoint(14,11235,5039.56);
    cutg_b6f1->SetPoint(15,11113.6,4930.59);
    cutg_b6f1->SetPoint(16,11113.6,4861.76);
    cutg_b6f1->SetPoint(17,11127.1,4815.88);
    cutg_b6f1->SetPoint(18,11140.6,4787.21);
    cutg_b6f1->SetPoint(19,11154.1,4792.94);
    cutg_b6f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f1
    c7->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f1 = banana_b6f1->ProjectionX("projx_cutg_b6f1",1,banana_b6f1->GetNbinsX(),"[cutg_b6f1]");              
    projx_cutg_b6f1->Rebin(2);
    projx_cutg_b6f1->Draw("");
    projx_cutg_b6f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f1 = banana_b6f1->ProjectionY("projy_cutg_b6f1",1,banana_b6f1->GetNbinsY(),"[cutg_b6f1]");              
    projy_cutg_b6f1->Rebin(2);
    projy_cutg_b6f1->Draw("");
    projy_cutg_b6f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c7->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f2 60Ni(a,a) elastic peak
    banana_b6f2->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f2->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f2->Draw();

    TCutG *cutg_b6f2 = new TCutG("cutg_b6f2",21);
    cutg_b6f2->SetVarX(" E detector 6 strip 2");
    cutg_b6f2->SetVarY("#DeltaE ");
    cutg_b6f2->SetTitle("Graph");
    cutg_b6f2->SetFillStyle(1000);
    cutg_b6f2->SetPoint(0,11317.6,4770.59);
    cutg_b6f2->SetPoint(1,11560.3,4605.88);
    cutg_b6f2->SetPoint(2,11851.6,4529.41);
    cutg_b6f2->SetPoint(3,12223.8,4482.35);
    cutg_b6f2->SetPoint(4,12482.7,4464.71);
    cutg_b6f2->SetPoint(5,12709.2,4464.71);
    cutg_b6f2->SetPoint(6,12903.4,4511.76);
    cutg_b6f2->SetPoint(7,12951.9,4576.47);
    cutg_b6f2->SetPoint(8,12903.4,4694.12);
    cutg_b6f2->SetPoint(9,12773.9,4764.71);
    cutg_b6f2->SetPoint(10,12579.7,4841.18);
    cutg_b6f2->SetPoint(11,12434.1,4900);
    cutg_b6f2->SetPoint(12,12256.1,4970.59);
    cutg_b6f2->SetPoint(13,11932.5,5035.29);
    cutg_b6f2->SetPoint(14,11592.7,5047.06);
    cutg_b6f2->SetPoint(15,11350,5041.18);
    cutg_b6f2->SetPoint(16,11220.5,4976.47);
    cutg_b6f2->SetPoint(17,11301.4,4847.06);
    cutg_b6f2->SetPoint(18,11301.4,4794.12);
    cutg_b6f2->SetPoint(19,11317.6,4758.82);
    cutg_b6f2->SetPoint(20,11317.6,4770.59);
    cutg_b6f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f2
    c7->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f2 = banana_b6f2->ProjectionX("projx_cutg_b6f2",1,banana_b6f2->GetNbinsX(),"[cutg_b6f2]");              
    projx_cutg_b6f2->Rebin(2);
    projx_cutg_b6f2->Draw("");
    projx_cutg_b6f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f2 = banana_b6f2->ProjectionY("projy_cutg_b6f2",1,banana_b6f2->GetNbinsY(),"[cutg_b6f2]");              
    projy_cutg_b6f2->Rebin(2);
    projy_cutg_b6f2->Draw("");
    projy_cutg_b6f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f3 60Ni(a,a) elastic peak
    banana_b6f3->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f3->Draw();

    TCutG *cutg_b6f3 = new TCutG("cutg_b6f3",18);
    cutg_b6f3->SetVarX(" E detector 6 strip 3");
    cutg_b6f3->SetVarY("#DeltaE ");
    cutg_b6f3->SetTitle("Graph");
    cutg_b6f3->SetFillStyle(1000);
    cutg_b6f3->SetPoint(0,11575.1,4594.41);
    cutg_b6f3->SetPoint(1,11782.3,4396.76);
    cutg_b6f3->SetPoint(2,11989.4,4378.24);
    cutg_b6f3->SetPoint(3,12279.4,4322.65);
    cutg_b6f3->SetPoint(4,12496.8,4322.65);
    cutg_b6f3->SetPoint(5,12724.7,4341.18);
    cutg_b6f3->SetPoint(6,12786.8,4458.53);
    cutg_b6f3->SetPoint(7,12786.8,4594.41);
    cutg_b6f3->SetPoint(8,12631.5,4730.29);
    cutg_b6f3->SetPoint(9,12331.1,4903.24);
    cutg_b6f3->SetPoint(10,12041.2,4940.29);
    cutg_b6f3->SetPoint(11,11699.4,4971.18);
    cutg_b6f3->SetPoint(12,11575.1,4927.94);
    cutg_b6f3->SetPoint(13,11492.3,4816.76);
    cutg_b6f3->SetPoint(14,11502.7,4724.12);
    cutg_b6f3->SetPoint(15,11544.1,4643.82);
    cutg_b6f3->SetPoint(16,11564.8,4600.59);
    cutg_b6f3->SetPoint(17,11575.1,4594.41);
    cutg_b6f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f3
    c7->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f3 = banana_b6f3->ProjectionX("projx_cutg_b6f3",1,banana_b6f3->GetNbinsX(),"[cutg_b6f3]");              
    projx_cutg_b6f3->Rebin(2);
    projx_cutg_b6f3->Draw("");
    projx_cutg_b6f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f3 = banana_b6f3->ProjectionY("projy_cutg_b6f3",1,banana_b6f3->GetNbinsY(),"[cutg_b6f3]");              
    projy_cutg_b6f3->Rebin(2);
    projy_cutg_b6f3->Draw("");
    projy_cutg_b6f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f4 60Ni(a,a) elastic peak
    banana_b6f4->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f4->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f4->Draw();

    TCutG *cutg_b6f4 = new TCutG("cutg_b6f4",21);
    cutg_b6f4->SetVarX(" E detector 6 strip 4");
    cutg_b6f4->SetVarY("#DeltaE ");
    cutg_b6f4->SetTitle("Graph");
    cutg_b6f4->SetFillStyle(1000);
    cutg_b6f4->SetPoint(0,11530.3,4759.56);
    cutg_b6f4->SetPoint(1,11623.2,4661.76);
    cutg_b6f4->SetPoint(2,11782.4,4584.93);
    cutg_b6f4->SetPoint(3,11994.7,4522.06);
    cutg_b6f4->SetPoint(4,12313.2,4459.19);
    cutg_b6f4->SetPoint(5,12591.8,4452.21);
    cutg_b6f4->SetPoint(6,12910.3,4473.16);
    cutg_b6f4->SetPoint(7,12976.6,4529.04);
    cutg_b6f4->SetPoint(8,13042.9,4647.79);
    cutg_b6f4->SetPoint(9,12976.6,4773.53);
    cutg_b6f4->SetPoint(10,12751,4878.31);
    cutg_b6f4->SetPoint(11,12565.3,4990.07);
    cutg_b6f4->SetPoint(12,12339.7,5073.9);
    cutg_b6f4->SetPoint(13,12127.4,5094.85);
    cutg_b6f4->SetPoint(14,11888.6,5101.84);
    cutg_b6f4->SetPoint(15,11742.6,5073.9);
    cutg_b6f4->SetPoint(16,11663,5011.03);
    cutg_b6f4->SetPoint(17,11583.4,4899.26);
    cutg_b6f4->SetPoint(18,11503.8,4808.46);
    cutg_b6f4->SetPoint(19,11530.3,4752.57);
    cutg_b6f4->SetPoint(20,11530.3,4759.56);
    cutg_b6f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f4
    c7->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f4 = banana_b6f4->ProjectionX("projx_cutg_b6f4",1,banana_b6f4->GetNbinsX(),"[cutg_b6f4]");              
    projx_cutg_b6f4->Rebin(2);
    projx_cutg_b6f4->Draw("");
    projx_cutg_b6f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f4 = banana_b6f4->ProjectionY("projy_cutg_b6f4",1,banana_b6f4->GetNbinsY(),"[cutg_b6f4]");              
    projy_cutg_b6f4->Rebin(2);
    projy_cutg_b6f4->Draw("");
    projy_cutg_b6f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f5 60Ni(a,a) elastic peak
    banana_b6f5->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f5->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f5->Draw();

    TCutG *cutg_b6f5 = new TCutG("cutg_b6f5",23);
    cutg_b6f5->SetVarX(" E detector 6 strip 5");
    cutg_b6f5->SetVarY("#DeltaE ");
    cutg_b6f5->SetTitle("Graph");
    cutg_b6f5->SetFillStyle(1000);
    cutg_b6f5->SetPoint(0,11595.4,4770.96);
    cutg_b6f5->SetPoint(1,11775.7,4635.44);
    cutg_b6f5->SetPoint(2,12021.7,4542.72);
    cutg_b6f5->SetPoint(3,12275.9,4435.74);
    cutg_b6f5->SetPoint(4,12530,4392.94);
    cutg_b6f5->SetPoint(5,12767.8,4392.94);
    cutg_b6f5->SetPoint(6,12948.1,4457.13);
    cutg_b6f5->SetPoint(7,13013.7,4556.99);
    cutg_b6f5->SetPoint(8,12997.3,4699.63);
    cutg_b6f5->SetPoint(9,12915.3,4835.15);
    cutg_b6f5->SetPoint(10,12800.6,4927.87);
    cutg_b6f5->SetPoint(11,12620.2,5006.32);
    cutg_b6f5->SetPoint(12,12480.8,5099.04);
    cutg_b6f5->SetPoint(13,12234.9,5234.56);
    cutg_b6f5->SetPoint(14,11997.1,5255.96);
    cutg_b6f5->SetPoint(15,11751.2,5227.43);
    cutg_b6f5->SetPoint(16,11652.8,5170.37);
    cutg_b6f5->SetPoint(17,11554.4,5027.72);
    cutg_b6f5->SetPoint(18,11505.2,4949.26);
    cutg_b6f5->SetPoint(19,11538,4870.81);
    cutg_b6f5->SetPoint(20,11562.6,4806.62);
    cutg_b6f5->SetPoint(21,11603.6,4770.96);
    cutg_b6f5->SetPoint(22,11595.4,4770.96);
    cutg_b6f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f5
    c7->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f5 = banana_b6f5->ProjectionX("projx_cutg_b6f5",1,banana_b6f5->GetNbinsX(),"[cutg_b6f5]");              
    projx_cutg_b6f5->Rebin(2);
    projx_cutg_b6f5->Draw("");
    projx_cutg_b6f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f5 = banana_b6f5->ProjectionY("projy_cutg_b6f5",1,banana_b6f5->GetNbinsY(),"[cutg_b6f5]");              
    projy_cutg_b6f5->Rebin(2);
    projy_cutg_b6f5->Draw("");
    projy_cutg_b6f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f6 60Ni(a,a) elastic peak
    banana_b6f6->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f6->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f6->Draw();

    TCutG *cutg_b6f6 = new TCutG("cutg_b6f6",21);
    cutg_b6f6->SetVarX(" E detector 6 strip 6");
    cutg_b6f6->SetVarY("#DeltaE ");
    cutg_b6f6->SetTitle("Graph");
    cutg_b6f6->SetFillStyle(1000);
    cutg_b6f6->SetPoint(0,11700.5,4751.4);
    cutg_b6f6->SetPoint(1,11819.7,4679.71);
    cutg_b6f6->SetPoint(2,11975.6,4602.5);
    cutg_b6f6->SetPoint(3,12287.4,4525.29);
    cutg_b6f6->SetPoint(4,12590,4470.15);
    cutg_b6f6->SetPoint(5,12819.2,4464.63);
    cutg_b6f6->SetPoint(6,13020.9,4580.44);
    cutg_b6f6->SetPoint(7,13011.7,4740.37);
    cutg_b6f6->SetPoint(8,12892.5,4883.75);
    cutg_b6f6->SetPoint(9,12690.8,5038.16);
    cutg_b6f6->SetPoint(10,12424.9,5120.88);
    cutg_b6f6->SetPoint(11,12177.3,5176.03);
    cutg_b6f6->SetPoint(12,11948.1,5170.51);
    cutg_b6f6->SetPoint(13,11819.7,5153.97);
    cutg_b6f6->SetPoint(14,11682.2,5115.37);
    cutg_b6f6->SetPoint(15,11572.2,5054.71);
    cutg_b6f6->SetPoint(16,11535.5,4955.44);
    cutg_b6f6->SetPoint(17,11544.6,4867.21);
    cutg_b6f6->SetPoint(18,11618,4795.51);
    cutg_b6f6->SetPoint(19,11709.7,4751.4);
    cutg_b6f6->SetPoint(20,11700.5,4751.4);
    cutg_b6f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b6f6
    c7->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f6 = banana_b6f6->ProjectionX("projx_cutg_b6f6",1,banana_b6f6->GetNbinsX(),"[cutg_b6f6]");              
    projx_cutg_b6f6->Rebin(2);
    projx_cutg_b6f6->Draw("");
    projx_cutg_b6f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f6 = banana_b6f6->ProjectionY("projy_cutg_b6f6",1,banana_b6f6->GetNbinsY(),"[cutg_b6f6]");              
    projy_cutg_b6f6->Rebin(2);
    projy_cutg_b6f6->Draw("");
    projy_cutg_b6f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c7->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b6f7 60Ni(a,a) elastic peak
    banana_b6f7->GetXaxis()->SetRangeUser(9000,14000);
    banana_b6f7->GetYaxis()->SetRangeUser(3500,6000);
    banana_b6f7->Draw();

    TCutG *cutg_b6f7 = new TCutG("cutg_b6f7",23);
    cutg_b6f7->SetVarX(" E detector 6 strip 7");
    cutg_b6f7->SetVarY("#DeltaE ");
    cutg_b6f7->SetTitle("Graph");
    cutg_b6f7->SetFillStyle(1000);
    cutg_b6f7->SetPoint(0,11674.4,4522.21);
    cutg_b6f7->SetPoint(1,11863,4418.53);
    cutg_b6f7->SetPoint(2,12150.8,4390.88);
    cutg_b6f7->SetPoint(3,12458.5,4377.06);
    cutg_b6f7->SetPoint(4,12666.9,4383.97);
    cutg_b6f7->SetPoint(5,12885.2,4377.06);
    cutg_b6f7->SetPoint(6,13093.6,4460);
    cutg_b6f7->SetPoint(7,13192.9,4598.24);
    cutg_b6f7->SetPoint(8,13103.6,4743.38);
    cutg_b6f7->SetPoint(9,12736.4,4923.09);
    cutg_b6f7->SetPoint(10,12468.4,5033.68);
    cutg_b6f7->SetPoint(11,12131,5144.26);
    cutg_b6f7->SetPoint(12,11922.5,5165);
    cutg_b6f7->SetPoint(13,11714.1,5165);
    cutg_b6f7->SetPoint(14,11614.9,5075.15);
    cutg_b6f7->SetPoint(15,11485.9,5019.85);
    cutg_b6f7->SetPoint(16,11426.3,4923.09);
    cutg_b6f7->SetPoint(17,11426.3,4784.85);
    cutg_b6f7->SetPoint(18,11505.7,4639.71);
    cutg_b6f7->SetPoint(19,11555.3,4591.32);
    cutg_b6f7->SetPoint(20,11664.5,4522.21);
    cutg_b6f7->SetPoint(21,11694.3,4508.38);
    cutg_b6f7->SetPoint(22,11674.4,4522.21);
    cutg_b6f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b6f7
    c7->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b6f7 = banana_b6f7->ProjectionX("projx_cutg_b6f7",1,banana_b6f7->GetNbinsX(),"[cutg_b6f7]");              
    projx_cutg_b6f7->Rebin(2);
    projx_cutg_b6f7->Draw("");
    projx_cutg_b6f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b6f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c7->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b6f7 = banana_b6f7->ProjectionY("projy_cutg_b6f7",1,banana_b6f7->GetNbinsY(),"[cutg_b6f7]");              
    projy_cutg_b6f7->Rebin(2);
    projy_cutg_b6f7->Draw("");
    projy_cutg_b6f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b6f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b6f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;    


    ///////////////////
    // E DETECTOR b7 //
    ///////////////////

    // Make canvas to plot the 2D banana plots in the range of the elastic peak
    TCanvas *c8 = new TCanvas("c8","c8:b7 bananas",1400,800);
    c8->Divide(8,3,0,0);
    c8->cd(1);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f0 60Ni(a,a) elastic peak
    banana_b7f0->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f0->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f0->Draw();

    TCutG *cutg_b7f0 = new TCutG("cutg_b7f0",23);
    cutg_b7f0->SetVarX(" E detector 7 strip 0");
    cutg_b7f0->SetVarY("#DeltaE ");
    cutg_b7f0->SetTitle("Graph");
    cutg_b7f0->SetFillStyle(1000);
    cutg_b7f0->SetPoint(0,10929.8,4790.15);
    cutg_b7f0->SetPoint(1,11047.6,4676.4);
    cutg_b7f0->SetPoint(2,11192.6,4602.79);
    cutg_b7f0->SetPoint(3,11428.2,4562.65);
    cutg_b7f0->SetPoint(4,11736.3,4562.65);
    cutg_b7f0->SetPoint(5,11990,4596.1);
    cutg_b7f0->SetPoint(6,12135,4723.24);
    cutg_b7f0->SetPoint(7,12153.1,4944.04);
    cutg_b7f0->SetPoint(8,11999.1,5124.71);
    cutg_b7f0->SetPoint(9,11826.9,5258.53);
    cutg_b7f0->SetPoint(10,11582.3,5345.51);
    cutg_b7f0->SetPoint(11,11401,5378.97);
    cutg_b7f0->SetPoint(12,11219.8,5445.88);
    cutg_b7f0->SetPoint(13,11056.7,5452.57);
    cutg_b7f0->SetPoint(14,10920.8,5385.66);
    cutg_b7f0->SetPoint(15,10721.4,5318.75);
    cutg_b7f0->SetPoint(16,10658,5178.24);
    cutg_b7f0->SetPoint(17,10658,5064.49);
    cutg_b7f0->SetPoint(18,10685.2,4990.88);
    cutg_b7f0->SetPoint(19,10748.6,4897.21);
    cutg_b7f0->SetPoint(20,10875.5,4796.84);
    cutg_b7f0->SetPoint(21,10938.9,4770.07);
    cutg_b7f0->SetPoint(22,10929.8,4790.15);
    cutg_b7f0->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f0
    c8->cd(9);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f0 = banana_b7f0->ProjectionX("projx_cutg_b7f0",1,banana_b7f0->GetNbinsX(),"[cutg_b7f0]");              
    projx_cutg_b7f0->Rebin(2);
    projx_cutg_b7f0->Draw("");
    projx_cutg_b7f0->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f0->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(17);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f0 = banana_b7f0->ProjectionY("projy_cutg_b7f0",1,banana_b7f0->GetNbinsY(),"[cutg_b7f0]");              
    projy_cutg_b7f0->Rebin(2);
    projy_cutg_b7f0->Draw("");
    projy_cutg_b7f0->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f0->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f0" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(2);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f1 60Ni(a,a) elastic peak
    banana_b7f1->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f1->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f1->Draw();
   
    TCutG *cutg_b7f1 = new TCutG("cutg_b7f1",21);
    cutg_b7f1->SetVarX(" E detector 7 strip 1");
    cutg_b7f1->SetVarY("#DeltaE ");
    cutg_b7f1->SetTitle("Graph");
    cutg_b7f1->SetFillStyle(1000);
    cutg_b7f1->SetPoint(0,10984.8,4908.82);
    cutg_b7f1->SetPoint(1,11230.7,4809.41);
    cutg_b7f1->SetPoint(2,11452.1,4702.35);
    cutg_b7f1->SetPoint(3,11722.7,4641.18);
    cutg_b7f1->SetPoint(4,12030.1,4602.94);
    cutg_b7f1->SetPoint(5,12312.9,4648.82);
    cutg_b7f1->SetPoint(6,12337.5,4794.12);
    cutg_b7f1->SetPoint(7,12239.2,4985.29);
    cutg_b7f1->SetPoint(8,12091.6,5084.71);
    cutg_b7f1->SetPoint(9,11784.1,5268.24);
    cutg_b7f1->SetPoint(10,11550.5,5382.94);
    cutg_b7f1->SetPoint(11,11243,5421.18);
    cutg_b7f1->SetPoint(12,10997.1,5421.18);
    cutg_b7f1->SetPoint(13,10800.3,5375.29);
    cutg_b7f1->SetPoint(14,10726.5,5275.88);
    cutg_b7f1->SetPoint(15,10701.9,5153.53);
    cutg_b7f1->SetPoint(16,10714.2,5038.82);
    cutg_b7f1->SetPoint(17,10800.3,4977.65);
    cutg_b7f1->SetPoint(18,10898.7,4939.41);
    cutg_b7f1->SetPoint(19,10984.8,4916.47);
    cutg_b7f1->SetPoint(20,10984.8,4908.82);
    cutg_b7f1->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f1
    c8->cd(10);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f1 = banana_b7f1->ProjectionX("projx_cutg_b7f1",1,banana_b7f1->GetNbinsX(),"[cutg_b7f1]");              
    projx_cutg_b7f1->Rebin(2);
    projx_cutg_b7f1->Draw("");
    projx_cutg_b7f1->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f1->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(18);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f1 = banana_b7f1->ProjectionY("projy_cutg_b7f1",1,banana_b7f1->GetNbinsY(),"[cutg_b7f1]");              
    projy_cutg_b7f1->Rebin(2);
    projy_cutg_b7f1->Draw("");
    projy_cutg_b7f1->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f1->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f1" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(3);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f2 60Ni(a,a) elastic peak
    banana_b7f2->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f2->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f2->Draw();

    TCutG *cutg_b7f2 = new TCutG("cutg_b7f2",21);
    cutg_b7f2->SetVarX(" E detector 7 strip 2");
    cutg_b7f2->SetVarY("#DeltaE ");
    cutg_b7f2->SetTitle("Graph");
    cutg_b7f2->SetFillStyle(1000);
    cutg_b7f2->SetPoint(0,11001.5,4965);
    cutg_b7f2->SetPoint(1,11177.5,4850.74);
    cutg_b7f2->SetPoint(2,11342.6,4790.88);
    cutg_b7f2->SetPoint(3,11606.7,4752.79);
    cutg_b7f2->SetPoint(4,11914.8,4720.15);
    cutg_b7f2->SetPoint(5,12123.8,4752.79);
    cutg_b7f2->SetPoint(6,12222.8,4828.97);
    cutg_b7f2->SetPoint(7,12244.9,4986.76);
    cutg_b7f2->SetPoint(8,12200.8,5101.03);
    cutg_b7f2->SetPoint(9,12002.8,5242.5);
    cutg_b7f2->SetPoint(10,11672.7,5302.35);
    cutg_b7f2->SetPoint(11,11507.6,5335);
    cutg_b7f2->SetPoint(12,11254.6,5356.76);
    cutg_b7f2->SetPoint(13,11045.5,5351.32);
    cutg_b7f2->SetPoint(14,10891.5,5318.68);
    cutg_b7f2->SetPoint(15,10847.4,5215.29);
    cutg_b7f2->SetPoint(16,10847.4,5117.35);
    cutg_b7f2->SetPoint(17,10891.5,5062.94);
    cutg_b7f2->SetPoint(18,10946.5,5019.41);
    cutg_b7f2->SetPoint(19,11012.5,4965);
    cutg_b7f2->SetPoint(20,11001.5,4965);
    cutg_b7f2->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f2
    c8->cd(11);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f2 = banana_b7f2->ProjectionX("projx_cutg_b7f2",1,banana_b7f2->GetNbinsX(),"[cutg_b7f2]");              
    projx_cutg_b7f2->Rebin(2);
    projx_cutg_b7f2->Draw("");
    projx_cutg_b7f2->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f2->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(19);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f2 = banana_b7f2->ProjectionY("projy_cutg_b7f2",1,banana_b7f2->GetNbinsY(),"[cutg_b7f2]");              
    projy_cutg_b7f2->Rebin(2);
    projy_cutg_b7f2->Draw("");
    projy_cutg_b7f2->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f2->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f2" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(4);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f3 60Ni(a,a) elastic peak
    banana_b7f3->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f3->GetYaxis()->SetRangeUser(3500,6000);
    banana_b7f3->Draw();

    TCutG *cutg_b7f3 = new TCutG("cutg_b7f3",21);
    cutg_b7f3->SetVarX(" E detector 7 strip 3");
    cutg_b7f3->SetVarY("#DeltaE ");
    cutg_b7f3->SetTitle("Graph");
    cutg_b7f3->SetFillStyle(1000);
    cutg_b7f3->SetPoint(0,10955.6,4755);
    cutg_b7f3->SetPoint(1,11144.2,4642.5);
    cutg_b7f3->SetPoint(2,11308.2,4592.5);
    cutg_b7f3->SetPoint(3,11586.9,4548.75);
    cutg_b7f3->SetPoint(4,11824.7,4523.75);
    cutg_b7f3->SetPoint(5,11996.9,4517.5);
    cutg_b7f3->SetPoint(6,12160.8,4580);
    cutg_b7f3->SetPoint(7,12201.8,4705);
    cutg_b7f3->SetPoint(8,12185.4,4792.5);
    cutg_b7f3->SetPoint(9,12111.6,4917.5);
    cutg_b7f3->SetPoint(10,11980.5,5036.25);
    cutg_b7f3->SetPoint(11,11816.5,5130);
    cutg_b7f3->SetPoint(12,11537.7,5173.75);
    cutg_b7f3->SetPoint(13,11275.4,5173.75);
    cutg_b7f3->SetPoint(14,11013,5136.25);
    cutg_b7f3->SetPoint(15,10939.2,5080);
    cutg_b7f3->SetPoint(16,10898.3,4967.5);
    cutg_b7f3->SetPoint(17,10898.3,4848.75);
    cutg_b7f3->SetPoint(18,10988.4,4748.75);
    cutg_b7f3->SetPoint(19,11004.8,4730);
    cutg_b7f3->SetPoint(20,10955.6,4755);
    cutg_b7f3->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f3
    c8->cd(12);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f3 = banana_b7f3->ProjectionX("projx_cutg_b7f3",1,banana_b7f3->GetNbinsX(),"[cutg_b7f3]");              
    projx_cutg_b7f3->Rebin(2);
    projx_cutg_b7f3->Draw("");
    projx_cutg_b7f3->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f3->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(20);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f3 = banana_b7f3->ProjectionY("projy_cutg_b7f3",1,banana_b7f3->GetNbinsY(),"[cutg_b7f3]");              
    projy_cutg_b7f3->Rebin(2);
    projy_cutg_b7f3->Draw("");
    projy_cutg_b7f3->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f3->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f3" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(5);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f4 60Ni(a,a) elastic peak
    banana_b7f4->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f4->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f4->Draw();

    TCutG *cutg_b7f4 = new TCutG("cutg_b7f4",16);
    cutg_b7f4->SetVarX(" E detector 7 strip 4");
    cutg_b7f4->SetVarY("#DeltaE ");
    cutg_b7f4->SetTitle("Graph");
    cutg_b7f4->SetFillStyle(1000);
    cutg_b7f4->SetPoint(0,11022.5,4911.1);
    cutg_b7f4->SetPoint(1,11292.9,4796.99);
    cutg_b7f4->SetPoint(2,11575.1,4739.93);
    cutg_b7f4->SetPoint(3,11974.9,4739.93);
    cutg_b7f4->SetPoint(4,12245.3,4775.59);
    cutg_b7f4->SetPoint(5,12257.1,4939.63);
    cutg_b7f4->SetPoint(6,12163,5089.41);
    cutg_b7f4->SetPoint(7,11939.6,5217.79);
    cutg_b7f4->SetPoint(8,11586.9,5324.78);
    cutg_b7f4->SetPoint(9,11351.7,5396.1);
    cutg_b7f4->SetPoint(10,11093,5367.57);
    cutg_b7f4->SetPoint(11,10940.2,5289.12);
    cutg_b7f4->SetPoint(12,10940.2,5160.74);
    cutg_b7f4->SetPoint(13,10951.9,4975.29);
    cutg_b7f4->SetPoint(14,11034.2,4911.1);
    cutg_b7f4->SetPoint(15,11022.5,4911.1);
    cutg_b7f4->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f4
    c8->cd(13);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f4 = banana_b7f4->ProjectionX("projx_cutg_b7f4",1,banana_b7f4->GetNbinsX(),"[cutg_b7f4]");              
    projx_cutg_b7f4->Rebin(2);
    projx_cutg_b7f4->Draw("");
    projx_cutg_b7f4->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f4->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(21);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f4 = banana_b7f4->ProjectionY("projy_cutg_b7f4",1,banana_b7f4->GetNbinsY(),"[cutg_b7f4]");              
    projy_cutg_b7f4->Rebin(2);
    projy_cutg_b7f4->Draw("");
    projy_cutg_b7f4->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f4->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f4" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;


    c8->cd(6);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f5 60Ni(a,a) elastic peak
    banana_b7f5->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f5->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f5->Draw();

    TCutG *cutg_b7f5 = new TCutG("cutg_b7f5",19);
    cutg_b7f5->SetVarX(" E detector 7 strip 5");
    cutg_b7f5->SetVarY("#DeltaE ");
    cutg_b7f5->SetTitle("Graph");
    cutg_b7f5->SetFillStyle(1000);
    cutg_b7f5->SetPoint(0,11089,4792.94);
    cutg_b7f5->SetPoint(1,11367.6,4705);
    cutg_b7f5->SetPoint(2,11566.6,4610.29);
    cutg_b7f5->SetPoint(3,11752.4,4576.47);
    cutg_b7f5->SetPoint(4,11964.7,4549.41);
    cutg_b7f5->SetPoint(5,12163.7,4583.24);
    cutg_b7f5->SetPoint(6,12362.8,4718.53);
    cutg_b7f5->SetPoint(7,12322.9,4867.35);
    cutg_b7f5->SetPoint(8,12150.5,4968.82);
    cutg_b7f5->SetPoint(9,11924.9,5083.82);
    cutg_b7f5->SetPoint(10,11633,5185.29);
    cutg_b7f5->SetPoint(11,11380.9,5198.82);
    cutg_b7f5->SetPoint(12,11089,5205.59);
    cutg_b7f5->SetPoint(13,10943,5097.35);
    cutg_b7f5->SetPoint(14,10943,4948.53);
    cutg_b7f5->SetPoint(15,10982.8,4874.12);
    cutg_b7f5->SetPoint(16,11049.2,4813.24);
    cutg_b7f5->SetPoint(17,11115.5,4792.94);
    cutg_b7f5->SetPoint(18,11089,4792.94);
    cutg_b7f5->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f5
    c8->cd(14);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f5 = banana_b7f5->ProjectionX("projx_cutg_b7f5",1,banana_b7f5->GetNbinsX(),"[cutg_b7f5]");              
    projx_cutg_b7f5->Rebin(2);
    projx_cutg_b7f5->Draw("");
    projx_cutg_b7f5->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f5->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(22);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f5 = banana_b7f5->ProjectionY("projy_cutg_b7f5",1,banana_b7f5->GetNbinsY(),"[cutg_b7f5]");              
    projy_cutg_b7f5->Rebin(2);
    projy_cutg_b7f5->Draw("");
    projy_cutg_b7f5->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f5->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f5" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(7);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f6 60Ni(a,a) elastic peak
    banana_b7f6->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f6->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f6->Draw();

    TCutG *cutg_b7f6 = new TCutG("cutg_b7f6",21);
    cutg_b7f6->SetVarX(" E detector 7 strip 6");
    cutg_b7f6->SetVarY("#DeltaE ");
    cutg_b7f6->SetTitle("Graph");
    cutg_b7f6->SetFillStyle(1000);
    cutg_b7f6->SetPoint(0,10953.3,5087.72);
    cutg_b7f6->SetPoint(1,11116,4947.35);
    cutg_b7f6->SetPoint(2,11253.6,4868.01);
    cutg_b7f6->SetPoint(3,11591.5,4794.78);
    cutg_b7f6->SetPoint(4,11891.8,4776.47);
    cutg_b7f6->SetPoint(5,12154.6,4770.37);
    cutg_b7f6->SetPoint(6,12442.4,4825.29);
    cutg_b7f6->SetPoint(7,12530,4904.63);
    cutg_b7f6->SetPoint(8,12530,5002.28);
    cutg_b7f6->SetPoint(9,12392.4,5118.24);
    cutg_b7f6->SetPoint(10,12317.3,5173.16);
    cutg_b7f6->SetPoint(11,12104.6,5289.12);
    cutg_b7f6->SetPoint(12,11829.3,5374.56);
    cutg_b7f6->SetPoint(13,11591.5,5466.1);
    cutg_b7f6->SetPoint(14,11353.7,5466.1);
    cutg_b7f6->SetPoint(15,11065.9,5460);
    cutg_b7f6->SetPoint(16,10953.3,5325.74);
    cutg_b7f6->SetPoint(17,10940.8,5234.19);
    cutg_b7f6->SetPoint(18,10940.8,5142.65);
    cutg_b7f6->SetPoint(19,10978.3,5075.51);
    cutg_b7f6->SetPoint(20,10953.3,5087.72);
    cutg_b7f6->Draw("same");


    // Plot the projection on the E detector axis (x axis), b7f6
    c8->cd(15);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f6 = banana_b7f6->ProjectionX("projx_cutg_b7f6",1,banana_b7f6->GetNbinsX(),"[cutg_b7f6]");              
    projx_cutg_b7f6->Rebin(2);
    projx_cutg_b7f6->Draw("");
    projx_cutg_b7f6->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f6->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(23);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f6 = banana_b7f6->ProjectionY("projy_cutg_b7f6",1,banana_b7f6->GetNbinsY(),"[cutg_b7f6]");              
    projy_cutg_b7f6->Rebin(2);
    projy_cutg_b7f6->Draw("");
    projy_cutg_b7f6->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f6->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f6" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;

    c8->cd(8);
    gPad->SetLogz();
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);

    // The b7f7 60Ni(a,a) elastic peak
    banana_b7f7->GetXaxis()->SetRangeUser(9000,14000);
    banana_b7f7->GetYaxis()->SetRangeUser(3700,6200);
    banana_b7f7->Draw();

    TCutG *cutg_b7f7 = new TCutG("cutg_b7f7",21);
    cutg_b7f7->SetVarX(" E detector 7 strip 7");
    cutg_b7f7->SetVarY("#DeltaE ");
    cutg_b7f7->SetTitle("Graph");
    cutg_b7f7->SetFillStyle(1000);
    cutg_b7f7->SetPoint(0,10850.3,4941.76);
    cutg_b7f7->SetPoint(1,11123.3,4802.21);
    cutg_b7f7->SetPoint(2,11455.5,4710.96);
    cutg_b7f7->SetPoint(3,11728.4,4684.12);
    cutg_b7f7->SetPoint(4,11953.9,4684.12);
    cutg_b7f7->SetPoint(5,12226.8,4689.49);
    cutg_b7f7->SetPoint(6,12381.1,4743.16);
    cutg_b7f7->SetPoint(7,12464.1,4834.41);
    cutg_b7f7->SetPoint(8,12416.7,4995.44);
    cutg_b7f7->SetPoint(9,12298,5118.9);
    cutg_b7f7->SetPoint(10,12072.6,5247.72);
    cutg_b7f7->SetPoint(11,11740.3,5317.5);
    cutg_b7f7->SetPoint(12,11408,5355.07);
    cutg_b7f7->SetPoint(13,11123.3,5344.34);
    cutg_b7f7->SetPoint(14,10957.1,5349.71);
    cutg_b7f7->SetPoint(15,10802.9,5290.66);
    cutg_b7f7->SetPoint(16,10731.7,5177.94);
    cutg_b7f7->SetPoint(17,10731.7,5097.43);
    cutg_b7f7->SetPoint(18,10767.3,5000.81);
    cutg_b7f7->SetPoint(19,10850.3,4936.4);
    cutg_b7f7->SetPoint(20,10850.3,4941.76);
    cutg_b7f7->Draw("same");

    // Plot the projection on the E detector axis (x axis), b7f7
    c8->cd(16);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the E detector
    TH1D *projx_cutg_b7f7 = banana_b7f7->ProjectionX("projx_cutg_b7f7",1,banana_b7f7->GetNbinsX(),"[cutg_b7f7]");              
    projx_cutg_b7f7->Rebin(2);
    projx_cutg_b7f7->Draw("");
    projx_cutg_b7f7->Fit("gaus");
    fitx = (TF1*)projx_cutg_b7f7->GetListOfFunctions()->FindObject("gaus");
    centroidx = fitx->GetParameter(1);

    // Plot the projection on the Delta E detector axis (y axis)
    c8->cd(24);
    gPad->SetBottomMargin(0.13);
    gPad->SetLeftMargin(0.14);
    gPad->SetRightMargin(0.03);
    gPad->SetTopMargin(0.07);
    // Grab the centroid for the Delta E detector
    TH1D *projy_cutg_b7f7 = banana_b7f7->ProjectionY("projy_cutg_b7f7",1,banana_b7f7->GetNbinsY(),"[cutg_b7f7]");              
    projy_cutg_b7f7->Rebin(2);
    projy_cutg_b7f7->Draw("");
    projy_cutg_b7f7->Fit("gaus");
    fity = (TF1*)projy_cutg_b7f7->GetListOfFunctions()->FindObject("gaus");
    centroidy = fity->GetParameter(1);

    // Write the two centroids to file
    outfile << " b7f7" << endl;
    outfile << centroidx <<  "," << centroidy << endl;
    outfile << endl;    


    outfile.close();


}
