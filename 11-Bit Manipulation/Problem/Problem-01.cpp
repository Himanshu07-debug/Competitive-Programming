// Given an Integer N, find four distinct integers a, b, c and d such that :
// 1 <= a, b, c, d <= 10^18
// ( (a & b) | c ) ^ d = N

// 0 <= N < 2^32

// If there are Multiple answers, print any of them .. If no answer, then -1


// LOGIC ------------------>>

// Think in Chunks.. If a & b == 0 , then our problem will reduce to c ^ d = N  .. Which is much EASY to solve

// a & b = 0  ==> a = 2^35  and b = 2^36 ... They both consists only one set bit and at different positions. a , b <= 10^18 .. So no ISSUE

// c ^ d = N  ===> c = 1 , d = N ^ 1  ==> 1 ^ (N ^ 1) ==> N

// Bit Manipulation TIP -> Think About Edge cases becz answer mostly differ at edge case in Bit questions

// What kind of I/P will make our solution FAIL ???

// N = 0 , becz c and d will have same value .. Let c = x, d = (0 ^ x) => x ... NOT DISTINCT

// Ab a & b = 0 nhi rakh sakte becz then c ^ d = 0 i.e c == d hona padega

// Now -> ( (a & b) | c ) ^ d = N  ==> ( (a & b) | c ) = d .. Therefore take any random distinct values for a, b, c
// Solve for 5 4 2 => d = 6

// FOR N == 1, d will come as 0 -> Not Allowed
// c = 3, d = 2


// TIP -> Bit is nothing but breaking the Problem into Small - small cases


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve(){

    // Your code here
    int n;
    cin >> n;

    if(n == 0){
        cout << "5 4 2 6" << endl;
    }
    if(n == 1){
        cout << (1LL << 35) << " " << (1LL << 36) << " " << 2 << " " << 3 << endl;
    }
    else{
        cout << (1LL << 35) << " " << (1LL << 36) << " " << 1 << " " << (n^1) << endl;
    }

    // For shifts with large no.s , use 1LL / 1ll

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}