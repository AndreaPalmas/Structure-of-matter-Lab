#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void Cristalli(){

    float const hc=1240.0*pow(10,-9); // [ev*m]
    float const pi = 3.1415;


float t=20;
float Err_t=0.001;

int const M_K=17;
int const M_R=19;
int const M_L=20;

float teta_2_K[M_K]={26,26.17,26.33,26.50,26.67,26.83,27,27.17,27.33,27.50,27.67,27.83,28,28.17,28.33,28.50,28.67};
float conteggi_K[M_K]={30,24,35,53,115,189,320,432,520,497,397,313,151,89,47,45,26};

float teta_2_R[M_R]={24,24.17,24.33,24.50,24.67,24.83,25,25.17,25.33,25.50,25.67,25.83,26,26.17,26.33,26.50,26.67,26.83,27};
float conteggi_R[M_R]={58,82,131,181,403,702,875,1196,1339,1541,1551,1531,1170,717,274,104,70,65,68};

float teta_2_L[M_L]={43,43.17,43.33,43.50,43.67,43.83,44,44.17,44.33,44.50,44.67,44.83,45,45.17,45.33,45.50,45.67,45.83,46,46.17};
float conteggi_L[M_L]={44,34,37,29,50,56,69,82,99,118,163,157,120,92,76,60,54,40,46,34};

float Err_2_teta_K[M_K];
float Err_2_teta_R[M_R];
float Err_2_teta_L[M_L];

float teta_K[M_K];
float Err_teta_K[M_K];
float Err_conteggi_K[M_K];
float rate_K[M_K];
float Err_rate_K[M_K];

float teta_R[M_R];
float Err_teta_R[M_R];
float Err_conteggi_R[M_R];
float rate_R[M_R];
float Err_rate_R[M_R];

float teta_L[M_L];
float Err_teta_L[M_L];
float Err_conteggi_L[M_L];
float rate_L[M_L];
float Err_rate_L[M_L];

for(int i=0;i<M_K;i++){
    Err_2_teta_K[i]=0.166; // valore indicativo: abbiamo guardato la scala grande di risoluzione 1 grado
    
    teta_K[i]=teta_2_K[i]*0.5;
    Err_teta_K[i]=Err_2_teta_K[i]*0.5;

    Err_conteggi_K[i]=sqrtf(conteggi_K[i]);

    rate_K[i]=conteggi_K[i]/t;
    Err_rate_K[i]= sqrtf(pow(Err_conteggi_K[i]/conteggi_K[i],2)+pow(Err_t/t,2))*rate_K[i];
    
}
for(int i=0;i<M_R;i++){
    Err_2_teta_R[i]=0.166;

    teta_R[i]=teta_2_R[i]*0.5;
    Err_teta_R[i]=Err_2_teta_R[i]*0.5;

    Err_conteggi_R[i]=sqrtf(conteggi_R[i]);

    rate_R[i]=conteggi_R[i]/t;
    Err_rate_R[i]= sqrtf(pow(Err_conteggi_R[i]/conteggi_R[i],2)+pow(Err_t/t,2))*rate_R[i];
}

for(int i=0;i<M_L;i++){
    Err_2_teta_L[i]=0.166;

    teta_L[i]=teta_2_L[i]*0.5;
    Err_teta_L[i]=Err_2_teta_L[i]*0.5;

    Err_conteggi_L[i]=sqrtf(conteggi_L[i]);

    rate_L[i]=conteggi_L[i]/t;
    Err_rate_L[i]= sqrtf(pow(Err_conteggi_L[i]/conteggi_L[i],2)+pow(Err_t/t,2))*rate_L[i];

}


TCanvas *c1= new TCanvas("c1", "cps_K(teta)", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(M_K, teta_K,rate_K,Err_teta_K,Err_rate_K);
gr1->SetTitle("#it{cps(#theta) - KCl}");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{#theta}[#circ]");
gr1->GetYaxis()->SetTitle("cps[# s^{-1}]");
gr1->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "gaus",13.2, 14.2); 
fit_1->SetParameter(0,35);
fit_1->SetParameter(1,14.4);
fit_1->SetParameter(2,0.2);
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gr1->Fit("fit_1","RM+");
gr1->Draw("AP");


TCanvas *c2= new TCanvas("c2", "cps_R(teta)", 200,30,1200,800);
c2->SetGrid();
c2->cd();

TGraphErrors *gr2= new TGraphErrors(M_R, teta_R,rate_R,Err_teta_R,Err_rate_R);
gr2->SetTitle("#it{cps(#theta) - RbCl}");
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(0.8);
gr2->GetXaxis()->SetTitle("#it{#theta}[#circ]");
gr2->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr2->Draw("AP");

TF1 *fit_2 = new TF1("fit_2", "gaus",12.2, 13.3); 
fit_2->SetParameter(0,80);
fit_2->SetParameter(1,12.8);
fit_2->SetParameter(2,0.2);
fit_2->SetLineColor(8);
fit_2->SetLineWidth(2);
gr2->Fit("fit_2","RM+");
gr2->Draw("AP");


TCanvas *c3= new TCanvas("3", "cps_L(teta)", 200,30,1200,800);
c3->SetGrid();
c3->cd();

TGraphErrors *gr3= new TGraphErrors(M_L, teta_L,rate_L,Err_teta_L,Err_rate_L);
gr3->SetTitle("#it{cps(#theta) - LiF}");
gr3->SetMarkerStyle(8);
gr3->SetMarkerSize(0.8);
gr3->GetXaxis()->SetTitle("#it{#theta}[#circ]");
gr3->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr3->Draw("AP");

TF1 *fit_3 = new TF1("fit_3", "[3]+gaus",21.8, 22.9); 
fit_3->SetParameter(0,9);
fit_3->SetParameter(1,22.4);
fit_3->SetParameter(2,0.2);
fit_3->SetLineColor(8);
fit_3->SetLineWidth(2);
gr3->Fit("fit_3","RM+");
gr3->Draw("AP");



///////////////////////////////////////////////////////////////////////////

// Calcolo lambda

float lambda= 0.154 * pow(10,-9); //m

float d_K;
float d_R;
float d_L;

float Err_d_K;
float Err_d_R;
float Err_d_L;

float media_K= fit_1->GetParameter(1)*pi/180;
float sigma_K= fit_1->GetParameter(2)*pi/180;

float media_R= fit_2->GetParameter(1)*pi/180;
float sigma_R= fit_2->GetParameter(2)*pi/180;

float media_L= fit_3->GetParameter(1)*pi/180;
float sigma_L= fit_3->GetParameter(2)*pi/180;

cout << "theta K:" << media_K << "+-" << sigma_K << "rad" << endl;
cout << "theta R:" << media_R << "+-" << sigma_R << "rad" << endl;
cout << "theta L:" << media_L << "+-" << sigma_L << "rad" << endl;


d_K= lambda/(2*sin(media_K));
d_R= lambda/(2*sin(media_R));
d_L= lambda/(2*sin(media_L));

Err_d_K=(lambda*cos(media_K)*sigma_K)/(2*pow(sin(media_K),2));
Err_d_R=(lambda*cos(media_R)*sigma_R)/(2*pow(sin(media_R),2));
Err_d_L=(lambda*cos(media_L)*sigma_L)/(2*pow(sin(media_L),2));

cout<<"\nd_K = "<<d_K<<"+-"<<Err_d_K<<endl;
cout<<"d_R = "<<d_R<<"+-"<<Err_d_R<<endl;
cout<<"d_L = "<<d_L<<"+-"<<Err_d_L<<endl;

}

