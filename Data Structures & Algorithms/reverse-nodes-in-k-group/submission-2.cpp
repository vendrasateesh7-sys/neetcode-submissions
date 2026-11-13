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
        if(!head || k<=0)
        return head;

        ListNode* temp = head;
        int n = 0;

        while(temp)
        {
            n++;

            temp = temp->next;
        }

        temp = head;
        ListNode dummy;
        ListNode* duplicate = &dummy;
        duplicate->next = head;

        while(n>=k)
        {
            ListNode* current = nullptr;
            ListNode* previous = nullptr;
            ListNode* new_head = temp;

            for(int i=0;i<k;i++)
            {
                current = temp->next;
                temp->next = previous;
                previous = temp;
                temp = current;
            }
            duplicate->next = previous;
            new_head->next = temp;
            duplicate = new_head;

            n-=k;
        }

        return dummy.next;


    }

        
       
};
