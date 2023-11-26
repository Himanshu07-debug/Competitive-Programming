// A border of a string is a prefix that is also a suffix of the string but not the whole string. 
// For example, the borders of abcababcab are ab and abcab.
// Your task is to find all border lengths of a given string.

// Constraints -> 1 <= n <= 10^6

// LOGIC -------------------->>

// prefix of length i = suffix of length i

// Approach ===========================>
// We know that ki border n/2 se jyada nhi honga becz same substring muje right me bhi chahiye .. n/2 se big kiya to right wali less that n/2 hongi
// To hum first n/2 characters ke hash aaise nikalenge --> hash[i] = hash[i-1] + (s[i] * p )  ,, p = p * 31
// Last ke n/2 hum reverse traverse krnge and unka hash --> hash[i] = hash[i+1]*p + s[i]  ,, p = p * 31

// Dry run krke dekho hash same aa rhe hai checking ke liye


// APPROACH 2 ===========================>>>

// (0, i) ka corresponding (n-1-i , n-1) range ke hash value se check krnge...

// OBSERVE -> Rabin karp jaisa ek common Power se multiply nhi kar sakte subtraction of l-1 part ka becz yha fixed window size nhi hai ..
//            Apko Yaa to prefix[l-1] me 31^(j-i) multiply krna padega yaa prefix[r] se 31^(j-i) divide krdo




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    string s; cin >> s;

    int n = s.size();

    // **************************************** APPROACH 1 *************************************************

    vector<long long> hash(n);

    long long p = 1;

    long long h = 0;

    for(int i=0; i<n ; i++){
        h = (h + ((s[i] - 'a' + 1) * p)%MOD)%MOD;
        p = (p * 31ll) % MOD;
        hash[i] = h;
    }  

    h = 0;

    for(int i=n-1 ; i >= 1 ;i--){          // i >= 1 becz whole string ka length return nhi krna hai
        h = (h * 31ll) % MOD;
        h = (h + (s[i] - 'a' + 1)) % MOD;
        
        if(h == hash[n-i-1]){
            cout << n - i << endl;    // (n - i - 1) + 1 ==> n - i
        }

    }

    cout << " -------------- APPROACH  2 ----------------- " << endl;


    // ******************************** APPROACH 2 *************************************************

    // String HASHING for Query of RANGES -->> 

    // TIP ===> In case of Answering Query for different ranges, make Powers array

    vector<long long> pow1(n);

    long long p1 = 31;

    pow1[0] = 1;
    
    // Calculating Powers Array
    for(int i = 1; i < n; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
    }

    vector<long long> hash2(n);

    h = 0;

    for(int i=0 ; i < n ;i++){      

        h = (h * 31ll) % MOD;
        h = (h + (s[i] - 'a' + 1)) % MOD;
        hash2[i] = h;

    }

    for(int i=0; i < n-1 ; i++){

        long long prefix = hash2[i];
        long long suffix = (hash2[n-1] - (hash2[n-i-2] * pow1[i+1])%MOD)%MOD;
        if(suffix < 0) suffix += MOD;

        if(prefix == suffix) cout << (i+1) << endl;

    }

}

 
 