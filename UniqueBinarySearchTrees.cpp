#include<iostream>
#include<vector>
using namespace std;

/**
 * 动态规划
 * BST中有n个节点，若i为根节点，则[1, i-1]构成左子树，[i+1, n]构成右子树
 * f(i)表示以区间[1, i]的数字为节点（i个节点）的BST的数目
 ** /


class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int k = 1; k <= i; k++)
                f[i] += f[k - 1]*f[i - k];
        }
        return f[n];
    }
};

