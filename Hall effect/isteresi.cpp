#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void isteresi(){

int const N_1=81;
int const N_2=41;

float B_1[]= {
    421.1, 408.6, 397.4, 382.3, 366.1, 349.6, 331.8, 310.9, 293.5, 270.0,
    247.0, 228.6, 206.9, 185.5, 163.2, 134.7, 109.8, 86.8, 60.7, 36.4,
    9.4, -16.9, -41.4, -67.7, -91.5, -116.0, -142.8, -163.6, -189.4, -209.2,
    -232.9, -252.1, -277.2, -294.4, -317.6, -337.0, -354.4, -372.6, -388.6, -405.1,
    -418.6, -409.7, -396.4, -382.2, -365.8, -350.3, -331.8, -311.0, -290.3, -270.1,
    -246.8, -227.0, -207.6, -183.0, -160.4, -136.6, -112.1, -86.1, -59.4, -34.4,
    -8.9, 19.6, 44.6, 65.5, 92.6, 116.5, 140, 163.8, 187.7, 211.3,
    232.8, 255.6, 276.0, 298.0, 315.3, 335.6, 353.6, 374.5, 390.0, 406.1,
    417.2 
}; //primo ciclo

float I_1[]={2.008,1.897,1.798,1.692,1.595,1.500,1.400,1.299,1.208,1.096,0.994,0.898,0.800,0.704,
    0.613,0.498,0.401,0.315,0.204,0.106,0,-0.102,-0.205,-0.305,-0.400,-0.506,-0.608,-0.699,-0.810,
    -0.900,-1.007,-1.097,-1.214,-1.296,-1.404,-1.506,-1.598,-1.696,-1.794,-1.899,-1.991,-1.902,
    -1.799,-1.694,-1.592,-1.502,-1.406,-1.297,-1.196,-1.100,-0.989,-0.898,-0.810,-0.703,-0.605,
    -0.507,-0.411,-0.307,-0.202,-0.101,0,0.109,0.207,0.299,0.408,0.505,0.600,0.696,0.798,0.905,
    1.003,1.104,1.201,1.302,1.393,1.494,1.590,1.706,1.799,1.902,1.978}; //primo ciclo

    float B_2[]= {
    417.2, 397.1, 368.5, 329.2, 291.6, 249.7, 206.3, 161.8, 108.1, 56.2,
    9.0, -43.9, -93, -137.4, -188, -233, -279.1, -316, -356.5, -389.7,
    -415.9, -395.9, -367, -331.8, -292.9, -247.8, -202.8, -160.7, -109.5, -59.3,
    -8.8, 45, 88.3, 137.4, 191.6, 233.7, 275.4, 317.6, 352.7, 390.9,
    415.7
};//secondo ciclo

float I_2[]={1.978,1.808,1.607,1.388,1.204,1.001,
    0.802,0.610,0.395,0.188,0,-0.202,-0.410,-0.592,-0.798,-1.004,-1.221,-1.399,-1.609,-1.801,-1.973,
    -1.799,-1.601,-1.404,-1.208,-0.994,-0.789,-0.606,-0.402,-0.202,0,0.212,0.392,0.590,0.806,1.008,
    1.201,1.391,1.584,1.805,1.969};//secondo ciclo

float Err_B_1[N_1];
float Err_I_1[N_1];

float Err_B_2[N_2];
float Err_I_2[N_2];


for(int i=0;i<N_1;i++){
   Err_B_1[i]=0.1*10+abs(0.05*B_1[i]);
    Err_I_1[i]=0.001*10+abs(0.015*I_1[i]);
}

for(int i=0;i<N_2;i++){
   Err_B_2[i]=0.1*10+abs(0.05*B_2[i]);
    Err_I_2[i]=0.001*10+abs(0.015*I_2[i]);
}



//////////////////////////////////////////
int const N_1_A=41;

float I_1_A[]={2.008,1.897,1.798,1.692,1.595,1.500,1.400,1.299,1.208,1.096,0.994,0.898,0.800,0.704,
    0.613,0.498,0.401,0.315,0.204,0.106,0,-0.102,-0.205,-0.305,-0.400,-0.506,-0.608,-0.699,-0.810,
    -0.900,-1.007,-1.097,-1.214,-1.296,-1.404,-1.506,-1.598,-1.696,-1.794,-1.899,-1.991}; //prima discesa

float B_1_A[]={ 421.1, 408.6, 397.4, 382.3, 366.1, 349.6, 331.8, 310.9, 293.5, 270.0,
    247.0, 228.6, 206.9, 185.5, 163.2, 134.7, 109.8, 86.8, 60.7, 36.4,
    9.4, -16.9, -41.4, -67.7, -91.5, -116.0, -142.8, -163.6, -189.4, -209.2,
    -232.9, -252.1, -277.2, -294.4, -317.6, -337.0, -354.4, -372.6, -388.6, -405.1,
    -418.6}; //prima discesa


int const N_1_B=41;

float I_1_B[]={-1.991,-1.902,
    -1.799,-1.694,-1.592,-1.502,-1.406,-1.297,-1.196,-1.100,-0.989,-0.898,-0.810,-0.703,-0.605,
    -0.507,-0.411,-0.307,-0.202,-0.101,0,0.109,0.207,0.299,0.408,0.505,0.600,0.696,0.798,0.905,
    1.003,1.104,1.201,1.302,1.393,1.494,1.590,1.706,1.799,1.902,1.978}; //prima salita

float B_1_B[]={-418.6, -409.7, -396.4, -382.2, -365.8, -350.3, -331.8, -311.0, -290.3, -270.1,
    -246.8, -227.0, -207.6, -183.0, -160.4, -136.6, -112.1, -86.1, -59.4, -34.4,
    -8.9, 19.6, 44.6, 65.5, 92.6, 116.5, 140, 163.8, 187.7, 211.3,
    232.8, 255.6, 276.0, 298.0, 315.3, 335.6, 353.6, 374.5, 390.0, 406.1,
    417.2,}; //prima salita

//////////////////////////////////////////////////////

int const N_2_A=21;

float I_2_A[]={1.978,1.808,1.607,1.388,1.204,1.001,
    0.802,0.610,0.395,0.188,0,-0.202,-0.410,-0.592,-0.798,-1.004,-1.221,-1.399,-1.609,-1.801,-1.973,}; //seconda discesa

float B_2_A[]={ 417.2, 397.1, 368.5, 329.2, 291.6, 249.7, 206.3, 161.8, 108.1, 56.2,
    9.0, -43.9, -93, -137.4, -188, -233, -279.1, -316, -356.5, -389.7,
    -415.9 };//seconda discesa


int const N_2_B=21;

float I_2_B[]={-1.973,
    -1.799,-1.601,-1.404,-1.208,-0.994,-0.789,-0.606,-0.402,-0.202,0,0.212,0.392,0.590,0.806,1.008,
    1.201,1.391,1.584,1.805,1.969}; //seconda salita

float B_2_B[]={-415.9, -395.9, -367, -331.8, -292.9, -247.8, -202.8, -160.7, -109.5, -59.3,
    -8.8, 45, 88.3, 137.4, 191.6, 233.7, 275.4, 317.6, 352.7, 390.9,
    415.7}; //seconda salita

///////////////////////////////////////////////////////

float Err_I_1_A[N_1_A];
float Err_B_1_A[N_1_A];
float Err_I_1_B[N_1_B];
float Err_B_1_B[N_1_B];

float Err_I_2_A[N_2_A];
float Err_B_2_A[N_2_A];
float Err_I_2_B[N_2_B];
float Err_B_2_B[N_2_B];


for(int i=0;i<N_1_A;i++){
    Err_B_1_A[i]=0.1*10+abs(0.05*B_1_A[i]);
    Err_I_1_A[i]=0.001*10+abs(0.015*I_1_A[i]);
}

for(int i=0;i<N_1_B;i++){
    Err_B_1_B[i]=0.1*10+abs(0.05*B_1_B[i]);
    Err_I_1_B[i]=0.001*10+abs(0.015*I_1_B[i]);
}

for(int i=0;i<N_2_A;i++){
    Err_B_2_A[i]=0.1*10+abs(0.05*B_2_A[i]);
    Err_I_2_A[i]=0.001*10+abs(0.015*I_2_A[i]);
}

for(int i=0;i<N_2_B;i++){
    Err_B_2_B[i]=0.1*10+abs(0.05*B_2_B[i]);
    Err_I_2_B[i]=0.001*10+abs(0.015*I_2_B[i]);
}

////////////////////////////////////////////////////////////

TCanvas *c1= new TCanvas("c1", "B(I_{M}) 1", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(N_1,I_1,B_1,Err_I_1,Err_B_1);
gr1->SetTitle("#it{B(I_{M})} primo ciclo");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr1->GetYaxis()->SetTitle("#it{B}[mT]");
gr1->Draw("AP");

TCanvas *c2= new TCanvas("c2", "B(I) 2", 200,30,1200,800);
c2->SetGrid();
c2->cd();

TGraphErrors *gr2= new TGraphErrors(N_2,I_2,B_2,Err_I_2,Err_B_2);
gr2->SetTitle("#it{B(I_{M})} secondo ciclo");
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(0.8);
gr2->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr2->GetYaxis()->SetTitle("#it{B}[mT]");
gr2->Draw("AP");

///////////////////////////////////////


TF1 *fit = new TF1("fit", "[0]*x+[1]",-1.5, 1.5); 
fit->SetParameter(0,200);
fit->SetParameter(1,0);
fit->SetLineColor(8);
fit->SetLineWidth(2);

TF1 *fitB = new TF1("fitB", "[0]*x+[1]",-1.5, 1.5); 
fitB->SetParameter(0,200);
fitB->SetParameter(1,0);
fitB->SetLineColor(9);
fitB->SetLineWidth(2);


TCanvas *c3= new TCanvas("c3", "B(I) 1", 200,30,1200,800);
c3->SetGrid();
c3->cd();

TMultiGraph *mg1= new TMultiGraph();

TGraphErrors *gr1A= new TGraphErrors(N_1_A,I_1_A,B_1_A,Err_I_1_A,Err_B_1_A);
gr1A->SetTitle("#it{B(I_{M})} prima discesa");
gr1A->SetMarkerStyle(8);
gr1A->SetMarkerSize(0.8);
gr1A->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr1A->GetYaxis()->SetTitle("#it{B}[mT]");
gr1A->Draw("AP");

TGraphErrors *gr1B= new TGraphErrors(N_1_B,I_1_B,B_1_B,Err_I_1_B,Err_B_1_B);
gr1B->SetTitle("#it{B(I_{M})} prima salita");
gr1B->SetMarkerStyle(8);
gr1B->SetMarkerSize(0.8);
gr1B->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr1B->GetYaxis()->SetTitle("#it{B}[mT]");
gr1B->Draw("AP");

mg1->Add(gr1A,"P");
mg1->Add(gr1B,"P");
mg1->SetTitle("#it{B(I_{M})} primo ciclo");
mg1->GetXaxis()->SetTitle("#it{I_{M}}[A]");
mg1->GetYaxis()->SetTitle("#it{B}[mT]");
mg1->Draw("A");

gr1A->Fit("fit","R");
float a_1_A= fit->GetParameter(0);
float b_1_A= fit->GetParameter(1);
float Err_a_1_A= fit->GetParError(0);
float Err_b_1_A= fit->GetParError(1);
gr1B->Fit("fitB","R");
float a_1_B= fitB->GetParameter(0);
float b_1_B= fitB->GetParameter(1);
float Err_a_1_B= fitB->GetParError(0);
float Err_b_1_B= fitB->GetParError(1);

auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Legenda","C"); // option "C" allows to center the header
   legend->AddEntry(fit,"Linearit#grave{a} della discesa","l");
   legend->AddEntry(fitB,"Linearit#grave{a} della salita","l");
   legend->Draw();


////////////////////////////////////////////////////////////


TCanvas *c4= new TCanvas("c4", "B(I) 1", 200,30,1200,800);
c4->SetGrid();
c4->cd();

TMultiGraph *mg2= new TMultiGraph();

TGraphErrors *gr2A= new TGraphErrors(N_2_A,I_2_A,B_2_A,Err_I_2_A,Err_B_2_A);
gr2A->SetTitle("#it{B(I_{M})} seconda discesa");
gr2A->SetMarkerStyle(8);
gr2A->SetMarkerSize(0.8);
gr2A->GetXaxis()->SetTitle("it{I_{M}}[A]");
gr2A->GetYaxis()->SetTitle("#it{B}[mT]");
gr2A->Draw("AP");

TGraphErrors *gr2B= new TGraphErrors(N_2_B,I_2_B,B_2_B,Err_I_2_B,Err_B_2_B);
gr2B->SetTitle("#it{B(I_{M})} seconda salita");
gr2B->SetMarkerStyle(8);
gr2B->SetMarkerSize(0.8);
gr2B->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr2B->GetYaxis()->SetTitle("#it{B}[mT]");
gr2B->Draw("AP");


mg2->Add(gr2A,"P");
mg2->Add(gr2B,"P");
mg2->SetTitle("#it{B(I_{M})} secondo ciclo");
mg2->GetXaxis()->SetTitle("#it{I_{M}}[A]");
mg2->GetYaxis()->SetTitle("#it{B}[mT]");
mg2->Draw("A");

gr2A->Fit("fit","R");
float a_2_A= fit->GetParameter(0);
float b_2_A= fit->GetParameter(1);
float Err_a_2_A= fit->GetParError(0);
float Err_b_2_A= fit->GetParError(1);
gr2B->Fit("fitB","R");
float a_2_B= fitB->GetParameter(0);
float b_2_B= fitB->GetParameter(1);
float Err_a_2_B= fitB->GetParError(0);

float Err_b_2_B= fitB->GetParError(1);

auto legend1 = new TLegend(0.1,0.7,0.48,0.9);
   legend1->SetHeader("Legenda","C"); // option "C" allows to center the header
   legend1->AddEntry(fit,"Linearit#grave{a} della discesa","l");
   legend1->AddEntry(fitB,"Linearit#grave{a} della salita","l");
   legend1->Draw();



/*TF1 *fit = new TF1("fit", "[0]*x+[1]",-1.5, 1.5); 
fit->SetParameter(0,200);
fit->SetParameter(1,0);
fit->SetLineColor(8);
fit->SetLineWidth(2);

TF1 *fitB = new TF1("fitB", "[0]*x+[1]",-1.5, 1.5); 
fitB->SetParameter(0,200);
fitB->SetParameter(1,0);
fitB->SetLineColor(9);
fitB->SetLineWidth(2);


gr1A->Fit("fit","R");
float a_1_A= fit->GetParameter(0);
float b_1_A= fit->GetParameter(1);
float Err_a_1_A= fit->GetParError(0);
float Err_b_1_A= fit->GetParError(1);
gr1B->Fit("fitB","R");
float a_1_B= fitB->GetParameter(0);
float b_1_B= fitB->GetParameter(1);
float Err_a_1_B= fitB->GetParError(0);
float Err_b_1_B= fitB->GetParError(1);
gr2A->Fit("fit","R");
float a_2_A= fit->GetParameter(0);
float b_2_A= fit->GetParameter(1);
float Err_a_2_A= fit->GetParError(0);
float Err_b_2_A= fit->GetParError(1);
gr2B->Fit("fitB","R");
float a_2_B= fitB->GetParameter(0);
float b_2_B= fitB->GetParameter(1);
float Err_a_2_B= fitB->GetParError(0);
float Err_b_2_B= fitB->GetParError(1);

auto legend = new TLegend(0.1,0.7,0.48,0.9);
   legend->SetHeader("Legenda","C"); // option "C" allows to center the header
   legend->AddEntry("fit","Linearita' della discesa","l");
   legend->AddEntry("fitB","Linearita' della salita","l");
   legend->Draw(); */


///////////////////////////////////////////////////////////////////////

cout << endl << "--- RISULTATI DEI FIT ---" << endl;
cout << left << setw(8) << "Graph" << " | " << "Valore +/- Errore (a)" << " | " << "Valore +/- Errore (b)" << endl;
cout << string(70, '-') << endl;

// Imposto la precisione a 4 decimali per tutti i numeri che seguono
cout << fixed << setprecision(4);

// Stampa gr1A
cout << setw(8) << "gr1A" << " | " << a_1_A << " +/- " << Err_a_1_A << " | " << b_1_A << " +/- " << Err_b_1_A << endl;

// Stampa gr1B
cout << setw(8) << "gr1B" << " | " << a_1_B << " +/- " << Err_a_1_B << " | " << b_1_B << " +/- " << Err_b_1_B << endl;

// Stampa gr2A
cout << setw(8) << "gr2A" << " | " << a_2_A << " +/- " << Err_a_2_A << " | " << b_2_A << " +/- " << Err_b_2_A << endl;

// Stampa gr2B
cout << setw(8) << "gr2B" << " | " << a_2_B << " +/- " << Err_a_2_B << " | " << b_2_B << " +/- " << Err_b_2_B << endl;

cout << string(70, '-') << endl;


///////////////////////////////////////////////////////////////////////////


// --- MEDIA GRUPPO A (1A + 2A) ---
float a_mean_A = (a_1_A + a_2_A) / 2.0;
float b_mean_A = (b_1_A + b_2_A) / 2.0;
// Errore della media (propagazione: 1/2 * sqrt(err1^2 + err2^2))
float Err_a_mean_A = 0.5 * sqrt(Err_a_1_A*Err_a_1_A + Err_a_2_A*Err_a_2_A);
float Err_b_mean_A = 0.5 * sqrt(Err_b_1_A*Err_b_1_A + Err_b_2_A*Err_b_2_A);

// --- MEDIA GRUPPO B (1B + 2B) ---
float a_mean_B = (a_1_B + a_2_B) / 2.0;
float b_mean_B = (b_1_B + b_2_B) / 2.0;
float Err_a_mean_B = 0.5 * sqrt(Err_a_1_B*Err_a_1_B + Err_a_2_B*Err_a_2_B);
float Err_b_mean_B = 0.5 * sqrt(Err_b_1_B*Err_b_1_B + Err_b_2_B*Err_b_2_B);

// --- STAMPA ---
cout << "\n--- MEDIE ---" << endl;
cout << "MEDIA A: a = " << a_mean_A << " +/- " << Err_a_mean_A << endl;
cout << "         b = " << b_mean_A << " +/- " << Err_b_mean_A << endl;
cout << "MEDIA B: a = " << a_mean_B << " +/- " << Err_a_mean_B << endl;
cout << "         b = " << b_mean_B << " +/- " << Err_b_mean_B << endl;

/////////////////////////////////////////////////////////

float media_a = (a_mean_A + a_mean_B)/2.0;
float Err_media_a =sqrt(Err_a_mean_A*Err_a_mean_A + Err_a_mean_B*Err_a_mean_B);
float media_b = (b_mean_A + b_mean_B)/2.0;
float Err_media_b=abs((b_mean_A - b_mean_B)/2.0);



TCanvas *c5= new TCanvas("c5", "B(I_{M}) 1", 200,30,1200,800);
c5->SetGrid();
c5->cd();

TGraphErrors *gr5= new TGraphErrors(N_1,I_1,B_1,Err_I_1,Err_B_1);
gr5->SetTitle("#it{B(I_{M})} primo ciclo");
gr5->SetMarkerStyle(8);
gr5->SetMarkerSize(0.8);
gr5->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr5->GetYaxis()->SetTitle("#it{B}[mT]");
gr5->Draw("AP");

TF1 *fm = new TF1("fm", "pol1", -1.5, 1.5);
fm->SetParameters(1, 241.8);
fm->SetParameter(0, 0); 
fm->SetLineColor(8); 
fm->SetLineWidth(2);
fm->Draw("SAME");

TCanvas *c6= new TCanvas("c6", "B(I) 2", 200,30,1200,800);
c6->SetGrid();
c6->cd();

TGraphErrors *gr6= new TGraphErrors(N_2,I_2,B_2,Err_I_2,Err_B_2);
gr6->SetTitle("#it{B(I_{M})} secondo ciclo");
gr6->SetMarkerStyle(8);
gr6->SetMarkerSize(0.8);
gr6->GetXaxis()->SetTitle("#it{I_{M}}[A]");
gr6->GetYaxis()->SetTitle("#it{B}[mT]");
gr6->Draw("AP");

TF1 *fm1 = new TF1("fm1", "pol1", -1.5, 1.5);
fm1->SetParameter(1, 241.8);
fm1->SetParameter(0, 0);
fm1->SetLineColor(8); 
fm1->SetLineWidth(2);
fm1->Draw("SAME");
///////////////////////////////////////

// --- STAMPA RISULTATI FINALI (MEDIA DELLE MEDIE) ---

cout << endl << string(50, '=') << endl;
cout << "          RISULTATI FINALI COMPLESSIVI" << endl;
cout << string(50, '=') << endl;

// Imposto la precisione (es. 5 decimali, vedi tu quanti te ne servono)
cout << fixed << setprecision(5);

cout << left << setw(15) << "Parametro" << " | " << "Valore +/- Errore" << endl;
cout << string(50, '-') << endl;

// Stampa per la Media a
cout << left << setw(15) << "MEDIA a" << " | " 
     << media_a << " +/- " << Err_media_a << endl;

// Stampa per la Media b
cout << left << setw(15) << "MEDIA b" << " | " 
     << media_b << " +/- " << Err_media_b << endl;

cout << string(50, '=') << endl;


}
