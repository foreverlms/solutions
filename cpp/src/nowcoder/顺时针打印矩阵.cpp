#include <iostream>

using namespace std;

//29

void printInCircle(int** numbers,int rows,int cols, int start){
    int endX = cols - 1 -start;
    int endY = rows - 1 - start;

    //从左到右打印一行
    for (int i = start; i < endX; i++)
    {
        int num = numbers[start][i];
        cout << num << " ";
    }

    //从上到下打印最右一列
    if(start<endY){
        for (int i = start; i < endY; i++)
        {
            int num = numbers[i][endX];
            cout << num << " ";
        }
    }

    //从右到左打印最下一列
    if(start< endX && start <endY){
        for (int i = endX-1; i> start ; i--)
        {
            int num = numbers[endY][i];
            cout << num << " " ;
        }
        
    }
    //从下到上打印最左一列
    if(start<endX && start < endY - 1){
        for (int i = endY-1; i > start; i--)
        {
            int num = numbers[i][start];
            cout << num << " " ;
        }
    }
}
void printMatrixClockWise(int** numbers,int rows,int cols){
    if(numbers == nullptr || cols <= 0 || rows <= 0){
        return;
    }

    int start = 0;//左上角

    while (cols > start*2 && rows > start*2)
    {   
        printInCircle(numbers,rows,cols,start);

        ++start;
    }
}