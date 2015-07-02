#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty())
            return false;
        int retRow = binarySearchRow(matrix, target);
        if(retRow == -1)
            return true;
        bool ret = binarySearchColumn(matrix[retRow], target);
        return ret;
    }

    int binarySearchRow(vector<vector<int> > &matrix, int target)
    {
        int low = 0;
        int high = matrix.size() - 1;
        //关键考虑清楚什么时候low <= high;什么时候不加等号
        //一般在返回target下标的时候，多半是 不加 等号
        //若只是返回bool值，则一般加等号
        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(matrix[mid][0] == target)
                return -1;
            else if(matrix[mid][0] > target)
                high = mid - 1;
            else
            {
                //这里特殊情况，当high = low + 1时，此时mid == low；即查找到数列的最后时，此种情况应该根据题意判断，return low之前，low的值应该为多少
                if(mid == low)
                    return low;
                low = mid + 1;
            }
        }
       // cout << "low " << low << endl;
        return low;
    }

    bool binarySearchColumn(vector<int> matrix, int target)
    {
        int low = 0;
        int high = matrix.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
          //  cout << "mid " << mid << endl;
            if(matrix[mid] == target)
                return true;
            else if(matrix[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }

};

int main()
{
    vector<  vector<int> > matrix;

    int m,n;
    cin >> m >> n;
    while(m --)
    {
        int k = n;
        vector<int> row;
        while(k --)
        {
            int val;
            cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    int target;
    cin >> target;

    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
    return 0;

}
