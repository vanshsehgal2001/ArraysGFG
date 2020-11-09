#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class MinMax
{
public:
    int min;
    int max;
};

//SIMPLE ITERATIVE O(n)
MinMax minMax1(int arr[], int n)
{
    MinMax p;

    if (n == 1)
    {
        p.max = arr[0];
        p.min = arr[1];
        return p;
    }

    if (arr[0] > arr[1])
    {
        p.max = arr[0];
        p.min = arr[1];
    }
    else
    {
        p.max = arr[1];
        p.min = arr[0];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > p.max)
        {
            p.max = arr[i];
        }
        if (arr[i] < p.min)
        {
            p.min = arr[i];
        }
    }
    return p;
}

//RECURSIVELY... O(n) but if n is a power of 2 then less comparisons as commpared to if n is not a power of 2
MinMax minMax2(int arr[], int start, int end)
{
    MinMax p;

    if (start == end)
    {
        p.max = arr[start];
        p.min = arr[start];
        return p;
    }

    if (end - start == 1)
    {
        if (arr[start] > arr[end])
        {
            p.max = arr[start];
            p.min = arr[end];
        }
        else
        {
            p.max = arr[end];
            p.min = arr[start];
        }
        return p;
    }
    int mid = (start + end) / 2;
    MinMax leftPair = minMax2(arr, start, mid);
    MinMax rightPair = minMax2(arr, mid + 1, end);

    MinMax ans;
    ans.max = max(leftPair.max, rightPair.max);
    ans.min = min(leftPair.min, rightPair.min);
    return ans;
}

//BEST O(n)
MinMax minMax3(int arr[], int n)
{
    MinMax p;
    int i;
    if (n % 2 != 0)
    {
        p.max = arr[0];
        p.min = arr[0];
        i = 1;
    }
    else
    {
        if (arr[0] > arr[1])
        {
            p.max = arr[0];
            p.min = arr[1];
        }
        else
        {
            p.max = arr[1];
            p.min = arr[0];
        }
        i = 2;
    }
    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > p.max)
            {
                p.max = arr[i];
            }
            if (arr[i + 1] < p.min)
            {
                p.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > p.max)
            {
                p.max = arr[i + 1];
            }
            if (arr[i] < p.min)
            {
                p.min = arr[i];
            }
        }
        i=i+2;
    }
    return p;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    MinMax t;
    // t=minMax1(arr,n);
    // t=minMax2(arr,0,n-1);
    t = minMax3(arr, n);
    cout << "Max element is: " << t.max << endl;
    cout << "Min element is: " << t.min << endl;
    return 0;
}
