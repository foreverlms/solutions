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

    Solution solution;
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};

    solution.rotate(a);

    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a.size(); ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}