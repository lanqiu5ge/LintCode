#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        if(nums.empty())
            return 0;

        sort(nums.begin(), nums.end());
        int closest = INT_MAX;

        int num1 = nums[0];
        int num2 = nums[0];
        for(int i = 0; i < nums.size() - 2; i ++)
        {
            findClosest(nums, i + 1, nums.size() - 1, target - nums[i], num1, num2);
            int ret = nums[i] + num1 + num2;
            if(ret == target)
                return target;
            closest = closest > ret ? ret : closest;
        }

        return closest;
    }

    void findClosest(vector<int> &nums, int low, int high, int target, int& num1, int& num2)
    {
        int min = INT_MAX;
        while(low < high)
        {
            if(nums[low] + nums[high] == target)
            {
               num1 = nums[low];
               num2 = nums[high];
               return ;
            }
            else
            {
                if(nums[low] + nums[high] > target)
                {
                    high --;
                    int gap = nums[low] + nums[high] - target;
                    if(min > gap)
                    {
                        num1 = nums[low];
                        num2 = nums[high];
                    }
                }
                else
                {
                    low ++;
                    int gap = target - nums[low] + nums[high];
                    if(min > gap)
                    {
                        num1 = nums[low];
                        num2 = nums[high];
                    }
                }
            }
        }

        return ;
    }
};


int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    while( n --)
    {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int target;
    cin >> target;
    Solution sol;
    cout << sol.threeSumClosest(nums, target) << endl;
    return 0;
}
