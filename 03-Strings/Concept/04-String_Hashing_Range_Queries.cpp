#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// Determine that s[l,r] is equal to pattern t   ... abs(l - r) == t.size()

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    string s, t; cin >> s >> t;

    long long q;  cin >> q;

    int n = s.size();

    vector<long long> pow1(n);

    long long p1 = 31;

    pow1[0] = 1;
    
    // Calculating Powers Array
    for(int i = 1; i < n; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
    }

    long long hs = 0;

    for(int i=0 ; i < t.size() ;i++){      

        hs = (hs * 31ll) % MOD;
        hs= (hs + (t[i] - 'a' + 1)) % MOD;

    }


    vector<long long> hash2(n);

    long long h = 0;

    for(int i=0 ; i < n ;i++){      

        h = (h * 31ll) % MOD;
        h = (h + (s[i] - 'a' + 1)) % MOD;
        hash2[i] = h;

    }

    while(q--){

        int l, r; cin >> l >> r;

        long long hash;

        if(l == 0){
            hash = hash2[r];
        }
        else{
            hash = (hash2[r] - (hash2[l-1] * pow1[r-l+1])%MOD)%MOD;   
            // REMEMBER --> Power indx calculation ( r - (l-1) )
            // Here kyuki bola hai ki l and r ki size pattern ki size rhngi, Aap fixed power se multiply kar sakte ho hash2[l-1] ko

            if(hash < 0)  hash += MOD;
        }

        if(hash == hs){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;

    }    
        
    return 0;
}