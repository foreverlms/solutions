#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

/**
 * 逆序输出链表
 * 思路： 1、遍历，入栈；
 *       2、递归
 */
class Solution
{
public:

    void recursive(ListNode* head,vector<int>& array){
        if(head->next != nullptr){
            recursive(head->next,array);
        }

        array.push_back(head->val);
    }
    vector<int> printListFromTailToHead(ListNode *head)
    {
        vector<int> array;
        if(head == nullptr){
            return array;
        }

        recursive(head,array);
        return array;
    }
};