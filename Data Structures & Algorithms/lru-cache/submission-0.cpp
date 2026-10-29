class LRUCache {

    struct Node
    {
        int data;
        int ind;
        Node* prv;
        Node* next;
    };
    unordered_map<int,Node*> mp;
    Node* head = nullptr;
    Node* tail = nullptr;
    int capacity;
   public:  
    LRUCache(int capacity)
    {
      this->capacity = capacity;
      
    }

    Node* create(int num,int ky)
    {
        Node* node = new Node();
        node->data = num;
        node->ind  = ky;
        node->next = nullptr;
        node->prv = nullptr;

        return node;
    }
    
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            int n = mp[key]->data;
            Node* gt = mp[key];

            if(!gt->next)
            return n;

            if(!gt->prv && gt->next)
            {
                head = gt->next;
                head->prv = nullptr;
                tail->next = gt;
                gt->prv = tail;
                tail = gt;
                gt->next = nullptr;

                return n;
            }

            if(gt->prv && gt->next)
            {
                gt->prv->next = gt->next;
                gt->next->prv = gt->prv;
                tail->next = gt;
                gt->prv = tail;
                tail = gt;
                gt->next = nullptr;

                return n;
            }

        }

        return -1;
        
    }
    
    void put(int key, int value) 
    {
        if(capacity<=0)
        return;

        if(mp.find(key)!=mp.end())
        {
          mp[key]->data = value;

          if(!mp[key]->next)
          return;
          
          Node* last = mp[key];

          if(!last->prv && last->next)
          {
            head = last->next;
            head->prv = nullptr;
            tail->next = last;
            last->prv = tail;
            tail = last;
            last->next = nullptr;

            return;
          }

          if(last->prv && last->next)
          {
            last->prv->next = last->next;
            last->next->prv = last->prv;
            tail->next = last;
            last->prv = tail;
            tail = last;
            last->next = nullptr;
          }

          
        }
        else
        {
            Node* node = create(value,key);
            

            if(mp.size()<capacity)
            { 
                mp[key] = node;

                if(!head)
                {
                    head = node;
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    node->prv = tail;
                    tail = node;
                }
            }
            else
            {
                Node* to_delt = head;
                   
                   if(!to_delt->next)
                   {
                    head = node;
                    tail = node;
                    mp.erase(to_delt->ind);
                    mp[key] = node;
                    delete to_delt;
                    return;
                   }  
            
               
                    head = to_delt->next;
                    head->prv = nullptr;
                    tail->next = node;
                    node->prv = tail;
                    tail = node;
                    mp.erase(to_delt->ind);
                    mp[key] = node;
                    delete to_delt;

                }
            }
  }
        
    
};
