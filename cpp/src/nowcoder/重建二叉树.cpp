#include <iostream>
#include <vector>

using namespace std;
//  Definition for binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    //已知前序遍历和中序遍历
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() == 0 || vin.size() == 0)
        {
            return nullptr;
        }

        TreeNode root(pre[0]);

        recons(root, pre, vin);

        return &root;
    }

    void recons(TreeNode &root, vector<int> &pre, vector<int> &vin)
    {
        int left = -1, right = vin.size();
        for (int i = 0; i < vin.size(); i++)
        {
            if (vin[i] == root.val)
            {
                left = i - 1;
                right = i + 1;
                break;
            }
        }
        if (left >= 0)
        {
            root.left = new TreeNode(pre[1]);
            auto b = pre.begin()+1;
            auto e = pre.begin()+left+1;
            auto bb = vin.begin();
            auto ee =vin.begin()+left;
            vector<int> pre_(b,e);
            vector<int> vin_(bb,ee);
            recons(*(root.left),pre_,vin_);
        }

        if (right < vin.size())
        {
            root.right = new TreeNode(pre[right]);
            auto b = pre.begin()+right;
            auto e = pre.end();
            auto bb = vin.begin()+right;
            auto ee = vin.end();

            vector<int> pre_(b,e);
            vector<int> vin_(bb,ee);

            recons(*(root.right),pre_,vin_);
        }
    }
};