//
// Created by bob on 19-3-7.
//

#include "../include/header.h"

/**
 * 下面这种直接操作l1的方法不对
 */
//ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
//    ListNode* p;
//    if ((l1 == NULL && l2 == NULL) || (l1 != NULL && l2 == NULL)){
//        return l1;
//    } else if (l1 == NULL && l2 != NULL){
//        return l2;
//    }
//
//    if (l1->val <= l2->val)
//        p = l1;
//    else
//        p = l2;
//
//    while (l1->next != NULL){
//        ListNode* temp1 = l1->next;
//        ListNode* temp2 = l2->next;
//        if (l1->val <= l2->val){
//            l1->next = l2;
//            l2->next = temp1;
//        } else{
//            l1 = l2;
//            l2->next = temp1;
//        }
//
//        if(temp2 == NULL)
//            break;
//
//        l1 = temp1;
//        l2 = temp2;
//
////        l1 = temp1;
////        l2 = temp2;
////        cout << l1->val << endl;
////        cout << l2->val << endl;
////        cout << "***" << endl;
////
////        if (l1->next == NULL && l2->next != NULL){
////            l1->next = l2;
////            break;
////        } else if (l1->next != NULL && l2->next == NULL){
////            break;
////        } else if(l1->next == NULL && l2->next == NULL){
////            if (l1->val <= l2->val)
////                l1->next = l2;
////            else{
////                temp1 = l1;
////                l1 = l2;
////                l1->next = temp1;
////            }
////            break;
////        }
//    }
//
//    if (l1->next == NULL && l2->next != NULL)
//        l1->next = l2;
//    else if (l1->next == NULL && l2->next == NULL)
//        l1->next = l2;
//
//    return p;
//}

ListNode* Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* first = new ListNode(0);
    ListNode* p = first;

    while (l1 && l2){
        if (l1->val <= l2->val){
            p->next = l1;
            l1 = l1->next;
        } else{
            p->next = l2;
            l2 = l2->next;
        }

        p = p->next;
    }

    if (l1 != NULL){
        p->next = l1;
    }

    if (l2 != NULL){
        p->next = l2;
    }

    return first->next;
}