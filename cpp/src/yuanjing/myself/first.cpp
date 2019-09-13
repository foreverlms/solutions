#include <iostream>
#include <vector>

/**
 * 输入一串数字，分别为每天的股票价格，允许任意次的买入卖出，求最大损失多少
 */
using namespace std;
int main(void){
    vector<int> prices;
    int tmp;
    while (cin>>tmp)
    {
        prices.push_back(tmp);
    }

    int loss = 0;
    for (int i = 0; i < prices.size()-1;)
    {

        if(prices[i] > prices[i+1]){
            int j=i+1;
            for (; j < prices.size()-1;j++)
            {
                if(prices[j] < prices[j+1]){
                    loss+=prices[i]-prices[j];
                    i=j+1;
                    break;
                }
            }
            if(j+1 == prices.size()){
                loss+=prices[i]-prices[j];
                break;
            }
        }else{
            i++;
        }
    }
    
    cout << loss << endl;
    
}