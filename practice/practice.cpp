#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    std::vector<string> q ({});
    string o;
    while (std::cin >> o){
        if (o.compare("x") != 0){
            break;
        }
        q.push_back(o);
    }
    for (auto a: q){
        std::cout << a << " ";
    }
    cout << endl;

    return 0;
}