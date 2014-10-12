#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    if (n < 3121)
        printf("impossible\n");
    for (long long i = 3121; i <= n; i+=3125)
        printf("%lld ", i);
    printf("\n");
    return 0;
}
