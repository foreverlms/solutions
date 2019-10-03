#include <iostream>
#include <vector>

using namespace std;

void get(int a,vector<int>& record){
    int tmp;
    while (a)
    {
        tmp=a%10;
        record[tmp]++;
        a/=10;
    }
    
}

int main(){
    int N,a,b;
    vector<int> reocrd_all_result(10,0);
    cin>>N;
    while (N--)
    {
        vector<int> record(10,0);
        cin>>a>>b;
        get(a,record);
        get(b,record);
        int intermediate = b;
        while(b){
            int foo = b % 10;
            int s = foo*a;
            if(s){
                get(s,record);
            }
            b/=10;
        }

        get(a*intermediate,record);
        for (int i = 1; i < 10; i++)
        {
            reocrd_all_result[i]+=record[i];
            cout << record[i];
            if(i<9){
                cout << " ";
            }
        }

        cout << endl;
        
    }
    
    int index = 1;
    for (int i = 1; i < 10; i++)
    {
        if(reocrd_all_result[i] > reocrd_all_result[index]){
            index=i;
        }
    }
    cout << index;
    return 0;
    
}