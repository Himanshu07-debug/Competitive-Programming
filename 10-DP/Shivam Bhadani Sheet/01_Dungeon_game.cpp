#include<bits/stdc++.h>

using namespace std;

// FORM 2 
// a sequence / a path to find

// State -->
// dp[i][j] --> min health required at (i, j) so that the knight reach to the princess (n-1, m-1)

// Transition ---------->>
// 2 movements are possible same as min Sum path in Grid


// 1   3
// 30 -5

// when at bottom right cell, -5 ---> minHealth required if we start from this cell is 1 - (-5) = 6

// When we are at cell 30 ---> transition ans ==> 6 as min... min - 30 = -24 < 0
// our health becomes negative, this means we have reward here, so if we start with this cell, 
// we will required minHealth of 1 i.e 1(st) + 30 = 31 --> BR cell

// but if the cell value was -ve or +ve with value < 6 --> we continue with those starting health values...




int dp[201][201];
int n, m;

int help(int i, int j, vector<vector<int>> &arr){

    if(i == n || j == m) return 1e9;

    if(i == n-1 && j == m-1){

        if(arr[i][j] <= 0) return 1-arr[i][j];
        else return 1;       // 

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

