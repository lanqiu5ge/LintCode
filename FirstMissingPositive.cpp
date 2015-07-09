class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        if(A.empty())
            return 1;
        int n = A.size();
        for(int i = 0; i < n; i ++)
        {
            while(A[i] <= n && A[i] > 0 && A[A[i]-1] != A[i])
                swap(A[i], A[A[i] - 1]);
        }

        for(int i = 0; i < n; i++)
        {
            if(A[i] != i + 1)
                return i + 1;
        }

        return n+1;
    }
};

