// Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with length between a and b.

// Constraint => 1 <= n <= 10^5  ,,  1 <= a <= b <= n  , -10^9 <= arr[i] <= 10^9

// n = 8 , a = 1, b = 2
// arr = [-1 3 -2 5 3 -5 2 2]
// Ans => 8  ( [5,3] )


// LOGIC ------------------->>

// Agar b length ka Subarray hai, The length of Subarray can be -> b - a, b - (a-1) , b - (a-2) , .... b - 0

// Simply, for a Subarray ending with indx j, the no. of starting pts. possible is j - (b-a) , j - (b-(a-1)) , j - 0
// We have to take the maximum out of this all Subarray for the Subarray ending with indx j .. (j >= b)
// This is same as Solving Queries for each indx j....


// Maximum sum ke liye j indx pe end hone wale possible Subarray me se Minimum sum wla wla discarded part subtract krna padega...
// Iske liye saare possible st. pts i ke prefix[i] minus krke dekna padega prefix[j] se.. This can give TLE becz 1 <= a <= b <= n
// Use Multiset.. This will give you the Minimum Sum Discarded prefix at just O(logn) 


// We are trying to maximize prefix[j] - prefix[i] . Since i is gauranted to be within the window [j-b, j - (b-a)] we can construct a 
// sliding window of size b, and compute max(prefix[j] - prefix[i])  where a <= i <= b



#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll INF = 1e18;

int N, A, B;

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> B;  

	vector<long long> pfx(N + 1);
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		pfx[i] = a + pfx[i - 1];
	}

	ll res = -INF;

	multiset<ll> ms;

	// we can keep a sliding window of size B, then find the lowest pfx[j] using multiset
	for (int i = A; i <= N; ++i) {

		if (i > B)
			ms.erase(ms.find(pfx[i - B - 1]));  // erase the element if size > B

		ms.insert(pfx[i - A]);
		res = max(res, pfx[i] - *ms.begin());  // we want to minimize ms.begin() aka pfx[j]

	}

	cout << res << "\n";

}
