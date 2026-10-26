#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

void spessore_alluminio(){
int const N=18;

float t[]={20,20,20,20,20,20,20,20,20,20,20,20,30,30,30,50,100,160}; // [s]
float Err_t[N];

float spessore[]={0.1,0.25,0.35,0.50,0.60,0.75,0.85,1,1.10,1.25,1.35,1.50,1.60,1.75,2,2.50,3,3.50}; //[mm]
float Err_spessore[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

float conteggi[]={5840,1771,958,652,536,435,291,277,206,169,131,124,153,137,119,105,132,156};
float Err_conteggi[N];

float rate[N];
float Err_rate[N];

for(int i=0;i<N;i++){
Err_t[i]=0.001; //[s]
Err_conteggi[i]=sqrt(conteggi[i]);

rate[i]=conteggi[i]/t[i];
Err_rate[i]=sqrt(pow(Err_conteggi[i]/conteggi[i],2)+pow(Err_t[i]/t[i],2))*rate[i];
}

float log_rate[N];
float Err_log_rate[N];

for(int i=0;i<N;i++){
    log_rate[i]=log(rate[i]);
    Err_log_rate[i]=(1/rate[i])*Err_rate[i];

    //trasformo in cm
    spessore[i]=spessore[i]*0.1;
    Err_spessore[i]=Err_spessore[i]*0.1;

}

TCanvas *c1= new TCanvas("c1", "cps(s)", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(N, spessore,rate,Err_spessore,Err_rate);
gr1->SetTitle("#it{cps(s)}");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{s}[cm]");
gr1->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr1->Draw("AP");


TF1 *fit_3 = new TF1("fit_3", "[0]*exp(-x*[1])",0, 0.4); 
fit_3->SetParameter(0,10000);
fit_3->SetParameter(1,10);
//fit_3->SetParNames("a","b");
fit_3->SetLineColor(8);
fit_3->SetLineWidth(2);
gr1->Fit("fit_3","RM+");
gr1->Draw("AP");

TCanvas *c2= new TCanvas("c2", "cps(s)", 200,30,1200,800);
c2->SetGrid();
c2->cd();

TGraphErrors *gr2= new TGraphErrors(N, spessore,log_rate,Err_spessore,Err_log_rate);
gr2->SetTitle("#it{cps}(s)");
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(0.8);
gr2->GetXaxis()->SetTitle("#it{s}[cm]");
gr2->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr2->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "[0]*x+[1]",0, 0.045); 
fit_1->SetParameter(0,6);
fit_1->SetParameter(1,-10);
//fit_1->SetParNames("a","b");
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gr2->Fit("fit_1","RM+");
gr2->Draw("AP");

TF1 *fit_2 = new TF1("fit_2", "[0]*x+[1]",0.190, 0.37); 
fit_2->SetParameter(0,6);
fit_2->SetParameter(1,-10);
//fit_2->SetParNames("a","b");
fit_2->SetLineColor(9);
fit_2->SetLineWidth(2);
gr2->Fit("fit_2","RM+");
gr2->Draw("AP");
// to do: fit alluminio, presa dati piombo, fit piombo, fit logaritmico per verificare linearita'


}
