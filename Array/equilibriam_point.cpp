// Given an array A of n positive numbers. The task is to find the first equilibrium point in an array. Equilibrium point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

// Example 1:

// Input: 
// n = 5 
// A[] = {1,3,5,2,2} 
// Output: 
// 3 
// Explanation: equilibrium point is at position 3 as sum of elements before it (1+3) = sum of elements after it (2+2). 


//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int sum = 0;
        int answer = -1;
        for(int i=0;i<n;i++){
            sum += a[i];
        }
        if(n==1){
            return 1;
        }
        int lsum = 0;
        int rsum = 0;
        for(int i=1;i<n-1;i++){
            lsum += a[i-1];
            rsum = sum - lsum -a[i];
            // cout<<"lsum:"<<lsum<<" rsum:"<<rsum;
            if(lsum == rsum){
                answer = ++i;
                break;
            }
        }
        return answer;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends