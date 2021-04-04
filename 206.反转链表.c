//ÒÀ´Îµü´ú
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* pre = NULL, * cur = head;
//    struct ListNode* last;
//    while (cur != NULL)
//    {
//        last = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = last;
//    }
//    return pre;
//
//}
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* phead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return phead;
}