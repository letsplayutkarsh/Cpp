#include <bits/stdc++.h>
#include <iostream>
#include "DataSequence.h"
#include "Histogram.h"
#include "FiveNumberSummary.h"
using namespace std;

DataSequence::DataSequence (float *f, int binSize, int n){
    size = n;
    bs = binSize;

    arr = new float[size];
    bV = new float[binSize+1];
    bF = new float[binSize];

    for(int i=0; i<size; i++){
        *(arr+i) = *(f+i);
    }
    sort(arr,arr+size);

    createBin();
    createFreq();

    FiveNoS.setter(arr,size);
}

DataSequence::DataSequence (const DataSequence &f){
    size = f.size;
    bs = f.bs;

    bV = new float[bs+1];
    bF = new float[bs];
    arr = new float[size];

    for(int i=0; i<size; i++)
        *(arr+i) = *(f.arr+i);

    sort(arr,arr+size);

    createBin();
    createFreq();

    FiveNoS.setter(arr,size);
}

// DataSequence::~DataSequence (){
//     delete []arr;
//     delete []bV;
//     delete []bF;
// }

float DataSequence::median(){
    return FiveNoS.getMedian();
}
float DataSequence::firstQuartile(){
    return FiveNoS.getFirst_quartile();
}
float DataSequence::min(){
    return FiveNoS.getMinimum();
}
float DataSequence::max(){
    return FiveNoS.getMaximum();
}
float DataSequence::thirdQuartile(){
    return FiveNoS.getThird_quartile();
}

void DataSequence::createBin(){
    float start;

    if(size==1 || *(arr+size-1) - *(arr+0) == 0){
        binRange = 1.0/bs;
        start = *(arr+0)-0.5;

        for(int i=0; i<bs+1; i++){
            *(bV + i) = start;
            start += binRange;
        }
    }
    else{
        binRange = (*(arr+size-1) - *(arr+0))/bs;
        start = *(arr+0);

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
            if((*(arr+j) >= *(bV+i) && *(arr+j) < *(bV+i)+binRange) || *(arr+j)  == *(bV+bs))
                count+=1;
        }

        // if(*(arr+i) + 0.000001 >= *(bV+bs-1) + binRange){
        //     *(bF+bs-1)+=1;
        // }
        *(bF+i)=count;
    }

    for(int i=0; i<bs; i++)
        *(bF+i) /= size;


    float suum=0;

    for(int i=0; i<bs; i++){
        suum += *(bF+i);
    }
    if(suum!=1){
        *(bF+bs-1) += 1-suum; 
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

void DataSequence::addNumber(float no){

    float *temp = new float[size+1];

    for(int i=0; i<size; i++)
        *(temp+i) = *(arr+i);
    *(temp+size) = no;

    delete []arr;
    arr = new float[size+1];

    for(int i=0; i<size+1; i++)
        *(arr+i) = *(temp+i);

    size=size+1;

    sort(arr,arr+size);
    createBin();
    createFreq();

    FiveNoS.setter(arr,size);
}
