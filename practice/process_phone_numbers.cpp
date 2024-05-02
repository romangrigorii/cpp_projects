// This is an example file which I will use to process phone numbers in a file

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

bool is_number(string s){
    !s.empty() && s.find_first_not_of("0123456789") == std::string::npos;
}

bool is_para(string s){
    !s.empty() && s.find_first_not_of("()") == std::string::npos;
}

class PhoneNumbers {
    public:
        string firstname;
        vector<string> numbers;
};

int main(int argc, char ** argv){
    string filein = string(argv[1]);
    string fileout = string(argv[2]);
    ifstream input(filein);
    ofstream output(fileout, ofstream::app);
    string num;
    string name;
    string line;
    string word;
    while (getline(input, line)){
        istringstream record(line);
        cout << line << endl;
        while (record >> word){
            if (!is_number(word)){
                name += word + " ";
            } else {
                break;
            }
        }
        while (record >> word){
            if (is_number(word)){
                num+=word;
            } else if (is_para(word)) {
                ;
            } else {
                break;
            }
        }
        output << name << " " << num;
        break;
    }
    return 0;
}