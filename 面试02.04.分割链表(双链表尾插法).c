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
//通过设置两个哨兵结点，一个用于链接小于val的结点，一个用于链接大于val的结点
//用cur指针去依次结点遍历，用尾插法将遍历的结点按照要求插入不同的链表后cur继续向下一个结点遍历
///当cur遍历到NULL时，就结束循环。就会有两个链表，small上全是小于val的结点，big上全是大于val的结点
//同时按照要求大于val的结点在后，小于val的结点在前，用small的尾去链接big的哨兵位的下一个结点，同时还要将big的尾结点的next指向NULL。
//再返回small哨兵尾的next.