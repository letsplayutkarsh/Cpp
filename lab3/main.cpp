#include "DataSequence.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

inline float truncf(float n){
    return floor((floor(n*1e5)*1e-5+1e-5)*1e4)*1e-4;
}

int main(){

    string input;
    getline(cin, input);
    stringstream s(input);

    vector<DataSequence> DSVector;
    vector<string> temp;
    vector<string> vect;

    string nums;
    while(getline(s,nums,'-')){
        temp.push_back(nums);
    }

    for(int i = 0; i < temp.size()-1; i++){
        if(i!=0){
            string v1(temp[i], 2, temp[i].length());
            vect.push_back(v1);
        }
        else
            vect.push_back(temp[i]);

        if(vect[i][0] != 'A' && vect[i][0] != 'N'){
            cerr<<"-1";
            return 0;
        }
    }
    if(temp[temp.size()-1][0] != '1'){
        cerr<<"-1";
        return 0;
    }

    for(int i=0; i<vect.size(); i++){
        char opp,c1,c2;
        int n;
        float no;
        string numbers;
        stringstream s(vect[i]);
        if(vect[i][0] == 'N'){
            if(!(s >> opp >> c1 >> n >> numbers)){
                cout<<"-1";
                return 0;
            }

            stringstream ns(numbers);
            string number;
            float* array = new float[n];

            for(int i=0; i<n; i++){
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
            DataSequence d(array ,10, n);
            DSVector.push_back(d);

            // cout<<opp<<" "<<n<<" "<<numbers<<endl;
        }
        else if(vect[i][0] == 'A'){
            if(!(s >> opp >> c1 >> n >>c2 >> no)){
                cerr<<"-1";
                return 0;
            }
            if(n<0 || n>=DSVector.size() || no<=0){
                cerr<<"-1";
                return 0;
            }
            DSVector[n].addNumber(no);
            // cout<<opp<<" "<<n<<" "<<no<<endl;
        }
    }

    for(int i=0; i<DSVector.size(); i++ ){
        cout<<fixed<<setprecision(4)<< truncf(DSVector[i].min()) << "," << truncf(DSVector[i].firstQuartile()) << ","<<truncf(DSVector[i].median()) << ","<< truncf(DSVector[i].thirdQuartile()) <<","<< truncf(DSVector[i].max())<<" ";
        DSVector[i].printHistoVal();
        DSVector[i].printHistoFreq();
    }

    return 0;
}
