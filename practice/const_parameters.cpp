#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const string &shorterString(const string &s1, const string &s2){
    return s1.size()>s2.size() ? s2 : s1;
}

// overloading the function with nonconst arguments
const string &shorterString(string &s1, string &s2){
    return shorterString((const string &) s1, (const string &) s2); // this forces us to use option 1
}

int main(){
    cout << "Which string is shorter: 'Howdy' or 'Neighbor'? " << shorterString("Howdy", "Neighbor") << "\n";
    // we will force use of overloaded function
    string s1 = "Howdy";
    string s2 = "Neighbor";
    cout << "Which string is shorter: 'Howdy' or 'Neighbor'? " << shorterString(s1, s2) << "\n";
}