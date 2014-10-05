#include <iostream>

using namespace std;

long long fun(long long n, long long tempNums[])
{
    if (-1 != tempNums[n])
    {
        return tempNums[n];      
    }
    long long result = 0;
    for (int i=0; i<n; i+=2)
    {
        result = result + fun(i, tempNums) * fun(n-2-i, tempNums);
    }
    tempNums[n] = result;
    return result;
}

int main()
{
    long long tempNums[50];
    tempNums[0] = 1;
    for (int i = 1; i < 50; i++)
    {
        tempNums[i] = -1; 
    }
    long long n = 0;
    cin >> n;
    cout << fun(2*n, tempNums) << endl;
    return 0;
}
