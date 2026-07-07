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
    
    int goodNodes(TreeNode* root) 
    {
        if(!root)
        return 0;  
       
        return maxnodes(root,root->val);

    }

   
   int maxnodes(TreeNode* root,int maxval)
   {
      if(!root)
      return 0;

       
      int res = (root->val >=maxval) ? 1 : 0;
       
       maxval = max(maxval,root->val);

      res =res+ maxnodes(root->left,maxval);
      res =res+ maxnodes(root->right,maxval);

      return res;

   }
    

};
