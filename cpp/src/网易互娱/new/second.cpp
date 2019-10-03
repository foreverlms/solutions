#include <iostream>
#include <map>
#include <algorithm>
#include <string>


using namespace std;

int ans = INT32_MAX;

void swap(char& a,char& b){
    char tmp = a;
    a = b;
    b = tmp;
}

int cal(char* source,int len,const char* foo,int input){
    int tmp = 0;
    map<char,int> index_map;
        for (int i = 0; i < len; i++)
        {
            index_map.insert(make_pair(source[i],i+1));
        }
    int last = index_map[source[0]];
    for (int i = 0; i < input; i++)
    {
        tmp+=abs(index_map[foo[i]]-last);
        last  = index_map[foo[i]];
    }

    return tmp;
}

void permutation(char *source, int start,int len,const char* foo, int input){
    if (start == len-1)
    {
        //如果start== len-1，说明已经只剩一个元素，没法在置换了，是一个排列
        ans = min(cal(source,len,foo,input),ans);
        return;
    }

    //start位置的元素要和他后面的每个元素置换一次，递归
    for (int i = start; i < len; i++)
    {
        swap(source[start],source[i]);
        permutation(source,start+1,len,foo,input);
        //复原
        swap(source[start],source[i]);
    }  
}


int main(void){
    char keyboard[6] = {'A','S','D','F','G','H'};
    int t;
    string bar;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = INT32_MAX;
        cin >> bar;
        permutation(keyboard,0,6,bar.c_str(),bar.length());
        cout << ans << endl;
    }
    
}