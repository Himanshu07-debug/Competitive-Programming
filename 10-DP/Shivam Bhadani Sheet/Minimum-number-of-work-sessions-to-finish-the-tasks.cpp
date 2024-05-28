#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds; 

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> PBDS;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> PBDSp;


#define endl '\n'
const long long MOD = 1e9 + 7;
const long long INF = LLONG_MAX >> 1; 
const long long NINF = LLONG_MIN;

// There are n tasks assigned to you. The task times are represented as an integer array tasks of length n, where the ith task takes 
// tasks[i] hours to finish. A work session is when you work for at most sessionTime consecutive hours and then take a break.

// You should finish the given tasks in a way that satisfies the following conditions:

// If you start a task in a work session, you must complete it in the same work session.
// You can start a new task immediately after finishing the previous one.
// You may complete the tasks in any order.
// Given tasks and sessionTime, return the minimum number of work sessions needed to finish all the tasks following the conditions above.

// Input: tasks = [1,2,3], sessionTime = 3
// Output: 2
// Explanation: You can finish the tasks in two work sessions.
// - First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
// - Second work session: finish the third task in 3 hours.

// Wrong Greedy Approach:

// 1. Sort the tasks array and keep adding the task to the current session until the sum becomes equal to or more than the sessionTime.
// 2. This approach fails on test cases like tasks = {3, 4, 7, 8, 10} sessionTime = 12

// also BS also not helping..

// Constraint dekhke and kuch aur na chalne pe --> Recursion hi lga

// any Moment --> 2 choices ... 
// either to include the tasks[i] to the new session or to include it to any of the previous active sessions 

// We have created a vector named sessions. The length of which denotes the number of work sessions we currently have
// sessions[i] denotes the number of work hours we have completed in the ith session


int rec(int i, int n, vector<int> &sessions, int sessionTime, vector<int> &tasks){

    if(i >= n) return 0;

    // adding a new session 
    sessions.push_back(tasks[i]);
    int ans = 1 + rec(i+1, n, sessions, sessionTime, tasks);
    sessions.pop_back();


    // trying to add tasks[i] to the previous active work sessions
    for(int j=0;j<sessions.size();j++){

        if(sessions[j] + tasks[i] <= sessionTime){

            sessions[j] += tasks[i];

            int res = rec(i+1, n, sessions, sessionTime, tasks);
            ans = min(ans, res);

            sessions[j] -= tasks[i];

        }

    }

    return ans;

}


int minSessions(vector<int>& tasks, int sessionTime) {

    vector<int> sessions;

    return rec(0, tasks.size(), sessions, sessionTime, tasks);
    
}




// Memoization --> 
// many overlapping state 
// in [1, 2, 3] only, 3 is visited and computed twice

// 2 changing parameters --> indx and sessions vector... We can use unordered_map.. but key should contain both indx and sessions..
// we can use map with pair of indx and vector...

// but learn a new way to handle such things...
// like huffman encoding... encode your state in a key of string ....


unordered_map<string, int> dp;

string encodeState(int pos, vector<int>& sessions) {

    vector<int> copy = sessions;

    // We first sort the sessions to reduce the number of repeated states.
    // [1, 3, 2], [1, 2, 3], [3, 1, 2]
    // in all of this.. the active work sessions are same.  
    sort(copy.begin(), copy.end());
    
    string key = to_string(pos) + "$";

    for (int i = 0; i < copy.size(); i++)
        key += to_string(copy[i]) + "$";
    
    return key;

}

int rec(int i, int n, vector<int> &sessions, int sessionTime, vector<int> &tasks){

    if(i >= n) return 0;

    string key = encodeState(i, sessions);

    if(dp.find(key) != dp.end()) return dp[key];

    // adding a new session 
    sessions.push_back(tasks[i]);
    int ans = 1 + rec(i+1, n, sessions, sessionTime, tasks);
    sessions.pop_back();


    // trying to add tasks[i] to the previous active work sessions
    for(int j=0;j<sessions.size();j++){

        if(sessions[j] + tasks[i] <= sessionTime){

            sessions[j] += tasks[i];

            int res = rec(i+1, n, sessions, sessionTime, tasks);
            ans = min(ans, res);

            sessions[j] -= tasks[i];

        }

    }

    return dp[key] = ans;

}


int minSessions(vector<int>& tasks, int sessionTime) {

    vector<int> sessions;

    return rec(0, tasks.size(), sessions, sessionTime, tasks);
    
}


// BITMASKING WILL LEARN LATER
