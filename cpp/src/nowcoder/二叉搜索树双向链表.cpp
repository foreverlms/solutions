#include <iostream>

using namespace std;

//36

//中序遍历

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* convert(BinaryTreeNode* root){
    BinaryTreeNode* last = nullptr;
    convertNode(root,&last);

    BinaryTreeNode* head = last;

    while (head && last->left)
    {
        head = head->left;
    }
    
    return head;
}

void convertNode(BinaryTreeNode* node,BinaryTreeNode** last){
    if(node==nullptr){
        return;
    }

    BinaryTreeNode* cur = node;
    if(cur->left){
        convertNode(cur->left,last);
    }

    cur->left = *last;
    if(*last){
        (*last)->right = cur;
    }

    if(cur->right){
        convertNode(cur->right,last);
    }
}