// You are given an unsorted permutation p1,p2,…,pn . To sort the permutation, you choose a constant k (k≥1 ) and do some operations on the 
// permutation. In one operation, you can choose two integers i , j (1 ≤ j < i ≤ n ) such that i−j = k , then swap pi and pj . 
// What is the maximum value of k that you can choose to sort the given permutation?

// 3 1 2 ==> K = 1
// 4 2 6 7 5 3 1  ==> K = 3

// Constraint -> 2 <= n <= 10^5


// LOGIC --> 

// Suppose first Index pe 4 hai, lekin 4 hume 4th position pe chahiye, what will be the difference ? Indx : 4 - 1 => 3
// Similarly difference all element ka bhi nikal lo array ka unke required position se ...

// Agar Yeah all difference divisble by any value of k ho jaaye, This means all elements can be moved to their correct position using 
// operations where i - j == k

// No matter operation kitna bhi krna pade, but kyuki all array element ka common divisor nikale hai, divisor se move krke sabko unke correct
// position me set kar sakte hai .. 

// We want the greatest divisor --> GCD 

// Here we had used GCD for Sorting elements

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    int t;
    cin >> t;
    while (t--) {
    	int n, res = 0;  // gcd(x,0) => x
    	cin >> n;
    	for (int i = 1; i <= n; i++) {
    		int x; cin >> x;
    		res = __gcd(res, abs(x - i));
    	}
    	cout << res << "\n";
    }

    return 0;
    
}

