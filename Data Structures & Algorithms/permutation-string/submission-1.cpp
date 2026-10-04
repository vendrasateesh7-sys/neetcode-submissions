class Solution {
public:
    bool checkInclusion(string s1, string s2)
   {  
    if(s1.empty() || s2.empty())
    return false;

    int frq[26] = {};
    int frq1[26]= {};
    
    int right = 0;
    int left = 0;

    for(auto&i:s1)
    frq[i-'a']++;

    while(left < s2.size() && right < s2.size())
    {
        frq1[s2[right]-'a']++;
        bool match = true;
        if((right - left+1) == s1.size())
        {
           for(int i=0;i<26;i++)
           {
           if(frq[i]!=frq1[i])
           {
            match = false;
            break;
           }
          
           }

           if(match)
           return true; 
          else
          {
             frq1[s2[left]-'a']--;
             left++;
             if(right < s2.size())
             right++;
          }
        }
        else
        right++;
        
       
    }

    return false;
        
    }
};
