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

    cout << d[3] << endl ; // 0-based indexing

    d.pop_back();
    d.pop_front();
    
    d.push_front(0);

    for(auto i : d){
        cout << i << " ";
    }

    cout << endl;

    // NOTE --> DEQUES vs VECTOR ?? Deques are slower than vectors in Terms of Performance


    // ****************************** Priority_queue *******************************

    // Priority queue are much faster than SET, but you only get LAST value

    priority_queue<int> pq;   // Max heap
    pq.push(5);
    pq.push(3);
    pq.push(1);

    // MIN Heap
    priority_queue<int,vector<int>,greater<int>> pq2;

    // 1st -> datatype, 2nd -> PQ are built on vectors or any other Contiguos loca. DS, 3rd --> Responsible for Sorting in ascending

    // At 2nd , you can take deque<int> , arr, but vector is Recommended


    // *************************** SORTING IN PRIORITY QUEUE *********************************

    // If the datatypes are numeric in pairs, then never use comparators... Wo Cmp ke bina bhi ho sakta hai

    // In numeric values, aap minus use kar sakte ho, Kyuki minus greatest value ko samllest kar denga..
    // EXAMPLE -> In max heap, 10 is in the top, if I will do -10, then it will at the bottom

    // SORT --> First element => ascending and Second element => descending

    priority_queue<pair<int,int>> p;   // MAX HEAP

    for(int i=0;i<5;i++){
        int a,b;
        cin >> a >> b;

        p.push({-a, b});  // Humne a ko -ve kar diye, so ab first element ascending order me sort honge
        
    }

    // DO NOT FORGOT WHILE PRINTING, REMOVE THE MINUS SIGN
    while(!p.empty()){
        cout << -p.top().first << " " << p.top().second << endl;
        p.pop();
    }


    // Similarly you can Sort as (desc, desc) , (desc, asc) , (asc, asc)

    return 0;
}