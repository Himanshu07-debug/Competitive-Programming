// You are Given an Integer C. Let d be the smaller integer sucht that 2^d is strictly greater than C.
// Consider all pairs of non-negative integers (A, B) such that A, B < 2^d and A ^ B = C..

// Find the maximum value of A * B over all this pairs..

// Constraint ->  1 <= C <= 10^9


// LOGIC ---------------------------->>

// All pairs nhi bana sakte -> TLE
// C diya hai and All pairs have A ^ B = C ...
// From C, I can guess the bits of A & B
// MSB in C -> A ko denge ... Now A will be bigger than B becz yeah bit pe B -> 0
// Now, if 0 comes in C, A & B dono ko 1
// If 1 comes in C other than MSB, all goes to B


// NOTE --> Agar a * b max chahiye , them abs(a - b) minimum hona chahiye --> REMEMBER

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve(){

    // Your code here
    int a, b, c;  cin >> c;

    a = 0;
    b = 0;

    int d = c;

    int len = 0;
    while(d > 0){
        len++;
        d/=2;
    }

    // Giving first bit to a
    a += 1 << len;

    for(int i=0;i<len;i++){

        if(c & (1LL << i)){
            b += (1LL << i);
        }
        else{
            a += (1LL << i);
            b += (1LL << i);
        }

    }

    cout << a*1LL*b << endl;


}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}

