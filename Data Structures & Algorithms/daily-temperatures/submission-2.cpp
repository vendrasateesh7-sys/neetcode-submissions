class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        if(temperatures.empty())
        return temperatures;

        stack<int> st;
        vector<int> ss(temperatures.size());

        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty() && temperatures[st.top()]<temperatures[i])
            {
                int n = st.top();
                st.pop();
                ss[n] = i-n;
            }

            st.push(i);
        }
        
        return ss;
    }
};
