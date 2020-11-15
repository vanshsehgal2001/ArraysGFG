#include <iostream>
using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n,x;
// 	    cin>>n>>x;
// 	    int arr[n];
// 	    for(int i=0;i<n;i++){
// 	        cin>>arr[i];
// 	    }
	    
// 	    int finalLength=n+1;
// 	    int sum=0;
// 	    for(int start=0;start<n;start++){
// 	        sum=arr[start];
// 	        if(sum>x){
// 	            finalLength=1;
// 	            break;
// 	        }
// 	        for(int end=start+1;end<n;end++){
// 	            sum=sum+arr[end];
// 	            if(sum>x && (end-start+1)<finalLength){
// 	                finalLength=end-start+1;
// 	            }
// 	        }
// 	    }
// 	    cout<<finalLength<<endl;
// 	}
// 	return 0;
// }

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int finalLength=n+1;
        int sum=0;
        int start=0;
        int end=0;
        while(end<n){
            while(sum<=x && end<n){
                sum=sum+arr[end];
                end++;
            }
            while(sum>x && start<n){
                if(end-start<finalLength){
                    finalLength=end-start;
                }
                sum=sum-arr[start];
                start++;
            }
        }
        cout<<finalLength<<endl;
    }
	return 0;
}
