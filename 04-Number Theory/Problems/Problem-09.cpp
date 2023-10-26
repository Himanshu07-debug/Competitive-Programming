// Gvien an Psoitive integer n , it can consists of atmost 100 digits and no leading zeroes. 
// Determine is it possible to remove some of the digits(possibly not remove any digit at all) so that the result contains atleast one digit,
// no leading zeroes and is divisible by 8

// 3454  ---> Yes 344
// 10  ----> Yes 0
// 111111  ----->> No

// Constraint : 1 <= n <= 10^100


// LOGIC : 

// We know that ki a number is divisible by 8 if the last 3 digits are divisble by 8. 

// Yha pe humko remove krke number divisible by 8 bnana hai, NOTICE that khi pe bhi Apko min removal nhi bola hai. We can return any Possible 
// number with Divisble By 8 

// So hum dekhenge ki number me single digit no. which is divisible by 8, nhi to we will see all possible 2 digit number and Then 3 digit.. 
// Iske Upar nhi

// NOTE --> No need to make this Question TDS i.e removing from the last and making a Number divisble by 8 from the last

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 

int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here

    string s;  cin >> s;

    // Single digit
    for(int i=0;i<s.size();i++){
        if(s[i]=='8' || s[i]=='0'){
            cout << "YES" << endl;
            cout << s[i] << endl;
            return 0;
        }
    }

    // 2 digit
    if(s.size()>=2){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){

                int num = (s[i]-'0')*10 + (s[j]-'0');

                if(num%8 == 0){
                    cout << "YES" << endl;
                    cout << num << endl;
                    return 0;
                }

            }
        }
    }

    // 3 digits
    if(s.size()>=3){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                for(int k=j+1;k<s.size();k++){
                    int num = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');

                    if(num%8 == 0){
                        cout << "YES" << endl;
                        return 0;
                    }
                }

                int num = (s[i]-'0')*10 + (s[j]-'0');

                if(num%8 == 0){
                    cout << "YES" << endl;
                    cout << num << endl;
                    return 0;
                }

            }
        }
    }

    cout << "NO" << endl;
    
    
    return 0;
}