#include <iostream>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /**
     * 核心：将问题分解为最多只有两层的情况
     * 参照104递归实现，但是这里需要判断左右子节点是否为空
     * 左子节点为空，那么需要递归右子节点树的高度+1
     * 右子节点为空，那么需要递归左子节点树的高度+1
     * 都不为空，则需要递归二者高度较小值+1
     */
    int minDepth(TreeNode *root)
    {
        //DP问题？
        if (root == NULL)
        {
            return 0;
        }

        if(root->left == NULL){
            return minDepth(root->right) + 1;
        }else if(root->right == NULL){
            return minDepth(root->left)+1;
        }else{
            return std::min(minDepth(root->left),minDepth(root->right)) + 1;
        }
    }
};