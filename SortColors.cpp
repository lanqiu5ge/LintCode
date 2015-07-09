class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        // write your code here
        //计数排序
        if(nums.empty())
            return;
        int array[3] = {0};
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                array[0] ++;
            else if(nums[i] == 1)
                array[1] ++;
            else
                array[2] ++;
        }

        for(int i = 0; i < n; i ++)
        {
            if(i < array[0])
                nums[i] = 0;
            else if(i - array[0] < array[1])
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }
};

