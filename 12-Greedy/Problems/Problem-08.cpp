// Given a number n . Find 3 distinct integers a,b,c such that a * b * c == n where 2 <= a, b, c 
// Constraint -> 1 <= n <= 10^9

// 64 --> 2 4 8
// 32 --> No


// LOGIC -------------->>

// Yeah Prime Factorization se ho jayega.. But Did you really want to do so, easy way me nhi ho sakta ???
// a,b,c prime factors nhi bhi hue to chalta, divisors hona chahiye

// If want to do by Prime Factorization ------------->>
// Let n has p prime factors
// if p = 1, then power of p should be atleast 6 (2, 2^2, 2^3)
// if p = 2, then n / p1*p2 ,, p1 or p2 ke equal nhi aana chahiye
// if p = 3, then No Problem


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    long long n; cin >> n;

    long long a = 1, b = 1, c = 1;

    for(int i=2;i*i <= n;i++){

        if(n%i == 0){
            a = i;
            break;
        }

    }

    n = n/a;

    for(int i=2;i*i <= n;i++){
        if(n%i == 0 && i != a){
            b = i;
            break;
        }
    }

    n = n/b;

    c = n;

    if(a == 1 || b == 1 || c == 1 || a==b || b == c || a==c) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << a << " " << b << " " << c << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}




