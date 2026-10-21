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
    void inOrder(TreeNode* root, vector<int> &vec){
        if(root == nullptr){
            return;
        }
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        //Create a vector to store elements
        vector<int> flat;

        //Store elements in in order way
        inOrder(root, flat);

        // for(int i: flat){
        //     cout << i << " ,";
        // }

        // Index starts at 0, so we can return
        // k-1th element
        for(int i = 0; i < k; i++){
            if(i == k - 1)
            return flat[i];
        }
    }
};
