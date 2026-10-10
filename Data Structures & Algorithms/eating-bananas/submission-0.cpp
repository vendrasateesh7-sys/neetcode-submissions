class Solution {
public:
    int subfunction(vector<int>& arr,int start,int end,int h,int mins)
    {
        if(start>end)
        return mins;

        int total = 0;
        
        int mid = start + (end-start)/2;

        for(int i=0;i<arr.size();i++)
        total+= (arr[i]+mid-1)/mid;

        if(total<=h)
        {
            mins = min(mins,mid);
            return subfunction(arr,start,mid-1,h,mins);
        }
        else
        return subfunction(arr,mid+1,end,h,mins);
    }

    int minEatingSpeed(vector<int>& piles, int h)
    {
        int start = 1;
        int end = INT_MIN;
        int mins = INT_MAX;

        for(int i=0;i<piles.size();i++)
        end =  max(end,piles[i]);

        return subfunction(piles,start,end,h,mins);
        
    }
};
