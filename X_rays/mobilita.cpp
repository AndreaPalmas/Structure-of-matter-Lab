#include<iostream>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>


using namespace std;

void mobilita(){

int N = 17;

float I[] = {8.003, 7.006, 6.008, 5.009, 4.004, 3.004, 2.002, 1.008, 0, -1.000, -2.000, -3.009, -4.002, -5.003, -6.000, -7.007, -8.006}; //mA
float ErrI[N];
float VH[] = {0.32602, 0.28544, 0.24487, 0.20418, 0.16330, 0.12261, 0.081917, 0.041328, 0.000001, -0.040703, -0.081365, -0.12233, -0.16275, -0.20348, -0.24407, -0.28500, -0.32570}; //V
float ErrVH[N];

for(int i=0; i < N; i++){
I[i] = I[i] * pow(10, -3);
}


for(int i=0; i<N; i++){
ErrI[i] = (0.5/100)*I[i]+5*0.000001;
if((i<6)or(i>10))
	ErrVH[i] = 0.0025*VH[i] + 0.0006*0.000001;
else
	ErrVH[i] = 0.0030*VH[i] + 0.0035*0.0000001;
}


for(int i=0; i<17; i++){
cout << VH[i] << " +- " << ErrVH[i] << endl;
} 

TCanvas *cgf= new TCanvas("cgf", "Mobilità",200,30,1200,800);
cgf->SetFillColor(0);
cgf->SetGrid();
cgf->cd();

TGraphErrors *cgg= new TGraphErrors(N, I, VH, ErrI, ErrVH);
cgg->SetTitle("#it{VH(I)}");
cgg->SetMarkerStyle(8);
cgg->SetMarkerSize(0.8);
cgg->GetXaxis()->SetTitle("#it{I} [A]");
cgg->GetYaxis()->SetTitle("#it{VH} [V]");


/*
TF1 *fit = new TF1("fit", "[0]*x+[1]",800, 1300); 
fit->SetParameter(0,0.005);
fit->SetParameter(1,1091);
fit->SetLineColor(8);
fit->SetLineWidth(2);
cgf->Fit("fit","RM+"); 

cgg->Draw("AP");

TFitResultPtr fitresults=cgf->Fit(fit,"MS");
cout<<endl<<"Chi^2"<<fit->GetChisquare()<<endl;  */

TF1* f2 = new TF1("f2", "[0]*x + [1]", -8.01, 8.01); 
f2->SetParameter(0, 0.05);
f2->SetParameter(1, 0);
f2->SetParNames("a", "b");
f2->SetNpx(5000);
f2->SetLineColor(8);

gStyle->SetOptFit(1);

cgg->Fit(f2);
cgg->Draw("AP");

float R = f2 -> GetParameter(0);
float ErrR = f2 -> GetParError(0);

float sigma = (20/10)*pow(10, 3) / R; 
float Errsigma = (20/10)*pow(10, 3) * ErrR / (R*R);

float RHall=0.0062;//ohm*m/T
float ErrRHall=0.00011;

float mu = RHall * sigma;
float Errmu = sqrt(pow(sigma*ErrRHall, 2) + pow(RHall*Errsigma, 2));

cout << R << " +- " << ErrR << endl;
cout << "Conducibilità: " << sigma <<  " +- " << Errsigma << endl;
cout << "Mobilità: " << mu <<  " +- " << Errmu << endl;



}
