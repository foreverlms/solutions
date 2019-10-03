#include <iostream>

using namespace std;

//28

struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

bool judge(BinaryTreeNode* root_1,BinaryTreeNode* root_2){
    if(root_1 == nullptr && root_2 == nullptr){
        //如果root_1和root_2都为空
        return true;
    }

    if(root_1 == nullptr || root_2 == nullptr){
        //如果只有一个为空
        return false;
    }

    if(root_2->val != root_1->val){
        return false;
    }
    //当root_1和root_2都不为空，且值相等时，判断其各自子树
    return judge(root_1->left,root_2->right) && judge(root_1->right,root_2->left);//递归，root_1的左右子节点必须与root_2的右左子节点对称
}

bool isSymmetrical(BinaryTreeNode* root){
    return judge(root,root);
}


int main(void){

}