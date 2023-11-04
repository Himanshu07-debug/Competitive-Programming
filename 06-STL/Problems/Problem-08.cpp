// You have N frnds .. Each of them you know his name and the grades Arabic, Math, science and English

// Sort the string according to Following Conditions --> 
// If the absolute diff between the total grades is greater than 10, then put the person with higher grade in the first
// Otherwise, compare their names and sort them lexicographically

// Constraint -> 1 <= N <= 10^5 , 1 <= |name| <= 10

// Input -> 
// 7
// Hussien 95 75 65 85
// Hafez 98 57 75 68
// Omar 77 68 75 64
// Atef 56 97 75 64
// Karemo 60 91 98 70
// Ezzat 72 83 69 95
// Muhammad 98 97 57 95

// Output -> 
// Muhammad 347 98 97 57 95
// Atef 322 56 97 75 64
// Ezzat 319 72 83 69 95
// Hussien 320 95 75 65 85
// Karemo 319 60 91 98 70
// Hafez 298 98 57 75 68
// Omar 77 68 75 64


// LOGIC -> 

// In such type of Questions, Always use your own defined Datatype such as STRUCT

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

struct Friend{
    string name;
    int arabic;
    int maths;
    int science;
    int english;
};

bool cmp(const Friend &a, const Friend &b){

    int total1 = a.arabic + a.maths + a.science + a.english;
    int total2 = b.arabic + b.maths + b.science + b.english;

    if(abs(total1 - total2) > 10){
        return total1 > total2;
    }
    else{
        return a.name < b.name;
    }


}

int main(){

    int n; cin >> n;

    Friend arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i].name >> arr[i].arabic >> arr[i].maths >> arr[i].science >> arr[i].english;
    }

    sort(arr,arr + n,cmp);

    for(auto f : arr){
        // print it
    }



}