// You are given three integers x,y and n. Your task is to find the maximum integer k such that 0 ≤ k ≤ n that k mod x = y, where mod
// is modulo operation. 

// Constraint :  2 ≤ x ≤ 10^9 ; 0 ≤ y < x;  y ≤ n ≤ 10^9

// Input : x = 7 , y = 5 , n = 12345        Output : 12399
//  12339 = 7*1762 + 5 ( 12339 mod 7 = 5 )


// LOGIC : We have to find max element k <= N

// Remainder = N mod X

// There can be 2 cases : 

// Case 1 : rem >= y  => Diff = Remainder - y and Answer = N - Diff

// Case 2 : rem < y  =>  N = N - (Remainder + 1)  => Remainder = N % X => Same as Case 1 now

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int x, y, n;
 
    cin >> x >> y >> n;

    int rem = n % x;

    // CASE 1:

    // In the current cycle, n%x is greater than y
    if(rem >= y){

        int diff = rem - y;

        cout << (n - diff) << endl;

    }

    // CASE 2 :

    else{

        // rem < y i.e we have to move to the previous cycle for the equality
        n =  n - (rem + 1);

        rem = n%x;

        // now rem must be >= y

        int diff = rem - y;

        cout << (n - diff) << endl;

    }

    return 0;

}