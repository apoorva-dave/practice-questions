ListNode* Solution::insertionSortList(ListNode* A) {
    //empty list to insert elements in sorted order
    ListNode *sorted = NULL;
    ListNode *list = A;
    while(list!=NULL)
    {
        //traverse through the list and keep inserting nodes in correct position
        ListNode *curr = list;
        list = list->next;
        if(sorted == NULL  || sorted->val > curr->val)
        {
           curr->next = sorted;
           sorted = curr;
        }
        else
        {
            ListNode *tmp = sorted;
            while(tmp!=NULL)
            {
                ListNode *s = tmp;
                tmp = tmp->next;
                if(s->next==NULL || s->next->val > curr->val)
                {
                    curr->next = s->next;
                    s->next = curr;   
                    break;
                }
            }
        }
        
    }
    return sorted;
}