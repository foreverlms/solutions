//
// Created by bob on 19-3-15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size();
        if (i != 1){
            while (--i >= 1 ){
                digits[i] += 1;
                if (digits[i] <= 9){
                    break;
                }
                else{
                    digits[i-1] += 1;
                    digits[i] = 0;
                    if (digits[i-1] <= 9)
                        break;
                }
            }
        } else{
            digits[--i] += 1;
        }
        if (digits[0] > 9){
            digits.insert(begin(digits),1);
            digits[1] = 0;
        }
        return digits;
    }
};