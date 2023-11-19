#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);


    // ************************ SET AND MAP **********************************************

    // SET , MAP needs the < function implemented
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



    // ********************** NOTE *******************************************

    set<int> st;

    st.insert(2);
    st.insert(3);

    // Erase can be by value ans Iterator
    // By iterator
    st.erase(st.begin());
    st.erase(st.end()--);

    // REMEMBER, Aap reverse iterator nhi use kar sakte erase, Erase function interprates them differently
    // NOT -->
    // st.erase(st.rbegin());  OR st.erase(st.rend()++);

    // REMEMBER, while comparing iterators, compare begin() with end()  AND rbegin() with rend()
    // While Comparing Values, You can use any combo begin() & rbegin()

    // while(st.begin() == st.rbegin())  ==> ERROR
    // while(st.begin() == st.end()--)   ==> No ERROR
    // while(*st.begin() == *st.rbegin())   ==> NO ERROR, by value any combo allowed
    

    return 0;
}