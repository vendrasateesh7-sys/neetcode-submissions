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
    
   long long int value (ListNode*& head)
    {
        if(!head)
        return 0;

       long long int sum = 0;
        
        ListNode* temp = head;

        while(temp!=nullptr)
        {
            sum = sum*10+temp->val;
            temp = temp->next;
        }
        long long int rvsum = 0;

        while(sum>0)
        {
            int r = sum%10;
            rvsum = rvsum*10+r;

            sum = sum/10;
        }

        return rvsum;
    }
   
   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if(!l1 && !l2)
        return l1;

        if(l1->val == 0 && l2->val == 0)
        {
            ListNode* head1 = l1;
            return head1;
        }
        
       long long int sum1 = value(l1);
       long long int sum2 = value(l2);
       long long int total = sum1+sum2;
        ListNode* tail = nullptr;
        ListNode* head1 = nullptr;

        while(total>0)
        {
            int r = total%10;

            ListNode* node = new ListNode();
            node->val = r;

            if(!head1)
            {
                head1 = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }

            total = total/10;

        }

     return head1;
        
    }
};
