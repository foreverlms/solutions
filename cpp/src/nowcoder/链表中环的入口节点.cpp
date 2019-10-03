#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node* next;
};

Node* getTheJointNode(Node* head){
    //判断该链表是否存在环
    if(!head){
        return nullptr;
    }

    Node* first = head->next;

    if(!first){
        return nullptr;//只有一个节点
    }
    
    Node* second = head->next->next;//second走的快(一次两步)，first走得慢(一次一步)

    while (second && first)
    {
        if(second == first){
            break;
        }
    }
    
    if(!second || !first){
        return nullptr;//如果second或者first一个为null，说明不存在环
    }

    //执行到这里，说明环存在，而且相遇的节点(并不一定是环开始节点)得到了，即second和first当前指向的节点。现在开始统计环节点包含的节点数目n
    Node* meetingNode = first;
    int n = 1;
    while (first->next != meetingNode)
    {
        first = first->next;
        n++;
    }
    //此时n即为环内节点个数
    first = head;//将first置于头节点
    second = head;
    for (int i = 0; i < n; i++)
    {
        second = second->next;
    }//将second放置于第n个节点
    
    while (first!=second)
    {
        first = first->next;
        second=second->next;//first和second以相同速度向前走，相遇时记为环开始节点
    }
    
    return first;

}
int main(void){

}