#include <iostream>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void serialize(BinaryTreeNode* root,ostream& out){
    if(!root){
        out<<"$,";
        return;
    }

    out << root->val << ",";
    serialize(root->left,out);
    serialize(root->right,out);
}


void deseialize(BinaryTreeNode** root,istream& in){
    int number;
    if(in>>number){
        *root = new BinaryTreeNode();
        (*root)->val = number;
        (*root)->left = nullptr;
        (*root)->right = nullptr;

        deseialize(&((*root)->left),in);
        deseialize(&((*root)->right),in);
    }
}