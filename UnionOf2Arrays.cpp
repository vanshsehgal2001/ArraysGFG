#include <iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
    	cin>>n1>>n2;
    	vector<int> a(n1);
    	vector<int> b(n2);
    	for(int i=0;i<n1;i++){
    	    cin>>a[i];
    	}
    	for(int i=0;i<n2;i++){
    	    cin>>b[i];
    	}
    	for(int i=0;i<n2;i++){
    	    a.push_back(b[i]);
    	}
    	set<int> s;
    	for(int i=0;i<a.size();i++){
    	    s.insert(a[i]);
    	}
    	cout<<s.size()<<endl;
	}
	return 0;
}
