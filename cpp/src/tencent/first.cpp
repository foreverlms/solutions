#include<iostream>

using namespace std;
/**
 *  栏杆问题 滑动窗口
 */

int main(void){
    int n,k;
    while (cin>>n>>k)
    {
        int* length_ = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>length_[i];
        }

        int sum=0;
        int index_ = 1;
        for(int i=0;i<k;i++){
            sum+=length_[i];
        }
        

        int current_sum = sum;
        for (int i = k; i < n; i++)
        {
            current_sum+=length_[i]-length_[i-k];
            if(current_sum < sum){
                index_ = i-k+2;
                sum = current_sum;
            }
        }

        delete[] length_;
        cout << index_ << endl;
        
    }
    
}