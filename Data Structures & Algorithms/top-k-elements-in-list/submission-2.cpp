class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
     {

        if(nums.empty())
        return {};

        map<int,int> mp;
        vector<int>freq;
        map<int,vector<int>,greater<int>>cp;

        for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;

        for(auto& i:mp)
        cp[i.second].push_back(i.first);

        for(auto &i:cp)
        {
            for(auto& j:i.second)
            {
                if(k>0)
                {
                freq.push_back(j);
                k--;
                }
            }
            if(k==0)
            break;
        }
        
        
        return freq;
    }
    
};
