// You are given an integer n . In one move, you can either multiply n by two 
// or divide n by 6 (if it is divisible by 6 without the remainder). 
// Your task is to find the minimum number of moves needed to obtain 1 from n or determine if it's impossible to do that.

// 1 <= n <= 10^9

// Input : 1 -> 0 , 2 -> -1 , 3 -> 2



// LOGIC : This types of questions are pure mathemathical, Math ke Problem jaisa socho and prove kro pen-paper me

// Apne ko n ko reduce 1 me krna hai, 2 se multiply krke n 1 se durr honga aur, so we cant do that, Divide hi suitable
// Operation hai

// If n prime factorization contains numbers other than 2 and 3 , then it can never reduce to 1 becz 2*3 ko 6 cancel 
// kar denga, Lekin jo samne ke factors rhnge wo waise hi rhnge and hence n equal to 1 nhi honga

// n = 2^a * 3^b ( Agar aaisa n hai, tabhi aage proceed krnge 1 ke liye)

// There can be 2 cases here :
// a <= b : Hum multiply kar denge 2 se n ko till a == b
// a > b  : multiplication by 3 is not allowed, so here also it is impossible to reduce N to 1



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n;
    cin >> n;

    int a=0 , b=0;

    while(n%2 == 0){
        a++;
        n/=2;
    }

    while(n%3 == 0){
        b++;
        n/=3;
    }

    if(n>1){
        cout << -1 << endl;
        return 0;
    }

    if(a <= b) cout << (b - a) + b << endl;  // (b-a) power equal krne ke liye and b operation for dividing
    else cout << -1 << endl;
    
    return 0;
}

