#include <iostream>

using namespace std;
//39

/**
 * 第一种方法：
 * 类似快排来做
 */
int partition(int *source, int start, int end, int len)
{
    int tmp = source[start];

    int left = start;//这里必须是从start开始
    int right = end - 1;

    while (left < right)
    {

        while (left < right && source[right] >= tmp)
        {
            right--;
        }
        source[left] = source[right];
        while (left < right && source[left] <= tmp)
        {
            left++;
        }
        source[right] = source[left];
    }

    source[left] = tmp;

    return left;
}
int getTheMediumNumber(int *source, int len)
{
    if(len<=2 && len >=1){
        return source[0];
    }

    int middle = len / 2;
    int start = 0;
    int end = len;

    int index = partition(source,start,end,len);
    while (index != middle)
    {
        if(index > middle){
            end = index;
            index = partition(source,start,end,len);
        }else{
            start = index+1;
            index = partition(source,start,end,len);
        }
    }

    int res = source[middle];

    return res;    
}


/**
 * 第二种方法：
 * 计数法，两个数，p208
 */

int ans(int* source,int len){
    int res = source[0];
    int times = 1;

    for (int i = 0; i < len; i++)
    {
        if(times == 0){
            res=source[i];
            times=1;
        }else if(source[i] == res){
            times++;
        }else{
            times--;
        }
    }
    
    return res;
}