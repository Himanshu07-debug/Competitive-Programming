// ****************************** GREEDY ************************************

// --> Choosing the most optimal option at every Step
// Ex -> N houses have different no. of Coins. thief can select only k houses to Rob. Kinko krnga ROB ??
// -> Thief ko max Profit chahiye to K houses max. coins wale rob krnga i.e each step 1st max, 2nd max , so on.. THIS IS ONLY GREEDY  


// ************************ Questions Where We think in an GREEDY way **************************************


// ------------------------------------------------>> 1. Kadane Algorithm 

// Find the largest sum subarray ..

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


long long kadane(vector<long long> &arr, int n){

    long long res = NINF;

    long long curr = 0;

    for(int i=0; i<n ;i++){

        curr += arr[i];

        res = max(res,curr);

        // Reseting current sum becz current index i ne isko -ve kar diya i.e arr[i] is sure -ve .. Will never Contribute to the longest sum
        if(curr < 0) curr = 0;

    }

    return res;

}

// Find the Minimum Subarray Sum ------>>

long long min_kadane(vector<long long> &arr, int n){

    long long res = INF;

    long long curr = 0;

    for(int i=0; i<n ;i++){

        curr += arr[i];

        res = min(res,curr);

        // Reseting current sum becz current index i ne isko +ve kar diya i.e arr[i] is sure +ve .. Will never Contribute to the Minimum sum
        if(curr > 0) curr = 0;

    }

    return res;

}


// Max Subarray sum when Circular subarray are allowed ----------------------->

// For max Circular Subarray sum ---> (Total sum - Min subarray sum)

long long circular_kadane(vector<long long> &arr, int n){

    long long mx = kadane(arr,n);

    if(mx < 0){
        // This happens only when all array elements are -ve
        return mx;
    }

    long long total = 0;

    for(int i=0;i<n;i++) total += arr[i];

    long long circular_mx = total - min_kadane(arr,n);

    return max(circular_mx, mx);

    // NOTE -> Humne mx < 0 phle check kiye becz When all array elements are -ve, circular_mx will be 0 and 0 return ho jaega -> WRONG

}



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    cout << kadane(arr, n) << endl;

    cout << circular_kadane(arr , n) << endl;
    
        
    return 0;
}