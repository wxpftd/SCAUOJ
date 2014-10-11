#include <iostream>
using namespace std;

int main()
{
    int n;
    int maxArea = 0;
    int *nums = new int[1000000];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> nums[i];
    for (int i=0; i<n; i++)
    {
        int sumLen = nums[i];
        for (int j=i-1; j>=0; j--)
        {
            if (nums[i] <= nums[j]) 
                sumLen += nums[i];
            else
                break;
        }
        for (int j=i+1; j<=n-1; j++)
        {
            if (nums[i] <= nums[j]) 
                sumLen += nums[i];
            else
                break;
        }
        if (sumLen > maxArea)
            maxArea = sumLen;
    }
    cout << maxArea << endl;

    delete nums;
    return 0;
}
