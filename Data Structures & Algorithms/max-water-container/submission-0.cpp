class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        if(heights.empty())
        return 0;

        int left = 0;
        int right = heights.size()-1;
        int maxland = 0;

        while(left < right)
        {
           int mins = min (heights[left],heights[right]);
           int area = (right - left)*mins;

           maxland = max (maxland,area);

           if(heights[left]<heights[right])
           left++;
           else
           right--;
        }

        return maxland;
        
    }
};
