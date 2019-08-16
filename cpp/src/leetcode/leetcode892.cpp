#include <vector>
using namespace std;

inline int diff(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    if (a - b > 0)
    {
        return a - b;
    }
    else
    {
        return 0;
    }
}

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int area = 0;
        int left = 0, right = 0, up = 0, down = 0;
        int left_a = 0, right_a = 0, up_a = 0, down_a = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                area += 2;

                if (j - 1 >= 0)
                {
                    left = grid[i][j - 1];
                }

                if (j + 1 < grid[i].size())
                {
                    right = grid[i][j + 1];
                }

                if (i - 1 >= 0)
                {
                    up = grid[i - 1][j];
                }

                if (i + 1 < grid.size())
                {
                    down = grid[i + 1][j];
                }

                int center = grid[i][j];

                left_a = diff(center, left);
                right_a = diff(center, right);
                down_a = diff(center, down);
                up_a = diff(center, up);

                area += (left_a + right_a + up_a + down_a);

                left = 0;
                right = 0;
                up = 0;
                down = 0;
            }
        }

        return area;
    }
};