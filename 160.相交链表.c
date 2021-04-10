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
//ͨ��ָ��ķ�ʽʹ�����������ʼ�Ƚϳ���һ������һ��֮�󣬾Ϳ��Կ�ʼѭ���Ƚ�ÿ��ָ��ָ��Ľ���Ƿ���ͬ����ͬ���ǵ�һ���ཻ��㡣