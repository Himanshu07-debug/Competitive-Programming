// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
// Return the answer in any order.

// Mobile pad = { "", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz" };

// INPUT -> "23"
// OUTPUT -> ["ad","ae","af","bd","be","bf","cd","ce","cf"]


// Constraints -> 0 <= digits.size() <= 4


// LOGIC -> 

// Draw the Recursion Tree.. Each letters of digits[0] will be mapped with all letters of digits[1] and each of digits[1] to all letters of dig[2]
//.... and so on...

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

vector<string> ans;
const vector<string> pad = { "", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz" };


void fun(string &s, string &temp, int indx){

    if(indx == s.size() ){
        ans.push_back(temp);
        return;
    }

    string t = pad[s[indx] - '0'];

    for( auto &key : t){
        temp.push_back(key);
        fun(s, temp, indx + 1);
        temp.pop_back();
    }

    // You can use this, but remove reference from temp, becz here apan assume kar rhe that at particular indx i, for each call, the temp 
    // is same , Reference liye to aaisa nhi honga, previous call ke appended characters remove nhi honge

    // for(int i=0;i<t.size();i++){
    //     temp.push_back(t[i]);
    //     fun(s, temp, indx + 1);
    // }


    // NOTE --> If temp ko reference me le rhe ho then while recursion calling, you cant do temp + t[i] .. Apko push_back use krna padega
    //      --> Without Reference wale me kar sakte ho



}


void solve(){

    // Your code here

    string s; 
    cin >> s;

    string temp;

    fun(s, temp, 0);

    for(auto &x : ans){
        cout << x << endl;
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
