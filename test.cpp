#include <iostream>
using namespace std;
long  total=0;
int main()
{
    void solve(long n);
    long n;
    cin>>n;
    solve(n);
    cout<<total<<endl;
    return 0;
}
void solve(long n)
{
    if(n==1)
        total++;
    else
    {
        for(long i=2;i<=n;i++)
            if(n%i==0)
                solve(n/i);
    }
}
