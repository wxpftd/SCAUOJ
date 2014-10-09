#include <iostream>
#include <cstdio>

using namespace std;

int findk(int x[], int y[], int k, int xl, int xr, int yl, int yr)
{
    if (xl > xr) return y[yl+k-1];
    if (yl > yr) return x[xl+k-1];
    int xm = (xl+xr)/2;
    int ym = (yl+yr)/2;
    int halflen = xm - xl + ym - yl + 2;
    //printf("ma:%d  mb:%d  halflen:%d  k:%d\n", xm, ym, halflen, k);
    if (x[xm] > y[ym])
    {
        if (k < halflen) return findk(x, y, k, xl, xm-1, yl, yr); 
        k = k - (ym-yl+1);
        return findk(x, y, k, xl, xr, ym+1, yr);
    }
    else
    {
        if (k < halflen) return findk(x, y, k, xl, xr, yl, ym-1); 
        k = k - (xm-xl+1);
        return findk(x, y, k, xm+1, xr, yl, yr);
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int *x = new int[n];
    int *y = new int[m];
    for (int i=0; i<n; i++)
        cin >> x[i];
    for (int i=0; i<m; i++)
        cin >> y[i];
    cout << findk(x, y, k, 0, n-1, 0, m-1) << endl;
    delete x;
    delete y;
    return 0;
}
