// Given two numbers K and S. Determine how many different values of X,Y and Z such that 
// (0 ≤ X,Y,Z ≤ K) and X+Y+Z = S

// Constraints : 0 ≤ K ≤ 3000, 0 ≤ S ≤ 3K   

#include<bits/stdc++.h>
using namespace std;


int main(){

    int k, s;

    cin >> k >> s;

    // We can generate all possible triplets in 3 loops but O( k^3 ) is not ACCEPTED

    // So We Can consider all possible pairs of x and y and will see that either a Valid Triplet is forming or NOT
    // O( k^2 ) time is ACCEPTED in the given constraints

    long long cnt = 0;

    for(int i=0; i<=k; i++){
        
        for( int j=0; j<=k; j++){

            int z = s - (i + j);

            if( z >= 0 && z <= k){    // VALID
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    
    return 0;
}
