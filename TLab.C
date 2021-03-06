#include "TLab.h"
#include "./includes.h"

#if !defined(__CINT__)
ClassImp(TLab)
#endif

// Default Constructor
TLab::TLab( ) {
    cout <<  endl;
    cout << " Default constructor. " << endl;
}

// option for use with one raw file 
TLab::TLab(TString runNumber) {
SetFilenames(runNumber);
}

TLab::TLab(TString runNumber,
TString simNumber) {
simData = new TSim(simNumber);
SetFilenames(runNumber);
}

// option for use with multiple raw files
// per run
TLab::TLab(TString runNumber,
TString fileNumStart,
        TString fileNumFinish) {

cout << endl;
cout << " fileNumStart  = " << fileNumStart  << endl;
cout << " fileNumFinish = " << fileNumFinish << endl;

fileNumStart  = "_" + fileNumStart;
fileNumFinish = "_" + fileNumFinish;

SetFilenames(runNumber,
        fileNumStart,
        fileNumFinish);

}

//-------------------------------------------------

TLab::~TLab()
{
    cout << endl;
    cout << " TLab object has been destructed!" << endl;
}

// ------------------------------------------------

void TLab::SetFilenames(TString runNumber){

cout << endl;
cout << " TLab object has been created " << endl;

runNumberInt = runNumber.Atoi();

cout << endl;
cout << " Run Number = " << runNumberInt << endl;

textFileName    = runNumber + ".txt";
rootFileRawName = runNumber + ".root";
rootFileCalName = runNumber + ".root";

textFileName    = "../Data/run" + textFileName;
rootFileRawName = "../Data/run" + rootFileRawName;
rootFileCalName = "../Data/cal" + rootFileCalName;

}

void TLab::SetFilenames(TString runNumber,
TString fileNumStart,
        TString fileNumFinish) {

cout << endl;
cout << " TLab object has been created " << endl;

runNumberInt = runNumber.Atoi();

cout << endl;
cout << " Run Number    = " << runNumberInt  << endl;

textFileName    = runNumber + fileNumStart;
rootFileRawName = runNumber + fileNumStart;
rootFileCalName = runNumber + fileNumStart;

textFileName    = textFileName    + fileNumFinish;
rootFileRawName = rootFileRawName + fileNumFinish;
rootFileCalName = rootFileCalName + fileNumFinish;

textFileName    = textFileName    + ".txt";
rootFileRawName = rootFileRawName + ".root";
rootFileCalName = rootFileCalName + ".root";

textFileName    = "../Data/run" + textFileName;
rootFileRawName = "../Data/run" + rootFileRawName;
rootFileCalName = "../Data/cal" + rootFileCalName;

cout << " rootFileRawName = " << rootFileRawName << endl;
}

/** Public member functions *********/

Bool_t TLab::RawROOTFileExists(){

    TFile *file = TFile::Open(rootFileRawName);

    return file;
}

void TLab::MakeRawDataTreeFile(){

    TString textFile = "??";
    TString rootFile = "??";

    eventNumber = 0;

    for(Int_t i = 0 ; i < nChannels ; i++ ){
        Q[i] = 0.0;
        T[i] = 0.0;
    }

    textFile = textFileName;
    rootFile = rootFileRawName;

    inData = new ifstream(textFile);

    rootFileRawData = new TFile(rootFile,"RECREATE","Raw LYSO data");
    rawDataTree     = new TTree("rawDataTree",
                                "LYSO data QDC and TDC values");

    rawDataTree->Branch("eventNumber",
                        &eventNumber,
                        "eventNumber/L");

    TString tempString = "";

    tempString.Form("Q[%d]/F",nChannels);
    rawDataTree->Branch("Q",Q,tempString);

    tempString.Form("T[%d]/F",nChannels);
    rawDataTree->Branch("T",T,tempString);

    TString nameHist;
    TString titleHist;

    for(Int_t i = 0 ; i < nChannels ; i++ ){

        nameHist.Form("hQ%d",i);
        titleHist.Form("hQ%d;QDC bin;Counts",i);
        hQ[i] = new TH1F(nameHist,titleHist,4096,0,4096);

        nameHist.Form("hT%d",i);
        titleHist.Form("hT%d;TDC bin;Counts",i);
        hT[i] = new TH1F(nameHist,titleHist,5200,0,5200);

    }

    cout << endl;
    cout << " Making tree " << endl;

    eventNumber = 0;

    Int_t index = 0;

    while(*inData
            >> Q[0+index]
            >> Q[1+index]
            >> Q[2+index]
            >> Q[3+index]
            >> Q[4+index]
            >> T[0+index]
            >> T[1+index]
            >> T[2+index]
            >> T[3+index]
            >> T[4+index]
            ){

        if(eventNumber==0){

            if(index==0){
                cout << endl;
                cout << " Line format: " << endl;
            }
            cout << " "
                 << Q[0+index] << " "
                 << Q[1+index] << " "
                 << Q[2+index] << " "
                 << Q[3+index] << " "
                 << Q[4+index] << " "
                 << T[0+index] << " "
                 << T[1+index] << " "
                 << T[2+index] << " "
                 << T[3+index] << " "
                 << T[4+index] << " "
                 << endl;
        }

        for(Int_t i = index ; i < (index+5) ; i++ ){
            hQ[i]->Fill(Q[i]);
            hT[i]->Fill(T[i]);
        } // end of: for(Int_t i = 0 ; i < 16 ; i++ ...

        if(index==5){
            rawDataTree->Fill();
            eventNumber++;
        }

        if(index==0)
            index = 5;
        else
            index = 0;

    }// end of: while( .....

    cout << endl;
    cout << " Making " << rootFile << endl;

    rawDataTree->Write();

    // writes the histograms
    rootFileRawData->Write();

    rootFileRawData->Close();

}

Bool_t TLab::CalibratedROOTFileExists(){
    TFile *file = TFile::Open(rootFileCalName);
    return file;
}

void TLab::MakeCalibratedDataTreeFile(){

    cout << endl;
    cout << " Making calibrated data tree " << endl;

    // To Do - implement routine
    // to extract AND data pedestals
    // from OR - trigger data
    //SetPedestals();

    // To Do - implement routine
    // to calibrate AND trigger Na22 data
    // from OR trigger Ba133 data
    //CalibrateEnergy();
    //SetPhotopeaks();

    cout << endl;
    cout << "Post photopeak setting rootFileRawName is "
         << rootFileRawName << endl;

    // read from this
    rootFileRawData = new TFile(rootFileRawName);
    rawDataTree     = (TTree*)rootFileRawData->Get("rawDataTree");

    // write to this
    rootFileCalData = new TFile(rootFileCalName,
                                "RECREATE","Calibrated LYSO data");

    calDataTree     = new TTree("calDataTree",
                                "LYSO data QDC and TDC values");

    TString tempString = "";

    rawDataTree->SetBranchAddress("Q",Q);

    rawDataTree->SetBranchAddress("T",T);

    rawDataTree->SetBranchAddress("eventNumber",&eventNumber);

    tempString.Form("EA[%d]/F",nChannels);
    calDataTree->Branch("EA",EA,tempString);

    tempString.Form("EB[%d]/F",nChannels);
    calDataTree->Branch("EB",EB,tempString);

    tempString.Form("tHA[%d]/F",nChannels);
    calDataTree->Branch("tHA",tHA,tempString);

    tempString.Form("tHB[%d]/F",nChannels);
    calDataTree->Branch("tHB",tHB,tempString);

    tempString.Form("TA[%d]/F",nChannels);
    calDataTree->Branch("TA",TA,tempString);

    tempString.Form("TB[%d]/F",nChannels);
    calDataTree->Branch("TB",TB,tempString);

    TString plotNameA  = "";
    TString plotTitleA = "";
    TString plotNameB  = "";
    TString plotTitleB = "";

    Float_t min = 0;
    Float_t max = 1300;

    for( Int_t i = 0 ; i < nChannels ; i++ ){
        plotNameA.Form("hEA%d",i);
        plotTitleA.Form("hEA%d;Energy (keV);Counts",i);
        hEA[i] = new TH1F(plotNameA,plotTitleA,512,min,max);

        plotNameB.Form("hEB%d",i);
        plotTitleB.Form("hEB%d;QDC;Counts",i);
        hEB[i] = new TH1F(plotNameB,plotTitleB,512,min,max);
    }

    cout << " rawDataTree->GetEntries() = " <<
         rawDataTree->GetEntries() << endl;



    // Calculate E,T,theta
    for( Int_t i = 0 ; i < rawDataTree->GetEntries() ; i++ ){

        rawDataTree->GetEntry(i);

        // To Do: map channels to
        // crystal number scheme
        // for ease of use in
        // asymmetry calculation
        for (Int_t k = 0 ; k < 5 ; k ++){
            QA[k]  = Q[k];
            TA[k]  = T[k];


            //EA[k]  = (Q[k]-pedQ[k])*511./(phoQ[k]-pedQ[k]) ;

            EA[k]  = GetEnergy(Q[k],k);
            // EA[k]  = GetEnergy(Q[k]);

            tHA[k] = PhotonEnergyToTheta(EA[k]);

            QB[k]  = Q[k+5];
            TB[k]  = T[k+5];
            EB[k]  = GetEnergy(Q[k+5], k+5);
            tHB[k] = PhotonEnergyToTheta(EB[k]);

        }


        // Create Energy Histos
        for( Int_t j = 0 ; j < nChannels ; j++ ) {

            hEA[j]->Fill(EA[j]);
            hEB[j]->Fill(EB[j]);

        }
        calDataTree->Fill();

    }

    calDataTree->Write();

    rootFileCalData->Write();

}

void TLab::SetPedestals(){

    // This method takes the value
    // in the maximum bin which will work
    // for data taken with OR trigger

    // To Do: take pedestals for AND trigger
    // data from OR data file/s

    cout << endl;
    cout << " Setting Pedestals " << endl;

    TString rawFileName;

    cout << endl;
    cout << " Reading " << rootFileRawName << endl;
    rootFileRawData = new TFile(rootFileRawName);

    TString histName = "";

    cout << endl;
    for( Int_t i = 0 ; i < nChannels ; i++ ){
        histName.Form("hQ%d",i);
        hQ[i] = (TH1F*)rootFileRawData->Get(histName);
        pedQ[i] = hQ[i]->GetXaxis()->GetBinCenter(hQ[i]->GetMaximumBin());
    }

    //!!!!!!!!!!!!!!!!!
    // Very temporary
    pedQ[4] = 600.0;
    pedQ[9] = 600.0;

    for( Int_t i = 0 ; i < nChannels ; i++ )
        cout << " pedQ["<< i << "] =  " << pedQ[i] << endl;

    rootFileRawData->Close();

}

Float_t TLab::GetPedestal(Int_t channel){
    return pedQ[channel];
}

Float_t TLab::GetEnergy(Float_t Q, Int_t iCrystal){

    Float_t m[10];
    Float_t c[10];


    //calibration run 1
    m[0] = 4.37743; m[1] = 4.64053; m[2] = 4.88337; m[3] = 4.40472; m[4] = 5.08472;
    m[5] = 5.71938; m[6] = 5.6558; m[7] = 5.28923; m[8] = 5.2653; m[9] = 6.34144;

    c[0] = 629.865; c[1] = 589.072; c[2] = 559.769; c[3] = 569.58; c[4] = 613.119;
    c[5] = 600.275; c[6] = 563.256; c[7] = 565.896; c[8] = 560.052; c[9] = 602.255;
/////////////////////////////////////////////////////////////////////////////////////////////
    //calibration run 1, fixed c
      /*m[0] = 4.4033; m[1] = 4.60787; m[2] = 4.77076; m[3] = 4.32109; m[4] = 4.99958;
      m[5] = 5.64133; m[6] = 5.52834; m[7] = 5.18928; m[8] = 5.14376; m[9] = 6.19753;

      c[0] = 622.; c[1] = 599.; c[2] = 594.; c[3] = 595.; c[4] = 639.;
      c[5] = 624.; c[6] = 602.; c[7] = 599.; c[8] = 597.; c[9] = 646.;*/
//////////////////////////////////////////////////////////////////////////////////////////////////
    //calibration run 2
    /*m[0] = 3.92203; m[1] = 4.56307; m[2] = 4.621; m[3] = 3.879; m[4] = 4.68;
    m[5] = 5.36765; m[6] = 5.54034; m[7] = 5.06367; m[8] = 5.1451; m[9] = 6.15134;

    c[0] = 657.885; c[1] = 590.613; c[2] = 567.701; c[3] = 580.325; c[4] = 633.83;
    c[5] = 605.669; c[6] = 565.058; c[7] = 568.702; c[8] = 562.729; c[9] = 613.128;*/
/////////////////////////////////////////////////////////////////////////////////////////////////
    /*//calibration run 2, fixed c
    m[0] = 4.03021; m[1] = 4.5289; m[2] = 4.5289; m[3] = 3.83072; m[4] = 4.56116;
    m[5] = 5.30406; m[6] = 5.41552; m[7] = 4.96616; m[8] = 5.03236; m[9] = 6.02281;

    c[0] = 625.; c[1] = 601.; c[2] = 599.; c[3] = 595.; c[4] = 649.5;
    c[5] = 625.; c[6] = 603.; c[7] = 601.; c[8] = 597.; c[9] = 652.2;*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////



    Float_t energy = (Q - c[iCrystal])/m[iCrystal];

    return energy;
}

void TLab::SetPhotopeaks(){

    cout << endl;
    cout << " Setting Photopeaks " << endl;

    //!!!!!!!!!!!!!!!!!
    // Very temporary
    phoQ[0] = 3600;
    phoQ[1] = 3600;
    phoQ[2] = 3600;
    phoQ[3] = 3600;
    phoQ[4] = 3600;
    phoQ[5] = 3600;
    phoQ[6] = 3600;
    phoQ[7] = 3600;
    phoQ[8] = 3600;
    phoQ[9] = 3600;

    cout << endl;
    for( Int_t i = 0 ; i < nChannels ; i++ ){

        cout << " phoQ["<< i << "] =  " << phoQ[i] << endl;

    }

}


Float_t TLab::GetPhotopeak(Int_t channel){
    return phoQ[channel];
}


Bool_t TLab::GoodTiming(Float_t time){

    Bool_t goodTime = kFALSE;

    // Unit is TDC bins
    Float_t timingRange[2];
    timingRange[0] =  800.;
    timingRange[1] = 1200.;

    if( time > timingRange[0] &&
        time < timingRange[1]   )
        goodTime = kTRUE;

    return goodTime;
}


Bool_t TLab::GoodTheta(Float_t theta){

    Bool_t goodTheta = kFALSE;

    // Asymmety is minimal below
    // 30 degrees but allow
    // for energy resolution
    Float_t thetaRange[2];
    thetaRange[0] =  10.;
    thetaRange[1] =  170.;

    if( theta > thetaRange[0]  &&
        theta < thetaRange[1] )
        goodTheta = kTRUE;

    return goodTheta;
}

void TLab::CalculateAsymmetry(Int_t   dPhi,
                              Float_t minTh,
                              Float_t maxTh
){

    // this function will calculate values
    // for the following data members:
    Asym    = 1.0;
    AsymErr = 0.0;

    Float_t minE = 200.;
    Float_t maxE = 400.;

    rootFileCalData = new TFile(rootFileCalName);
    calDataTree = (TTree*)rootFileCalData->Get("calDataTree");
    calDataTree->SetBranchAddress("EA",EA);
    calDataTree->SetBranchAddress("EB",EB);
    calDataTree->SetBranchAddress("tHA",tHA);
    calDataTree->SetBranchAddress("tHB",tHB);
    calDataTree->SetBranchAddress("TA",&TA);
    calDataTree->SetBranchAddress("TB",&TB);

    // example variables to use for checking
    // hits
    Bool_t A[nChannels];
    Bool_t B[nChannels];
    Int_t numA[nChannels];
    Int_t numB[nChannels];

    Bool_t hasScatteredA = kFALSE;
    Bool_t hasScatteredB = kFALSE;
    Int_t n0A = 0, n90A = 0, n180A = 0, n270A = 0;
    Int_t n0B = 0, n90B = 0, n180B = 0, n270B = 0;
    Int_t nDelPhi0 = 0, nDelPhi90 = 0, nDelPhi180 = 0, nDelPhi270 = 0;
    Int_t phiA = 0;
    Int_t phiB = 0;
    Int_t deltaPhi = 0;
    Int_t nSuccesses = 0;


    for ( Int_t i = 0 ; i < nChannels ; i++ ){
        A[i] = kFALSE;
        B[i] = kFALSE;
        numA[i] = 0;
        numB[i] = 0;
    }



    cout << endl;
    cout << " entries = " << calDataTree->GetEntries() << endl;

    Int_t nA4 = 0;

    for(Int_t i = 0 ; i < calDataTree->GetEntries(); i++ ){

        calDataTree->GetEvent(i);


        hasScatteredA = kFALSE;
        hasScatteredB = kFALSE;
        phiA = 2000;
        phiB = 3000;
        deltaPhi = 7000;

        for ( Int_t j = 0 ; j < nChannels ; j++ ){

            A[j] = kFALSE;
            B[j] = kFALSE;

            if((EA[4] < maxE && EA[4] > minE)){

                A[4] = kTRUE;
                numA[4]++;

                if((EA[4] + EA[j]) > 450. && (EA[4] + EA[j]) < 600.){
                    A[j] = kTRUE;
                    numA[j]++;
                    hasScatteredA = kTRUE;
                }
            }
            if((EB[4] < maxE && EB[4] > minE)){

                B[4] = kTRUE;
                numB[4]++;

                if((EB[4] + EB[j]) > 450. && (EB[4] + EB[j]) < 600.){
                    B[j] = kTRUE;
                    numB[j]++;
                    hasScatteredB = kTRUE;
                }
            }
            
        }


        if(hasScatteredA && hasScatteredB) {
            if (A[4] && A[0]) phiA = 0;
            else if (A[4] && A[1]) phiA = 90;
            else if (A[4] && A[2]) phiA = 180;
            else if (A[4] && A[3]) phiA = 270;

            if (B[4] && B[0]) phiB = 0;
            else if (B[4] && B[1]) phiB = 90;
            else if (B[4] && B[2]) phiB = 180;
            else if (B[4] && B[3]) phiB = 270;


            deltaPhi = phiA - phiB;
            if(deltaPhi < 0) deltaPhi += 360;

            if(deltaPhi == 0) nDelPhi0++;
            else if(deltaPhi == 90) nDelPhi90++;
            else if(deltaPhi == 180) nDelPhi180++;
            else if(deltaPhi == 270) nDelPhi270++;

            nSuccesses++;
        }

    }

    Int_t nScatters = nDelPhi0 + nDelPhi90 + nDelPhi180 + nDelPhi270;
    Float_t ratio0 = Float_t(nDelPhi0)/Float_t(nDelPhi0);
    Float_t ratio90 = Float_t(nDelPhi90)/Float_t(nDelPhi0);
    Float_t ratio180 = Float_t(nDelPhi180)/Float_t(nDelPhi0);
    Float_t ratio270 = Float_t(nDelPhi270)/Float_t(nDelPhi0);

    cout << " nA0 = " << numA[0] << endl;
    cout << " nA2 = " << numA[1] << endl;
    cout << " nA4 = " << numA[2] << endl;
    cout << " nA6 = " << numA[3] << endl;
    cout << " nA8 = " << numA[4] << endl;

    cout << " nB0 = " << numB[0] << endl;
    cout << " nB2 = " << numB[1] << endl;
    cout << " nB4 = " << numB[2] << endl;
    cout << " nB6 = " << numB[3] << endl;
    cout << " nB8 = " << numB[4] << endl;

    cout << "\nnDelphi = 0: " << nDelPhi0 << endl;
    cout << "N(0)/N(0) = " << ratio0 <<endl;
    cout << "\nnDelphi = 90: " << nDelPhi90 << endl;
    cout << "N(90)/N(0) = " << ratio90 << endl;
    cout << "\nnDelphi = 180: " << nDelPhi180 << endl;
    cout << "N(180)/N(0) = " << ratio180 << endl;
    cout << "\nnDelphi = 270: " << nDelPhi270 << endl;
    cout << "N(270)/N(0) = " << ratio270 << endl;

    cout << "\nnSuccesses: " << nSuccesses << endl;
    cout <<"compare to nScatters, should be same: " << nScatters << endl;


    cout << endl;
    cout << " Here is where the Asymmetry be calculated " << endl;
    cout << " A(" << dPhi << ") in the range "
         << minTh << " < #theta < " << maxTh << endl;
    cout << endl;

}

Float_t TLab::ElectronEnergyToTheta(Float_t energy){

    Float_t theta = 0.0;

    energy = 511. - energy;

    const Float_t m = 511.0;

    // cos(theta)
    theta = 2 - m/energy;

    theta = TMath::ACos(theta);
    theta = TMath::RadToDeg()*theta;

    return theta;
}

Float_t TLab::PhotonEnergyToTheta(Float_t energy){

    Float_t theta = 0.0;

    const Float_t m = 511.0;

    // cos(theta)
    theta = 2 - m/energy;

    theta = TMath::ACos(theta);
    theta = TMath::RadToDeg()*theta;

    return theta;
}

void TLab::GraphAsymmetry(Char_t option){

    SetStyle();

    TCanvas *canvas = new TCanvas("canvas","canvas",
                                  10,10,1200,800);

    const Int_t nBins = 4;

    // The ratio to be calculated for the
    // lab data:  90 e.g corresponds to
    // A(90) = P(90)/P(0)
    Int_t   dPhiDiff = 90;

    Float_t  theta[nBins];
    Float_t  thetaRange[nBins][2];
    Float_t  As090[nBins];
    Float_t  Ae090[nBins];

    // Theta range
    Float_t thetaLowEdge  = 30.;
    Float_t thetaHighEdge = 130.;

    Float_t thetaBinWidth = (thetaHighEdge - thetaLowEdge)/(Float_t)nBins;

    // Axis
    TH1F * hr;
    hr = canvas->DrawFrame(thetaLowEdge,0.5,thetaHighEdge,2.5);
    hr->GetXaxis()->SetTitle("#theta (deg)");

    hr->GetYaxis()->SetTitle("P(90^{o})/P(0^{o})");

    // Theory curve
    Float_t aTheory[nBins];
    // half resolution in dPhi
    // !!to do - access alpha1 from user input
    Float_t alpha1   = DegToRad()*22.5;
    // half resolution in theta
    Float_t semiSpan = thetaBinWidth/2.*DegToRad();

    cout << endl;
    cout << " semiSpan = " << semiSpan*RadToDeg() << endl;
    cout << " alpha1   = " << alpha1*RadToDeg()   << endl;

    TTheory * theory =  new TTheory();

    // Simulation results

    Float_t aSim[nBins];
    Float_t aSimE[nBins];

    for(Int_t i = 0 ; i < nBins ; i++){
        thetaRange[i][0]  = thetaLowEdge + thetaBinWidth*i;
        thetaRange[i][1]  = thetaRange[i][0] + thetaBinWidth;
        theta[i] = (thetaRange[i][0] + thetaRange[i][1])/2.;
    }

    // lab only
    if( option!='t' && option!='T'){

        cout << endl;
        cout << " Calculating asymmetry values and " << endl;
        cout << " associated errors for lab data ... " << endl;

        for(Int_t i = 0 ; i < nBins ; i++){

            CalculateAsymmetry(dPhiDiff,thetaRange[i][0],
                               thetaRange[i][1]);

            As090[i] = Asym;

            Ae090[i] = AsymErr;

            cout << endl;
            cout << " A(90,"<< theta[i] <<")/A(0,"<< theta[i] <<") = "
                 << As090[i] << " ± " << Ae090[i] << endl;
        }

    }// end of: if( option!='t' &...

    // theory and lab
    if( option=='t' || option=='T' ||
        option=='b' || option=='B' ){

        cout << endl;
        cout << " Calculating theory curve ... " << endl;

        for(Int_t i = 0 ; i < nBins ; i++){
            theta[i] = theta[i]*DegToRad();

            aTheory[i] = theory->rho2(theta[i],semiSpan,alpha1);

            theta[i] = theta[i]*RadToDeg();
        }

    }// end of:  if( option=='t' || option=='T'

    // sim
    if( option=='a' || option=='A' ||
        option=='s' || option=='S' ||
        option=='c' || option=='C' ){

        cout << endl;
        cout << " Calculating theory curve " << endl;
        cout << " and simulation results ... " << endl;

        for(Int_t i = 0 ; i < nBins ; i++){
            theta[i] = theta[i]*DegToRad();

            aTheory[i] = theory->rho2(theta[i],semiSpan,alpha1);

            aSim[i]    = simData->GetAsymm(i);
            aSimE[i]   = simData->GetAsymErr(i);

            theta[i] = theta[i]*RadToDeg();
        }

    }// end of:  if( option=='t' || option=='T'

    cout << endl;
    cout << " ... done.  " << endl;
    cout << " Plotting the results.  " << endl;

    TGraphErrors *grAsym[3];
    grAsym[0] =  new TGraphErrors(nBins,theta,As090,0,Ae090);
    grAsym[1] =  new TGraphErrors(nBins,theta,aTheory,0,0);

    grAsym[2] =  new TGraphErrors(nBins,theta,aSim,0,aSimE);

    grAsym[0]->SetLineColor(kBlue);
    grAsym[0]->SetMarkerColor(kBlue);
    grAsym[1]->SetLineColor(kRed);
    grAsym[1]->SetMarkerColor(kRed);
    grAsym[2]->SetLineColor(kGreen+2);
    grAsym[2]->SetMarkerColor(kGreen+2);

    TLegend * leg =  new TLegend(0.6,0.8,0.9,0.85);

    if     (option=='b' || option=='B'){
        leg->AddEntry(grAsym[0],"laboratory","E P");
        leg->AddEntry(grAsym[1],
                      "theory curve #alpha_{#Delta#phi} = 22.5^{o}","L P");
        grAsym[0]->Draw("P E");
        grAsym[1]->Draw("same P L");
    }
    else if(option=='l' || option=='L'){
        leg->AddEntry(grAsym[0],"laboratory","E P");
        grAsym[0]->Draw("P E");
    }
    else if(option == 't' || option == 'T'){
        leg->AddEntry(grAsym[1],
                      "theory curve #sigma_{#Delta#phi} = 20^{o}","L P");
        grAsym[1]->Draw("L P");
    }
    else if(option=='a' || option=='A'){
        leg->AddEntry(grAsym[0],
                      "laboratory","E P");
        leg->AddEntry(grAsym[1],
                      "theory curve #sigma_{#Delta#phi} = 20^{o}","L P");
        leg->AddEntry(grAsym[2],
                      "simulation (no entanglement)","P E");
        grAsym[0]->Draw("P E");
        grAsym[1]->Draw("same L P");
        grAsym[2]->Draw("same P");
    }
    else if(option=='c' || option=='C'){
        leg->AddEntry(grAsym[0],
                      "laboratory","E P");
        leg->AddEntry(grAsym[2],
                      "simulation (no entanglement)","P E");
        grAsym[0]->Draw("P E");
        grAsym[2]->Draw("same P");
    }
    else if(option=='s' || option=='S'){
        leg->AddEntry(grAsym[1],
                      "theory curve #sigma_{#Delta#phi} = 20^{o}","L P");
        leg->AddEntry(grAsym[2],
                      "simulation (no entanglement)","P E");
        grAsym[1]->Draw("P L");
        grAsym[2]->Draw("same P L");
    }

    leg->Draw();

    Char_t plotName[128];

    sprintf(plotName,"../Plots/A_%d.pdf",runNumberInt);

    canvas->SaveAs(plotName);

    // beep
    cout << '\a' << endl;

}

void TLab::SetStyle(){

    TStyle     *garyStyle  = new TStyle("garyStyle","My Root Styles");

    const Int_t NCont = 255;
    const Int_t NRGBs = 5;

    // Color scheme for 2D plotting with a better defined scale
    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);

    garyStyle->SetNumberContours(NCont);

    // General
    // OPTIONS - FILL LINE TEXT MARKER

    garyStyle->SetFillColor(0);
    garyStyle->SetTextSize(0.05);

    //-----------  Canvas

    garyStyle->SetCanvasBorderMode(0);
    garyStyle->SetCanvasColor(kWhite);

    //------------- Pad

    garyStyle->SetPadBorderMode(0);
    garyStyle->SetPadColor(kWhite);

    //Make more room for X and Y titles
    // one pad
    garyStyle->SetPadRightMargin(0.05);  //percentage
    garyStyle->SetPadLeftMargin(0.1);    //percentage
    garyStyle->SetPadBottomMargin(0.12); //percentage

    // six sub-pads
    // garyStyle->SetPadRightMargin(0.16);  //percentage
    // garyStyle->SetPadLeftMargin(0.2);    //percentage
    // garyStyle->SetPadBottomMargin(0.14); //percentage

    //----------- Histogram

    //Histos
    garyStyle->SetHistLineWidth(2);
    garyStyle->SetHistLineWidth(2);
    garyStyle->SetMarkerStyle(20);

    //  FILL CONTOURS LINE BAR
    //  Frames
    garyStyle->SetFrameBorderMode(0);

    //  FILL BORDER LINE
    //  Graphs
    //  LINE ERRORS

    //---------  Axis

    garyStyle->SetLabelFont(132,"XYZ");
    garyStyle->SetLabelSize(0.04,"XYZ");
    garyStyle->SetLabelOffset(0.01 ,"Y");

    //---------  Title
    garyStyle->SetOptTitle(0);

    garyStyle->SetTitleFont(132,"XYZ");
    garyStyle->SetTitleSize(0.05,"XYZ");

    garyStyle->SetTitleOffset(1.0,"XYZ");

    // 6 sub-pads
    //garyStyle->SetTitleOffset(1.6,"Y");

    //----------  Stats
    garyStyle->SetOptStat(0);
    garyStyle->SetOptFit(0);

    //----------  Legend
    garyStyle->SetLegendBorderSize(0);
    //garyStyle->SetLegendFont(132);

    gROOT->SetStyle("garyStyle");
    gROOT->ForceStyle();

}

// ------------------------------------------------------------------------------------------------
