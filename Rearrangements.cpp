//REARRANGEMENT OF EVEN AND ODD PLACES

#include <iostream>
#include<climits>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void rearrangeArray(int arr[],int n){
    vector<int> temp;
    sort(arr,arr+n);
    if(n%2!=0){
        temp.push_back(arr[0]);
        int start=1;
        int end=n-1;
        while(start<end){
            temp.insert(temp.begin(),arr[end]);
            temp.insert(temp.begin(),arr[start]);
            ++start;
            --end;
        }
    }
    else{
        int start=0;
        int end=n-1;
        while(start<end){
            temp.insert(temp.begin(),arr[end]);
            temp.insert(temp.begin(),arr[start]);
            ++start;
            --end;
        }
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
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
    rearrangeArray(arr,n);
    return 0;
}

//REARRANGE POSITIVE AND NEGATIVE NUMBERS(IN O(n) TIME AND O(1) SPACE COMPLEXITY) WITHOUT CHANGING ACTUAL ORDER OF ELEMENTS

#include <iostream>
using namespace std;

void shiftToRight(int arr[],int n,int reqIndex,int i){
    int ele=arr[i];
    for(int j=i;j>reqIndex;j--){
        arr[j]=arr[j-1];
    }
    arr[reqIndex]=ele;
}

void rearrangeArray(int arr[],int n){
    int reqIndex=-1;
    for(int i=0;i<n;i++){
        if(reqIndex>=0){
            if((arr[i]>=0 && arr[reqIndex]<0)||(arr[i]<0 && arr[reqIndex]>=0)){
                shiftToRight(arr,n,reqIndex,i);
                if(i-reqIndex>=2){
                    reqIndex+=2;
                }else{
                    reqIndex=-1;
                }
            }
        }
        else if(reqIndex==-1){
            if((arr[i]<0 && i%2!=0)||(arr[i]>=0 && i%2==0)){
                reqIndex=i;
            }
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
    rearrangeArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//REARRANGE POSITIVE AND NEGATIVE NUMBERS(IN O(n) TIME AND O(1) SPACE COMPLEXITY) CHANGING ACTUAL ORDER OF ELEMENTS

#include <iostream>
using namespace std;

void rearrangeArray(int arr[],int n){
    int pivot=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            ++pivot;
            int temp=arr[i];
            arr[i]=arr[pivot];
            arr[pivot]=temp;
        }
    }
    int i=1;
    int j=pivot+1;
    while(i<=j && j<n && i<n){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i+=2;
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
    rearrangeArray(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//SHIFT ZEROS TO END

//A-1

#include <iostream>
using namespace std;


void shiftZeros(int arr[],int n){
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            if(i!=index){
                int temp=arr[index];
                arr[index]=arr[i];
                arr[i]=temp; 
            }
            index++;
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
    shiftZeros(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//A-2

#include <iostream>
using namespace std;

void rightShift(int arr[],int n,int reqIndex,int i){
    int ele=arr[i];
    for(int j=i;j>reqIndex;j--){
        arr[j]=arr[j-1];
    }
    arr[reqIndex]=ele;
}

void shiftZeros(int arr[],int n){
    int reqIndex=-1;
    for(int i=0;i<n;i++){
        if(reqIndex>=0){
            if(arr[i]!=0 && arr[reqIndex]==0){
                rightShift(arr,n,reqIndex,i);
                reqIndex++;
            }
        }
        else if(reqIndex==-1){
            if(arr[i]==0){
                reqIndex=i;
            }
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
    shiftZeros(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//MIN SWAPS REQUIRED TO BRING ALL ELEMENTS LESS THA/EQUAL TO K TOGETHER

#include <iostream>
using namespace std;


int minSwaps(int arr[],int n,int k){
    int index=0;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            if(i!=index){
                ans++;
            }
            index++;
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
    int k;
    cin>>k;
    cout<<minSwaps(arr,n,k);
    return 0;
}


//SEPARATE POSITIVE AND NEGATIVE ELEMENTS

//A-1 O(n)

// C++ implementation of 
// the above approach
#include <iostream>

void printArray(int array[], int length)
{
	std::cout << "[";
	
	for(int i = 0; i < length; i++)
	{
		std::cout << array[i];
		
		if(i < (length - 1))
			std::cout << ", ";
		else
			std::cout << "]" << std::endl;
	}
}

void reverse(int array[], int start, int end)
{
	while(start < end)
	{
		int temp = array[start];
		array[start] = array[end];
		array[end] = temp;
		start++;
		end--;
	}
}

// Rearrange the array with all negative integers
// on left and positive integers on right 
// use recursion to split the array with first element
// as one half and the rest array as another and then 
// merge it with head of the array in each step 
void rearrange(int array[], int start, int end)
{
	// exit condition 
	if(start == end)
		return;
	
	// rearrange the array except the first
	// element in each recursive call 
	rearrange(array, (start + 1), end);
	
	// If the first element of the array is positive, 
	// then right-rotate the array by one place first
	// and then reverse the merged array.
	if(array[start] >= 0)
	{
		reverse(array, (start + 1), end);
		reverse(array, start, end);
	}
}

// Driver code
int main()
{
	int array[] = {-12, -11, -13, -5, -6, 7, 5, 3, 6};
	int length = (sizeof(array) / sizeof(array[0]));
	int countNegative = 0;
	
	for(int i = 0; i < length; i++)
	{
		if(array[i] < 0)
			countNegative++;
	}
	
	std::cout << "array: ";
	printArray(array, length);
	rearrange(array, 0, (length - 1));
	
	reverse(array, countNegative, (length - 1));
	
	std::cout << "rearranged array: ";
	printArray(array, length);
	return 0;
}

//A-2 O(nlogn)

// CPP program to rearrange positive 
// and negative integers keeping 
// order of elements.
#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b)
{

// swap not needed
if((a > 0 && b > 0) || 
(a < 0 && b < 0) || 
(a > 0 && b < 0 ))
return false;

// swap needed
if(a < 0 && b > 0) 
return true;

// swap not needed
if((a == 0 && b < 0) || 
(a > 0 && b == 0))
return false;

// swap needed
if((a == 0 && b > 0) || 
(a < 0 && b == 0))
return true;

}

void rearrange(int arr[], int n)
{
	sort(arr, arr + n, comp);
}

// Driver code
int main()
{
	int arr[] = { -12, 11, -13, -5, 
				6, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	for (int i = 0; i < n; i++)
		cout << " " << arr[i];

	return 0;
}

//REARRANGE LIKE ELEMENTS AT EVEN POS GREATER THAN THOSE AT ODD POS

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void rearrange(int arr[],int n){
    sort(arr,arr+n);
    int start=1;
    int end=n-1;
    while(start<end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start+=2;
        --end;
    }
}

// void rearrange(int arr[],int n){
//     for(int i=1;i<n;i++){
//         if(i%2==0){
//             if(arr[i]>arr[i-1]){
//                 int temp=arr[i];
//                 arr[i]=arr[i-1];
//                 arr[i-1]=temp;
//             } 
//         }
//         else{
//             if(arr[i-1]>arr[i]){
//                 int temp=arr[i];
//                 arr[i]=arr[i-1];
//                 arr[i-1]=temp;
//             }
//         }
//     }
// }

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//REPLACE EVERY ELEMENT WITH MULTIPLICATION OF PREV AND NEXT

// C++ program to update every array element with 
// multiplication of previous and next numbers in array 
#include<iostream> 
using namespace std; 

void modify(int arr[], int n) 
{ 
	// Nothing to do when array size is 1 
	if (n <= 1) 
	return; 

	// store current value of arr[0] and update it 
	int prev = arr[0]; 
	arr[0] = arr[0] * arr[1]; 

	// Update rest of the array elements 
	for (int i=1; i<n-1; i++) 
	{ 
		// Store current value of next interation 
		int curr = arr[i]; 

		// Update current value using previos value 
		arr[i] = prev * arr[i+1]; 

		// Update previous value 
		prev = curr; 
	} 

	// Update last array element 
	arr[n-1] = prev * arr[n-1]; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {2, 3, 4, 5, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	modify(arr, n); 
	for (int i=0; i<n; i++) 
	cout << arr[i] << " "; 
	return 0; 
} 


//GET BIGGEST NUMBER

// Given an array of numbers,
// program to arrange the numbers
// to form the largest number
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int myCompare(string X, string Y)
{
	string XY = X.append(Y);

	string YX = Y.append(X);

	
	return XY.compare(YX) > 0 ? 1 : 0;  //IF 0 THEN SWAP ELSE NOT SWAP
}

void printLargest(vector<string> arr)
{
	
	sort(arr.begin(), arr.end(), myCompare);

	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
}

// Driver program to test above functions
int main()
{
	vector<string> arr;

	// output should be 6054854654
	arr.push_back("54");
	arr.push_back("546");
	arr.push_back("548");
	arr.push_back("60");
	printLargest(arr);

	return 0;
}


//REPLACE ARR[I]=J AS ARR[J]=I

// A space efficient C++ program to rearrange contents of 
// arr[] such that arr[j] becomes j if arr[i] is j 
#include <iostream> 
using namespace std; 

// A utility function to rearrange elements in the cycle 
// starting at arr[i]. This function assumes values in 
// arr[] be from 1 to n. It changes arr[j-1] to i+1 
// if arr[i-1] is j+1 
void rearrangeUtil(int arr[], int n, int i) 
{ 
	// 'val' is the value to be stored at 'arr[i]' 
	int val = -(i + 1); // The next value is determined 
	// using current index 
	i = arr[i] - 1; // The next index is determined 
	// using current value 

	// While all elements in cycle are not processed 
	while (arr[i] > 0) 
	{ 
		
		// Store value at index as it is going to be 
		// used as next index 
		int new_i = arr[i] - 1; 

		// Update arr[] 
		arr[i] = val; 

		// Update value and index for next iteration 
		val = -(i + 1); 
		i = new_i; 
	} 
} 

// A space efficient method to rearrange 'arr[0..n-1]' 
// so that 'arr[j]' becomes 'i' if 'arr[i]' is 'j' 
void rearrange(int arr[], int n) 
{ 
	// Increment all values by 1, so that all elements 
	// can be made negative to mark them as visited 
	int i; 
	for (i = 0; i < n; i++) 
		arr[i]++; 

	// Process all cycles 
	for (i = 0; i < n; i++) 
	{ 
		
		// Process cycle starting at arr[i] if this cycle is 
		// not already processed 
		if (arr[i] > 0) 
			rearrangeUtil(arr, n, i); 
	} 

	// Change sign and values of arr[] to get the original 
	// values back, i.e., values in range from 0 to n-1 
	for (i = 0; i < n; i++) 
		arr[i] = (-arr[i]) - 1; 
} 

// A utility function to print contents of arr[0..n-1] 
void printArray(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 2, 0, 1, 4, 5, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << "Given array is " << endl; 
	printArray(arr, n); 

	rearrange(arr, n); 

	cout << "Modified array is " << endl; 
	printArray(arr, n); 
	return 0; 
} 

// This code is contributed by shubhamsingh10 


//SHUFFLE ARRAY WITH 2n INTEGERS

//A-1 BRUTE FORCE(USING 2 LOOPS)

//A-2 USING 2 POINTERS(ORDER OF O(n))

//A-3 DIVIDE AND CONQUER (O(nlogn))

// C++ Effective program to shuffle an array of size 2n 

#include <bits/stdc++.h> 
using namespace std; 

// function to shuffle an array of size 2n 
void shufleArray(int a[], int f, int l) 
{ 
	if (f > l) { 
		return; 
	} 

	// If only 2 element, return 
	if (l - f == 1) 
		return; 

	// finding mid to divide the array 
	int mid = (f + l) / 2; 

	// using temp for swapping first half of second array 
	int temp = mid + 1; 

	// mmid is use for swapping second half for first array 
	int mmid = (f + mid) / 2; 

	// Swapping the element 
	for (int i = mmid + 1; i <= mid; i++) 
		swap(a[i], a[temp++]); 

	shufleArray(a, f, mid); 
	shufleArray(a, mid + 1, l); 
} 

// Driven Program 
int main() 
{ 
	int a[] = { 1, 3, 5, 7, 2, 4, 6, 8 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	shufleArray(a, 0, n - 1); 

	for (int i = 0; i < n; i++) 
		cout << a[i] << " "; 

	return 0; 
} 

//A-4 SWAP ALGO(O(n2))

// CPP program to shuffle an array in 
// the form of a1, b1, a2, b2,... 
#include<iostream> 
using namespace std; 

// function to rearrange the array 
void rearrange(int arr[], int n) 
{ 

	// if size is null or odd return because it 
	// is not possible to rearrange 
	if (arr == NULL || n % 2 == 1) 
		return; 

	// start from the middle index 
	int currIdx = (n - 1) / 2; 

	// each time we will set two elements from the 
	// start to the valid position by swapping 
	while (currIdx > 0) 
	{ 
		int count = currIdx, swapIdx = currIdx; 
	
		while (count-- > 0) 
		{ 
			int temp = arr[swapIdx + 1]; 
			arr[swapIdx + 1] = arr[swapIdx]; 
			arr[swapIdx] = temp; 
			swapIdx++; 
		} 
		
		currIdx--; 
	} 
} 

// Driver Program 
int main() 
{ 
	int arr[] = {1, 3, 5, 2, 4, 6}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	rearrange(arr, n); 
	for (int i = 0; i < n; i++) 
	cout << " " << arr[i]; 

} 

// This code is contributed by Smitha Dinesh Semwal 


//REARRANGE A BINARY STRING

//A-1 SAVING THE COUNTS OF 0 AND 1 AND THEN SIMPLY REPLACING ALTERNATIVELY IN THE STRING

#include <iostream>
using namespace std;

string rearrangeBinaryString(string s,int x,int y){
    int arr[2]={0};
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='0'){
            arr[s[i]-'0']++;
        }else{
            arr[s[i]-'0']++;
        }
    }
    for(int i=0;s[i]!='\0';){
        int num=x;
        while(num>0 && arr[0]>0){
            s[i]='0';
            ++i;
            --arr[0];
            --num;
        }
        num=y;
        while(num>0 && arr[1]>0){
            s[i]='1';
            ++i;
            --arr[1];
            --num;
        }
    }
    return s;
}
    
int main()
{
    string s;
    cin>>s;
    int x;
    int y;
    cin>>x>>y;
    cout<<rearrangeBinaryString(s,x,y);
    return 0;
}

//A-2 CAN BE USING RIGHT ROTATION METHOD

//MAKE SEQUENCE ACC TO D OR I STRING

#include <iostream>
using namespace std;

void rightRotate(int arr[],int n,int first,int second){
    int temp=arr[second];
    for(int i=second;i>first;i--){
        arr[i]=arr[i-1];
    }
    arr[first]=temp;
}

void formMinNum(string s){
    int n=s.size();
    int arr[n+1];
    for(int i=0;i<n+1;i++){
        arr[i]=i+1;
    }
    int first=0;
    int second=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='D'){
            rightRotate(arr,n+1,first,second);
            if(i+1<n && s[i+1]=='I'){
                first=second;
                ++second;
            }else{
                ++second;
            }
        }
        else{
            first=second;
                ++second;
        }
    }
    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    string s;
    cin>>s;
    formMinNum(s);
    return 0;
}


//A-2

// C++ program to print minimum number that can be formed
// from a given sequence of Is and Ds
#include<bits/stdc++.h>
using namespace std;

void printLeast(string arr)
{
	// min_avail represents the minimum number which is
	// still available for inserting in the output vector.
	// pos_of_I keeps track of the most recent index
	// where 'I' was encountered w.r.t the output vector
	int min_avail = 1, pos_of_I = 0;

	//vector to store the output
	vector<int>v;

	// cover the base cases
	if (arr[0]=='I')
	{
		v.push_back(1);
		v.push_back(2);
		min_avail = 3;
		pos_of_I = 1;
	}
	else
	{
		v.push_back(2);
		v.push_back(1);
		min_avail = 3;
		pos_of_I = 0;
	}

	// Traverse rest of the input
	for (int i=1; i<arr.length(); i++)
	{
		if (arr[i]=='I')
		{
			v.push_back(min_avail);
			min_avail++;
			pos_of_I = i+1;
		}
		else
		{
			v.push_back(v[i]);
			for (int j=pos_of_I; j<=i; j++)
				v[j]++;

			min_avail++;
		}
	}

	// print the number
	for (int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

// Driver program to check the above function
int main()
{
	printLeast("IDID");
	printLeast("I");
	printLeast("DD");
	printLeast("II");
	printLeast("DIDI");
	printLeast("IIDDD");
	printLeast("DDIDDIID");
	return 0;
}

//A-3 USING STACKS

// IF ITS I OR I IS EQUAL TO STRING SIZE, THEN PUSH i+1 TO THE STACK,  REMOVE ALL THE ELEMENTS FROM THE STACK ELSE IF ITS D THEN PUSH i+1 TO THE STACK AND DONT DO ANYTHING...

// C++ program to print minimum number that can be formed
// from a given sequence of Is and Ds
#include <bits/stdc++.h>
using namespace std;

// Function to decode the given sequence to construct
// minimum number without repeated digits
void PrintMinNumberForPattern(string seq)
{
	// result store output string
	string result;

	// create an empty stack of integers
	stack<int> stk;

	// run n+1 times where n is length of input sequence
	for (int i = 0; i <= seq.length(); i++)
	{
		// push number i+1 into the stack
		stk.push(i + 1);

		// if all characters of the input sequence are
		// processed or current character is 'I'
		// (increasing)
		if (i == seq.length() || seq[i] == 'I')
		{
			// run till stack is empty
			while (!stk.empty())
			{
				// remove top element from the stack and
				// add it to solution
				result += to_string(stk.top());
				result += " ";
				stk.pop();
			}
		}
	}

	cout << result << endl;
}

// main function
int main()
{
	PrintMinNumberForPattern("IDID");
	PrintMinNumberForPattern("I");
	PrintMinNumberForPattern("DD");
	PrintMinNumberForPattern("II");
	PrintMinNumberForPattern("DIDI");
	PrintMinNumberForPattern("IIDDD");
	PrintMinNumberForPattern("DDIDDIID");
	return 0;
}
 
//MIN NUM SWAPS TO PUT ADJACENT ELEMENTS IN THE PAIR TOGETHER

// C++ program to find minimum number of swaps required so that 
// all pairs become adjacent. 
#include<bits/stdc++.h> 
using namespace std; 

// This function updates indexes of elements 'a' and 'b' 
void updateindex(int index[], int a, int ai, int b, int bi) 
{ 
	index[a] = ai; 
	index[b] = bi; 
} 

// This function returns minimum number of swaps required to arrange 
// all elements of arr[i..n] become aranged 
int minSwapsUtil(int arr[], int pairs[], int index[], int i, int n) 
{ 
	// If all pairs procesed so no swapping needed return 0 
	if (i > n) return 0; 

	// If current pair is valid so DO NOT DISTURB this pair 
	// and move ahead. 
	if (pairs[arr[i]] == arr[i+1]) 
		return minSwapsUtil(arr, pairs, index, i+2, n); 

	// If we reach here, then arr[i] and arr[i+1] don't form a pair 

	// Swap pair of arr[i] with arr[i+1] and recursively compute 
	// minimum swap required if this move is made. 
	int one = arr[i+1]; 
	int indextwo = i+1; 
	int indexone = index[pairs[arr[i]]]; 
	int two = arr[index[pairs[arr[i]]]]; 
	swap(arr[i+1], arr[indexone]); 
	updateindex(index, one, indexone, two, indextwo); 
	int a = minSwapsUtil(arr, pairs, index, i+2, n); 

	// Backtrack to previous configuration. Also restore the 
	// previous indices, of one and two 
	swap(arr[i+1], arr[indexone]); 
	updateindex(index, one, indextwo, two, indexone); 
	one = arr[i], indexone = index[pairs[arr[i+1]]]; 

	// Now swap arr[i] with pair of arr[i+1] and recursively 
	// compute minimum swaps required for the subproblem 
	// after this move 
	two = arr[index[pairs[arr[i+1]]]], indextwo = i; 
	swap(arr[i], arr[indexone]); 
	updateindex(index, one, indexone, two, indextwo); 
	int b = minSwapsUtil(arr, pairs, index, i+2, n); 

	// Backtrack to previous configuration. Also restore 
	// the previous indices, of one and two 
	swap(arr[i], arr[indexone]); 
	updateindex(index, one, indextwo, two, indexone); 

	// Return minimum of two cases 
	return 1 + min(a, b); 
} 

// Returns minimum swaps required 
int minSwaps(int n, int pairs[], int arr[]) 
{ 
	int index[2*n + 1]; // To store indices of array elements 

	// Store index of each element in array index 
	for (int i = 1; i <= 2*n; i++) 
		index[arr[i]] = i; 

	// Call the recursive function 
	return minSwapsUtil(arr, pairs, index, 1, 2*n); 
} 

// Driver program 
int main() 
{ 
	// For simplicity, it is assumed that arr[0] is 
	// not used. The elements from index 1 to n are 
	// only valid elements 
	int arr[] = {0, 3, 5, 6, 4, 1, 2}; 

	// if (a, b) is pair than we have assigned elements 
	// in array such that pairs[a] = b and pairs[b] = a 
	int pairs[] = {0, 3, 6, 1, 5, 4, 2}; 
	int m = sizeof(arr)/sizeof(arr[0]); 

	int n = m/2; // Number of pairs n is half of total elements 

	// If there are n elements in array, then 
	// there are n pairs 
	cout << "Min swaps required is " << minSwaps(n, pairs, arr); 
	return 0; 
} 

//GEN ALL POSSIBLE SORTED ARRAYS USING 2

#include <iostream>
using namespace std;

void helper(int arr1[],int arr2[],int size1,int size2,int temp[],bool flag,int i,int j,int len){
    if(flag){
        if(len){
            for(int i=0;i<=len;i++){
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
        for(int k=i;k<size1;k++){
            if(len){
                if(arr1[k]>temp[len]){
                    temp[len+1]=arr1[k];
                    helper(arr1,arr2,size1,size2,temp,false,k+1,j,len+1);
                }    
            }
            else{
                temp[len]=arr1[k];
                helper(arr1,arr2,size1,size2,temp,false,k+1,j,len);
            }
        }
    }
    else{
        for(int k=j;k<size2;k++){
            if(arr2[k]>temp[len]){
                temp[len+1]=arr2[k];
                helper(arr1,arr2,size1,size2,temp,true,i,k+1,len+1);
            }
        }
    }
}

void genSortedArrays(int arr1[],int arr2[],int size1,int size2){
    int temp[size1+size2];
    helper(arr1,arr2,size1,size2,temp,true,0,0,0);
}

int main()
{
    int size1,size2;
    cin>>size1;
    int arr1[size1];
    for(int i=0;i<size1;i++){
        cin>>arr1[i];
    }
    cin>>size2;
    int arr2[size2];
    for(int i=0;i<size2;i++){
        cin>>arr2[i];
    }
    genSortedArrays(arr1,arr2,size1,size2);
    return 0;
}

//FIND SORTED SEQUENCE

#include <iostream>
using namespace std;

void sortedSeq1(int arr[],int n){
    int smaller[n];
    smaller[0]=-1;
    int min=0;
    for(int i=1;i<n;i++){
        if(arr[i]<=arr[min]){
            min=i;
            smaller[i]=-1;
        }
        else{
            smaller[i]=min;
        }
    }
    int greater[n];
    greater[n-1]=-1;
    int max=n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>=arr[max]){
            max=i;
            greater[i]=-1;
        }
        else{
            greater[i]=max;
        }
    }
    for(int i=0;i<n;i++){
        if(smaller[i]!=-1 && greater[i]!=-1){
            cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[greater[i]]<<endl;
            break;
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
    sortedSeq1(arr,n);
    return 0;
}

//SUBARRAY WITH EQUAL 0 AND 1 MAX SIZE

#include <iostream>
#include<climits>
using namespace std;

void subArray(int arr[],int n){
    int sum=INT_MIN;
    int ans=-1;
    int sindex=-1;
    int eindex=-1;
    for(int i=0;i<n-1;i++){
        if(arr[i]==0){
            sum=-1;
        }
        else{
            sum=1;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j]==0){
                sum+=-1;    
            }
            else{
                sum+=1;
            }
            if(sum==0){
                int s=j-i+1;
                if(s>ans){
                    ans=s;
                    sindex=i;
                    eindex=j;
                }
            }
        }
    }
    for(int i=sindex;i<=eindex;i++){
        cout<<arr[i]<<" ";
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
    subArray(arr,n);
    return 0;
}

// C++ program to find largest subarray with equal number of
// 0's and 1's.

#include <bits/stdc++.h>
using namespace std;

// Returns largest subarray with equal number of 0s and 1s

int maxLen(int arr[], int n)
{
	// Creates an empty hashMap hM

	unordered_map<int, int> hM;

	int sum = 0; // Initialize sum of elements
	int max_len = 0; // Initialize result
	int ending_index = -1;

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == 0) ? -1 : 1;

	// Traverse through the given array

	for (int i = 0; i < n; i++) {
		// Add current element to sum

		sum += arr[i];

		// To handle sum=0 at last index

		if (sum == 0) {
			max_len = i + 1;
			ending_index = i;
		}

		// If this sum is seen before, then update max_len
		// if required

		if (hM.find(sum + n) != hM.end()) {
			if (max_len < i - hM[sum + n]) {
				max_len = i - hM[sum + n];
				ending_index = i;
			}
		}
		else // Else put this sum in hash table
			hM[sum + n] = i;
	}

	for (int i = 0; i < n; i++)
		arr[i] = (arr[i] == -1) ? 0 : 1;

	printf("%d to %d\n",
		ending_index - max_len + 1, ending_index);

	return max_len;
}

// Driver method

int main()
{
	int arr[] = { 1, 0, 0, 1, 0, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	maxLen(arr, n);
	return 0;
}

// This code is contributed by Aditya Goel


//MAX PROD SUBARRAY

//A-1 USING 2 LOOPS

//A-2 O(N)

#include <iostream>
#include<climits>
using namespace std;

void maxProdSubArray(int arr[],int n){
    int ans=INT_MIN;
    int maxProd=1;
    int minProd=1;
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            maxProd*=arr[i];
            minProd=min(minProd*arr[i],1);
            flag=1;
        }
        else if(arr[i]<0){
            int temp=maxProd;
            maxProd=max(minProd*arr[i],1);
            minProd=temp*arr[i];
        }
        else{
            minProd=1;
            maxProd=1;
        }
        ans=max(ans,maxProd);
    }
    if(flag==0 && ans==INT_MIN){
        cout<<0<<endl;
    }else{
        cout<<ans<<endl;
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
    maxProdSubArray(arr,n);
    return 0;
}

//REPLACE WITH GREATEST ELEMENT ON RIGHT

#include <iostream>
#include<climits>
using namespace std;

void replace(int arr[],int n){
    if(n==1){
        arr[0]=-1;
        return;
    }
    int temp=arr[n-2];
    arr[n-2]=arr[n-1];
    arr[n-1]=-1;
    
    for(int i=n-3;i>=0;i--){
        int a=arr[i];
        arr[i]=temp;
        temp=max(temp,a);
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
    replace(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//LIS - GENERATE LIS AND ALSO FIND LIS LENGTH

#include <iostream>
using namespace std;

// int helper(int arr[],int a[],int low,int high,int ele){
//     while(high-low>1){
//         int mid=(low+high)/2;
//         if(arr[a[mid]]>=ele){
//             high=mid;
//         }
//         else{
//             low=mid;
//         }
//     }
//     return high;
// }

int helper(int arr[],int low,int high,int ele){
    while(high-low>1){
        int mid=(low+high)/2;
        if(arr[mid]>=ele){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    return high;
}

// void LIS(int arr[],int n){
//     int a[n]={0};
//     int b[n]={-1};
    
//     int length=1;
//     for(int i=1;i<n;i++){
//         if(arr[i]<arr[a[0]]){
//             a[0]=i;
//         }
//         else if(arr[i]>arr[a[length-1]]){
//             b[i]=a[length-1];
//             a[length++]=i;
//         }
//         else{
//             int index=helper(arr,a,-1,length-1,arr[i]);
            
//             b[i]=a[index-1];
//             a[index]=i;
//         }
//     }
//     for(int i=a[length-1];i>=0;i=b[i]){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

int LISLength(int arr[],int n){
    int a[n]={0};
    
    int length=1;
    a[0]=arr[0];
    for(int i=1;i<n;i++){
        if(a[0]>arr[i]){
            a[0]=arr[i];
        }
        else if(a[length-1]<arr[i]){
            a[length++]=arr[i];
        }
        else{
            int index=helper(a,-1,length-1,arr[i]);
            
            a[index]=arr[i];
        }
    }
    return length;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // LIS(arr,n);
    cout<<LISLength(arr,n);
    return 0;
}


//MAX CIRCULAR SUM SUBARRAY

//A-1 USING SIMPLE APROACH - KADANE ALGO IN OG AND REVERSE ARRAY AND THEN CALC MAX SUM IN BOTH AND RETURNING MAX

#include <iostream>
#include<climits>
using namespace std;

int helper(int arr[],int n){
    int maxSum=0;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        maxSum+=arr[i];
        if(maxSum<0){
            maxSum=0;
        }
        ans=max(ans,maxSum);
    }
    return ans;
}

int maxCircularSum(int arr[],int n){
    int sum=helper(arr,n);  
    int arrSum=0;
    for(int i=0;i<n;i++){
        arrSum+=arr[i];
        arr[i]=-arr[i];
    }
    int revSum=helper(arr,n);
    arrSum+=revSum;
    return max(arrSum,sum);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxCircularSum(arr,n);
    cout<<endl;
    return 0;
}


//A-2 USING MODIFIED KADANE ALGO

// C++ program for maximum contiguous circular sum problem 
#include <bits/stdc++.h> 
using namespace std; 

// The function returns maximum 
// circular contiguous sum in a[] 
int maxCircularSum(int a[], int n) 
{ 
	// Corner Case 
	if (n == 1) 
		return a[0]; 

	// Initialize sum variable which store total sum of the array. 
	int sum = 0; 
	for (int i = 0; i < n; i++) { 
		sum += a[i]; 
	} 

	// Initialize every variable with first value of array. 
	int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0]; 

	// Concept of Kadane's Algorithm 
	for (int i = 1; i < n; i++) { 
		// Kadane's Algorithm to find Maximum subarray sum. 
		curr_max = max(curr_max + a[i], a[i]); 
		max_so_far = max(max_so_far, curr_max); 

		// Kadane's Algorithm to find Minimum subarray sum. 
		curr_min = min(curr_min + a[i], a[i]); 
		min_so_far = min(min_so_far, curr_min); 
	} 

	if (min_so_far == sum) 
		return max_so_far; 

	// returning the maximum value 
	return max(max_so_far, sum - min_so_far); 
} 

/* Driver program to test maxCircularSum() */
int main() 
{ 
	int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl; 
	return 0; 
} 

//SORT 1ST ARRAY ACC TO 2ND ARRAY

#include <iostream>
#include<map>
using namespace std;

void sortAcc(int arr1[],int n1,int arr2[],int n2){
    map<int,int> m;
    for(int i=0;i<n1;i++){
        m[arr1[i]]++;
    }
    for(int i=0;i<n2;i++){
        int num=arr2[i];
        while(m[num]>0){
            cout<<num<<" ";
            --m[num];
        }
    }
    for(auto i=m.begin();i!=m.end();i++){
        if(i->second==0){
            continue;
        }
        cout<<i->first<<" ";
    }
    cout<<endl;
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
    sortAcc(arr1,n1,arr2,n2);
    return 0;
}

//FIND INDEX OF 0 TO BE REPLACED


#include <iostream>
#include<vector>
using namespace std;

int findIndex(int arr[],int n){
    vector<int> indices;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            indices.push_back(i);
        }
    }
    int start=0;
    int end=n-1;
    if(indices.size()==1){
        return (indices[0]-start)+(end-indices[0])+1;
    }
    int maxi=-1;
    int res=-1;
    for(int i=0;i<indices.size();i++){
        int ans=0;
        // int index=indices[i];
        if(i==0){
            ans=(indices[i]-start)+(indices[i+1]-indices[i]);
        }
        else if(i==indices.size()-1){
            ans=(indices[i]-indices[i-1])+(end-indices[i]);
        }
        else{
            ans=(indices[i]-indices[i-1]-1)+(indices[i+1]-indices[i]);
        }
        if(maxi<ans){
            maxi=ans;
            res=indices[i];
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findIndex(arr,n);
    return 0;
}


