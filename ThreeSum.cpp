class Solution {
public:
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > result;
        if(nums.empty())
            return result;

        sort(nums.begin(), nums.end());
        vector<int> triplet;
        int size = nums.size();

        vector<int>::const_iterator it = nums.begin();
        int pre = nums[0];
        int next = 1;
        while(*it <= 0 && it != nums.end() - 2)
        {
            if(next != 1 && pre == *it)
            {
                next ++;
				it ++;
                continue;
            }

            vector<vector<int> > ret = findNums(nums, next, nums.size() - 1, - *it);
            result.insert(result.end(), ret.begin(), ret.end());
            next ++;
			it ++;
        }

		if(!result.empty())
			deleteDuplicate(result);

        return result;
    }

    vector<vector<int> > findNums(vector<int>& nums, int low, int high, int target)
    {
        vector<vector<int> > res;
        vector<int> triplet;
        while(low < high)
        {
            if(target == nums[low] + nums[high])
            {
                triplet.push_back(- target);
                triplet.push_back(nums[low]);
                triplet.push_back(nums[high]);
                res.push_back(triplet);
				triplet.clear();
				low ++;
				high --;
            }
            else if(target > nums[low] + nums[high])
            {
                low ++;
            }
            else
            {
                high --;
            }
        }
        return res;
    }

    void deleteDuplicate(vector<vector<int> >& nums)
    {
       vector<vector<int> >::iterator it = nums.begin();
       for(int i = 0; i < nums.size() - 1; i ++)
       {
		   for(int k = i+1; k < nums.size();)
		   {
			   bool dup = true;
			   for(int j = 0; j < 3; j ++)
			   {
				   if(nums[i][j] != nums[k][j])
				   {
					   dup = false;
					   k++;
					   break;
				   }
			   }
			   if(dup)
			   {
				   it = nums.begin() + k;
				   nums.erase(it);
				  /* it = nums.begin() + i;*/
			   }
		   }
       }
    }
};
