#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef struct a{
    int a;
    int b;
} basic;

int main(){
    basic q({1,2});
    std::cout << "b.a: " << q.a << " b.b: " << q.b << "\n";
    return 0;
}