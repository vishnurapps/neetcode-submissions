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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    unordered_map<int, int>& inMap, int& preIndex,
                    int left, int right){

                        // This happens when there is no more children.
                        // So we return nullptr
                        if(left > right){
                            return nullptr;
                        }

                        // Using the index, we get the value of root 
                        int rootVal = preorder[preIndex++];

                        // We create the root using the value
                        TreeNode* root = new TreeNode(rootVal);
                        
                        // Find the position of root in inorder 
                        int rootPos = inMap[rootVal];

                        // Build left and right subtree.
                        root->left = build(preorder, inorder, inMap, preIndex, left, rootPos - 1);
                        root->right = build(preorder, inorder, inMap, preIndex, rootPos+1, right);

                        return root;
                    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        // We create a map to track the elements in inorder and their index
        unordered_map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        // Root will be on the 0th element of preorder
        int preIndex = 0;

        return build(preorder, inorder, inMap, preIndex, 0, inorder.size()-1);
    }
};
