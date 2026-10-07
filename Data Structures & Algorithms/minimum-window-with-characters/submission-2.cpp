class Solution {
public:
    string minWindow(string s, string t)
     {
        if(t.empty()||s.size()<t.size())
        return "";

        int frq1[128] = {};
        int frq[128] = {};
        
        int start = 0;
        int next = 0;

        int minimum = INT_MAX;
        int new_start = 0;

        string sub;

        for(auto& i:t)
        frq[i]++;

        while( next < s.size())
        {
              frq1[s[next]]++;
              bool valid = true;

              for(int i=0;i<128;i++)
              {
                if(frq1[i]<frq[i])
                {
                  valid = false;
                  break;
                }
              }

             while(valid)
             {
                int local_lenght = next - start + 1;

                if(local_lenght < minimum)
                {
                    minimum = local_lenght;
                    new_start = start;
                    sub.clear();
                }


                 frq1[s[start]]--;
                    start++;

                    for(int i=0;i<128;i++)
                    {
                        if(frq1[i]<frq[i])
                        {
                            valid = false;
                            break;
                        }
                    }


             }

             if(!valid)
             next++;

        }

        if(minimum!=INT_MAX)
        {
            int i = new_start;

            while(i<=new_start + minimum - 1)
            {
                sub.push_back(s[i]);
                i++;
            }
        }

        return sub;
        
    }
};
