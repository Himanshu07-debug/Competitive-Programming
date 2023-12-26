// In a cityscape, there are several cities positioned along a straight line, and cellular towers are scattered across the same line. 
// Each tower covers cities within a certain radius, ensuring they have network coverage.
// The task is to determine the minimum radius 'r' needed for each city to be within the range of at least one tower. 
// If 'r' equals zero, a tower only covers its exact location. Towers can serve multiple cities, but all covered cities must be within 
// the specified radius 'r'. (radius means har ek tower "x - r To x + r" tk cover krnga)


// Constraint -> 1 <= n, m <= 10^5   , -10^9 <= arr[i], brr[i] <= 10^9


//  n = 3 , m = 2
// arr = [-2, 2, 4] , brr = [-3, 0]
// Ans => 4


// LOGIC ---> 

// Har ek city ke liye atleast ek to hona chahiye left or right me .. So har ek city ka right wla nikal lenge upperbound lagagke brr() me and 
// left wla indx - 1 honga, usase bhi nikal lenge... Jisase Min. distance honga, city uss side ke Tower ko choose karengi


// Final answer will be the maximum of all this possible answer for each city becz humko sabko jalana hai....

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, m; cin >> n >> m;

    vector<long long> arr(n),brr(m);

    for(int i=0;i<n;i++) cin>> arr[i];

    for(int i=0;i<m;i++) cin>> brr[i];

    long long ans = 0;

    for(int i=0;i<n;i++){

        int j = upper_bound(brr.begin(),brr.end(),arr[i]) - brr.begin();

        // no tower at greater than arr[i] position
        if(j == m){
            ans = max(ans, arr[i] - brr[j-1]);
        }
        else if(j == 0){
            ans = max(ans, brr[j] - arr[i]);
        }
        else{
            ans = max(ans, min(brr[j] - arr[i],arr[i] - brr[j-1]));
        }

    }

    cout << ans << endl;


    // TIP --->>

    // Aaise Question me ,You have to handle the arrays extreme points.. Agar isase bachna chahte ho.. brr[i] ke begin me -1e17 and right me 1e17
    // Kyuki 10^9 hai value, maximum diff hua bhi to 2 * 10^9 se bda to honga nhi, 1e17 se diff bhut jyada aayenga and we are taking min. isliye
    // consider nhi honga

    // TIP 2 --> You can use SET for towers. Apko current iterator ke sirf it-- se hi check krna hai


    // NOTE ---> This is Binary Search approach -> O(nlogn)




    // ****************************** TWO POINTER ***************************************************


    // For a Valid City i, dist(i,j) < dist(i,j+1) ==> becz towers are in sorted order...
    // So agar jth tower pe ho and upar wla condition satisfy nhi hua, this means city i ke liye yeah valid Towers nhi hai i.e nearest nhi hai,
    //  so Check with further towers i.e j++

    // Kisi bhi city i ke liye uske j and j + 1 tower ke location ki only 3 possible cases hai (imagine in an Number line ) ==>

    // 1. Dono tower city i ke left me ho .. here dist(i, j) > dist(i, j+1)
    // ==> jth tower nearest nhi hai city i ke, check for j+1 and j+2 --> j++

    // 2. Dono tower city i ke right me ho .. here dist(i,j) < dist(i,j+1)
    // ==> Valid nearest jth tower 

    // 3. Ek tower left me ho and right me j+1 wla
    // ==> If dist(i,j) < dist(i,j+1) --> Valid jth tower , OTHERWISE dist(i, j) > dist(i, j+1) --> j+1 is the Valid Tower


    // NOTE --> For any City i, j will be a valid tower if dist(i,j) < dist(i, j+1) , Otherwise Invalid Tower hai, aage ke tower check kro


    // Also City i ke liye jo jth tower aayenga, city i + 1 ka tower j se hi aage aayenga, no need to check [1,..., j-1]


    int j = 0;

    long long res = NINF;

    for(int i=0;i<n;i++){

        while(j+1 < m){

            long long d1 = abs(arr[i] - brr[j]);
            long long d2 = abs(arr[i] - brr[j+1]);

            if(d1 >= d2) j++;   // j+1 is more nearer than j
            else break;         // Valid jth tower

        }

        res = max(res, abs(arr[i] - brr[j]));

    }


    cout << "Two Pointer Approach ==> " << res << endl;


    return 0;
}

