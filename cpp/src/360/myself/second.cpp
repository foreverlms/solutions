#include <iostream>

using namespace std;
int main(void){

    int n,m;
    cin >> n >> m;
    int d[m];
    for (int i = 0; i < m; i++)
    {
        cin >> d[i]; 
    }
    
    int possible = 0;
    
    //回溯法，需要保存每次走失败之后的上一状态
    for (int i = 0; i < n; i++)
    {
        int last_step;
        for (int j = 0; j < m; j++)
        {
            if(last_step)
        }
        
    }
    
}