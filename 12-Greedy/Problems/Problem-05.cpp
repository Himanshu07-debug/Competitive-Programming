// Maximum Product Subarray sum ----------->>

// [2, 3, -2, 4]  ===> 6
// [-1, 0, -2]    ===> 0


// Constraint --> 1 <= n <= 10^5


// LOGIC -------------------------------------->>>

// OBSERVATION --> 
// Agar arr[i] < 0 i.e -ve aaya to ==>
// Maximum Product multiply hoke Minimum Possible product banayenga ( +ve * -ve => -ve )
// Minimum Product multiply hoke Maximum Possible product banayenga ( -ve * -ve => +ve )

// So hum KADANE lagayenge, for each index i, we will decide either to include the arr[i] into the Previous Subarray or Start a new subarray


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    int n; cin >> n;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    long long ans = arr[0];
    
    long long maxEnding = ans;
    long long minEnding = ans;

    for(int i=1;i<n;i++){

        if(arr[i] < 0){
            swap(maxEnding, minEnding);
        }

        maxEnding = max(arr[i] , maxEnding * arr[i]);
        minEnding = min(arr[i] , minEnding * arr[i]);

        ans = max(ans, maxEnding);

    }

    cout << ans << endl;

    // NOTE --> Observe at each index i, maxEnding stores the Maximum Product Subarray possible from indx 0 to i , Similarly minEnding for min


    // IN SIMPLE WAY --->>

    maxEnding = arr[0];
    minEnding = arr[0];

    long long res = maxEnding;

    for(int i=1;i<n;i++){

        long long temp = maxEnding * arr[i];

        maxEnding = max({arr[i] * maxEnding, arr[i] * minEnding, arr[i] });
        minEnding = min({temp, arr[i] * minEnding, arr[i] });

        res = max(res, maxEnding);

    }



    return 0;
}