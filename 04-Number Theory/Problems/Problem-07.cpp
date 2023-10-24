// Count the number of pairs of integers (x, y) such that 1 ≤ x  ≤  n, 1 ≤ y  ≤  m and (x + y) % 5 equals 0.

// Constraint : 1 <= M, N <= 10^6


// LOGIC --> 

// You can consider it as  n * m grid and As it is Modulo, You have to just analzye the starting values, further the events will be repeating

// Make the grid for n = 6 , m = 11 and then fill the valid cells, you will get the below approach

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    int n,m;
    cin >> n >> m;

    int mi = min(m,n);
    int mx = max(m,n);

    long long ans = 0 ;

    for(int i=1;i<=mi;i++){

        if(i%5){
            // Range remaining after the first valid point
            int r = mx - (5 - (i%5));
            ans = ans + r/5;
            // mx was smaller than the valid starting cell i.e r < 0 , and we will not include the starting pt in our ans
            if(r >= 0) ans++;
        }
        else{
            // In case of 5, there is no starting pt, therefore range = mx
            ans += mx/5;
        }

    }

    cout << ans << endl;


    return 0;
}


// Another Approach ===> Decoding the modulo more deeply to optimize the Above one

int main(){

    long long n, m;

    cin >> n >> m;

    vector<long long> arr(5,0) , brr(5,0);

    for(int i=1;i<=n;i++){
        arr[i%5]++;
    }

    for(int i=1;i<=m;i++){
        brr[i%5]++;
    }

    long long ans = 0;

    // All possible pairs with modulo 5 as 0
    ans+=(arr[0]*brr[0]);
    ans+=(arr[1]*brr[4]);
    ans+=(arr[2]*brr[3]);
    ans+=(arr[3]*brr[2]);
    ans+=(arr[4]*brr[1]);


    // Example -> n = 6 , m =  12 , then arr[0] = 1 and brr[0] = 2, then consider 5 in n and 5,10 in m, this are 
    //                              only the valid pairs (5 + 5) , (5 + 10)

    // We are just deciding the how many rows are possible and then in each how much col is valid, In 5th row, 5 and 10
    // col are valid

    // Similarly -> 1%5 + 4%5 = 5%5 = 0 ....

    cout << ans << endl;


    return 0;
}



