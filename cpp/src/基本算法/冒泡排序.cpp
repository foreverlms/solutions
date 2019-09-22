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

/**
 * 依次比较相邻两元素，若前一元素大于后一元素则交换之，直至最后一个元素即为最大；
 * 然后重新从首元素开始重复同样的操作，直至倒数第二个元素即为次大元素；依次类推。
 * 如同水中的气泡，依次将最大或最小元素气泡浮出水面。
 */
/**
 * 时间复杂度:o(n^2) 稳定
 */
void bubble(int* source,int length){
    /*升序排列，大的数慢慢浮到尾部*/
    for (int i = length-1; i >= 0; i--)
    {
        for (int j = 0;  j <= i -1; j++)
        {
            if(source[j] > source[j+1]){
                int tmp = source[j+1];
                source[j+1] = source[j];
                source[j] = tmp;
            }
        }
        
    }
    
}