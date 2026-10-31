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
    struct Match
    {
        bool operator()(ListNode* a,ListNode* b)
        {
         return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if(lists.empty())
        return nullptr;

        if(lists.size()==1)
        return lists[0];

        priority_queue<ListNode*,vector<ListNode*>,Match>pq;
        
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            pq.push(lists[i]);
        }

        while(!pq.empty())
        {
            ListNode* node = pq.top();
            pq.pop();

            if(node->next)
            {
                ListNode* next_node = node->next;
                pq.push(next_node);
            }
            if(!head)
            {
                head = node;
                tail = node;
                tail->next = nullptr;
            }
            else
            {
                tail->next = node;
                tail = node;
                tail->next = nullptr;
            }
        }

        return head;
        
        
    }
};
