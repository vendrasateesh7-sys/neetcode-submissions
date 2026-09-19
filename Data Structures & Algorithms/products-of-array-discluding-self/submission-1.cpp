class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        if(nums.empty())
        return {};

        vector<int>left;
        vector<int>right;
       

        left.push_back(1);

        for(int i=0;i<nums.size()-1;i++)
        left.push_back(left[i]*nums[i]);


        right.push_back(1);

        for(int j=nums.size()-1,k=0;j>=0;j--)
        {
          right.push_back(right[k]*nums[j]);
          k++;
        }

        int k=left.size()-1;
        for(int i=0;i<left.size();i++)
        {
          nums[i]=(right[k]*left[i]);
         k--;
        }


        return nums;

    }
};
