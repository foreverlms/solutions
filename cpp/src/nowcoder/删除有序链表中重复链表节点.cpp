#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

void deleteDuplicatedNode(ListNode **list_head)
{
    //有序链表
    if (!list_head || !*list_head)
    {
        return;
    }

    ListNode *pre = nullptr;
    ListNode *cur = *list_head; //当前节点
    while (cur)
    {
        ListNode *next = cur->next;
        if (next != nullptr && cur->val == next->val)
        {
            int value = cur->val;
            while (cur && cur->val == value)
            {
                ListNode* deleted = cur;
                cur=cur->next;
                //回收这个节点指向的内存空间
                delete deleted;
                deleted = nullptr;
            }
            
            if(pre == nullptr){
                //如果pre==nullptr，说明第一个节点就开始重复了，这时候需要将头节点指向cur
                *list_head = cur;
            }else{
                pre->next = cur;
            }
        }
        else
        {
            pre = cur;
            cur = next;
        }
    }
}
int main(void)
{
}