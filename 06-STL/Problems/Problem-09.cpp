//A card pyramid of height 1 is constructed by resting two cards against each other. 
// For h > 1, 2 pyramid niche me, and One at the top ke liye card lagenge, one more card for as a base for the top one pyramid..

// See Diagram here --> https://codeforces.com/problemset/problem/1345/B

// TASK -> You start with n cards and build the tallest pyramid that you can. If there are some cards remaining, you build the tallest 
//          pyramid possible with the remaining cards. You repeat this process until it is impossible to build another pyramid. In the end, 
//          how many pyramids will you have constructed?


// In SIMPLE WORDS ---> 
// Apko N cards diye hai, Maximum No. of Pyramids aap kitna bana sakte ho assuming that each Pyramid is as tall as Possible

// Input : 3 ==> 1 (you construct a pyramid of height 1 with 2 cards. There is 1 card remaining, which is not enough to build a pyramid. )
// Input : 15 ==> 1 (Complete 3 height ka ban sakta ek pyramid exactly 15 cards se)
// 24 ==> 3 ( 15 cards se 3 height ka banaye, remaining 9 me se ek 2 height ka banaye and then ek 1 height ka banaye )

// Constraint --> 1 <= N <= 10^9 ...( O(N) nhi kar sakte , O(Logn) jaana padega )


// LOGIC ---> 

// Humne starting 4 height ke liye no. of cards required nikale -> 2 , 7, 15 , 26, ... 
// By OEIS, we get the General Term --> n * (3*n + 1)/2;

// Now simple, becz Apna series montonous and sorted hai, we will use lower_bound to get answer for each Input no. of cards

// Agar GLOBAL not allowed, each test case ke liye arr banao.. Same code 1e9 wla, TLE will be will not there as arr.length much less than 10^5
// You can verify by our General Term formula for the series

// *************** ANOTHER WAY TO GET THE SERIES ----------------->>

// 2, 7, 15, 26 ===> see the increment in each indx -> 2 + 5 => 7 + 8 => 15 + 11 => 26 ....

// At each indx i , arr.back() + (i * 2) + (i - 1)


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

vector<long long> arr;

long long cal(int n){
    return (n * 1ll * (3*n + 1))/2;
}

void initialize(){

    long long ans = cal(1);

    arr.push_back(ans);

    int l = 2;

    while(ans <= 1e9){
        ans = cal(l);
        arr.push_back(ans);
        l += 1;
    }

}

void solve(){

    // Your code here
    int x; cin >> x;

    int indx = lower_bound(arr.begin(),arr.end(),x) - arr.begin();

    if(arr[indx] == x) cout << 1 << endl;
    else{
        if(indx - 1 < 0) cout << 0 << endl;
        else{
            indx -= 1;
            long long a = 0;
            while(indx >=0){
                long long y = x/arr[indx];
                a+=y;
                x -= (arr[indx]*y);
                if(x==0) break;
                indx--;
            }

            cout << a << endl;
        }
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




