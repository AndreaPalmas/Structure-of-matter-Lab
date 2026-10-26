#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void Hall(){
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

TCanvas *c1= new TCanvas("c1", "Rumore", 1800, 700);
c1->SetGrid();
c1->cd();


TGraphErrors *gr1= new TGraphErrors(N, I,VH,Err_I,Err_VH);
gr1->SetTitle("#it{V_{H}(I_{C})}, B=0");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr1->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
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

int const M=10;

float I_magnete[]={0.205,0.4,0.701,1.004,1.306,-0.205,-0.401,-0.707,-1.004,-1.307};
float Err_I_magnete[M];

// Retta isteresi per avere B(I)
float a= 241.89546 ;
float Err_a= 3.59138;
float b=0.12652 ;
float Err_b= 8.69114;

float B[M];
float Err_B[M];

for(int i=0;i<M;i++){

    Err_I_magnete[i]=0.001*10+0.015*I_magnete[i];

    B[i]=a*I_magnete[i]+b; // B in mT
    Err_B[i]=sqrt(pow(Err_b,2)+pow(I_magnete[i]*Err_a,2)+pow(a*Err_I_magnete[i],2));
}

////////////////////////////////////////////////////////////////////////////////

// B positivo
// --- BLOCCO 1 (Magnete 0.205 A) ---
const int n1 = 17;
float I1[] = {-8.001, -7.000, -6.000, -5.000, -4.003, -3.001, -2.005, -0.999, 0.000, 1.009, 2.008, 3.002, 4.003, 5.004, 6.007, 7.002, 8.001};
float V1[] = {2.587, 2.261, 1.937, 1.612, 1.289, 0.964, 0.641, 0.314, -0.010, -0.339, -0.663, -0.986, -1.312, -1.637, -1.963, -2.286, -2.611};

// --- BLOCCO 2 (Magnete 0.4 A) ---
const int n2 = 17;
float I2[] = {-8.007, -7.008, -6.000, -5.007, -4.005, -3.004, -2.009, -1.007, 0.000, 1.000, 2.004, 3.002, 4.006, 5.002, 6.005, 7.008, 8.002};
float V2[] = {4.822, 4.219, 3.612, 3.012, 2.408, 1.803, 1.203, 0.598, -0.010, -0.615, -1.222, -1.823, -2.430, -3.030, -3.635, -4.241, -4.842};

// --- BLOCCO 3 (Magnete 0.701 A) ---
const int n3 = 17;
float I3[] = {-8.005, -6.999, -6.009, -5.004, -4.004, -3.009, -2.001, -1.006, 0.000, 1.006, 2.000, 3.006, 4.003, 5.006, 6.004, 7.001, 8.002};
float V3[] = {8.522, 7.449, 6.395, 5.325, 4.260, 3.197, 2.126, 1.064, -0.008, -1.083, -2.144, -3.215, -4.279, -5.347, -6.411, -7.473, -8.541};

// --- BLOCCO 4 (Magnete 1.004 A) ---
const int n4 = 17;
float I4[] = {-8.004, -7.000, -6.008, -5.000, -4.004, -3.006, -2.005, -1.006, 0.000, 1.008, 2.004, 3.006, 4.004, 5.003, 6.008, 7.004, 8.005};
float V4[] = {12.043, 10.532, 9.041, 7.725, 6.028, 4.527, 3.022, 1.517, 0.001, -1.520, -3.020, -4.528, -6.031, -7.534, -9.048, -10.545, -12.057};

// --- BLOCCO 5 (Magnete 1.306 A) ---
const int n5 = 17;
float I5[] = {-8.005, -7.007, -6.008, -5.005, -4.002, -3.008, -2.003, -1.002, 0.000, 1.007, 2.004, 3.006, 4.004, 5.003, 6.004, 7.003, 8.005};
float V5[] = {15.644, 13.694, 11.744, 9.784, 7.826, 5.884, 3.921, 1.965, 0.004, -1.967, -3.917, -5.874, -7.823, -9.773, -11.730, -13.680, -15.637};

// B negativo

// --- BLOCCO 6 (Magnete -0.205 A) ---
const int n6 = 17;
float I6[] = {-7.999, -7.003, -6.008, -5.003, -3.999, -3.007, -2.000, -1.003, 0.000, 0.999, 2.001, 3.004, 4.008, 5.007, 6.005, 7.004, 7.999};
float V6[] = {-2.329, -2.040, -1.752, -1.460, -1.169, -0.882, -0.590, -0.301, -0.010, 0.280, 0.570, 0.860, 1.152, 1.440, 1.730, 2.018, 2.307};

// --- BLOCCO 7 (Magnete -0.401 A) ---
const int n7 = 17;
float I7[] = {-7.998, -7.001, -6.000, -5.001, -4.007, -3.008, -2.005, -1.006, 0.000, 1.003, 2.007, 3.003, 4.003, 5.008, 6.006, 7.000, 8.002};
float V7[] = {-4.740, -4.150, -3.558, -2.968, -2.380, -1.789, -1.196, -0.605, -0.010, 0.584, 1.178, 1.766, 2.357, 2.951, 3.540, 4.128, 4.720};

// --- BLOCCO 8 (Magnete -0.707 A) ---
const int n8 = 17;
float I8[] = {-8.007, -7.002, -6.006, -5.007, -4.006, -3.004, -2.002, -1.005, 0.000, 1.009, 2.003, 2.999, 4.005, 5.007, 5.999, 7.002, 8.001};
float V8[] = {-8.693, -7.604, -6.526, -5.441, -4.357, -3.268, -2.181, -1.098, -0.005, 1.094, 2.176, 3.258, 4.353, 5.442, 6.523, 7.614, 8.704};

// --- BLOCCO 9 (Magnete -1.004 A) ---
const int n9 = 17;
float I9[] = {-8.005, -7.004, -6.001, -5.000, -4.009, -3.005, -2.003, -1.006, 0.000, 1.008, 2.004, 3.003, 4.002, 5.001, 6.005, 7.009, 8.007};
float V9[] = {-12.081, -10.568, -9.056, -7.547, -6.053, -4.537, -3.026, -1.521, -0.003, 1.523, 3.026, 4.533, 6.041, 7.547, 9.062, 10.575, 12.080};

// --- BLOCCO 10 (Magnete -1.307 A) ---
const int n10 = 17;
float I10[] = {-8.007, -7.005, -6.009, -5.003, -4.004, -3.008, -2.004, -1.005, 0.000, 1.004, 2.002, 3.003, 4.003, 5.002, 6.002, 7.002, 8.002};
float V10[] = {-15.529, -13.585, -11.653, -9.698, -7.762, -5.828, -3.882, -1.943, 0.009, 1.966, 3.906, 5.850, 7.794, 9.733, 11.677, 13.620, 15.573};


// Blocchi per errori Corrente (Err_I) e Tensione (Err_V)
float Err_I1[17], Err_V1[17], Err_I2[17], Err_V2[17], Err_I3[17], Err_V3[17], Err_I4[17], Err_V4[17], Err_I5[17], Err_V5[17];
float Err_I6[17], Err_V6[17], Err_I7[17], Err_V7[17], Err_I8[17], Err_V8[17], Err_I9[17], Err_V9[17], Err_I10[17], Err_V10[17];

// Ciclo di calcolo per i primi 5 blocchi (B positivo)
for(int i=0; i<17; i++) {
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
}

// Ciclo di calcolo per i blocchi 6-10 (B negativo)
for(int i=0; i<17; i++) {
    // Blocco 6
    Err_I6[i] = 0.001 * 10 + 0.015 * abs(I6[i]);
    Err_V6[i] = (0.000030 * abs(V6[i])) + (0.000035 * range);
    // Blocco 7
    Err_I7[i] = 0.001 * 10 + 0.015 * abs(I7[i]);
    Err_V7[i] = (0.000030 * abs(V7[i])) + (0.000035 * range);
    // Blocco 8
    Err_I8[i] = 0.001 * 10 + 0.015 * abs(I8[i]);
    Err_V8[i] = (0.000030 * abs(V8[i])) + (0.000035 * range);
    // Blocco 9
    Err_I9[i] = 0.001 * 10 + 0.015 * abs(I9[i]);
    Err_V9[i] = (0.000030 * abs(V9[i])) + (0.000035 * range);
    // Blocco 10
    Err_I10[i] = 0.001 * 10 + 0.015 * abs(I10[i]);
    Err_V10[i] = (0.000030 * abs(V10[i])) + (0.000035 * range);
}

// Dichiarazione dei vettori corretti
float V1_c[17], V2_c[17], V3_c[17], V4_c[17], V5_c[17], V6_c[17], V7_c[17], V8_c[17], V9_c[17], V10_c[17];
float Err_V1_c[17], Err_V2_c[17], Err_V3_c[17], Err_V4_c[17], Err_V5_c[17], Err_V6_c[17], Err_V7_c[17], Err_V8_c[17], Err_V9_c[17], Err_V10_c[17];

// Loop di correzione
for(int i=0; i<17; i++) {
    // Blocco 1
    V1_c[i] = V1[i] - (rumore_a * I1[i] + rumore_b);
    Err_V1_c[i] = sqrt(pow(Err_V1[i],2) + pow(I1[i]*Err_rumore_a,2) + pow(rumore_a*Err_I1[i],2) + pow(Err_rumore_b,2));

    // Blocco 2
    V2_c[i] = V2[i] - (rumore_a * I2[i] + rumore_b);
    Err_V2_c[i] = sqrt(pow(Err_V2[i],2) + pow(I2[i]*Err_rumore_a,2) + pow(rumore_a*Err_I2[i],2) + pow(Err_rumore_b,2));

    // Blocco 3
    V3_c[i] = V3[i] - (rumore_a * I3[i] + rumore_b);
    Err_V3_c[i] = sqrt(pow(Err_V3[i],2) + pow(I3[i]*Err_rumore_a,2) + pow(rumore_a*Err_I3[i],2) + pow(Err_rumore_b,2));

    // Blocco 4
    V4_c[i] = V4[i] - (rumore_a * I4[i] + rumore_b);
    Err_V4_c[i] = sqrt(pow(Err_V4[i],2) + pow(I4[i]*Err_rumore_a,2) + pow(rumore_a*Err_I4[i],2) + pow(Err_rumore_b,2));

    // Blocco 5
    V5_c[i] = V5[i] - (rumore_a * I5[i] + rumore_b);
    Err_V5_c[i] = sqrt(pow(Err_V5[i],2) + pow(I5[i]*Err_rumore_a,2) + pow(rumore_a*Err_I5[i],2) + pow(Err_rumore_b,2));

    // Blocco 6
    V6_c[i] = V6[i] - (rumore_a * I6[i] + rumore_b);
    Err_V6_c[i] = sqrt(pow(Err_V6[i],2) + pow(I6[i]*Err_rumore_a,2) + pow(rumore_a*Err_I6[i],2) + pow(Err_rumore_b,2));

    // Blocco 7
    V7_c[i] = V7[i] - (rumore_a * I7[i] + rumore_b);
    Err_V7_c[i] = sqrt(pow(Err_V7[i],2) + pow(I7[i]*Err_rumore_a,2) + pow(rumore_a*Err_I7[i],2) + pow(Err_rumore_b,2));

    // Blocco 8
    V8_c[i] = V8[i] - (rumore_a * I8[i] + rumore_b);
    Err_V8_c[i] = sqrt(pow(Err_V8[i],2) + pow(I8[i]*Err_rumore_a,2) + pow(rumore_a*Err_I8[i],2) + pow(Err_rumore_b,2));

    // Blocco 9
    V9_c[i] = V9[i] - (rumore_a * I9[i] + rumore_b);
    Err_V9_c[i] = sqrt(pow(Err_V9[i],2) + pow(I9[i]*Err_rumore_a,2) + pow(rumore_a*Err_I9[i],2) + pow(Err_rumore_b,2));

    // Blocco 10
    V10_c[i] = V10[i] - (rumore_a * I10[i] + rumore_b);
    Err_V10_c[i] = sqrt(pow(Err_V10[i],2) + pow(I10[i]*Err_rumore_a,2) + pow(rumore_a*Err_I10[i],2) + pow(Err_rumore_b,2));
}



TCanvas *c_all = new TCanvas("c_all", "Tutti i Grafici Hall", 1800, 700);
c_all->SetGrid();
c_all->Divide(5,2);
c_all->cd();

TGraphErrors* gr[10];

gr[0] = new TGraphErrors(17, I1, V1_c, Err_I1, Err_V1_c);
gr[0]->SetTitle("#it{V_{H}(I_{c})}, B=50 mT");
gr[0]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[0]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[1] = new TGraphErrors(17, I2, V2_c, Err_I2, Err_V2_c);
gr[1]->SetTitle("#it{V_{H}(I_{c})}, B=100 mT");
gr[1]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[1]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[2] = new TGraphErrors(17, I3, V3_c, Err_I3, Err_V3_c);
gr[2]->SetTitle("#it{V_{H}(I_{c})}, B=170 mT");
gr[2]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[2]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[3] = new TGraphErrors(17, I4, V4_c, Err_I4, Err_V4_c);
gr[3]->SetTitle("#it{V_{H}(I_{c})}, B=240 mT");
gr[3]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[3]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[4] = new TGraphErrors(17, I5, V5_c, Err_I5, Err_V5_c);
gr[4]->SetTitle("#it{V_{H}(I_{c})}, B=320 mT");
gr[4]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[4]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");

gr[5] = new TGraphErrors(17, I6, V6_c, Err_I6, Err_V6_c);
gr[5]->SetTitle("#it{V_{H}(I_{c})}, B=-50 mT");
gr[5]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[5]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[6] = new TGraphErrors(17, I7, V7_c, Err_I7, Err_V7_c);
gr[6]->SetTitle("#it{V_{H}(I_{c})}, B=-100 mT");
gr[6]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[6]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[7] = new TGraphErrors(17, I8, V8_c, Err_I8, Err_V8_c);
gr[7]->SetTitle("#it{V_{H}(I_{c})}, B=-170 mT");
gr[7]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[7]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[8] = new TGraphErrors(17, I9, V9_c, Err_I9, Err_V9_c);
gr[8]->SetTitle("#it{V_{H}(I_{c})}, B=-240 mT");
gr[8]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[8]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr[9] = new TGraphErrors(17, I10, V10_c, Err_I10, Err_V10_c);
gr[9]->SetTitle("#it{V_{H}(I_{c})}, B=-320 mT");
gr[9]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr[9]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");

//Fit 1/5
TF1 *fit_A = new TF1("fit_A", "[0]*x+[1]",-8.5, 8.5); 
fit_A->SetParameter(0,-1);
fit_A->SetParameter(1,0);
fit_A->SetParNames("a","b");
fit_A->SetLineColor(8);
fit_A->SetLineWidth(2);


//fit 6/10
TF1 *fit_B = new TF1("fit_B", "[0]*x+[1]",-8.5, 8.5); 
fit_B->SetParameter(0,1);
fit_B->SetParameter(1,0);
fit_B->SetParNames("a","b");
fit_B->SetLineColor(8);
fit_B->SetLineWidth(2);

float pendenze[10], err_pendenze[10];
float intercetta[10], err_intercetta[10];


for(int i=0;i<10;i++){
    c_all->cd(i+1);
    gPad->SetGrid();
    gr[i]->Fit(fit_A,"RQ");
    gr[i]->Draw("AP");
    
    pendenze[i] = fit_A->GetParameter(0);
    err_pendenze[i] = fit_A->GetParError(0);
    intercetta[i]=fit_A->GetParameter(1);
    err_intercetta[i]=fit_A->GetParError(1);

    printf("Blocco %2d | Pendenza: %.3f +/- %.3f | Campo B: %.2f  +- %.2f\n ", i+1, pendenze[i], err_pendenze[i], B[i], Err_B[i]);
   

}
for(int i=5;i<10;i++){
    c_all->cd(i+1);
    gPad->SetGrid();
    gr[i]->Fit(fit_B,"RQ");
    gr[i]->Draw("AP");
    
    pendenze[i] = fit_B->GetParameter(0);
    err_pendenze[i] = fit_B->GetParError(0);
    intercetta[i]=fit_B->GetParameter(1);
    err_intercetta[i]=fit_B->GetParError(1);

    printf("Blocco %2d | Pendenza: %.3f +/- %.3f | Campo B: %.2f  +- %.2f\n ", i+1, pendenze[i], err_pendenze[i], B[i], Err_B[i]);


}

/////////////////////////////////////////////////////////////////////////////////////////////

// Calcolo RH

float RH[10];
float Err_RH[10];

float const t= 0.001; // thickness = m


for(int i=0;i<10;i++){
    RH[i]= pendenze[i]*t/(B[i]/1000.0);
    Err_RH[i]=sqrt(pow(err_pendenze[i]/pendenze[i],2)+pow(Err_B[i]/B[i],2))*RH[i];

    printf("RH %d = %f +- %f\n", i+1, RH[i],Err_RH[i]);

}

float p[10];

for(int i=0;i<10;i++){
    p[i]=1/pow(Err_RH[i],2);
}

float num=0;
float den=0;

for(int i=0;i<5;i++){
num=num+ RH[i]*p[i];
den=den+p[i];
}

float media_1=num/den;
float Err_media_1=sqrt(1/den);

num=0;
den=0;

for(int i=5;i<10;i++){
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



// grafico in verticale
TCanvas *c_all_2 = new TCanvas("c_all_2", "Tutti i Grafici Hall", 300, 800);
c_all_2->SetGrid();
c_all_2->Divide(2,5);
c_all_2->cd();

TGraphErrors* gr_2[10];

gr_2[0] = new TGraphErrors(17, I1, V1_c, Err_I1, Err_V1_c);
gr_2[0]->SetTitle("#it{V_{H}(I_{c})}, B=50 mT");
gr_2[0]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[0]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[2] = new TGraphErrors(17, I2, V2_c, Err_I2, Err_V2_c);
gr_2[2]->SetTitle("#it{V_{H}(I_{c})}, B=100 mT");
gr_2[2]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[2]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[4] = new TGraphErrors(17, I3, V3_c, Err_I3, Err_V3_c);
gr_2[4]->SetTitle("#it{V_{H}(I_{c})}, B=170 mT");
gr_2[4]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[4]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[6] = new TGraphErrors(17, I4, V4_c, Err_I4, Err_V4_c);
gr_2[6]->SetTitle("#it{V_{H}(I_{c})}, B=240 mT");
gr_2[6]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[6]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[8] = new TGraphErrors(17, I5, V5_c, Err_I5, Err_V5_c);
gr_2[8]->SetTitle("#it{V_{H}(I_{c})}, B=320 mT");
gr_2[8]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[8]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");

gr_2[1] = new TGraphErrors(17, I6, V6_c, Err_I6, Err_V6_c);
gr_2[1]->SetTitle("#it{V_{H}(I_{c})}, B=-50 mT");
gr_2[1]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[1]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[3] = new TGraphErrors(17, I7, V7_c, Err_I7, Err_V7_c);
gr_2[3]->SetTitle("#it{V_{H}(I_{c})}, B=-100 mT");
gr_2[3]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[3]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[5] = new TGraphErrors(17, I8, V8_c, Err_I8, Err_V8_c);
gr_2[5]->SetTitle("#it{V_{H}(I_{c})}, B=-170 mT");
gr_2[5]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[5]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[7] = new TGraphErrors(17, I9, V9_c, Err_I9, Err_V9_c);
gr_2[7]->SetTitle("#it{V_{H}(I_{c})}, B=-240 mT");
gr_2[7]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[7]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");
gr_2[9] = new TGraphErrors(17, I10, V10_c, Err_I10, Err_V10_c);
gr_2[9]->SetTitle("#it{V_{H}(I_{c})}, B=-320 mT");
gr_2[9]->GetXaxis()->SetTitle("#it{I_{c}}[mA]");
gr_2[9]->GetYaxis()->SetTitle("#it{V_{H}}[mV]");


float pendenze_2[10], err_pendenze_2[10];
float intercetta_2[10], err_intercetta_2[10];

//Fit 1/5
TF1 *fit_A_2 = new TF1("fit_A_2", "[0]*x+[1]",-8.5, 8.5); 
fit_A_2->SetParameter(0,-1);
fit_A_2->SetParameter(1,0);
fit_A_2->SetParNames("a","b");
fit_A_2->SetLineColor(8);
fit_A_2->SetLineWidth(2);


//fit 6/10
TF1 *fit_B_2 = new TF1("fit_B_2", "[0]*x+[1]",-8.5, 8.5); 
fit_B_2->SetParameter(0,1);
fit_B_2->SetParameter(1,0);
fit_B_2->SetParNames("a","b");
fit_B_2->SetLineColor(8);
fit_B_2->SetLineWidth(2);


for(int i=0;i<10;i++){
    if(i%2==0 || i==0){
    c_all_2->cd(i+1);
    gPad->SetGrid();
    gr_2[i]->Fit(fit_A_2,"RQ");
    gr_2[i]->Draw("AP");
    pendenze_2[i] = fit_A_2->GetParameter(0);
    err_pendenze_2[i] = fit_A_2->GetParError(0);
    intercetta_2[i]=fit_A_2->GetParameter(1);
    err_intercetta_2[i]=fit_A_2->GetParError(1);

    //printf("Blocco %2d | Pendenza: %.3f +/- %.3f | Campo B: %.2f  +- %.2f\n ", i+1, pendenze_2[i], err_pendenze_2[i], B[i], Err_B[i]);
    }
    else{
    c_all_2->cd(i+1);
    gPad->SetGrid();
    gr_2[i]->Fit(fit_B_2,"RQ");
    gr_2[i]->Draw("AP");
    
    pendenze_2[i] = fit_B_2->GetParameter(0);
    err_pendenze_2[i] = fit_B_2->GetParError(0);
    intercetta_2[i]=fit_B_2->GetParameter(1);
    err_intercetta_2[i]=fit_B_2->GetParError(1);

    //printf("Blocco %2d | Pendenza: %.3f +/- %.3f | Campo B: %.2f  +- %.2f\n ", i+1, pendenze_2[i], err_pendenze_2[i], B[i], Err_B[i]);   


}


/*
 for(int i=5;i<10;i++){
    c_all->cd(i+1);
    gr[i]->Fit(fit_B,"RQ");
    
    pendenze[i] = fit_B->GetParameter(0);
    err_pendenze[i] = fit_B->GetParError(0);
    intercetta[i]=fit_A->GetParameter(1);
    err_intercetta[i]=fit_A->GetParError(1);

    printf("Blocco %2d | Pendenza: %.3f +/- %.3f | Campo B: %.2f  +- %.2f\n ", i+1, pendenze[i], err_pendenze[i], B[i], Err_B[i]);

    gr[i]->Draw("AP");


}
*/

}


}
