#include <math.h>
#include "pav_analysis.h"

float compute_power(const float *x, unsigned int N)
{
    float pot = 1e-12;
    for (unsigned int n = 0; n <= N; n++)
    {
        pot += x[n] * x[n];
    }
    return 10 * log10(pot/N);
}

float compute_am(const float *x, unsigned int N)
{
    float amp = 1e-12;
    for (unsigned int n = 0; n < N; n++)
    {
        amp += fabs(x[n]);
    }
    return (amp/N);
}

float compute_zcr(const float *x, unsigned int N, float fm)
{
    int zcr=0;
    for (unsigned int n = 1; n < N; n++){
        if(x[n]*x[n-1]<0){
            zcr++;
        }
    }
    return (fm/2.0)*(1.0/(N-1.0))*zcr;
}
