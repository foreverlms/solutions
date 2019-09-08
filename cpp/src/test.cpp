// #include<iostream>
// #include<Eigen/Core>
// #include<sophus/so3.h>
// #include<sophus/se3.h>

// using namespace std;
// using namespace Sophus;

// int main(void){
//     Eigen::Matrix3d r_0 = Eigen::AngleAxisd(M_PI/3,Eigen::Vector3d(0,0,1)).toRotationMatrix();
//     Eigen::Matrix3d r_1 = Eigen::AngleAxisd(M_PI/4,Eigen::Vector3d(1,0,0)).toRotationMatrix();

//     Eigen::Vector3d a(9,22,0);

//     cout << r_1.inverse()*a << endl;
// }
// #include <iostream>
// #include <hash_set>

// using namespace std;

// int main(void){
//     int n,m,k;
//     while (cin>>n>>m>>k)
//     {
//         int value[n*m];

//     }

// }

//拼多多第四题
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int main(void)
// {
//     int n, m, k, tmp;
//     cin >> n >> m >> k;
//     int numbers = n * m;
//     vector<int> r;
//     for (int i = n; i > 0; i--)
//     {
//         for (int j = m; j > 0; j--)
//         {
//             tmp = n * m;
//             r.push_back(tmp);
//         }
//     }
//     sort(r.begin(), r.end());
//     cout << r.at(n * m - k + 1) << endl;
//     return 0;
// }

//拼多多第三题

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double expectation(int n, int x[])
{
    if (n == 1)
    {
        double tmp = 0.0;
        for (int i = 1; i <= x[0]; i++)
        {
            tmp = tmp + i;
        }

        tmp = tmp / x[0];

        return tmp;
    }
    else
    {
        int possible = 1;
        for (int i = 0; i < n - 1; i++)
        {
            possible *= x[i];
        }
        double tmp = expectation(n - 1, x);
        double p = 0.0;
        for (int i = 1; i <= x[n - 1]; i++)
        {
            if (tmp > i)
            {
                p += tmp * possible;
            }
            else
            {
                p += i * possible;
            }
        }
        return p / (possible * x[n - 1]);
    }
}

// class Friend
// {
// private:
//     int age;
//     string name;

// public:
//     Friend();
//     Friend(const Friend &another);
//     Friend &operator=(const Friend &another)
//     {
//         this->age = another.age;
//         this->name = another.name;
//     }
//     Friend(int age_, string name_)
//     {
//         this->name = name_;
//         this->age = age_;
//     }
//     static int compare_with_age(const Friend &a, const Friend &b);
//     static int compare_with_name(const Friend &a, const Friend &b);

//     friend ostream &operator<<(ostream &out, const Friend &friend_)
//     {
//         out << "name: " << friend_.name << " "
//             << "age: " << friend_.age;
//         return out;
//     }
// };

// Friend::Friend()
// {
//     this->age = 20;
//     this->name = "foo";
// }

// Friend::Friend(const Friend &another)
// {
//     this->age = another.age;
//     this->name = another.name;
// }

// int Friend::compare_with_age(const Friend &a, const Friend &b)
// {
//     if (a.age < b.age)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int Friend::compare_with_name(const Friend &a, const Friend &b)
// {
//     if (a.name.length() < b.name.length())
//     {

//         return 1;
//     }
//     else if (a.name.length() > b.name.length())
//     {
//         return 0;
//     }
//     else
//     {
//         for (int i = 0; i < a.name.length(); i++)
//         {
//             if (a.name[i] < b.name[i])
//             {
//                 return 1;
//             }
//         }
//         return 0;
//     }
// }
// int main(void)
// {
//     // int n;
//     // while (cin>>n)
//     // {
//     //     int x[n];
//     //     for (int i = 0; i < n; i++)
//     //     {
//     //         cin >> x[i];
//     //     }

//     //     cout << expectation(n,x);
//     // }
//     vector<Friend> friends;
//     friends.push_back(Friend(10, "A"));
//     friends.push_back(Friend(30, "B"));
//     friends.push_back(Friend(20, "C"));

//     // sort(begin(friends),end(friends),Friend::compare_with_age);
//     sort(begin(friends), end(friends), Friend::compare_with_name);

//     for (int i = 0; i < 3; i++)
//     {
//         cout << friends[i] << endl;
//     }
// }

void replaceSpace(char *str, int length)
{
    if (str == nullptr || length <= 0)
    {
        return;
    }

    int counter = 0;
    int real_length = 0;
    char *tmp = str;
    while (*tmp != '\0')
    {
        real_length++;
        if (*tmp == ' ')
        {
            counter++;
        }
        tmp++;
    }

    if (str + real_length + counter * 2 > str + length)
    {
        return;
    }
    char *new_str = str + real_length + counter * 2 - 1;
    char *old_str = str + real_length - 1;
    *(new_str + 1) = '\0';

    while (old_str - str >= 0 && new_str - old_str > 0)
    {
        if (*old_str == ' ')
        {
            *new_str = '0';
            new_str--;
            *new_str = '2';
            new_str--;
            *new_str = '%';
            new_str--;
        }
        else
        {
            *new_str = *old_str;
            new_str--;
        }

        old_str--;
    }
}

int main(void)
{
    // char str[30] = "abc def gh";

    // replaceSpace(str, 30);
    // cout << str << endl;
}