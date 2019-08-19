#include <iostream>
#include <vector>
#include <hash_map>
#include <unordered_set>

using namespace __gnu_cxx;
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    int numComponents(ListNode *head, vector<int> &G)
    {
        unordered_set<int> counter(G.begin(), G.end());

        int num = 0;
        while (head)
        {
            if (counter.count(head->val))
            {
                head = head->next;
                //判断下一个元素是否还在G中，在，不加，不在，加一
                if (!head || counter.count(head->val) == 0)
                {
                    num++;
                }
            }
            else
            {
                head = head->next;
            }
        }

        return num;
    }
};