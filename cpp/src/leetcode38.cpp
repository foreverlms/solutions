//
// Created by bob on 19-3-13.
//

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * 需要优化
     * @param n
     * @return
     */
    string countAndSay(int n) {
        string result("1");
        int i = 1;

        while (i < n){
            ++i;

            int length = result.length();
            string tmp = result;
            result = "";

            int count = 1;

            for (int j = 0; j < length; ++j) {
                if (j+1 > length)
                    continue;
                if (tmp[j] == tmp[j+1]){
                    count++;
                } else{
                    result = result + (char) (count+48) +tmp[j];
                    count = 1;
                }
            }
        }

        return result;
    }
};