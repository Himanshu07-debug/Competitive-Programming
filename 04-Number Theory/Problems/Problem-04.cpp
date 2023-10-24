// Given a positive integer n, find k integers (not necessary distinct) such that all these integers are strictly greater than 1, 
// and their product is equal to n.

// 10000 2 --> 2 5000  ,,  100000 20  --->  -1  ,,,, 1024 5 --> 2 64 2 2 2 

// Constraint : 2 ≤ n ≤ 10^5   ,, 1 <= k <= 20

// LOGIC ==> Will create K factors if possible , otherwise factors cnt < k , will return -1



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

    long long cnt = 0;

    long long org = n;

    vector<int>arr;

    for(int i=2;i*i<=org && n!=1;i++){

        bool flag = false;

        if(n % i == 0){

            while(n%i == 0){
                // Checking here avoid the need of checking above the for loop and we are ensuring that When it breaks the loop, n ke pass aur
                // factors remaining hai
                if(cnt == k - 1){
                    flag = true;
                    break;
                }

                n /= i;
                cnt++;
                arr.push_back(i);
            }

        }

        if(flag){
            break;
        }

    }

    
    if(cnt == k-1 && n > 1){
        for(auto x:arr) cout << x << " ";
        cout << n << endl;
    }
    else{
        cout << -1 << endl;
    }


    return 0;
}



