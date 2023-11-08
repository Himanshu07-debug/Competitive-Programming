// There is an entire deck of n cards. The values of cards from the topmost to the bottommost are integers a1,a2, .. , an , and 
// all values are different.

// Shuffle the deck m times. With the j-th shuffle, you should take bj topmost cards and move them under the remaining (n − bj)
// cards without changing the order.

// Can You tell him the Topmost element after the m times shuffle...

// n = 4  [ 3 1 4 2 ]
// m = 2  ==> 3 1
// 3  
// first shuffle -> [2, 3, 1, 4]  , second shuffle -> [3, 1, 4, 2]

// Constraint -> 1 <= m,n <= 2 * 10^5


// LOGIC --> 

// Do not think for Queue or Reversal Algorithm becz they will give Definitely give TLE and You cant optimize it.. 

// After n shuffles, the topmost element will be a1
// 1 shuffle -> a2 , 2 shuffle -> a3 and so on ...

// Aap kitne baar bhi n shuffles kro, a1 hi rhnga TOP pe

// Its like a CYCLE, MODULO can help , sum of given m shuffles -> sum % n  -> will tell you the indx of the array which will be on the top

// 0 (multiple of n) => arr[0]  ,, 1 => arr[1] [arr[0] niche gya 1 shuufle me]  .. SO ON   5 => arr[5] i.e last element at the top

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here
    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int m; cin >> m;

    long long sum = 0;

    for(int i=0;i<m;i++){
        int x; cin >> x;
        sum += x;
    }

    cout << arr[sum % n] << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }

    return 0;

}


