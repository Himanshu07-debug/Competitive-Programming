// Monocarp's character currently has health equal to hC and attack equal to dC. He wants to slay a monster with 
// health equal to hM and attack equal to dM. Before the fight, Monocarp can spend up to k coins to upgrade his 
// character's weapon and/or armor; each upgrade costs exactly one coin, each weapon upgrade increases the character's 
// attack by w, and each armor upgrade increases the character's health by a.
// Can Monocarp's character slay the monster if Monocarp spends coins on upgrades optimally(Monocarp will start first)?

// The fight ends when someone's health becomes non-positive (i. e. 0 or less). If the monster's health becomes 
// non-positive, the character wins, otherwise the monster wins.

// Constraint : 1 <= hc,hm <= 10^15  , 1 <= dc,dm <= 10^9 , 0 ≤ k ≤ 2*10^5 , 0 ≤ w ≤ 10^4 ,  0 ≤ a ≤ 10^10

// INPUT : hc = 25, dc= 4, hm = 9, dm = 20, k = 1 , w = 1, a= 10
// Output : YES 
//  Monocarp can spend one coin to upgrade weapon (dc will be equal to 5), then health during battle will change 
// as follows: 
// (hC,hM) = (25,9) → (25,4) → (5,4) → (5,−1). The battle ended with Monocarp's victory. 


// LOGIC : Time to kill the monster = ceil(hm/dc) and Time to kill the Hero = ceil(hc/dm)

// Hero will win only if ceil(hm/dc) <= ceil(hc/dm)

// We will use all possibilities of K coins i.e 
// hc + 0 and dc + k
// hc + 1 and dc + (k-1)

// At any case, if we will satisfy the condition of ceil, we will return 


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    long long hc, hm, dc, dm;

    long long k , w , a;

    cin >> hc >> dc ;

    cin >> hm >> dm;

    cin >> k >> w >> a;

    long long c = (hc + dm -1)/dm;

    long long m = (hm + dc - 1)/dc;

    if(c >= m){
        cout << "YES"<<endl;
        return;
    }

    for(int i=0;i<=k;i++){

        long long h = hc + a * i;
        long long wp = dc + w * ( k-i );

        c = (h + dm -1)/dm;

        m = (hm + wp - 1)/wp;

        if(c >= m){
            cout << "YES"<<endl;
            return;
        }

    }

    cout << "NO" << endl;

    
    return 0;
}