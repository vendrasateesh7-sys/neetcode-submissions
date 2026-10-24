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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)
        return list2; 
    
        if(!list2)
        return list1;

        ListNode* tail = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp1 = nullptr;

        if(list1->val <= list2->val)
        {
            tail =  list1;
            temp = list1->next;
            temp1 = list2;
        }
        else
        {
            tail = list2;
            temp1 = list2->next;
            temp = list1;
        }

        ListNode* new_head = tail;

        while(temp!=nullptr && temp1!=nullptr)
        {
            if(temp->val <= temp1->val)
            {
                tail->next = temp;
                tail = temp;
                temp = temp->next;
            }
            else
            {
                tail->next = temp1;
                tail = temp1;
                temp1 = temp1->next;
            }
        }

        if(temp)
        tail->next = temp;

        if(temp1)
        tail->next = temp1;
        

        return new_head;
    }
};
