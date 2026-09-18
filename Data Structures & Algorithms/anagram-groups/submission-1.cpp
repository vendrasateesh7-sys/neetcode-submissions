class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
        return{};

       
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ang;

        for(int i=0;i<strs.size();i++)
        {
            vector<int>an(26);
            string ky;
            for(auto j:strs[i])
            {
                int fr;
                if(j>=65 && j<=90)
                fr = int (j)-65;
                else
                fr = int (j)-97;

                an[fr]++;

            }
            for(int j=0;j<an.size();j++)
            ky += to_string(an[j]);

            if(mp.find(ky)!=mp.end())
            mp[ky].push_back(strs[i]);
            else
            mp[ky] = {strs[i]};
        }

        for(auto i:mp)
        ang.push_back(i.second);
        

        return ang;
        
    }
};
