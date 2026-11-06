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
    void reorderList(ListNode* head) 
    {
        if(!head)
        return ;

        ListNode* prv = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            prv = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prv)
        prv->next = nullptr;

        ListNode* temp1 = slow;
        ListNode* temp = head;

                  prv = nullptr;
        ListNode* curr = nullptr;

        while(slow)
        {
            curr = slow->next;
            slow->next = prv;
            prv = slow;
            slow = curr;
        }
        temp1 = prv;

        while(temp && temp1)
        {
            if(!temp->next && temp1->next)
            {
            temp->next = temp1;
            break;
            }
            
            ListNode* pres = temp->next;
            temp->next = temp1;
            ListNode* pres1 = temp1->next;
            temp1->next = pres;
            temp = pres;
            temp1 = pres1;
 
        }

         
      
       

        
    }
};
