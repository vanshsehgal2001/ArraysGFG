#include <iostream>
using namespace std;

//NO LOGIC BUT JUST REVERSE PRINTING THE ARRAY
void reverseArray1(int *arr,int n){
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//ITERATIVE WAY
void reverseArray2(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

//RECURSIVELY REVERSE PRINTING ARRAY
void reverseArray3(int arr[],int n){
    if(n==0){
        return;
    }
    reverseArray3(arr+1,n-1);
    cout<<arr[0]<<" ";
}

//RECURSIVELY MAKING CHANGES TO ARRAY AND THEN PRINTING
void reverseArray4(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    reverseArray4(arr,start+1,end-1);
}


int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // reverseArray1(arr,n);
    
    // reverseArray2(arr,n);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    
    //reverseArray3(arr,n);
    
    reverseArray4(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
