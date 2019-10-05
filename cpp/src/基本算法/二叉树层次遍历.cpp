#include <iostream>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

/**
 * 层次遍历。这里实现了二叉树的右视图
 */
void traverseByLevel(BinaryTreeNode* root){
    if(!root){
        return;
    }

    queue<BinaryTreeNode*> nodes;

    int count = 1;

    nodes.push(root);

    while (!nodes.empty())
    {
        for (int i = 0; i < count; i++)
        {
            BinaryTreeNode* tmp = nodes.front();
            nodes.pop();
            if(i==count-1){
                cout << tmp->val << endl;
            }

            if(tmp->left){
                nodes.push(tmp->left);
            }

            if(tmp->right){
                nodes.push(tmp->right);
            }
        }

        count = nodes.size();
    }
    
}