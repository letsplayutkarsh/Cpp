#include "FiveNumberSummary.h"
#ifndef DataSequence_H
#define DataSequence_H

class DataSequence {
private:
    float *arr,*bV,*bF;
    int size,bs;
    float binRange;
    FiveNumberSummary FiveNoS;

    void createBin();
    void createFreq();

public:
    DataSequence (float *f, int binSize, int n);
    DataSequence (const DataSequence &f);
    // ~DataSequence ();

    

    float median();
    float firstQuartile();
    float min();
    float max();
    float thirdQuartile();

    void printHistoVal();
    void printHistoFreq();

    void addNumber(float no);
};

#endif
