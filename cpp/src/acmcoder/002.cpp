#include <iostream>
#include <string>

/*
    https://exercise.acmcoder.com/online/online_judge_ques?ques_id=1677&konwledgeId=135
    兰博和提莫闲聊之后，回归到了他们的正题，约德尔人的未来。
    说起约德尔人的未来，黑默丁格曾经提出了一个约德尔测试，将约德尔人的历史的每个阶段都用一个字符表达出来。(包括可写字符,不包括空格。)。然后将这个字符串转化为一个01串。转化规则是如果这个字符如果是字母或者数字，这个字符变为1,其它变为0。然后将这个01串和黑默丁格观测星空得到的01串做比较，得到一个相似率。相似率越高,则约德尔的未来越光明。
    请问:相似率为多少？
    
    每组输入数据为两行，第一行为有关约德尔人历史的字符串，第二行是黑默丁格观测星空得到的字符串。
    (两个字符串的长度相等,字符串长度不小于1且不超过1000。)
 */

int main(void)
{
    int length;
    int count = 0;
    char s;
    std::string line_1, line_2;
    while (std::cin >> line_1 >> line_2)
    {
        length = line_1.length();
        for (int i = 0; i < length; i++)
        {
            s = line_1.at(i);
            if ((s <= '9' && s >= '0') || (s <= 'Z' && s >= 'A') || (s <= 'z' && s >= 'a'))
            {
                s = '1';
            }
            else
            {
                s = '0';
            }
            if (s == line_2.at(i))
            {
                count++;
            }
        }

        double ratio = 100 * (double)count / length;
        printf("%4.2f%%", ratio);
    }
}