#include <iostream>

using namespace std;

//54 中序遍历
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* traverse(BinaryTreeNode* root,int& index){
    BinaryTreeNode* target = nullptr;

    if(root->left!=nullptr){
        target = traverse(root->left,index);
    }

    if(target==nullptr){
        if(index==1){
            target = root;
        }

        index--;
    }

    if(target == nullptr && root->right != nullptr){
        target=traverse(root->right,index);
    }


    return target;
}
BinaryTreeNode* theKthLargestNode(BinaryTreeNode* root,int k){
    if(root==nullptr || k==0){
        return nullptr;
    }
    return traverse(root,k);
}

