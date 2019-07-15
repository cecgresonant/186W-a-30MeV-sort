// Script to grab the m_e_de_b0fX matrices for the 60Ni(a,a') calibration data
// and make graphical cuts of the ground-state peak, and fit the energy 
// deposited in the E and Delta E detectors to be used for calibration
// of the 186W(a,a') data set. This is now for the b0 
// Cecilie, July 2, 2019

void TCutG_60Ni_aa_b0(){
    
    // Grab input file
    TFile *file = TFile::Open("offline_60Ni_plain.root");
	TH2F *banana_b0f0  = (TH2F*)file->Get("m_e_de_b0f0"); // Delta E - E matrix for b0f0



    TCanvas *c1 = new TCanvas("c1","c1",800,700);
    c1->cd();
    c1->SetLogz();
    c1->SetBottomMargin(0.13);
    c1->SetLeftMargin(0.14);
    banana_b0f0->Draw();

    /*
    nai_matrix->SetTitle("^{56}Fe(p,p'#gamma), NaI:Tl detectors ");
    nai_matrix->GetXaxis()->SetTitle("#gamma energy E_{#gamma} (keV)");
    nai_matrix->GetXaxis()->SetTitleSize(0.045);
    nai_matrix->GetXaxis()->SetLabelSize(0.04);
    nai_matrix->GetXaxis()->SetTitleOffset(1.2);
    nai_matrix->GetXaxis()->CenterTitle();
    nai_matrix->GetYaxis()->SetTitle("Excitation energy E (keV)");
    nai_matrix->GetYaxis()->SetTitleSize(0.045);
    nai_matrix->GetYaxis()->SetLabelSize(0.04);
    nai_matrix->GetYaxis()->SetTitleOffset(1.5);
    nai_matrix->GetYaxis()->CenterTitle();
    nai_matrix->GetXaxis()->SetRangeUser(0,11800);
    nai_matrix->GetYaxis()->SetRangeUser(300,11800);
    nai_matrix->GetZaxis()->SetRangeUser(1,8000);
    nai_matrix->Draw();
    
    gPad->Update();
	TPaletteAxis *palette = (TPaletteAxis*)nai_matrix->GetListOfFunctions()->FindObject("palette");
	if(!palette)
        cout << "nono." << endl;
    //palette->SetX1NDC(0.905);
    //palette->SetX2NDC(0.93);
    palette->SetLabelSize(0.03);
    palette->Draw();
	c1->Print("nai_e_eg_matrix_56Fe.png");

    
    TCanvas *c2 = new TCanvas("c2","LaBr3 Ex-Eg matrix",800,700);
    c2->cd();
    c2->SetBottomMargin(0.13);
    c2->SetLeftMargin(0.14);
    c2->SetLogz();
    labr3_matrix->SetTitle("^{56}Fe(p,p'#gamma), LaBr_{3}:Ce detectors ");
    labr3_matrix->GetXaxis()->SetTitle("#gamma energy E_{#gamma} (keV)");
    labr3_matrix->GetXaxis()->SetTitleSize(0.045);
    labr3_matrix->GetXaxis()->SetLabelSize(0.04);
    labr3_matrix->GetXaxis()->SetTitleOffset(1.2);
    labr3_matrix->GetXaxis()->CenterTitle();
    labr3_matrix->GetYaxis()->SetTitle("Excitation energy E (keV)");
    labr3_matrix->GetYaxis()->SetTitleSize(0.045);
    labr3_matrix->GetYaxis()->SetLabelSize(0.04);
    labr3_matrix->GetYaxis()->SetTitleOffset(1.5);
    labr3_matrix->GetYaxis()->CenterTitle();
    labr3_matrix->GetXaxis()->SetRangeUser(0,11800);
    labr3_matrix->GetYaxis()->SetRangeUser(300,11800);
    labr3_matrix->GetZaxis()->SetRangeUser(1,700);
    labr3_matrix->Draw();
    
    gPad->Update();
	TPaletteAxis *palette = (TPaletteAxis*)labr3_matrix->GetListOfFunctions()->FindObject("palette");
	if(!palette)
        cout << "nono." << endl;
        //palette->SetX1NDC(0.905);
        //palette->SetX2NDC(0.93);
    palette->SetLabelSize(0.03);
    palette->Draw();
    
    c2->Print("labr3_e_eg_matrix_56Fe.png");
    */

    
}
