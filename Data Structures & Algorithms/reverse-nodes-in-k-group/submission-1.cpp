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

        ListNode duplicate;
        ListNode* dummy = &duplicate;
        dummy->next = head;

        while(n>=k)
        {
            ListNode* new_head = temp;
            ListNode* current_node = nullptr;
            ListNode* privous_node = nullptr;

            for(int i=0;i<k;i++)
            {
                current_node = temp->next;
                temp->next = privous_node;
                privous_node = temp;
                temp = current_node;
            }
            dummy->next = privous_node;
            new_head->next = temp;
            dummy = new_head;

            n-=k;
        }

        return duplicate.next;

    }    
       
};
