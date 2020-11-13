#include "BinomialDistribution.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    float p1,p2;

    string input;
    getline(cin, input);
    stringstream s(input);

    if(!(s>>n>>p1>>p2)){
        // cerr<< "-1";
        cout<<"-1";
        return 0;
    }
    if((p1 <= 0 || p1 >= 1) || (p2 <= 0 or p2 >= 1) || n<=0){
        // cerr<< "-1";
        cout<<"-1";
        return 0;
    }

    BinomialDistribution bd(p1,p2,n);
    bd.printDistance();
}
