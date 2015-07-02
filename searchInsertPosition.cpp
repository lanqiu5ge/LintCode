class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.empty())
            return 0;
        int low = 0;
        int high = A.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] > target)
            {
                high = mid - 1;
                //搜索到数列队头的情况
                if(high < 0)
                    return 0;
                if(A[high] < target)
                    return high+1;
                else if(A[high] == target)
                    return high;

            }
            else
            {
                low = mid + 1;
                if(A[low] >= target)
                    return low;
            }
        }
     }
};

