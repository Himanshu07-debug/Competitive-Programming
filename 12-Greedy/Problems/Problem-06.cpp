// Yash and Jay - both are frnds. They buy cupcakes of the shop. In the shop, there are n types of cupcakes and each cupcake is infinitely available.
// arr[i] -> tastiness of each cupcake of type i. 
// Yash purchased exactly one cupcakes of each type. Jay will purchased a segment of cupcake. Jay will not purchase the whole cupcake..
// Whoever total tastiness is stictly greater than the other, he is Happy. Tell if whether Yash will be happy or not ???

// [7,4,−1]
// Yash => 7 + 4 -1 = 10
// Jay => segments [7],[4],[−1],[7,4] or [4,−1], their total tastinesses are 7,4,−1,11 and 3 respectively. 
// OUTPUT => NO ( Jay 11 > Yash 10) -> Yash will not Happy


// Constraint -> 2 <= n <= 10^5 ,,,  -10^9 <= arr[i] <= 10^9



// LOGIC ------------->>

// Jay ke liye max. Subarray sum nikal lete KADANE se .. 
// Also iss subarray ke size ka bhi track rakhte so that we can check j - i + 1 < N when max_sum == total_sum

// KADANE VARIATION with index of Subarray

// REMEMBER -> In KADANE, hamesha window ki size min. consider hoti hai i.e [0, 8] -> size = 1 ( 0  consider nhi hota bhale hi same sum hai)
//                                                                           [8, 0] -> size = 1 (last wla 0 not considered)


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



void solve(){

    // Your code here
    int n; cin >> n;

    vector<long long> arr(n);

    long long sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    long long res = arr[0];
    long long maxEnding = arr[0];

    int st = 0;
    int max_st = 0;
    int max_en = 0;

    for(int i=1;i<n;i++){

        maxEnding = max(arr[i], maxEnding + arr[i]);

        // new Subarray started
        if(maxEnding == arr[i]) st = i;

        if(res < maxEnding){
            res = max(res,maxEnding);
            max_st = st;
            max_en = i;
        }

    }

    if(res > sum){
        cout << "NO" << endl;
    }
    else if(res == sum){
        if((max_en - max_st + 1) < n) cout << "NO" << endl;
        else cout << "YES" << endl;  
    }
    else cout << "YES" << endl;

}

// Maximum Window consider hoye, iske liye update -->
// prevEnding == maxEnding --->  maxEnding = max(arr[i], maxEnding + arr[i]);   --> if(maxEnding == arr[i] && prevEnding != 0 ) st = i;
// if(res <= maxEnding )


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}
