#include <iostream>
//#include "include/header.h"
#include "src/leetcode48.cpp"

int main() {
//    vector<string> strs = {};
//    Solution solution;
//    ListNode a(1);
//    ListNode b(1);
//    ListNode c(4);
//
//    a.next = &b;
//    b.next = &c;
//
//    ListNode d(0);
//
//
//    ListNode *p = solution.mergeTwoLists(&a,&d);
//
//    while (p->next != NULL){
//        cout << p->val << endl;
//        p = p->next;
//    }

    vector<int> a = {1,2,3,4};

    auto start = begin(a),end_ = end(a);

    for (start;start != end_;start++)
        cout << *start << endl;
    

    return 0;
}