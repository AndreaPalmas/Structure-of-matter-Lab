#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void Hall_2(){

    int const N = 17;


// Corrente I (mA)
float I[] = {
    -8.004, -7.003, -6.004, -5.003, -4.008, -2.999, -1.999, -1.001, 
     0.000,  1.005,  2.007,  3.002,  4.005,  5.005,  6.001,  7.005,  8.004
};

// Tensione di Hall VH (mV)
float VH[] = {
    -0.054, -0.048, -0.042, -0.036, -0.029, -0.022, -0.016, -0.009, 
    -0.003,  0.002,  0.008,  0.014,  0.020,  0.026,  0.032,  0.037,  0.044
};

float Err_I[N];
float Err_VH[N];

int const range=100; //mV

for(int i=0;i<N;i++){
    Err_I[i]= 0.001*10+0.015*I[i];
    Err_VH[i]=(0.000030*VH[i])+(0.000035*range);
}

TGraphErrors *gr1= new TGraphErrors(N, I,VH,Err_I,Err_VH);
gr1->SetTitle("VH(I) Rumore");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("I[mA]");
gr1->GetYaxis()->SetTitle("VH[mV]");
gr1->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "[0]*x+[1]",-8.5, 8.5); 
fit_1->SetParameter(0,0.04);
fit_1->SetParameter(1,0);
fit_1->SetParNames("a","b");
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gStyle->SetOptFit(1);
gr1->Fit("fit_1","R");
gr1->Draw("AP");

float rumore_a= fit_1->GetParameter(0);
float rumore_b= fit_1->GetParameter(1);

float Err_rumore_a=  fit_1->GetParError(0);
float Err_rumore_b= fit_1->GetParError(1);

/////////////////////////////////////////////////////////////////////////

int const M=6;

float I_germanio[]={8.004,5.000,2.001,-8.007,-5.001,-2.003}; //mA
float Err_I_germanio[M];

for(int i=0;i<M;i++){
    Err_I_germanio[i]=5*0.001+0.005*I_germanio[i];
}

/////////////////////////////////////////////////////////////////////////////

// --- BLOCCO 1 (I_campione = 8.004 mA) ---
const int n1 = 11;
float I1[] = {-1.306, -1.005, -0.703, -0.404, -0.204, 0.000, 0.207, 0.408, 0.700, 1.006, 1.302};
float V1[] = {15.560, 12.658, 9.119, 5.532, 2.709, 0.440, -2.191, -4.956, -8.302, -12.017, -15.450};

// --- BLOCCO 2 (I_campione = 5.000 mA) ---
const int n2 = 11;
float I2[] = {-1.303, -1.007, -0.699, -0.400, -0.200, 0.000, 0.208, 0.403, 0.703, 1.006, 1.300};
float V2[] = {9.654, 7.568, 5.235, 2.977, 1.527, -0.208, -1.784, -3.357, -5.680, -7.830, -9.564};

// --- BLOCCO 3 (I_campione = 2.001 mA) ---
const int n3 = 11;
float I3[] = {-1.302, -1.007, -0.704, -0.399, -0.204, 0.000, 0.206, 0.400, 0.704, 0.996, 1.302};
float V3[] = {3.885, 3.173, 2.322, 1.381, 0.774, 0.130, -0.568, -1.126, -2.071, -2.946, -3.824};

// --- BLOCCO 4 (I_campione = -8.007 mA) ---
const int n4 = 11;
float I4[] = {-1.306, -1.009, -0.710, -0.401, -0.201, 0.000, 0.206, 0.406, 0.702, 1.005, 1.302};
float V4[] = {-15.480, -12.022, -8.527, -4.678, -2.348, 0.416, 2.976, 5.547, 9.132, 12.640, 15.507};

// --- BLOCCO 5 (I_campione = -5.001 mA) ---
const int n5 = 11;
float I5[] = {-1.305, -1.006, -0.700, -0.404, -0.209, 0.000, 0.200, 0.404, 0.700, 1.000, 1.300};
float V5[] = {-9.656, -7.845, -5.507, -3.393, -1.869, -0.218, 1.391, 2.982, 5.238, 7.494, 9.624};

// --- BLOCCO 6 (I_campione = -2.003 mA) ---
const int n6 = 11;
float I6[] = {-1.304, -1.006, -0.701, -0.409, -0.205, 0.000, 0.209, 0.406, 0.700, 1.006, 1.301};
float V6[] = {-3.823, -2.971, -2.056, -1.171, -0.522, 0.127, 0.793, 1.410, 2.297, 3.171, 3.887};


// Blocchi per errori Corrente (Err_I) e Tensione (Err_V)
float Err_I1[11], Err_V1[11], Err_I2[11], Err_V2[11], Err_I3[11], Err_V3[11], Err_I4[11], Err_V4[11], Err_I5[11], Err_V5[11], Err_I6[11], Err_V6[11];

// Ciclo di calcolo per i primi 5 blocchi (B positivo)
for(int i=0; i<11; i++) {
    // Blocco 1
    Err_I1[i] = 0.001 * 10 + 0.015 * abs(I1[i]);
    Err_V1[i] = (0.000030 * abs(V1[i])) + (0.000035 * range);
    // Blocco 2
    Err_I2[i] = 0.001 * 10 + 0.015 * abs(I2[i]);
    Err_V2[i] = (0.000030 * abs(V2[i])) + (0.000035 * range);
    // Blocco 3
    Err_I3[i] = 0.001 * 10 + 0.015 * abs(I3[i]);
    Err_V3[i] = (0.000030 * abs(V3[i])) + (0.000035 * range);
    // Blocco 4
    Err_I4[i] = 0.001 * 10 + 0.015 * abs(I4[i]);
    Err_V4[i] = (0.000030 * abs(V4[i])) + (0.000035 * range);
    // Blocco 5
    Err_I5[i] = 0.001 * 10 + 0.015 * abs(I5[i]);
    Err_V5[i] = (0.000030 * abs(V5[i])) + (0.000035 * range);
    // Blocco 6
    Err_I6[i] = 0.001 * 10 + 0.015 * abs(I6[i]);
    Err_V6[i] = (0.000030 * abs(V6[i])) + (0.000035 * range);
}


// Dichiarazione dei vettori corretti
float V1_c[11], V2_c[11], V3_c[11], V4_c[11], V5_c[11], V6_c[11];
float Err_V1_c[11], Err_V2_c[11], Err_V3_c[11], Err_V4_c[11], Err_V5_c[11], Err_V6_c[11];


for(int i=0; i<11; i++) {
    // Blocco 1
    V1_c[i] = V1[i] - (rumore_a * I_germanio[0] + rumore_b);
    Err_V1_c[i] = sqrt(pow(Err_V1[i],2) + pow(I_germanio[0]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[0],2) + pow(Err_rumore_b,2));

    // Blocco 2
    V2_c[i] = V2[i] - (rumore_a * I_germanio[1] + rumore_b);
    Err_V2_c[i] = sqrt(pow(Err_V2[i],2) + pow(I_germanio[1]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[1],2) + pow(Err_rumore_b,2));

    // Blocco 3
    V3_c[i] = V3[i] - (rumore_a * I_germanio[2] + rumore_b);
    Err_V3_c[i] = sqrt(pow(Err_V3[i],2) + pow(I_germanio[2]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[2],2) + pow(Err_rumore_b,2));

    // Blocco 4
    V4_c[i] = V4[i] - (rumore_a * I_germanio[3] + rumore_b);
    Err_V4_c[i] = sqrt(pow(Err_V4[i],2) + pow(I_germanio[3]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[3],2) + pow(Err_rumore_b,2));

    // Blocco 5
    V5_c[i] = V5[i] - (rumore_a * I_germanio[4] + rumore_b);
    Err_V5_c[i] = sqrt(pow(Err_V5[i],2) + pow(I_germanio[4]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[4],2) + pow(Err_rumore_b,2));

    // Blocco 6
    V6_c[i] = V6[i] - (rumore_a * I_germanio[5] + rumore_b);
    Err_V6_c[i] = sqrt(pow(Err_V6[i],2) + pow(I_germanio[5]*Err_rumore_a,2) + pow(rumore_a*Err_I_germanio[5],2) + pow(Err_rumore_b,2));

}


//Calcolo campi B


float B_1[11],B_2[11],B_3[11],B_4[11],B_5[11],B_6[11];
float Err_B_1[11],Err_B_2[11],Err_B_3[11],Err_B_4[11],Err_B_5[11],Err_B_6[11];


// Retta isteresi per avere B(I)
float a= 241.89546 ;
float Err_a= 3.59138;
float b=0.12652 ;
float Err_b= 8.69114;


for(int i=0;i<11;i++){
B_1[i]=a*I1[i]+b;
B_2[i]=a*I2[i]+b;
B_3[i]=a*I3[i]+b;
B_4[i]=a*I4[i]+b;
B_5[i]=a*I5[i]+b;
B_6[i]=a*I6[i]+b;

Err_B_1[i]=sqrt(pow(Err_b,2)+pow(I1[i]*Err_a,2)+pow(a*Err_I1[i],2));
Err_B_2[i]=sqrt(pow(Err_b,2)+pow(I2[i]*Err_a,2)+pow(a*Err_I2[i],2));
Err_B_3[i]=sqrt(pow(Err_b,2)+pow(I3[i]*Err_a,2)+pow(a*Err_I3[i],2));
Err_B_4[i]=sqrt(pow(Err_b,2)+pow(I4[i]*Err_a,2)+pow(a*Err_I4[i],2));
Err_B_5[i]=sqrt(pow(Err_b,2)+pow(I5[i]*Err_a,2)+pow(a*Err_I5[i],2));
Err_B_6[i]=sqrt(pow(Err_b,2)+pow(I6[i]*Err_a,2)+pow(a*Err_I6[i],2));

}

TCanvas *c_all = new TCanvas("c_all", "Tutti i Grafici Hall", 1800, 700);
c_all->Divide(3, 2);

TGraphErrors* gr[6];

// Inizializzazione
gr[0] = new TGraphErrors(11, B_1, V1_c, Err_B_1, Err_V1_c);
gr[0]->SetTitle("#it{V_{H}(B)}, I_{c}=8.004 mA");
gr[0]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[0]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[1] = new TGraphErrors(11, B_2, V2_c, Err_B_2, Err_V2_c);
gr[1]->SetTitle("#it{V_{H}(B)}, I_{c}=5.000 mA");
gr[1]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[1]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[2] = new TGraphErrors(11, B_3, V3_c, Err_B_3, Err_V3_c);
gr[2]->SetTitle("#it{V_{H}(B)}, I_{c}=2.001 mA");
gr[2]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[2]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[3] = new TGraphErrors(11, B_4, V4_c, Err_B_4, Err_V4_c);
gr[3]->SetTitle("#it{V_{H}(B)}, I_{c}=-8.007 mA");
gr[3]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[3]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[4] = new TGraphErrors(11, B_5, V5_c, Err_B_5, Err_V5_c);
gr[4]->SetTitle("#it{V_{H}(B)}, I_{c}=-5.001 mA");
gr[4]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[4]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[5] = new TGraphErrors(11, B_6, V6_c, Err_B_6, Err_V6_c);
gr[5]->SetTitle("#it{V_{H}(B)}, I_{c}=-2.003 mA");
gr[5]->GetXaxis()->SetTitle("#it{B}[mT]");
gr[5]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");

//Fit 1/3
TF1 *fit_A = new TF1("fit_A", "[0]*x+[1]",-700, 700); 
fit_A->SetParameter(0,-100);
fit_A->SetParameter(1,0);
fit_A->SetParNames("a","b");
fit_A->SetLineColor(8);
fit_A->SetLineWidth(2);


//fit 4/6
TF1 *fit_B = new TF1("fit_B", "[0]*x+[1]",-700, 700); 
fit_B->SetParameter(0,100);
fit_B->SetParameter(1,0);
fit_B->SetParNames("a","b");
fit_B->SetLineColor(8);
fit_B->SetLineWidth(2);



float pendenze[6], err_pendenze[6];
float intercetta[6], err_intercetta[6];


for(int i=0;i<3;i++){
    c_all->cd(i+1);
    gPad->SetGrid();
    gr[i]->SetMarkerSize(0.8);
    gr[i]->Fit(fit_A,"RQ");
    gr[i]->Draw("AP");
    pendenze[i] = fit_A->GetParameter(0);
    err_pendenze[i] = fit_A->GetParError(0);
    intercetta[i]=fit_A->GetParameter(1);
    err_intercetta[i]=fit_A->GetParError(1);

    printf("Blocco %2d | Pendenza: %.3f +/- %.3f \n ", i+1, pendenze[i], err_pendenze[i]);

}
for(int i=3;i<6;i++){
    c_all->cd(i+1);
    gPad->SetGrid();
    gr[i]->Fit(fit_B,"RQ");
    
    pendenze[i] = fit_B->GetParameter(0);
    err_pendenze[i] = fit_B->GetParError(0);
    intercetta[i]=fit_A->GetParameter(1);
    err_intercetta[i]=fit_A->GetParError(1);

    printf("Blocco %2d | Pendenza: %.3f +/- %.3f\n ", i+1, pendenze[i], err_pendenze[i]);

    gr[i]->Draw("AP");


}


///////////////////////////////////////////////////////////

// Calcolo RH

float RH[6];
float Err_RH[6];

float const t=0.001; //m


for(int i=0;i<6;i++){
RH[i]=pendenze[i]*(t)/(I_germanio[i]/1000.0);
Err_RH[i]=sqrt(pow(err_pendenze[i]/pendenze[i],2)+pow(Err_I_germanio[i]/I_germanio[i],2))*RH[i];

printf("RH %d = %f +- %f\n", i+1, RH[i],Err_RH[i]);

}

/////////////////////////////////////////////////
float p[6];

for(int i=0;i<6;i++){
    p[i]=1/pow(Err_RH[i],2);
}

float num=0;
float den=0;

for(int i=0;i<3;i++){
num=num+ RH[i]*p[i];
den=den+p[i];
}

float media_1=num/den;
float Err_media_1=sqrt(1/den);

num=0;
den=0;

for(int i=3;i<6;i++){
num=num+ RH[i]*p[i];
den=den+p[i];
}

float media_2=num/den;
float Err_media_2=sqrt(1/den);

float media_finale= ((media_1/pow(Err_media_1,2))+(media_2/pow(Err_media_2,2)))/((1/pow(Err_media_1,2))+(1/pow(Err_media_2,2)));
float Err_media_finale=1/sqrt(1/(pow(Err_media_1,2))+1/(pow(Err_media_1,2)));

cout<< "Media B positivo:"<<media_1<<"+-"<<Err_media_1<<endl<<"Media B negativo: "<< media_2<<"+-"<<Err_media_2<<endl;

cout<< "Z = "<<(media_1-media_2)/sqrt(pow(Err_media_1,2)+pow(Err_media_2,2))<<endl;

cout<<"\nMedia finale ="<<media_finale<<"+-"<<Err_media_finale<<endl;;



/////////////////////////////////////////////////////////

// COnfronto con RH di Hall 1


float media_RH1=-0.0062;
float Err_media_RH1=0.0001;

cout<<"\nZ fra RH1 e RH2 = "<<(media_finale-media_RH1)/(sqrt(pow(Err_media_finale,2)+pow(Err_media_RH1,2)))<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

// media finale è la stima di RH per I costante!!!!

float const e= 1.602*pow(10,-19);

float concentrazione_1 = 1.0/(e*media_finale);
float Err_concentrazione_1 = (Err_media_finale/media_finale)*concentrazione_1;

float concentrazione_2 = 1.0/(e*media_RH1);
float Err_concentrazione_2 = (Err_media_RH1/media_RH1)*concentrazione_2;


cout<< "\nConcentrazione 1 = "<<concentrazione_1<<"+-"<<Err_concentrazione_1<<"\nConcentrazione 2 = "<<concentrazione_2<<"+-"<<Err_concentrazione_2<<endl; 

cout<<"\nZ fra Concentrazione 1 e concentrazione 2 = "<<(concentrazione_1-concentrazione_2)/(sqrt(pow(Err_concentrazione_1,2)+pow(Err_concentrazione_2,2)))<<endl;



}
