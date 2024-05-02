#include <iostream>

// ******************************************************************
// The following program will ask for two numbers and then add them.
// *******************************************************************
// int main(){
//     std::cout << "Enter two numbers" << std::endl;
//     int v1 = 0, v2 = 0;
//     std::cin >> v1 >> v2;
//     std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
//     return 0;
// }
// ******************************************************************
// The following program will ask for numbers until EOF or a non-number is given.
// It will then return the sum of the numbers given thus far and terminate.
// ******************************************************************
// int main(){
//     int sum = 0, val = 0;
//     while ( std::cin >> val){
//         sum+=val;
//     }
//     std::cout<<"The final value is: "<<sum<<std::endl;
//     return 0;
// }
// *******************************************************************
// This program will check signed and unsigned interger type interactions
// *******************************************************************
// int main(){
//     unsigned u = 10, u2 = 42;
//     std::cout << u2 - u << std::endl;
//     std::cout << u - u2 << std::endl;
//     int i = 10, i2 = 42;
//     std::cout << i2 - i << std::endl;
//     std::cout << i - i2 << std::endl;
//     std::cout << i - u << std::endl;
//     std::cout << u - i << std::endl;
//     return 0;
// }
// *******************************************************************
// This program showcases reference function
// *******************************************************************

// int main(){
//     int i, &ri = i;
//     i = 5; ri = 10;
//     std::cout << i << " " << ri << std::endl;
// }

// *******************************************************************
// This program showcases pointer functionality 
// *******************************************************************
// int main(){
//     int dval = 10;
//     int *point = &dval;
//     int *point2 = point;
//     std::cout << "dval value: "  << dval << " point address: " 
//     << point << " point value: " << *point << " point 2 value: " 
//     << *point2 << std::endl;
//     *point = 0;
//     std::cout << "after setting *point to 0, the new dval value is: " << dval <<  std::endl;
// }
// *******************************************************************
// Exploring Dectype and auto
// *******************************************************************
// int main(){
//     int a = 3, b = 4;
//     auto c = a;
//     decltype((b)) d = a;
//     ++c;
//     ++d;
//     std::cout << a << b << c << d << std::endl;
// }
// *******************************************************************
// Exploring struct and struct operations 
// *******************************************************************
// #include <string>
// #include <iostream>
// struct sales_data {
//     std::string bookNo;
//     double price;
//     unsigned units_sold = 0;
//     double revenue = 0.0;
// };
// int main(){
//     sales_data sale1, sale2;
//     std::cout<<"Enter the book number, number sold, and price" << "\n";
//     std::cin >> sale1.bookNo >> sale1.units_sold >> sale1.price;
//     sale1.revenue = sale1.units_sold*sale1.price;
//     std::cout<<"Enter the book number, number sold, and price" << "\n";
//     std::cin >> sale2.bookNo >> sale2.units_sold >> sale2.price;
//     sale2.revenue = sale2.units_sold*sale2.price;
//     if (sale1.bookNo == sale2.bookNo){
//         unsigned totalCount = sale1.units_sold + sale2.units_sold;
//         double totalRevenue = sale1.revenue + sale2.revenue;
//         std::cout << sale1.bookNo << " " << totalCount << " " << totalRevenue << " ";
//         if (totalCount != 0)
//             std::cout<<totalRevenue/totalCount<<std::endl;
//         else
//             std::cout<<"no sale"<<std::endl;
//         return 0;
//     } else {
//         std::cerr << "Data must refer to the same ISBN" << std::endl;
//         return -1;
//     }
//     return 0;
// }
// *******************************************************************
// Exploring string operations
// *******************************************************************
// #include <string>
// using std::string;
// using std::endl;
// using std::cout;
// using std::cin;

// int main(){

//     // three ways to initialize a string
//     string a("Hello"); // a = Hello
//     string b = "Hello"; // b = Hello
//     string c(10,'a'); // c = aaaaaaaaaa
//     cout << a << " " << b << " " << c << endl;
//     getline(cin, a);
//     cout << a << " " << a + a << " " << (a<b) << endl;
//     return 0;
// }
// *******************************************************************
// The program below will keep printing the strings supplied until EOF
// *******************************************************************
// using namespace std;
// #include <string>
// int main(){
//     string word;
//     // while (cin >> word && word.size()>0) // this will not terminate when empty string is given
//     while (getline(cin, word) && word.size()>0) // this will terminate when empty string is given
//         cout << word << " " << word.size() << endl;
//     return 0;
// }
// *******************************************************************
// Looping through elements of a list and capitalizing them
// *******************************************************************
// using namespace std;
// #include <string>
// int main(){
//     cout << "Go ahead and give a string of lowercase and uppercase letters:" << endl;
//     string str;
//     getline(cin, str);
//     for (char c : str)
//         if (c != ' ' && c>='a' && c<='z')
//             cout << char(c + 'A' - 'a');
//         else
//             cout << c;
//     cout << endl;
// }
// *******************************************************************
// We capitalize elements in a list using references and toupper() function
// *******************************************************************
// using namespace std;
// #include <string>
// int main(){
//     string s("Hello World!");
//     for (auto &c : s)
//         c = toupper(c);
//     cout << s << endl;
//     return 0;
// }
// *******************************************************************
// Vector initialization and copyng
// *******************************************************************
// using namespace std;
// #include <vector>
// #include <string>
// int main(){
//     vector<string> newvector = {"I", "am", "robot"};
//     vector<string> vector1(newvector); // a way to copy vectors
//     vector<string> vector2 = newvector; // another way to copy vectors

//     // the following will collect words ina a vecotr and then print them out
//     string word;
//     vector<string> text;
//     while (getline(cin,word) && word.size()>0) {
//         text.push_back(word);
//     }
//     for (string word : text)
//         cout << word << endl;

//     // next we sqaure each element in the vector

//     vector<int> v{1,2,3,4,5};
//     for (auto &i : v) // note we have to use reference in order to change the value in v
//         i *= i;
//     for (auto i: v)
//         cout << i << " ";
//     cout << endl;
// }
// *******************************************************************
// Capitalizing every element in a string using iterators
// *******************************************************************
// #include <string>
// using namespace std;
// int main(){
//     string s;
//     cin >> s;
//     for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
//         *it = toupper(*it); // capitalize the current character
//     cout << s << endl;
//     return 0;
// }
// *******************************************************************
// Capitalizing every element in a string by iterating via different method 
// *******************************************************************
// #include <string>
// using namespace std;
// int main(){
//     string s;
//     cin >> s; // take in input from the user
//     for (auto &it : s)
//         it = toupper(it); // capitalize the current character
//     cout << s << endl;
//     return 0;
// }
// *******************************************************************
// Four ways in which we can print elements of a multi dimensional array
// *******************************************************************
// using namespace std;
// int main(){
//     int ar[3][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11}};

//     for (auto &a: ar){ // reference the array elements which are arrays
//         for (auto &b: a) // reference the array elements of the arrays
//             cout << b << " "; 
//         cout << endl;
//     }

//     for (auto a = ar; a != ar+3; ++a){ // grab the array and move until we hit the third element within from memory perspective 
//         for (auto b = *a; b != *a + 4; ++b) // grab the item that a is pointing to, and again iterate over memory location
//             cout << *b << " ";
//         cout << endl;
//     }
    
//     for (auto a = begin(ar); a != end(ar); ++a){
//         for (auto b = begin(*a); b != end(*a); ++b)
//             cout << *b << " ";
//         cout << endl;
//     }

//     for (int a = 0; a<3; a++){
//         for (int b = 0; b<4; b++){
//             cout << ar[a][b] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
// *******************************************************************
// The following will count the number of vowels in a given sentance
// *******************************************************************
// using namespace std;
// #include <string>
// int main(){
//     string sentance;
//     getline(cin,sentance);
//     int vovs = 0, consts = 0;
//     for (auto q : sentance){
//         q = tolower(q);
//         if (q >= 'a' && q <= 'z'){
//             switch (q){
//                 case 'a': case 'o': case 'i': case 'u': case 'y': case 'e':
//                     vovs++;
//                     break;
//                 default:
//                     consts++;
//                     break;
//             }
//         }
//     }
//     cout << "In the sentance \"" << sentance << "\"" << " there are " << vovs << " vowels and " << consts << " constanants." << endl; 
// }
// *******************************************************************
// The following will grab a arbitrary number of characters from cin and print them as words
// *******************************************************************
#include <string>
#include <iostream>
using std::cin; using std:: cout; using std::endl; using std::string;
int main(){
    string word;
    while (cin >> word)
        cout << word << endl;
    return 0;
}