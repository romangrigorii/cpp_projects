#include<iostream>
#include<vector>

using namespace::std;

string longestPalindrome(string s){
    int l, longest = 0, st = 0, en = 0;
    for (int i = 0; i<s.length(); i++){
        l = 1;
        while ((i-l)>=0 && (i+l)<s.length() && s[i-l]==s[i+l]){
            l++;
        }
        if (longest<(l-1)*2 + 1){
            longest = (l-1)*2 + 1;
            st = i-l+1;
            en = i+l-1;
        }        
        l = 1;
        while ((i-l+1)>=0 && (i+l)<s.length() && s[i-l+1]==s[i+l]){
            l++;
        }
        if (longest<((l-1)*2)){
            longest = (l-1)*2;
            st = i-l+2;
            en = i+l-1;
        }
    }
    cout << st << " " << en << endl;
    return s.substr(st, en-st+1);
}

int main(){
    string s1 = "babad";
    string s2 = "cbbd";
    string s3 = "bb";
    string s4 = "ccc";
    cout << "The longest palindrome of "<< s1 << " is " << longestPalindrome(s1) << endl;
    cout << "The longest palindrome of "<< s2 << " is " << longestPalindrome(s2) << endl;
    cout << "The longest palindrome of "<< s3 << " is " << longestPalindrome(s3) << endl;
    cout << "The longest palindrome of "<< s4 << " is " << longestPalindrome(s4) << endl;
    return 0;
}