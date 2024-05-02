#include <string>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;

// NOTES
// * Make function that is beign overwitten when inheritted as virtual
// * If you want to import the same template from a class 
// * 
// * 
// * 

class Pet{
    public:
        Pet() = default;
        ~Pet() = default;
        Pet(string name, string sound, int age, int fed_status);
        Pet(string name, int age, int fed_status);
        virtual void makeSound(); // virtual means it can be overwritten
        void feed();
        bool operator< (const Pet & p) {
            return this->age < p.age; 
        }
        std::string getname(){
            return name;
        }
        std::string setname(std::string name){
            this->name = name;
        }
    protected:
        string name;
        string sound;
        int age;
        int fed_status;
};

class Dog : public Pet{
    using Pet::Pet; // This gives up the ability to use the same constructor as Pet
    public:        
        void makeSound() override {
            std::cout<< "Woof" << "\n";
        }
};

Pet::Pet(string name, string sound, int age, int fed_status): name(name), sound(sound), age(age), fed_status(fed_status) {}

Pet::Pet(string name, int age, int fed_status): name(name), age(age), fed_status(fed_status) {}

void Pet::feed(){
    int feed_status_old = fed_status;
    fed_status+=10;
    fed_status = fed_status>100 ? 100 : fed_status;
    std::cout << "I was " << feed_status_old << " % fed, and now I am " << fed_status << " % fed \n";
}

void Pet::makeSound(){
    std::cout<< sound << "\n";
}

int main(){

    auto pet = Pet("Jack", "Meow", 7, 40);
    pet.feed();
    pet.makeSound();
    auto dog = Dog("Cow", 6, 40);
    auto dig = Dog(); // using defualt initiailziation here. 
    dog.makeSound();
    dig.makeSound();
    if (pet<dog){
        std::cout << pet.getname() << " is younger than " << dog.getname();
    } else {
        std::cout << dog.getname() << " is younger than " << pet.getname();
    }
    return 0;
}