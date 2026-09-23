class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if(nums.empty())
        return {};
   
        sort(nums.begin(),nums.end());
        vector<vector<int>> triple;

        for(int fix = 0;fix<nums.size()-2;fix++)
        {
            if(fix > 0 && nums[fix]==nums[fix-1])
            continue;

            int left = fix+1;
            int right = nums.size()-1;

            while(left < right)
            {
                int sum = nums[left]+nums[fix]+nums[right];

                if(sum < 0)
                {
                    left++;
                    continue;
                }
                if(sum > 0)
                {
                    right--;
                    continue;
                }
                if(sum == 0)
                {
                    triple.push_back({nums[left],nums[fix],nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left]==nums[left-1])
                    left++;

                    while(left < right && nums[right]==nums[right+1])
                    right--;
                }
            }
            
        }

        return triple;
        
    }
};
