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
 * 归并排序 o(nlogn) 稳定
 * 借助递归
 */
void mergeSortInOrder(int * source,int start, int mid,int end){
    /**
     *归并排序中的合并阶段 
     */
    //tmp的长度是end-start，因为需要归并的两段是start,end
    int* tmp = new int[end-start];
    //index记录插入位置
    int index = start;
    int l_index = start;
    int r_index = mid;

    while (l_index < mid && r_index < end)  
    {
        if (source[l_index] < source[r_index])
        {
            //如果source[l_index] < source[r_index]，将前者填入tmp，并比较l_index的下一个
            tmp[index]= source[l_index];
            l_index++;
        }else{
            tmp[index] = source[r_index];
            r_index++;
        }
        index++;
    }    

    //把剩下没比较完的部分直接插入到tmp中，因为左右肯定有一个没比完
    while (l_index < mid){
        tmp[index++] = source[l_index++];
    }
    while (r_index < end)
    {
        tmp[index++] = source[r_index++];
    }
    
    

    // show(tmp,end-start);
    for (int i = start; i < end; i++)
    {
        source[i] = tmp[i];
    }
    delete[] tmp;
    
}

void mergeSort(int* source,int  start, int end){
    //不包含end
    if(end-start <= 1){
        return;//递归终止条件：当要分治的段只有一个元素时，返回
    }

    int mid = (end-start)/2 + start;
    mergeSort(source,start,mid);
    mergeSort(source,mid,end);
    mergeSortInOrder(source,start,mid,end);
}
