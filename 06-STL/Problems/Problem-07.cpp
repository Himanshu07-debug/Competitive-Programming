// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Input -->
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output -->
// [null,null,null,null,-3,null,0,-2]


// LOGIC --> 

// Approach 1 ->

// Approach 2 -> Using 2 stacks , one will keep track of the minimum element and One as a Normal stack



#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 


class MinStack {
public:

    stack<int>st;
    stack<int> min_st;

    MinStack(){

    }
    
    void push(int val) {
        if(min_st.size()){
            if(val <= min_st.top()){
                min_st.push(val);
            }
        }
        else{
            min_st.push(val);
        }
        
        st.push(val);

    }
    
    void pop() {

        if(st.top() == min_st.top()) min_st.pop();

        st.pop();

    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
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

