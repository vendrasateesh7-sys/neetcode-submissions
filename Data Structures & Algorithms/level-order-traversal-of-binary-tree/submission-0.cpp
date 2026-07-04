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
    vector<vector<int>> levelOrder(TreeNode* root) {

      if(!root)
      return {};

      queue<TreeNode*>st;
      st.push(root);
      vector<vector<int>>ans;

      while(!st.empty())
      {
        int sz = st.size();
        vector<int>arr(sz);

        for(int i=0;i<sz;i++)
        {
          TreeNode* temp = st.front();
          st.pop();

          arr[i]=temp->val;

          if(temp->left)
          st.push(temp->left);

          if(temp->right)
          st.push(temp->right);
        }

        ans.push_back(arr);
      }

      return ans;
        
    }

};
