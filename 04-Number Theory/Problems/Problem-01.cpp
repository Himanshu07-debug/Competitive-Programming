// P % a = P % b
// 2 ≤ a < b ≤ P    P --> Prime

// Constraint : 5 ≤ P ≤ 10^9  ,  2 ≤ a < b ≤ P

// LOGIC : Simple question becz constraint are helping , a can be 2 , and we remainder of 2 with any number is 0 or 1, so we will take a = 2

// P is Prime , so it will take only odd values, becz 2 is the only prime no. that is even and P starts from 5

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    int p;
    cin>> p;

    // Remiander -> 1 always as 2 which is the only even Prime number is not in Constraint of P
    cout << 2 << " " << (p-1) << endl;


    return 0;
}


