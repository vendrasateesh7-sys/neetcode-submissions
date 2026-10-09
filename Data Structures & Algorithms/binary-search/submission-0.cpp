class Solution {
public:

    int subsrc(vector<int>& arr,int start,int end,int tr)
    {
        if(arr.empty())
        return -1;

        int mid = start+(end-start)/2;

        if(start > end)
        return -1;
        else
        if(arr[mid]==tr)
        return mid;
        else
        if(arr[mid]<tr)
        return subsrc(arr,mid+1,end,tr);
        else
        if(arr[mid]>tr)
        return subsrc(arr,start,mid-1,tr);
    }

    int search(vector<int>& nums, int target) 
    {
        if(nums.empty())
        return -1;
        
        int start = 0;
        int end = nums.size()-1;

        return subsrc(nums,start,end,target);
    
        
    }
};
