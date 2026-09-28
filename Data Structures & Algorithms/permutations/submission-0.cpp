class Solution {
public:
   void combo(vector<int>&nums,vector<vector<int>>&ans,int index)
   {
    if(nums.empty())
    return;

    if(index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int i=index;i<nums.size();i++)
    {
        swap(nums[index],nums[i]);
        combo(nums,ans,index+1);
        swap(nums[index],nums[i]);
    }

   }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        int index = 0;

        combo(nums,ans,index);

        return ans;
        
    }
};
