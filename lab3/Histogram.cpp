#include <bits/stdc++.h>
#include "Histogram.h"
using namespace std;

Histogram::Histogram (float *bv, float *bf, int binSize){

    bs = binSize;
    bV = new float[bs+1];
    bF = new float[bs];

    for(int i=0; i<bs; i++){
        *(bV+i) = *(bv+i);
        *(bF+i) = *(bf+i);
    }
    *(bV+bs) = *(bv+bs);
}

Histogram::Histogram (const Histogram &f){
    bs = f.bs;
    bV = new float[bs+1];
    bF = new float[bs];

    for(int i=0; i<bs; i++){
        *(bF+i) = *(f.bF+i);
        *(bV+i) = *(f.bV+i);
    }
    *(bV+bs) = *(f.bV+bs);
}

Histogram::~Histogram (){
    delete []bV;
    delete []bF;
}

inline float Histogram::truncf(float n){
    return floor((floor(n*1e5)*1e-5+1e-5)*1e4)*1e-4;
}


void Histogram::printBinValue(){
    for(int i=0; i<bs; i++)
        cout<<fixed<<setprecision(4)<<truncf(*(bV+i))<<",";
    cout<<fixed<<setprecision(4)<<truncf(*(bV+bs))<<" ";

}
void Histogram::printBinFreq(){
    for(int i=0; i<bs-1; i++)
        cout<<fixed<<setprecision(4)<<truncf(*(bF+i))<<",";
    cout<<fixed<<setprecision(4)<<truncf(*(bF+bs-1))<<" -1 ";
}
