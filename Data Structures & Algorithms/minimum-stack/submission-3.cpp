class MinStack {
    vector<int>arr,marr;
    int index ;
    int mindex;
public:
    MinStack()
     {
       arr.resize(30000);
       marr.resize(30000);
       index = -1;
       mindex = -1;
    }
    
    void push(int num) 
    {
        if(index == 99)
        return;
       if(index<0 && mindex<0)
       {
        index++;
        mindex++;
        arr[index] = num;
        marr[mindex] = num;
        return;
       } 

       if(getMin()>=num)
       {
        index++;
        mindex++;
        arr[index] = num;
        marr[mindex] = num;
        return;
       }
       index++;
       arr[index] = num;

    }
    
    void pop()
    {
        if(index<0)
        return;

        if(marr[mindex]==arr[index])
        {
            mindex--;
            index--;
            return;
        }
        index--;
        
    }
    
    int top() 
    {
        if(index<0)
        return 0;

        int n = arr[index];

        return n;
    }
    
    int getMin()
     {
        if(index<0)
        return 0;
        int n = marr[mindex];

        return n;
        
    }
};
