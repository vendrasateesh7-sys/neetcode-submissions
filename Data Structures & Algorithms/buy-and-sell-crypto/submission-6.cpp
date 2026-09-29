class Solution {
public:
    int maxProfit(vector<int>& prices)
   {
    if(prices.empty()||prices.size()==0)
    return 0;

    int sum = INT_MIN;
    int minm = INT_MAX;
   
   for(int i=0;i<prices.size();i++)
   {
    int sm = 0;
     minm = min(minm,prices[i]);

       sm = prices[i]-minm;

       sum = max(sum,sm);
      
   }
   if(sum==INT_MIN || sum < 0)
    return sum = 0;

    return sum;
        
    }
};
