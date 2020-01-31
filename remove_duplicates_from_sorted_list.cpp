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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(temp==NULL)
            return temp;
        ListNode* tmp = temp->next;
        while(tmp != NULL)
        {
            if(temp->val==tmp->val)
            {
                tmp = tmp->next;
            }
            else
            {
                temp->next = tmp;
                tmp = tmp->next;
                temp = temp->next;
            }
        }
        temp->next = tmp;
        return head;
    }
};