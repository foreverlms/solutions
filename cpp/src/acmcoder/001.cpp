#include <stdio.h>
#include <algorithm>

/*
https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1664&konwledgeId=134

有股神吗？

有，小赛就是！

经过严密的计算，小赛买了一支股票，他知道从他买股票的那天开始，股票会有以下变化：第一天不变，以后涨一天，跌一天，涨两天，跌一天，涨三天，跌一天...依此类推。

为方便计算，假设每次涨和跌皆为1，股票初始单价也为1，请计算买股票的第n天每股股票值多少钱？

 */

/*
    思路：以每次股票下降为分隔，将价格随天数变化的序列分成m编号的若干个segment:
    n =         1 2 | 3 4 5| 6 7 8 9 | 10 11 12 13 14 | 15 ...
    increment = 0 +1|-1 +1 +1 | -1 +1 +1 +1 | -1 +1 +1 +1 +1 | -1 ...
    segment:    1 2 | 1 2 3| 2 3 4 5 | 4 5 6 7 8 | 7 ...
    m (m>=2) =         2   | 3    |   4     |  5        | 6 ...
    可以得到 m(m+1)/2 - 1 = n => (2m+1)^2 = 8n+9; 每个segment的第一天价格排列为p：
    p = 1 | 1 | 2 | 4 |7 |...
    得到递推公式： p(m) = p(m-1)+m-3，所以p(m)=(m-3)(m-2)/2 + 1;
    所以对于第n天，先求出其所在的segment编号m，然后求出该segment的第一天价格，然后加上n与这个segment第一天相差的天数即为价格。
 */
int main(void)
{
    int n; //第n天
    int first;//每个segment第一天价格
    int price;

    while (~scanf("%d", &n))
    {
        int m;//记录是第几个segment
        m = ceil((sqrt(8*n+9)-1)/2);
        first = (m*m-5*m+8)/2;
        price = first + n - m*(m-1)/2;

        printf("%d\n",price);
    }


    return 0;
}

