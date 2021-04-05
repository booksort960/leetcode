struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    int i = 0;
    struct ListNode* p = head;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    int num = i - k;
    struct ListNode* s = head;
    for (int j = 0; j < num; j++)
    {
        s = s->next;
    }
    return s;

}