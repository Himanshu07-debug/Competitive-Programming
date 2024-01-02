// Chef and Chefina are playing Tetris with the following rules:
// A player can clear 1, 2, 3, or 4 lines in a single move.
// If a player clears only one line, the turn shifts to the other player; otherwise, it remains with the current player.
// The game stops when the sum of lines cleared by both players is at least L.
// Chef aims to end the game by clearing 4 lines (getting a "Tetris") and wants to be the one to finish the game in this manner.

// We need to determine the number of sequences of moves that allow Chef to be the player to clear the final 4 lines, 
// considering the game stops when the total lines cleared is at least L.

// INPUT => L = 3  -------->> O/P => 3 ... Jump order -> (4) , (1,1,4) , (2,4) ..

// Constraint -> 1 <= L <= 1e5


// LOGIC -------------------->>>


// A Typical DP Question --> No. of ways and each step, 4 moves are Possible.. Only we have to consider the Control part between chef and Chefina

// We will make two array X and Y for Chef and Chefina and lets Define our STATE ------->>
// X[i] -> Every lines before i is removed and the Chef is having the control on the ith line currently
// Y[i] -> Every lines before i is removed and the Chefina is having the control on the ith line currently 

// If the no. of ways of reaching Lth line is N, so Yha se TETRIS karne ke no. of ways ==> N
// Similarly for X[L-1] , X[L-2] , X[L-3] --> becz yeah saare Line se Chef Tetris kar sakta hai in one-go and it will be ensured that L lines are 
// removed


// ANSWER ==> X[L] + X[L-1] + X[L-2] + X[L-3] 

// BASE CASE ==> X[1] = 1 and Y[1] = 0 ... becz first turn Chef ki hai.. Wo start krnga



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int n = 1e5;

vector<int> x(n+10, 0);    // W.C me L == N i.e 1e5 and wha se aage ke 4 remove kar sakta hu for Tetris
vector<int> y(n+10,0); 


void initialize(){

    x[1] = 1;  // In first turn, Chef has the control

    for(int i=1; i<=n ;i++){

        // Control will not change for 2, 3, 4
        x[i+2] = (x[i+2] + x[i]) % MOD;
        x[i+3] = (x[i+3] + x[i]) % MOD;
        x[i+4] = (x[i+4] + x[i]) % MOD;

        y[i+2] = (y[i+2] + y[i]) % MOD;
        y[i+3] = (y[i+3] + y[i]) % MOD;
        y[i+4] = (y[i+4] + y[i]) % MOD;

        // Control change when moving 1
        x[i+1] += y[i];
        y[i+1] += x[i];

    }

}


void solve(){

    // Your code here
    int l; cin >> l;

    if(l == 1 || l==2) cout << 1 << endl;
    else if(l == 3) cout << 3 << endl;
    else{

        cout << (x[l] + x[l-1] + x[l-2] + x[l-3])%MOD << endl;
    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    initialize();

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}