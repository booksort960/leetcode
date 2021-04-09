struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

