class Solution {
public:
    bool isPalindrome(string s) 
    {
        if(s.empty())
        return false;

        int right = s.size()-1;
        int left = 0;

        while(left < right)
        {
            if(!isalnum(s[left]))
            {
                left++;
                continue;
            }
            if(!isalnum(s[right]))
            {
                right--;
                continue;
            }
            if(isupper(s[left]))
            s[left] = char (s[left]-'A'+'a');

            if(isupper(s[right]))
            s[right] = char (s[right]-'A'+'a');

            if(s[left]!=s[right])
            return false;

            left++;
            right--;
        }

        return true;

    }    
};
