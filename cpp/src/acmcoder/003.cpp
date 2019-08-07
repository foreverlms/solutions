#include <iostream>

using namespace std;

/*

    https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1668&konwledgeId=136

 */

int climbStairs(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int before_one = 1, before_two = 1, total = 0;

    for (int i = 3; i <= n; ++i)
    {
        total = before_one + before_two;
        before_two = before_one;
        before_one = total;
    }

    return total;
}

int main(int argc, const char *argv[])
{
    int n, m;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cout << climbStairs(m) << endl;
    }
}