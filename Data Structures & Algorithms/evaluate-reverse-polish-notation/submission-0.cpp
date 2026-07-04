class Solution {
public:
    int evalRPN(vector<string>& tokens)
     {
       if(tokens.empty())
       return 0;
      
      stack<int> st;
      int n =0;
      int m = 0;

      for(int i=0;i<tokens.size();i++)
      {
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="%" && tokens[i]!="/")
        {
            int n = stoi(tokens[i]);
            st.push(n);
        }
        else
         if(tokens[i]=="+")
         {
           n = st.top();
           st.pop();
           m = st.top();
           st.pop();
           st.push(m+n);
         }
         else
         if(tokens[i]=="-")
         {
            n = st.top();
            st.pop();
            m = st.top();
            st.pop();
            st.push(m-n);
         }
         else
         if(tokens[i]=="*")
         {
            n = st.top();
            st.pop();
            m = st.top();
            st.pop();
            st.push(m*n);

         }
         else
         if(tokens[i]=="%")
         {
            n = st.top();
            st.pop();
            m = st.top();
            st.pop();
            st.push(m%n);
         }
         else
          if(tokens[i]=="/")
          {
            n = st.top();
            st.pop();
            m = st.top();
            st.pop();
            st.push(m/n);
          }
      }

      return st.top();
     
    }
};
