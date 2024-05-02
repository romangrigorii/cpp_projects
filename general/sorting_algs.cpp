#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

// - - - - - - - SELECTION SORT - - - - - - - - 
template <typename T>
void selection_sort(vector<T> &items){
    T min;
    int min_i;
    int jj;
    for (int ii = 0; ii < items.size(); ii++){
        min = items[ii];
        min_i = ii;        
        for (jj = ii; jj < items.size(); jj++){
           if (items[jj] < min){
                min = items[jj];
                min_i = jj;
           }
        }
        swap(items[ii], items[min_i]);
    }
}
// - - - - - - - INSERTION SORT - - - - - - - - 
template <typename T>
void insertion_sort(vector<T> &items){
    int jj;
    for (int ii = 0; ii < items.size(); ii++){
        jj = ii;
        while (jj>0 && items[jj-1]>items[jj]){
            swap(items[jj-1], items[jj]);
            jj--;
        }
    }
}
// - - - - - - - MERGE SORT - - - - - - - - 
template <typename T>
void merge(vector<T> &items, int l1s, int l1e, int l2s, int l2e){ // merge treats last element as noninclusive 
    int iter = 0;
    int l1ss = l1s;
    vector<T> items_o(items.begin()+l1s, items.begin()+l2e);
    while (l2e>l2s || l1e>l1s){
        if ((l2e==l2s || items[l1s]<items[l2s]) && l1s<l1e) {
            items_o[iter++] = items[l1s++];
        }
        else {
            items_o[iter++] = items[l2s++];
        }
    }
    for (int ii = 0; ii<items_o.size();ii++){
        items[ii+l1ss] = items_o[ii];        
    }
}
template <typename T>
void merge_sort_helper(vector<T> &items, int l1, int l2){// l2 must also be treated as noninclusive 
    if ((l2 - l1)<=2){
        if (items[l1]>items[l2-1]){
            swap(items[l1], items[l2-1]);
        }
    } else {
        merge_sort_helper(items, l1, (l1+l2)/2);
        merge_sort_helper(items, (l1+l2)/2, l2);
        merge(items, l1, (l1+l2)/2, (l1+l2)/2, l2);
    }
};
template <typename T>
void merge_sort(vector<T> &items){
    merge_sort_helper(items,0,items.size());
}
// - - - - - - - QUICK SORT - - - - - - - - 
template <typename T>
void quick_sort_helper(vector<T> &items, int l1, int l2){
    int lsi = l1;
    int lei = l2-1;
    int end_idx = l2;
    while (lei>=lsi){
        while (lsi<=lei && items[lsi]<items[end_idx]){
            lsi++;
        }
        while (lsi<=lei && items[lei]>=items[end_idx]){
            lei--;
        }
        if (lsi<lei) {
            swap(items[lsi++], items[lei--]);
        } else {
            swap(items[end_idx], items[lsi]);
        }
    }
    if ((lsi-l1)>=2){
        quick_sort_helper(items,l1,lsi-1);
    }
    if ((l2-lsi-1)>=2){
        quick_sort_helper(items,lsi+1,l2);
    }
}

template <typename T>
void quick_sort(vector<T> &items){
    quick_sort_helper(items,0,items.size()-1);
}

int main(){
    vector<int> in = {1,6,3,8,4,2,8,6,0,4,5,1};
    vector<int> in_copy1(in);
    selection_sort(in_copy1);
    vector<int> in_copy2(in);
    insertion_sort(in_copy2);
    vector<int> in_copy3(in);
    merge_sort(in_copy3);
    vector<int> in_copy4(in);
    quick_sort(in_copy4);
    for (auto &a: in){
        std::cout << a << " ";
    }
    std::cout << endl;
    for (auto &a: in_copy1){
        std::cout << a << " ";
    }
    std::cout << endl;
    for (auto &a: in_copy2){
        std::cout << a << " ";
    }
    std::cout << endl;
    for (auto &a: in_copy3){
        std::cout << a << " ";
    }
    std::cout << endl;
    for (auto &a: in_copy4){
        std::cout << a << " ";
    }
    std::cout << endl;
    return 0;
}