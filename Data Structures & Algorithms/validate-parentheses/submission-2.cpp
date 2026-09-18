class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty())
        return false;
        if(s.size==1)
        return false;
        stack<int>st;
        for(char ch: s)
        {
            if(ch=='('||ch=='{'||ch=='[')
            st.push(ch);
            else
            if(ch==')'&&st.top()=='(' || ch=='}'&&st.top()=='{'||ch==']'&&st.top()=='[')
            st.pop();
        }
        if(st.empty())
        return true;
        else
        return false;
    }
};
