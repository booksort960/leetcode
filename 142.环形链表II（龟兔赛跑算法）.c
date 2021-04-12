struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return NULL;


}