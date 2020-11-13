#ifndef BinomialDistribution_H
#define BinomialDistribution_H

#include "Histogram.h"

class BinomialDistribution : public Histogram {
private:
    double *H1, *H2;
    int bs,n;
    double p1,p2;

    double PMF(int k, int n, double p);
    double fact(int n);
    double nCr(int n, int r);
    void calBinValue();
    inline double truncf(double n);


public:
    BinomialDistribution (double P1, double P2, int N);
    BinomialDistribution (const BinomialDistribution &f);
    ~BinomialDistribution();

    void printDistance();
};

#endif
