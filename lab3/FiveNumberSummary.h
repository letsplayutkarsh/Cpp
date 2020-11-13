#include <bits/stdc++.h>
using namespace std;
#ifndef FiveNumberSummary_H
#define FiveNumberSummary_H

class FiveNumberSummary {
private:
    float minimum,first_quartile,median,third_quartile,maximum;
    float *arr;
    int size;

    float calculateMinimum();
    float calculateFirst_quartile();
    float calculateMedian();
    float calculateThird_quartile();
    float calculateMaximum();

public:
    ~FiveNumberSummary ();

    void setter(float *f, int n);

    float getMinimum();
    float getFirst_quartile();
    float getMedian();
    float getThird_quartile();
    float getMaximum();

};

#endif
