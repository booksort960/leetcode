//struct ListNode* insertionSortList(struct ListNode* head)
//{
//    if (head == NULL || head->next == NULL)
//        return head;
//    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    phead->next = head;
//    struct ListNode* cur = head->next, * pre = phead, * refval = head;
//    while (cur)
//    {
//        struct ListNode* pnext = cur->next;
//        if (refval->val < cur->val)//���ڱ�׼ֱֵ�Ӻ��
//        {
//            refval->next = cur;
//        }
//        else//С�ڱ�׼ֵ�ʹ�phead->next��ʼ������ͬʱҪ����ָ��Ҫ����ָ���׼ֵ����
//        {
//            pre = phead;
//            struct ListNode* pcur = phead->next;
//            while (pcur != refval)
//            {
//                if (pcur->val > cur->val)//���������ǰ���ָ����cur->val������ǰ�����
//                {
//                    pre->next = cur;
//                    cur->next = pcur;
//                    break;
//                }
//                else//������ڻ���ھͼ����������
//                {
//                    pre = pcur;
//                    pcur = pcur->next;
//                }
//            }
//        }
//        refval = cur;
//        cur = pnext;
//    }
//    return phead->next;
//}
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* refval = head, * pre, * cur = refval;
    phead->next = NULL;
    while (cur)//���������е�ÿһ�����
    {
        struct ListNode* newcur = cur;
        cur = cur->next;
        pre = phead;
        while (pre->next && (pre->next->val < newcur->val))
        {
            pre = pre->next;
        }
        newcur->next = pre->next;
        pre->next = newcur;
    }
    return phead->next;
}