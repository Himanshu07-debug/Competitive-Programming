// you're given a string and need to determine if it fits the pattern of a cat's meow. The string should start with 'm' or 'M', 
// followed by 'e' or 'E', then 'o' or 'O', and finally 'w' or 'W'.

// Given a string, check if it represents a cat's meowing sound.

// Example:

// Input: "meow"
// Output: YES
// Input: "MmeEoOwW"
// Output: YES
// Input: "Mweo"
// Output: NO


// LOGIC --> 

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    int n; cin >> n;

    string s; cin >> s;

    int i = 0;
    
    int a = -1, b = -1, c= -1, d = -1;

    while (i < n && (s[i] == 'm' || s[i] == 'M')) {
        a=1;
        i++;
    }

    while (i < n && (s[i] == 'e' || s[i] == 'E')) {
        b=1;
        i++;
    }

    while (i < n && (s[i] == 'o' || s[i] == 'O')) {
        c=1;
        i++;
    }

    while (i < n && (s[i] == 'w' || s[i] == 'W')) {
        d=1;
        i++;
    }

    if(i == n && a == 1 && b==1 && c == 1 && d==1 ) cout << "YES" << endl;
    else cout << "NO" << endl;
    

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