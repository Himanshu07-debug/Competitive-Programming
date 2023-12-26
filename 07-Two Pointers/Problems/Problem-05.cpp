#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    long long n, k; cin >> n >> k;

    vector<long long> arr(n);

    long long sum = 0;
    long long mx = NINF;

    int indx = -1;

    for(int i=0;i<n;i++){
        cin>> arr[i];
        sum += arr[i];
        if(arr[i] > mx){
            mx = arr[i];
            indx = i;
        }
    }

    if( k > sum){
        cout << indx << " " << k/mx << endl;
        return;
    }


    vector<long long> brr(2*n);

    for(int i=0;i<2*n;i++){
        brr[i] = arr[i%n];
    }

    mx = INF;

    for(int x = 0; x < n;x++){

        int j = x;
        int i = x;

        long long s = 0;

        while( j < (n + j)){

            s += brr[j];

            while( i <= j && s >= k){

                if((j - i + 1) < mx){
                    mx = (j - i + 1);
                    indx = i;
                }

                s -= brr[i];
                i++;

            }
            j++;
        }
    }

    cout << indx << " " << mx << endl;


        

    return 0;
}

