#include<iostream>
#include<Eigen/Core>
#include<sophus/so3.h>
#include<sophus/se3.h>

using namespace std;
using namespace Sophus;

int main(void){
    Eigen::Matrix3d r_0 = Eigen::AngleAxisd(M_PI/3,Eigen::Vector3d(0,0,1)).toRotationMatrix();
    Eigen::Matrix3d r_1 = Eigen::AngleAxisd(M_PI/4,Eigen::Vector3d(1,0,0)).toRotationMatrix();

    Eigen::Vector3d a(9,22,0);

    cout << r_1.inverse()*a << endl;
}