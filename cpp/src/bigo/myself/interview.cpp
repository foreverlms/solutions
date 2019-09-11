#include <iostream>
#include <random>//第二题

using namespace std;

/**
 * 第一题：
 * 一个箱子里有m个红球，n个白球，A和B依次轮流不放回的抽取这些球，A先取。规定谁先拿到红球谁赢，求问A赢的概率是？
 * 感觉是个数列？
 * 
 */

/**
 * 第二题：
 * 给定单位球体，圆心位于(0,0,0)，编写程序输出球面上的一个随机均匀采样的点
 */

struct Point{
    double x;
    double y;
    double z;
};

struct Point getRandom(){
    default_random_engine engine;
    uniform_real_distribution<double> d(-1,1);

    //球面坐标系，r=1
    double theta = d(engine)*M_PI*2;
    double phi = d(engine)*M_PI*2;

    double x = 1*cos(theta);
    double y = 1*sin(theta)*sin(phi);
    double z = 1*sin(theta)*(-cos(phi));

    return {x,y,z};
    //球面坐标系r,theta,phi
}

int main(void){
    Point a = getRandom();
    cout << a.x << " " << a.y << " " << a.z << " " <<endl;
}

