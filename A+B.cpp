#define _AB
#ifdef _AB

#include<iostream>
using namespace std;
class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
       if(a < b)
       {
           int c = a;
           a = b;
           b = c;
       }

        int move = 0;
        int carry = 0;

        for(move = 0; move < 32; move ++)
        {
            if(checkBitValue(a, move) == 1 && checkBitValue(b, move) == 1)
            {
                if(carry == 0)
                    a &= (~(1 << move));
                carry = 1;
            }
            else if(checkBitValue(a, move) == 1 || checkBitValue(b, move) == 1)
            {
                if(carry == 1)
                {
                    a &= (~(1 << move));
                    carry = 1;
                }
                else
                {
                    a |= (1 << move);
                    carry = 0;
                }
            }
            else
            {
                a |= (carry << move);
                carry = 0;
            }
        }

        return a;
    }

    int checkBitValue(int num, int moveSteps)
    {
        if(num & (1 << moveSteps))
            return 1;
        else
            return 0;
    }
};

int main()
{
    int a,b;
    cin >> a >> b;
    Solution sol;
    cout << sol.aplusb(a, b) << endl;
}

#endif
