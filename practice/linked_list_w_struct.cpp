#include<iostream>
#include<vector>
#include<numeric>
#include<map>

using namespace::std;

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
        }
        this->next = qp->next->next; // this will skip the default initialziation 
        this->val = qp->next->val;    
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


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* q = new ListNode(0);
        ListNode* p = q;
        int remainder = 0;
        int sum = 0;
        while(l1 != NULL || l2 != NULL || remainder != 0){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + remainder;
            remainder = sum/10;
            p->next =  new ListNode(sum%10);
            p->next->next = NULL;
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return q->next;
    }
};

int main(){

    // method 1 of initializing numbers 
    ListNode *q = new ListNode(7, NULL);
    ListNode *qp = q;
    q->next = new ListNode(4, NULL);
    q = q->next;
    q->next = new ListNode(8, NULL);

    ListNode *r = new ListNode(6, NULL);
    ListNode *rp = r;
    r->next = new ListNode(8, NULL);
    r = r->next;
    r->next = new ListNode(9, NULL);

    Solution sl;
    ListNode *a = sl.addTwoNumbers(qp, rp);

    qp->print();
    rp->print();
    a->print();
    
    // method 2 of initializing numbers 
    ListNode *v1 = new ListNode({1,2,3,4});
    ListNode *v2 = new ListNode({7,3,6,5});
    v1->print();
    v2->print();
    ListNode *v3 = sl.addTwoNumbers(v1,v2);
    v3->print();

}