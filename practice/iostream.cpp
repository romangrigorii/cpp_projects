#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "sales_data.cpp"
#include <fstream>

int main(int a, char ** b){
    string in_filename = std::string(b[1]);
    string out_filename = std::string(b[2]);
    ifstream input(in_filename);
    ofstream output(out_filename, ofstream::app); // this will preserve file entries and just add to the end of the file
    Sales_data total;
    if (read(input, total)){
        Sales_data trans;
        while (read(input, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    } else 
        cerr << "No data?!" << endl;
    return 0;
}

// ./a 'files/book_info_in' 'files/book_info_out'