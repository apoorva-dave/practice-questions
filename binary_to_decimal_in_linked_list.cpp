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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int count =0;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        temp = head;
        int sum = 0;
        while(temp!=NULL)
        {
            sum += (temp->val)*pow(2,count-1);
            count--;
            temp=temp->next;
        }
        return sum;
    }
};