struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* cura = headA;
    struct ListNode* curb = headB;
    int a = 0, b = 0;
    while (cura)
    {
        cura = cura->next;
        a++;
    }
    while (curb)
    {
        curb = curb->next;
        b++;
    }
    int len = a > b ? b : a;
    cura = headA;
    curb = headB;
    while (cura && a > len)
    {
        cura = cura->next;
        --a;
    }
    while (curb && b > len)
    {
        curb = curb->next;
        --b;
    }
    while (cura && curb)
    {
        if (cura == curb)
            return cura;
        cura = cura->next;
        curb = curb->next;
    }
    return NULL;

}
//通过指针的方式使两个链表的起始比较长度一样，当一样之后，就可以开始循环比较每个指针指向的结点是否相同，相同就是第一个相交结点。