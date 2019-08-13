//
// Created by bob on 19-2-28.
//

#include "../include/header.h"

string Solution::longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
        return "";
    string common_prefix(strs[0]);
    for (int i = 1; i < strs.size(); ++i) {
        unsigned long size = strs[i].length() < common_prefix.length() ? strs[i].length() : common_prefix.length();
        unsigned long index = 0;
        for (; index < size; ++index) {
            if (strs[i][index] != common_prefix[index])
                break;
        }

        if (index == 0){
            common_prefix = "";
            break;
        } else{
            common_prefix = common_prefix.assign(common_prefix,0,index);
        }
    }

    return common_prefix;
}