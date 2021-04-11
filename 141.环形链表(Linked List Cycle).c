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
//����ָ�룬һ���뻷��fastָ�����ջ�׷��slow�����û�л�����ô����ָ����ߵ�NULL����