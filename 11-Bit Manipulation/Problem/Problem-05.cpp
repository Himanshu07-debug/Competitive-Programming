// You are given an Integer N . Consider the sequence of Integers 1, 2, 3, ...., N in increasing order (all distinct).
// Find the length of the longest subarray in the sequence such that bitwise AND of all elements in the subarray is Positive


// LOGIC --------------------->>>

// Suppose N = 7 ... 
// 001, 010, 011, 100, 101, 110, 111 
// 1 ka AND 2 se kronge 0 .... Similarly 3 ka AND 4 se kronge 0 ..
// Breaking down non-zero subsrrays --> 
// (1) , (2, 3) , (4, 5, 6, 7) ...

// ONSERVATION ---->>

// Perfect Powers of 2 me sirf 1 set bit hota hai , uske ek piche wale me saare bits set rhte hai .. Inka AND hamesha zero honga


// We want the Longest Subarray --> Yeah hamesha last wala subarray honga.. Lekin N kam diya hai ex. 10, then 8 -> 15 tk ka subarray ban hi nhi
// payenga and apna second subarray from right will be LONGEST


// HOW TO DETERMINE KI FOR ANY VALUE OF N , HUM KITNE POWER OF 2 TK JAA RHE HAI ???
// pow(2, p) = N  --> Taking log on BOTH side --> p = log(N)/log(2)


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

typedef long long ll;



void solve(){

    // Your code here
    long long n; cin >> n;

    long long p = log(n) / log(2);   // FLOOR DIVISION

    long long ans1 = n - pow(2,p) + 1;   // For n = 15, we will n = 3

    long long ans2 = INT_MIN;

    // If Previous subarray exist
    if(p - 1 >= 0){
        ans2 = pow(2,p) - pow(2,p-1);
    }

    cout << max(ans1, ans2) << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}