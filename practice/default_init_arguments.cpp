#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void ff(int a = 0, int b = 1, int c = 2){
    cout << "a: " << a << " b: " << b << " c: " << c << "\n";
}

void gg(int a, int b, int c = 2){
    cout << "a: " << a << " b: " << b << " c: " << c << "\n";
}

int a = 0;
int b = 1;
void hh(int a = a, int b = b, int c = 2){
    cout << "a: " << a << " b: " << b << " c: " << c << "\n";
}

int main(){
    cout << "ff function output:\n";
    ff();
    ff(3);
    ff(3,4);
    ff(3,4,5);
    cout << "gg function output:\n";
    gg(0, 1);
    cout << "hh function output:\n";    
    hh();
    b = 4; // this b refers to the b declared earlier 
    int a = 3; // this a has nothing to do with the a that was declared earlier
    hh();
}