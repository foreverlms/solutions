//
// Created by bob on 19-4-3.
//

#include <iostream>
#include <stack>

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
     * 参考一下leetcode100的解法
     * @param root
     * @return
     */
    bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return true;
        }

        return isSameTree(root->left,root->right);
    }

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
            //这里p的左子节点与q的右子节点入参；p的右子节点和q的左子节点入参，
            // 相当于把root这棵树的右子树翻转了了一下来与root的左子树比较。如果一样说明肯定对称
            //这与leetcode100中是不一样的
            return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
        }
    }
};