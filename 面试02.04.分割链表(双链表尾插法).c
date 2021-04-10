struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* cur = head;
    struct ListNode* smallhead = (struct ListNode*)malloc(sizeof(struct ListNode)), * smalltail = smallhead;
    struct ListNode* bighead = (struct ListNode*)malloc(sizeof(struct ListNode)), * bigtail = bighead;
    while (cur)
    {
        struct ListNode* node = cur->next;
        if (cur->val < x)
        {
            smalltail->next = cur;
            smalltail = smalltail->next;
        }
        else
        {
            bigtail->next = cur;
            bigtail = bigtail->next;
        }
        cur = node;
    }
    bigtail->next = NULL;
    smalltail->next = bighead->next;
    return smallhead->next;
}
//ͨ�����������ڱ���㣬һ����������С��val�Ľ�㣬һ���������Ӵ���val�Ľ��
//��curָ��ȥ���ν���������β�巨�������Ľ�㰴��Ҫ����벻ͬ�������cur��������һ��������
///��cur������NULLʱ���ͽ���ѭ�����ͻ�����������small��ȫ��С��val�Ľ�㣬big��ȫ�Ǵ���val�Ľ��
//ͬʱ����Ҫ�����val�Ľ���ں�С��val�Ľ����ǰ����small��βȥ����big���ڱ�λ����һ����㣬ͬʱ��Ҫ��big��β����nextָ��NULL��
//�ٷ���small�ڱ�β��next.