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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || k<0)
        return head;

        ListNode* temp = head;
        int n =0;

        while(temp!=nullptr)
        {
            n++;
            temp = temp->next;
        }
        
        ListNode duplicate;
        duplicate.next = head;
        ListNode* dummyhead = &duplicate;
        
        temp = head;

        while(n>=k)
        {
            ListNode* newhead = temp;
            ListNode* prev = nullptr;
            ListNode* curr = nullptr;

            for(int i=0;i<k;i++)
            {
              curr = temp->next;
              temp->next = prev;
              prev = temp;
              temp = curr;
            }

            dummyhead->next = prev;
            newhead->next = temp;
            dummyhead = newhead;

            n-=k;
        }

        return duplicate.next;
    }
};
