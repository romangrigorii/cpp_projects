#include <vector>
#include <deque>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

// emplace - means the constructor will be applied automatically 

class Person{  
    public: 
        Person(std::string name, int age) : name(name), age(age) {};
        void print(){
            std::cout << name << "\n";
        }
    private:
        std::string name;
        int age;
};

int main(){

    std::deque<Person> deq;
    Person q = Person("Roman", 31);
    deq.push_back(q);
    deq.emplace_front("Vanesa", 32);
    deq.emplace(deq.begin(), "Jack", 9);
    deq.insert(deq.begin(), deq.end()-2, deq.end()); // we reinsert the last two elements
    deq.insert(deq.end(), *(deq.begin())); // place beginning element at the end
    for (auto &q: deq){
        q.print();
    }        

    return 0;
}