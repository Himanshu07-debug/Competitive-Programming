// Petya recieved a gift of a string s with length up to 105 characters for his birthday. He took two more empty strings t and u and 
// decided to play a game. This game has two possible moves --> 
//      Extract the first character of s and append t with this character.
//      Extract the last character of t and append u with this character.
// Petya wants to get strings s and t empty and string u lexicographically minimal

// Constraint -> 1 <= n <= 1e5

// cab ==> abc
// acdb => abdc


// LOGIC -------------------------------->>

// Agar lexicographically minimal string bnana hai to always try to put the minimal character at the starting.. bhale hi uske baad ordering 
// Characters ki inefficient hi kyu na ho jaaye... Yeah minimal hi rhnga becz all characters ka minimal front i.e index = 0 pe hai...
// Agar kisi bhi ek character > minimal ko aage rakh diye, it will be greater 

// In this Question -->
// abfgdeab  ---> aabedgfb  (koi bhi efficient combination isase minimal nhi honga)

// Here t string can be consider as Stack becz uske functions stack wale hai...


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    string s, t, u;

    cin >> s;

    vector<int> arr(26, -1);

    for(int i=0;i<s.size();i++){

        arr[s[i] - 'a'] = i;    // storing the last occured indx of each character

    }

    int i = 0;
    int curr = 0;

    while(i < s.size()){

        if(i <= arr[curr]){

            t += s[i];

            // If last index pe jaate-jaate beech me bhi current character mile to le lena and t se pop kar dena
            while(t.size() && t.back() - 'a' == curr){
                u += t.back();
                t.pop_back();
            }

            i++;

        }

        curr++;

        while(t.size() && t.back() - 'a' <= curr){
            u += t.back();
            t.pop_back();
        }

    }

    reverse(t.begin(),t.end());

    u += t;

    cout << u << endl;

    return 0;

}