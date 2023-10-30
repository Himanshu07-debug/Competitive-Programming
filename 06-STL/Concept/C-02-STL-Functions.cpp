#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// COMPARATORS

bool cmp(int a, int b){
    return a < b;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    vector<int> arr{1,2,3,5,4,7,6};

    // ****************************** COMPARATOR ****************************************************

    sort(arr.begin(),arr.end(), cmp);   // --> Time Complexity --> O(N*logN) * Time Complexity of Comparator

    // decltype() is syntax to use Comparators in STL datatypes other than array like datatypes

    priority_queue<int,vector<int>, decltype(&cmp) > pq(cmp);   

    set<int, decltype(&cmp) > s(cmp);

    // s.lower_bound() nhi use kar sakte agar set me user-defined Comparator daale

    map<int,int, decltype(&cmp) > m(cmp);





    // ************************************** Max And Min  ******************************

    int x = *min_element(arr.begin(),arr.end());

    // If you have an Iterator, how to get Index --->

    cout << min_element(arr.begin(),arr.end()) - arr.begin() << endl;

    // NOTE : As array, vector has Contigous memory loc, There index can be found, We cant found in Set, Map, etc

    cout << count(arr.begin(),arr.end(),5) << endl;


    // FOR STL CONTAINERS --> https://devdocs.io/cpp/container
    // FOR STL ALGORITHMS --> https://devdocs.io/cpp/algorithm 




    return 0;
}