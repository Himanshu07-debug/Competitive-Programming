#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);


    // DEQUE are Similar To VECTOR, But it provides two more functions -> push_front(x) , pop_front();

    deque<int> d = {5, 3, 8, 4};
    d.push_back(1);
    d.push_back(2);

    sort(d.begin(),d.end());

    for(auto i : d){
        cout << i << " ";
    }

    cout << endl;

    cout << d[3];

    d.pop_back();
    d.pop_front();
    
    d.push_front(0);

    for(auto i : d){
        cout << i << " ";
    }

    cout << endl;




    return 0;
}