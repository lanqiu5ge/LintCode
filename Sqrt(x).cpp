#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x < 0)
            return -1;
        if(x == 0)
            return 0;
        if(x == 0x7FFFFFFF)
            return 46340;
        int low = 1;
        int high = x;
        while(low <= high)
        {
            //注意，mid值可能导致mid 的 2 次幂溢出
            int mid = low + (high - low) / 2;
            if(mid > 46340)
                mid = 46340;
            if(x == mid * mid)
                return mid;
            else if(x > mid * mid)
            {
                low = mid + 1;
                if(x <= low * low)
                    return mid;
            }
            else
            {
                high = mid - 1;
                if(x >= high * high)
                    return high;
            }
        }
    }
};

int main()
{
    int x;
    cin >> x;
    Solution sol;
    cout << "The result is:" << sol.sqrt(x) << endl;
    return 0;
}


