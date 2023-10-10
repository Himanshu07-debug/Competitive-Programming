// A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers 
// any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.

// Constraint : 1  ≤  n  ≤  10^9


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


// NOTE : When you are given a Number, time complexity will be mostly the count of digits in the number


// LOGIC : In a given number, only three possibilities are possible  and therefore we will check each time either one 
//          of them exists

// TIME : O( N^2 ) where N = count of digits of the given number.. n can be max upto 9 (LOOSE CONSTRAINT)


int main() {

    string s; cin>>s;

    bool ok = true;
    int i=0;

    while(i < s.size() ){

        if ( i+2 < s.size() && s.substr(i,3) == "144") i+=3;
        else if( i+1 < s.size() && s.substr(i,2) == "14") i+=2;
        else if(s[i]=='1') i++;
        else{
            ok = 0;
            break;
        }

    }

    if(ok) cout << "Yes" << endl;
    else cout << "NO" << endl;

    return 0;

}


// O( N ) where N = count of digits of the given number

int main() {

    long long n ;

    cin >> n;

    long long prev=-1;
    int cnt = 0;
    bool flag = true;

    while(n > 0){

        int rem = n%10;

        if(rem>=0 && rem<=9) {
            if(rem!=4 && rem!=1){
                flag = false;
                break;
            } 
        }

        if(prev == -1){
            prev = rem;
        }
        else if(prev == 4){
            if(rem == 4 && cnt == 2) {
                flag = false;
                break;
            }
        }

        if(rem == 4) cnt++;
        else cnt = 0;

        prev = rem;
        n = n/10;

    }

    if(prev == 4) flag = false;

    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;

}