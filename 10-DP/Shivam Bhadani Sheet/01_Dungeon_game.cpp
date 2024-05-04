#include<bits/stdc++.h>

using namespace std;


int dp[201][201];
int n, m;

int help(int i, int j, vector<vector<int>> &arr){

    if(i == n || j == m) return 1e9;

    if(i == n-1 && j == m-1){

        if(arr[i][j] <= 0) return 1-arr[i][j];
        else return 1;

    }

    if(dp[i][j] != -1) return dp[i][j];

    int mi = min(help(i+1,j, arr), help(i, j+1, arr));

    int x = mi - arr[i][j];

    return dp[i][j] = (x <= 0) ? 1 : x;
}

int calculateMinimumHP(vector<vector<int>>& arr) {

    memset(dp, -1, sizeof(dp));
    n = arr.size() , m = arr[0].size();

    return help(0, 0, arr);

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    

    return 0;
}

