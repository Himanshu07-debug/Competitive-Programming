// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses

// INPUT -> n = 3
// OUTPUT -> [ "((()))", "(()())", "(())()", "()(())", "()()()" ]

// CONSTRAINT -->  1 <= n <= 8



// LOGIC -------------->>

// See the Constraint --> VERY Small  ===> We can Go with RECURSION

// We will try out all possibilities of adding the open and Close Bracket...
// DRAW THE Recursion Tree
// Observation --> We can add open bracket anytime if no. of open bracket < n
//             --> We can add close bracket only if no.of Close bracket < Open Bracket

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void fun(int n, vector<string> &ans, string &temp, int open = 0, int close = 0){

    if(open == n && close == n){            // You can also Do -> temp.size() == 2 * n
        ans.push_back(temp);
        return;
    }

    if(open < n){
        temp.push_back('(');
        fun(n, ans, temp, open + 1, close);
        temp.pop_back();
        // Removal of Open is IMP from String becz next if me apan close ko append krnge uske jagah
    }

    // No need to check " close < n " as It is ensured By Open
    if(close < open){
        temp.push_back(')');
        fun(n, ans, temp, open, close + 1);
        temp.pop_back();
    }

}


void solve(){

    // Your code here

    int n;  cin >> n;

    vector<string> ans;
    
    string temp;

    fun(n, ans, temp);

    // NOTE --> We had pass our Parameters as reference, This is to avoid Creation of multiple copies of Temp.. This will harm the Space

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

