#include <iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    int m;
	    cin>>m;
	    if(m==0||n==0){
	        return 0;
	    }
	    sort(arr,arr+n);
	    if(m>n){
	        return -1;
	    }
	    int ans=INT_MAX;
	    for(int i=0;i+m-1<n;i++){
	        int temp=arr[i+m-1]-arr[i];
	        if(ans>temp){
	            ans=temp;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
