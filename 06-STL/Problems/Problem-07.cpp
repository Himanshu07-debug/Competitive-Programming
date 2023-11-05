// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Input -->
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output -->
// [null,null,null,null,-3,null,0,-2]


// LOGIC --> 

// Approach 1 -> Using 2 stacks , one will keep track of the minimum element and One as a Normal stack

// SPACE Optimized -> Instead of using 2 stacks, we can use a Stack of pairs.. first element for normal stack and second for Minimum track

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


class MinStack {
public:

    stack<pair<int,int>> st;

    MinStack(){

    }
    
    void push(int val) {
        if(st.size()){
            st.push({val, min(val,st.top().second)});
        }
        else{
            st.push({val,val});
        }
    }
    
    void pop() {

        st.pop();

    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};




int main(){

    ios::sync_with_stdio(false); cin.tie(NULL);

    // Your code here
    
    MinStack* obj =  new MinStack();
    obj->push(5);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();


    

    
    return 0;
}

