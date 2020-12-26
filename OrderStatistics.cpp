//kth SMALLEST ELEMENT

#include <iostream>
#include<climits>
using namespace std;

int getPivot(int arr[],int start,int end){
    int num=arr[end];
    int i=start;
    for(int j=start;j<=end-1;j++){
        if(arr[j]<=num){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp=arr[i];
    arr[i]=arr[end];
    arr[end]=temp;
    return i;
}

int kthSmallest(int arr[],int start,int end,int k){
    if(k>0 && k<end-start+1){
        int pivot=getPivot(arr,start,end);
        
        if(pivot-start==k-1){
            return arr[pivot];
        }
        if(pivot-start>k-1){
            return kthSmallest(arr,start,pivot-1,k);
        }
        return kthSmallest(arr,pivot+1,end,k-pivot+start-1);
    }
    return INT_MIN;
}

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
    cout<<kthSmallest(arr,0,n-1,k);
    return 0;
}

//SMALLEST ELEMENT

//A-1

#include <iostream>
#include<map>
using namespace std;

int smallestNum(int arr[],int n,int m){
    map<int,bool> mm;
    for(int i=0;i<m;i++){
        mm[i]=false;
    }
    for(int i=0;i<n;i++){
        mm[arr[i]]=true;
    }
    int ans;
    for(auto i=mm.begin();i!=mm.end();i++){
        if(i->second==false){
            ans=i->first;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    cout<<smallestNum(arr,n,m);
    return 0;
}

//A-2 OTHER CAN BE USING BINARY SEARCH


//SMALLEST AND SECOND SMALLEST

#include <iostream>
#include<map>
#include<climits>
using namespace std;

void smallestAndSecondSmallest(int arr[],int n){
    int smallest=INT_MAX;
    for(int i=0;i<n;i++){
        if(smallest>arr[i]){
            smallest=arr[i];
        }
    }
    int secondSmallest=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]!=smallest && secondSmallest>arr[i]){
            secondSmallest=arr[i];
        }
    }
    cout<<smallest<<" "<<secondSmallest<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int m;
    // cin>>m;
    smallestAndSecondSmallest(arr,n);
    return 0;
}

//KTH SMALLEST ABS DIFF

// C++ program to find k-th absolute difference 
// between two elements 
#include<bits/stdc++.h> 
using namespace std; 

// returns number of pairs with absolute difference 
// less than or equal to mid. 
int countPairs(int *a, int n, int mid) 
{ 
	int res = 0; 
	for (int i = 0; i < n; ++i) {

		// Upper bound returns pointer to position 
		// of next higher number than a[i]+mid in 
		// a[i..n-1]. We subtract (a + i + 1) from 
		// this position to count 
		res += upper_bound(a+i, a+n, a[i] + mid) - 
									(a + i + 1); 
      	cout<<res<<" ";
    }
	return res; 
} 

// Returns k-th absolute difference 
int kthDiff(int a[], int n, int k) 
{ 
	// Sort array 
	sort(a, a+n); 

	// Minimum absolute difference 
	int low = a[1] - a[0]; 
	for (int i = 1; i <= n-2; ++i) 
		low = min(low, a[i+1] - a[i]); 

	// Maximum absolute difference 
	int high = a[n-1] - a[0]; 

	// Do binary search for k-th absolute difference 
	while (low < high) 
	{ 
		int mid = (low+high)>>1; 
		if (countPairs(a, n, mid) < k) 
			low = mid + 1; 
		else
			high = mid; 
	} 

	return low; 
} 

// Driver code 
int main() 
{ 
	int k = 4; 
	int a[] = {1,5,9,20,15}; 
	int n = sizeof(a)/sizeof(a[0]); 
	kthDiff(a,n,k);
	return 0; 
} 


//KTH SMALLEST SUM PAIRS

#include <iostream>
#include<climits>
using namespace std;

void kSmallestSumPairs(int arr1[],int n1,int arr2[],int n2,int k){
    int indices[n1]={0};
    while(k--){
        int minSum=INT_MAX;
        int index=0;
        for(int i=0;i<n1;i++){
            if(indices[i]<n1 && arr1[i]+arr2[indices[i]]<minSum){
                minSum=arr1[i]+arr2[indices[i]];
                index=i;
            }
        }
        cout<<arr1[index]<<" "<<arr2[indices[index]]<<endl;
        indices[index]++;
    }
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int k;
    cin>>k;
    kSmallestSumPairs(arr1,n1,arr2,n2,k);
    return 0;
}


// K SMALLEST ELEMENTS

//A1 TIME COMP-> O(NLOGN) SPACE-> O(N)

#include <iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void kSmallest(int arr[],int n,int k){
    int temp[n];
    vector<int> ans;
    for(int i=0;i<n;i++){
        temp[i]=arr[i];
    }
    sort(temp,temp+n);
    for(int i=0;i<n;i++){
        int low=0;
        int high=k-1;
        int key=arr[i];
        while(low<=high){
            int mid=(high+low)/2;
            if(temp[mid]==key){
                ans.push_back(key);
                break;
            }
            else if(temp[mid]>key){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int k;
    cin>>k;
    kSmallest(arr1,n1,k);
    return 0;
}

//A-2 O(1) SPACE COMPLEXITY

#include <iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void kSmallest(int arr[],int n,int k){
    
    for(int i=k;i<n;i++){
        int maxEle=INT_MIN;
        int index=-1;
        for(int j=0;j<k;j++){
            if(maxEle<arr[j]){
                maxEle=arr[j];
                index=j;
            }
        }
        if(maxEle>arr[i]){
            int j=index;
            while(j<k-1){
                arr[j]=arr[j+1];
                j++;
            }
            arr[k-1]=arr[i];
        }
    }
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int k;
    cin>>k;
    kSmallest(arr1,n1,k);
    return 0;
}

// K MAX SUMS OF NON-OVERLAPPING SUB ARRAYS

//APPROACH- USING KADANE ALGO K TIMES

#include <iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void kSmallest(vector<int> v,int k){
    
    while(k--){
        int maxSum=INT_MIN;
        int sum=0;
        int start=0;
        int end=0;
        int index=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(maxSum<sum){
                maxSum=sum;
                start=index;
                end=i;
            }
            if(sum<=0){
                sum=0;
                index=i+1;
            }
        }
        cout<<"Max sum - "<<maxSum<<" "<<"Starting Index - "<<start<<" "<<"Ending index - "<<end<<endl;
        for(int i=start;i<=end;i++){
            v[i]=INT_MIN;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    int k;
    cin>>k;
    kSmallest(v,k);
    return 0;
}

//MAX SUB ARRAY SUM USING PREFIX SUM

#include <iostream>
#include<climits>
using namespace std;

int maxSubArraySumByPrefixSum(int arr[],int n){
    int prefix[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    int minSum=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,prefix[i]-minSum);
        minSum=min(minSum,prefix[i]);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSubArraySumByPrefixSum(arr,n);
    return 0;
}


//GREATER ELEMENT

#include <iostream>
#include<climits>
#include<stack>
using namespace std;

//UNORDERED FORM 
int nextGreaterU(int arr[],int n){
    stack<int> s;
    s.push(arr[0]);
    
    for(int i=1;i<n;i++){
        
        while(!s.empty() && s.top()<arr[i]){
            cout<<s.top()<<" modifies to "<<arr[i]<<endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while(!s.empty()){
        cout<<s.top()<<" modifies to "<<-1<<endl;
        s.pop();
    }
}

//ORDERED FORM
void nextGreaterO(int arr[],int n){
    stack<int> s;
    
    int temp[n];
    
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()<=arr[i]){
            s.pop();
        }
        
        if(!s.empty()){
            temp[i]=s.top();
        }else{
            temp[i]=-1;
        }
        
        s.push(arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" modifies to "<<temp[i]<<endl;
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
    // nextGreater(arr,n);
    nextGreaterO(arr,n);
    return 0;
}

//MIN ELEMENTS TO GET REQ MEDIAN X

#include <iostream>
#include<climits>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

// O(knlogn)
int minElementsToGetReqMedian(int arr[],int n,int x){
    sort(arr,arr+n);
    int count=0;
    for(int i=0;arr[(n-1)/2]!=x;i++){
        arr[n++]=x;
        count++;
        sort(arr,arr+n);
    }
    return count;
}

// O(n)
int minElementsToGetReqMedian1(int arr[],int n,int x){
    int less=0,more=0,equal=0;
    for(int i=0;i<n;i++){
        if(arr[i]<x){
            less++;
        }
        else if(arr[i]>x){
            more++;
        }
        else{
            equal++;
        }
    }
    if(less>more){
        return less-more+1-equal;
    }
    else{
        return more-less+1-equal;
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
    int x;
    cin>>x;
    // cout<<minElementsToGetReqMedian(arr,n,x);
    cout<<minElementsToGetReqMedian1(arr,n,x);
    return 0;
}

//MAX DIFF

#include <iostream>
#include<climits>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int arr[],int n,int k){
    sort(arr,arr+n);
    
    int sum1=0;
    int sum2=0,count=0;
    for(int i=0;i<n;i++){
        if(count<k){
            sum2+=arr[i];
        }
        else{
            sum1+=arr[i];
        }
        count++;
    }
    int diff1=abs(sum1-sum2);
    sum1=0;
    sum2=0;
    int t=n-k;
    count=0;
    for(int i=0;i<n;i++){
        if(count<t){
            sum1+=arr[i];
        }
        else{
            sum2+=arr[i];
        }
        count++;
    }
    int diff2=abs(sum1-sum2);
    
    return max(diff1,diff2);
}

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
    cout<<maxDiff(arr,n,k);
    return 0;
}

//COUNT STRICTLY INCREASING SUB ARRAYS

#include <iostream>
#include<climits>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int countSubArraysStricInc1(int arr[],int n){
    int count=0;
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[j-1]){
                count++;
            }
            else{
                break;
            }
        }
    }
    return count;
}

int countSubArraysStricInc2(int arr[],int n){
    int count=1;
    int ans=0;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]>arr[i]){
            count++;
        }
        else{
            ans+=((count-1)*count)/2;
            count=1;
        }
    }
    if(count>1){
        ans+=((count-1)*count)/2;
        count=1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<countSubArraysStricInc1(arr,n);
    cout<<countSubArraysStricInc2(arr,n);
    return 0;
}

//ZEROES TO BE FILLED

#include <iostream>
#include<climits>
#include<stack>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int flipZeros(int arr[],int n,int m){
    int leftWindow=0;
    int rightWindow=0;
    int bestLeft=0;
    int bestWindow=0;
    int zeroes=0;
    
    for(int i=0;i<n;i++){
        if(zeroes<=m){
            if(arr[rightWindow]==0){
                zeroes++;
            }
            rightWindow++;
        }
        
        if(zeroes>m){
            if(arr[leftWindow]==0){
                zeroes--;
            }
            leftWindow++;
        }
        
        if(rightWindow-leftWindow>bestWindow && zeroes<=m){
            bestWindow=rightWindow-leftWindow;
            bestLeft=leftWindow;
        }
    }
    for(int i=0;i<bestWindow;i++){
        if(arr[bestLeft+i]==0){
            cout<<bestLeft+i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m;
    cin>>m;
    flipZeros(arr,n,m);
    return 0;
}

//DELETE ARRAY ELEMENTS WHICH ARE SMALLER THAN THE NEXT

//A-1

#include <iostream>
#include<climits>
#include<stack>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void deleteElements(int arr[],int n,int k){
    int i=0;
    int j=i+1;
    while(k){
        while(arr[i]<arr[j] && k){
            for(int k=i;k<n-1;k++){
                arr[k]=arr[k+1];
            }
            n--;
            k--;
            i=0;
            j=1;
        }
        i++;
        j++;
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
    int k;
    cin>>k;
    deleteElements(arr,n,k);
    return 0;
}

//A-2 USING STACK

// C++ program to delete elements from array. 
#include <bits/stdc++.h> 
using namespace std; 

// Function for deleting k elements 
void deleteElements(int arr[], int n, int k) 
{ 
	// Create a stack and push arr[0] 
	stack<int> s; 
	s.push(arr[0]); 

	int count = 0; 
	
	// traversing a loop from i = 1 to n 
	for (int i=1; i<n; i++) { 
		
		// condition for deleting an element 
		while (!s.empty() && s.top() < arr[i] 
							&& count < k) {									 
			s.pop(); 
			count++; 
		} 
		
		s.push(arr[i]); 
	} 
	
	// Putting elements of stack in a vector 
	// from end to begin. 
	int m = s.size(); 
	vector<int> v(m); // Size of vector is m 
	while (!s.empty()) { 
		
		// push element from stack to vector v 
		v[--m] = s.top(); 
		s.pop(); 
	} 
	
	// printing result 
	for (auto x : v) 
		cout << x << " "; 
		
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int n = 5, k = 2; 
	int arr[] = {20, 10, 25, 30, 40}; 
	deleteElements(arr, n, k); 
	return 0; 
} 

//SMALLEST GREATER ELEMENT

#include <iostream>
#include<set>
using namespace std;

void smallestGreaterElement(int arr[],int n){
    set<int> s;
    
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    
    for(int i=0;i<n;i++){
        auto ii=s.end();
        --ii;
        if(arr[i]==*ii){
            arr[i]=-1;
            cout<<arr[i]<<" ";
            continue;
        }
        auto it=s.upper_bound(arr[i]);
        arr[i]=*it;
        cout<<arr[i]<<" ";
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
    smallestGreaterElement(arr,n);
    return 0;
}

//MAX SUM PATH

#include <iostream>
#include<set>
using namespace std;

int maxSumPath(int arr1[],int n1,int arr2[],int n2){
    int sum1=0;
    int sum2=0;
    int ans=0;
    
    int i,j;
    i=j=0;
    
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            sum1+=arr1[i++];
        }
        else if(arr1[i]>arr2[j]){
            sum2+=arr2[j++];
        }
        else{
            ans+=max(sum1,sum2);
            
            int k=i;
            sum1=0;
            sum2=0;
            while(i<n1 && arr1[i]==arr2[j]){
                sum1+=arr1[i++];
            }
            while(j<n2 && arr1[k]==arr2[j]){
                sum2+=arr2[j++];
            }
            ans+=max(sum1,sum2);
            sum1=sum2=0;
        }
    }
    while(i<n1){
        sum1+=arr1[i++];
    }
    while(j<n2){
        sum2+=arr2[j++];
    }
    ans+=max(sum1,sum2);
    
    return ans;
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    cout<<maxSumPath(arr1,n1,arr2,n2);
    return 0;
}

//LIS WITH MAX PROD OF LENGTH 3

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int LISWithMaxProd(int arr[],int n){
    int a[n];
    int b[n];
    int smaller,greater;
    for(int i=0;i<n;i++){
        smaller=-1;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i] && smaller<arr[j]){
                smaller=arr[j];
            }
        }
        a[i]=smaller;
        greater=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i] && greater<arr[j]){
                greater=arr[j];
            }
        }
        b[i]=greater;
    }
    int prod=-1;
    for(int i=0;i<n;i++){
        if(a[i]==-1 || b[i]==-1){
            continue;
        }
        prod=max(prod,a[i]*arr[i]*b[i]);
    }
    return prod;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<LISWithMaxProd(arr,n)<<endl;
    return 0;
}

//SMALLEST POS IN UNSORTED ARRAY

//A-1

/* C++ program to find the smallest positive missing number */
#include <bits/stdc++.h>
using namespace std;

/* Utility to swap to integers */
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

/* Utility function that puts all 
non-positive (0 and negative) numbers on left 
side of arr[] and return count of such numbers */
int segregate(int arr[], int size)
{
	int j = 0, i;
	for (i = 0; i < size; i++) {
		if (arr[i] <= 0) {
			swap(&arr[i], &arr[j]);
			j++; // increment count of non-positive integers
		}
	}

	return j;
}

/* Find the smallest positive missing number 
in an array that contains all positive integers */
int findMissingPositive(int arr[], int size)
{
	int i;

	// Mark arr[i] as visited by making arr[arr[i] - 1] negative.
	// Note that 1 is subtracted because index start
	// from 0 and positive numbers start from 1
	for (i = 0; i < size; i++) {
		if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0)
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
	}

	// Return the first index value at which is positive
	for (i = 0; i < size; i++)
		if (arr[i] > 0)
			// 1 is added because indexes start from 0
			return i + 1;

	return size + 1;
}

/* Find the smallest positive missing 
number in an array that contains 
both positive and negative integers */
int findMissing(int arr[], int size)
{
	// First separate positive and negative numbers
	int shift = segregate(arr, size);

	// Shift the array and call findMissingPositive for
	// positive part
	return findMissingPositive(arr + shift, size - shift);
}

// Driver code
int main()
{
	int arr[] = { 0, 10, 2, -10, -20 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	int missing = findMissing(arr, arr_size);
	cout << "The smallest positive missing number is " << missing;
	return 0;
}

// This is code is contributed by rathbhupendra

//A-2 USING HASHING


//FIND MAX ELEMENT IN ARRAY WHICH IS FIRST INC THEN DEC

//A-1 USING LINEAR SEARCH

//A-2 USING BINARY SEARCH - - -  IF MID IS GREATER THAN LEFT AND GREATER THAN RIGHT, THEN MID IS MAX.... ELSE IF MID IS GREATER THAN LEFT AND SMALLER THAN RIGHT, THEN MAX LIES ON RIGHT SIDE OF MID.... ELSE IF MID IS SMALLER THAN LEFT AND GREATER THAN RIGHT, THEN MAX LIES ON THE LEFT OF MID


//MIN DIST

#include <iostream>
#include<vector>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minDist(int arr[],int n,int x,int y){
    int ans=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x || arr[i]==y){
            if(index!=-1 && arr[index]!=arr[i]){
                int dist=i-index;
                ans=min(ans,dist);
            }
            index=i;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int x,y;
    cin>>x>>y;
    cout<<minDist(arr,n,x,y)<<endl;
    return 0;
}


//SLIDING WINDOW

#include <iostream>
#include<vector>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void slidingWindow(int arr[],int n,int k){
    // vector<int> ans;
    for(int i=0;i<n-k+1;i++){
        int res=-1;
        for(int j=i;j<i+k;j++){
            res=max(res,arr[j]);
        }
        cout<<res<<" ";
    }
    cout<<endl;
}

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
    slidingWindow(arr,n,k);
    return 0;
}

//MAX DIFF

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int arr[],int n){
    vector<int> temp(n+1,INT_MIN);
    
    for(int i=n-1;i>=0;i--){
        temp[i]=max(arr[i],temp[i+1]);
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        int low=i+1;
        int high=n-1;
        int res=i;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[i]<temp[mid]){
                res=max(res,mid);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        ans=max(ans,res-i);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiff(arr,n);
    return 0;
}

//MAX DIFF BW NUMBERS SUCH THAT LARGER COMES AFTER SMALLER

//A-1

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiffBwNums(int arr[],int n){
    vector<int> temp(n+1,INT_MIN);
    
    for(int i=n-1;i>=0;i--){
        temp[i]=max(arr[i],temp[i+1]);
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        int low=i+1;
        int high=n-1;
        int diff=INT_MIN;
        while(low<=high){
            int mid=(low+high)/2;
            if(temp[mid]-arr[i]>diff){
                diff=max(diff,temp[mid]-arr[i]);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        ans=max(ans,diff);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiffBwNums(arr,n);
    return 0;
}


//A-2

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiffBwNums(int arr[],int n){
    int minEle=arr[0];
    int diff=arr[1]-arr[0];
    
    for(int i=1;i<n;i++){
        if(arr[i]-minEle>diff){
            diff=arr[i]-minEle;
        }
        minEle=min(minEle,arr[i]);
    }
    return diff;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiffBwNums(arr,n);
    return 0;
}

//A-3

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiffBwNums(int arr[],int n){
    int diff=arr[n-1]-arr[n-2];
    int maxEle=arr[n-1];
    
    for(int i=n-2;i>=0;i--){
        maxEle=max(maxEle,arr[i]);
        diff=max(diff,maxEle-arr[i]);
    }
    return diff;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiffBwNums(arr,n);
    return 0;
}

//A-4

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiffBwNums(int arr[],int n){
    int diff[n-1];
    for(int i=0;i<n-1;i++){
        diff[i]=arr[i+1]-arri[i];
    }
    int maxDiff=diff[0];
    for(int i=1;i<n-1;i++){
        if(diff[i-1]>0){
            diff[i]+=diff[i-1];
        }
        else{
            maxDiff=diff[i];
        }
    }
    return maxDiff;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiffBwNums(arr,n);
    return 0;
}

//A-5

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxDiffBwNums(int arr[],int n){
    int diff=arr[1]-arr[0];
    int sum=diff;
    int ans=sum;
    
    for(int i=1;i<n-1;i++){
        diff=arr[i+1]-arr[i];
        
        if(sum>0){
            sum+=diff;
        }
        else{
            sum=diff;
        }
        ans=max(ans,sum);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxDiffBwNums(arr,n);
    return 0;
}

//GENERATE SUBARRAYS AND SUBSEQUENCES WITHOUT RECURSION

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//GET ALL SUBARRAYS WITHOUT RECURSION
void findSubArrays(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
}

//GET ALL SUBSEQUENCES WITH RECURSION
void findSubSeq(int arr[],int n){
    int num=pow(2,n);
    
    for(int i=1;i<num;i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
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
    // findSubArrays(arr,n);
    findSubSeq(arr,n);
    return 0;
}


//KTH LARGEST SUM VALUES IN 2 ARRAYS

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void kthLargestSumPairs(int arr1[],int n1,int arr2[],int n2,int k){
    int indices[n1]={0};
    while(k--){
        int sum=INT_MIN;
        int index;
        for(int i=0;i<n1;i++){
            if(indices[i]<n2 && arr1[i]+arr2[indices[i]]>sum){
                sum=arr1[i]+arr2[indices[i]];
                index=i;
            }
        }
        cout<<arr1[index]<<" "<<arr2[indices[index]]<<endl;
        indices[index]++;
    }
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    int n2;
    cin>>n2;
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    int k;
    cin>>k;
    kthLargestSumPairs(arr1,n1,arr2,n2,k);    
    return 0;
}


