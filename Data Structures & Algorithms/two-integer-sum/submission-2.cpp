class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> pr;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            int vl = target-nums[i];
            if(mp.find(vl)!=mp.end())
            {
                pr.push_back(mp[vl]);
                pr.push_back(i);
            }
            else
            mp[nums[i]]=i;
        }

        return pr;
    }
};
