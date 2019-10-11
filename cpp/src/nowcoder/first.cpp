#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    vector<int> numbers;
    int zeros=0;

    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin>>tmp;

        if(tmp==0){
            zeros++;
        }else{
            numbers.push_back(tmp);
        }
    }
    cout << numbers.size() << endl;
    int backup = zeros;
    sort(numbers.begin(),numbers.end());
    for (int i = 0; i < n-zeros-1; i++)
    {
        if((numbers[i+1]-numbers[i])!=1){
            zeros-=numbers[i+1]-numbers[i];
        }
    }
    
    if(zeros>=0){
        cout << "YES+" << backup << endl;
    }else{
        cout << "NO+" << backup << endl;
    }
}