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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != nullptr){
            if((root->val > p->val) && (root->val > q->val)){
                //Both are on left side
                root = root->left;
                cout << root->val << endl;
            } else if ((root->val < p->val) && (root->val < q->val)){
                //Both are on right side;
                root = root->right;
            } else {
                //They split here or p/q is root
                return root;
            }
        }
        return nullptr;
    }
};
