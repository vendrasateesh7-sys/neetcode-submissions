class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
     {

        if(nums.empty())
        return {};

        map<int,int,greater<int>> mp;
        vector<int>freq;

        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        for(auto& i:mp)
        {
            if(i.second>1 && k>=1)
            {
             freq.push_back(i.first);
             k--;
            }
        }
        
        return freq;
    }
    
};
