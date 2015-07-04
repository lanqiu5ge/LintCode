class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        //细节实现题
        //测试用例设计时需要考虑的地方：
        //1、字符串为空

        //2、字符串不合法
        //2.1 不止一个正负号
        //2.2 除了开头的空格外，数字中间或者最后还有空格或者其他非数字字符
        //2.3 正负号和数字之间有空格或者其他非数字字符
        //2.4 带小数点的字符串中，在小数点后边还有非数字字符

        //3、字符串合法
        //3.1 字符串表示的值溢出
        //3.2 正确的值
        //3.3 带小数点的合法字符串

        if(str.empty())
            return 0;

        const int BASE = 10; //进制基数
        int len = str.size();
        int i = 0;

        int sym = 0;    //正负号
        bool digit = false; //是否出现数字
        bool dot = false;   //判断点是否已经出现过

        int value = 0;

        while(str[i] != '\0')
        {
            if(str[i] == ' ')
            {
                if(digit || sym != 0)
                    return 0;
             //  i ++;
             //   continue;
            }
            else if(str[i] == '-')
            {
                if(sym != 0) //重复出现负号
                    return 0;
                sym = -1;
            }
            else if(str[i] == '+')
            {
                if(sym != 0) //重复出现正号
                    return 0;
                sym = 1;
              //  continue;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                digit = true;

                if(dot == false)
                    value = value * BASE + (str[i] - '0');
                else if(str[i] != '0')
                    return 0;

                //判断是否溢出
                if(value > INT_MAX / 10 && str[i + 1] != '\0' && str[i + 1] != '.')
                {
                    if(sym == -1)
                        return INT_MIN;
                    return INT_MAX;
                }
                else if(value == INT_MAX / 10 && str[i + 1] != '\0' && str[i + 1] != '.' && str[i + 1] > '0')
                {
                    if(sym == -1)
                        return INT_MIN;
                    return INT_MAX;
                }

            }
            else if(str[i] == '.')
            {
                if(str[i + 1] == '\0' || dot)
                    return 0;
                dot = true;
            }
            else
            {
                return 0;
            }

            ++ i;
        }

        if(sym == -1)
            return sym * value;
        else
            return value;
    }
};

