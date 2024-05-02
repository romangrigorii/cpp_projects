#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "sales_data.cpp"

int main(){
    Sales_data record1;
    Sales_data record2;
    read(cin, record1);
    read(cin, record2);
    record1.combine(record2);
    print(cout, record1);
    return 0;
}