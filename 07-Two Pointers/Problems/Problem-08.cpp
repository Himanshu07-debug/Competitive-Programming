// You are given a huge integer a consisting of n digits (n is between 1 and 3⋅105 , inclusive). It may contain leading zeros. You can swap 
// two digits on adjacent (neighboring) positions if the swapping digits are of different parity (that is, they have different remainders 
// when divided by 2 ).You can perform any number (possibly, zero) of such operations. 
// Find the minimum integer you can obtain. 
// Note that the resulting integer also may contain leading zeros.


// INPUT --> 0709 => 0079 , 1337 => 1337 , 246432 => 234642

// Constraint -> 1 <= n <= 3 * 10^5



// OBSERVATION ------------------------->>>

// Let e -> even, o -> odd

// If o o o o || e e e e -> Change nhi kar sakte order becz same parity ke hai

// If e e e e o  -> Hum odd ko swap krke aage yaa khi bhi beech me daal sakte hai
// If o o o o e  -> Same hum even ko bhi khi bhi jagah daal sakte hai

// if o e o e    -> Yha pe bhi khi pe bhi daal sakte hai element (Ex -> e o o e  => e e o o  OR  e o e o)


// FINAL OBSERVATION --> 
// 1. Even Numbers Apni ordering change nhi krnge , Same for Odd.. Kyuki Same parity wla swap nhi ho sakte..
//  -> e1 e2 o1 e3  -> o1 e1 e2 e3 , or ...

// 2. Subarray of any length with same parity ke andar diff parity wla koi bhi pe place kar sakte hai ....

// Based on 1st observation =>
// Apne ko min. answer chahiye , Therefore -> We will make Two arrays of even and odd .. 

// Based on 2nd Observation =>
// So agar Considering Even as Same parity, usme current pointed odd agar min. hai current pointed even element se, Place there Odd



// Each time jo min. honga even and odd me usko final String me daal denge ...

// Example -> 2 1 4  ==> e = {2, 4}  , o = {1}
// Agar 2 min. hai diff parity wale next number se to order change nhi krnge , otherwise diff parity wla daal denge


// Merge Sort wla 2 pointer's logic jaise dono array ko handle krnge




#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    string s; cin >> s;

    vector<int> o,e;

    for(int i=0;i<s.size();i++){

        int x = s[i] - '0';

        if(x & 1) o.push_back(s[i]);
        else e.push_back(s[i]);

    }

    int i=0, j = 0;

    string res;

    while(i < e.size() && j < o.size()){

        if(e[i] <= o[j]){
            res.push_back((char)e[i]);
            i++;
        }
        else{
            res.push_back((char)o[j]);
            j++;
        }

    }

    while(i < e.size()){
        res.push_back((char)e[i]);
        i++;
    }

    while(j < o.size()){
        res.push_back((char)o[j]);
        j++;
    }

    cout << res << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}