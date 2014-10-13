#include <iostream>
using namespace std;

int fun(int Total[], int n)
{
    if (Total[n] != 0)
        return Total[n];
    int total = 0;
    for (int i=2; i<=n-1; i++)
    {
        int front = i, back = n+1-i;
        if (Total[front] == 0)
            Total[front] = fun(Total, front);
        if (Total[back] == 0)
            Total[back] = fun(Total, back);
        total += Total[front] * Total[back];
    }
    return total;
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n < 3)
    {
        printf("No answer\n"); 
        return 0;
    }
    int Total[50]{0};
    Total[3] = 1;
    Total[2] = 1;
    int total = 0;
    total = fun(Total, n);
    printf("%d\n", total);
    return 0;
}
