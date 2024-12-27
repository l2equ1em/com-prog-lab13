#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double num[],int n,double output[]){
    double sum = 0, product = 1.0, sum2 = 0, sumH = 0, max = num[0], min = num[0];
    for(int i = 0; i < n; i++){
        sum += num[i];
        sum2 += num[i]*num[i];
        product *= num[i];
        sumH += 1/num[i];
        if(num[i] > max) max = num[i];
        else if(num[i] < min) min = num[i];
    }
    output[0] = sum / n;
    output[1] = sqrt(sum2 / n - (sum / n) * (sum / n));
    output[2] = pow(product, 1.0 / n);
    output[3] = n / sumH;
    output[4] = max;
    output[5] = min;
}