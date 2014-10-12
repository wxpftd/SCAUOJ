#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    double *X = (double*)malloc(n*sizeof(double)); 
    double *Y = (double*)malloc(n*sizeof(double)); 
    double *Z = (double*)malloc(n*sizeof(double)); 
    for (int i=0; i<n; i++)
        scanf("%lf", &X[i]);
    Y[0] = X[0];
    Z[0] = X[0];
    for (int i=1; i<n; i++)
    {
        Y[i] = Y[i-1] + X[i];
        Z[i] = Y[i] / (i+1);
    }
    for (int i=0; i<n; i++)
        printf("%.2lf ", Z[i]);
    printf("\n");
    free (X);
    free (Y);
    free (Z);
    return 0;
}

