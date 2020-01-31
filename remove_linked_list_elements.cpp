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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        if(temp==NULL)
            return temp;
        while(temp!=NULL && temp->val == val)
        {
            head = temp->next;
            temp=temp->next;    
        }
        
        while(temp!=NULL)
        {
            if(temp->next !=NULL && temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};