class Solution {
public:
    vector<string> mobile(string&dig,int index,vector<string>&ans,string path)
    {
        if(dig.empty())
        return{};

        
        if(index == dig.size())
        {
            ans.push_back(path);
            return ans;
        }
        
        vector<string> phone = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        char d = dig[index];

        for(char ch:phone[d-'2'])
        {
            path.push_back(ch);
            mobile(dig,index+1,ans,path);
            path.pop_back();
        }

        return ans;
    }

    vector<string> letterCombinations(string digits)
     {
        if(digits.empty())
        return {};

        int index = 0;
        vector<string> ans;
        string path;

        return mobile(digits,index,ans,path);
        
    }
};
