#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>


int main(){
    std::vector<int> vec = {1,2,3,4,4};
    int arr[5]; 
    // we want to copy entries of vec to arr
    int q = 0;
    for (auto i =  vec.begin(); i!=vec.end(); ++i){
        arr[q++] = *i;
    }

    std::string a = "Hello";
    std::string b = "Howdy";
    std::cout << strcmp(b.c_str(), a.c_str()) << std::endl;

    return 0; 

}