//ROTATE ARRAY BY K AMOUNT

//APPROACH-1 CAN BE LIKE USING 2 LOOPS WHERE OUTER IS FOR NO OF ROTATIONS AND INNER FOR SWAPPING OR SHIFTING....

//OTHER CAN BE USED A TEMP ARRAY AND DIVIDING THE ARRAY WITH K AS A PIVOT AND SEPARATELY USING THE ARRAYS FOR GETTING RESULT

//A-3 IS USING JUGGLING ARRAY APPROACH WHERE WE FORM SETS... NO OF SETS EQUAL THE GCD OF N AND K AND THEN SHIFTING THE ELEMENTS BY K AMOUNT APT.

	#include <iostream>

	using namespace std;

	int GCD(int a,int b){
	    if(b==0){
		return a;
	    }
	    return GCD(b,a%b);
	}

	void rotate1(int arr[],int n,int d){
	    d=d%n;
	    int gcd=GCD(d,n);
	    for(int i=0;i<gcd;i++){
		int temp=arr[i];
		int j=i;
		 while (1) { 
            		int k = j + d; 
            		if (k >= n) 
                	k = k - n; 
  
            		if (k == i) 
                	break; 
  
            	arr[j] = arr[k]; 
            	j = k; 
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
	    int k;
	    cin>>k;
	    rotate1(arr,n,k);
	    for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    return 0;
	}

//OTHER APPROACH CAN BE REVERSING THE ARRAY INTO SEVERAL PARTS... LIKE FIRST REVERSING 1 TO K PART OF ARRAY.. THEN REVERSING K+1 TO N PART AND THEN REVERSING ARRAY AS A WHOLE




//SEARCH ELEMENT IN A ROTATED AND A SORTED ARRAY

//A-1
#include <iostream>

using namespace std;

int binarySearch(int arr[],int start,int end,int key){
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return start;
}

int findPivot(int arr[],int start,int end){
    // if(start>end){
    //     return -1;
    // }
    if(start==end){
        return start;
    }
    int mid=(start+end)/2;
    if(mid>start && arr[mid-1]>arr[mid]){
        return mid-1;
    }
    if(mid<end && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(arr[start]>=arr[mid]){
        return findPivot(arr,start,mid-1);
    }
    return findPivot(arr,mid+1,end);
}

int rotate2(int arr[],int n,int key){
    int pivot=findPivot(arr,0,n-1);
    if(pivot==-1){
        return binarySearch(arr,0,n-1,key);
    }
    if(arr[pivot]==key){
        return pivot;
    }
    if(arr[0]<=key){
        return binarySearch(arr,0,pivot-1,key);
    }
    return binarySearch(arr,pivot+1,n-1,key);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<rotate2(arr,n,key);
    cout<<endl;
    return 0;
}

//A-2 USING ONLY 1 RECUSRIVE CALL OF BINARY SEARCH
#include <iostream>

using namespace std;

int rotate3(int arr[],int start,int end,int key){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[start]<=arr[mid]){
        if(key>=arr[start] && arr[mid]>=key){
            return rotate3(arr,start,mid-1,key);
        }
        return rotate3(arr,mid+1,end,key);
    }
    if(key>=arr[mid] && key<=arr[end]){
        return rotate3(arr,mid+1,end,key);
    }
    return rotate3(arr,start,mid-1,key);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<rotate3(arr,0,n-1,key);
    cout<<endl;
    return 0;
}

//MAX SUM (i*arr[i]) ARRAY ROTATIONS

#include <iostream>
using namespace std;

int maxSum(int arr[],int n){
    int curr=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        curr+=i*arr[i];
    }
    int maxsum=curr;
    for(int j=1;j<n;j++){
        curr+=sum-n*arr[n-j];
        maxsum=max(maxsum,curr);
    }
    return maxsum;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxSum(arr,n);
    cout<<endl;
    return 0;
}

//FIND HOW MANY ROTATIONS REQ TO GET SORTED ARRAY

#include <iostream>
using namespace std;

//SIMPLE COUNTING
int countRotations1(int arr[],int n){
    int count=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            break;
        }
        count++;
    }
    return count;
}

//SIMILAR TO FINDING PIVOT
int helper(int arr[],int start,int end){
    if(start>end){
        return -1;
    }
    if(start==end){
        return end;
    }
    int mid=(start+end)/2;
    if(mid<end && arr[mid]>arr[mid+1]){
        return mid+1;
    }
    if(mid>start && arr[mid]<arr[mid-1]){
        return mid;
    }
    if(arr[end]>arr[mid]){
        return helper(arr,start,mid-1);
    }
    else{
        return helper(arr,mid+1,end);
    }
}

int countRotations2(int arr[],int n){
    return helper(arr,0,n-1);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<countRotations1(arr,n);
    cout<<countRotations2(arr,n);
    cout<<endl;
    return 0;
}

//FIND ELEMENT AFTER N ROTATIONS

#include <bits/stdc++.h> 
using namespace std; 
  
// Function to compute the element at 
// given index 
int findElement(int arr[], int ranges[][2], 
               int rotations, int index) 
{ 
    for (int i = rotations - 1; i >= 0; i--) { 
  
        // Range[left...right] 
        int left = ranges[i][0]; 
        int right = ranges[i][1]; 
  
        // Rotation will not have any effect 
        if (left <= index && right >= index) { 
            if (index == left) 
                index = right; 
            else
                index--; 
        } 
    } 
  
    // Returning new element 
    return arr[index]; 
} 
  
// Driver 
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5 }; 
  
    // No. of rotations 
    int rotations = 2; 
  
    // Ranges according to 0-based indexing 
    int ranges[rotations][2] = { { 0, 2 }, { 0, 3 } }; 
  
    int index = 1; 
  
    cout << findElement(arr, ranges, rotations, index); 
  
    return 0; 
  
} 

//MAX DIAGONAL SUM BY ROTATING ROWS COLUMNS BY A +VE INTEGER

#include<climits>
#include <iostream>
using namespace std;

int maxDiagonalSum(int mat[3][3]){
    int ans=INT_MIN;
    int curr=0;
    for(int i=0;i<3;i++){
        curr=0;
        for(int j=0;j<3;j++){
            curr+=mat[j][(i+j)%3];
        }
        ans=max(ans,curr);
    }
    for(int i=0;i<3;i++){
        curr=0;
        for(int j=0;j<3;j++){
            curr+=mat[(i+j)%3][j];
        }
        ans=max(ans,curr);
    }
    return ans;
}

int main()
{
     
    int mat[3][3] = { { 1, 1, 2 }, 
                    { 2, 1, 2 }, 
                    { 1, 2, 2 } };
     
    cout<< maxDiagonalSum(mat);
    return 0;
}

//GEN MATRIX WHERE SUM OF ELEMENTS OF SECOND DIAGONAL IS PERFECT SQUARE

#include<climits>
#include <iostream>
using namespace std;

void generateMat(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[(i+j)%n]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    generateMat(arr,n);
    return 0;
}

//QUERIES TO BE PERFORMED FOR ROTATING ARRAY AND CONTIGUOUS MAX SUM SUBARRAY

// C++ program for the above approach 

#include <bits/stdc++.h> 
using namespace std; 

// Function to calculate the maximum 
// sum of length k 
int MaxSum(vector<int> arr, int n, 
		int k) 
{ 
	int i, max_sum = 0, sum = 0; 

	// Calculating the max sum for 
	// the first k elements 
	for (i = 0; i < k; i++) { 
		sum += arr[i]; 
	} 
	max_sum = sum; 

	// Find subarray with maximum sum 
	while (i < n) { 

		// Update the sum 
		sum = sum - arr[i - k] + arr[i]; 
		if (max_sum < sum) { 
			max_sum = sum; 
		} 
		i++; 
	} 

	// Return maximum sum 
	return max_sum; 
} 

// Function to calculate gcd of the 
// two numbers n1 and n2 
int gcd(int n1, int n2) 
{ 
	// Base Case 
	if (n2 == 0) { 
		return n1; 
	} 

	// Recursively find the GCD 
	else { 
		return gcd(n2, n1 % n2); 
	} 
} 

// Function to rotate the array by Y 
vector<int> RotateArr(vector<int> arr, 
					int n, int d) 
{ 
	// For handling k >= N 
	int i = 0, j = 0; 
	d = d % n; 

	// Dividing the array into 
	// number of sets 
	int no_of_sets = gcd(d, n); 

	for (i = 0; i < no_of_sets; i++) { 

		int temp = arr[i]; 
		j = i; 

		// Rotate the array by Y 
		while (true) { 

			int k = j + d; 

			if (k >= n) 
				k = k - n; 

			if (k == i) 
				break; 

			arr[j] = arr[k]; 
			j = k; 
		} 

		// Update arr[j] 
		arr[j] = temp; 
	} 

	// Return the rotated array 
	return arr; 
} 

// Function that performs the queries 
// on the given array 
void performQuery(vector<int>& arr, 
				int Q[][2], int q) 
{ 

	int N = (int)arr.size(); 

	// Traverse each query 
	for (int i = 0; i < q; i++) { 

		// If query of type X = 1 
		if (Q[i][0] == 1) { 

			arr = RotateArr(arr, N, 
							Q[i][1]); 

			// Print the array 
			for (auto t : arr) { 
				cout << t << " "; 
			} 
			cout << "\n"; 
		} 

		// If query of type X = 2 
		else { 
			cout << MaxSum(arr, N, Q[i][1]) 
				<< "\n"; 
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	// Given array arr[] 
	vector<int> arr = { 1, 2, 3, 4, 5 }; 

	int q = 5; 

	// Given Queries 
	int Q[][2] = { { 1, 2 }, { 2, 3 }, 
				{ 1, 3 }, { 1, 1 }, 
				{ 2, 4 } 
	}; 

	// Function Call 
	performQuery(arr, Q, q); 

	return 0; 
} 

//MAX CHARACTERS THAT CAN BE REPLACED SO THAT LEFT AND RIGHT BOTH ROTATIONS ARE SAME

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int calcMinChanges(string s){
    int n=s.size();
    if(n%2==0){
        vector<int> even(26);
        vector<int> odd(26);
        for(int i=0;i<n;i++){
            if(i%2==0){
                even[s[i]-'a']++;
            }else{
                odd[s[i]-'a']++;
            }
        }
        int a1;
        int a2;
        a1=*max_element(even.begin(),even.end());
        a2=*max_element(odd.begin(),odd.end());
        return n-a1-a2;
    }
    else{
        vector<int> temp(26);
        for(int i=0;i<n;i++){
            temp[s[i]-'a']++;
        }
        int a;
        a=*max_element(temp.begin(),temp.end());
        return n-a;
    }
}

int main()
{
    string s;
    cin>>s;
    cout<<calcMinChanges(s);
    return 0;
}


//LONGEST SUBSEQ WITH SAME LEFT AND RIGHT ROTATION

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int subseq(string s){
    int first=0;
    int curr=0;
    int ans=-1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            first=0;
            curr=0;
            for(int k=0;k<s.size();k++){
                if(first==0 && s[k]-'0'==i){
                    first=1;
                    curr++;
                }
                else if(first==1 && s[k]-'0'==j){
                    first=0;
                    curr++;
                }
            }
            if(i!=j && curr%2==1){
                curr--;
            }
            ans=max(ans,curr);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<subseq(s);
    return 0;
}

//ROTATE MATRIX BY 45 DEGREES

// C++ program for the above approach 
#include <bits/stdc++.h>
using namespace std;

// Function to rotate matrix by 45 degree
void matrix(int n, int m, vector<vector<int>> li)
{
	
	// Counter Variable 
	int ctr = 0;
	
	while (ctr < 2 * n - 1)
	{
		for(int i = 0; 
				i < abs(n - ctr - 1);
				i++)
		{
			cout << " ";
		}
		
		vector<int> lst;

		// Iterate [0, m] 
		for(int i = 0; i < m; i++)
		{
			
			// Iterate [0, n] 
			for(int j = 0; j < n; j++)
			{
				
				// Diagonal Elements 
				// Condition 
				if (i + j == ctr)
				{
					
					// Appending the 
					// Diagonal Elements 
					lst.push_back(li[i][j]);
				}
			}
		}
			
		// Printing reversed Diagonal 
		// Elements 
		for(int i = lst.size() - 1; i >= 0; i--)
		{
			cout << lst[i] << " ";
		}
		cout << endl;
		ctr += 1;
	}
}

// Driver code 
int main()
{
	
	// Dimensions of Matrix 
	int n = 8;
	int m = n; 
	
	// Given matrix 
	vector<vector<int>> li{ 
		{ 4, 5, 6, 9, 8, 7, 1, 4 }, 
		{ 1, 5, 9, 7, 5, 3, 1, 6 }, 
		{ 7, 5, 3, 1, 5, 9, 8, 0 }, 
		{ 6, 5, 4, 7, 8, 9, 3, 7 }, 
		{ 3, 5, 6, 4, 8, 9, 2, 1 }, 
		{ 3, 1, 6, 4, 7, 9, 5, 0 }, 
		{ 8, 0, 7, 2, 3, 1, 0, 8 }, 
		{ 7, 5, 3, 1, 5, 9, 8, 5 } };
	
	// Function call 
	matrix(n, m, li);

	return 0;
}

// This code is contributed by divyeshrabadiya07


//ROTATE ALL ODD TO RIGHT AND EVEN TO LEFT

//A-1
#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

void rotate(int arr[],int n){
    vector<int> even;
    vector<int> odd;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            even.push_back(arr[i]);
        }else{
            odd.push_back(arr[i]);
        }
    }
    for(int i=odd.size()-1;i>0;i--){
        int temp=odd[i];
        odd[i]=odd[i-1];
        odd[i-1]=temp;
    }
    for(int i=0;i<even.size()-1;i++){
        int temp=even[i];
        even[i]=even[i+1];
        even[i+1]=temp;
    }
    int i=0;
    int j=0;
    int k=0;
    while(i<odd.size() && j<even.size()){
        arr[k++]=odd[i++];
        arr[k++]=even[j++];
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
    rotate(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}


//MAX COUNT OF CORRESP SAME ELEMENTS IN DIFF PERMUTATIONS USING CYCLIC ROTATIONS

#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int maxCount(int arr1[],int arr2[],int n){
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    for(int i=0;i<n;i++){
        m1[arr1[i]]=i;
    }
    for(int i=0;i<n;i++){
        m2[arr2[i]]=i;
    }
    int left[n];
    int right[n];
    for(int i=0;i<n;i++){
        int index1=i;
        int index2=m2[arr1[i]];
        
        if(index1==index2){
            left[i]=0;
            right[i]=0;
        }
        if(index1>index2){
            left[i]=index1-index2;
            right[i]=n-(index1-index2);
        }else{
            left[i]=n-(index2-index1);
            right[i]=index2-index1;
        }
    }
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        if(left[i]==1){
            count1++;
        }
        if(right[i]==1){
            count2++;
        }
    }
    return max(count1,count2);
}

int main()
{
    int n;
    cin>>n;
    int arr1[n];
    int arr2[n];
    for(int i=0;i<n;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    cout<<maxCount(arr1,arr2,n);
    cout<<endl;
    return 0;
}


//ARRAY SUM AFTER SPLITTING ARRAY INTO 2 HALVES AFTER K SHIFTS USING BITWISE OR

#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int maxBitwiseORSum(int arr[],int n,int q,int k[]){
    int rotation=0;
    int num1=0;
    int num2=0;
    for(int i=0;i<q;i++){
        num1=0;
        num2=0;
        rotation=rotation-k[i];
        for(int i=0;i<n/2;i++){
            num1=num1|arr[(rotation+i+n)%n];
        }
        for(int i=n/2;i<n;i++){
            num2=num2|arr[(rotation+i+n)%n];
        }
        cout<<num1+num2<<endl;
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
    int q;
    cin>>q;
    int k[q];
    for(int i=0;i<q;i++){
        cin>>k[i];
    }
    maxBitwiseORSum(arr,n,q,k);
    cout<<endl;
    return 0;
}

//LEXICOGRAPHICALLY MIN STRING ROTATION-1


//TIME COMPLEXITY - O(n2logn)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string sortByLexico(string s){
    string arr[s.size()];
    string temp=s+s;
    for(int i=0;i<s.size();i++){
        arr[i]=temp.substr(i,s.size());
    }
    sort(arr,arr+s.size());
    return arr[0];
}

int main()
{
    string s;
    cin>>s;
    cout<<sortByLexico(s);
    return 0;
}


//LEXICOGRAPHICALLY MIN STRING ROTATION-2

//TIME COMPLEXITY - O(n)

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int startingIndex(string s){
    int ans=0;
    for(int i=1;i<s.size();i++){
        if(s[i]<s[ans]){
            ans=i;
        }
    }
    return ans;
}

void sortByLexico2(string s){
    int index=startingIndex(s);
    for(int i=0;i<s.size();i++){
        cout<<s[(index+i)%s.size()];
    }
}

int main()
{
    string s;
    cin>>s;
    sortByLexico2(s);
    return 0;
}

//ROTATE EACH RING OF MATRIX ANTICLOCKWISE BY K

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int max;

void helper(int mat[][1000],int m,int n,int temp[]){
    int index=0;
    int rs=0;
    int cs=0;
    int re=m-1;
    int ce=n-1;
    while(rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            mat[rs][i]=temp[index++];
        }
        rs++;
        for(int i=rs;i<=re;i++){
            mat[i][ce]=temp[index++];
        }
        ce--;
        if(rs<=re){
            for(int i=ce;i>=cs;i--){
                mat[re][i]=temp[index++];
            }
            re--;   
        }
        if(cs<=ce){
            for(int i=re;i>=rs;i--){
                mat[i][cs]=temp[index++];
            }
            cs++;    
        }
    }
}

void rotateRing(int mat[][1000],int m,int n,int k){
    int temp[m*n];
    int *start=temp;
    int rows=m;
    int cols=n;
    int s=0;
    int e=0;
    int index=0;
    while(s<rows && e<cols){
        int *end=start;
        for(int i=e;i<cols;i++){
            temp[index]=mat[s][i];
            end++;
            index++;
        }
        s++;
        for(int i=s;i<rows;i++){
            temp[index]=mat[i][cols-1];
            index++;
            end++;
        }
        cols--;
        if(s<rows){
            for(int i=cols-1;i>=e;i--){
                temp[index]=mat[rows-1][i];
                index++;
                end++;
            }
            rows--;
        }
        if(e<cols){
            for(int i=rows-1;i>=s;i--){
                temp[index]=mat[i][e];
                index++;
                end++;
            }
            e++;
        }
        if(end-start>k){
            reverse(start,start+k);
            reverse(start+k,end);
            reverse(start,end);
            start=end;
        }
        else{
            break;
        }
    }
    helper(mat,m,n,temp);
}

int main()
{
    int m,n;
    cin>>m>>n;
    ::max=n;
    int mat[m][1000];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int k;
    cin>>k;
    rotateRing(mat,m,n,k);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//CHECK IF 2 NOS ARE BIT ROTATIONS OF EACH OTHER

#include <iostream>

using namespace std;

bool isRotation(unsigned int x,unsigned int y){
    unsigned long long int num=x|((unsigned long long int)x<<32);
    while(num>=y){
        if(unsigned(num)==y){
            return true;
        }
        num=num>>1; //or num>>=1 (does shifting as well as assignment to num after shifting)
    }
    return false;
}

int main()
{
    unsigned int x=180;
    unsigned int y=150;
    // cin>>x>>y;
    if(isRotation(x,y)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}

//ROTATE MATRIX CLOCKWISE BY 1(SIMILAR TO RING... BUT HERE WE DONT NEED TO ASSIGN ALL THE RING ELEMENTS TO A NEW ARRAY.... WHILE ITERATING WE CAN SWAP OR INTERCHANGE THE ELEMENTS)

// C++ program to rotate a matrix 

#include <bits/stdc++.h> 
#define R 4 
#define C 4 
using namespace std; 

// A function to rotate a matrix mat[][] of size R x C. 
// Initially, m = R and n = C 
void rotatematrix(int m, int n, int mat[R][C]) 
{ 
	int row = 0, col = 0; 
	int prev, curr; 

	/* 
	row - Staring row index 
	m - ending row index 
	col - starting column index 
	n - ending column index 
	i - iterator 
	*/
	while (row < m && col < n) 
	{ 

		if (row + 1 == m || col + 1 == n) 
			break; 

		// Store the first element of next row, this 
		// element will replace first element of current 
		// row 
		prev = mat[row + 1][col]; 

		/* Move elements of first row from the remaining rows */
		for (int i = col; i < n; i++) 
		{ 
			curr = mat[row][i]; 
			mat[row][i] = prev; 
			prev = curr; 
		} 
		row++; 

		/* Move elements of last column from the remaining columns */
		for (int i = row; i < m; i++) 
		{ 
			curr = mat[i][n-1]; 
			mat[i][n-1] = prev; 
			prev = curr; 
		} 
		n--; 

		/* Move elements of last row from the remaining rows */
		if (row < m) 
		{ 
			for (int i = n-1; i >= col; i--) 
			{ 
				curr = mat[m-1][i]; 
				mat[m-1][i] = prev; 
				prev = curr; 
			} 
		} 
		m--; 

		/* Move elements of first column from the remaining rows */
		if (col < n) 
		{ 
			for (int i = m-1; i >= row; i--) 
			{ 
				curr = mat[i][col]; 
				mat[i][col] = prev; 
				prev = curr; 
			} 
		} 
		col++; 
	} 

	// Print rotated matrix 
	for (int i=0; i<R; i++) 
	{ 
		for (int j=0; j<C; j++) 
		cout << mat[i][j] << " "; 
		cout << endl; 
	} 
} 

/* Driver program to test above functions */
int main() 
{ 
	// Test Case 1 
	int a[R][C] = { {1, 2, 3, 4}, 
		{5, 6, 7, 8}, 
		{9, 10, 11, 12}, 
		{13, 14, 15, 16} }; 

	// Tese Case 2 
	/* int a[R][C] = {{1, 2, 3}, 
					{4, 5, 6}, 
					{7, 8, 9} 
					}; 
	*/ rotatematrix(R, C, a); 
	return 0; 
} 


//ROTATE MATRIX BY 90 DEGREES

#include <iostream>
using namespace std;

void turnBy90(int** mat,int m,int n){
    int temp[n][m];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            temp[j][m-i-1]=mat[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    int mat[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int* t[m];
    for(int i=0;i<m;i++){
        t[i]=mat[i];
    }
    turnBy90(t,m,n);
    return 0;
}

//INPLACE ROTATE SQUARE MATRIX

#include <iostream>
using namespace std;

void inplaceRotate(int** mat,int n){
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[j][n-i-1];
            mat[j][n-i-1]=mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1]=mat[n-j-1][i];
            mat[n-j-1][i]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int* t[n];
    for(int i=0;i<n;i++){
        t[i]=mat[i];
    }
    inplaceRotate(t,n);
    return 0;
}

//CHECK IF ALL ROWS OF MATRIX ARE CIRCULAR ROTATIONS OF EACH OTHER

// C++ program to check if all rows of a matrix 
// are rotations of each other 
#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 1000; 

// Returns true if all rows of mat[0..n-1][0..n-1] 
// are rotations of each other. 
bool isPermutedMatrix( int mat[MAX][MAX], int n) 
{ 
	// Creating a string that contains elements of first 
	// row. 
	string str_cat = ""; 
	for (int i = 0 ; i < n ; i++) 
		str_cat = str_cat + "-" + to_string(mat[0][i]); 

	// Concatenating the string with itself so that 
	// substring search operations can be performed on 
	// this 
	str_cat = str_cat + str_cat; 

	// Start traversing remaining rows 
	for (int i=1; i<n; i++) 
	{ 
		// Store the matrix into vector in the form 
		// of strings 
		string curr_str = ""; 
		for (int j = 0 ; j < n ; j++) 
			curr_str = curr_str + "-" + to_string(mat[i][j]); 

		// Check if the current string is present in 
		// the concatenated string or not 
		if (str_cat.find(curr_str) == string::npos) 
			return false; 
	} 

	return true; 
} 

// Drivers code 
int main() 
{ 
	int n = 4 ; 
	int mat[MAX][MAX] = {{1, 2, 3, 4}, 
		{4, 1, 2, 3}, 
		{3, 4, 1, 2}, 
		{2, 3, 4, 1} 
	}; 
	isPermutedMatrix(mat, n)? cout << "Yes" : 
							cout << "No"; 
	return 0; 
} 

//CHECK IF A STRING CAN BE OBTAINED BY ROTATING OTHER BY 2 PLACES

#include <iostream>
using namespace std;

bool check(string s1,string s2){
    string t=s1+s1;
    int k=2;
    int n=s1.size();
    int kComp=n-k;
    int pos=t.find(s2);
    if(pos==k||pos==kComp){
        return true;
    }
    return false;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    if(check(s1,s2)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

//CHECK DIVISIBLITY PAIRS ROTATIONS BY 4

#include <iostream>
using namespace std;

int countRotations(string s){
    int n=s.size();
    if(n==1){
        int num=s.at(0)-'0';
        if(num%4==0){
            return 1;
        }
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int num1=s.at(i%n)-'0';
        int num2=s.at((i+1)%n)-'0';
        int num=num1*10+num2;
        if(num%4==0){
            ans++;
        }
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<countRotations(s);
    return 0;
}

//MIN MOV TO END OR LEFT OPERATIONS

// CPP program to make all strings same using 
// move to end operations. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns minimum number of moves to end 
// operations to make all strings same. 
int minimunMoves(string arr[], int n) 
{ 
	int ans = INT_MAX; 
	for (int i = 0; i < n; i++) 
	{ 
		int curr_count = 0; 

		// Consider s[i] as target string and 
		// count rotations required to make 
		// all other strings same as str[i]. 
		for (int j = 0; j < n; j++) { 

			string tmp = arr[j] + arr[j]; 

			// find function returns the index where we 
			// found arr[i] which is actually count of 
			// move-to-front operations. 
			int index = tmp.find(arr[i]); 

			// If any two strings are not rotations of 
			// each other, we can't make them same. 
			if (index == string::npos) 
				return -1; 

			curr_count += index; 
		} 

		ans = min(curr_count, ans); 
	} 

	return ans; 
} 

// driver code for above function. 
int main() 
{ 
	string arr[] = {"xzzwo", "zwoxz", "zzwox", "xzzwo"}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << minimunMoves(arr, n); 
	return 0; 
} 

//ROTATE BY PI

#include <iostream>
#include<climits>
using namespace std;

void rotateBypi(int** mat,int n){
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i;j++){
            int temp=mat[i][j];
            mat[i][j]=mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1]=temp;
        }
        for(int j=i+1;j<n-i-1;j++){
            int temp=mat[j][n-i-1];
            mat[j][n-i-1]=mat[n-j-1][i];
            mat[n-j-1][i]=temp;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    int* t[n];
    for(int i=0;i<n;i++){
        t[i]=mat[i];
    }
    rotateBypi(t,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

//COMPARE STRINGS IF THEY ARE ROTATIONS OF EACH OTHER

// C++ program to check if 
// two strings are rotations
// of each other
#include<bits/stdc++.h>
using namespace std;
bool isRotation(string a, 
                string b)
{
  int n = a.length();
  int m = b.length();
  if (n != m)
    return false;
 
  // create lps[] that 
  // will hold the longest
  // prefix suffix values 
  // for pattern
  int lps[n];
 
  // length of the previous 
  // longest prefix suffix
  int len = 0;
  int i = 1;
   
  // lps[0] is always 0
  lps[0] = 0; 
 
  // the loop calculates 
  // lps[i] for i = 1 to n-1
  while (i < n) 
  {
    if (a[i] == b[len]) 
    {
      lps[i] = ++len;
      ++i;
    }
    else
    {
      if (len == 0) 
      {
        lps[i] = 0;
        ++i;
      }
      else
      {
        len = lps[len - 1];
      }
    }
  }
 
  i = 0;
 
  // Match from that rotating
  // point
  for (int k = lps[n - 1]; 
           k < m; ++k) 
  {
    if (b[k] != a[i++])
      return false;
  }
  return true;
}
 
// Driver code
int main()
{
  string s1 = "ABACD";
  string s2 = "CDABA";
  cout << (isRotation(s1, s2) ? 
           "1" : "0");
}
 
 //COUNT CONTINUOUS ONES
 
 #include <iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxCont1(string s,int k){
    int count=0;
    vector<int> v;
    for(int i=0;i<s.size();){
        count=0;
        int k=i;
        while(s[k]=='1' && k<s.size()){
            ++count;
            ++k;
        }
        if(k==i){
            i++;
        }else{
            i=k;
        }
        v.push_back(count);
    }
    sort(v.begin(),v.end());
    int ans=0;
    int n=v.size();
    while(k>=0){
        ans+=v[n-1];
        --n;
        --k;
    }
    return ans;
}

int main()
{
    // string s;
    // cin>>s;
    // int k;
    // cin>>k;
    cout<<maxCont1("001100111000110011100",2);
    return 0;
}


