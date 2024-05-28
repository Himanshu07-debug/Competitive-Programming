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



// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
// Determine the fewest cuts needed for palindrome partitioning of the given string.


// Input: str = "ababbbabbababa"
// Output: 3
// Explaination: After 3 partitioning substrings are "a", "babbbab", "b", "ababa".

// 1 ≤ length of str ≤ 500


// LOGIC ------------------------------------------>>>

// an easy question... Just an extension of Palindrome Partitioning...

// Recursive --> (n-1) choices + (n - 2) choices + (n - 3) choices + ..... + 1 ==> n! * n (palindrome check)


// Using DP --> 
// dp(i) --> min number of cuts from i to n-1
// With DP --> O(n * n * n)  --> not acceptable

// use Palindrome table also to nullify n --> O(n * n) --> acceptable


int dp[505];
int palindrome[502][502];

int rec(int i, int j, string &s){

    if(i > j) return 1;

    if(palindrome[i][j] != -1) return palindrome[i][j];

    return palindrome[i][j] = (s[i] == s[j]) && rec(i+1,j-1, s);

}

int help(int i, string &s){

    if(i == s.size()) return 0;
    
    if(dp[i] != -1) return dp[i];

    int ans = 1e9 + 2;

    for(int j=i;j<s.size();j++){

        if(palindrome[i][j] == 0) continue;

        int res = help(j+1, s) + 1;

        ans = min(ans, res);

    }

    return dp[i] = ans;

}

int palindromicPartition(string str)
{
    // code here
    memset(dp, -1, sizeof(dp));

    memset(palindrome, -1, sizeof(palindrome));

    int n = str.size();

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){

            int x = rec(i, j, str);

        }
    }

    return help(0, str) - 1;

    // -1 becz to nullfiy the cut of last one i.e if i am at n-1, no need of cut there... but our code is counting it...
    // nullify it

    // ex --> ababa --> whole string is palindrome .. 0 cuts.. but in our code.. when i = 0, j = n-1, res = 0 + 1 --> res = 1, nullfiying this

}

// tabulation 

class Solution {
public:
    bool isPalindrome(int i, int j, string &s){

        if(i >= j) return true;

        return (s[i] == s[j]) && isPalindrome(i+1, j-1, s); 

    }

    int minCut(string s) {
            
        int n = s.size();

        vector<int> dp(n + 1, 0);

        for(int i = n-1 ; i >= 0 ; i--){

            int mi = INT_MAX;

            for(int j = i; j < n; j++){

                if(isPalindrome(i, j, s)){

                    int cut = 1 + dp[j + 1];

                    mi = min(mi, cut);

                }

            }

            dp[i] = mi;

        }

        return dp[0] - 1;

    }

};


