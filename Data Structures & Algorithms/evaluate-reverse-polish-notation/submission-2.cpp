class Solution {
public:
    int evalRPN(vector<string>& tokens)
     {
       if(tokens.empty())
       return -1;

       vector<int>st(tokens.size());

       for(string s:tokens)
       {
        int ns = 0;
        int ms = 0;

        if(s!="*"  && s!="-" && s!="/" && s!="+")
        {
         int n = stoi(s);
         st.push_back(n);
        }
        else
        if(s=="*")
        {
            ns = st.back();
            st.pop_back();
            ms = st.back();
            st.pop_back();

            st.push_back(ns*ms);
        }
        else
         if(s=="+")
         {
            ns = st.back();
            st.pop_back();
            ms = st.back();
            st.pop_back();

            st.push_back(ns+ms);
         }
         else
         if(s=="-")
         {
            ns = st.back();
            st.pop_back();
            ms = st.back();
            st.pop_back();
            st.push_back(ms-ns);
         }
         else
          if(s=="/")
          {
            ns = st.back();
            st.pop_back();
            ms = st.back();
            st.pop_back();
            st.push_back(ms/ns);
          }

       }

       return st.back();
     
    }
};
