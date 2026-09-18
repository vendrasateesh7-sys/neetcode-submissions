class Solution {
public:

    string encode(vector<string>& strs)
     {
      if(strs.empty())
      return {};

      string ky;

      for(int i=0;i<strs.size();i++)
      {
        int len = strs[i].size();
        ky+=to_string(len)+"#";
        ky+=strs[i];
      }
      return ky;

    }

    vector<string> decode(string s) 
    {
        if(s.empty())
        return {};

        vector<string> dcnm;

        for(int i=0;i<s.size();i++)
        {
            int ind =  0;
            int p = 0;

            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='#')
                {
                    p = j+1;
                    break;
                }
                ind = ind*10+s[j]-'0';
            }
            string nm(ind,' ');

            for(int k=0;k<ind;k++)
            {
                nm[k]=s[p];
                p++;
            }
            dcnm.push_back(nm);
            i = p-1;
        }

        return dcnm;

    }



};
