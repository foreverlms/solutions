// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);
//
// Created by bob on 19/08/07.
//
class Solution
{
public:
    int guessNumber(int n)
    {
        int max = n;
        int min = 1;

        int average = (max + min) / 2;
        while (guess(average) != 0)
        {
            if (guess(average) > 0)
            {
                min = average+1;
            }
            else
            {
                max = average;
            }
            // average = (max + min) / 2;
            average = min + (max-min)/2;//这里有技巧啊。。这样写肯定不会溢出
        }

        return average;
    }
};