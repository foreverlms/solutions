#include<iostream>

using namespace std;

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

//递归遍历树

bool ans(BinaryTreeNode* tree_A,BinaryTreeNode* tree_B){
    //找子树的第一步，先遍历A树找出和根节点一样的节点，来判断
    bool res = false;
    if(!tree_A && !tree_B){
        if(tree_A->val == tree_B->val){
            res = AContainsBRoot(tree_A,tree_B);
        }
        //当前A的节点并不包含B树，遍历A的左右子树
        //左子树
        if(!res){
            res = ans(tree_A->left,tree_B);
        }
        //右子树
        if(!res){
            res = ans(tree_A->right,tree_B);
        }
    }

    return res;
}
//判断B树是否是A树的子结构
bool AContainsBRoot(BinaryTreeNode* tree_A,BinaryTreeNode* tree_B){
    //判断A树总是否含有B树的根节点

    if(!tree_B){
        return true;//B树是空的，肯定是A树的子结构
    }

    if(!tree_A){
        return false;//A树空，肯定不是
    }

    if(tree_A->val != tree_B->val){
        return false;//两个节点的值不一致，肯定不是啊
    }
    //如果值相等，那么就要对左右子树递归了
    return AContainsBRoot(tree_A->left,tree_B->left) && AContainsBRoot(tree_A->right,tree_B->right);//递归，A的左子树必须包含B的左子树
}
int main(void){

}