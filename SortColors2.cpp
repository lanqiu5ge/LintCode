class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        if(colors.empty())
            return ;

        int size = colors.size();
        for(int i = 0; i < size; )
        {
			int cur = colors[i];
            if(cur > 0)
            {
                if(colors[cur - 1] > 0)
                {
                    colors[i] = colors[cur - 1];
                    colors[cur - 1] = -1;
                }
                else if(colors[cur - 1] < 0)
                {
                    colors[i] = 0;
                    colors[cur - 1] --;
                    i ++;
                }
                else
				{
					colors[i] = 0;
					colors[cur - 1] --;
                    i ++;
                }
            }
            else
			{
                i ++;
            }
        }

		for(int i = k-1; i >= 0; i --)
		{
			int num = -(colors[i]);
			for(int j = 0; j < num; j ++)
			{
				colors[size - 1 - j] = i + 1;
				//cout << colors[size - 1 - j] << endl;
			}
			size -= num;
		}
    }
};

