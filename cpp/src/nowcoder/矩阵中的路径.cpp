#include <iostream>
#include <string.h>
using namespace std;

/**
 * 回溯法，剑指offer面试题12
 */

bool hasPathCore(char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited){
    if(str[pathLength] == '\0'){
        return true;
    }

    bool hasPath = false;
    //满足条件：墙壁也考虑了；matrix[row,col]上的字符等于str[pathLength]；没有被标记已经用过了
    if(row>=0 && row<rows && col >=0 && col <cols && matrix[row*cols+col] == str[pathLength] && !visited[rows*cols+col]){
        ++pathLength;
        visited[row*cols+col]= true;//更新

        //回溯法递归实现
        hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited) ||
                hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited) ||
                hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited) ||
                hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);
        //来检测matrix[row,col]的上下左右四个位置有没有下一个字符

        if(!hasPath){
            --pathLength;
            visited[row*cols+col] = false;//还原
        }
    }
}
bool hasPath(char* matrix,int rows,int cols,char* str){
    if(matrix == nullptr || rows < 1 || str==nullptr){
        return false;//当矩阵为空或者str字符串为空时直接返回false
    }

    bool* visited=new bool[rows*cols];
    memset(visited,0,rows*cols);//将用来记录某个矩阵被访问过数组visited置0
    
    int pathLength = 0;//记录走过的路径长度

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited)){
                return true;
            }
        }
        
    }

    delete[] visited;

    return false;
    
}
int main(void)
{

}