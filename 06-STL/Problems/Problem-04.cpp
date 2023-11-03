// N * M Grid ( N rows & M col )

// Every Grid Cell has two possible states -> 
// Cell can have a plant -> x     OR    cell can have a weed -> .

// K is the number of Cells having Plant

// Goal is to Build the fences such that -> 
// There should always be fence between a plant and a weed
// There should always be fence between a plant and the outside of the GRID

// INPUT --> 
// N = 4, M = 4 , K = 9
// K plant cells as follows -> 
// 1 4
// 2 1 
// 2 2
// 2 3
// 3 1
// 3 3
// 4 1
// 4 2
// 4 3
// 4 4 1
// 1 1

// OUTPUT ---> 20 
// Consider x as plant and . as weed
// ...x
// xxx.
// x.x.
// xxx.

// An optimal solution is to build fences around the topmost plant (with length 4), around the remaining eight plants (with length 12) 
// and around the hole between them (with length 4). The total length is 4 + 12 + 4 = 20

// Constaint -> 1 <= N, M <= 1e9


// LOGIC --> N, M - 10^9  ==> Iterating over teh grid isnt possible

// For every K cells, we will check its adjacent neighbour. For this, we will initally store the K cells in a set



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here

    int n,m,k;
    cin >> n >> m >> k;

    vector<int> arr(n);

    set<pair<int,int>>s;

    for(int i=0;i<n;i++){
        int x , y;
        cin >> x >> y;
        s.insert({x,y});
    }

    long long cnt = 0;

    for(auto it=s.begin();it!=s.end();it++){
        int x = it->first;
        int y = it->second;

        if(s.find({x+1,y}) == s.end()) cnt++;
        if(s.find({x,y+1}) == s.end()) cnt++;
        if(s.find({x,y-1}) == s.end()) cnt++;
        if(s.find({x-1,y}) == s.end()) cnt++;

    }

    cout << cnt << endl;
    
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}