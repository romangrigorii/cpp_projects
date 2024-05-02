#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
struct Sales_data {
    string isbn() const {return bookNo;}
    Sales_data& combine (const Sales_data&);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

double Sales_data::avg_price() const {
    if (units_sold){
        return revenue/units_sold; 
    }
    return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    this->units_sold += rhs.units_sold; // note we do not have to use -> operator, we can simply refer to units_sold
    this->revenue += rhs.revenue;
    return *this;
}

istream &read(istream& is, Sales_data& item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item){
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
