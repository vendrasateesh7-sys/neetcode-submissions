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
        if(!head || n<0)
        return nullptr;

        ListNode* slow =  head;
        ListNode* fast = head;
        ListNode* delete_node = nullptr;
        ListNode* prev = nullptr;

        for(int i=0;i<n;i++)
        {
            if(!fast)
            return slow;

            fast = fast->next;
        }
        
        if(!fast)
        {
           delete_node = slow;
           head = slow->next;
           slow->next = head;
           delete delete_node;
           return head;
        }

        while(fast!=nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        delete_node = slow;
        prev->next = delete_node->next;
        delete slow;

        return head;
        
        
        
    }
};
