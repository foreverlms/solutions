#include <iostream>
#include <algorithm>

using namespace std;

bool invalidInput = false;//标志异常
double pow_bob(int base,unsigned int absExp){
    double res = 1.0;
    for (int i = 0; i < absExp; i++)
    {
        res*=base;
    }
    return res;
}
double power(double base,int exponent){
    invalidInput = false;
    //如果底数等于0，然后指数小于0，非法
    if(base-0.0 <1e-9 && exponent < 0){
        invalidInput = true;
        return 0.0;
    }

    unsigned int absExp = exponent > 0 ? exponent : (unsigned int) -exponent;//有符号->无符号

    double res = pow_bob(base,absExp);
    
    if(exponent < 0){
        res = 1.0 / res;
    }

    return res;
}

