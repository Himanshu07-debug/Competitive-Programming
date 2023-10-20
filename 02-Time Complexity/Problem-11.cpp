// You are given two integers n and k . Your task is to find if n can be represented as a sum of k distinct positive odd integers or not.

// 3,1 -> YES (3),  4,2 --> YES (1 + 3) ,    10,3 ---> NO

// Cosntraint : 1<= n,k <= 10^7

// LOGIC : If n is even, then k should be even becz ( odd + odd = even )
//         if n is odd, then k should be odd (odd + odd + odd = odd)

// HOW TO HANDLE DISTINCT PART ??? 
// If k = 3, and n = 13,  then 1 + 3 + 5 < 13, we will only update the last one, i.e we are sure ans will exist -> 5 to 9 [ 1+3+9 = 13 ]
// This means apne ko k tk ka sum le lenge, agar equal nhi aaya to last wale element me ( n - sum ) add kar denge

// This means Answer is always YES only there is one the Edge case to handle ->
// k=3 but n = 3 ==> Then n < sum of k odd numbers, --->> NO

// To get kth sum of Odd numbers -> k*k      ( 1 + 4 + 9 + 16 + ... )
// To get kth sum of Odd numbers -> k*(k+1)  ( 2 + 6 + 12 + 20 + ... )

// A.P ke sum wale formulae se nikale


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n,k;
    cin >> n >> k;

    if(n&1){

        if(!(k&1) || k*k > n ) cout << 'NO' << endl;
        else cout << 'YES' << endl;
    }
    else{

        if((k&1) || k*(k+1) > n ) cout << 'NO' << endl;
        else cout << 'YES' << endl;

    }

    return 0;
}