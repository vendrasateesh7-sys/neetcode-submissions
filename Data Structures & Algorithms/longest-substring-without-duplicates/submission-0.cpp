class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       if(s.empty())
       return 0;

       int left = 0;
       int right = 0;
       int count = INT_MIN;
       set<char> sub;

       while(left < s.size() && right < s.size())
       {
          if(sub.find(s[right])==sub.end())
          {
            sub.insert({s[right]});
            right++;
          }
          else
          {
            sub.erase(s[left]);
            left++;
          }

          int local_count = sub.size();
          count = max(count,local_count);
       }

       return count;
    }
};
