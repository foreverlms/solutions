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
 * 选择排序 o(n^2) 不稳定
 * 首先初始化最小元素索引值为首元素，依次遍历待排序数列，若遇到小于该最小索引位置处的元素则刷新最小索引为该较小元素的位置，直至遇到尾元素，结束一次遍历，并将最小索引处元素与首元素交换；
 * 然后，初始化最小索引值为第二个待排序数列元素位置，同样的操作，可得到数列第二个元素即为次小元素；以此类推
 */
void selectSort(int *source, int len){
    //初始选择的比较元素下标是0
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        index = i;
        for (int j = i+1; j < len; j++)
        {
            //如果后面的出现比index指向的元素更小，更新index为这个更小的索引，最终得到整个数列的最小元素
            if(source[j] <= source[index]){
                index = j;
            }
        }
        //最小元素与首元素交换
        int tmp = source[index];
        source[index]= source[i];
        source[i]=tmp;
    }
    
}