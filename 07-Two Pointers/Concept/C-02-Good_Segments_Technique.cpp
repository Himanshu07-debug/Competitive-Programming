#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// GOOD SEGMENTS TECHNIQUE -------------------------------->>

// Learn by Problems

// Increasing Example ==================>>>

// 1. Find the Longest Subarray with sum <= k

// Appraoch 1 ==> We can do the Binary Search on the All Possible Lengths of the Subarrays i.e 0 to n 
//               [ BINARY SEARCH + SLIDING WINDOW(predicate) ]
//               a) If I know that there exists a Subarray of Length X with sum <= k, then array me [1,..,X-1] length ke bhi subarrays honge with
//               sum <= k , So we can directly move l = X i.e l = mid
//               b) If Array me X length ka Subarray nhi hai with sum <= k, then array me length > X ka bhi koi valid subarray nhi honga becz
//               all the elements in array are Positive
// TIME ---> O(n * logn)

// NOTE --> As all the array elements are Positive, We can use Binary Search .. If negatives are allowed, BS cant be used
//          Ex -> [100, 100, -10, 100, -10] , k = 80  
//          Any Subarray with length 2 and sum <= 80 do not exist, but there exists Subarray with length 3 with sum <= 80 , no Monotonicity



// GOOD SEGMENT TECHNIQUE ------------------->>

// Define the Notion ( IMP to do ) -->
// GOOD SEGMENT --> A segment in the array that satisfies the condition Provided by the Question ...

// If a Subarray is of Length X is GOOD, then all the segments contained in X i.e Smaller length Subarrays possible from the GOOD subarray, 
// are also GOOD ...


void longestSubarray(vector<int> arr, int n,int k){

    int ans = 0 , sum = 0;

    int i=0, j=0;

    while(j < n){

        sum += arr[j];

        while( i <= j && sum > k){
            sum -= arr[i];
            i++;
        }

        ans = max(ans, j - i + 1);

        j++;

    }

    cout << ans << endl;

}

// 2. Find the Longest Subarray with not more than K distinct elements. 

// Similar to Above question, X length Subarray GOOD then Smaller length Subarrays possible from the GOOD subarray are also good

// In Such type of Distinct elements question, If Array Contains Duplicates, use Frequency MAP, If no Duplicates -> SET




// Decreasing Example ==================>>>

// 3. Given an array of Positive integers. Find the Smallest Subarray with sum >= K

// NOTE --> We can do this by BS + Sliding Window in O(nlogn)

// NOTION --> Subarray is GOOD if it has sum >= K 

// In the Previous Question, we want our ith pointer farthest from the j ( LONGEST ) ... Yha pe Humko ith pointer nearest chahiye ( SMALLEST ).. 
// Sirf Yhi nya hai iss question me. 

// Also, agar (i, j) -> GOOD, then (i+1, j) can also be GOOD i.e a Potential answer , ho bhi skta hai and nhi bhi
// If (i,j) -> GOOD hai to (i, j+1) bhi GOOD honga and Longest honga, Humko yeah nhi chahiye, So nearest i jha se condition satisfy nhi ho rhi hai
// GOOD subarray me, wha se Start krnge new Subarray ka Computation...


void smallestSubarray(vector<int> arr, int n,int k){

    int ans = INF , sum = 0;

    int i=0, j=0;

    while(j < n){

        sum += arr[j];

        while( i <= j && sum >= k){
            ans = min(ans, j - i + 1);
            sum -= arr[i];
            i++;
        }

        j++;

    }

    cout << ans << endl;

}


// ************************************************************ GENERAL TRICK ***********************************************

// Condition 1 --> If Segment [l,r] is GOOD, then all the segments enclosed within in will be GOOD.. 
//                  ( Use Increasing Technique )


// Condition 2 --> If Segment [l,r] is GOOD, then all the segments enclosing it will be GOOD.. (i.e (i.j) GOOD then (i-1,j),(i+1,j+1) -> GOOD)
//                  ( Use Decreasing Technique )


// NOTE --> Only try to get the Feel of Nearest and farthest ith pointer from j at 2 diff. conditions...

// REMEMBER, 2 pointer cant be used with Subsequence, or Subset






