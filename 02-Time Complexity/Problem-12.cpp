// Once upon a time, bartender Decim found three threadlets and a pair of scissors.
// In one operation, Decim chooses any threadlet and cuts it into two threadlets, whose lengths are positive integers and their sum is equal to the length of the threadlet being cut.

// For example, he can cut a threadlet of length 5 -> 2 and 3, but he cannot cut it -> 2.5 and 2.5, or lengths 0 and 5

// Decim can perform at most three operations. He is allowed to cut the threadlets obtained from previous cuts. 
// Will he be able to make all the threadlets of equal length

// LOGIC : 

// If we apply operation in all of the 3 numbers i.e a -> a1,a2 , b -> b1,b2 , c -> c1,c2. Then a1=a2=b1=b2=c1=c2 should be equal as 
// we had used atmost 3 operations, no more operation we can do.. 
// a1=a2=b1=b2=c1=c2 implies that a1 + a2 == b1 + b2 == c1 + c2 which means a = b = c
// NOTE : We can only perform the operation on all 3 numbers iff the given 3 numbers are EQUAL, otherwise not


// If given 3 numbers are not equal, then hum teeno me operation nhi kar sakte, ek number unchanged rhnga, so You can think that hum unchanged
// minimum wale ko krnge, becz larger ko Minimum me divide krne ka try kar sakte hai, vice versa nhi
// So we will divide the larger number as : x and y - x  ,,, where x -> min element,  y -> max element


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here

    int a, b, c;
    cin >> a >> b >> c;

    multiset<int>s;
    s.insert(a);
    s.insert(b);
    s.insert(c);

    for(int i=0;i<3 && *s.rbegin()!=*s.begin();i++){
        
        int x = *s.rbegin();
        s.erase(--s.end());   // iterator pointing at last element

        s.insert(*s.begin());
        s.insert(x - *s.begin());

    }

    if(*s.rbegin() != *s.begin())  cout << "Yes" << endl;
    else cout << "NO" << endl;

}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}