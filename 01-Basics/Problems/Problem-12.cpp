// There are N frnds. You are given an Array where a[i] = no. of candies ith frnd have. Your Task is to check that is it possible to have all 
// frnds to have equal number of Candies . You can take 2^k no. of candies from one frnd and can give it to other. ( 2 <= 2^k <= 2^x )
// You can perform this Operation any Number of times. If it is Possible, print YES otherwise NO

// N = 2, [4,4] --> YES,  [ 2, 4, 12 ]  ---> YES  , [4, 6] --> NO

// 1 <= N <= 10^5


// LOGIC ---> 

// If the sum of the Integers is divisible By n, this means we can distribute the total sum in n equal parts of value sum/n
// For each element, we will check usko kitne aur element chahiye sum/n hone ke liye, if differnce 2 ka multiple hai, we can give, Agar ODD aaya,
// We cant share 


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

void solve(){

    // Your code here

    int n;
    cin >> n;

    vector<int> arr(n,0);

    long long sum = 0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    if(sum % n){
        cout << "NO"<< endl;
        return ;
    }

    int diff = sum / n;

    bool flag = false;

    for(auto x:arr){
        if(abs(x-diff)&1){
            flag = true;
            break;
        }
    }

    if(flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    
}


int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--){

        solve();
    
    }

    return 0;

}
