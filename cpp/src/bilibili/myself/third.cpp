#include <iostream>
#include <vector>

using namespace std;
int main(void){
    int tmp;
    vector<int> list;
    
    while (cin>>tmp)
    {
        list.push_back(tmp);
        if(cin.get()=='#'){
            break;
        }
    }
    
    cout << "Here" <<endl;
    int k;
    cin>>k;

    // for (int i = 0; i < list.size(); i++)
    // {
    //     cout << list[i] << endl;
    // }
    
    cout << k << endl;
}