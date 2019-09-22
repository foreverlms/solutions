#include <iostream>

using namespace std;
void show(int *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << " " << endl;
    }

    cout << endl;
}

void quick_sort(int source[], int start, int end)
{
    /**
     * 快速排序 最好结果 o(nlogn) 最坏时间复杂度o(n^2) 平均时间复杂度o(nlogn)
     * 基于分治的思想，是冒泡排序的改进型。首先在数组中选择一个基准点（该基准点的选取可能影响快速排序的效率，后面讲解选取的方法），
     * 然后分别从数组的两端扫描数组，设两个指示标志（low指向起始位置，high指向末尾)，首先从后半部分开始，如果发现有元素比该基准点的值小，
     * 就交换low和high位置的值，然后从前半部分开始扫秒，发现有元素大于基准点的值，就交换low和high位置的值，如此往复循环，直到low>=high,
     * 然后把基准点的值放到high这个位置。一次排序就完成了。以后采用递归的方式分别对前半部分和后半部分排序，当前半部分和后半部分均有序时该数组就自然有序了。
     */

    /**
     * 快速排序稳定性：不稳定
     */
    //递归终止条件
    if (end - start <= 0)
    {
        return;
    }
    int ref = source[start];
    int b = start;
    int e = end; //记录初始的比较位置，用于后面递归

    while (start < end)
    {
        while (start < end && source[end] >= ref)
        {
            end--;
        }
        source[start] = source[end]; //先由右向左遍历，一旦出现比ref小的，将小的那个元素赋值到左指针指向的元素

        while (start < end && source[start] <= ref)
        {
            start++;
        }

        source[end] = source[start];
    }

    //start已经和end相等了
    source[start] = ref;

    quick_sort(source, b, start - 1);
    quick_sort(source, start + 1, e);
}
