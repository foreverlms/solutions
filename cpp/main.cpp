#include <iostream>
//#include "include/header.h"
#include "src/leetcode38.cpp"

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

    Solution solution;
    solution.countAndSay(3);

    string a = "122";

    cout << a + 1 << endl;

    return 0;
}