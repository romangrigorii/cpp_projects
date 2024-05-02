#include<iostream>
#include<vector>
#include<numeric>
#include<map>

using namespace::std;


class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        std::map<int,int> nummap;
        vector<int> out;
        int n = 0;
        while(n <= nums.size()){
            if (nummap.count(nums[n]) > 0){
                out.push_back(nummap[nums[n]]);
                out.push_back(n);
                break;
            } else {
                nummap[target-nums[n]] = n;
            }
            n++;
        }
        return out;
    }

    void twoSumA(vector<int>& nums, int target, int *out) {
        std::map<int,int> nummap;
        int n = 0;
        while(n <= nums.size()){
            if (nummap.count(nums[n]) > 0){
                out[0] = nummap[nums[n]];
                out[1] = n;

                break;
            } else {
                nummap[target-nums[n]] = n;
            }
            n++;
        }
    }
};


int main(){
    Solution cl;
    vector<int> v;    
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    int *out;
    cl.twoSumA(v,6,out);// this one processes a reference and a pointer to a string and returns nothing
    for (int i: cl.twoSum(v,6)){ // this one process a vector and returns a string
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0;i <2; i++){
        cout << out[i] << " ";
    }
    cout << endl;
    return 0;
}