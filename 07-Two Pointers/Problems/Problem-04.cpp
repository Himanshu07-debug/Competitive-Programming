#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, k; cin >> n >> k;

    vector<long long > arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int i=0 , j = 0;

    long long sum = 0;

    long long res = 0;

    while(j < n){

        sum += arr[j];

        while( i<=j && sum > k){
            
            sum -= arr[i];

            i++;
        }

        long long x = (j - i + 1);

        res += (x * (x + 1))/2;

        j++;

    }

    cout << res << endl;


    return 0;
}

