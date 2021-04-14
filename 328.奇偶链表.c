struct ListNode* oddEvenList(struct ListNode* head)
{
    int num = 0;
    struct ListNode* oddhead = (struct ListNode*)malloc(sizeof(struct ListNode)), * oddtail = oddhead;
    struct ListNode* evenhead = (struct ListNode*)malloc(sizeof(struct ListNode)), * eventail = evenhead;
    struct ListNode* cur = head;
    while (cur)
    {
        ++num;
        if (num % 2 == 0)
        {
            eventail->next = cur;
            eventail = eventail->next;
        }
        else
        {
            oddtail->next = cur;
            oddtail = oddtail->next;
        }
        cur = cur->next;
    }
    eventail->next = NULL;
    oddtail->next = evenhead->next;
    struct ListNode* p = oddhead->next;
    free(oddhead);
    free(evenhead);
    return p;
}
//用两个额外创建的结点一个负责尾插奇数位的结点，另一个负责尾插偶数位的结点。
//同时用一个cur指针负责遍历单链表中的每个结点位。
//cur访问为NULL后就将两个链表链接，合成一个链表。
//同时要满足新链表的为结点->next要置空，否者会因为未改变其next的指向，造成问题可能是环形链表之类的。