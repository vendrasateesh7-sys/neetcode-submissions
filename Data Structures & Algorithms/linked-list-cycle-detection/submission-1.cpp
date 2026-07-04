/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head)
    {
       if(!head)
       return false;

       ListNode* temp = head;
       unordered_set<ListNode*>set;

       while(temp!=nullptr)
       {

           if(set.find(temp)!=set.end())
           return true;
           else
           {
              set.insert(temp);
              temp = temp->next;
           }
       }

       return false;     
    }
};
