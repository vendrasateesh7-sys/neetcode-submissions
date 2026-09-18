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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
     {
      
      if(preorder.empty() || inorder.empty())

      return nullptr;
       
     
      int st = 0;
      int end = inorder.size()-1;
      

      
      return returntree(inorder,st,end);
        
    }

    TreeNode* returntree(vector<int>&inorder,int st,int end)
    {
      
       if(st>end)
       return nullptr;

        int mid = st+(end-st)/2;

       TreeNode* newroot = new TreeNode();
       newroot->val = inorder[mid];
       newroot->left = returntree(inorder,st,mid-1);
       newroot->right = returntree(inorder,mid+1,end);

       return newroot;

    }
};
