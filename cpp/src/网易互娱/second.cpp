#include <iostream>
#include <vector>
using namespace std;

//建立树节点
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int l;
    int r;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main(void){
    int t,n;
    vector<TreeNode> queue;
    cin>>t;
    // while (t)
    // {
    //     cin >> n;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int val,l,r;
    //         cin >> val >> l >> r;

    //         TreeNode tmp(val);
    //         tmp.l = l;
    //         tmp.r=r;

    //         queue.push_back(tmp);
    //     }
        
    // }
    TreeNode tmp(10);
    queue.push_back(tmp);
    cout << queue[0].val <<endl;

    tmp.val = 9;
    queue.push_back(tmp);
    cout << queue[1].val << endl;
}