//
// Created by bob on 19-3-14.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.size();
        if (length == 0)
            return 0;
        int i = length - 1;

        for (;i>=0;i--){
            if (s[i] != ' ')
                break;
        }

        int len = 0;
        //这里优化，不需要判断i == -1
//        if (i == -1)
//            return 0;
//
//        else{
//            while (s[i] != ' ' && i >= 0){
//                len++;
//                i--;
//            }
//
//            return len;
//        }

        while (s[i] != ' ' && i >= 0){
            len++;
            i--;
        }

        return len;
    }
};