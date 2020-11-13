#ifndef Histogram_H
#define Histogram_H

class Histogram {
private:
    float *bV;
    int *bF;
    int bs;

    inline float truncf(float n);

public:
    Histogram (float *bv, int *bf, int binSize);
    Histogram (const Histogram &f);
    ~Histogram ();

    void printBinValue();
    void printBinFreq();

};

#endif
