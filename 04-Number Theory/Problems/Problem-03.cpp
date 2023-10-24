// find the maximum possible product of digits among all integers from 1 to n

// 1000000  ---> 999999  ,   390 ---->> 389

// Constraint : 1 ≤ n ≤ 2 * 10^9

// LOGIC : We want max 9 in our number so that we can maximize the product. But we cant make them directly, See -> 389 > 299 [Product Comparison]

// Hum RHS se 9 daalenge one by one and will compare it with the other Possible answer

// HOW TO ADD 9 ENSURING THAT THE NUMBER FROMED WILL BE LESS THAN N ??

// ----> For Example -> Take a Number N = 2478

// *************** BEAUTIFUL TECHNIQUE ***********************

// N++ -> 2479
// 2479 * 1 - 1 = 2478 ( original num)
// 247 * 10 - 1 = 2469 (last me 9)
// 24 * 100 - 1 = 2399 (last me 99)
// 2 * 1000 - 1 = 1999 (last me 999)  

// All possible maximum value number generated , Find Maximum in them


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

long long product(long long n){

    long long res = 1;

    while(n > 1){
        res *= n%10;
        n/=10;
    }

    return res;

}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

   long long n;
   cin >> n;

   n++;

   long long p =  1;
   long long ans = 1;

    while(n>0){
        ans =  max(ans, n*p - 1);
        n/=10;
        p*=10;
    }

    cout << ans << endl;


    return 0;
}