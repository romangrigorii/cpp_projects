#include<iostream>
#include<vector>
#include<numeric>
#include<map>

using namespace std;

typedef struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(vector<int> mems){ // starting up a linked list from a vecotr input
        ListNode* q = new ListNode();
        ListNode* qp = q;
        if (mems.size()){
            for (auto& mem: mems){
                ListNode *h = new ListNode(mem);
                q->next = h;
                q = q->next;
            }
            this->next = qp->next->next; // this will skip the default initialziation 
            this->val = qp->next->val;    
        }        
    }
    void print(){
        auto q = this;
        while (q){
            cout << q->val<< " ";
            q = q->next;
        }
        cout << endl;
    }
} ListNode;


class ListNode2{
    public:
        ListNode2() : val(0), next(nullptr) {};
        ListNode2(int val): val(val), next(nullptr) {};
        ListNode2(int val, ListNode2 * ln): val(val), next(ln) {};
        void print(){
            ListNode2 * q = this;
            while (q){
                std::cout << q << " ";
                q = q->next;
            }
            std::cout << std::endl;
        }

        void add(int val){
            this->next = this;
            this->val = val;
        }
    private:
        int val;
        ListNode2 * next;
};

int main(void){
    ListNode2 q;
    q.add(10);
    q.add(11);
    q.add(12);
    q.print();

    return 0;
}
