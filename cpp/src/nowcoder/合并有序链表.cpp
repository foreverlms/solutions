#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
//递归实现
ListNode* merge(ListNode* first_head,ListNode* second_head){
    if(first_head == nullptr){
        return second_head;
    }else if(second_head == nullptr){
        return first_head;
    }//递归终止条件

    ListNode* merged_ptr = nullptr;

    if(first_head->val < second_head->val){
        merged_ptr = first_head;
        merged_ptr->next = merge(first_head->next,second_head);
    }else{
        merged_ptr = second_head;
        merged_ptr->next = merge(first_head,second_head->next);
    }

    return merged_ptr;
}
int main(void){
    
}