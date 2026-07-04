class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty())
        return false;
      
        stack <char>ss;

        for(char ch : s)
        {
            if(ch == '(' || ch == '[' || ch == '{' )
            ss.push(ch);
            else
            {
                if(ss.empty())
                return false;

                if(ch == ')' && ss.top() == '(' || ch == ']' && ss.top() == '[' || ch == '}' && ss.top() == '{')
                ss.pop();
                else
                return false;
            }
        }

        if(ss.empty())
        return true;
        else
        return false;
    }
};
