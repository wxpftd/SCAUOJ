#include <iostream>
#include <cstdio>
using namespace std;

int lessN(int n, int m)
{
    if (1 > n || 1 > m)
        return 0;
    else if (1 == n || 1 == m)
        return 1;
    else if (m == n)
    {
        return 1 + lessN(n, m-1); 
    }
    else if (m > n)
    {
        return lessN(n, n);
    }
    else if (n > m)
    {
        return lessN(n-m, m) + lessN(n, m-1); 
    }
    else
    {
        return 0;
    }
}

int fun1(int n, int m)
{
    if (m < 1 || n < 1)
        return 0;
    else if (m > n)
        return 0;
    else if (m == 1)
        return 1;
    else if (n == m)
        return 1;
    else if (m < n)
    {
        return fun1(n-m, m) + fun1(n-1, m-1);
    }
    else
    {
        printf("Error\n");
        return 0;
    }
}

int lessLenN(int n, int m)
{
    if (m < 1 || n < 1)
        return 0;
    else if (m > n)
        return 0;
    else if (m == 1)
        return 1;
    else 
    {
        int total = 0;
        for (int i=1; i<=m; i++)
            total += fun1(n, i);
        return total; 
    }
}
int odd(int n, int m);
int even(int n, int m);

int even(int n, int m)
{
    if (n == 1 && m == 1)
        return 0;
    if (n == 2 && m == 1)
        return 1;
    if (n == 2 && m == 2)
        return 0;
    if (m > n || m <= 0 || n <= 0)
        return 0;
    else 
        return odd(n-m, m);
}

int odd(int n, int m)
{   
    if (n == 1 && m == 1)
        return 1;
    if (n == 2 && m == 1)
        return 0;
    if (n == 2 && m == 2)
        return 1;
    if (m > n || m <= 0 || n <= 0)
        return 0;
    else
        return odd(n-1, m-1)+even(n-m, m);
}

int oddsum(int n)
{
    int total = 0;
    for (int i=1; i<=n; i++)
        total += odd(n, i);
    return total;
}

int diffPosi(int n, int m)
{
    if (n == 1 && m == 1)
        return 1;
    if (n == 1 && m > 1)
        return 0;
    if (m < 0)
        return 0;
    if (m == 0)
        return 1;
    return diffPosi(n-1, m) + diffPosi(n-1, m-n);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d %d %d %d\n", lessN(n, m), lessLenN(n, m), oddsum(n), diffPosi(n, n));
    return 0;
}
