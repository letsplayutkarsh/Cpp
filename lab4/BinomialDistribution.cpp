#include <bits/stdc++.h>
#include "BinomialDistribution.h"
using namespace std;

BinomialDistribution::BinomialDistribution(double P1, double P2, int N){
    bs = N+1;
    n = N;
    H1 = new double[bs];
    H2 = new double[bs];
    p1 = P1;
    p2 = P2;

    calBinValue();
}

BinomialDistribution::BinomialDistribution (const BinomialDistribution &f){
    bs = f.bs;
    n = f.n;

    H1 = new double[bs];
    H2 = new double[bs];
    p1 = f.p1;
    p2 = f.p2;

    for(int i=0; i<bs; i++){
        *(H1+i) = *(f.H1+i);
        *(H2+i) = *(f.H2+i);
    }
}

BinomialDistribution::~BinomialDistribution (){
    delete []H1;
    delete []H2;
}

double BinomialDistribution::fact(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

double BinomialDistribution::nCr(int n, int r){
    return (fact(n)/(fact(n-r)*fact(r)));
}

double BinomialDistribution::PMF(int k, int n, double p){
    return nCr(n, k)*pow(p, k)*pow(1-p, n-k);
}

void BinomialDistribution::calBinValue(){

    for(int i=0; i<bs; i++){
        *(H1 + i) = PMF(i,n,p1);
        *(H2 + i) = PMF(i,n,p2);
    }
}

inline double BinomialDistribution::truncf(double n){
    return floor((floor(n*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

void BinomialDistribution::printDistance(){
    if(check(H1,H2)){
        cout<<fixed<<setprecision(4)<<truncf(ManhattanDistance(H1,H2,bs))<<" ";
        cout<<fixed<<setprecision(4)<<truncf(EuclideanDistance(H1,H2,bs))<<" ";
        cout<<fixed<<setprecision(4)<<truncf(ChebyshevDistance(H1,H2,bs))<<" ";
        cout<<fixed<<setprecision(4)<<truncf(KullbackLeiblerDivergence(H1,H2,bs) + KullbackLeiblerDivergence(H2,H1,bs))<<" ";
        cout<<fixed<<setprecision(4)<<truncf(JensenShannonDistance(H1,H2,bs));
    }
    else {
        cerr<<"-1";
    }
}
