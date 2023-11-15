// Given a string s and a parameter k, you need to check if there exist k+1 non-empty strings a1,a2...,ak+1 , such that -
// s = a1 + a2 + … + ak + ak+1 + R(ak) + R(ak−1) + … + R(a1)
// Here + represents concatenation. We define R(x) as a reversed string x

// Constraint : 1 <= n <= 100 , 1 <= k <= n/2 

// Input : n=5 , k=1 , s = qwqwq                      -> Yes
// Input : n=22 , k=0 , s = dokidokiliteratureclub    -> Yes
// Input : n=6 , k=3 , s = aaaaaa                     -> Yes


// Logic : Hum check krnge kya string ko k+1 strings ko divide kar sakte hai kya , If yes , then
//         hum k characters check krnge starting and ending ke .. same mile, then aage Yes , 
//         becz k strings 1-1 character ki ban jayegi and aage equality check krne ki need nhi


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here
    int n , k;
    string s;

    cin >> n >> k;
    cin >> s;

    // Checking for Valid String
    if( n <= 2*k )  cout << "NO" << endl;
    else{

        if(k==0){
            cout << "YES" << endl;
            return;
        } 

        string x = s.substr(n-k);
        reverse(x.begin(),x.end());

        if(s.substr(0,k)==x){
            cout << "YES" << endl;
            return;
        }

        // It is similar to checking palindrome of string of length k 

        for(int i=k-1;i<n/2;i++){

            string x = s.substr(n-1-i);
            reverse(x.begin(),x.end());

            if(s.substr(0,i+1)==x){
                cout << "YES" << endl;
                return;
            }

        }

        cout << "NO" << endl;
    }

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}

