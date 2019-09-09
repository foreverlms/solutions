#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

/**
 * 给定一个二叉树，每个节点有一个正整数权值。若一颗二叉树，每一层的节点权值和都严格小于下一层次的节点权值和，则称这颗二叉树是递增二叉树。
 * 输入：第一行正整数T，表示有几组用例
 * 接下来T组用例，每组输入的第一行是N，表示树的节点个数，。接下来是N行，每行为一个节点：VAL LEFT RIGHT ，VAL是该节点的值，LEFT是左子节点的序号（就是第几行代表的节点是这个节点的子节点），没有为-1，
 * RIGHT是右子节点，没有为-1.
 * 对于每一组样例，是递增二叉树，输出YES，不是输出NO。
 */
//建立树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    //l,r存储节点序号
    int l;
    int r;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool levelOrder(TreeNode &root)
{
    /**
     * 层序遍历
     */
    queue<TreeNode> q;
    q.push(root);
    //用来比较是否每层递增
    int sum = 0;
    while (!q.empty())
    {
        int size = q.size();
        int tmp_sum = 0;//每层的和
        for (int i = 0; i < size; i++)
        {
            TreeNode tmp = q.front();
            tmp_sum += tmp.val;
            q.pop();
            if (tmp.left != nullptr)
            {
                q.push(*tmp.left);
            }
            if (tmp.right != nullptr)
            {
                q.push(*tmp.right);
            }
        }

        if(sum < tmp_sum){
            //如果确实递增，更新sum
            sum=tmp_sum;
        }else{
            //不是，返回false
            return false;
        }
    }

    return true;
}
int main(void)
{
    int t, n;
    vector<TreeNode> sequence;
    cin >> t;
    while (t)
    {
        cin >> n;
        if (n == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int a[n];
        memset(a, 0, sizeof(int) * n);

        for (int i = 0; i < n; i++)
        {
            int val, l, r;
            cin >> val >> l >> r;

            TreeNode tmp(val);
            tmp.l = l;
            tmp.r = r;
            sequence.push_back(tmp);
        }
        TreeNode *root = nullptr;
        //构建二叉树
        for (int i = 0; i < n; i++)
        {
            if (sequence[i].l != -1)
            {
                sequence[i].left = &sequence[sequence[i].l];
                a[sequence[i].l] = 1;
            }

            if (sequence[i].r != -1)
            {
                sequence[i].right = &sequence[sequence[i].r];
                a[sequence[i].r] = 1;
            }
        }

        //找出根节点
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                root = &sequence[i];
                break;
            }
        }

        if(levelOrder(*root)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

        t--;
    }
}