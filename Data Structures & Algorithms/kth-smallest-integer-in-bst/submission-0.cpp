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
    int kthSmallest(TreeNode* root, int k) 
    {
        if(!root)
        return 0;
        
        int count = 0;

        return smallelem(root,k,count);
    }

    int smallelem(TreeNode* root,int k,int &count)
    {
        if(!root)
        return 0;

        int temp = smallelem(root->left,k,count);

        if(temp)
        return temp;

        count++;

        if(k == count)
        return root->val;
        else
        return smallelem(root->right,k,count);

        return 0;
    }
};
