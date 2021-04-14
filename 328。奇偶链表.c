struct ListNode* oddEvenList(struct ListNode* head)
{
    int num = 0;
    struct ListNode* oddhead = (struct ListNode*)malloc(sizeof(struct ListNode)), * oddtail = oddhead;
    struct ListNode* evenhead = (struct ListNode*)malloc(sizeof(struct ListNode)), * eventail = evenhead;
    struct ListNode* cur = head;
    while (cur)
    {
        ++num;
        if (num % 2 == 0)
        {
            eventail->next = cur;
            eventail = eventail->next;
        }
        else
        {
            oddtail->next = cur;
            oddtail = oddtail->next;
        }
        cur = cur->next;
    }
    eventail->next = NULL;
    oddtail->next = evenhead->next;
    struct ListNode* p = oddhead->next;
    free(oddhead);
    free(evenhead);
    return p;
}