
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// NOTE : Kabhi bhi pow() wla function mat use krna, it takes a,b parameters as float and returns an float ans which might have precision errors

// O(log N)
int power(int a , int b) {
    if(b==0){
        return 1;
    }

    int half_power = power(a, b/2);

    if(b&1){
        return half_power * half_power * a;
    }
    else {
        return half_power * half_power;
    }

}

int powerModulo(int a,int b){

    if(b==0){
        return 1;
    }

    int half_power = powerModulo(a, b/2);    // This will return the MOD value

    if(b&1){
        return half_power * half_power % MOD * (a % MOD) % MOD ;   // a % MOD -> becz if a is greater than 10^9 i.e 10^12, ...
    }
    else {
        return half_power * half_power % MOD;
    }

}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    int a, b ;
    cin >> a >> b;

    cout << power(a,b) << endl;
    cout << powerModulo(a,b) << endl;
    
    return 0;
}