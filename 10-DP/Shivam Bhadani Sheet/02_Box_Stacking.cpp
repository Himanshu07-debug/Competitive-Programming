#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// just worry about max score.. becz after sorting ---> the highest length will be at the end.. LIS
// among all lengths of equal length, we take the max one

int maxHeight(int height[], int width[], int length[], int n) {
    
    vector<vector<int>> cuboids;

    for (int i = 0; i < n; i++) {
        cuboids.push_back({length[i], width[i], height[i]});
        cuboids.push_back({length[i], height[i], width[i]});
        cuboids.push_back({width[i], length[i], height[i]});
        cuboids.push_back({width[i], height[i], length[i]});
        cuboids.push_back({height[i], length[i], width[i]});
        cuboids.push_back({height[i], width[i], length[i]});
    }

    n = cuboids.size();

    sort(cuboids.begin(), cuboids.end(), [&](vector<int> a, vector<int> b) {
        return (a[0] * a[1]) > (b[0] * b[1]);
    });

    vector<int> dp(n);
    
    int mx = 0;

    for(int i=0;i<n;i++){
        
        dp[i] = cuboids[i][2];

        for(int j=0;j<i;j++){
                
            if(cuboids[j][0] > cuboids[i][0] && cuboids[j][1] > cuboids[i][1]){
                
               dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                
            }
            
        }
        
        mx = max(mx, dp[i]);
    }


    return mx;

}