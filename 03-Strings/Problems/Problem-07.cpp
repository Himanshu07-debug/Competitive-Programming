// A border of a string is a prefix that is also a suffix of the string but not the whole string. 
// For example, the borders of abcababcab are ab and abcab.
// Your task is to find all border lengths of a given string.

// Constraints -> 1 <= n <= 10^6

// LOGIC -------------------->>

// prefix of length i = suffix of length i

// There are 2 Approaches ------>>

// Approach 1 ===========================>
// We know that ki border n/2 se jyada nhi honga becz same substring muje right me bhi chahiye .. n/2 se big kiya to right wali less that n/2 hongi
// To hum first n/2 characters ke hash aaise nikalenge --> hash[i] = hash[i-1] + (s[i] * p )  ,, p = p * 31
// Last ke n/2 hum reverse traverse krnge and unka hash --> hash[i] = hash[i+1]*p + s[i]  ,, p = p * 31

// Dry run krke dekho hash same aa rhe hai checking ke liye


// APPROACH 2 ===========================>>>

// (0, i) ka corresponding (n-1-i , n-1) range ke hash value se check krnge...

// OBSERVE -> Rabin karp jaisa ek common Power se multiply nhi kar sakte subtraction of l-1 part ka becz yha fixed window size nhi hai ..
//            Apko Yaa to prefix[l-1] me 31^(j-i) multiply krna padega yaa prefix[r] se 31^(j-i) divide krdo



// NOTE => Hum Second Approach use krnge .. First one is also easy ..
// In Both of them, For Double hashing, use 2 hash array -> hash1  & hash2


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long bin_powerModulo(int a, int b){

    a %= MOD;

    long long res = 1;

    while(b > 0){

        if(b&1)  res = res * a % MOD;

        a = a * a % MOD;

        b = b >> 1;

    }

    return res;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;

    long n = s.size();

    long long p1 = 31 , mod1 = 1e9 + 7;
    long long p2 = 37, mod2 = 1e9 + 9;

    vector<long long> hash1(n, 0) , hash2(n, 0);

    hash1[0] = hash2[0] = s[0] - 'a' + 1;

    for(long long i = 1; i < n ; i++){

        hash1[i] = (hash1[i-1] + (s[i] - 'a' + 1) * bin_powerModulo(p1, i)) % mod1;
        hash2[i] = (hash2[i-1] + (s[i] - 'a' + 1) * bin_powerModulo(p2, i)) % mod2;

    }

    for(int i = 1; i < n ; i++){

        // Checking hashPrefix = hashSuffix

        long long hash1prefix = hash1[i-1];
        long long hash2prefix = hash2[i-1];

        

    }

    
    
    return 0;
}
