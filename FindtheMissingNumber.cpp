class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        if(nums.empty())
            return -1;
        int N = nums.size();
        int result = 0;
       //位操作--“异或”，idea来自查找数组中不重复的那个数字
       for(int i = 0; i < N; i++ )
       {
           result ^= (nums[i] ^ i);
       }

       result ^= N;
       return result;
    }
};

