struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* fast = head, * slow = head, * pre = NULL;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    while (fast)
    {
        pre = slow;
        fast = fast->next;
        slow = slow->next;
    }
    if (pre == NULL)
        return head->next;
    pre->next = slow->next;

    return head;
}
//利用快慢指针的方法查找到第n个结点，再每次都使用一个pre的指针在slow的前面，当fast到NULL时，slow就定位到倒数第n个结点。再pre改变前一个指针指向就行了