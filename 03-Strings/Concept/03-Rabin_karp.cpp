#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long get_hash(string s){

    long long h = 0;

    for(char c : s)  h = (h * 31 + (c - 'a' + 1)) % MOD;

    return h;
}

vector<int> rabin_karp(string s, string t){

    int n = s.size() , m = t.size();

    long long p = 1;

    for(int i=0; i < m-1 ;i++)  p = (p * 31) % MOD;

    vector<int> pos;

    long long ht = get_hash(t);
    long long hs = get_hash(s.substr(0,m));

    if(hs == ht)  pos.push_back(0);

    for(int l = 1, r = m; r < n; l++, r++){

        int del = (( s[l-1] - 'a' + 1 ) * p) % MOD;
        int add = s[r] - 'a' + 1;

        hs = ((hs - del + MOD) * 31 + add) % MOD;

        if(hs == ht){
            // REMEMBER, yha pe Spurious hit check karna padega
            pos.push_back(l);
        }

    }

    return pos;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s, t;
    cin >> s >> t;

    vector<int> occ = rabin_karp(s,t);

    for(int x : occ)  cout << x << " ";

    cout << endl;
    
    
    return 0;
}