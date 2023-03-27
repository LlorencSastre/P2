#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N) {
    float pot = 1e-12;
    for(unsigned int i = 0; i<N; i++){
        pot += x[i] * x[i];
    }
    return (10*log10(pot/N));
}

float compute_am(const float *x, unsigned int N) {
    float res = 0;
    for(unsigned int i = 0; i<N; i++){
        res += fabs(x[i]);
    }
    return res/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int zcr = 0;
    for(unsigned int i = 1; i < N; i++){
        if(x[i]*x[i-1]<0){
            zcr++;
        }
    }
    return (fm/2.0)*(1.0/(N-1.0))*zcr;
}