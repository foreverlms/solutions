#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
  public:
    /**
     * 队列法，参照leetcode107.cpp
     */
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> up, down;
        vector<vector<int>> result;
        TreeNode *tmp;
        vector<int> tmp_v;

        if (root == NULL)
        {
            return result;
        }

        up.push(root);

        while (!up.empty())
        {

            while (!up.empty())
            {
                tmp = up.front();
                up.pop();

                tmp_v.push_back(tmp->val);

                if (tmp->left)
                {
                    down.push(tmp->left);
                }

                if (tmp->right)
                {
                    down.push(tmp->right);
                }
            }
            result.insert(begin(result), tmp_v);//这里与107不一样，在result头部插入新的一层
            tmp_v.clear();
            //将down赋给up
            up = down;
            while (!down.empty())
            {
                down.pop();
            }
        }

        return result;
    }

    vector<vector<int>> recurse(TreeNode* root){
        vector<vector<int>> result;
        recurse(root,result,0);

        return result;
    }

    void recurse(TreeNode *root, vector<vector<int>> &re, int level)
    {
        if (root == NULL)
            return;

        //如果此时的re的长度小于层数加一，说明还存在下一层，需要添加一个元素来装下一层
        if (re.size() < level + 1)
        {
            // vector<int> tmp;
            // re.push_back(vector<int>());
            re.insert(begin(re),vector<int>());
        }
        //将节点值装入当前层
        re[re.size() - level - 1].push_back(root->val);

        recurse(root->left, re, level + 1);
        recurse(root->right, re, level + 1);
    }
};