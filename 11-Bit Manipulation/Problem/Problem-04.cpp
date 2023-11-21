// Given an array . Find the minimum no. of Operations required to convert all integers to 0
// In one operation -> Choose a non-negative integer p (p >= 0)
//                  -> Select at most k indices in the array
//                  -> For each selected index i, replace arr[i] with (arr[i] ^ pow(2,p) )

// LOGIC ----->> 

// Power of 2  ---> isko aap as a HINT le sakte ho For using BIT logic here

// This is a Bit Independent Problem. We can think for each bits separately

// Ek array lo -> [4, 5, 6, 7, 8] , k = 2

// Start Assuming no. in bits

//          16  8  4  2  1
// 4 ==>    0   0  1  0  0
// 5 ==>    0   0  1  0  1
// 6 ==>    0   0  1  1  0
// 7 ==>    0   0  1  1  1
// 8 ==>    0   1  0  0  0


// Suppose humne p = 0 liye then i.e pow(2, 0) --> last bit 
// We will select 5 and 7 as k = 2 and make them as 0 in one operation --> 5 and 6 ko jab xor kronge pow(2,0) ke sath unke last bit 0 ho jayenge

// Similarly for pow(2, 1) i.e bit position => 2 ... Take 6 and 7

// For pow(2, 2) --> In one operation take 4 , 5 and in second operation take 6, 7 ==> Total 2 operations required in bit position 2

// For pow(2, 3) --> 1 hi bit hai, usko 0 krne ke liye 1 operation

// Therefore, for any bit position, Total no. of operation is ceil( count(1) / K )


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


void solve(){

    // Your code here
    int n,  k; cin >> n >> k;

    int arr[n];
    for(int i=0;i < n; i++) cin >> arr[i];

    map<int,int> m;

    for(int i=0;i< n;i++){
        for(int j=0;j < 31;j++){
            if(arr[i] & (1 << j)) m[j]++;
        }
    }

    long long ans = 0;

    for(auto [a,b] : m){
        ans += (b + k - 1)/k;
    }

    cout << ans << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}




