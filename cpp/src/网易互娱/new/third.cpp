#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool has_same_color_around(vector<string>& matrix,int x,int y){
    char color = matrix[x][y];
    // if(y+1)
}

int get_height_of_col(vector<string>& matrix,int col){
    int height = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        if(matrix[i][col] != '#'){
            height++;
        }
    }
    
    return height;
}
int main(void){
    int t;
    int m,n;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n;
        vector<string> matrix;

        for (int k = 0; k < m; k++)
        {
            string tmp;
            cin >> tmp;
            matrix.push_back(tmp);
        }


        
    }
    
}