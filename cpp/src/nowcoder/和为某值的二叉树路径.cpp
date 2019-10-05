#include <iostream>
#include <vector>

using namespace std;
//34
struct BinaryTreeNode
{
    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void find_path(BinaryTreeNode* root,int num,vector<int>& path,int sum){
    sum+=root->val;
    //sum不需要在回溯时减去，因为这是每次调用都会复制一份的局部变量，不是传的引用，互不影响
    path.push_back(root->val);

    bool isLeaf = root->left == nullptr && root->right == nullptr;//此时为叶子节点
    if(isLeaf && sum == num){//如果是叶子节点而且加起来和确实等于num，找到了一条
        for(auto x : path){
            cout << x << " " ;
        }
        cout << endl;
        //TODO:这里可不能return，因为后面的path还没弹出呢
    }

    if(root->left){
        find_path(root->left,num,path,sum);
    }

    if(root->right){
        find_path(root->right,num,path,sum);
    }
    path.pop_back();//返回父节点之前，在路径上删除当前节点
}

void find(BinaryTreeNode* root, int num){
    if(root==nullptr){
        return;
    }

    vector<int> path;
    int sum = 0;
    find_path(root,num,path,sum);
}
