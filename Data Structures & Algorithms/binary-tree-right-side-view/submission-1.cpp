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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        vector<vector<int>> ans;
        if(root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i = 0; i < s; i++){
                TreeNode* top = q.front();
                q.pop();
                level.push_back(top->val);
                if(top->left != nullptr){
                    q.push(top->left);
                }
                if(top->right != nullptr){
                    q.push(top->right);
                }
            }
            ans.push_back(level);
        }

        for(vector<int> v: ans){
            result.push_back(v.back());
        }

        return result;
    }
};
