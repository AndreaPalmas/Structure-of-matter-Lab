#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void Diffrazione(){

    float const hc=1240.0*pow(10,-9); // [ev*m]
    float const pi = 3.1415;

/////////////////////////////////////////////////

// GRAFICO RATE ANGOLI INTERI
float t=20;
float Err_t=0.001;

int const M=25;

float teta_2_interi[]={11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
float Err_2teta_interi[M];

float conteggi_interi[]={75,68,71,56,64,83,113,81,86,80,85,105,100,112,98,97,150,181,121,138,909,130,117,121,104};
float Err_conteggi_interi[M];

float teta_interi[M];
float Err_teta_interi[M];

float rate_interi[M];
float Err_rate_interi[M];

for(int i=0;i<16;i++){ //metto fino a 15 perchè le prime 15 erano state prese gurdando la risoluzione di 1 grado mentre dopo si è passati ad 1/6 di grado
    Err_2teta_interi[i]=0.3; // valore indicativo: abbiamo guardato la scala grande di risoluzione 1 grado

    teta_interi[i]=teta_2_interi[i]*0.5;
    Err_teta_interi[i]=Err_2teta_interi[i]*0.5;

    Err_conteggi_interi[i]=sqrtf(conteggi_interi[i]);

    rate_interi[i]=conteggi_interi[i]/t;
    Err_rate_interi[i]= sqrtf(pow(Err_conteggi_interi[i]/conteggi_interi[i],2)+pow(Err_t/t,2))*rate_interi[i];
}

for(int i=16;i<M;i++){ //metto fino a 15 perchè le prime 15 erano state prese gurdando la risoluzione di 1 grado mentre dopo si è passati ad 1/6 di grado
    Err_2teta_interi[i]=0.166667; // valore indicativo: abbiamo guardato la scala grande di risoluzione 1 grado

    teta_interi[i]=teta_2_interi[i]*0.5;
    Err_teta_interi[i]=Err_2teta_interi[i]*0.5;

    Err_conteggi_interi[i]=sqrtf(conteggi_interi[i]);

    rate_interi[i]=conteggi_interi[i]/t;
    Err_rate_interi[i]= sqrtf(pow(Err_conteggi_interi[i]/conteggi_interi[i],2)+pow(Err_t/t,2))*rate_interi[i];
}


TCanvas *c2= new TCanvas("c2", "cps(teta)", 200,30,1200,800);
c2->SetGrid();
c2->cd();

TGraphErrors *gr2= new TGraphErrors(M, teta_interi,rate_interi,Err_teta_interi,Err_rate_interi);
gr2->SetTitle("#it{cps(#theta) NaCl}");
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(0.8);
gr2->GetXaxis()->SetTitle("#it{theta}[#circ]");
gr2->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr2->Draw("AP");

///////////////////////////////////////////////////////////////////////////////////////

// GRAFCICO DI TUTTI GLI ANGOLI
int const N=55;

float teta_2[]={11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,26.17,26.33,26.50,26.67,26.83,27.17,27.33,27.50,27.67,27.83,28,28.17,28.33,28.50,28.67,28.83,29,29.17,29.33,29.50,29.67,29.83,30,30.17,30.33,30.50,30.67,30.83,31,31.17,31.33,31.50,31.67,31.83,32,33,34,35};
float Err_2teta[N];

float conteggi[]={75,68,71,56,64,83,113,81,86,80,85,105,100,112,98,97,88,103,104,96,109,150,199,236,295,322,223,181,143,121,109,109,118,121,121,111,112,119,133,138,351,557,688,967,1057,909,673,372,211,120,117,130,117,121,104};
float Err_conteggi[N];

float teta[N];
float Err_teta[N];

float rate[N];
float Err_rate[N];


for(int i=0;i<N;i++){
    if(i<16){
        Err_2teta[i]=0.3; // valore indicativo: abbiamo guardato la scala grande di risoluzione 1 grado
    }else{
        Err_2teta[i]= 0.166667; // circa 1/6 di grado;
    }

    teta[i]=teta_2[i]*0.5;
    Err_teta[i]=Err_2teta[i]*0.5;

    Err_conteggi[i]=sqrtf(conteggi[i]);

    rate[i]=conteggi[i]/t;
    Err_rate[i]= sqrtf(pow(Err_conteggi[i]/conteggi[i],2)+pow(Err_t/t,2))*rate[i];
}


TCanvas *c1= new TCanvas("c1", "cps(teta)", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(N, teta,rate,Err_teta,Err_rate);
gr1->SetTitle("#it{cps(#theta) NaCl}");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{#theta}[#circ]");
gr1->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr1->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "gaus",13.5, 14.3); 
fit_1->SetParameter(0,17);
fit_1->SetParameter(1,13.8);
fit_1->SetParameter(2,0.2);
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gr1->Fit("fit_1","RM+");
gr1->Draw("AP");

TF1 *fit_2 = new TF1("fit_2", "gaus",15, 15.95); 
fit_2->SetParameter(0,55);
fit_2->SetParameter(1,15.5);
fit_2->SetParameter(2,0.2);
fit_2->SetLineColor(9);
fit_2->SetLineWidth(2);
gr1->Fit("fit_2","RM+");
gr1->Draw("AP");

///////////////////////////////////////////////////////////////////////////

// Calcolo lambda

float lambda_alfa;
float Err_lambda_alfa;

float lambda_beta;
float Err_lambda_beta;

float E_alfa;
float Err_E_alfa;

float E_beta;
float Err_E_beta;

float d_2= 0.564*pow(10,-9); //m
float Err_2_d=0.002*pow(10,-9);//m

float beta_media= fit_1->GetParameter(1)*pi/180;
float beta_sigma= fit_1->GetParameter(2)*pi/180;

float alfa_media= fit_2->GetParameter(1)*pi/180;
float alfa_sigma= fit_2->GetParameter(2)*pi/180;


lambda_alfa= (d_2*sin(alfa_media))/1.0;
Err_lambda_alfa=sqrt(pow(sin(alfa_media)*Err_2_d,2)+pow(d_2*cos(alfa_media)*alfa_sigma,2));

lambda_beta= (d_2*sin(beta_media))/1.0;
Err_lambda_beta=sqrt(pow(sin(beta_media)*Err_2_d,2)+pow(d_2*cos(beta_media)*beta_sigma,2));

E_alfa=hc/lambda_alfa;
Err_E_alfa=(hc/pow(lambda_alfa,2))*Err_lambda_alfa;

E_beta=hc/lambda_beta;
Err_E_beta=(hc/pow(lambda_beta,2))*Err_lambda_beta;

cout<<"\nLambda alfa: \t"<<lambda_alfa<<"+-"<<Err_lambda_alfa<<endl;
cout<<"Lambda beta: \t"<<lambda_beta<<"+-"<<Err_lambda_beta<<endl;


cout<<"\nE alfa: \t"<<E_alfa<<"+-"<<Err_E_alfa<<endl;
cout<<"E beta: \t"<<E_beta<<"+-"<<Err_E_beta<<endl;

float Z_alfa= ((0.1545*pow(10,-9))-(lambda_alfa))/Err_lambda_alfa; 
float Z_beta= ((0.1392*pow(10,-9))-(lambda_beta))/Err_lambda_beta; 
cout<<"\nZ alfa = "<<Z_alfa<<endl;
cout<<"Z beta = "<< Z_beta<<endl;

float Z_Ealfa= ((8.032*pow(10,3))-(E_alfa))/Err_E_alfa; 
float Z_Ebeta= ((8.9*pow(10,3))-(E_beta))/Err_E_beta; 
cout<<"\nZ E alfa = "<<Z_Ealfa<<endl;
cout<<"Z E beta = "<< Z_Ebeta<<endl;

}

