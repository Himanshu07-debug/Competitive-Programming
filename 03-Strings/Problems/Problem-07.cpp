// A border of a string is a prefix that is also a suffix of the string but not the whole string. 
// For example, the borders of abcababcab are ab and abcab.
// Your task is to find all border lengths of a given string.

// Constraints -> 1 <= n <= 10^6

// LOGIC -------------------->>

// prefix of length i = suffix of length i

// Approach ===========================>
// We know that ki border n/2 se jyada nhi honga becz same substring muje right me bhi chahiye .. n/2 se big kiya to right wali less that n/2 hongi
// To hum first n/2 characters ke hash aaise nikalenge --> hash[i] = hash[i-1] + (s[i] * p )  ,, p = p * 31
// Last ke n/2 hum reverse traverse krnge and unka hash --> hash[i] = hash[i+1]*p + s[i]  ,, p = p * 31

// Dry run krke dekho hash same aa rhe hai checking ke liye


// APPROACH 2 ===========================>>>

// (0, i) ka corresponding (n-1-i , n-1) range ke hash value se check krnge...

// OBSERVE -> Rabin karp jaisa ek common Power se multiply nhi kar sakte subtraction of l-1 part ka becz yha fixed window size nhi hai ..
//            Apko Yaa to prefix[l-1] me 31^(j-i) multiply krna padega yaa prefix[r] se 31^(j-i) divide krdo




#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 53;
const ll p2 = 127;
const int maxN = 1e6+5;

long long pow1[maxN], pow2[maxN], ph1, ph2, sh1, sh2;


int main(){

    string s; cin >> s;

    int n = s.size();

    pow1[0] = pow2[0] = 1;
    
    for(int i = 1; i < n; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
    }

    for(int i = 0; i < n-1; i++){
        int l = (s[i] - 'a' + 1);
        int r = (s[n-i-1] - 'a' + 1);

        ph1 = (ph1 + l * pow1[i]) % MOD;
        ph2 = (ph2 + l * pow2[i]) % MOD;
        sh1 = (sh1 * p1 + r) % MOD;
        sh2 = (sh2 * p2 + r) % MOD;

        if(ph1 == sh1 && ph2 == sh2)
            printf("%d ", i+1);
    }
}

// #include <bits/stdc++.h>
// using namespace std;
 
// using ll = long long;
// using vi = vector<int>;
// #define f first
// #define s second
// #define pb push_back
// #define all(x) begin(x), end(x)
 
// #define F0R(i,a) for(int i=0; i<(a); i++)
// #define FOR(i,a,b) for(int i=(a); i<=(b); i++)
// #define R0F(i,a) for(int i=(a)-1; i>=0; i--)
// #define ROF(i,a,b) for(int i=(b); i>=a; i--)
// #define trav(a,x) for (auto& a: x)
 
// /* source: ekzlib */
// typedef pair<ll, ll> pll;
 
// const int MOD = 1e9 + 7;
// const pll BASE = {9973, 7817};
 
// pll operator+(const pll& a, const pll& b) {
// 	return { (a.first + b.first) % MOD, (a.second + b.second) % MOD };
// }
// pll operator+(const pll& a, const ll& b) {
// 	return { (a.first + b) % MOD, (a.second + b) % MOD };
// }
// pll operator-(const pll& a, const pll& b) {
// 	return { (MOD + a.first - b.first) % MOD, (MOD + a.second - b.second) % MOD };
// }
// pll operator*(const pll& a, const pll& b) {
// 	return { (a.first * b.first) % MOD, (a.second * b.second) % MOD };
// }
// pll operator*(const pll& a, const ll& b) {
// 	return { (a.first * b) % MOD, (a.second * b) % MOD };
// }
 
// pll get_hash(string s) {
// 	pll h = {0, 0};
// 	for (int i = 0; i < s.size(); i++) {
// 		h = BASE * h + s[i];
// 	}
// 	return h;
// }
 
// struct hsh {
// 	int N;
// 	string S;
// 	vector<pll> pre, pp;
 
// 	void init(string S_) {
// 		S = S_;
// 		N = S.size();
// 		pp.resize(N);
// 		pre.resize(N + 1);
// 		pp[0] = {1, 1};
// 		for (int i = 0; i < N; i++) {
// 			pre[i + 1] = pre[i] * BASE + S[i];
// 			if (i) { pp[i] = pp[i - 1] * BASE; }
// 		}
// 	}
 
// 	pll get(int s, int e) {
// 		return pre[e] - pre[s] * pp[e - s];
// 	}
// };
 
// int main() {
 
//     string s; cin >> s;
//     hsh n; n.init(s);
//     FOR(i,1,n.N-1) {
//         if(n.get(0,i) == n.get(n.N-i, n.N)) cout << i <<" ";
//     }
// }