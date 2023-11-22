// You are given an Array of size n. In one operation --> 
// You can select an Integer K such that -> 
// X => arr[i_1] & arr[i_2] & ............. & arr[i_k] 
// Subtract this X from all selected K indexes..
// arr[i_1] = arr[i_1] - X
// ...
// arr[i_k] = arr[i_k] - X

// Find all possible value of K such that the entire array becomes 0 ?



// LOGIC ------------------------------------>>>

// X me 1 means saare selected k indexes ke wo bit position pe 1 hai ....
// By subtracting X, sabke wo bit position 0 ho jayenge becz humne pow(2,i) subtract kar diye ...........

// Lekin K ke konse value le sakte hai???
// Jaise 1 to hamesha hi le sakte hai becz 1 element liye aur usko subtract kar diye wahi element se 0 banane ke liye .. 
// Waise hi aue konse k ke value le sakte hai ??

// OBSERVATION -> Entire array ko agar 0 krna hai to, Frequency of each bit must be divisible by K . Becz agar cnt k se divisible nhi to ..
//                K indexes select karke bhi 0 nhi kar paonge ..

// Kyuki hume all possible solution chahiye K ke .. Hum Greatest common divisor nikal lunga from all bit positions frequencies .. 

// Now all possible divisors of GCD can be our K value..
// For example -> GCD = 4 ... Then K = 1, 2 bhi se bhi array 0 ho jayenga


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



void solve(){

    // Your code here
    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0;i < n;i++) cin >> arr[i];

    int cnt[32] = {0};

    for(int i=0;i<n;i++){
        for(int j = 0; j < 30;j++){
            if(arr[i] & (1 << j)) cnt[j]++;
        }
    }

    int ans = 0;

    for(int i=0;i<30;i++){
        ans = __gcd(ans, cnt[i]);
    }

    for(int i=1; i <= n;i++){
        if( ans % i == 0){
            cout << i << endl;
        }
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

