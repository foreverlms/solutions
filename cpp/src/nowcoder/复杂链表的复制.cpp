#include <iostream>

using namespace std;

//35
struct ComplexListNode
{
    int val;
    ComplexListNode* next;
    ComplexListNode* sibling;
};

//直接在原节点后插入

void clone_node(ComplexListNode* head){
    ComplexListNode* cur = head;
    while (cur!=nullptr)
    {
        ComplexListNode* cloned = new ComplexListNode();
        cloned->val = cur->val;
        cloned->next = cur->next;
        cloned->sibling = nullptr;//sibling暂时不复制

        cur->next = cloned;
        cur = cloned->next;
    }
}

void connecct_sibling_node(ComplexListNode* head){
    ComplexListNode* cur = head;
    while (cur!=nullptr)
    {
        ComplexListNode* cloned = cur->next;
        if(cur->sibling != nullptr){
            cloned->sibling = cur->sibling->next;
        }
        //间隔一个取cur
        cur=cloned->next;
    }
}

ComplexListNode* disconnect_whole_linked_list(ComplexListNode* head){
    ComplexListNode* after_head = nullptr;
    ComplexListNode* cloned = nullptr;
    ComplexListNode* cur = head;

    if(cur){
        after_head = cloned = cur->next;
        cur->next = cloned->next;
        cur = cur->next;
    }
    
    while (cur)
    {
        cloned->next = cur->next;//cloned next指向下一个复制节点
        cloned = cloned->next;//cloned更新为下一个复制节点
        cur->next = cloned->next;//cur next更新为下一个原节点
        cur = cur->next;//cur更新为下一个原节点
    }

    return after_head;
    

}