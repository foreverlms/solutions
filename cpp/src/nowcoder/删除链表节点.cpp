#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
};

void deleteNode(ListNode* head,ListNode* tobedeleted){
    if(!head || !tobedeleted){
        return;
    }

    if(tobedeleted->next != nullptr){
        ListNode* next = tobedeleted->next;
        tobedeleted->val = next->val;
        tobedeleted->next = next->next;

        next = nullptr;
    }else if(head == tobedeleted){
        head=nullptr;
        delete tobedeleted;
        tobedeleted=nullptr;
    }else{
        ListNode* next = head;
        while (next->next != tobedeleted)
        {
            next = next->next;
        }

        next->next = nullptr;
        delete tobedeleted;
        tobedeleted = nullptr;
        
    }
}
int main(void){
    
}
