#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    int n, k; cin >> n >> k; 

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    long long cnt = 0;

    int sum = 0;

    int i=0, j=0;

    while(j < n){

        sum += arr[j];

        while( i <= j && sum >= k){

            cnt += (n - j);
            
            sum -= arr[i];
            i++;
        }

        j++;

    }  

    cout << cnt << endl;

    return 0;
}

