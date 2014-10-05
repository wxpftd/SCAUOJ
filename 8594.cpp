#include <iostream>

using namespace std;

void swap(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
}

void sortchar(char list[], int n)
{
    for (int i=1; i<n; i++)  
    {
        for (int j=i; j>0 && list[j] < list[j-1]; j--)  
        {
            swap(list[j], list[j-1]); 
        }
    }
}

bool Findsame(char list[], int k, int m)
{
    for (int i=k; i<m; i++)
    {
        if (list[m] == list[i]) 
            return true;
    }
    return false;
}

void permpp(char list[], int k, int m, int &count)
{
    int i;
    if (k == m)
    {
        for (i=1; i<=m; i++) 
        {
            cout << list[i]; 
        }
        cout << endl;
        count++;
    }
    else
    {
        for (i=k; i<=m; i++) 
        {
            if (Findsame(list, k, i))
                continue;
            swap(list[k], list[i]); 
            permpp(list, k+1, m, count);
            swap(list[k], list[i]);
        }
    }
}

int main()
{
    int n(0);
    char list[20];
    int count = 0;
    cin >> n;
    for (int i=1; i <= n; i++)
    {
        cin >> list[i];
    }
    //sortchar(list, n);
    permpp(list, 1, n, count);
    cout << count << endl;
    return 0;
}
