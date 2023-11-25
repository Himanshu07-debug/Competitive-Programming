// You are given a string . Find the longest substring which is the prefix, suffix and also present in the middle of string other than Prefix
// and suffix. If No substring possible , Output -> Just a legend

// fixprefixsuffix  ------>> fix
// abcdabc  ---->> Just a legend

// Constraint --> 1 <= n <= 10^5


// LOGIC --------------------->>

// Realistic Thinking ==> 
// Agar prefix suffix same hai to hum beech me bhi check kar lenge wo prefix hai kya. Hum longest ke liye aage bhi try krnge

// Dividing in Chunks ===>
// O(n) me same nikal lenge lekin fir middle wali substring check krne ke liye O(n) by RABIN KARP i.e O(n^2) ho jayega

// We want the Longest possible valid PREFIX ====>> BINARY SEARCH ... Lekin kha ??
// We can store the indexes of valid Prefix in an array..
// Now valid indexes array me Binary Search and For each index predicate function me RABIN KARP se checking ==> O(n logn)
// Agar valid index ke array me mid wali substring hai middle me , then indx < mid wale bhi substring hongi beech me, move right 


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

bool check(string &s, long long len){

    string t = s.substr(0,len);

    int n = s.size() , m = t.size();

    long long p = 1;

    for(int i=0; i < m-1 ;i++)  p = (p * 31) % MOD;

    vector<int> pos;

    long long ht = get_hash(t);
    long long hs = get_hash(s.substr(0,m));

    long long cnt = 0;

    if(hs == ht)  cnt++ ;

    for(int l = 1, r = m; r < n; l++, r++){

        int del = (( s[l-1] - 'a' + 1 ) * p) % MOD;
        int add = s[r] - 'a' + 1;

        hs = ((hs - del + MOD) * 31 + add) % MOD;

        if(hs == ht)  cnt++;

    }

    return cnt > 2;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s; cin >> s;

    int n = s.size();

    vector<long long> hash(n);

    long long p = 1;

    long long h = 0;

    for(int i=0; i<n ; i++){
        h = (h + ((s[i] - 'a' + 1) * p)%MOD)%MOD;
        p = (p * 31ll) % MOD;
        hash[i] = h;
    }  

    h = 0;

    vector<long long> valid;

    for(int i=n-1 ; i>=0 ;i--){
        h = (h * 31ll) % MOD;
        h = (h + (s[i] - 'a' + 1)) % MOD;
        
        if(h == hash[n-i-1]){
            valid.push_back(n-1-i);
        }

    }

    long long l = -1 , r = valid.size();

    while(r - l > 1){

        long long mid = (l + r)/2;

        (check(s, valid[mid] + 1)) ? l = mid : r = mid; 

    }

    if(l < 0) cout << "Just a legend" << endl;
    else cout << s.substr(0, valid[l] + 1) << endl;
    
    
    return 0;
}
