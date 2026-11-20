class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
     {

        if(heights.empty())
        return -1;

        vector<int>left(heights.size());
        vector<int>right(heights.size());
        vector<int>area(heights.size());
        stack<int> st;

        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty()&& heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            left[i] = -1;
            else
            left[i] = st.top();

            st.push(i);
        }

        while(!st.empty())
        st.pop();

        for(int i = heights.size()-1;i>=0;i--)
        {
          while(!st.empty() && heights[st.top()]>=heights[i])
          st.pop();
         
         if(st.empty())
         right[i] = heights.size();
         else
         right[i] = st.top();

         st.push(i);

        }

        int mx = 0;

        for(int i=0;i<heights.size();i++)
        {
            area[i] = (right[i]-left[i]-1)*heights[i];
            if(mx<area[i])
            mx = area[i];
            
        }

        return mx;

       
     }
};
