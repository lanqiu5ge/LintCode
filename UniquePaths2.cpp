#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        if(obstacleGrid.empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;

        for(int i = n-1; i >= 0; -- i)
        {
            if( obstacleGrid[m-1][i] == 1)
            {
                for(; i >=0; --i)
                     obstacleGrid[m-1][i] = 0;
                break;
            }
            else
                 obstacleGrid[m-1][i] = 1;
        }

        //注意右下角的gridnode不应该被修改两次 i应该从m-2开始
        for(int i = m-2; i >= 0; -- i)
        {
            if( obstacleGrid[i][n-1] == 1)
            {
                for(; i >=0; --i)
                     obstacleGrid[i][n-1] = 0;
                break;
            }
            else
                 obstacleGrid[i][n-1] = 1;
        }


        for(int i = m - 2; i >= 0; -- i)
            for(int j = n -2; j >= 0; -- j)
            {
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i][j + 1] + obstacleGrid[i + 1][j];
            }

        return obstacleGrid[0][0];
    }
};

int main()
{
    vector< vector<int> > grid;
    int m,n;
    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        vector<int> vec;
        for(int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            vec.push_back(val);
        }
        grid.push_back(vec);
    }

    Solution sol;
    cout<<  sol.uniquePathsWithObstacles(grid) << endl;
    return 0;
}
