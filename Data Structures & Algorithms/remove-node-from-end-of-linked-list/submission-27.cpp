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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
       if(n<=0)
       return head;

       if(!head)
       return nullptr;

       if(!head->next && n==1)
       {
         ListNode* to_delete = head;
         head = nullptr;
         delete to_delete;
         return head;
       }

       ListNode* slow = head;
       ListNode* fast = head;

       for(int i=0;i<n;i++)
       {
          if(!fast)
          return head;

          fast = fast->next;
       }

       if(!fast)
       {
          ListNode* to_delete = slow;
          head = slow->next;
          delete to_delete;
          return head;
       }

       while(fast->next)
       {
        slow = slow->next;
        fast = fast->next;
       }

       ListNode* to_delete = slow->next;
       slow->next =slow->next->next;
       delete to_delete;


       return head;


    }
};
