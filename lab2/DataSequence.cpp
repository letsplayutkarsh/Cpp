#include <bits/stdc++.h>
#include <iostream>
#include "DataSequence.h"
#include "Histogram.h"
using namespace std;

DataSequence::DataSequence (float *f, int binSize, int n){
    size = n;
    bs = binSize;

    arr = new float[size];
    bV = new float[binSize+1];
    bF = new int[binSize];

    for(int i=0; i<size; i++){
        *(arr+i) = *(f+i);
    }
    sort(arr,arr+size);

    createBin();
    createFreq();
}

DataSequence::DataSequence (const DataSequence &f){
    bs = f.bs;
    bV = new float[bs+1];
    bF = new int[bs];

    for(int i=0; i<size; i++)
        *(arr+i) = *(f.arr+i);

    createBin();
    createFreq();
}

DataSequence::~DataSequence (){
    delete []arr;
    delete []bV;
    delete []bF;
}

float DataSequence::median(){
    if(size%2==0)
        return (*(arr + (size-1)/2) + *(arr + size/2))/2 ;
    return *(arr + size/2);
}

float DataSequence::mean(){
    float sum=0.0;

    for(int i=0; i<size; i++)
        sum += *(arr+i);
    return sum/(float)size;
}

float DataSequence::min(){
    return *(arr+0);
}

float DataSequence::max(){
    return *(arr+size-1);
}

void DataSequence::createBin(){
    float start;

    if(size==1 || max() - min() == 0){
        binRange = 1.0/bs;
        start = min()-0.5;

        for(int i=0; i<bs+1; i++){
            *(bV + i) = start;
            start += binRange;
        }
    }
    else{
        binRange = (max() - min())/bs;
        start = min();

        for(int i=0; i<bs+1; i++){
            *(bV + i) = start;
            start += binRange;
        }
    }
}

void DataSequence::createFreq(){


    int count=0;

    for(int i=0; i<bs; i++){
        count=0;
        for(int j=0; j<size; j++){
            if(*(arr+j) >= *(bV+i) && *(arr+j) < *(bV+i)+binRange)
                count+=1;
            }
        *(bF+i)=count;
    }

}

void DataSequence::printHistoVal(){
    Histogram histo(bV,bF,bs);
    histo.printBinValue();
}

void DataSequence::printHistoFreq(){
    Histogram histo(bV,bF,bs);
    histo.printBinFreq();
}
