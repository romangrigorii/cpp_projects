#include <cstdio>
#include <cstdlib>
#include <iostream>

class A{
    public:
        A(int a, int b): a(a), b(b), c(a*b) {};
        A(int a) : A(a,a) {}; // this is a delegating constructor        
        void print(){
            std::cout << " a: " << a << " b: " << b << " a*b: " << a*b << "\n";
        }   
        static constexpr int a_value = 30;
    private:
        int a,b,c;
};

constexpr int A::a_value;     


int main(){
    A a(1,2);
    A b(1);
    
    a.print();
    b.print();
    std::cout <<" constant value is: " << b.a_value;
    return 0;
}