#include<iostream>
#include<vector>

using namespace::std;

int lengthOfLongestSubstring(string s){
    vector<int> dict(26,-1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++){
        if (dict[s[i] - 'a']>start){
            start = dict[s[i]-'a'];
        }
        dict[s[i]-'a'] = i;
        maxLen = max(maxLen, i - start);
    }
    return maxLen;
}

int main(){
    string s1 = "abcabcbb";
    string s2 = "bbbb";
    string s3 = "pwwkew";
    cout<<"The length of longest substring in "<<s1<<" is "<< lengthOfLongestSubstring(s1)<<endl;
    cout<<"The length of longest substring in "<<s2<<" is "<< lengthOfLongestSubstring(s2)<<endl;
    cout<<"The length of longest substring in "<<s3<<" is "<< lengthOfLongestSubstring(s3)<<endl;
    return 0;
}