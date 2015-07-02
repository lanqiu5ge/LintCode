
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.empty())
            return -1;
        int low = 0;
        int high = array.size() - 1;
        int tarIndex = -1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(array[mid] == target)
            {
                 tarIndex = mid;
                 break;
            }
            else if(array[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        if(tarIndex != -1)
        {
            int ret = tarIndex;
            while(tarIndex >= 0)
                if(array[tarIndex] == target)
                {
                    ret = tarIndex;
                    tarIndex --;
                }
                else
                    break;
            return ret;
        }

        return -1;
    }
};

