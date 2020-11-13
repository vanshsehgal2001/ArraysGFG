#include<climits>
#include <iostream>
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
	    int k;
	    cin>>k;
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]<=k){
	            count++;
	        }
	    }
	    int cnt=0;
	    int ans=INT_MAX;
	    for(int i=0;i<=n-count;i++){
	        cnt=0;
	        for(int j=i;j<count+i;j++){
	            if(arr[j]>k){
	                cnt++;
	            }
	        }
	        ans=min(cnt,ans);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
