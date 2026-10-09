class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(nums.empty())
        return {};

        vector<int> mx;
        int start = 0;
        int next = 0;
        deque<pair<int,int>> dq;

        while(next < nums.size())
        {
            while(!dq.empty()&& nums[next]>dq.back().first)
            dq.pop_back();

            dq.push_back({nums[next],next});

            if(!dq.empty() && dq.front().second < next - k+1)
            {
                dq.pop_front();
            }
            
            if(next - start+1 < k)
            next++;
            else
            if(next - start+1 == k)
            {
                mx.push_back(dq.front().first);
                start++;
                next++;
            }
        }

        return mx;
        
    }
};
