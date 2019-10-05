#include <iostream>
#include<vector>

using namespace std;

//双指针法
vector<int> mergeTwoArray(int* ascend, int* descend, int len1, int len2){
    vector<int> res(len1+len2);

    int p1 = 0;
    int p2 = len2-1;
    int index = 0;
    while (p1 < len1 && p2 >=0)
    {
        if(ascend[p1] > descend[p2]){
            res[index++] = descend[p2--];
        }else{
            res[index++] = ascend[p1++];
        }
    }
    
    while (p1<len1)
    {
        res[index++] = ascend[p1++];
    }
    while (p2>=0)
    {
        res[index++] = descend[p2--];
    }
    
    return res;
}