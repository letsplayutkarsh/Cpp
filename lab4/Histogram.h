#ifndef Histogram_H
#define Histogram_H

class Histogram {
private:
    double abss(double a);

public:
    double ManhattanDistance(double *H1, double *H2, int n);
    double EuclideanDistance(double *H1, double *H2, int n);
    double ChebyshevDistance(double *H1, double *H2, int n);
    double KullbackLeiblerDivergence(double *H1, double *H2, int n);
    double JensenShannonDistance(double *H1, double *H2, int n);
    int check(double *H1, double *H2);

};

#endif
