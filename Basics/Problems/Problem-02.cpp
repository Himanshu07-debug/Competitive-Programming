// You are given a range represented by two integers L and R and you should find the sum of the numbers in the range 
// between L and R inclusive.

// Input :                                     Output: 
// 2
// 3 6                                          18
// 2 11                                         65


// 1 ≤ L,R ≤ 10^9

// NOTE : This Problem is Simple, but here learn how to avoid OVERFLOW


#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    while(t--){

        // In case of long long questions, take Input also in Long long
        long long n, x;
        cin >> n >> x;
        
        // Edge Case
        if(x > n){
            swap(n,x);
        }
    
        // Inorder to avoid Overflow, use 1ll always in case of long long
        long long ans1 = n * 1ll * (n+1)/2;
        long long ans2 = x * 1ll * (x-1)/2;
        
        // Never do the operation in the cout statement, store it in a variable and then output it
        long long res = ans1 - ans2;
        
        cout<< res<<"\n";

    }

    // ******************************************** CONCEPT ***************************************

    // In Finding Prime Questions, we do not use sqrt(), WHY ???

    // sqrt() returns float values and also there may be error in Precision, therefore multiplication of int, int 
    // i.e i*i is Preffered 


    
    return 0;
}