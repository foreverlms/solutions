#include <iostream>
#include<cmath>
#include<stack>


using namespace std;

// int dp[6];
// int weight[6] = {5,3,2,10,4,8},value[6] = {4,8,15,1,6,3};

// struct S1
// {
//     int a;
//     static int b;
// };

// struct S2
// {
//     int a;
//     bool b;
//     char c;
// };

// struct S3
// {
//     float a;
//     int b;
//     char c;
// };

// struct S4
// {
//     double a;
//     float b;
//     int c;
//     char d;
// };

inline int diff(int a,int b){
    if(b==0){
        return a;
    }
    if(a-b > 0){
        return a-b;
    }else{
        return 0;
    }
}


int main(void)
{
    // int max_ = 20;
    // for (int i = 0; i < 6; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         dp[j]= std::max(dp[j],dp[j-weight[i]+value[i]]);
    //     }
        
    // }

    // cout << dp[6] << endl;
    
    // cout << sizeof(S1) << endl;
    // cout << sizeof(S2) << endl;
    // cout << sizeof(S3) << endl;
    // cout << sizeof(S4) << endl;
    int n,m;
    int **num = new int* [n];
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        num[i] = new int[m];
    }
    
    int left=0,right=0,up=0,down=0;
    int left_a=0,right_a=0,up_a=0,down_a=0;

    while (cin>>n>>m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>num[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(num[i][j] == 0){
                    continue;
                }

                area+=2;

                if(j-1 >= 0){
                    left = num[i][j-1];
                }

                if(j+1<m){
                    right = num[i][j+1];
                }

                if(i-1 >=0){
                    up = num[i-1][j];
                }

                if(i+1 < n){
                    down = num[i+1][j];
                }
                int center = num[i][j];

                left_a = diff(center,left);
                right_a = diff(center,right);
                down_a = diff(center,down);
                up_a = diff(center,up);
                
                area += (left_a + right_a + up_a + down_a);

                left = 0;
                right = 0;
                up = 0;
                down = 0;
            }
            
        }
        
        cout <<area << endl;
    }
    
    return 0;
}