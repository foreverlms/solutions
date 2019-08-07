#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;
/*
    有许多程序员都热爱玩游戏游戏，而小J自称为游戏王，曾玩过几百种游戏，几乎所有能玩到的游戏大作都玩遍了。
    随着时间的推移，他发觉已经没有游戏可以让他玩了！于是他想改玩一些古老的游戏，以成为真正的“游戏王”。
    他希望在接下来的一段时间内将过去出的游戏全部玩一遍，但是毕竟时间有限，因此他感到很苦恼。于是他给每个
    游戏标上一个成就值，同时估算了完成这些游戏所需要的时间。现在他只有X天时间。而每个游戏一旦开始玩，
    至少需要玩一天才能够停下来。那么，他所玩完的游戏的成就值之和最大能达到多少呢？（每个游戏必须玩完才能取得成就值。）

    第一行输入case数T（0<T<20）。对于每个case，第一行输入游戏的数目N(0<N<11)，总时间X(0<X<1000)用空格分隔。
    从第二行到第N+1行每行输入游戏的成就值Ai(0<Ai<10000)，所需要花费时间Bi(0<Bi<10000)。
 */

/* 
    贪心算法
 */
int main(void)
{
    int num; //case数目
    scanf("%d", &num);

    int game;           //游戏数量
    int max;            //最长时间
    int score = 0;          //最终得分

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &game, &max);
        if (max == 0)
        {
            printf("0\n");
            continue;
        }
        map<double,int> map_of_score;
        int time[game];     //每款游戏完成所需时间
        int point[game]; //每款游戏对应成就值
        for (int j = 0; j < game; j++)
        {
            scanf("%d %d", &point[j], &time[j]);
            map_of_score.insert(make_pair((double)point[j]/time[j],j));
        }
        for(auto p= map_of_score.rbegin();p!=map_of_score.rend();p++){
            int time_ = time[(*p).second];
            if(max >= time_){
                score+=point[(*p).second];
                max-=time_;
            }

            if(max<=0){
                break;
            }
        }

        printf("%d\n",score);

        score = 0;
    }
}