#include <iostream>
#include <string>

using namespace std;

bool scanUnsignedInteger(const char** str){
    const char * pre = *str;
    while (**str!='\0' && **str >= '0' && **str<='9')
    {
        (*str)++;
    }

    return *str > pre;//当str最终指向的位置在pre之后时，说明它遍历的都是0-9
}
bool scanInteger(const char** str){
    //扫描整数部分
    //这里要修改指针的值，所以传入了指针的指针
    if(**str == '+' || **str=='-'){
        (*str)++;
    }

    return scanUnsignedInteger(str);
}
bool isNumber(const char* str){
    if(!str){
        return false;
    }

    bool num_true = scanInteger(&str);
    //此时str指向的是第一个非0-9字符，开始判断
    if(*str=='.'){
        ++str;
        num_true = scanUnsignedInteger(&str)|| num_true;
    }
    
    if(*str == 'e' || *str == 'E'){
        ++str;
        num_true =scanInteger(&str) && num_true;
    }

    //判断是否为数字，需要能够str遍历完而且num_true为真
    return num_true && *str == '\0';
}
int main(void){
    string a = "+100";
    cout << isNumber(a.c_str()) << endl;
}