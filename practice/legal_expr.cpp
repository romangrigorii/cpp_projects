#include <cstdlib>
#include <iostream>
#include <vector>
#include <stdio.h>


void summ(int& val1, const int &val2){
    val1 += val2;
}

char &get_char(std::string &str, const int& idx){
    // rturns reference to a character at some index within the string
    return str[idx];
}

template <typename T>
void print_vec(std::vector<T> a){
    if (a.size() > 0){
        std::cout<< a[0] << " ";
        print_vec(std::vector<T>{a.begin()+1, a.end()});
    } else {
        std::cout <<"\n";
    }    
}

int *return_pointer(std::vector<int> values){
    return &values[0];
}
// another way of declaring the return type of a function
auto return_pointer_2(std::vector<int> values) -> int* {
   return &values[0];
}

int main(){
    std::vector<int> q({1,2,3});
    auto a = q.begin();
    // iterator stuff 
    std::cout << "Iterator stuff" << "\n";
    std::cout << *a++ << "\n"; // this returns 1 and incremeents the iterator to position 1
    std::cout << (*a)++ << "\n"; // This iterates the values at position 1, i.e. 2 becomes 3, but the returned values is 2
    std::cout << ++*a << "\n"; // This iterates the values at position 1, i.e. 3 becomes 4
    // operands 
    std::cout<< "Operands" << "\n";
    unsigned long ul1 = 3, ul2 = 7;
    std::cout << "3 & 7  = " << (ul1 & ul2) << '\n';
    std::cout << "3 && 7 = " << (ul1 && ul2) << '\n';
    std::cout << "3 | 7  = " << (ul1 | ul2) << '\n';
    std::cout << "3 || 7 = " << (ul1 || ul2) << '\n';

    // implicit type conversions
    char cval;
    int ival = 3;
    unsigned int ui = 2;
    float fval = -1;
    double dval;
    cval = 'a' + 3;         // converts to int and then back to char
    fval = ui - ival*1.0;   // converts ui to int, subtracts, then converts to float
    dval = ui * fval;       // converts ui to float, multiplies, then conerts to double
    std::cout << cval << " " << fval << " " << dval << "\n";

    // use of const value and passing by reference 
    // we have to use a const otherwise we won't be able to pass an l value as reference
    int aa = 10;
    summ(aa, 10);
    std::cout << "The value of a is " << aa << "\n";

    // using refernece to change a value in a string
    std::string atr = "Hello World";
    std::cout << "The string is " << atr << "\n";
    get_char(atr, 0) = 'N';
    std::cout << "The string was changed to " << atr << "\n";

    // recusrive printout of vector contents
    print_vec<int>({0,1,2,3,4});

    // return pointer to passed array as an exercize
    std::vector<int> vec ({0,1,3});
    std::cout << *return_pointer(vec) << "\n";
    std::cout << *return_pointer_2(vec) << "\n";

}
