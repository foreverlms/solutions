#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};


void symmetric(BinaryTreeNode* root){
    //镜像树
    if(root == nullptr){
        return;
    }

    if(root->left == nullptr && root->right == nullptr){
        //已经遍历到叶子节点
        return;
    }

    BinaryTreeNode* left = root->left;
    root->left = root->right;
    root->right = left;

    //如果是nullptr，就没必要镜像了
    if(root->left){
        symmetric(root->left);
    }

    if(root->right){
        symmetric(root->right);
    }
}