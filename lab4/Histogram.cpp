#include <bits/stdc++.h>
#include "Histogram.h"
using namespace std;

double Histogram::abss(double a){
    if (a<0)
        return -a;
    else
        return a;
}

int Histogram::check(double *H1, double *H2){
    if(sizeof(H1) == sizeof(H2)) return 1;
    else return 0;
}

double Histogram::ManhattanDistance(double *v1, double *v2, int n){
    double md=0;
    for(int i=0; i<n; i++)
        md += abss(v2[i] - v1[i]);
    return md;
}

double Histogram::EuclideanDistance(double *v1, double *v2, int n){
    double ed=0;
    for(int i=0; i<n; i++)
        ed += (v2[i] - v1[i])*(v2[i] - v1[i]);
    return sqrt(ed);
}

double Histogram::ChebyshevDistance(double *v1, double *v2, int n){
    double cd=0;
    double temp[n];

    for(int i=0; i<n; i++)
        temp[i] = abss(v2[i] - v1[i]);
    for(int i=0; i<n ; i++)
        if(temp[i]>cd)
            cd=temp[i];

    return cd;
}

double Histogram::KullbackLeiblerDivergence(double *v1, double *v2, int n){
    double kld=0;
    for(int i=0; i<n; i++)
        kld += (v1[i] * log( v1[i] / v2[i] ) );
    return kld;
}

double Histogram::JensenShannonDistance(double *v1, double *v2, int n){
    double jsd,m[n];
    for(int i=0; i<n; i++)
        m[i] = (v1[i]+v2[i])/2;

    jsd = 0.5*(KullbackLeiblerDivergence(v1,m,n) + KullbackLeiblerDivergence(v2,m,n));
    return sqrt(jsd);
}
