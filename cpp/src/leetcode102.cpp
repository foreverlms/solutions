#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *For example : Given binary tree[3, 9, 20, null, null, 15, 7], 
 */


//Definition for a binary tree node.
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        recurse(root,result,0);

        return result;
    }
    /**
     *递归方式
     */
    void recurse(TreeNode* root,vector<vector<int>>& re, int level){
        if (root == NULL)
            return;
        
        //如果此时的re的长度小于层数加一，说明还存在下一层，需要添加一个元素来装下一层
        if (re.size() < level + 1) {
            // vector<int> tmp;
            re.push_back(vector<int>());
        }
        //将节点值装入当前层
        re[level].push_back(root->val);

        recurse(root->left,re,level+1);
        recurse(root->right,re,level+1);
    }

    /**
     * 队列方式
     * 核心就是两个队列，一个队列up用来存上一层节点，另一个队down列存下一层节点
     * 当上一层节点遍历完时，需要把up置为down，并将down清空。什么时候结束呢？
     * 就是down为空时，这时说明没有下一层了。
     */
    vector<vector<int>> queue_(TreeNode* root){
        queue<TreeNode*> up,down;
        vector<vector<int>> result;
        TreeNode* tmp;
        vector<int> tmp_v;

        if (root == NULL) {
            return result;
        }

        up.push(root);

        while(!up.empty()){
           
           while(!up.empty()){
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
        //    result.push_back(tmp_v);
           result.insert(begin(result),tmp_v);
           tmp_v.clear();
           //将down赋给up
           up = down;
           while(!down.empty()){
               down.pop();
           }
        }

        return result;
    }
};