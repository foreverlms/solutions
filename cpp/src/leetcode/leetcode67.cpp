//
// Created by bob on 19-3-17.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 思路：
     * 1、先找出长度较小的字符串，然后以长的字符串为准，将短字符串按位加到长字符串
     * "1001" "111" -> "1112"
     * 2、得到新的长字符串后从尾部开始向前遍历，逢2将当前位置置'0'，前一位置加'1'；逢3将当
     * 前位置置'1',前一位置加'1'；逢1不做改变
     * 3、遍历完之后判断第一位字符是'1'、'2'、'3'，中哪一个，然后相应的参照上面添加进位。
     * 是'1'的话不用添加进位。
     * @param a
     * @param b
     * @return
     */
    string addBinary(string a, string b) {
        if (a.size() >= b.size()) {
            string tmp = a;
            a = b;
            b = tmp;
        }
        int i = 0;
        while (i < a.size() ){
            b[b.size()-i-1] = (char)(a[a.size()-i-1] + b[b.size()-i-1] - '0');
            i++;
        }
        for (int j = b.length()-1; j > 0; --j) {
            if (b[j] == '2'){
                b[j] = '0';
                b[j-1] = b[j-1] + '1' - '0';
            } else if (b[j] == '3'){
                b[j] = '1';
                b[j-1] = b[j-1] + '1' - '0';
            }
        }
        if (b[0] == '2'){
            b[0] = '0';
            b.insert(begin(b),'1');
        } else if (b[0] == '3'){
            b[0] = '1';
            b.insert(begin(b),'1');
        }
        return b;
    }
};