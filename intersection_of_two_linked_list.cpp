#include<bits/stdc++.h>
using namespace std;
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
ListNode *findNode(ListNode *temp1, ListNode *temp2, int diff)
{
    int n = 0;
    while(n!=diff)
    {
        temp2=temp2->next;
        n++;
    }
    while(temp1 != NULL && temp2 != NULL && temp1 != temp2)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
    ListNode *temp1 = headA;
    ListNode *temp2 = headB;
    int count1 =0, count2= 0;
    while(temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    while(temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }
    // cout<<count1<<" "<<count2;
    int diff = abs(count2-count1);
    // cout<<diff;
    temp1 = headA;
    temp2 = headB;
    ListNode* res;
    
    if(count2>count1)
        res = findNode(temp1,temp2,diff);
    else
        res = findNode(temp2,temp1,diff);
    return res;
    }
};