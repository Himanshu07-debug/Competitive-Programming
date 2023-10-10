// Theatre Square in the capital city of Berland has a rectangular shape with the size n × m meters. 
// On the occasion of the city's anniversary, a decision was taken to pave the Square with square granite flagstones.
// Each flagstone is of the size a × a.

// What is the least number of flagstones needed to pave the Square? It's allowed to cover the surface larger than 
// the Theatre Square, but the Square has to be covered. It's not allowed to break the flagstones. 

// Constraints : 1 ≤   n, m, a  ≤  10^9

// n = 6, m = 6 , a = 4                       OUTPUT -> 4

#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
 
    int n , m, a;
 
    cin >> n >> m >> a;
 
    long long r =  (ceil)( (float)n/a );
    long long c = (ceil)( (float)m/a );

    // The above code gives an AC, but it is RECOMMENDED never to use Ceil function becz it might give you Incorrect 
    // values 
    // For example -> 
    // ceil(2.000000000000000001) , if computer do not have much space to handle last wla 1, then wo consider 
    //                              nhi honga and answer will be 2 which is WRONG, it should be 3

    // ceil(a/b)  ====> (a + b - 1) / b
    // floor(a/b) ===> By default, int divide hoke floor value hi dete hai
 
    cout << r * c << endl;
 
    return 0;
}