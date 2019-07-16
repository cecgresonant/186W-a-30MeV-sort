// Script to grab the m_e_de_b0fX matrices for the 60Ni(a,a) calibration data
// and make graphical cuts of the ground-state peak, and fit the energy 
// deposited in the E and Delta E detectors to be used for calibration
// of the 186W(a,a') data set. This is for the b0 detector.
// Cecilie, July 16, 2019

#include <fstream>
#include <iostream>

void TCutG_60Ni_aa_b0(){
    // No stats shown
    gStyle->SetOptStat(0);

    // Create output file to write the centroids of the 60Ni(a,a) peak in the Delta E and E detectors
    ofstream outfile("alpha_peaks_60Ni_b0.csv");
    outfile << " Ground-state peak positions for the elastic alpha scattering off 60Ni" << endl;
    
    // Grab input file
    TFile *file = TFile::Open("offline_60Ni_plain.root");
	TH2D *banana_b0f0  = (TH2D*)file->Get("m_e_de_b0f0"); // Delta E - E matrix for b0f0
    TH2D *banana_b0f1  = (TH2D*)file->Get("m_e_de_b0f1"); // Delta E - E matrix for b0f1
    TH2D *banana_b0f2  = (TH2D*)file->Get("m_e_de_b0f2"); // Delta E - E matrix for b0f2
    TH2D *banana_b0f3  = (TH2D*)file->Get("m_e_de_b0f3"); // Delta E - E matrix for b0f3
    TH2D *banana_b0f4  = (TH2D*)file->Get("m_e_de_b0f4"); // Delta E - E matrix for b0f4
    TH2D *banana_b0f5  = (TH2D*)file->Get("m_e_de_b0f5"); // Delta E - E matrix for b0f5
    TH2D *banana_b0f6  = (TH2D*)file->Get("m_e_de_b0f6"); // Delta E - E matrix for b0f6
    TH2D *banana_b0f7  = (TH2D*)file->Get("m_e_de_b0f7"); // Delta E - E matrix for b0f7


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

    outfile.close();

    c1->Print("fit_60Ni_aa_peaks.png"); 

}
