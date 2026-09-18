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

        int count = 0;
        queue <TreeNode*> st;
        st.push(root);
        int max = 0;

        while(!st.empty())
        {
            TreeNode* temp = st.front();
              st.pop();
              
              if(max <= temp->val)
              {
              max = temp->val;
              count++;
              }

              if(temp->left)
              st.push(temp->left);
              if(temp->right)
              st.push(temp->right);

        }
        
        return count;
    }
};
