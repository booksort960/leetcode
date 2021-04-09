bool isPalindrome(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode* pt = slow->next, * pre = slow;
    while (pt)
    {
        struct ListNode* tmp = pt->next;
        pt->next = pre;
        pre = pt;
        pt = tmp;
    }
    while (pre > head)
    {
        if (head->val != pre->val)
        {
            return 0;
        }
        head = head->next;
        pre = pre->next;
    }
    return 1;
}