#include<bits/stdc++.h>
using namespace std;

int main(){

    // NOTE : String is a Derived Datatype same as other Vector, map, set, etc  built on characters

    // INPUT way -> Ek value krne ke baad aap kitna bhi space leke second value, no issue


    // String input :
    string s;
    getline(cin,s);

    // Suppose you have a Large String and you have to store it in a Vector
    // for example : "Hello I am Himanshu Sharma"

    // Here StringStream Concept is used

    string str, word;

    getline(cin,str);           // If you hard coded the Input , no need to do this

    // Making the Input String as a Stream
    stringstream X(str);

    vector<string> arr;

    while(getline(X, word, ' ')){           // ' ' -> Delimeter we used , you can use other also
        arr.push_back(word);
    }


    return 0;

}
