// Polycarp needs to buy exactly n shovels from a shop that sells k types of packages, where each package contains i shovels (1 ≤ i ≤ k). 
// He wants to choose one type of package and buy the minimum number of packages to fulfill the requirement. Determine the smallest number of 
// packages Polycarp needs to buy to get exactly n shovels.

// For example, if n = 8 and k = 7 , then Polycarp will buy 2 packages of 4 shovels.

// CONSTRAINT -> 1 <= n,k <= 10^9

// LOGIC --> 

// We have to find the greatest divisor of n, but it should be K

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here
    long n ,k; 
    cin >> n >> k;

    long long mx = LLONG_MIN;

    for(long long i=1;i*i<=n;i++){
        if(n%i == 0){
            if(i <= k) mx = max(mx,i);
            if(n/i <= k) mx = max(mx,n/i);
        }
    }

    cout << n/mx << endl;
    

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
        
    }
    
    return 0;

}