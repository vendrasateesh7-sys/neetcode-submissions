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
int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root)
        return d++;

        int leftdai = diameterOfBinaryTree(root->left);
        int rightdai = diameterOfBinaryTree(root->right);
         
         
         d = max(leftdai,rightdai);
         return d;
    }
};


















