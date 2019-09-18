#include <iostream>

/**
 * 老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩.

输入描述:
输入包括多组测试数据。
每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
学生ID编号从1编到N。
第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B。

 */
using namespace std;

int getHighestScore(int *scores, int start, int end)
{
    int tmp = scores[start];
    for (int i = start+1; i < end; i++)
    {
        tmp = max(tmp, scores[i]);
    }

    return tmp;
}
int main(void)
{
    int n, m;
    cin >> n >> m;
    int* scores = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    char order;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> order >> a >> b;
        if (order == 'Q')
        {
            cout << getHighestScore(scores, a-1, b) << endl;
        }
        else
        {
            scores[a - 1] = b;
        }
    }

    delete[] scores;
}