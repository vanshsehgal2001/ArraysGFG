#include <iostream>
#include<vector>
using namespace std;

vector<int> sortByOrder(vector<int> arr){
    int zeroes=0;
    int ones=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            zeroes++;
        }
        else if(arr[i]==1){
            ones++;
        }
    }
    vector<int> output;
    for(int i=0;i<zeroes;i++){
        output.push_back(0);
    }
    for(int i=0;i<ones;i++){
        output.push_back(1);
    }
    for(int i=0;i<(arr.size()-zeroes-ones);i++){
        output.push_back(2);
    }
    return output;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i=0;i<n;i++){
	        int a;
	        cin>>a;
	        arr.push_back(a);
	    }
	    vector<int> ans=sortByOrder(arr);
	    for(int i=0;i<ans.size();i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
