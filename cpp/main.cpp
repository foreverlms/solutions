#include <iostream>
//#include "include/header.h"
#include "src/leetcode15.cpp"
//#include "src/leetcode88.cpp"

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
//    vector<int> a = {-1, 0, 1, 2, -1, -4};
    vector<int> a = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    for (auto x : solution.threeSum(a)){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}