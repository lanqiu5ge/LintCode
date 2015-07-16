
class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        vector<int> twoNums;
        if(A.empty())
            return twoNums;
        int res = 0;
        int len = A.size();
        for(int i = 0; i < len; i++)
        {
            res ^= A[i];
        }
        cout << "res: " << res << endl;
        int k = 0;
        while(res !=0 && (res & (1 << k)) != 1)
            k++;

        int shift = 1 << k;
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < len; i++)
        {
            if((A[i] & shift) == 0)
            {
                num1 ^= A[i];
            }
            else
                num2 ^= A[i];
        }

        cout << num1 << num2 << endl;
        twoNums.push_back(num1);
        twoNums.push_back(num2);

        return twoNums;
    }
};

