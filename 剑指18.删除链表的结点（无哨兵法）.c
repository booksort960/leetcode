struct ListNode* deleteNode(struct ListNode* head, int val)
{
    struct ListNode* pre = head;
    struct ListNode* cur = head->next;
    while (cur)
    {
        if (cur->val == val)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    head = head->val == val ? head->next : head;
    return head;
}