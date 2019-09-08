#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>

#define AA (365)*(24)*(3600)

using namespace std;

int judgeVarOrNum(string a){
    // int length = a.length();
    // for (int i = 0; i < length; i++)
    // {
    //     if((a[i] < 'Z' && a[i] >= 'A') || (a[i] <= 'z' && a[i] >= 'a')){
    //         //是变量
    //         return -1;
    //     }
    // }
    if(a.empty()){
        return -2;
    }
    if ((a[0] < 'Z' && a[0] >= 'A') || (a[0] <= 'z' && a[0] >= 'a'))
    {
        return -1;
    }else if ( a[0] <= '9' &&  a[0] >= '0' ){
        return atoi(a.c_str());
    }else{
        return -2;
    }
    
}

void get(vector<string>& queue,string line){
    string tmp;
    int length = line.length();
    char char_tmp;

    for (int  i = 0; i < length; i++)
    {
        if (line[i] != ' ')
        {
            if (line[i] != '=' || line[i] != '+')
            {
                
            }
            
        }
        
    }
    
}
int main(void){
    int n;
    cin >> n;
    map<string,int> table;
    vector<string> queue;
    string tmp_str;
    int value = 0;
    int res;
    string tmp;
    char ope;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        while ((ope = cin.get())!='\n')
        {
            
            if(ope == '='){
                cout << "Here" <<endl;
                tmp_str = tmp;
            }else if (ope == '+'){
                int s = judgeVarOrNum(tmp);
                if(s){
                    value += s;
                }else if(s == -1){
                    if(table.find(tmp) != table.end()){
                        value += table[tmp];
                    }else{
                        cout << "NA" << endl;
                        exit(0);
                    }
                }
                char z;
                while ( (z = cin.get() ==' '))
                {
                }
                cin >> tmp;
                tmp = z + tmp;

                s = judgeVarOrNum(tmp);
                if (s)
                {
                    value += s;
                }
                else if (s == -1)
                {
                    if (table.find(tmp) != table.end())
                    {
                        value += table[tmp];
                    }
                    else
                    {
                        cout << "NA" << endl;
                        exit(0);
                    }
                }
                continue;
            }

            cin >> tmp;
        }
        
        table.insert(make_pair(tmp_str,value));
        cout << "value: " << value << endl;
        if (i == n-1)
        {
            res = table[tmp_str];
        }

        value = 0;
    }
    
    cout << res << endl;
}