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

// this are the Recurrence problems... No forms

// Here you have to see the patterns ... 
// here tested for n = 1, 2, 3

// and then check from IDE for n = 4

// simple Fibonacci was it

long long countStrings(int n) {
	    
    long long a = 1, b = 2;

    for(int i=2;i<=n;i++){
        int sum = (a + b)%MOD;
        a = b;
        b = sum;
    }

    return b;

}


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    

    return 0;
}

