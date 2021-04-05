struct ListNode* middleNode(struct ListNode* head)
{
    int i = 0;
    struct ListNode* p = head;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    int mid = i / 2 + 1;
    struct ListNode* s = head;
    for (int j = 1; j < mid; j++)
    {
        s = s->next;
    }
    return s;

}