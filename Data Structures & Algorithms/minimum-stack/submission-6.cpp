class MinStack {
    
    
public:
stack<int>ss;
stack<int>st;
   
    MinStack() {

       
        
    }
    
    void push(int val)
    {
        if(ss.empty()&&st.empty())
        {
            ss.push(val);
            st.push(val);
        }
        else
        {
            if(ss.empty()||ss.top()>=val)
            ss.push(val);
            
        }
        st.push(val);
        
      
    }
    
    void pop()
    {
        if(ss.top()==st.top())
        ss.pop();
        
    
       st.pop();
          
    }
    
    int top() 
    {

     return st.top();     
        
    }
    
    int getMin() 
    {
     
     return ss.top(); 

    }
};
