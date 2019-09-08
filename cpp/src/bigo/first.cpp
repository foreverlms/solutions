#include <iostream>

using namespace std;
void getMinMaxTime(int length, int ant_cnt, int positions[], int *min, int *max)
{
    int ant_speed = 1; //1 cm/s
    int max_time = 0, min_time = 0;
    int tmp_max;
    int tmp_min;

    for (int i = 0; i < ant_cnt; i++)
    {
        tmp_max = 0;
        tmp_min = 0;

        if (positions[i] < length)
        {
            tmp_max = (length - positions[i]) / ant_speed;
            tmp_min = positions[i] / ant_speed;
        }//左边
        else
        {
            tmp_max = positions[i] / ant_speed;
            tmp_min = (length - positions[i]) / ant_speed;
        }

        if (max_time < tmp_max)
        {
            max_time = tmp_max;
        }

        if (min_time < tmp_min)
        {
            min_time = tmp_min;
        }
    }

    cout << max_time << " " << min_time << endl;
}
int main(void)
{
    //调用
}