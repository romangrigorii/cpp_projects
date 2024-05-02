#include <cstdio>
#include <cstdlib>
#include <iostream>

// const int * d  : the const here refers to value stored at *d to be const
// int * const d  : the const here refers to the pointer itself to stay const 

int main(){
    int a, b;
    const int c = 1;
    const int *d = &b;
    int * const e = &a;     
    b = 2;
    a = 3;
    d = &a;
    // *d = 4; // not allowed because its a pointer to const object 
    // e = &b; // not allowed because e is a const pointer
    std::cout << "a: " << a <<  " b: " << b << " c: " << c << " d: "<< *d << " e: " << *e << '\n';
}