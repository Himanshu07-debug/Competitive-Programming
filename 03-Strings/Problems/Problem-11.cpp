// You've got string s with good and bad letters. 
// The substring s[l...r] is good, if among the letters  sl, sl + 1, ..., sr there are at most k bad ones. 

// INPUT --->
// s = ababab
// 01000000000000000000000000 [ 26 alaphabets ke liye hai , 0 -> bad , 1 -> good]
// k = 1

// OUTPUT ==> 5  ( "a", "ab", "b", "ba", "bab" ) [ only the distinct ones ]

// Constraint ==> s can be max of 1500 characters ==> 1 <= n <= 1.5 * 10^3   , 0 <= k <= n



// LOGIC ------------------>>>

// The HACK is Constraint, Generate All possible substring and for distinct hum MAP/ SET me store kar lenge

// Here is a CATCH -> Set / Map me insertion O(n * logn) me honga becz Inserted element is string and It can be atmost of n length .. 
//                    Comparison O(n)

// To avoid this overhead, we will store the hash value in Set .. Now insertion in O(log N)

// Always while using HASHING, collision ko avoid krne ke liye ONLINE JUDGES me, use DOUBLE HASHING
// NOTE -> There might come a case when Single Hashing causes an ERROR


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

    string isBad; cin >> isBad;

    int k; cin >> k;

    int base[2] = {53, 127};
    int mod[2] = { 1000000007, 1000000009 };

    int n = s.size();

    set< pair<int, int>> st;

    for(int i=0; i<n ; i++){

        int hash[2] = {0, 0};
        int pw[2] = {1, 1};

        int cnt = 0;

        for(int j = i ; j<n ; j++){
            
            if(isBad[s[j] - 'a'] == '0') cnt++;

            if(cnt > k) break;

            for(int l = 0 ; l < 2 ; l++){

                hash[l] = (hash[l] * pw[l] + s[j]) % mod[l];
                pw[l] = (pw[l] * base[l]) % mod[l];

            }

            st.insert( { hash[0], hash[1]});

        }

    }

    cout << st.size() << endl;
    
    
    return 0;
}


