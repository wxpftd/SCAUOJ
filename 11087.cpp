#include <iostream>

using namespace std;

void inline swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void mergeSortArray(int list[], int head, int mid, int tail, int tempList[], int &count)
{
    if (head < tail)
    {
        int i = head, j = mid + 1;
        int m = mid, n = tail;
        int k = 0;
        while (i <= m && j <= n)
        {
            if (list[i] <= list[j]) 
            {
                tempList[k++] = list[i++];
            }
            else
            {
                tempList[k++] = list[j++]; 
                count += m - i + 1;
            }
        }
        while (i <= m)
        {
            tempList[k++] = list[i++];
        }
        while (j <= n)
        {
            tempList[k++] = list[j++]; 
        }
        for (int i = 0; i < k; i++)
        {
            list[head+i] = tempList[i]; 
        }
    }
}

void mergeSortAction(int list[], int head, int tail, int tempList[], int &count)
{
    if (head < tail)
    {
        int mid = (head+tail)/2;
        mergeSortAction(list, head, mid, tempList, count);
        mergeSortAction(list, mid+1, tail, tempList,  count);
        mergeSortArray(list, head, mid, tail, tempList, count);
    }
}

void mergeSort(int list[], int n, int &count)
{
    int *tempList = new int[n];
    if (tempList == NULL)
        return;
    mergeSortAction(list, 0, n-1, tempList, count);
    delete tempList;
}

int main()
{
    int count = 0;
    int n = 0;
    cin >> n;
    int *list = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> list[i]; 
    }
    mergeSort(list, n, count);
    cout << count << endl;
    delete list;
    return 0;
}

