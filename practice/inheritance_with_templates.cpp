#include <cstdlib>
#include <cstdio>
#include <iostream>


// Note tht virtual function can be overwritten
// If we dont specify a function as virtual, then we will use the base version of it

class A {
    public:
        struct a{
            int a;
            int b;
        };
        template <typename T>
        void ff(T &q){ // this function will print out a field from a struct
            std::cout << "a: "<< q.a << " b: " << q.b << "\n";
        }
};

class B : public A {
    public:
        struct b{
            int a;
            int b;
        };
};

int main(){
    A::a struct_a({0,1});
    B::b struct_b({2,3});
    A classA;
    B classB;
    classA.ff(struct_a); // we can provide type but we don't have to
    classB.ff<B::b>(struct_b);

}
