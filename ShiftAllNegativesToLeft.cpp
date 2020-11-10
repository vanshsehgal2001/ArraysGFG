#include <iostream>
using namespace std;

//ITS LIKE FINDING PIVOT IN QUICKSORT
void shiftNegativesToLeft1(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
            j++;
        }
    }
}

//MAKING 2 POINTERS AND THEN ACCORDINGLY CHECKING FOR CONDITIONS
void shiftNegativesToLeft2(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        if(arr[start]<0 && arr[end]<0){
            start++;
        }
        else if(arr[start]>0 && arr[end]<0){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        else if(arr[start]>0 && arr[end]>0){
            end--;
        }
        else{
            start++;
            end--;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // shiftNegativesToLeft1(arr,n);
    shiftNegativesToLeft2(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
