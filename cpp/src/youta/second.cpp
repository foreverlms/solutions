#include <iostream>
using namespace std;

const int inside = 0;
const int left_ = 1;
const int right_ = 2;
const int top = 8;
const int bottom = 4;

/**
 * 某游戏地图上有n条行军路线，每条用线段表示，已知屏幕中心坐标，宽高，输入n条行军路线（每行四个数，为起点和终点坐标），问n条行军路线有几条会在屏幕里显示出来（贴着边和切着角都算）？
 * 提示：
 *      Cohen–Sutherland线段裁剪算法
 */
inline int calculate(int x, int y, int x_min, int y_min, int x_max, int y_max)
{
    int code;
    code = inside;
    if (x < x_min)
    {
        code |= left_;
    }
    else if (x > x_max)
    {
        code |= right_;
    }

    if (y < y_min)
    {
        code |= bottom;
    }
    else if (y > y_max)
    {
        code |= top;
    }

    return code;
}
int main(void)
{
    int n, center_x, center_y, width, height;
    int line[4];
    while (cin >> n >> center_x >> center_y >> width >> height)
    {
        int x_min = center_x - width / 2;
        int x_max = center_x + width / 2;
        int y_min = center_y - height / 2;
        int y_max = center_y + height / 2;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> line[0] >> line[1] >> line[2] >> line[4];
            int code1, code2;
            code1 = calculate(line[0], line[1], x_min, y_min, x_max, y_max);
            code2 = calculate(line[2], line[3], x_min, y_min, x_max, y_max);
            if (!(code1 & code2 != 0))
            {
                count++;
            }
        }
        cout << count << endl;
    }
}