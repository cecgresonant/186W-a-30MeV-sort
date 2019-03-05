{
//    bool loaded = false;
//    const char* paths[] = {"libEvent.so", "./src/libEvent.so",
//                           "/home/ab/geant4/tmp/Linux-g++/chato/libEvent.so",
//                           "/home/abuerger/geant4/tmp/Linux-g++/chato/libEvent.so",
//                           0 };
//    for(int i=0; !loaded && paths[i]; ++i) {
//        if (!gSystem->AccessPathName(paths[i])) {
//            gSystem->Load(paths[i]);
//            loaded = true;
//        }
//    }
//    if( !loaded ) {
//        cout << "Warning: no libEvent.so found." << endl;
//    }

//    char* fit1 = gSystem->ExpandPathName("~/Uni/E287c/ganan287c/mcr/fit1.C");
//    if (!gSystem->AccessPathName(fit1))
//        gROOT->LoadMacro(fit1);
//    else
//        cout << "Warning: no fit1.C found." << endl;
//    delete fit1;

//    gROOT->LoadMacro("fitN.C+");

    gStyle->SetPadGridX(kTRUE);
    gStyle->SetPadGridY(kTRUE);
    gStyle->SetPaperSize(11.7,18);
    gStyle->SetPalette(1);
    gStyle->SetCanvasColor(kWhite);
    gStyle->SetOptStat(1111111);
    gStyle->SetStatFormat("10.8g");
    gStyle->SetNdivisions(520,"y");
}
