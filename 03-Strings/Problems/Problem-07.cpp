// A border of a string is a prefix that is also a suffix of the string but not the whole string. 
// For example, the borders of abcababcab are ab and abcab.
// Your task is to find all border lengths of a given string.

// Constraints -> 1 <= n <= 10^6

// LOGIC -------------------->>

// There are 2 Approaches ------>>

// Approach 1 ===========================>
// We know that ki border n/2 se jyada nhi honga becz same substring muje right me bhi chahiye .. n/2 se big kiya to right wali less that n/2 hongi
// To hum first n/2 characters ke hash aaise nikalenge --> hash[i] = hash[i-1] + (s[i] * p )  ,, p = p * 31
// Last ke n/2 hum reverse traverse krnge and unka hash --> hash[i] = hash[i+1]*p + s[i]  ,, p = p * 31

// Dry run krke dekho hash same aa rhe hai checking ke liye



// APPROACH 2 ===========================>>>

// (0, i) ka corresponding (n-1-i , n-1) range ke hash value se check krnge
// Suffix Prefix nhi rhnga, Same like Prefix, Ek hi Prefix array rhnga


// NOTE => Hum Second Approach use krnge .. First one is also easy ..
// In Both of them, For Double hashing, use 2 hash array -> hash1  & hash2


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    
    
    return 0;
}
