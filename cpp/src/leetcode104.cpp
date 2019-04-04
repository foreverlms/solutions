#include <iostream>
#include <algorithm>
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    int maxDepth(TreeNode* root)
    {   
        //DP问题？
        if (root == NULL) {
            return 0;
        }
        
        return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};