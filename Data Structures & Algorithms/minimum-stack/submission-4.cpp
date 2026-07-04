class MinStack {
     vector<int>arr,marr; 
   
public:
    MinStack()
     {
      
    }
    
    void push(int num) 
    {
        if(arr.empty() && marr.empty())
        {
        marr.push_back(num);
        arr.push_back(num);
        return;
        }
        

       if(getMin()>=num)
       {
        marr.push_back(num);
        arr.push_back(num);
        return;
       }
       
       arr.push_back(num);

    }
    
    void pop()
    {
        if(arr.empty())
        return;

        if(marr.back()==arr.back())
        {
           marr.pop_back();
           arr.pop_back();
           return;
        }
        arr.pop_back();

        
    }
    
    int top() 
    {
        if(arr.empty())
        return 0;

        int n = arr.back();

        return n;
    }
    
    int getMin()
     {
        
        int n = marr.back();

        return n;
        
    }
};
