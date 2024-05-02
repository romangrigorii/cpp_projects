#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include <vector>

int main(){
    std::vector<std::string> deq;
    std::string neword;
    auto iter = deq.end();
    while (std::cin >> neword){
        if (neword == "x"){
            break;
        }
        iter = deq.insert(iter, neword)+1; // insert places element before iter and returns the new points which is iter-1
        std::cout<<neword + " x " << std::endl;
    }
    for (auto ii = deq.begin(); ii < deq.end(); ii++){
        std::cout << *ii << " ";
    }
    std::cout << std::endl;
}