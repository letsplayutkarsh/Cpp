#include <bits/stdc++.h>
#include "Histogram.h"
using namespace std;

Histogram::Histogram (float *bv, int *bf, int binSize){

    bs = binSize;
    bV = new float[binSize+1];
    bF = new int[binSize];

    for(int i=0; i<bs; i++){
        *(bV+i) = *(bv+i);
        *(bF+i) = *(bf+i);
    }
    *(bV+bs) = *(bv+bs);

}

Histogram::Histogram (const Histogram &f){
    bs = f.bs;
    bV = new float[bs+1];
    bF = new int[bs];

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
    return floor((floor(n*1e5)*1e-5+1e-5)*1e4)*1e-4  ;
}

void Histogram::printBinValue(){
    for(int i=0; i<bs; i++)
        cout<<*(bV+i)<<",";
    cout<<*(bV+bs)<<" -1 ";

}
void Histogram::printBinFreq(){
    for(int i=0; i<bs-1; i++)
        cout<<(*(bF+i))<<",";
    cout<<*(bF+bs-1)<<" -1";

}
