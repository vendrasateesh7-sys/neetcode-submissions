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
    bool isValidBST(TreeNode* root) {
        if(!root)
        return true;  
         
         return treecheck(root);
    }

    bool treecheck(TreeNode* root)
    {
        if(!root)
        return true;
        if(!root->left && !root->right)
        return true;

        if(!root->left &&  root->right)
        {
            if(root->right->val <= root->val)
            return false;
            
        }
        if(!root->left && root->right)
        {
            if(root->right->val > root->val)
            return true;
        }
        if(root->left && !root->right)
        {
            if(root->left->val < root->val)
            return true;
        }

        if(root->left->val >= root->val || root->right->val <= root->val)
        return false;
        


        return treecheck(root->left) && treecheck(root->right);

    }
};
