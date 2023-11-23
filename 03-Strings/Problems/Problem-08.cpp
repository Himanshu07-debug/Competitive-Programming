// Given a string s, find the length of the longest substring without repeating characters.

// "abcabcbb"  ---> 3 ( "abc" )

// Constraint --> 0 <= s.length <= 5 * 10^4

// LOGIC -------------->>

// Similar to Variable length Sliding window

// REMEMBER, In sliding window , Indx j ko window me insert krne se phle Condition wla while check kro, uske baad Jab window valid ho jaaye arr[j]
// insert krne ke liye , Then INSERT

// In case of String, You can avoid using SET, MAP agar cnt[256] se ho skta ho code

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int lengthOfLongestSubstring(string s) {

    if(s.size() == 0) return 0;
    
    int cnt[256] = {0};

    int res = INT_MIN;

    int st = 0;

    for(int j=0; j < s.size(); j++){
        while(st < j && cnt[s[j]]){
            cnt[s[st]]--;
            st++;
        }

        res = max(res, j-st+1);

        cnt[s[j]]++;
    }

    return res;

}



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s; cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;
    
    return 0;
}


