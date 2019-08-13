#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main(void){
    int m,n;
    while (cin>>n>>m)
    {
        int a[n],c[n];
        string b[n];
        string judge;
        bool d[n];

        for (int i = 0; i < n; i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            cin>>judge;
            if(judge=="True"){
                d[i]=true;
            }else{
                d[i]=false;
            }
        }

        int a_delta,c_x;
        int c_same[30];
        int b_same[300];
        int c_different[10000];
        

        for (size_t i = 0; i < m; i++)
        {
            int count = 0;
            cin>>a_delta>>c_x;
            int z = 0;
            int t = 0;
            for (int k = 0; k < n; k++)
            {   
                if(c[k]!=c_x){
                    c_different[z]=k;
                    z++;
                }else{
                    c_same[t]=k;
                    t++;
                }
            }

            for (int p = 0; p < t; p++)
            {
                for (int s = 0; s < z; s++)
                {
                    int tmp_1 = c_same[p];
                    int tmp_2 = c_different[s];
                     if (b[tmp_1] == b[tmp_2] && d[tmp_1] != d[tmp_2] && abs(a[tmp_1]-tmp_2) <= a_delta){
                        count++;
                     }
                }
                
            }
            
            cout << count << endl;
        }
        
        
    }
        
}