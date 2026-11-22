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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        while(!que.empty()){
            auto[p, q] = que.front();
            que.pop();

            if(p == nullptr && q == nullptr){
                continue;
            }

            if(p == nullptr || q == nullptr){
                return false;
            }

            if(p->val != q->val){
                return false;
            }

            que.push({p->left, q->left});
            que.push({p->right, q->right});
        }
        return true;
    }
};
