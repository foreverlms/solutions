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

void insertSort(int* source,int gap,int len){
    for (int i = gap; i < len; i+=gap)
    {
        int j = i-gap;
        for (; j < i ; j+=gap)
        {
            if (source[j] > source[i])
            {

                break;
            }
            
        }
        int tmp = source[i];
        for (int k = i; k > j; k-=gap)
        {
            source[k] = source[k-gap];
        }
        source[j] = tmp;
    }

        
}
/**
 * 希尔排序 空间复杂度 o(1) 时间复杂度 o(n^1.3~n^1.5) 不稳定
 * 插入排序的改进版。为了减少数据的移动次数，在初始序列较大时取较大的步长，通常取序列长度的一半，
 * 此时只有两个元素比较，交换一次；之后步长依次减半直至步长为1，即为插入排序，由于此时序列已接近有序，故插入元素时数据移动的次数会相对较少，效率得到了提高。
 */
void shellSort(int* source,int len){
    for (int gap = len/2; gap >0; gap/=2)
    {
        insertSort(source,gap,len);
    }
    
}