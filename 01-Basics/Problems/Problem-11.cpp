// Given a year number, find the minimum year number which is strictly larger than the given one and has 
// only distinct digits.

// Input : 1987   Output : 2013
// Input : 2013   Output : 2014

// Constraint : 1000 <= y <= 9000

// Constraint are Loose, we can have a Brute Force Approach here upto O(N^2)

// We will check for upcoming years one by one that either they have distinct digits or not

#include<bits/stdc++.h>
using namespace std;

int main() {

    int y ;
    cin >> y;

    y++;

    while(1){

        set<char>s;

        string str = to_string(y);

        bool flag = true;

        for(int i=0;i<str.size();i++){

            if(s.count(str[i])){
                flag = false;
                break;
            }

            s.insert(str[i]);

        }

        if(flag){
            cout << y << endl;
            break;
        }

        y++;

    }

    return 0;

}
