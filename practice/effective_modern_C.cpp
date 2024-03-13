#include <stdio.h>
#include <vector>
#include<iostream>

int main(){
    int x = 1;
    int y = 2;

    auto &z = x;
    z++;
    std::cout << " x: " << x << " y: "<< y << " z: "<< z << "\n";
    return 0;
}