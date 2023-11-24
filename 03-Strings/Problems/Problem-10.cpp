// The bear has a string s = s1 s2 ... s|s| (record |s| is the string's length), consisting of lowercase English letters. 
// The bear wants to count the number of such pairs of indices i, j (1 ≤ i ≤ j ≤ |s|), that string x(i, j) = s[i] s[i + 1]... s[j] contains at 
// least one string "bear" as a substring.

// String x(i, j) contains string "bear", if there is such index k (i  ≤  k  ≤  j - 3), that s[k] = b, s[k + 1] = e, s[k + 2] = a, s[k+ 3] = r.


// Input --> bearbtear
// O/P -> 6 [ (1, 4), (1, 5), (1, 6), (1, 7), (1, 8), (1, 9) ]

// Input --> bearaabearc
// O/P -> 20
// (1,  4), (1,  5), (1,  6), (1,  7), (1,  8), (1,  9), (1,  10), (1,  11), (2,  10), (2,  11), (3,  10), (3,  11), (4,  10), (4,  11), (5,  10), (5,  11), (6,  10), (6,  11),
//  (7,  10), (7,  11)

// Constraint --> 1 <= |s| <= 5000 


// LOGIC --------------->>>

// The Hack is the Constraint .. I can generate all possible substrings and check bear substring in them ..

// If koi bhi Beech substring me "bear" aaya to saare aage indexes bhi required substring banayenge..

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s; cin >> s;

    int n = s.size();

    long long cnt = 0;

    for(int i=0; i <= (n - 4) ; i++){

        bool isBear = false;

        for(int j = i + 3; j < n; j++){

            if(isBear || s.substr(j-3, 4) == "bear"){ 
                isBear = true;
                cnt++;
            }

            // substr() ek baar true de diya uske baad isBear cnt++ karayenga

        }

    }

    cout << cnt << endl;
    
    return 0;
}

// ******************************* OPTIMIZATION ************************************************

// Agar humne Rabin - karp use kiye to wo hume starting ke indexes de denga jha pe bhi "bear" honga

// 0 ........... i "bear" j .............. n - 1

// How to get the Total no. of Substrings where this "bear" will come ??
// Number of Starting Points possible -> 0 to i + 1  ===> cnt1
// Number of ending points possible -> j - 1 to n - 1  ==> cnt2

// Total Possible number -> cnt1 * cnt2


// If there are Multiple "bear" in s , then ??
// 0 ... i1 "bear" j1 ..... i2 "bear" j2 ..... i3 "bear" j3 ..... n - 1
// For first bear --> Starting pts possible ==> 0 -> i1 + 1 (b)  , ending pts ==> j1 - 1 (r) -> n-1
// For second bear --> Starting pts possible ==> i1 + 2 (e) -> i2 + 1  , ending pts ==> j2 - 1 to n-1
// ... so on



