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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1 && !list2)
        return nullptr;

        if(!list1)
        {
            list1 = list2;
            return list1;
        }
        if(!list2)
        {
            list2 = list1;
            return list2;
        }
        ListNode* tail = nullptr;
        ListNode* temp = nullptr;
        ListNode* temp1 = nullptr;
        

        if(list1->val <= list2->val)
        {
            tail = list1;
            temp = list1->next;
            temp1 = list2;
        }
        else
        {
            tail = list2;
            temp = list2->next;
            temp1 = list1;
        }

        ListNode* newhead = tail;

        while(temp!=nullptr && temp1!=nullptr)
        {
            if(temp->val > temp1->val)
            {
                tail->next = temp1;
                 tail = temp1;
                temp1 = temp1->next;
               
            }
            else
             {
                tail->next = temp;
                tail = temp;
                temp = temp->next;
             }
        }

        if(temp!=nullptr)
        tail->next = temp;
        if(temp1!=nullptr)
        tail->next = temp1;


        return newhead;
        
    }
};















