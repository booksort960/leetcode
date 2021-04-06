struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* des = head;
    struct ListNode* src = head;
    while (src != NULL)
    {
        if (des->val < x)
        {
            des = des->next;
            src = src->next;
        }
        else
        {
            src = src->next;
            if (src != NULL && (src->val) < x)
            {
                int tmp = src->val;
                src->val = des->val;
                des->val = tmp;
                des = des->next;
            }
        }
    }
    return head;
}