class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.empty())
        return 0;

        int left = 0;
        int right = height.size()-1;

        int leftmx = height[left];
        int rightmx = height[right];
        int totalwater = 0;

        while(left < right)
        {
            if(leftmx < rightmx)
            {
                left++;
              leftmx = max(leftmx,height[left]);
             int left_water = leftmx-height[left];
              totalwater = totalwater + left_water;
              
            }
            else
            {
                right--;
                rightmx = max(rightmx,height[right]);
                int right_water = rightmx - height[right];
                totalwater = totalwater+right_water;
                
            }
        }

        return totalwater;
        
    }
};
