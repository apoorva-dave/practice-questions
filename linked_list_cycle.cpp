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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        if(slow== NULL)
            return false;
        ListNode *fast = head->next;
        while(fast !=NULL && fast->next!=NULL)
        {
            fast = fast->next;
            if(slow!=fast && fast->next !=NULL )
            {
                slow = slow->next;
                fast = fast->next;
            }
            else
                break;
            
        }
        if(slow==fast)
            return true;
        else
            return false;
    }
};