struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* cura = headA;
    struct ListNode* curb = headB;
    while (cura != curb)
    {
        cura = cura->next;
        curb = curb->next;
        if (cura == NULL && curb == NULL)
            break;
        if (cura == NULL)
        {
            cura = headB;
        }
        if (curb == NULL)
        {
            curb = headA;
        }

    }
    return cura;
}