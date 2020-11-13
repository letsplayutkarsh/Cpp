#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static inline float truncfun(float x) {
    return floor((floor(x*1e5)*1e-5+1e-5)*1e4)*1e-4 ;
}

//to convert string into array of double (vector)
void convertArray(char str[], double arr[], int n){
    char *temp1,*temp2;
    temp1=str;
    for(int i=0;i<n;i++){
        arr[i] = strtod(temp1,&temp2);
        temp2++;
        temp1 = temp2;
    }
}
//to check that every no is +ve
int checkPositive(double v[], int n){
    for(int i=0; i<n; i++)
        if(v[i]<0)
            return 0;
    return 1;
}

//to check if str is valid and call convertArray
int checknconvertString(char str[],double vect[] ,int n){
    convertArray(str,vect,n);

    for(int i=0; i<strlen(str); i++){
        //in valid str which is to be converted into double array should only have
        //numbers and ","
        if(isdigit(str[i]) || str[i] == ',' || str[i] == '.'){
            continue;
        }
        else
            //if no return 0
            return 0;
    }
    //check if no is +ve
    return checkPositive(vect,n);;
}

//to normalize vector
void normalize(double arr[], int n){
    double sum=0;
    for(int i=0; i<n ; i++)
        sum += arr[i];

    for(int i=0; i<n; i++)
        arr[i] /= sum;
}

// to find mod of double
double abss(double a){
    if (a<0)    return -a;
    else        return a;
}

//to find Manhattan Distance
double ManhattanDistance(double v1[], double v2[], int n){
    double md=0;
    for(int i=0; i<n; i++)
        md += abss(v2[i] - v1[i]);

    return md;
}
// to find Euclidean Distance
double EuclideanDistance(double v1[], double v2[], int n){
    double ed=0;
    for(int i=0; i<n; i++)
        ed += (v2[i] - v1[i])*(v2[i] - v1[i]);


    return sqrt(ed);
}

// to find Chebyshev Distance
double ChebyshevDistance(double v1[], double v2[], int n){
    double cd=0;
    double temp[n];
    for(int i=0; i<n; i++)
        temp[i] = abss(v2[i] - v1[i]);

    for(int i=0; i<n ; i++)
        if(temp[i]>cd)
            cd=temp[i];

    return cd;
}

// to find Kullback Leibler Divergence
double KullbackLeiblerDivergence(double v1[], double v2[], int n){
    double kld=0;

    for(int i=0; i<n; i++)
        kld += (v1[i] * log( v1[i] / v2[i] ) );
    return kld;
}

// to find Jensen Shannon Distance
double JensenShannonDistance(double v1[], double v2[], int n){
    double jsd,m[n];

    for(int i=0; i<n; i++)
        m[i] = (v1[i]+v2[i])/2;

    jsd = 0.5*(KullbackLeiblerDivergence(v1,m,n) + KullbackLeiblerDivergence(v2,m,n));
    return sqrt(jsd);
}

int main(){
    //declaration
    char str1[10000],str2[10000],str[10000];
    int n,m1,m2;
    float m3;
    //taking input string
    fgets(str,10000,stdin);

    //to check is last 2 element is equal to -1 // this cannot be taking by sscanf
    //as this place can be empty so doing explicitly
    // m3[0] = str[strlen(str)-3];
    // m3[1] = str[strlen(str)-2];

    // memcpy( m3, &str[strlen(str)-3], 2);
    // m3[2] = '\0';

    //string parsing (taking essential things)
    sscanf(str,"%d %d %[^ ] %d %[^ ] %f",&n,&m1,str1,&m2,str2,&m3);


    double vect1[n],vect2[n];
    //checking is -1 are at appropriate place
    if(m1==-1 && m2==-1 && m3==-1 && n>0){
        if( checknconvertString(str1,vect1,n) && checknconvertString(str2,vect2,n) ){

            //normalizing vector
            normalize(vect1,n);
            normalize(vect2,n);
            //calling functions
            printf("%.4lf,",truncfun(ManhattanDistance(vect1,vect2,n)));
            printf("%.4lf,",truncfun(EuclideanDistance(vect1,vect2,n)));
            printf("%.4lf,",truncfun(ChebyshevDistance(vect1,vect2,n)));
            printf("%.4lf,",truncfun(KullbackLeiblerDivergence(vect1,vect2,n) + KullbackLeiblerDivergence(vect2,vect1,n)));
            printf("%.4lf",truncfun(JensenShannonDistance(vect1,vect2,n)));

        }
        else
            printf("-1");
    }
    else
        printf("-1");
    return 0;
}
