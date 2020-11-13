#ifndef DataSequence_H
#define DataSequence_H

class DataSequence {
private:
    float *arr,*bV;
    int *bF;
    int size,bs;
    float binRange;

    void createBin();
    void createFreq();

public:
    DataSequence (float *f, int binSize, int n);
    DataSequence (const DataSequence &f);
    ~DataSequence ();

    float median();
    float mean();
    float min();
    float max();


    void printHistoVal();
    void printHistoFreq();
    // float getBinRange();
    // float* getBinValueArr();
    // int* getBinFreqArr();
};

#endif
