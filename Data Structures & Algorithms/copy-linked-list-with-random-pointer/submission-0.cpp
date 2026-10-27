/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* create(int vl)
    {
        
     Node *node = new Node(vl);
     return node;

    }
    
    Node* copyRandomList(Node* head) 
    { 
        if(!head)
        return head;
       unordered_map<Node*,Node*> mp;
        Node* temp      = head;
        Node* tail      = nullptr;
        Node* copy_head = nullptr;

        while(temp)
        {
            Node* node = create(temp->val);
            mp[temp] = node;

            if(!copy_head)
            {
                copy_head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }

            temp = temp->next;
        }

        temp = head;

        while(temp)
        {
            if(temp->random)
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }
    
    return copy_head;
        
    }
};
