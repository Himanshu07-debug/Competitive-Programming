#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Binary Search ---> Returns True and false

    // lowerBound ------> Returns iterator to the first occ. of a value >= target
    // upperBound ------> Returns iterator to the first occ. of a value > target

    // If You have to find ( value < target )  ===>

    vector<int> arr = {1,2,3,3,3,5,6,6,7,8,9};

    auto it = lower_bound(arr.begin(),arr.end(),3);

    if(it != arr.begin()){
        it--;
        cout << *it << endl;
    }
    else{
        cout << "Can't find prev values" << endl;
    }

    // lowerbound >= T  , Therefore --> lowerbound - 1 < T

    // Upperbound > T   , Therefore -->  upperbound -1 <= T


    // ********************************* BINARY SEARCH ON SORTED DATATYPES **********************************

    // Agar datatype sorted hai (Set, Map, etc) , Binary Search functions are in-Built into the datatype
    // auto it = sorted_datatype.lower_bound(target);

    set<int> s = {1, 2, 3 ,5 ,6};

    // auto it = lower_bound(s.begin(),s.end());   // NEVER DO THIS
    
    // lower_bound function set ke structure ko Samjh nhi paata, to BS nhi kr paata, so wo linear search krta hai x find krne ke liye

    cout << *s.lower_bound(5) << endl;

    auto itr = s.upper_bound(0);

    if(itr != s.begin()){
        itr--;
        cout << *it << endl;
    }
    else{
        cout << "No Prev value" << endl;
    }

    // Set do not Support Indexing, so aap nhi nikal sakte Index
    // Agar Indexing se kaam hai, Use Policy Based Data Structute (slower than set)

    
    return 0;
}