#include<iostream>
#include<math.h>
#include<TGraph.h>
#include<TF1.h>
#include<TCanvas.h>
#include<TLegend.h>

using namespace std;

void TensioneGeiger(){

int const N=28;  
int R= 100; // [mV/uA] -> Sarebbe R= 0.1 [V/uA]

float t=20;
float Err_t=0.001;

float conteggi[]={26,105,607,1500,2253,2763,3169,4116,5404,6434,7211,7727,7724,7972,8017,7902,7904,8052,8099,7979,8162,8060,8251,8177,8168,8173,8083,8222};
float Err_conteggi[N];

float HV[]={390,392,394,397,399,402,404,406,409,411,413,416,418,421,423,425,428,432,437,442,447,451,456,461,466,471,475,480};
float Err_HV[N];

float rate[N];
float Err_rate[N];

for(int i=0;i<N;i++){
Err_conteggi[i]=sqrt(conteggi[i]);
Err_HV[i]=1;

rate[i]=conteggi[i]/t;
Err_rate[i]= sqrt(pow(Err_conteggi[i]/conteggi[i],2)+pow(Err_t/t,2))*rate[i];
}

// Disegno i grafico con i fit lineari

TCanvas *c1= new TCanvas("c1", "cps(HV)", 200,30,1200,800);
c1->SetGrid();
c1->cd();

TGraphErrors *gr1= new TGraphErrors(N, HV, rate, Err_HV,Err_rate);
gr1->SetTitle("#it{cps(HV)}");
gr1->SetMarkerStyle(8);
gr1->SetMarkerSize(0.8);
gr1->GetXaxis()->SetTitle("#it{HV}[V]");
gr1->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr1->Draw("AP");

TF1 *fit_1 = new TF1("fit_1", "[0]*x+[1]",0, 420); 
fit_1->SetParameter(0,10);
fit_1->SetParameter(1,-10);
//fit_1->SetParNames("a","b");
fit_1->SetLineColor(8);
fit_1->SetLineWidth(2);
gr1->Fit("fit_1","RM+");
gr1->Draw("AP");

TF1 *fit_2 = new TF1("fit_2", "[0]*x+[1]",420, 500); 
fit_2->SetParameter(0,0);
fit_2->SetParameter(1,400);
//fit_2->SetParNames("a","b");
fit_2->SetLineColor(9);
fit_2->SetLineWidth(2);
gr1->Fit("fit_2","RM+");
gr1->Draw("Psame");

TLegend *L1 = new TLegend(0.1,0.7,0.48,0.9);
L1->SetHeader("Legenda");
L1->AddEntry(fit_1, "Salita","l");
L1->AddEntry(fit_2, "Plateau","l");
L1->Draw("same");




////////////////////////////////////////////////////////////////////////////////////////////

int const M=36;

float voltaggio[]={21.1,27.8,36.9,50.1,59.0,71.4,82.2,88.0,104.5,113.5,122.5,129.2,136.3,145.0,159.4,172.7,178.5,198.5,313.1,413.7,514.5,608.5,710.8,804.9,901.7,1065,1110,1200,1301,1399,1506,1610,1697,1797, 1898,1999}; // voltaggio del filamento [mV]
float Err_voltaggio[M];

float conteggi_2[]={5564,7238,9368,12065,13868,16114,17052,17870,18460,18573,18660,18363,18624,18840,18936,19093,19170,19262,22025,23731,24504,25551,26258,27237,27722,29100,29399,30154,30720,31693,32368,32926,33835,34534,35129,35830};
float Err_conteggi_2[M];

float corrente[M]; //[uA]
float Err_corrente[M];

float rate_2[M]; //sempre a t=20
float Err_rate_2[M];

for(int i=0;i<M;i++){
    if(voltaggio[i]<1000){
        Err_voltaggio[i]=(0.1/100)*voltaggio[i]+5*0.1; //[mV]
    }else{
        Err_voltaggio[i]=(0.1/100)*voltaggio[i]+5*1; //[mV]
    }
    Err_conteggi_2[i]=sqrt(conteggi_2[i]);

    corrente[i]=voltaggio[i]/R; // [uA]
    Err_corrente[i]=Err_voltaggio[i]/R;

    rate_2[i]=conteggi_2[i]/t;
    Err_rate_2[i]= sqrt(pow(Err_conteggi_2[i]/conteggi_2[i],2)+pow(Err_t/t,2))*rate_2[i];
}

// Disegno il grafico con i fit lineari

TCanvas *c2= new TCanvas("c2", "#it{cps(I)}", 200,30,1200,800);
c2->SetGrid();
c2->cd();
TGraphErrors *gr2= new TGraphErrors(M, corrente, rate_2, Err_corrente,Err_rate_2);
gr2->SetTitle("#it{cps(I)}");
gr2->SetMarkerStyle(8);
gr2->SetMarkerSize(0.8);
gr2->GetXaxis()->SetTitle("#it{I}[#muA]");
gr2->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr2->Draw("AP");

TF1 *fit_3 = new TF1("fit_3", "[0]*x+[1]",0, 0.80); 
fit_3->SetParameter(0,10);
fit_3->SetParameter(1,-10);
//fit_3->SetParNames("a","b");
fit_3->SetLineColor(8);
fit_3->SetLineWidth(2);
gr2->Fit("fit_3","RM+");
gr2->Draw("AP");

TF1 *fit_4 = new TF1("fit_4", "[0]*x+[1]",0.8, 2.2); 
fit_4->SetParameter(0,0);
fit_4->SetParameter(1,400);
//fit_4->SetParNames("a","b");
fit_4->SetLineColor(9);
fit_4->SetLineWidth(2);
gr2->Fit("fit_4","RM+");
gr2->Draw("Psame");

TF1 *fit_5 = new TF1("fit_5", "[0]*x+[1]",2.2, 25); 
fit_5->SetParameter(0,0);
fit_5->SetParameter(1,400);
//fit_5->SetParNames("a","b");
fit_5->SetLineColor(kRed);
fit_5->SetLineWidth(2);
gr2->Fit("fit_5","RM+");
gr2->Draw("Psame");

TLegend *L2 = new TLegend(0.1,0.7,0.48,0.9);
L2->SetHeader("Legenda");
L2->AddEntry(fit_3, "Pendenza 1","l");
L2->AddEntry(fit_4, "Pendenza 2","l");
L2->AddEntry(fit_5, "Pendenza 3","l");
L2->Draw("same");

//////////////////////////////////////////////////////////SOLo prima salita per trovare corrrente di lavoro

float Err_voltaggio1[7];
float Err_conteggi2[7];
float corrente1[7];
float Err_corrente1[7];
float rate3[7];
float Err_rate3[7];

for (int j=0; j<7; j++){
    Err_voltaggio1[j]=(0.1/100)*voltaggio[j]+5*0.1; //[mV]
    Err_conteggi2[j]=sqrt(conteggi_2[j]);
 
    corrente1[j]=voltaggio[j]/R; // [uA]
    Err_corrente1[j]=Err_voltaggio1[j]/R;

    rate3[j]=conteggi_2[j]/t;
    Err_rate3[j]= sqrt(pow(Err_conteggi2[j]/conteggi_2[j],2)+pow(Err_t/t,2))*rate3[j];

}

TCanvas *c4= new TCanvas("c4", "#it{cps(I)}", 200,30,1200,800);
c4->SetGrid();
c4->cd();
TGraphErrors *gr4= new TGraphErrors(6 ,corrente1, rate3, Err_corrente1,Err_rate3);
gr4->SetTitle("#it{cps(I)}");
gr4->SetMarkerStyle(8);
gr4->SetMarkerSize(0.8);
gr4->GetXaxis()->SetTitle("#it{I}[#muA]");
gr4->GetYaxis()->SetTitle("#it{cps}[#s^{-1}]");
gr4->Draw("AP");

TF1 *fit_6 = new TF1("fit_6", "[0]*x+[1]",0, 0.9); 
fit_6->SetParameter(0,1000);
fit_6->SetParameter(1,60);
fit_6->SetParNames("a","b");
fit_6->SetLineColor(8);
fit_6->SetLineWidth(2);
gStyle->SetOptFit(1);
gr4->Fit("fit_6","RM+");
gr4->Draw("AP");



// NOTA: ad un certo punto il geiger arriva a staurazione e si nota che la pendenza iniziale si attenua: cio' e' dovuto 
// ad un problema di sovrapposizione del segnale: il geiger non riesce a scaricarsi quando si hanno troppi conteggi e 
// quindi si sovrappone perdendosene qualcuno, per cui si ha un calo di efficienza all'aumentare dei conteggi


}

