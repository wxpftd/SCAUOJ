#include <iostream>
using namespace std;
long solve(long n, long temp[])
{
    long total = 0;
    if(n==1)
        return 1;
    else
    {
        for(long i=2;i<=n;i++)
            if(n%i==0)
            {
                if (temp[n/i]==0) 
                    temp[n/i] = solve(n/i, temp);
                total += temp[n/i];
            }
        return total;
    }
}
int main()
{
    long *temp = new long[1000000]{};
    long n;
    cin>>n;
    cout << solve(n, temp) << endl;
    delete temp;
    return 0;
}

