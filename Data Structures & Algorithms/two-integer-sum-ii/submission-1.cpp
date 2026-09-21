class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        if(numbers.empty())
        return {};

        int left = 0;
        int right = numbers.size()-1;
        vector<int> tsum;

        while(left < right)
        {
            int total = numbers[left]+numbers[right];

            if(total > target)
            {
                right--;
                continue;
            }
            else
            if(total < target)
            {
                left++;
                continue;
            }
            else
            {
                tsum.push_back(left+1);
                tsum.push_back(right+1);
                break;
            }
        }

        return tsum;
    }
};
