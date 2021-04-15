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
//���ÿ���ָ��ķ������ҵ���n����㣬��ÿ�ζ�ʹ��һ��pre��ָ����slow��ǰ�棬��fast��NULLʱ��slow�Ͷ�λ��������n����㡣��pre�ı�ǰһ��ָ��ָ�������