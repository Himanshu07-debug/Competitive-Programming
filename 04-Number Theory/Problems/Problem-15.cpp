// Given an array A of integers and Q queries represented by two integers L and R, find the GCD (Greatest Common Divisor) of the array 
// after excluding the elements in the range from L to R (inclusive, 1-based indexing). It is guaranteed that the remaining array 
// after exclusion is non-empty.

// Constraint --> 1 <= Q,N <= 10^5

// N = 3 , Q = 3
// [2, 6, 9]
// Queries -->
// 1 1  -> 3
// 2 2  -> 1
// 2 3  -> 2


// LOGIC --------------------------->>>

// Yha akele Prefix Se kaam nhi banega, you have to exclude the middle part so how to get track of rightmost one , For right, We have to do Suffix
// So here we will us COMBO of Prefix and Suffix


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long nINF = LLONG_MIN;


void solve(){

    // Your code here
    int n, q;
    cin >> n >> q;

    vector<int> arr(n+1,0);

    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    int prefix[n+2] = {0};
    for(int i=1;i<=n;i++){
        prefix[i] = __gcd(prefix[i-1],arr[i]);
    }

    int suffix[n+2] = {0};
    for(int i=n;i>=1;i--){
        suffix[i] = __gcd(suffix[i+1],arr[i]);
    }

    while(q--){
        int x,y;
        cin >> x >> y;

        cout << __gcd(prefix[x-1],suffix[y+1]) << endl;
    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}