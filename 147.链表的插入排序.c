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
//        if (refval->val < cur->val)//大于标准值直接后插
//        {
//            refval->next = cur;
//        }
//        else//小于标准值就从phead->next开始遍历，同时要遍历指针要不能指向标准值处。
//        {
//            pre = phead;
//            struct ListNode* pcur = phead->next;
//            while (pcur != refval)
//            {
//                if (pcur->val > cur->val)//如果遍历当前结点指大于cur->val就再他前面插入
//                {
//                    pre->next = cur;
//                    cur->next = pcur;
//                    break;
//                }
//                else//如果大于或等于就继续遍历结点
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
    while (cur)//遍历链表中的每一个结点
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