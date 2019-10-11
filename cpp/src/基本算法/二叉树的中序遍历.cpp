#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

//递归实现
void recursive(BinaryTreeNode* root,vector<int>& result){
    if(root==nullptr){
        return ;
    }

    recursive(root->left,result);
    result.push_back(root->val);
    recursive(root->right,result);
}


//栈实现

vector<int> stackForTraversal(BinaryTreeNode* root){
    vector<int> result;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* p = root;
    while (p||!s.empty())
    {
        while (p!=nullptr)
        {
            s.push(p);
            p=p->left;
        }

        if(!s.empty()){
            BinaryTreeNode* cur = s.top();
            s.pop();
            result.push_back(cur->val);
            p=cur->right;
        }   
    }

    return result;
}