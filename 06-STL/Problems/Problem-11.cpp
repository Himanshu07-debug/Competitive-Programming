// Monocarp knows that, on the i-th day, exactly ai friends will join him for skiing activity, bi friends will join him for a movie and ci friends 
// will join him for board games.
// Monocarp also knows that he can't try more than one activity in a single day.
// Thus, he asks you to help him choose three distinct days x,y,z in such a way that the total number of friends to join him for the activities 
// (ax + by + cz) is maximized

// n = 3 days
// arr = 1 10 1
// brr = 10 1 1
// crr = 1 1 10
// ANS -> 30 (day 2 for skiing, day1 for movie, day3 for board games )


// CONSTRAINT --->
// 3 <= n <= 10^5 ... 1 <= arr[i] , brr[i] , crr[i] <= 1e8


// LOGIC -------------------------------------------------->>

// Humko 3 different indexes lene hai 3 array se let x, y, z so that hum maximize kar sake (a[x] + b[y] + c[z]) value...

// Agar hum all Possible subsets check kar paaye indexes ke teeno array, se we can find the answer .. Lekin nhi kar sakte becz n <= 10^5
// n^3 nhi chalega complexity...

// LEKIN KYA HUMKO SAHI ME EVERY INDEXES KA SUBSET BANANA HAI ????
// NO, Remember Hume har ek array se max. distinct value jo valid le sakte hai wo chahiye ... 
// So ULLU mat bno .. SORT kro and last ke 3 indexes of all arrays se subset banao ... To handle the Index part, we will map them with value


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

void solve() {

    int n; cin >> n;

    vector<pair<long long,int>> arr(n), brr(n), crr(n);

    for(int i=0;i<n;i++){
        
        int a; cin>> a;

        arr[i] = {a, i+1};
    }

    for(int i=0;i<n;i++){
        
        int a; cin>> a;

        brr[i] = {a, i+1};
    }

        for(int i=0;i<n;i++){
        
        int a; cin>> a;

        crr[i] = {a, i+1};
    }

    sort(arr.begin(),arr.end());
    sort(brr.begin(),brr.end());
    sort(crr.begin(),crr.end());

    long long ans = NINF;

    for(int i=n-3;i<n;i++){
        for(int j = n-3;j<n;j++){
            for(int k = n-3;k<n;k++){
                if(arr[i].second != brr[j].second && brr[j].second != crr[k].second && arr[i].second != crr[k].second){
                    long long sum = arr[i].first + brr[j].first + crr[k].first;

                    if(sum > ans) ans = sum;
                }
            }
        }
    }

    cout << ans << endl;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}