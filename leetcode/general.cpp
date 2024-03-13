#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
class Solution {

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    // 1. Given a vector of values return indeces of two that sum up to target 
    vector<int> twoSum(vector<int>& nums, int target);
    // 2. Given two list nodes return a list node of their sum
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
    // 3. Given a substring, find the lnegth of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    // 53: https://leetcode.com/problems/maximum-subarray
    // Given an integer list nums, find the maximum value to which the subarrays can add to.    
    int maxSubArray(vector<int>& nums);
    
    // helper functions
    ListNode* ListNodeCreate(vector<int> nodes);
    void listNodePrint(ListNode* node);

    template<typename T>
    void vectorPrint(vector<T> vec);
};

int main(){
    Solution solution;
    // // // two Sum - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    // vector<int> values = {-1,2,4,-2,3,0,3,4};
    // for (int tt = 0; tt<9; tt++){
    //     cout << "The following (index)value sum up to" << " " << tt << ": ";
    //     auto sol = solution.twoSum(values, tt);
    //     for (auto a: sol){
    //         cout << "(" << a << ")" << values[a] << " ";
    //     }
    //     cout << "\n";
    // }
    // // // add Two Numbers In a Linked List  - - - - - - - - - - - - - - - - - - - - -
    // auto list1 = solution.ListNodeCreate(vector<int>({2,4,3}));
    // auto list2 = solution.ListNodeCreate(vector<int>({5,6,4}));
    // auto list3 = solution.addTwoNumbers(list1, list2);
    // std::cout << "First list is: \n";
    // solution.listNodePrint(list1);
    // std::cout << "Second list is: \n";
    // solution.listNodePrint(list2);
    // std::cout << "Resulting list is: \n";
    // solution.listNodePrint(list3);
    // // // Length of longest substring
    // string s1 = "ajhgjashgdjs";
    // std::cout << "The longest subtring in " << s1 << " is " << solution.lengthOfLongestSubstring(s1) << " long";
    // // // Find median of two arrays
    // vector<int> a1({1,2,3,4});
    // vector<int> a2({5,6,7,8});
    // std::cout << "Median of :\n";
    // solution.vectorPrint(a1);
    // solution.vectorPrint(a2);
    // std::cout << "is: " << solution.findMedianSortedArrays(a1,a2) << "\n";
    // vector<int> a3({1, 2});
    // vector<int> a4({3, 4});
    // std::cout << "Median of :\n";
    // solution.vectorPrint(a3);
    // solution.vectorPrint(a4);
    // std::cout << "is: " << solution.findMedianSortedArrays(a3,a4) << "\n";
    // // // Maximum Subarray
    vector<int> subarr({-2,1,-3,4,-1,2,1,-5,4});
    std::cout << "Max of sum of a subarray is\n";
    solution.vectorPrint(subarr);
    std::cout << solution.maxSubArray(subarr);
    return 0;
}

vector<int> Solution::twoSum(vector<int>& nums, int target){
    std::map<int, int> m;
    int index = 0;
    for (auto q: nums){
        if (m.find(q) == m.end()){
            m[target - q] = index;
        } else {
            return {m[q], index};
        }
        index++;
    }
    return {};
}

Solution::ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* return_list = NULL; // create a new pointer that doesn't point to anything but is of type ListNode*
        return_list = new ListNode(); // new keyword here is what will actually allocate space at the pointed to space of size ListNode
        auto ptr_to_return_list = return_list;
        int residual = 0;
        int val;
        while (residual>0 || l1 || l2){
            val = residual;
            if (l1){
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            residual = (int) val/10;
            val %= 10;
            
            ListNode* newnode = NULL;
            newnode = new ListNode();
            newnode->val = val;
            return_list->next = newnode;
            return_list = return_list->next;
        }
        return ptr_to_return_list->next;
    }

int Solution::lengthOfLongestSubstring(string s) {
        std::map<char, int> m;
        int since_last = 0;
        int max_len = 0;
        for (int idx = 0; idx < s.length(); idx++){
            if (m.find(s[idx]) == m.end()){ // if we do not find a key in a dictionary
                since_last++;
            } else {
                if (s[idx-1] == s[idx]){
                    since_last = 0;
                }
                since_last++;
                since_last = min(since_last, idx - m[s[idx]]);
            }
            max_len = max(max_len, since_last);
            m[s[idx]] = idx;
        }
        return max_len;
    }

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // not finished
    int L1 = nums1.size();
    int L2 = nums2.size();
    int L = L1 + L2; // total length
    int Lm = L/2;
    int even = 0;
    if (L%2 == 0){
        even = 1;
    }
    int idx1 = 0;
    int idx2 = 0;
    float res = 0.0;
    float val = 0.0;
    while ((idx1 + idx2) <= (Lm + even)){
        if (idx1 < L1 && idx2 < L2){
            if (nums1[idx1] <= nums2[idx2]) {                
                val = nums1[idx1];
                idx1++;
            } else {                
                val = nums2[idx2];
                idx2++;
            }
        } else {
            if (idx1 == L1) {                 
                val = nums2[idx2];
                idx2++;
            } else if (idx2 == L2){                
                val = nums1[idx1];
                idx1++;
            }
        }
        if ((idx1 + idx2) >= (Lm) && (idx1 + idx2)<(Lm+even+1)){
            res += val;
        }
    }
    return res/(even == 1 ? 2.0f : 1.0f);
    }

int Solution::maxSubArray(vector<int>& nums) {
        int maxx = nums[0];
        for (int ii = 1; ii < nums.size(); ++ii){
            if (nums[ii-1] > 0) {
                nums[ii] += nums[ii-1];
            }
            maxx = std::max(maxx, nums[ii]);
        }
        return maxx;
    }

/* - - - - - - - - - - - - HELPER FUNCIONS  - - - - - - - - - - - - */
Solution::ListNode* Solution::ListNodeCreate(vector<int> nodes){
    ListNode* return_list = NULL;
    return_list = new ListNode();
    auto ptr_to_list_node = return_list;
    for (auto q: nodes){
        ListNode* new_node = NULL;
        new_node = new ListNode(q);
        return_list->next = new_node;
        return_list = return_list->next;
    }
    return ptr_to_list_node->next;
}

void Solution::listNodePrint(ListNode* node){
    while (node){
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << "\n";
}
template <typename T>
void Solution::vectorPrint(vector<T> vec){
    for (auto &a: vec){
        cout << a << " ";
    }
    std::cout << "\n";
}
