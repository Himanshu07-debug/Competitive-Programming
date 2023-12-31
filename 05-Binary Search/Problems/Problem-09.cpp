// You are given an array a of n integers, where n is odd. You can make the following operation with it: Choose one of the elements of the array 
// (for example ai ) and increase it by 1 (that is, replace it with ai+1 ). 
// You want to make the median of the array the largest possible using at most k operations.

// n = 3, k = 2 , [1,3,5]  --> 5


// LOGIC ------------------------------------->>>

// We have to maximize the median value .... 
// Search Space -> T T T T T T F F F F F F
// Last T is the Max. Satisfying pt. to our Condition -> use BS to find it ....


// Predicate function is easy -> 
// Hume x ko median bna sakte hai kya, yeah check krna padega ...
// For this, there should be n/2 elements lesser than x and n/2 elements greater than x in the array...
// So we will sort the array... And [mid, n-1] ko mid ke equal bna denge...
// So.. [0,mid-1] -> lesser than mid AND [mid,n-1] == equal  ---> Median ==> [mid]


//  REMEMBER -> Predicate function ek bhi cheez miss nhi kar sakta Question ke condition ki... 
//              For the case, when current x se n/2 ke aage wale elements greater rhnge, so here x can be the Potential answer...
//              So yeah consider ho isliye hum cnt me 0 add krnge when arr[i] > m and aage max. value of mid ke liye try kro... 
//              When arr[i] < m honga, Now ab k operation ka test shuru honga to check the max value of mid...
//              samne wale n/2 elements ko mid tak increase krnge and number of operation calculate krnge.. If cnt > K -> FALSE...


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

bool fun(vector<long long> &arr, long long n, long long k, long long m){

    long long cnt = 0;

    for(int i=n/2 ; i < n;i++){

        cnt += max(0ll, m - arr[i]);   // m > arr[i] ==> aap increase kar sakte ho, decrease nhi

        if(cnt > k) return false;

    }

    return true;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n,k; cin >> n >> k;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    long long l = 0 , r = 1e18;

    while(r - l > 1){

        long long m = (l + r)/2;

        if(fun(arr,n,k,m)) l = m;
        else r = m;

    }

    cout << l << endl;
    

    return 0;
}

