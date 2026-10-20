/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDiameter = 0;
    int depth(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left_height = depth(root->left);
        int right_height = depth(root->right);
        maxDiameter = max(left_height + right_height, maxDiameter);

        return 1 + max(left_height,right_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }
};
