class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
     {
        if(position.empty()||speed.empty())
        return 0;

        vector<pair<int,int>>cars;
        stack<double>st;
        int count = 0;

        for(int i=0;i<speed.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());

        for(int i = cars.size()-1;i>=0;i--)
        {
            double n = (target - double(cars[i].first))/cars[i].second;

            if(st.empty())
            {
              count++;
              st.push(n);
            }
            else
             if(n>st.top())
             {
                count++;
                st.push(n);
             }
        }

        return count;
    }
};
