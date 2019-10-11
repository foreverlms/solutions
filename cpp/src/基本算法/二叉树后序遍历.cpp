#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 *递归实现 
 */
void recursive(TreeNode* root, vector<int>& res){
    if(root==nullptr){
        return;
    }

    recursive(root->left,res);
    recursive(root->right,res);
    res.push_back(root->val);

}
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> res;
    recursive(root,res);
    return res;
}

//非递归实现

vector<int> stackForTraversal(TreeNode* root){
    TreeNode* p = root;
    vector<int> res;
    stack<TreeNode*> nodes;
    if(root==nullptr){
        return res;
    }
    nodes.push(root);

    while (!nodes.empty())
    {
        TreeNode* cur = nodes.top();
        nodes.pop();
        //队首插入
        res.insert(res.begin(),cur->val);

        if(cur->left){
            nodes.push(cur->left);
        }

        if(cur->right){
            nodes.push(cur->right);
        }
    }

    return res;
    
}