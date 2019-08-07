#include <iostream>


int main(int argc, char* argv[]){
    int m,n;
    std::cin>>n>>m;
    
    int array[m+1][n+1];
    std::fill(array[0],array[0]+m*n,0);

    array[0][1]=1;

    for (int i = 1; i < m+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            if(j==1){
                array[i][1]=array[i-1][n]+array[i-1][2];
            }else if (j==n)
            {
                array[i][j]=array[i-1][n-1]+array[i-1][1];
            }else{
                array[i][j]=array[i-1][j-1]+array[i-1][j+1];
            }
        }
    }

    printf("%d\n",array[m][1]);
    


}