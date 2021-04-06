struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* pre;
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre = phead;
    while (l1 && l2)
    {
        if (l1->val > l2->val)
        {
            //if(pre&&pre->next)
            pre->next = l2;
            // if(l2!=NULL)
            l2 = l2->next;
            pre = pre->next;
        }
        else
        {
            //if(pre&&pre->next)
            pre->next = l1;
            // if(l1!=NULL)
            l1 = l1->next;
            pre = pre->next;
        }
    }
    pre->next = l1 == NULL ? l2 : l1;
    return phead->next;
}