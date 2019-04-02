//
// Created by bob on 19-4-2.
//

#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /**
     * 递归遍历树的结构
     * @param p
     * @param q
     * @return
     */
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //如果当前节点有一个空，另一个不空，这两个节点不一样，那么不是相同树
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        //如果p,q都是空，说明递归到了根节点，两棵树是相同的
        if (p == NULL && q == NULL)
            return true;

        //两个节点都不是空的，这时候就得比较值是否一致
        if (p->val != q->val)
            return false;
        else{
            //值相同也不能说一定是相同的树，还得递归比较其子节点。分左子节点和右子节点进行比较
            return isSameTree(p->left,q->left) && isSameTree(q->right,p->right);
        }
    }
};