// Polycarp is a music editor at the radio station. He received a playlist for tomorrow, that can be represented as a sequence a1, a2, ..., an,
//  where ai is a band, which performs the i-th song. Polycarp likes bands with the numbers from 1 to m, but he doesn't really like others.

// We define as bj the number of songs the group j is going to perform tomorrow. Polycarp wants to change the playlist in such a way that 
// the minimum among the numbers b1, b2, ..., bm will be as large as possible.

// Find this maximum possible value of the minimum among the bj (1 ≤ j ≤ m), and the minimum number of changes in the playlist Polycarp needs to 
// make to achieve it. One change in the playlist is a replacement of the performer of the i-th song with any other group.


// n = 7 , M = 3          ====>>       2 1             --> max. possible value and no. of changes
// 1 3 2 2 2 2 1                       1 3 3 2 2 2 1   --> updated array of bands


// M = 3 , Therefore 3 bands from 1 to 3 --> No. of songs they Played --> 2  4  1  ... 
// Currently min. is 1, now ek 2 ko 3 krdo --> 2  3  2  --> Min value ==> 2  ... Change ==> 1


// Constraint --> 1 <= m <= n <= 1e6   ,,,  1 <= arr[i] <= 10^9




// LOGIC ----------------------------------------------------->>>

// We define as bj the number of songs the group j is going to perform tomorrow 
// --> Yha grp j ke place pe "band" likhna tha => Confuse krne ke liye diya hai

// NOTE --> Jab bhi aaisa diya rhe --> Min. among the no.s as large as Possible OR max. possible value of Minimum -> Means Maximize the min. 
//                                                                                                                  value possible

// Polycarp likes bands with the numbers from 1 to m
// We have M buckets and N elements   ----> So Each Bucket me Max. min N/M elements to aayenge ...

// DRY RUN ------------>>
// If N % M == 0 ---> Then equally divide honga each bucket me i.e ->
// If N = 6 and M = 3 --> Distribution ====> 2 2 2 ... Kisi ko bhi increase/decrease kiye to Min. hamesha chotta aayenga 2 se .. Max -> N/M

// If N % M != 0 ---> Eg => N = 8 and M = 3 -->
//  Phle equally distribute krdo ==> 2 2 2 , now Remaining --> 2 
// OBSERVE -> Agar M bache rhte to sabko increment kar diye rhte, min. value increase ho jaata but Kyuki < M hbache ai i.e max. M - 1 rhnga.. 
//            , M - 1 increment krne pe bhi ek value unchanged hi rhngi i.e Maximum UNCHANGED


// THEREFORE , in both cases , Maximum min. value possible is N/M

// Now, for changes, Array me jo N/M se jyade rhnge unke position pe Other element ko rakhke cnt badhayenge


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;



int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    int n, m; cin >> n >> m;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> freq(m+1,n/m);

    vector<int> pos;

    for(int i=0;i<n;i++){

        if( arr[i] > m || freq[arr[i]] == 0){
            pos.push_back(i);
        }
        // here we ensured that value is <= M
        else{
            freq[arr[i]]--;
        }

    }

    int cnt = 0;

    for(int i=1;i<=m;i++){

        while(freq[i] != 0){
            int indx = pos.back();
            pos.pop_back();
            arr[indx] = i;
            cnt++;
            freq[i]--;
        }

    }

    cout << n/m << " " << cnt << endl;
    
    for(int x : arr) cout << x << " ";

    cout << endl;

    return 0;
}
