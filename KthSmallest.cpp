//IMPLEMENTED USING SIMPLE sort FUNCTION. BUT CAN ALSO BE SOLVED USING HEAP SORT(MIN AND MAX HEAP) TO OPTIMISE TIME COMPLEXITY FROM O(nlogn)

#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    sort(arr,arr+n);
    cout<<arr[k-1]<<endl;
    return 0;
}
