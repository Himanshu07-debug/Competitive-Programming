// You are given an array of n elements and q queries, each defined by a pair of integers li and ri (1 ≤ li ≤ ri ≤ n). 
// Rearrange the array elements to maximize the sum of elements within the specified query ranges.

// n = 3 , q = 3
// arr = [5 3 2]
// Queries -->
// 1 2
// 2 3
// 1 3
// OUTPUT ---> 25  .. Array is rearranged as [3, 5, 2]  before Answering the Query

// CONSTRAINT --->
// 1 <= n,q <= 2 * 10^5     ,,   1 <= arr[i] <= 2 * 10^5


// LOGIC ----->>

// Hume Saare queries ka total sum Maximize krna hai....
// Agar Array ka maximum elements most occurence indexes of Queries pe rhe to ho jaega MAXIMUM ...

#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    long long n,q;
    cin >> n  >> q;
    
    vector<long long> arr(n+1,0);

    for(int i=1;i<=n;i++) cin >> arr[i];

    vector<long long> diff(n+2,0);

    while(q--){
        long long l,r;
        cin >> l >> r;

        diff[l]++;
        diff[r+1]--;
    }

    sort(arr.begin() + 1,arr.end(),greater<long long>());

    vector<pair<int,int>> v(n+1);

    for(int i=1;i<=n;i++){
        diff[i] += diff[i-1];

        // For follow-up -->
        v[i] = {diff[i],i};
    }

    sort(diff.begin()+1,diff.end()-1,greater<long long>());

    long long sum = 0;

    for(int i=1;i<=n;i++){
        sum += (arr[i]*diff[i]*1ll);
    }

    // FOLLOW UP Q.s ===> Print the Rearranged Array

    sort(v.begin()+1, v.end(), greater<pair<int,int>> ());

    vector<long long> ans(n+1,0);

    for(int i=1;i<=n;i++){

        long long indx = v[i].second;
        ans[indx] = arr[i];                // My arr is sorted in DESC. order

        // Aap sum wla part yha se bhi kar sakte the 
        // sum += (arr[i] * v[i].first);

    }

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << sum << endl;
    
    return 0;
}









