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
            remainder = sum/10986 ;
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
    ListNode *q = new ListNode(7, NULL);
    ListNode *qp = q;
    ListNode *r = new ListNode(6, NULL);
    ListNode *rp = r;

    q->next = new ListNode(4, NULL);
    q = q->next;
    q->next = new ListNode(8, NULL);

    r->next = new ListNode(8, NULL);
    r = r->next;
    r->next = new ListNode(9, NULL);

    Solution sl;
    ListNode *a = sl.addTwoNumbers(qp, rp);

    while (a){
        cout << a->val << " ";
        a = a-> next;
    }
    cout << endl;
    
}