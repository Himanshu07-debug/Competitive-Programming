#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Increasing Condition ------------------------->>

// Given an Array of +ve integers, find the Number of Subarrays with sum <= k

// Agar X length good Subarray mila, to uss segment se bne smaller length Subarray bhi GOOD honge, humko unhe bhi cnt krna hai...

// No. of Subarrays possible ending with last index of array ..
// [1,2,3, ... , n]  --> n possible Subarrays...

// So har ek valid window me index j pe end krne wale kitne i possible hai, we will cnt

// [1,3,2] is GOOD ---------------->
// [1] -> 1
// [1,3] -> 2 ( [1,3] , [3] )
// [1,3,2] -> 3 ( [1,3,2] , [3,2] , [2] )



void numberOfSubarrays(vector<int> arr, int n,int k){

    int ans = 0 , sum = 0;

    int i=0, j=0;

    while(j < n){

        sum += arr[j];

        while( i <= j && sum > k){
            sum -= arr[i];
            i++;
        }

        ans  +=  (j - i + 1);

        j++;

    }

    cout << ans << endl;

}


// Decreasing Condition ------------------------->>
