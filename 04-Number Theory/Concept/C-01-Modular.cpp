
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long mod = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    long long a = 1e18;
    long long b = 1e18;

    long long add = (a%mod + b%mod) % mod;

    long long mul = ( (a%mod) * (b%mod) ) % mod;

    // Remember in Other Programming Languages, when you divide a -ve number , to keep the remainder as Positive, the divsion occurs like 
    // this :  if n = -13 and divisor = 5 , Quotient will be -3 and Remainder --> 2 i.e -13 - (5 * -3) => -13 + 15 -> 2

    // But thats not the case in C++, in above example Quotient will be -2 and remainder will be -3 --> -13 - (5 * -2) => -13 + 10 -> -3

    // REMEMBER --> Negative remainders are not ACCEPTED in most cases

    // So to handle that -> -3 + 5 ==> 2 (ANS)

    long long sub = (((a%mod - b%mod)%mod) + mod) % mod;


    // ***************************************** REMEMBER ******************************************************

    // MOD increases the time of computation, yes bhut kam increase krta hai, neglect kar sakte hai, but not a good Practice.. Avoid unnecessary
    // MOD's

    // Also const specified with MOD declaration make % faster

    return 0;
}