// She knows n coffee recipes. The i-th recipe suggests that coffee should be brewed between li & ri degrees, inclusive,to achieve the optimal taste.
// Karen thinks that a temperature is admissible if at least k recipes recommend it.
// Karen has a rather fickle mind, and so she asks q questions. In each question, given that she only wants to prepare coffee with a 
// temperature between a and b, inclusive, can you tell her how many admissible integer temperatures fall within the range?

// Input -> 
// n = 3, k = 2, Q = 4
// Recipies -->
// 91 94
// 92 97
// 97 99
// Queries --> 
// 92 94              ===> 3 [ 92, 93 and 94 degrees are all admissible. ]
// 93 97              ===> 3 [93, 94 and 97 degrees are all admissible.]
// 95 96              ===> 0 [ None ]
// 90 100             ===> 4 [ 92, 93, 94 and 97 degrees are all admissible.]


// Constraint --> 1 <= k <= n <= 2 * 10^5   ,, 1  ≤  q  ≤  2 * 10^5   ,, 1  ≤  li  ≤  ri  ≤   2 * 10^5 ,, 1  ≤  a  ≤  b  ≤   2 * 10^5 


// LOGIC ---> 

// Understanding Questions is V.V IMP.. 
// In this, N recipies given hai and unke valid Temp. ka range diya hai jha tak wo ban sakti hai..
// Apne ko query me btana hai ki a aur b range me kitne Admissible temp hai.. Admissible temp ki condition hai ki uss temp pe >= k recipies banani
// chahiye


// Difference Array to get the No. of occurence of recepies at a particular temp.
// Kyuki Humko Cnt chahiye, Difference Array me jiss temp. pe occurence >= k honga usko 1 denge otherwise 0
// Now Prefix sum this Binary Array and then answer the Query

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    long long n, q, k; cin >> n >> k >> q;

    vector<long long> diff(200005,0);

    for(int i=0;i<n;i++){

        long long x, y;
        cin >> x >> y;
        diff[x]++;
        diff[y+1]--;

    }

    vector<long long> bin(200005,0);   // BINARY ARRAY

    long long sum = 0;

    for(int i=0;i<200005;i++){
        sum += diff[i];
        if(sum >= k){
            bin[i] = 1;
        } 
        else{
            bin[i] = 0;
        }
    }

    for(int i=1;i<200005;i++){
        bin[i] += bin[i-1];
    }

    while(q--){
        long long a,b;
        cin >> a >> b;

        cout << bin[b] - bin[a-1] << endl;    // a ki value min. 1 hai
    }


    
    return 0;

}



