#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        if(board.empty())
            return false;

        bool used[9];
        for(int i = 0; i < 9; i++)
        {
            fill(used, used+9, false);
            //检查行
            for(int j = 0; j < 9; j++)
            {
                if(!check(board[i][j], used))
                    return false;
            }

            fill(used, used+9, false);
            //检查列
            for(int j = 0; j < 9; j++)
            {
                if(!check(board[j][i], used))
                    return false;
            }
        }

        //检查小的九宫格
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3)
            {
                fill(used, used+9, false);
                for(int k = 0; k < 3; k++)
                    for(int t = 0; t < 3; t++)
                    {
                        if(!check(board[i + k][j + t], used))
                            return false;
                    }
            }

        return true;
    }

    bool check(char ch, bool used[])
    {
        if(ch == '.')
            return true;
        if(used[ch - '1'])
            return false;
        return used[ch - '1'] = true;
    }
};


