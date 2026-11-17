class Solution {
public:
    int evalRPN(vector<string>& tokens)
     {
       if(tokens.empty())
       return -1;

       stack<int> st;

       for(string s:tokens)
       {
        int ns = 0;
        int ms = 0;

        if(s!="*"  && s!="-" && s!="/" && s!="+")
        {
         int n = stoi(s);
         st.push(n);
        }
        else
        if(s=="*")
        {
            ns = st.top();
            st.pop();
            ms = st.top();
            st.pop();

            st.push(ns*ms);
        }
        else
         if(s=="+")
         {
            ns = st.top();
            st.pop();
            ms = st.top();
            st.pop();

            st.push(ns+ms);
         }
         else
         if(s=="-")
         {
            ns = st.top();
            st.pop();
            ms = st.top();
            st.pop();
            st.push(ms-ns);
         }
         else
          if(s=="/")
          {
            ns = st.top();
            st.pop();
            ms = st.top();
            st.pop();
            st.push(ms/ns);
          }

       }

       return st.top();
     
    }
};
