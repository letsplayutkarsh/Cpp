#ifndef Histogram_H
#define Histogram_H

class Histogram {
private:
    float *bV;
    float *bF;
    int bs;
    inline float truncf(float n);

public:
    Histogram (float *bv, float *bf, int binSize);
    Histogram (const Histogram &f);
    ~Histogram ();

    void printBinValue();
    void printBinFreq();

};

#endif
