class Solution {
public:
    int characterReplacement(string s, int k)
     {
        if(s.empty())
        return 0;

        int left = 0;
        int right = 0;
        int max_frq = INT_MIN;
        int max_val = INT_MIN;
        int frq[26]={};

        while(left < s.size() && right <s.size())
        {
           frq[s[right]-'A']++;

           max_frq = max(max_frq,frq[s[right]-'A']);

           int valid = (right-left+1) - max_frq;

           
           while(valid > k)
           {
             frq[s[left]-'A']--;
             left++;

             valid = (right - left+1) - max_frq;
            
           }

           
            right++;
            max_val = max(max_val,(right-left));
           
        }

        return max_val;
    }
};
