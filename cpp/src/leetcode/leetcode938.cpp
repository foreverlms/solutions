/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};
class Solution
{
public:
    int sum = 0;

    void traverse(TreeNode* root,int L, int R){
        if (root != nullptr)
        {
            if (root->val <= R && root->val >= L)
            {
                sum += root->val;
            }
            if(root->val < R){
                traverse(root->right,L,R);
            }
            
            if(root->val > L){
                traverse(root->left,L,R);
            }
        }
    }
    int rangeSumBST(TreeNode *root, int L, int R)
    {
       traverse(root,L,R);
       return sum;
    }
};