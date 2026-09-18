class Solution {
public:

    bool scramb(string s1,string s2,unordered_map<string,int>&dp)
    {
        int len = s1.size();
        int len1 = s2.size();
        string key = s1+s2;

        if(len!=len1)
        return dp[key]=false;
        if(dp.find(key)!=dp.end())
        return dp[key] = false;
        if(s1 == s2)
        return dp[key] = true;

        for(int i=1;i<len;i++)
        {
            string s1_left = s1.substr(0,i);
            string s1_right =  s1.substr(i,len-i);

            string s2_left = s2.substr(0,i);
            string s2_right = s2.substr(i,len-i);

            string s2_newleft = s2.substr(0,len-i);
            string s2_newright = s2.substr(len-i,i);

            if(scramb(s1_left,s2_left,dp) && scramb(s1_right,s2_right,dp))
            return dp[key] = true;

            if(scramb(s1_left,s2_newright,dp) && scramb(s1_right,s2_newleft,dp))
            return dp[key] = true;
        }

        return dp[key];
    }


    bool isAnagram(string s, string t)
     {

        unordered_map<string,int>dp;

        if(scramb(s,t,dp))
        return true;
        else
        return false;
        
    }
};
