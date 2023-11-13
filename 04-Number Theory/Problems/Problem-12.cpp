// You own a small bus service business and you have just received an order to replace n tires. You know that the bus fleet owns two types 
// of buses: with two axles (these buses have 4 wheels) and with three axles (these buses have 6 wheels).

// You don't know how many buses of which type the AvtoBus bus fleet owns, so you wonder how many buses the fleet might have. You have to
// determine the minimum and the maximum number of buses that can be in the fleet if you know that the total number of wheels for all buses 
// is n .

// INPUT -> n = 24              OUTPUT -> 4 6 
// Four buses with 6 wheels  OR  Three buses with 4 wheels and two buses with 6 wheels  OR   Six buses with 4 wheels ...

// CONSTRAINT ->  1 <= n <= 10^18


// LOGIC ------------------------>>>

// OBSERVATION 1 --> Here we have to solve a equation ===> (4 * x) + (6 * y) = N

// Minimum No. of Bus --> Hum 6 wheels ke jyade banayenge so -> y ko maximize krna hai
// Similarly for Maximum no. of Bus  --> 4 wheels ke jyade

// OBSERVATION 2 --> 4 & 6 are even , so x aur y even ho yaa odd, Multiply hoke even hi honge and even + even ==> even i.e N should be even


// Now for Minimum, Y ko maximize krne ke liye hum 6 * y == N - 4*i  equation ko i=0 se verify krna shuru kar sakte hai.. Lekin this will be TLE

// So, We will go with Modular as Divisors are Fixed -> 4 and 6

// For 6 -> Even remainder possible are ==> 0, 2, 4  
// => For 0, ans = N/6
// => For 4, N = N - 4 , now N will be divide by 6 ...
// => For 2, N = N - 4*2 , now N will be divide by 6 ...

// For 4 -> Even remainder possible are => 0, 2
// => For 0, ans = N/6
// => For 2, N = N - 6 , now N will be divide by 4


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


void solve(){

    // Your code here
    long long n;  cin >> n;

    if(n&1){
        cout << -1 << endl;
        return;
    }

    int x = n%6;

    long long mx = -1;
    long long mi = -1;

    if(x == 0){
        mi = n/6;
    }
    else if(x == 2){
        long long y = (n - 4*2);
        if(y >= 0){
            mi = (2 + y/6);
        }
    }
    else if(x == 4){
        long long y = n - 4;
        if(y >= 0){
            mi = (1 + y/6);
        }
    }

    if(mi == -1){
        cout << -1 << endl;
        return;
    }

    int z = n%4;
    if(z == 0){
        mx = n/4;
    }
    else if(z == 2){
        long long y = n - 6;
        if(y >= 0){
            mx = (1 + y/4);
        }
    }

    if(mx == -1){
        cout << -1 << endl;
        return;
    }

    cout << mi << " " << mx << endl;

}

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
        
    }
    
    return 0;

}