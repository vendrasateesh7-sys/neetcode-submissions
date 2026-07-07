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

       int res = 0;

       return maxval(root,root->val,res);

    }

   int maxval(TreeNode* root,int maxvalue,int res)
   {
    if(!root)
    return 0;
    
    if(root->val >= maxvalue)
    res = 1;
    else
    res = 0;

    maxvalue = max(maxvalue,root->val);

    res = res + maxval(root->left,maxvalue,res);
    res = res + maxval(root->right,maxvalue,res);

    return res;

   }
    

};
