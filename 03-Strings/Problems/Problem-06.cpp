// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [ ["bat"], ["nat","tan"], ["ate","eat","tea"] ]

// Constraints -> 1 <= strs.length <= 10^4   ,,  0 <= strs[i].length <= 100


// LOGIC --------------------->>

// Brute nhi kar sakte, wo TLE denga i.e For string s[i] find all possible anagram from s[i+1] to s[n-1]

// Hum cnt array ko map ke key me use kar sakte hai, same cnt array wale string ko value me add kar lenge ....
// We can also use Sorted auixilary strings as a key in map

// Comparision in Approaches ------------->>

// map<vector<int>,vector<string>> m;  --->  BRUTE ( key is cnt array )

// value me string ke indx store karenge
// map<vector<int>,vector<int>> m;    -----> BETTER 

// SORTING ------------>>
// map<string,vector<int>> m;   -----> BEST ( using least memory )

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    map<string,vector<int>> m;

    for(int i=0;i<strs.size();i++){

        string t = strs[i];
        sort(t.begin(),t.end());
        m[t].push_back(i);

    }

    vector<vector<string>> ans;

    for(auto [a,b] : m){
        vector<string> s;
        for(int x : b){
            s.push_back(strs[x]);
        }
        ans.push_back(s);
    }

    return ans;
        
}



void solve(){

    // Your code here
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto &x : ans){
        for(auto &y : x){
            cout << y << " ";
        }
        cout << endl;
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