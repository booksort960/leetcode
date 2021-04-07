struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* phead = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        struct ListNode* la = cur->next;
        cur->next = phead;
        phead = cur;
        cur = la;
    }
    return phead;
}