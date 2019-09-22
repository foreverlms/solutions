#include <iostream>

using namespace std;

/**
 * 二分法查找肯定是针对有序数列的
 */
int binarySearch(int a[], int len, int target)
{
    //a从小到大有序排列
    int left = 0, right = len, mid;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

/**
 * 查找有序数列的目标数字左边界
 * 1 3 3 5 7 7 7 7 8 14 14
 * target = 7
 * 返回第一个7的下标，左边界4
 */

int binarySearchLeftBound(int a[], int len, int target)
{
    int left = 0, right = len, mid;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;

        if (a[mid] <= target)
        {
            right = mid -1;
        }else{
            left = mid+1;
        }
    }

    if(a[left] == target){
        return left;
    }
    return -1;
}