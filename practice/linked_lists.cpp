#include <cstdlib>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <limits>

template <typename T>
class ListNode{
    public:
        ListNode(){
            this->val = 0;
            this->next = nullptr;
        }
        ListNode(std::vector<T> vals): ListNode() { // this will initialize with default listnode
            for (auto &v: vals){
                this->add_back(v);
            }
        };
        ListNode(T val, ListNode* list): val(val), next(list) {};
        T pop();        
        void add_back(T elem);
        void add_front(T elem);
        void print(std::ofstream&);
        void print(std::ostream&); // this will print from vector
        void print2(std::ostream&); // this will print from ListNode
    private:
        ListNode *next;
        T val;        
        std::vector<T> vals;
};



template <typename T>
void ListNode<T>::add_front(T elem){
    auto q = new ListNode(elem, this->next);
    this->val = 0;
    this->next = q;

}  

template <typename T>
void ListNode<T>::add_back(T elem){
    vals.push_back(elem);
    ListNode *q = this;
    while (q->next){
        q = q->next;
    }
    q->next = new ListNode(elem, nullptr);
}   

template <typename T>
void ListNode<T>::print(std::ofstream &os){
    for (auto &v: this->vals){
        os << v << " ";
    }
    os << "\n";
}

template <typename T>
void ListNode<T>::print(std::ostream &os){
    for (auto &v: this->vals){
        os << v << " ";
    }
    os << "\n";
}

template <typename T>
void ListNode<T>::print2(std::ostream &os){
    ListNode *q = this->next;
    while (q){
        os <<q->val << " ";
        q = q->next;
    }
    os << std::endl;
}


int main(){
    //ListNode<int> linked_list(std::vector<int>({1,2,3,4}));
    ListNode<int> linked_list;
    linked_list.add_back(1);
    linked_list.add_back(2);
    linked_list.add_back(3);
    linked_list.print2(std::cout);

    ListNode<int> linked_list2;
    linked_list2.add_front(1);
    linked_list2.add_front(2);
    linked_list2.add_front(3);    
    linked_list2.print2(std::cout);

    ListNode<int> linked_list3(std::vector<int>({5,6,7}));
    linked_list3.print2(std::cout);

}
