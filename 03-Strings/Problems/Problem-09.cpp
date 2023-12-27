// The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'. For eg : "ACGAATTCCG" is a DNA sequence.
// Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a 
// DNA molecule. You may return the answer in any order.

// Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// Output: [ "AAAAACCCCC" , "CCCCCAAAAA" ] 
// NOTE -> Yhi 2 repeat hue.. First time 5 'C' hai, and second time 6 'C' hai contiguosly

// Constraint --> 1 <= s.length <= 10^5


// LOGIC ----------------------->>>

// Here window size is 10, all possible 10 sized substrings ko check krnge.. For freq, we will use MAP

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

vector<string> findRepeatedDnaSequences(string s) {

    int n = s.size();

    map<string, int> m;

    for(int i=0; i <= (n - 10) ; i++){

        string t = s.substr(i,10);    // s.substr() takes time equal to length i.e O(10) in this case

        m[t]++;     // O(log K) ( k -> k is the number of unique substrings of length 10 inserted in map)

    }

    vector<string> ans;

    for(auto [a, b] : m){
        if(b > 1){
            ans.push_back(a);
        }
    }

    return ans;
        
}




int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    vector<string> ans = findRepeatedDnaSequences(s);

    for(auto &x : s) cout << x << " ";

    cout << endl;
    
    
    return 0;
}


