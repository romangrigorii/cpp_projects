// In this file I will practice object structures in order to save and retrive data
#include <iostream>
#include <vector>
#include <map> 

using std::string;
using std::cout;

class Person{
    public:
        int get_age();
        std::string get_name();
        void set_name(std::string);
        void set_age(int);
        void report();
        Person(std::string name, int age, std::string type);
    private:
        int age;
        string name;
        string type;
};

class ClassRoom{    
    public:
        int get_kids_num();
        int get_teachers_num();
        std::string get_class_name() {return name;}
        void add_student(Person student) { kids.push_back(student);}

        ClassRoom(std::string name); // whenever you see an object of the same name as the class, this is a constructor
        ClassRoom(std::string name, std::vector<Person> teachers, std::vector<Person> kids);
        
    private:
        string name;
        std::vector <Person> teachers;
        std::vector<Person> kids;
};

ClassRoom::ClassRoom(std::string name): name(name) {
    ClassRoom::name = name += '!';
}

Person::Person(std::string name, int age, std::string type) : name(name), age(age), type(type){

}



int Person::get_age() {
    return Person::age;
}

std::string Person::get_name() {
    return Person::name;
}

void Person::set_age(int age){
    Person::age = age;
}

void Person::set_name(std::string name){
    Person::name = name;
}

int ClassRoom::get_kids_num(){
    return ClassRoom::kids.size();
}

int ClassRoom::get_teachers_num(){
    return ClassRoom::teachers.size();
}

int main(){

    ClassRoom clas("Algebra");
    std::cout << "This is " << clas.get_class_name() << "\n";
    printf("\a");
}