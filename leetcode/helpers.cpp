#include<iostream>
#include<vector>
#include<numeric>
#include<map>

using namespace std;

class ListNode2{
    public:
        ListNode2() : val(0), next(nullptr) {};
        ListNode2(int val): val(val), next(nullptr) {};
        ListNode2(int val, ListNode2 * ln): val(val), next(ln) {};
        void print(){
            ListNode2 * q = this;
            while (q){
                std::cout << q->val << " ";
                q = q->next;
            }
            std::cout << std::endl;
        }

        void add(int val){
            if (this -> initialized){                
                auto q = new ListNode2(this->val, this->next);
                this->next = q;                
            }
            this -> initialized = true;
            this->val = val;
        }
    private:
        bool initialized = false;
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
