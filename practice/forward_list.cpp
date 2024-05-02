#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <forward_list>
#include <vector>
#include <array>
using namespace std;

// We can construct a vector from .begin and .end operators of an iterator of  another entitity
// When begin and end operators do not eist we can use pointers, like in an array

void remove_odd_elements(forward_list<int> flst) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()){
        if (*curr % 2) {
            curr = flst.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
    for (auto& a: flst){
        cout << a << " ";
    }
    cout << endl;
}

void remove_even_elements_and_duplicae_odd(vector<int> vec){
    auto curr = vec.begin();
    while (curr != vec.end()){
        if (*curr % 2){
            curr = vec.insert(curr, *curr);
            curr+=2;
        } else {
            vec.erase(curr);
        }
    }
    for (auto& a: vec){
        cout << a << " ";
    }
    cout << endl;
}

int main(){
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    int array[10] = {1,2,3,4,5,6,7,8,9};
    remove_odd_elements(flst);
    remove_even_elements_and_duplicae_odd(vector<int>(flst.begin(), flst.end()));
    vector<int> array_vec = vector<int>(&array[0], &array[9]);
    for (auto q: array_vec){
        std::cout << q << " ";
    }
    return 0;
}