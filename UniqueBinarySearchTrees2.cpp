/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        if(n == 0)  return generate(1, 0);
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int end)
    {
        vector<TreeNode *> subTree;
        if(start > end)
        {
            subTree.push_back(NULL);
            return subTree;
        }

        for(int k = start; k <= end; k++)
        {
            vector<TreeNode *> leftSubs = generate(start, k - 1);
            vector<TreeNode *> rightSubs = generate(k + 1, end);

            for(int i = 0; i < leftSubs.size(); i++)
                for(int j = 0; j < rightSubs.size(); j++)
                {
                    TreeNode *node = new TreeNode(k);
                    node->left = leftSubs[i];
                    node->right = rightSubs[j];
                    subTree.push_back(node);
                }
        }

        return subTree;
    }
};
