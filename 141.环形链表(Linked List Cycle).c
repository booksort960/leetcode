bool hasCycle(struct ListNode* head)
{
    struct ListNode* fast = head, * slow = head;
    int i = 0;
    while (fast && fast->next)
    {
        if (fast == slow && i)
        {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
        i++;
    }
    return 0;
}
//快慢指针，一旦入环，fast指针最终会追上slow，如果没有环，那么，快指针会走到NULL结速