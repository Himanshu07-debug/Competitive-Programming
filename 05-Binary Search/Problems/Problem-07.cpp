// Ivan represent his array with increasing sequences one by one unitl the array becomes empty...

// [1, 3, 2, 5, 4]  ---> 1st => [1,3,5] sequence  , Remaining -> [2,4]  , 2nd => Take [2,4] sequence

// [4,3,2,1] -> [4] , [3] , [2] , [1]

// Constraint -> 1 <= n <= 1e5


// LOGIC ------------------------------------>>>


// How to find that ki current arr[i] ko konse set me daale ??
// We decide on the basis of the last element of each set for each arr[i]. 
// So we can apply Binary Search on the last elements of each set.



#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;


int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n; cin >> n;

    vector<long long> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<vector<long long>> ans;

    for(int i=0;i<n;i++){

        int l=0 , r = ans.size() - 1;
        int indx = ans.size();

        while(l <= r){

            int m = (l + r)/2;

            if(ans[m].back() < arr[i]){
                // Potential answer
                indx = m;
                r = m - 1;            
            }
            else{
                l = m + 1;
            }

        }

        // Here we are Doing r = m - 1 in the Potential answer, not l = m + 1 like we do in Typical BS...
        // This is becz we want the first indx that is Potential to store the New element

        if(indx != ans.size()){
            ans[indx].push_back(arr[i]);
        }
        else{
            // new set
            ans.push_back({arr[i]});
        }

    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}

