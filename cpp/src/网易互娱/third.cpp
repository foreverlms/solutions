#include <iostream>
#include <vector>
using namespace std;

int mostDaysFirstPeriod(int k, int end)
{
    if (1 == end)
    {
        return 0;
    }
    int days = 0;
    for (int i = 1; i < end; i += (k + 1))
    {
        if (i + k + 1 <= end)
        {
            days++;
        }
    }

    return days;
}
int mostDaysLastPeriod(int k, int start)
{
    if (30 == start)
    {
        return 0;
    }

    int days = 0;
    for (int i = start + k + 1; i <= 30; i += (k + 1))
    {
        days++;
    }

    return days;
}
int mostDaysBetweenInOnePeriod(int k, int start, int end)
{
    int days = 2;
    for (int i = start; i < end; i += (k + 1))
    {
        if (i + k + 1 < end)
        {
            days++;
        }
    }
    return days;
}

int main(void)
{
    int t, k, m, tmp, ans = 0;
    cin >> t;
    for (int  k = 0; k < t; k++)
    {
        cin >> k >> m;
        ans = 0;
        //如果没有固定时间和咖啡
        if (m == 0)
        {
            ans = 1 + mostDaysFirstPeriod(k, 30 - k);
            cout << ans;
            continue;
        }

        vector<int> fixed_days;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            fixed_days.push_back(tmp);
        }
        ans += mostDaysFirstPeriod(k, fixed_days[0]);

        if(fixed_days.size() > 2){
            for (int i = 0; i < fixed_days.size() && i + 1 < fixed_days.size(); i++)
            {
                ans += mostDaysBetweenInOnePeriod(k, fixed_days[i], fixed_days[i + 1]);
            }
            //去除重复计算
            ans -= fixed_days.size() - 2;
        }else if (fixed_days.size() == 2){
            ans += mostDaysBetweenInOnePeriod(k, fixed_days[0],fixed_days[1]);
        }else{
            ans+=2;
        }

        ans += mostDaysLastPeriod(k, fixed_days[fixed_days.size() - 1]);

        cout << ans << endl;
    }
}