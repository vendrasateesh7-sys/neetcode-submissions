class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
     {
        if(heights.empty())
        return 0;

        vector<int>psm(heights.size());
        vector<int>nsm(heights.size());
        vector<int>area(heights.size());
        int max = 0;
         stack<int> ss;

         for(int i=0;i<heights.size();i++)
         {
            while(!ss.empty() && heights[ss.top()]>=heights[i])
            {
                ss.pop();
            }
            if(ss.empty())
            psm[i]=-1;
            else
            psm[i]=ss.top();

            ss.push(i);
         }

         while(!ss.empty())
         {
            ss.pop();
         }

         for(int i=heights.size()-1;i>=0;i--)
         {
            while(!ss.empty()&&heights[ss.top()]>=heights[i])
            {
                ss.pop();
            }

            if(ss.empty())
            {
                nsm[i] = heights.size();
            }
            else
            nsm[i]=ss.top();

            ss.push(i);
         }

         for(int i=0;i<heights.size();i++)
         {
            area[i] =(nsm[i]-psm[i]-1)*heights[i];

            if(max<area[i])
            max = area[i];
         }
        return max;
     }
};
