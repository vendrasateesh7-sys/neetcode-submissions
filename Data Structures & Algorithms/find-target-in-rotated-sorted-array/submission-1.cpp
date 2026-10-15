class Solution {
public:
    int searches(vector<int>&arr,int start,int end,int target)
    {
        if(start>end)
        return -1;

        int mid = start + (end-start)/2;

        if(arr[mid] == target)
        return mid;

        if(arr[mid] > arr[end])
        {
         if(arr[start]<= target && target < arr[mid])   
         return searches(arr,start,mid-1,target);
         else
         return searches(arr,mid+1,end,target);
        }
        else
        { 
         if(arr[mid]<=target && target <= arr[end])     
         return searches(arr,mid+1,end,target);
         else
         return searches(arr,start,mid-1,target);
        }
    }
    int search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size()-1;
        return searches(nums,start,end,target);
        
    }
};
