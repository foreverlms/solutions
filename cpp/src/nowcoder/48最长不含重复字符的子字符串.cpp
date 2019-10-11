#include <iostream>
#include <string>
#include<cstring>

using namespace std;

//48

//双指针法

int longestNonConsecutiveSubString(string source){
    int cur_len = 0;
    int max_len = 0;

    int* positions = new int[26];
    memset(positions,-1,26*sizeof(int));//memset这样用其实不太好

    for (int i = 0; i < source.length(); i++)
    {
        int prev_index = positions[source[i]-'a'];
        if(prev_index<0 || i-prev_index > cur_len){
            cur_len++;
        }else{
            if(cur_len>max_len){
                max_len = cur_len;
            }

            cur_len = i-prev_index;
        }
        positions[source[i]-'a'] = i;
    }
    
    max_len=max(max_len,cur_len);

    delete[] positions;
    positions=nullptr;
    return max_len;

}