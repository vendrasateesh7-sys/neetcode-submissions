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

    int size_tree(TreeNode* root)
    {
      if(!root)
      return 0;
      return 1+max(size_tree(root->left),size_tree(root->right));
    }

    bool isBalanced(TreeNode* root)
     {
      if(!root)
      return true;
      
      int left = size_tree(root->left);
      int right = size_tree(root->right);
      
      if(abs(left-right)>1)
      return false;

      return isBalanced(root->left)&&isBalanced(root->right);
        
    }
};
