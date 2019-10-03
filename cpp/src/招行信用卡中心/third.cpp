#include <iostream>
#include <vector>

using namespace std;

int recursive(vector<int>& array,int m){
    vector<int> increase_index;
    int count = 0;
    for (int i = 0; i < array.size()-1; i++)
    {
        if (array[i] > array[i+1])
        {
            increase_index.push_back(i+1);
        }
    }

    if(increase_index.size()==0){
        return 0;
    }
    int max = 0;
    int closet= 0;
    for (int j = 0; j < increase_index.size(); j++)
    {
        int tmp = array[increase_index[j]-1] - m;
        if(tmp > max){
            closet = increase_index[j]-1;
        }
    }
    
    count+= array[closet] -m;

    for (int j = 0; j < increase_index.size(); j+=2)
    {
        for (int k = increase_index[j]; k < increase_index[j+1]; k++)
        {
            array[k] %= m;
        }
    }
    
    return count+=recursive(array,m);
}
int main(void){
    int n,m;
    cin >> n >> m;
    vector<int> array;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        array.push_back(tmp);
    }
    
    cout << recursive(array,m) << endl;
}