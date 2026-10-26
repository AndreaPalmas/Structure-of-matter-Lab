#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void DiffrazioneNi(){

    float const hc=1240.0*pow(10,-9); // [ev*m]
    float const pi = 3.1415;


float t=20;
float Err_t=0.001;

int const M=37;

float teta_2[M]={26,26.17,26.33,26.50,26.67,26.83,27,27.17,27.33,27.50,27.67,27.83,28,28.17,28.33,28.50,28.67,28.83,29,29.17,29.33,29.50,29.67,29.83,30,30.17,30.33,30.50,30.67,30.83,31,31.17,31.33,31.50,31.67,31.83,32};
float Err_2teta[M];
float conteggi[M]={22,22,21,36,32,32,28,25,42,47,43,49,28,35,37,37,35,33,34,50,31,42,48,66,184,302,456,613,702,584,487,375,218,115,48,53,44};

float teta[M];
float Err_teta[M];
float Err_conteggi[M];
float rate[M];
float Err_rate[M];


for(int i=0;i<M;i++){
    Err_2teta[i]=0.166; // valore indicativo: abbiamo guardato la scala grande di risoluzione 1 grado

    teta[i]=teta_2[i]*0.5;
    Err_teta[i]=Err_2teta[i]*0.5;

    Err_conteggi[i]=sqrtf(conteggi[i]);

    rate[i]=conteggi[i]/t;
    Err_rate[i]= sqrtf(pow(Err_conteggi[i]/conteggi[i],2)+pow(Err_t/t,2))*rate[i];
}



TCanvas *c1= new TCanvas("c1", "cps(teta)", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(M, teta,rate,Err_teta,Err_rate);
gr1->SetTitle("#it{cps(#theta)}");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{#theta}[#circ]");
gr1->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr1->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "gaus",14.8, 15.8); 
fit_1->SetParameter(0,35);
fit_1->SetParameter(1,14.4);
fit_1->SetParameter(2,0.2);
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gr1->Fit("fit_1","RM+");
gr1->Draw("AP");


///////////////////////////////////////////////////////////////////////////

// Calcolo lambda

float lambda_edge;
float Err_lambda_edge;


float E_edge;
float Err_E_edge;

float d_2= 0.564*pow(10,-9); //m
float Err_2_d=0.002*pow(10,-9);//m

float edge_media= fit_1->GetParameter(1)*pi/180;
float edge_sigma= fit_1->GetParameter(2)*pi/180;


lambda_edge= (d_2*sin(edge_media))/1.0;
Err_lambda_edge=sqrt(pow(sin(edge_media)*Err_2_d,2)+pow(d_2*cos(edge_media)*edge_sigma,2));


E_edge=hc/lambda_edge;
Err_E_edge=(hc/pow(lambda_edge,2))*Err_lambda_edge;


cout<<"\nLambda edge: \t"<<lambda_edge<<"+-"<<Err_lambda_edge<<endl;


cout<<"\nE edge: \t"<<E_edge<<"+-"<<Err_E_edge<<endl;

/*float Z_edge= ((0.1545*pow(10,-9))-(lambda_edge))/Err_lambda_edge;  
cout<<"\nZ edge = "<<Z_edge<<endl;*/

float Z_Eedge= ((8.33*pow(10,3))-(E_edge))/Err_E_edge; 
cout<<"\nZ E edge = "<<Z_Eedge<<endl;

}

