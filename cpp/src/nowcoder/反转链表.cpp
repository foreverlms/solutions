#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* reverseList(ListNode* head){
    //三个节点来实行反转,next,last,tmp
    if(!head || !head->next){
        return head;
    }
    ListNode* result = nullptr;
    ListNode* next = head->next;
    ListNode* last = head;
    last->next = nullptr;

    while (!next)
    {
        ListNode* tmp = next->next;

        //判断next是不是最后一个节点
        if(!tmp){
            //那么next就应该是翻转之后的头节点
            result = next;
        }
        next->next = last;
        last = next;
        next = tmp;
    }
    
    return result;
}
int main(void){
    
}