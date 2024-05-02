#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;
vector<int> twoSum(const vector<int>& nums, int target) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); i++){
        if (m.find(nums[i])!=m.end()){
            return vector<int>({m[i],i});
        } else {
            m[target - nums[i]] = i;
        }
    }
}

int main(void){
    vector<int> q({2,7,11,15});
    vector<int> a = twoSum(q, 13);
    cout << a[0] << " " << a[1] << endl;
    return 0;
    
}
