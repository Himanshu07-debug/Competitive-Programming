// Help Polycarp to find out whether the number n can be represented as the sum of a certain number of numbers 2020 and a certain number of 
// numbers 2021.

// Constraint ==>  1 <= n <= 10^6

// 4041  --> YES ( 2020 + 2021 )
// 4042  --> YES ( 2021 + 2021 )
// 8081  --> YES ( 2020 + 2020 + 2020 + 2021 )
// 8079  --> NO


// LOGIC ----------------------------------->>>

// OBSERVATION --> 
// No. 4 digit ke upar bhi ho sakta hai.. Also 2nd and 4th digit odd bhi ho sakte hai becz of carry ... 2020 /2021 ko 5 baar add kro and check


// So koi bhi digit pe koi bhi no. ho skta hai, Aap PATTERN nhi nikal sakte


// OBSERVE ---->  n = (2020 * x)  +  (2021 * y)
// If koi value of x ke liye, n - (2020 * x) is divisible by 2021 i.e y will be an integer ... 
// x >= 0  and  y >= 0



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



void solve(){

    // Your code here
    int n; cin >> n;

    // Max. value x ki ho sakti hai  ---> N/2020 > N/2021
    int x = n / 2020;

    for(int i=0;i<=x;i++){

        long long y = n - (2020*i*1ll);

        if(y < 0){
            cout << "NO" << endl;
            return;
        }

        if(y % 2021 == 0){
            cout << "YES" << endl;
            return;
        }

    }

    cout << "NO" << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}
