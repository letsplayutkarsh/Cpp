#include <bits/stdc++.h>
#include <iostream>
#include "FiveNumberSummary.h"
using namespace std;

void FiveNumberSummary::setter(float *f, int n){
    size = n;
    arr = new float[size];

    for(int i=0; i<size; i++)
        *(arr+i) = *(f+i);


    minimum = calculateMinimum();
    first_quartile = calculateFirst_quartile();
    median = calculateMedian();
    third_quartile = calculateThird_quartile();
    maximum = calculateMaximum();

}

FiveNumberSummary::~FiveNumberSummary (){
    delete []arr;
}

float FiveNumberSummary::calculateMaximum(){
    return *(arr+size-1);
}

float FiveNumberSummary::calculateMinimum(){
    return *(arr+0);
}

float FiveNumberSummary::calculateMedian(){
    if(size%2==0)
        return (*(arr + (size-1)/2) + *(arr + size/2))/2 ;
    return *(arr + size/2);
}

float FiveNumberSummary::calculateFirst_quartile(){

    if((size-1)%4 != 0)
        return (arr[(int)floor(0.25*(size-1))] + arr[(int)ceil(0.25*(size-1))])/2 ;
    else
        return arr[(int)(0.25*(size-1))];
}

float FiveNumberSummary::calculateThird_quartile(){
    if(3*(size-1) %4 != 0)
        return (arr[(int)floor(0.75*(size-1))] + arr[(int)ceil(0.75*(size-1))])/2 ;
    else
        return arr[(int)(0.75*(size-1))];

}

float FiveNumberSummary::getMinimum(){
    return minimum;
}
float FiveNumberSummary::getFirst_quartile(){
    return first_quartile;
}
float FiveNumberSummary::getMedian(){
    return median;
}
float FiveNumberSummary::getThird_quartile(){
    return third_quartile;
}
float FiveNumberSummary::getMaximum(){
    return maximum;
}
