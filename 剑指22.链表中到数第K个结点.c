struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    int i = 0;
    struct ListNode* fast = head;
    struct ListNode* last = head;
    while (i < k)
    {
        fast = fast->next;
        i++;
    }
    while (fast && last)
    {
        fast = fast->next;
        last = last->next;
    }
    return last;

}