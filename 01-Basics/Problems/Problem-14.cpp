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

long long sumDigitDifferences(vector<int>& arr) {

    int n = arr.size();

    int x = arr[0];

    int y = 0;
    while(x > 0){
        y++;
        x /= 10;
    }

    vector<vector<int>> table(y+1, vector<int>(10, 0));

    for(int i=0;i<n;i++){

        int z = arr[i];

        for(int k=1;k<=y;k++){

            table[k][z%10]++;

            z /= 10;

        }

    }

    long long ans = 0;

    for(int i=1;i<=y;i++){

        for(int j=0;j<10;j++){

            ans += table[i][j]*(n - table[i][j]);

        }

    }

    return ans/2;
        
}


void solve(){


    
}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    solve();
    

    return 0;
}

