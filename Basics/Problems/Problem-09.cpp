// You are given an array a of n integers. You have two kinds of operations
// increment any element in a (increase it by one).
// decrement any element in a (decrease it by one).
// What is the minimum number of operations to make the number of even elements equal to the number of odd elements, 
// or detect that this is impossible?

//  1 ≤ n, a[i] ≤ 10^5
// Input : 1 2 3 4 => 0   , 1 1 1 1 => 2 ,    1 2 3 => -1


// LOGIC : Take out the difference and then half-half dono me distribute krdo to make them equal


// Other Approach -> Count odd elements , if cnt < n/2 , (n/2 - cnt) changes to make EVEN -> ODD
//                                           cnt > n/2 , then abs(n/2 - cnt) changes to make ODD -> EVEN
// Therefore we will return abs( n/2 - cnt) for both cases once only .. SHORTER CODE


#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;   cin>>t;

    while(t--){

        int n; cin >> n;

        int arr[n];

        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        if(n&1){
            cout << -1 << endl;
        }
        else{
            int e = 0 ;
            for(int i=0;i<n;i++){
                if(arr[i]&1) e--;
                else e++;
            }

            if(abs(e)&1) cout << -1 <<endl;
            else cout << abs(e)/2 << endl;

        }

    }

    return 0;
}
