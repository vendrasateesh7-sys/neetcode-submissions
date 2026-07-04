class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
     {
        if(temperatures.empty())
        return temperatures;
        
        vector<int> out(temperatures.size());
        stack<int>st;

        for(int i = temperatures.size()-1;i>=0;i--)
        {
            while(!st.empty()&&temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }

            if(st.empty())
            out[i] = 0;
            else
            out[i] = st.top()-i;

            st.push(i);
        }

        return out;
    }
};
