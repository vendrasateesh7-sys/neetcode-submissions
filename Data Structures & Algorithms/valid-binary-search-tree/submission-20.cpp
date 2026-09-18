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
        
        if(root->left && !root->right && root->left->val > root->val || !root->left && root->right && root->right->val < root->val)
        return false;

        if(root->left &&  root->val <=root->left->val || root->right && root->val >= root->right->val)
        return false;
        else
        return true;
       
       return treecheck(root->left);
       return treecheck(root->right);

       return true;



    }
};
