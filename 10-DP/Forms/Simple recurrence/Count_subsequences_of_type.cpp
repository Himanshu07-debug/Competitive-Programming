// Given a string S, the task is to count number of subsequences of the form aibjck, where i >= 1, j >=1 and k >= 1.
// Note: 
// 1. Two subsequences are considered different if the set of array indexes picked for the 2 subsequences are different.
// 2.  For large test cases, the output value will be too large, return the answer MODULO 10^9+7

// S = "abbc"
// Output: 3
// Explanation: Subsequences are abc, abc and abbc.

// S = "abcabc"
// Output: 7
// Explanation: Subsequences are abc, abc,
// abbc, aabc abcc, abc and abc.

// constraint --> 1 <= n <= 1e5

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


// its just like building the regular expression..

// traverse the string..

// if a is encountered --> we have 2 choices .. either to include this a in previous cnted subsets of a or start a new a

// if b is encountered --> we have 2 choices .. either to include in prev counted ab subsets or not.. also we have the choice of including this
//                         current b to all prev subsets of a 

// if c is encountered --> we have 2 choices .. either to include in prev counted abc subsets or not.. also we have the choice of including this
//                         current c to all prev subsets of ab


// see the photo for clarity...
// formula came -->
// a --> 2*a + 1 .. (2 * a --> include not include in prev AND +1 for new a)
// b --> 2*ab + a
// c --> 2*abc + ab


int fun(string &s) {
    
    int a = 0, ab = 0, abc = 0;

    for(auto x : s){

        if(x == 'a') a = ((2*a)%MOD + 1)%MOD;

        else if(x == 'b') ab = ((2*ab)%MOD + a)%MOD;
        
        else if(x == 'c') abc = ((2*abc)%MOD + ab)%MOD;
        // checking c becz in string other than a,b,c characters are also allowed
    }

    return abc;
        
}