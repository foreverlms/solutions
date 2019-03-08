//
// Created by bob on 19-3-8.
//

#include "../include/header.h"


ListNode* Solution::deleteDuplicates(ListNode* head){
    if (head == NULL)
        return head;
    ListNode* p = head;
    while (p->next != NULL){
        ListNode* tmp = p->next;
        if (p->val == tmp->val){
            p->next = tmp->next;
        } else{
            p = p->next;
        }
    }
    return head;
}