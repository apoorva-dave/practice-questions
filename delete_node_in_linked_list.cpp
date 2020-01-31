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
    void deleteNode(ListNode* node) {
        cout<<node->val;
        // ListNode* temp = node;
        ListNode* tmp = node;
        while(node->next!=NULL)
        {
            node->val = node->next->val;
            tmp = node;
            node=node->next;
        }
        tmp->next=NULL;
    }
};