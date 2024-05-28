#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


// the OPTIMAL SOLUTION FOR IT IS ONLY AND ONLY --> Bitmasking .. learn and then do

// this is backtracking solution

bool rec(int i, int sum, vector<int> &vis, int bucketRemaining, vector<int>& arr, int n, int requiredSum){

    if(bucketRemaining == 1) return true;

    if(sum == requiredSum){
        return rec(0, 0, vis, bucketRemaining - 1, arr, n, requiredSum);
    }

    // use for loop and reducing the no. of calls of pick and skip
    for(int j=i; j<n; j++){

        if(vis[j]) continue;

        if(sum + arr[j] <= requiredSum){

            sum += arr[j];
            vis[j] = 1;

            bool sol = rec(j+1, sum, vis, bucketRemaining, arr, n, requiredSum);

            if(sol == true) return true;

            sum -= arr[j];
            vis[j] = 0;

        }

    }

    return false;

}


bool canPartitionKSubsets(vector<int>& arr, int k) {

    int n = arr.size();
    int sum  = 0;

    for(int x : arr){
        sum += x;
    }

    if(sum % k != 0) return false;

    int requiredSum = sum/k;

    int bucketRemaining = k;

    vector<int> vis(n, 0);

    return rec(0, 0, vis, bucketRemaining, arr, n, requiredSum);

}



