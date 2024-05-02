#include <cstdio>
#include <cstdlib>
#include <iostream>

// friend class means it can access private elements
// 
class B {
    friend class A;
    private:
        int a = 1;
};

class A {
    public:
        friend void f(){
            std::cout << "f function is called after 1st definition \n";
        }
        void h(){
            std::cout << "h function is called after 1st definition \n The value of a and b are " << this->a << " " << this->b << "\n"; 
        }
        void printB(B& b){
            std::cout << "a field in B is " << b.a << "\n";
        }

    public:
        A() = default;
        A(int a, int b) : a(a), b(b) {};
        int size() const;
        int product() {
            return a * b;
        }
        void g();
    private:
        int a = 0;
        int b = 0;
};

// defining the constructor 
// A::A(int a, int b) : a(a), b(b) {};

// declaring a function becasue its a friendly
// note how we do not need to declare h outside of the class
void f();

int A::size() const {
    return a * b;
}

void A::g(){
    f();
    h(); 
}

int main(){
    A a;
    A b(1,2);
    a.g();
    std::cout << "The product is " << a.product() << "\n";
    b.g();    
    std::cout << "The product is " << b.product() << "\n";
    B q;
    a.printB(q);
}