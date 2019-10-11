#include <iostream>

using namespace std;
void show(int *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;
}
/**
 * 插入排序 o(n^2) 稳定 适用于小规模数据或者基本有序
 * 数列前面部分看为有序，依次将后面的无序数列元素插入到前面的有序数列中，初始状态有序数列仅有一个元素，即首元素。
 * 在将无序数列元素插入有序数列的过程中，采用了逆序遍历有序数列，相较于顺序遍历会稍显繁琐，但当数列本身已近排序状态效率会更高。
 */
void insertSort(int *source, int len)
{
    //从第二个元素开始。以升序为例
    for (int i = 1; i < len; i++)
    {
        //0-(i-1)这个是有序序列
        int j = i - 1;
        for (; j < i; j++)
        {
            //找出比source[i]大的那个元素，那么source[i]应该插入到j这个位置
            if (source[j] > source[i])
            {
                break;
            }
        }

        if (j != i - 1)//判断这个数是不是在有序数列里，不在就不用插了
        {
            int tmp = source[i];
            //将j到i-1个有序元素向后移动一个单位，即整体后移至i位置
            for (int k = i; k > j; k--)
            {
                source[k] = source[k - 1];
            }
            //将source[i]赋值给source[j]，即插入
            source[j] = tmp;
        }
    }
}