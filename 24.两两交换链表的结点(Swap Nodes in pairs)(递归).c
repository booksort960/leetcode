struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* pnext = swapPairs(head->next->next);
    struct ListNode* newhead = head->next;
    newhead->next = head;
    head->next = pnext;
    return newhead;
}
//ֻ�е�ֻ��һ������û�н���ʱ��Ͳ����ٴεݹ飬�������ÿ�������ݹ�һ�Ρ�ÿ�εݹ����ζ��Ҫ������
//ͬʱҪ��ÿ���������½��Ϊ���ͷ����next��
//ͬʱ����ΪpnextҲ������һ�εݹ��ͷ��㡣