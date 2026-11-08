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
     
     ListNode* create(int n)
     {
        ListNode* node = new ListNode();
        node->val = n;
        node->next = nullptr;
        
        return node;
     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(!l1 && !l2)
        return l1;

        ListNode* temp = l1;
        ListNode* temp1 =  l2;
        int sum = 0;
        int dig = 0;
        int carry = 0;

        ListNode* new_head = nullptr;
        ListNode* tail = nullptr;

        while(temp && temp1)
        {
            sum = temp->val + temp1->val + carry;

            ListNode* node = nullptr;

            if(sum>=10)
            {
                dig = sum%10;
                carry = sum/10;
                node = create(dig);

                if(!new_head)
                {
                    new_head = node;
                    tail = node;
                }
                else
                 {
                    tail->next = node;
                    tail = node;
                 }
                 
            }
            else
            {
                carry = 0;

                node = create(sum);

                if(!new_head)
                {
                    new_head = node;
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }

            temp = temp->next;
            temp1 = temp1->next;
        }


        while(temp)
        {
            sum = temp->val + carry;
            ListNode* node = nullptr;

            if(sum>=10)
            {
                dig = sum%10;
                carry = sum/10;
                node = create(dig);
               if(!new_head)
               {
                 new_head = node;
                 tail = node;
               }
               else
               {
                tail->next = node;
                tail = node;
               }
            }
            else
            {
                carry = 0;

                node = create(sum);

                if(!new_head)
                {
                    new_head = node;
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }

            temp = temp->next;
        }


        while(temp1)
        {
            sum = temp1->val + carry;
            ListNode* node = nullptr;

            if(sum>=10)
            {
                dig = sum%10;
                carry = sum/10;

                node = create(dig);

                if(!new_head)
                {
                    new_head = node;
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }
            else
            {
                carry = 0;
                node = create(sum);

                if(!new_head)
                {
                    new_head = node;
                    tail = node;

                }
                else
                {
                    tail->next = node;
                    tail = node;
                }

            }
            temp1 = temp1->next;
            
        }

        if(carry)
        {
            ListNode* node = create(carry);
            tail->next = node;
            tail = node;
        }

        return new_head;
        
    }
};
