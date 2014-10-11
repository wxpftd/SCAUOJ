#include <iostream>
using namespace std;

int main()
{
    int n;
    int maxlen = 0, len = 0;
    int num;
    int *nums = new int[1000000];
    cin >> n;
    for (int i=0; i<n; i++)  
    {
        cin >> nums[i];
        if (nums[i] < 0)
            nums[i] = -nums[i];
    }
    for (int i=n-1; i>0; i--)
    {
        if (nums[i] >= nums[i-1]) 
            nums[i-1] = nums[i];
    }
    for (int i=0; i<n; i++)
    {
        if (nums[i] == num)
            ++len;
        else
        {
            if (len > maxlen)
            {
                maxlen = len; 
            }
            len = 1;
            num = nums[i];
        }
        if (i == n-1)
            if (len > maxlen) 
                maxlen = len;
    }
    cout << maxlen << endl;
    delete nums;
    return 0;
}
