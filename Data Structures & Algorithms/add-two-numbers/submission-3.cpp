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

    ListNode* creat_nd(int num)
    {
        ListNode* node = new ListNode();
        node->val = num;
        node->next = nullptr;

        return node;
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
        
        ListNode* head1 = nullptr;
        ListNode* tail = nullptr;
        ListNode* temp = l1;
        ListNode* temp1 = l2;

        int sum = 0;
        int carry = 0;
        int dig  = 0;

        while(temp!=nullptr && temp1!=nullptr)
        {
            sum = temp->val+temp1->val+carry;
            ListNode* node = nullptr;
            if(sum>=10)
            {
                carry = sum/10;
                dig = sum%10;
                node = creat_nd(dig);

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

            }  
                else
                {
                    carry = 0;
                    node = creat_nd(sum);
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
                }

            

            temp = temp->next;
            temp1 = temp1->next;
        }

        while(temp!=nullptr)
        {
            sum = temp->val+carry;
            ListNode* node = nullptr;
            if(sum>=10)
            {
                carry = sum/10;
                dig = sum%10;

                node = creat_nd(dig);
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

            }
            else
            {
                carry = 0;
                node = creat_nd(sum);
                if(!head1)
                {
                    head1 = node;
                    tail =node;
                }
                else
                {
                    tail->next = node;
                    tail = node;
                }
            }

            temp = temp->next;

        }

        while(temp1!=nullptr)
        {
            sum = temp1->val+carry;
            ListNode* node = nullptr;
            if(sum>=10)
            {
                carry = sum/10;
                dig = sum%10;
                node = creat_nd(dig);
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
            }
            else
            {
                carry = 0;
                node = creat_nd(sum);
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
            }

            temp1 = temp1->next;
        }
     if(carry)
     {
        ListNode* node = creat_nd(carry);
        tail->next = node;
     }
    return head1;
     
    }
};
