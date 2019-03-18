//
// Created by bob on 19-3-18.
//

using namespace std;

class Solution {
public:
    //核心就是牛顿迭代法的运用
    int mySqrt(int x) {
        double tmp = 2.0;
        while ((int)(tmp * tmp - x) != 0){
            tmp = (tmp + x / tmp)/2;
        }

        return (int) tmp;
    }

//    double abs(double x){
//        if(x >= 0)
//            return x;
//        else
//            return -x;
//    }
};