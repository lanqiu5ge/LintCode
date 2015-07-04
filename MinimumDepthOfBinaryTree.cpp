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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if(root == NULL)
            return 0;
        int leftDepth = 0;
        int rightDepth = 0;

        if(root->left == NULL && root->right != NULL)
            leftDepth = 0x7FFFFFFF;
        else
            leftDepth = minDepth(root->left);

        if(root->right == NULL && root->left != NULL)
            rightDepth = 0x7FFFFFFF;
        else
            rightDepth = minDepth(root->right);

        return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
    }
};

