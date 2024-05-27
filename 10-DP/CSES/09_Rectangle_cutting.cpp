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

// Given an a * b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into 
// two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves?

// Constraints - 1 <= a, b <= 500


// LOGIC ------------------------------------------------------->>>

// explore all possible choices of cuts....

// no need of any form, just be NAIVE and common sense in your logic

// dp(x, y) --> min no. of cuts to convert to square parts.....

// Transition --> 

// at a moment, 2 choice --> either to make a cut parallel to x-axis or to the y-axis

// making an x cut --> dp[x][y] = dp[a][y] + dp[x-a][y] + 1 ...... 1 <= a <= x-1
// making an y cut --> dp[x][y] = dp[x][b] + dp[x][y-b] + 1 ....... 1 <= b <= y-1


// if x == y --> no need of cut --> already a square



int dp[1001][1001];
int n, m;


void solve(){

    for(int x=1;x<=500;x++){
        for(int y=1;y<=500;y++){

            if(x == y){
                dp[x][y] = 0;
            }
            else{
                dp[x][y] = 1e9;   // as we have to minimized

                for(int a=1;a<=x-1;a++){

                    dp[x][y] = min(dp[x][y], dp[a][y] + dp[x-a][y] + 1);

                }

                for(int b=1;b<=y-1;b++){

                    dp[x][y] = min(dp[x][y], dp[x][b] + dp[x][y-b] + 1);

                }

            }

        }
    }
    
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    solve();

    cin >> n >> m;

    cout << dp[n][m] << endl;
    

    return 0;
}

