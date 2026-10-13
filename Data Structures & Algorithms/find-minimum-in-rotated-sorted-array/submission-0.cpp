class Solution {
public:
int small(vector<int>&arr,int start,int end)
  {
    if(start==end)
    return arr[start];

    int mid = start+(end-start)/2;

    if(arr[mid]<arr[end])
    return small(arr,start,mid);
    else
    return small(arr,mid+1,end);
  }



    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size()-1;
        return small(nums,start,end);
        
    }
};
