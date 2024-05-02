// // Following example in https://cplusplus.com/reference/sstream/stringstream/str/

#include <iostream>
#include <cstring>
#include <sstream> 
#include <vector>
#include <map>

using std::string;
using std::cin;
using std::cout;
using std::vector;

// - - - - - This a tempalte for a 'String'
template <unsigned Size> 
class String {
        char data[Size];
        static int overflows;
    public:
        String( char initial[Size] );
        int length();
};

template <unsigned Size> 
int String<Size>::length( ) {
    int len = 0;
    while (len < Size && data[len]!= '\0') len++;
    return len;
}

template <unsigned Size> 
String<Size>::String(char * initial){
    strncpy(data, initial, Size);
    if (length() == Size) {
        overflows++;
    }
}

template <unsigned Size> int String<Size>::overflows = 0;

void play_with_String(){
    String<10> my_string( (char *) "Hello World!");
    cout << "Length is " << my_string.length() << "\n";
}

// - - - - - this is a template for an Array 
template <class Elem> 
class Array {
        Elem* data;
        int size;
    public:
        print();
        Array( int sz );
        Array( vector<int> sz);
        int GetSize();
        Elem& operator[]( int idx );
};

template <class Elem> 
Array<Elem>::Array( int sz ){
    size = sz; 
    data = new Elem[size];
}

template <class Elem> 
Array<Elem>::Array(std::vector<int> vec ){
    data = new Elem[vec.size()];
    size = vec.size();
    for (int i = 0; i<size; i++){
        data[i] = vec[i];
    }
}

template <class Elem> int Array<Elem>::GetSize(){
    return size;
}

template <class Elem> int Array<Elem>::print(){
    std::stringstream ss;
    for (int i = 0; i < size; i++){
        ss <<  data[i] <<  " ";
    }
    cout << ss.str() << "\n";
}

void play_with_Array(){
    Array<int> hello(std::vector<int>({1,2,3}));
    hello.print();
}

// - - - - - this is an example of templatized max operation

template <class myType>
myType getMax(myType a, myType b){
    return a>b?a:b;
}

// - - - - - - This is a template Counter

template <typename T> 
class Counter{
    std::map<T, int> data;
    public:
        std::vector<T> values();
        std::vector<int> counts();
        int size();        
        void add(T);
        void pop(T);
        void print();
        Counter(std::vector<T> vec);
};

// defining the constructor of Counter 
template <typename T> 
Counter<T>::Counter(std::vector<T> vec) {
    for (auto a: vec){
        this->add(a);
    }
};

template <typename T> 
void Counter<T>::print(){
    for (auto q: data){
        std::cout << q.first << ":" << q.second<< " ";
    }
    std::cout << "\n"; 
}
        

template <typename T> 
vector<T> Counter<T>::values(){
    vector<T> q;
    for (auto a: data){
        q.push_back(a.first);
    }
    return q;
};

template <typename T> 
vector<int> Counter<T>::counts(){
    vector<int> q;
    for (auto a: data){
        q.push_back(a.second);
    }
    return q;
};

template <typename T> 
int Counter<T>::size(){
    return data.size();
};

template <typename T> 
void Counter<T>::add(T elem){
    if (data.find(elem) == data.end()){
        data[elem] = 1;
    } else {
         data[elem] += 1;
    }
};

template <typename T> 
void Counter<T>::pop(T elem){
    if (data.find(elem) == data.end()){
    } else {
        data[elem] -= 1;
        if (data[elem] == 0){
            data.erase(elem);
        }
    }
};


void play_with_counter(){
    Counter<int> numbers_counter = std::vector<int>({1,2,3});
    Counter<string> strings_counter = std::vector<string>({"aa","b","aa", "c"});
    std::cout << "We have made a Counter of numbers and a counter of strings:" << "\n";
    numbers_counter.print();
    strings_counter.print();
    std::cout<<"The numeric values are:" << "\n";
    for (auto a: numbers_counter.values()){
        std::cout << a << " ";
    }
    std::cout << "\n";
    std::cout<<"The string values are:" << "\n";
    for (auto a: strings_counter.values()){
        std::cout << a << " ";
    }
    std::cout << "\n";
    std::cout<<"We will now add 2 'b' and pop 'c' and 'aa'. The result is: " << "\n";
    strings_counter.add("b");
    strings_counter.add("b");
    strings_counter.pop("aa");
    strings_counter.pop("c");
    strings_counter.print();
}

int main(){
    play_with_Array();
    cout<< "- - - - - - - - - - - - - - - - - \n";
    play_with_String();
    cout<< "max between 1 and 2 is " << getMax(1,2)<< "\n";
    cout<< "max between aa and bbb is " << getMax("aa", "bbb") << "\n";
    cout<< "- - - - - - - - - - - - - - - - - \n";
    play_with_counter();
    return 0;
}