/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct compare { 
    bool operator()(ListNode* a, ListNode* b) 
    { 
        return a->val > b->val; 
    } 
    }; 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = NULL;
  
        ListNode* last, *top;
        
        priority_queue<int, vector<ListNode*>, compare> pq;
        for(int i=0; i<lists.size();i++)
        {
            if(lists[i])
            {
                ListNode* temp = lists[i];
                pq.push(temp);    
            }
            
        }
        while(!pq.empty())
        {
            top = pq.top();
            pq.pop();
            if(top->next != NULL)
                pq.push(top->next);
            if(head == NULL)
            {
                head = top;
                last = top;
            }
            else
            {
                last->next = top;
                last = top;
            }
        }
        return head;
    }
};