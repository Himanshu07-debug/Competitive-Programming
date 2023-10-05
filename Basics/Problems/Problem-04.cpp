
#include<bits/stdc++.h>
using namespace std;

int multiply(vector<long long> &arr, long long x , int n){

    int carry = 0;
    for(int i = 0; i< n;i++){
        unsigned long long s = arr[i] * x + carry;
        arr[i] = s % 10;
        carry = s/10;
    }

    while(carry > 0){
        arr[n] = carry % 10;
        carry /= 10;
        n++;
    }

    return n;

}


int main(){

    long long in[4];

    for(int i=0;i<4;i++){
        int a;
        cin>>a;
        in[i] = a;
    }

    vector<long long> arr(100);

    int n=1;
    arr[0] = 1;

    for(int i=0;i<4;i++){
        n = multiply(arr, in[i], n);
    }

    cout << arr[1]<<arr[0] <<endl;

    return 0;
}