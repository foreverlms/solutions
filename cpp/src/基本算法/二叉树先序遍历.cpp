#include <iostream>
#include <vector>
#include <stack>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

/**
 *递归实现 
 */
void recursive(TreeNode* root, vector<int>& res){
    if(root==nullptr){
        return;
    }

    res.push_back(root->val);
    recursive(root->left,res);
    recursive(root->right,res);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> res;
    recursive(root,res);
    return res;
}

/**
 * 栈实现
 */

vector<int> stackForTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> nodes;
    TreeNode* p = root;
    while (p || !nodes.empty())
    {
        while (p)
        {
            res.push_back(p->val);
            nodes.push(p);
            p=p->left;
        }
        
        if (!nodes.empty())
        {
            TreeNode* cur = nodes.top();
            nodes.pop();
            p=cur->right;
        }
        
    }

    return res;
    
}