#include <iostream>
#include <vector>

using namespace std;

/**
 * 某风电场每台风机的发电量和离升压站的距离各不相同，如风机1发电量30，距离20,；风机2发电量35，距离30...要求输电总距离限定（小于100）的前提下，选择不同的风机得到的总发电量最大。
 * 0-1背包问题
 */
int main(void)
{
    vector<int> distance, walt;
    int tmp;
    int max_dist;
    while (cin >> tmp)
    {
        while (cin.get() != '\n')
        {
            distance.push_back(tmp);
            cin >> tmp;
        }
        cin >> tmp;
        while (cin.get() != '\n')
        {
            walt.push_back(tmp);
            cin >> tmp;
        }

        cin >> max_dist;
        vector<int> dp(max_dist + 1,0);
        for (int i = 0; i < distance.size(); i++)
        {
            for (int j = max_dist; j >= distance[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - distance[i]] + walt[i]);
            }
        }

        cout << dp[max_dist];
    }
}