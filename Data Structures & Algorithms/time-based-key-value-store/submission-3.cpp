class TimeMap {
public:

unordered_map<string,vector<pair<int,string>>> mp;

    TimeMap() {

     
        
    }
    
    void set(string key, string value, int timestamp) {

        mp[key].push_back({timestamp,value});
        
    }

string subfun(string key,int timestamp,int start,int end,string &ss)
    {
        if(start>end)
        return ss;

    
        vector<pair<int,string>>&acc = mp[key];
        int mid = start+(end-start)/2;

        if(acc[mid].first <=timestamp)
        {
            if(!ss.empty())
            ss.pop_back();

            ss=acc[mid].second;
            return subfun(key,timestamp,mid+1,end,ss);
        }
        else
        return subfun(key,timestamp,start,mid-1,ss);

    }

    
    string get(string key, int timestamp) 
    {
        int start =  0;
        int end = mp[key].size()-1;
        string ss;
        
        return subfun( key,timestamp,start,end,ss);
    }
};
