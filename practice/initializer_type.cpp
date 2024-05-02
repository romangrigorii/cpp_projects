#include <cstdio>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include <iterator> 

bool is_number(const std::string &s) {
    return !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}

bool is_number2(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

template <typename T>
void sum_of_numbers(std::initializer_list<T> input){
    std::cout << "The sum of ";
    T sum = 0;
    for (const auto &msg : input){
        std::cout << msg << " ";
        sum += msg;
    }
    std::cout << "is " << sum << "\n";
}



int main(int varc, char **varv){
    std::cout << "You passed " << varc << " arguments\n";
    sum_of_numbers({1,2,3,4});
    return 0;
}