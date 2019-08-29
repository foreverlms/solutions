#include <iostream>
#include <cstring>

using namespace std;

//  https://www.cnblogs.com/heart-flying/p/9556401.html
// A 字节对齐 a x x x b b b b c c x x x x x x e e e e e e e e = 24 24是8的背书，无需进行结构体对齐
struct A
{
    char a;
    int b;
    short c;
    double e;
};

//B 字节对齐 a x b b c c c c e e e e y y | 1+1+2+4+4=12
//x是字节对齐补充字节，y是结构体对齐补充字节
//先在结构体内对齐，再对整个结构体对齐
// 结构体内，有效对齐值是指定对齐值和自身对齐值的较小值；结构体自身对齐值是其所含数据成员自身对齐值最大的那个
//结构体内，偏移量必须是有效对齐值的整数倍
struct B
{
    char a;
    short b;
    int c;
    float e;
};

//union所占空间大小是其最大数据成员所占的字节数，并且要适当扩充为其他成员的整数倍
union C {
    char flag[3];
    short value;
} un;
//un 中最长成员占3字节，3不是short 2字节的整数倍，因此扩充为4个字节


//p 8字节
struct p
{
    int x;
    int y;
};

int main(void)
{
    // 24 12 4
    // cout << sizeof(struct A) << " " << sizeof(struct B) << " " << sizeof(un);

    struct p p1[] = {1,92,3,94,5,96};
    //p1是数组类型，总共占据24个字节
    //输出 24
    cout << sizeof(p1) <<endl;
    //sizeof ptr = 8 ptr是指针，指针64位占据8字节 p1是数组
    struct p* ptr = p1;
    //x = 24
    int x = (sizeof(p1) / 5);

    if(x==3)
        cout << p1->x << " " << (p1+x-1)->x;
    else
        cout << "false";
    
    int array[2019] = {0};
    array[19]=2019;
    //3130
    //(unsigned long) ((short *) array + 2019) = init+2019*2;
    // (unsigned long) (array+*(unsigned char *)(array+19)) = init+227*2;
    // offset = 2019*2 - 227 *2 = 3130
    unsigned long offset = (unsigned long) ((short *) array + 2019) - (unsigned long) (array+*(unsigned char *)(array+19));
    cout << offset << endl;
}