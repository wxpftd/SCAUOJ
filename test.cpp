#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define maxn 100010
using namespace std;

int a[maxn],b[maxn],k;

int f(int la,int ra,int lb,int rb)
{
    int halflen,ma,mb;
    if(lb>rb) return a[la+k-1];//递归边界
    if(la>ra) return b[lb+k-1];//递归边界
    ma=(ra+la)/2;mb=(rb+lb)/2;
    halflen=ma-la+mb-lb+2;
    if(a[ma]<b[mb])
    {
        if(k<halflen) return f(la,ra,lb,mb-1);
        k=k-(ma-la+1);
        return f(ma+1,ra,lb,rb);
   }
    else
    {
        if(k<halflen) return f(la,ma-1,lb,rb);
        k=k-(mb-lb+1);
        cout << "amid: " << ma << endl;
        cout << "bmid: " << mb << endl;
        cout << "halfmid: " << halflen << endl;
        cout << "k: " << k << endl;
        return f(la,ra,mb+1,rb);
    }
}

int main()
{
    int m,n,i;

    scanf("%d%d%d",&m,&n,&k);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    printf("%d\n",f(0,m-1,0,n-1));
    return 0;
}
