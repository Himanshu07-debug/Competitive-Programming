// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// s1 = "ab", s2 = "eidbaooo"  -> True
// s1 = "ab", s2 = "eidboaoo"  -> False

// Constraint -> 1 <= n <= 10^5


// LOGIC --->

// Permuatation is same as Anagram Checking... 
// Only we have to ensure that the substring characters are Contigous in s2 for s1

// Contigous Substring Chahiye and Length Fixed hai -> s1.size() 
// SLIDING WINDOW with considering s1.size() as window size


#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s1, s2; cin >> s1 >> s2;

    if(s1.size() > s2.size()) return 0;
	    
    vector<int> cnt(256,0);
        
    for(char x : s1) cnt[x]++;
    
    int k = s1.size();
    
    vector<int> c(256,0);

    for(int i=0;i<k-1;i++){
        c[s2[i]]++;
    }
    
    long long ans = 0;

    for(int i=k-1;i<s2.size();i++){

        c[s2[i]]++;

        if(cnt == c){                   // O(256) Time i.e Constant
            cout << "YES" << endl;
            break;
        }
        
        c[s2[i-k+1]]--;
    }

    cout << "NO" << endl;

    return 0;
}

