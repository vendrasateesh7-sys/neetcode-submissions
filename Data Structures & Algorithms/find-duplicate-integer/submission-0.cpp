class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        if(nums.empty())
        return -1;

        unordered_set<int>st;

        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end())
            return nums[i];

            else
            {
                st.insert(nums[i]);
            }
        }


    }
};
