#include <iostream>
#include <string>
using namespace std;
long long gcd(long long x, long long y)
{
    long long r = x % y;
    while (r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
int main()
{
    string origin;
    string x, y;
    cin >> origin;
    int begin = origin.find('('), end = origin.find(')');
    int point = origin.find('.');
    if (origin.find('(') < origin.length())
    {
        x = origin.substr(point+1, begin-point-1);
        y = origin.substr(begin+1, end-begin-1);
        string mix = x + y;
        long long full = 0;
        long long part = 0;
        long long runfull = 1;
        long long runpart = 1;
        for (int i=mix.length()-1; i>=0; i--)
        {
            full += (mix[i] - '0') * runfull;
            runfull *= 10;
        }
        for (int i=x.length()-1; i>=0; i--)
        {
            part += (x[i] - '0') * runpart;
            runpart *= 10;
        }
        long long back = runfull - runpart, front = full - part;
        long long rest = gcd(front, back);
        cout << front/rest << " " << back/rest << endl;
    }
    else
    {
        x = origin.substr(point+1);
        long long full = 0;
        long long run = 1;
        for (int i=x.length()-1; i>=0; i--)
        {
            full += (x[i] - '0') * run;
            run *= 10;
        }
        long long rest = gcd(full, run);
        cout << full/rest << " " << run/rest << endl;
    }


    return 0;
}

