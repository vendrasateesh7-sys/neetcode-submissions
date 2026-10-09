class Solution {
public:
    bool subfun(vector<vector<int>>&arr,int start,int end,int tr)
    {
        if(arr.empty()||start > end)
        return false;

        int mid = start +(end - start)/2;
        int row = mid/arr[0].size();
        int colum = mid%arr[0].size();

        if(arr[row][colum]==tr)
        return true;
        else
        if(arr[row][colum]<tr)
        return subfun(arr,mid+1,end,tr);
        else
        return subfun(arr,start,mid-1,tr);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
       int start = 0;
       int end = matrix.size()*matrix[0].size()-1;
       return subfun(matrix,start,end,target); 
    }
};
