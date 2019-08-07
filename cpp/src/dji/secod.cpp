#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int m,n;
    while (cin>>m>>n)
    {
        string a,b,c;
        map<string,string> commands;
        for (int i = 0; i < m; i++)
        {
            cin>>a>>b;
            commands.insert(make_pair(a,b));
        }

        for (int k = 0; k < n; k++)
        {
            cin>>c;
            cout<<commands[c]<<endl;
        }
    }
    
}