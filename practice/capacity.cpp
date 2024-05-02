// In this file we learn about the functionality of capacity

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<int> q;
    vector<int> caps({0});
    int cur_cap = 0;
    for (int ii = 0; ii<100000; ii++){
        q.push_back(ii);
        cur_cap = q.capacity();
        if (*(caps.end()-1) != cur_cap){
            caps.push_back(cur_cap);
        }        
    }
    for (auto &q: caps){
        cout << q << " ";
    }
    cout << endl;

    return 0;

}