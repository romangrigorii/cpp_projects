#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream> 
#include <vector>
#include <cstring>
#include <sstream> 
#include <array>

#define BUFSIZE 30

using std::string;
using std::cin;
using std::cout;

void read_and_print_words(){
    string instring;
    cout << "Provide your string now \n";
    while (cin >> instring){
        for (auto a: instring){
            if (!ispunct(a)){ // eliminate punctuation from the printout 
                cout<<a;
            }
        }
        cout << "\n";
    }
}

int main(){   
    // a small section on copying over a string to a buffer in an efficient manner
    char q[BUFSIZE]; 
    memcpy(q, "Hello and welcome to this wonderful tutorial: ", BUFSIZE*sizeof(char));
    q[BUFSIZE-1] = '\0';
    printf("%s\n", q);

    // a small section on copying over a string to a buffer in an efficient manner
    strcpy(q, "You will now be given a task: ");
    printf("%s\n", q);
   
    //read_and_print_words();

    // capitalizing the first letter
    string s("hello world");
    std::cout << "Lets capitalize "<< s << "\n";
    if (s.size()>0){
        auto it = s.begin();
        *it = toupper(*it);
    }
    // captialize the first word
    std::cout << s << "\n";
    for (auto it = s.begin(); it !=s.end() && !isspace(*it); ++it ){
        *it = toupper(*it);
    }
    std::cout << s << "\n"; 
    // another way of initializing the buffer 
    char a[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    std::cout << a << "\n";
    

    std::vector<char> b;
    string word = "Hello World";
    b.assign(word.begin(), word.end());
    for (auto &q: b){
        std::cout << q << " ";
    }
    std::cout << std::endl;

    // Initializing a string
    string hello("Hello World");
    const char *hello_arr = hello.c_str();
    string gg(hello_arr); // this will grab the entire array
    string qq(hello_arr, 8); // this will make qq grab the first 8 charcters of the array
    std::cout<< "Out of " << hello << " we grabbed " << qq << std::endl; 
    string hh(hello, 2); // will make hh grab all characters after (including) index 2 items
    std::cout<< "Out of " << hello << " we grabbed " << hh << std::endl; 
    string nn(hello, 2, 5); // will make nn will grab characters in the range 2 - 5 from hello
    std::cout<< "Out of " << hello << " we grabbed " << nn << std::endl;
    hello.erase(1,2); // We erase to letters started from 'e' In Hello to get -> Hlo World
    std::cout << "We erased some parts of Hello World to obtain " << hello << std::endl;

    // Now we are going to find parts of a string
    string a_sentance("I went to the store the other day.");
    string vowels("iouyaeIOUYAE");
    string::size_type pos = 0;
    std::cout << "Lets print all the vowels out of " << a_sentance << std::endl;
    while ((pos = a_sentance.find_first_of(vowels, pos)) != string::npos){
        cout<<"found number at index: " << pos << " element is " << a_sentance[pos] << std::endl;
        ++pos;
    }
}





