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
      return;

      ListNode*  slow = head;
      ListNode* fast = head;

      while(fast->next!=nullptr && fast->next->next!=nullptr)
      {
        slow = slow->next;
        fast = fast->next->next;
      }

      ListNode* second = slow->next;
      slow->next = nullptr;
      ListNode* first = head;
     

        ListNode* prv = nullptr;
        ListNode* curr = nullptr;
        ListNode* temp = second;

        while(temp!=nullptr)
        {
            curr = temp->next;
            temp->next = prv;
            prv = temp;
            temp = curr;
        }

        second = prv;

        while(second!=nullptr)
        {
            ListNode* first_curr = first->next;
            ListNode* second_curr = second->next;

            first->next = second;
            second->next = first_curr;
            first = first_curr;
            second = second_curr;
        }



    }
};
