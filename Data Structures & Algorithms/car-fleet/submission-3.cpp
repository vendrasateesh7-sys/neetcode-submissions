class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
     {
        if(position.empty()||speed.empty()||target<=0)
        return -1;

        int count = 0;
        stack<double>fleet;
        vector<pair<int,int>>cars;

        for(int i=0;i<position.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        for(int i = cars.size()-1; i>=0;i--)
        {
          double n = (target- double(cars[i].first))/(cars[i].second);

          if(fleet.empty())
          {
            count++;
            fleet.push(n);
          }
          else
          if(n>fleet.top())
          {
            count++;
            fleet.push(n);
          }
        }
       
       return count;

    }
};
