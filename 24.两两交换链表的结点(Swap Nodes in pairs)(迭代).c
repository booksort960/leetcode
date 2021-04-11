struct ListNode* swapPairs(struct ListNode* head)
{
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = head;
    struct ListNode* cur = phead, * pre = phead;
    struct ListNode* pnext;
    while (cur->next && cur->next->next)
    {
        cur = cur->next;
        pnext = cur->next;
        struct ListNode* next = cur->next->next;
        cur->next->next = cur;
        cur->next = next;
        pre->next = pnext;
        pre = pre->next->next;
    }
    return phead->next;
}