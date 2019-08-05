#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;



int main(void){
    int num[10000 + 10000];
    int m,n;

    while (~scanf("%d%d", &m, &n))
    {
        for (int i = 0; i < m + n; i++)
        {
            scanf("%d", num + i);
        }
        sort(begin(num), num + m + n);
        // for (auto p = begin(num); p < num + m + n; p++)
        // {
        //     printf("%d", *p);
        // }

        for (int i = 0; i < m + n; i++)
        {
            if (i == 0)
            {
                printf("%d", num[0]);
                continue;
            }

            if (num[i] == num[i - 1])
            {
                continue;
            }
            else
            {
                printf(" %d", num[i]);
            }
        }

        printf("\n");
    }
    
    // while (~(c=scanf("%d%d",&m,&n)))
    // {   
    //     printf("scanf: %d",c);
    //     printf("num is: %d %d",m,n);
    // }
    
    return 0;
}