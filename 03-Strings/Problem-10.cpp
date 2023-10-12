// You are given a positive integer N. Note that N may exceed the range of a 64-bit integer.
// Find a positive integer M (without leading zeroes) divisible by 8, formed by changing minimum number of digits in N.
// Note that the number of digits in M must be equal to the number of digits in N.
// If there are multiple answers, you may print any one of them.

// Input : 1 7   ==> 8
// Input : 3 512   ==> 512
// 4 1044 => 1144  .. etc

// Constraint : 1<= N <= 10^1000 


// Logic : A number is divisible by 8 if its last 3 number are divisible by 8.. i.e we only have to check the 
//          the last 3 number

// Observe carefully, 8 hai, so increment dusre number pe 8 ke table me within 10 honga i.e starting 2 digit always
// valid rhngi, apne ko sirf dekhna hai wo 2 digit ke sath konsa 3rd number [0-9] lagake wo 8 se divisible hai
// Example -> 08 16 24 32 40 48 56 64  .. see the first digit, all number in a number series will come serially.
//            0  1  2  3  4  4  5  6

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);



    
    return 0;
}


// NOTE : Divisibilty by 3 -> Sum of digits of given number should be divisible by 3