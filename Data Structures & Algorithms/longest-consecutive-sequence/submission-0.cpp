class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty())
        return 0;

        int count = 0;
        int maxes = 0;
        unordered_set<int>st;

        for(int i=0;i<nums.size();i++)
        st.insert(nums[i]);

        for(int j=0;j<nums.size();j++)
        {
            int prv = nums[j]-1;
            if(st.find(prv)==st.end())
            {
                count = 1;
                int current = nums[j];
                while(st.find(current+1)!=st.end())
                {
                    count++;
                    current++;
                }

                maxes = max(count,maxes);
            }
            
        }

        return maxes;
        
    }
};
