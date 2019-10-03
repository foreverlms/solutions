#include <iostream>
#include <string>
using namespace std;


int main(void){
    string n ;
    cin >> n;
    if (n.length() == 1)
    {
        cout << n[0] - '0';
        return 0;
    }
    
    int tmp_1 = 1;
    for (int i = 0; i < n.length(); i++)
    {
        tmp_1 *= n[i]-'0';
    }

    int tmp_2 = 1;
    if(n[0] - '1' > 0){
        tmp_2 *= n[0]-'1';
    }

    for (int i = 0; i < n.length()-1; i++)
    {
        tmp_2 *= 9;
    }
    
    if (tmp_1 > tmp_2){
        cout << tmp_1;
    }else{
        cout << tmp_2;
    }
}