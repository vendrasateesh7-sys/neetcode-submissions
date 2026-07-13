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

       int min = INT_MIN;
       int maxes = INT_MAX;
         return treecheck(root,min,maxes);
    }

    bool treecheck(TreeNode* root,int min,int maxes)
    {
        if(!root)
        return true;

        if(root->val <=min || root->val>=maxes)
        return false;

        return treecheck(root->left,min,root->val) && treecheck(root->right,root->val,maxes);

       



    }
};
