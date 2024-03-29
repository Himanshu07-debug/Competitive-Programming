// Count all arr[i] > arr[j] where i < j  in the given array

// This is same as INVERSION COUNT

// [2,3,1,6,5] -> (1 < 2 & 3 ==> 2) + (5 < 6 ==> 1)  ===> ANS -> 3

// Constraint -> 1 <= n <= 10^5


// LOGIC -> 

// Hum loop me traverse krte krte Set ko rakh sakte hai, wo left elements ka track rkhnga and Current me Jo element insert krnge, wo jha 
// pe insert honga(indx) , Apna ans indx ke saare right wale honge.. We can do it by find() OR upper_bound()

// BUT ....... While using SET, we cant find indx in O(1), hume set me traverse krna honga it return by s.find() se s.end() - 1 tak
// In Worst Case, set me traverse krne wala loop bhi n baar chalega and Time complexity will be O(n^2)


// TO AVOID THIS, Here we have to find out the Indx of the element and SET can be used to solve this Problem
// So the best alternative for SET in such cases of Finding indx, POLICY BASED DATA STRUCTURE

// SET + (indx like stuff OR cnt like case) ==> PBDS

// In PBDS, we have ->
// find_by_order(indx) => Returns iterator to the element at given indx
// order_of_key(value) => Returns indx of the element ( PBDS have 0-based indexing )

// order_of_key() is same as lowerbound in SET...

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

// ERASE FUNCTION
void myerase(PBDS &t, int v){
    int rank = t.order_of_key(v);
    auto it = t.find_by_order(rank);
    t.erase(it);
}

// myerase(st,arr[i]);  --> TO DELETE


int main(){

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    PBDS st;

    long long cnt = 0;

    for(int i=0;i<n;i++){

        cnt += ( st.size() - st.order_of_key(arr[i] + 1) );     // arr[i] + 1 ==> Handles DUPLICATES


        // You can use only arr[i] in order_of_key() if it is ensured that duplicates are not there...
        
        // But in case of Duplicates, we have to ensure that ki indx arr[i] ke equal value ka na mile, next greater element ka mile
        // [4, 5, 2, 2] ->
        // At first 2, (2 - 0) will be done
        // At second 2, (3 - 1) is done, agar (arr[i] + 1) nhi use krte to (3 - 0) hota i.e wrong

        st.insert(arr[i]);

    }

    cout << cnt << endl;

}

// NOTE -> For Inversion count, Best one is using MERGE SORT ....



// *****************************************************  NOTE  ***************************************************

// See while defining PBDS in typedef, "less_equal" is written which is for making it multiset which can store duplicates
// By DEFAULT, it is less only with datatype for normal set

// ALSO, you cant use the erase function directly in this case, you need to write erase seperately and you have to Pass the iterator same as
// Multiset for deleting. Iterator nhi diye to saare duplicates will delete at once


// ---------------->> For Map/Multimap --> use Datatype pair<int,int>





