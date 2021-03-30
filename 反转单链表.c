//struct ListNode* ReverseList(struct ListNode* pHead)
//{
//    if (pHead == NULL)
//        return NULL;
//    if (pHead == NULL)
//        return pHead;
//    struct ListNode* cur = pHead;
//    struct ListNode* pre = NULL;
//    struct ListNode* tmp;
//    while (cur != NULL)
//    {
//        tmp = cur->next;
//        cur->next = pre;
//        pre = cur;
//        cur = tmp;
//    }
//    return pre;
//}
struct ListNode* ReverseList(struct ListNode* pHead)
{
	if (pHead == NULL||pHead==NULL)
		return pHead;
	struct ListNode* nhead = ReverseList(pHead->next);
	pHead->next->next = pHead;
	pHead->next = NULL;
	return nhead;
}