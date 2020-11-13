#include <iostream>

using namespace std;

int getMedian1(int arr1[],int arr2[],int n1,int n2){
    int size=n1+n2;
    int arr3[size];
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        else if(arr1[i]>arr2[j]){
            arr3[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr3[k++]=arr1[i++];
    }
    while(j<n2){
        arr3[k++]=arr2[j++];
    }
    for(int i=0;i<size;i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    int mid=size/2;
    return arr3[mid];
}

int getMedian2(int arr1[],int arr2[],int n1,int n2){
    int i=0;
    int j=0;
    int median1=-1;
    int median2=-1;
    int size=n1+n2;
    if(size%2!=0){
        for(int k=0;k<=size/2;k++){
            if(i<n1 && j<n2){
                median1=arr1[i]<=arr2[j]?arr1[i++]:arr2[j++];
            }
            else if(i<n1){
                median1=arr1[i++];
            }else if(j<n2){
                median1=arr2[j++];
            }
        }
        return median1;
    }
    else{
        for(int k=0;k<=size/2;k++){
            median2=median1;
            if(i<n1 && j<n2){
                median1=arr1[i]<=arr2[j]?arr1[i++]:arr2[j++];
            }
            else if(i<n1){
                median1=arr1[i++];
            }else if(j<n2){
                median1=arr2[j++];
            }
        }
        return (median1+median2)/2;
    }
}

int main()  
{  
    int n1,n2;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    // cout<<getMedian1(arr1,arr2,n1,n2);
    cout<<getMedian2(arr1,arr2,n1,n2);
    return 0;  
}  
