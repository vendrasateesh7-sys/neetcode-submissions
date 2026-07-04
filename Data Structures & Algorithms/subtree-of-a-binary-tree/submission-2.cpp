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
    
    bool istree(TreeNode* root ,TreeNode* root1)
    {
      if(!root && !root1)
      return true;
      if(root && !root1 || !root && root1)
      return false;

      if(root->val!=root1->val)
      return false;
      
      return istree(root->left,root1->left) && istree(root->right,root1->right);
    }
    

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

      if(!root && !subRoot)
      return true;
      if(!root && subRoot || root && !subRoot)
      return false;
     
     if(istree(root,subRoot))
     return true;
     if(istree(root->left,subRoot) || istree(root->right,subRoot))
     return true;

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
     
     
        
    }
};
