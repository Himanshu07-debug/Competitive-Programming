// find the Permutation of Size N such that A[i] != A[i-1] OR A[i-2] for all 3 <= i <= N

// Permutation contains 1 to N no. exactly once (DISIINCT)

// CONSTRAINT --> 3 <= N <= 10^5

// 3  --->  1 3 2
// 4  ---> 1 2 4 3
// 5  ---> 2 1 5 3 4

// LOGIC ----------------------->>>

// We know that -> 
// Let X = a OR b  ---> X will be equal to either a / b , or X value will be greater ... This are only the 2 possibilities ...

// So agar hum arr[i-1] and arr[i-2] ko arr[i] se bigger rkhe to hum arr[i] kabhi equal nhi arr[i-1] OR arr[i-2] ke

// REMEMBER , Constraint mostly Logic deviate krne ke liye hote hai .. Ek bhi Sorted OUTPUT nhi diya hai


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here

    int n;
    cin >> n;

    for(int i=n;i>0;i--){
        cout << i << " ";
    }

    cout << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
    
    return 0;

}