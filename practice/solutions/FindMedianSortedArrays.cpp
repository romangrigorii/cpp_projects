#include<iostream>
#include<vector>
using namespace::std;

double findMedianSortedArrays(vector<int> nums1, vector<int> nums2){
    int L1 = nums1.size(), L2 = nums2.size(), i1 = 0, i2 = 0;
    int mid = (L1+L2)/2; 
    vector<int> out;
    while ((i1 + i2)<=mid){
        if (i2==L2){
            out.push_back(nums1[i1]);
            i1++;
        }
        else if(i1==L1){
            out.push_back(nums2[i2]);
            i2++;
        }
        else if(nums1[i1]<nums2[i2]){
            out.push_back(nums1[i1]);
            i1++;
        } else {
            out.push_back(nums2[i2]);
            i2++;
        }       
    }
    if ((L1 + L2)%2) {
        return out[mid];
    } else {
        return ((double) out[mid] + out[mid-1])/2;
    }
}

int main(){
    cout << "The median of vectors [1,2] and [3,4] is " << findMedianSortedArrays(vector<int>{1,2}, vector<int>{3,4}) << endl;
    cout << "The median of vectors [1,3] and [2] is " << findMedianSortedArrays(vector<int>{1,3}, vector<int>{2}) << endl;
    return 0;
}