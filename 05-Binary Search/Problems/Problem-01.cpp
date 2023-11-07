// Limak, a small bear, created a drawing of his house. The house consists of a square and an isosceles triangle on top. 
// Both shapes are non-degenerate, symmetric, and have positive areas. The square's bottom side is on the x-axis, and the triangle's base is 
// longer than the square's side. All vertices have integer coordinates within [-1000, 1000] and non-negative y-coordinates. 
// Play the game, and you'll receive the drawing!

// TASK --> find the total area of the house (the sum of areas of the square and the triangle). To achieve that, you are allowed to ask at 
//          most 100 queries. In each query you choose some point with integer coordinates and the system will tell you if this point is 
//          in the house (including its boundary).

// FOR DIAGRAM ---> https://www.codechef.com/LRNDSA04/problems/QHOUSE


// Interaction -> 
// ? 1 0	YES
// ? 2 2	YES
// ? -3 0	NO
// ? -1 3	YES
// ? -1 4	YES
// ? 7 4	NO
// ? -3 6	NO
// ? 2 6	YES
// ! 34	


// In Interactive Problems, We go with Binary Search and here the Range of the co-ordinates are mentioned [-1000, 1000]

// LOGIC ---->>> 

// Refer Diagram or imagine that ki ek square ke upar Triangle rkha hai and triangle ka base > square ka side

// Finding the Sqaure side .. Y co-ordinate 0 rhnga saare points ka so hum l = 0 to r = 1000 tak Binary Search lagayenge to get Half of Sq. side

// Now Base nikalne ke liye .. l = Sq_side + 1 to r = 1000 tak binary search lagayenge.. We will get half of Traingle base

// Now for height , x co-ordinate 0 rhnga so hum max y possible nikalenge at x = 0 by Binary Search

#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


map<pair<int,int>,string> prev_values;   

string query(pair<int,int> index){
    if(prev_values.find(index) != prev_values.end()){
        return prev_values[index];
    }
    
    cout << "?" << index.first << " " << index.second << endl;   
    string value; cin >> value;        

    return prev_values[index] = value;

}


int main() {


    int l = 0 , r = 1001;

    while (r-l > 1) {       

        int m = (l + r) / 2;

        (query({m,0}) == "YES") ? l = m : r = m;

    }

    int sq_side = 2 * l;

    r = 1001;

    while (r-l > 1) {       

        int m = (l + r) / 2;

        (query({m, sq_side}) == "YES") ? l = m : r = m;

    }

    int base = 2 * l;

    l = sq_side - 1;
    r = 10001;

    while (r-l > 1) {       

        int m = (l + r) / 2;

        (query({0, m}) == "YES") ? l = m : r = m;

    }

    int total_height = l;
    int t_height = l - sq_side;

    int total_area = (sq_side * sq_side) +  (base * t_height)/2;

    cout << "!" << total_area << endl;

    
    return 0;

}





