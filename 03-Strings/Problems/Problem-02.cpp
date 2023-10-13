// Zookeeper is playing a game. In this game, Zookeeper must use bombs to bomb a string that consists of letters 'A' 
// and 'B'. He can use bombs to bomb a substring which is either "AB" or "BB". When he bombs such a substring, 
// the substring gets deleted from the string and the remaining parts of the string get concatenated.

// For example, Zookeeper can use two such operations: AABABBA → AABBA → AAA.

// Zookeeper wonders what the shortest string he can make is. Can you help him find the length of the shortest string?



// Logic : We can remove AB/BB ===> Observe this carefully, whatever is before B, A/B, we dont care ( ?B )

// Means we have to find B and remove the previous indx character of it
// For this, We can use Stack , B aaya to if stack non-empty hai, remove, at last, stack size is our answer
// We can Optimize it By using a length variable instead of Stack



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    cin >> s;

    int stk = 0;

    for(int i=0;i<s.size();i++){
        if(stk!=0 && s[i]=='B') stk--;
        else stk++;
    }

    cout << stk << endl;
  
    return 0;
}

