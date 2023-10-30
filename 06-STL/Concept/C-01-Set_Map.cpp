#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);


    // ************************ SET AND MAP **********************************************

    // Set , map needs the < function implemented
    // Unordered_set, Unordered_map need the hash function implemented

    // In Undordered Set, Vectors, pair are not allowed as they are not hashable [Search what are Hashable -> All primitive dataypes & string]
    // In Unordered Map, Value can be of any type(vectors, pair), but Key should be Hashahble

    unordered_map<int, vector<int>> um;

    // Generally Always used set, map becz HashMap, Hashset has worst case of O(n) , but SET has O(logn) for all case
    // NOTE --> If using SET give you TLE, then go for HashMap, Hashset

    

    // TRAVERSAL --> 

    map<int,int>m;

    for(int i=0;i<3;i++) m[i] = i;

    for(auto [a,b] : m)         // Structured Binding
        cout << a << " " << b << endl;

    // NOTE -> Vector of pairs and HashMap Also can be traverse as Same



    // https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/B
    //  https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/C
    // https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/D



    return 0;
}