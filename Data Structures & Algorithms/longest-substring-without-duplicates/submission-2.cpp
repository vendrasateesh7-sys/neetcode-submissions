class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
       if(s.empty())
       return 0;

       int left = 0;
       int right = 0;
       int count = INT_MIN;
       int local_count = 0;
       bool seen[256] = {false};

       while(left < s.size() && right < s.size())
       {
         
         if(!seen[s[right]])
         {
           local_count++;
           seen[s[right]]=true;
           right++;

         }
         else
         {
            seen[s[left]]=false;
            local_count--;
            left++;
         }

         
          count = max(count,local_count);
       }

       return count;
    }
};
