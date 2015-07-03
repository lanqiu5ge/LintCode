class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if(m <= 0 || n <= 0)
            return 0;
        if(m == 1 || n == 1)
            return 1;
        vector< vector<int> > grid(m, vector<int>(n, 1));
        for(int i = m - 2; i >= 0; -- i)
            for(int j = n -2; j >= 0; -- j)
            {
                grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
            }

        return grid[0][0];

    }
};
