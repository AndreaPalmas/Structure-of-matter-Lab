#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>
#include<TColor.h>

using namespace std;

void Campo_B(){
    const int nX = 9; // colonne
    const int nY = 9; // righe
    
    // Esempio di matrice (può essere un array 2D o una TMatrixD)
    double B[nX][nY]={
    {198.2,223.1,224.5,224.4,225.4,224.3,223.1,214.1,192.3},
    {217.22,249.50,249.98,250.35,249.88,249.95,250.06,242.99,209.87},
    {236.39,255.03,255.69,254.60,254.42,255.10,254.94,244.91,238.30},
    {235.41,254.41,255.10,254.66,254.45,254.41,254.56,248.25,223.76},
    {231.30,253.35,254.12,253.66,252.95,253.10,252.97,247.96,237.11},
    {226.78,252.76,253.68,253.35,253.16,253.20,253.17,247.36,221.14},
    {232.4,253.5,254,253.6,253.5,253.4,253.0,247.9,226.4},
    {226.3,250.0,252.5,251.9,252.8,252.8,252.2,247.4,226.2},
    {192.3,221.7,226.1,222.2,222.1,223,221.3,218,197.1}
    };
    

    // 2. Creiamo l'istogramma TH2F
    // TH2F("nome", "titolo", n_bin_x, x_min, x_max, n_bin_y, y_min, y_max)
    TH2F *h2 = new TH2F("h2", "#it{B(x,y)};#it{x}[mm];#it{y}[mm];#it{B}[mT]", 
                        nX, -2.5, 40 +2.5, nY, -2.5, 40+2.5);
                        
    int const Number = 3;
    double Red[Number]    = { 0.11, 0.00, 0.00};
    double Green[Number]  = { 0.56, 0.80, 1.00};
    double Blue[Number]   = { 1.00, 0.80, 0.50};
    double Length[Number] = { 0.00, 0.50, 1.00 };
    int nb=42;
    TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);

    // 3. Trasferiamo i dati dalla matrice all'istogramma
    for(int i=0; i<nX; i++) {
        for(int j=0; j<nY; j++) {
            // Nota: i bin di ROOT partono da 1, la matrice da 0
            h2->SetBinContent(i + 1, j + 1, B[i][j]);
        }
    }

    // 4. Disegniamo in 3D
    TCanvas *c1 = new TCanvas("c1", "Matrix 3D", 1000, 600);
    h2->SetContour(nb);
    c1->SetRightMargin(0.16);
    gStyle->SetOptStat(0);
    //gStyle->SetPalette(kViridis); // Colori moderni
    
    // Opzioni 3D consigliate per matrici:
    //"LEGO2" -> Istogramma a colonne 3D colorate
    // "SURF1" -> Superficie continua colorata
    // "COLZ" -> HeatMap 2D
    h2->Draw("COLZ");
    //h2->Draw("CONT1 SAME");
}
