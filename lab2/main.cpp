#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include "DataSequence.h"

inline float truncf(float n){
    return floor((floor(n*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

int main()
{
    string input;
    getline(cin, input);
    stringstream s(input);

    int n, n0, m1, m2, m3;
    string nums;

    if (!(s >> n >> m1 >> nums >> m2 >> n0 >> m3)){
        cerr << "-1";
        return 0;
    }

    if (m1!=-1 || m2!=-1 || m3!=-1){
        cerr << "-1";
        return 0;
    }
    if(n0<=0){
        cerr << "-1";
        return 0;
    }

    float* array = new float[n];

    stringstream ns(nums);
    string number;

    for(int i=0 ; i<n ; i++)
    {
        if(!getline(ns, number, ',')){
            cerr << "-1";
            return 0;
        }

        if(stof(number) <= 0){
            cerr << "-1";
            return 0;
        }
        else{
            array[i] = stof(number);
        }
    }

    DataSequence d(array, n0, n);
    cout<< fixed << setprecision(4) <<truncf(d.min()) << " -1 " << truncf(d.mean()) << " -1 " << truncf(d.median()) << " -1 " << truncf(d.max())<<  " -1 "<<endl ;
    d.printHistoVal();
    d.printHistoFreq();

}
