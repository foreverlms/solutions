//
// Created by bob on 19-3-11.
//

#include <string>
#include <iostream>
using namespace std;
class Solution{
public:
    int strStr(string haystack,string needle){
        //暴力法穷举啊
        int hsize = haystack.size();
        int nsize = needle.size();
        for (int i = 0; i <= hsize-nsize; ++i) {
            int j = 0;
            for (j; j < nsize; ++j) {
                if (haystack[j+i] != needle[j])
                    break;
            }

            if (j == nsize)
                return i;
        }

        return -1;
    }

};