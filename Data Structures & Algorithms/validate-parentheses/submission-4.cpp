class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty())
        return false;
      
        stack<int>st;
        for(char ch: s)
        {
            if(st.empty())
            st.push(ch);
            if(ch=='(' && st.top()!='('||ch=='{' && st.top()!='{'||ch=='['&& st.top()!='[')
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
