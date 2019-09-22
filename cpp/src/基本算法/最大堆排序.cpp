#include <iostream>

using namespace std;
/**
 * 堆排序 时间复杂度 o(nlogn) 空间复杂度： o(1) 不稳定
 */
void show(int *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void swap(int& a,int&b){
    int tmp = b;
    b=a;
    a=tmp;
}

void build_mini_heap(int* source, int len){
    /**
     * 构建原始无序最小堆
     */
    for (int parent = len-1; parent >= 0; parent--)
    {
        //从队尾，也就是最后一个叶子节点开始遍历
        int child = 2*parent+1;//当遍历到非叶子节点，那么其左子节点在数组的索引child为2*parent+1
        while (child < len)//这里保证只有在非叶子节点才进入循环
        {
            if(child+1 < len && source[child+1] > source[child]){//改成source[child+1] < source[child]即最小堆
                child+=1;//将child更新为parent两个子节点中较小的那一个
            }
            if(source[parent] >= source[child]){//改成source[parent] <= source[child]即最小堆
                break;//这种情况当前的parent和其子节点已经满足了最小堆了(最大堆)
            }

            //如果不满足，交换parent和child指向的元素
            swap(source[child],source[parent]);//现在parent指向的是值肯定比其子节点值小了

            //现在要更新child和parent，来保证child的子节点同样满足最小堆
            parent = child;//child变为了父节点
            child = 2 * child+1;//child指向自身的左子节点索引
        } 
    }//遍历完毕，最小堆构建完毕
}

void shift_down(int* source,int index,int len){
    //最小堆下沉
    //需要把index位置的数下沉到合适位置
    if(len == 1){
        return;//当只剩一个元素时，不需要排了
    }
    int less,flag =0;//flag用于标记是否需要继续向下调整
    //存在子结点且可以继续下沉，进入循环
    while (2*index+1 <  len && flag == 0)
    {
        if(source[index] < source[2*index+1]){
            less = 2*index+1;
        }else{
            less=index;
        }//先将index与其左孩子节点比较

        //若有右节点，再与最小值比较
        if(2*index+2 < len){
            if(source[less] <  source[2*index+2]){
                less = 2*index+2;
            }
        }
        if(less != index){
           swap(source[less],source[index]);
           index = less;//less此时指向的正式我们要下沉的元素，现在更新index，继续下一层下降 
        }else{
            //index指向的值就是其子节点相比最小的，不需要在下降
            flag = 1;
        }
    }
    
}

//最小堆排序是降序排列，最大堆排序是升序排序
void max_heap_sort(int* source,int len){
    //第一步，构建最大堆
    build_mini_heap(source,len);

    int tmp = len-1;
    while (tmp >= 0)
    {
        swap(source[0],source[tmp]);
        //每次将堆顶元素与最后元素互换，确保最好一个元素最大，然后堆前tmp个元素来调整堆，使满足最大堆
        shift_down(source,0,tmp);
        tmp--;
    }
    
    show(source,len);
}
int main(void)
{
    int a[6]={4,5,3,2,6,1};
    max_heap_sort(a,6);
}