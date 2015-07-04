class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        // wirte your code here
        if(A.empty() || A.size() == 1 )
            return A;

        //注意：offset大小超过字符串长度时，可以rotate one round
        int moveSteps = offset % A.size();
        if(moveSteps == 0)
            return A;
        int len = A.size();
        A.insert(0, A, A.size() - moveSteps, moveSteps);
        A.erase(len, moveSteps);

        // for(int i = 1; i <= moveSteps; i++)
        // {
        //   A.insert(A.begin(), A[A.size() - 1]);
        //   A.erase(A.size() - 1, 1);
        // }

        return A;
    }
};

