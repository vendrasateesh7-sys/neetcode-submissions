class Solution {

public:

    double subfuns(vector<int>&arr,vector<int>&arr1,int start,int end,int total,double vl)
    {
    
        if(start>end)
        return vl;

        int half = total/2;

        int mid = start+(end - start)/2;

        int j = half - mid;

        int left1 =  0;
        int right1 = 0;
        int left2 =  0;
        int right2 = 0;

        if(mid == 0)
        left1 = INT_MIN;
        else
        left1 = arr[mid-1];

        if(mid==arr.size())
        right1 = INT_MAX;
        else
        right1 = arr[mid];

        if(j == 0)
        left2 = INT_MIN;
        else
        left2 = arr1[j-1];

        if(j == arr1.size())
        right2 = INT_MAX;
        else
        right2 = arr1[j];

        if(left1<=right2 && left2 <=right1)
        {
            if(total%2!=0)
            vl = min(right1,right2);
            else
            vl = (max(left1,left2)+min(right1,right2))/2.0;

            return vl;
        }

        if(left1>right2)
       return subfuns(arr,arr1,start,mid-1,total,vl);

        if(left2>right1)
       return subfuns(arr,arr1,mid+1,end,total,vl);

  }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
     {
        
        int start = 0;
        int end = nums1.size();
        int total = nums1.size()+nums2.size();
        double value = 0.0;

       return subfuns(nums1,nums2,start,end,total,value);

        
    }



};
