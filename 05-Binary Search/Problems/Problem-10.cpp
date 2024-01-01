// What's the minimum number of days needed for a ship, starting at (x1, y1), to reach coordinates (x2, y2) based on a 
// periodic wind forecast (U, D, L, R) of length n? The ship moves one unit up, down, left, or right according to the wind, and can stays 
// in its place only. The wind direction repeats every n days.
// The ship can also make its move alongwith wind moves when it aims to move i.e In order to move Diagonally, when Wind is blowing L, it goes
// U, the ship will move ( x-1, y+1 ) .. If ship move U and wind is also moving U at that time, then it doubles (x, y + 2)

// x1 = 0, y1 = 0
// x2 = 4, y2 = 6
// n = 3
// str = "UUU"
// OUTPUT -> 5 ( (0,0) → (1,1) → (2,2) → (3,3) → (4,4) → (4,6) )

// x1 = 0, y1 = 0
// x2 = 0, y2 = 1
// n = 1
// str = "L"
// OUTPUT -> -1

// 1 <= n <= 10^5  , 0 <= x,y <= 10^9


// LOGIC ---> 


// We have to minimize the number of Days...
// Search Space -> on the days
// If I can reach in x days, I can reach in x+1 days also
// F F F F F F T T T T T T T


// In Binary Search, the Question Always gets Clear, Its hard to write the Predicate Function --->

// PREDICATE FUNCTION LOGIC --->

// Our Ship can make its moves only with winds moves, not alone... 
// So, If m operations are done by wind to move the ship in x no. of days, then the no. of Operation done by ship should be <= m ...

// This will be Our Main Idea ...
// Checking ship can reach to the destination in x no. of days ????
// 1. Let our starting pt. is x1,y1...
// 2. Now, we reach to some pt. x', y' by the wind contribution in x no. of days....
// 3. Now, x', y' --> x2, y2  .. jaane me Ship ko kitna move krna pada i.e abs(x2 - x') + abs(y2 - y') .. Calculate..
// 4. Now, if Number of moves made by ship <= x ... Then VALID, otherwise x no. of days is not valid to reach destination


// Question me bola hai Wind and Ship sath me chal rhe hai... We are Calculating it one after the other, Does this affect ???
// NO ... 
// REMEMBER, in Grids, we only concerns about the number of upper, lower, left, right moves .. 
// Koi bhi 2 moves milake usko digonal move bna sakte hai ... But even after doing this, If You will calculate.. The number of U,L,D,R moves 
// remain same for src to Destination... No matter whatever Path you take

// --> Iss Question me agar ship ka move <= x hua to It can be considered that ship ka moves wind ke sath kisi dinn hue x days me
// No. of Ships move = M, so x me se koi bhi M dinn ship ne move kiya honga alongwith wind..

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

long long x , y, x2, y2, n;
string s;

long long cntU, cntD, cntR, cntL;

bool check(long long val){

    // weather moves peroidic, so we had concatenated many string s in one single String
    long long u = (val/n)*1ll*cntU;
    long long d = (val/n)*1ll*cntD;
    long long l = (val/n)*1ll*cntL;
    long long r = (val/n)*1ll*cntR;

    // In the last segment, remaining days , wind contri
    for(int i=0;i<val%n;i++){

        u += (s[i] == 'U');
        d += (s[i] == 'D');
        l += (s[i] == 'L');
        r += (s[i] == 'R');

    }

    // Wind Contri
    long long x_dash = x + (r - l);
    long long y_dash = y + (u - d);

    // Ship moves
    long long tmp = ((long long)(abs(x_dash - x2) + abs(y_dash - y2)));

    return (tmp <= val);

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    cin >> x >> y >> x2 >> y2;

    cin >> n;
    cin >> s;

    cntU = count(s.begin(),s.end(),'U');
    cntR = count(s.begin(),s.end(),'R');
    cntL = count(s.begin(),s.end(),'L');
    cntD = count(s.begin(),s.end(),'D');

    long long l = 0, r = 1e15;

    long long ans = -1;

    while(l <= r){

        long long m = (l + r)/2;

        if(check(m)){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;

    }
    
    cout << ans << endl;
    

    return 0;
}










