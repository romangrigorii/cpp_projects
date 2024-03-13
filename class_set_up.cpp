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


class Pet{
    public:
        Pet(string name, string sound, int age, int fed_status);
        void makeSound();
        void feed();

    private:
        string name;
        string sound;
        int age;
        int fed_status;
};

Pet::Pet(string name, string sound, int age, int fed_status): name(name), sound(sound), age(age), fed_status(fed_status) {}

void Pet::feed(){
    int feed_status_old = fed_status;
    fed_status+=10;
    fed_status = fed_status>100 ? 100 : fed_status;
    std::cout << " I was " << feed_status_old << " fed and now I am " << fed_status << "\n";
}

void Pet::makeSound(){
    std::cout<< sound << "\n";
}

int main(){

    auto pet = Pet("Jack", "Meow", 7, 40);
    pet.feed();
    pet.makeSound();
    return 0;
}