//
// Created by bob on 19-2-28.
//

#ifndef CPP_HEADER_H
#define CPP_HEADER_H


#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL){}
};

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs);
    int minPathSum(vector<vector<int>>& grid);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    ListNode* deleteDuplicates(ListNode* head);
};
#endif //CPP_HEADER_H
