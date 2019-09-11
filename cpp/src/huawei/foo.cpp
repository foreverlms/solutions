#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/**
 * 纯粹字符串处理，还是刷题太少。
 * 给定字符串，要求删除掉不合法字符，然后'-'连接的单词为一个单词。'--'不表示连接，然后逆序输出所有单词。
 */
bool validate(char &s)
{
    if (s <= 'Z' && s >= 'A' || s <= 'z' && s >= 'a' || s <= '9' && s >= '0' || s == ' ' || s == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main(void)
{
    string source("I am an 20-years  out--standing @ * -stu- dent");
    // string source;
    // cin >> source;

    char c_str[source.length() + 1];
    for (int i = 0; i < source.length(); i++)
    {
        c_str[i] = source[i];
    }
    c_str[source.length()] = '\0';
    vector<string> strs;

    //先把所有非法字符删去
    for (int i = 0; i < source.length(); i++)
    {
        if (!validate(c_str[i]))
        {
            c_str[i] = ' ';
        }
    }


    for (int i = 0; i < source.length(); i++)
    {
        //c_str[i]是-
        if (c_str[i] == '-')
        {
            //未越上界
            if (i + 1 < source.length())
            {
                //紧跟着也是-
                if (c_str[i + 1] == '-')
                {
                    //替换为空格
                    c_str[i] = ' ';
                    c_str[i + 1] = ' ';
                }
                else
                {
                    //未越下界
                    if (i - 1 >= 0)
                    {
                        //如果是非空字符+'-'+非空字符的组合，不做处理，视为一个单词
                        if (c_str[i - 1] != ' ' && c_str[i + 1] != ' ')
                        {
                            //do nothing
                        }
                        else
                        {
                            //是-student-或者-student或者student-这样的情况，替换为空格
                            c_str[i] = ' ';
                        }
                    }
                    else
                    {
                        //第一位是'-'，替换为空格
                        c_str[i] = ' ';
                    }
                }
            }
            else
            {
                //最后一位为'-'，替换为空格
                c_str[i] = ' ';
            }
        }
    }
    
    //逆序输出
    istringstream is(c_str);
    string tmp_str;
    while (is>>tmp_str)
    {
        strs.push_back(tmp_str);
    }
    

    for (int i = strs.size() -1  ; i >0; i--)
    {
       cout <<  strs[i] << " ";
    }

    cout << strs[0] << endl;
    
}