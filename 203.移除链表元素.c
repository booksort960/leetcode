//直接迭代法
//struct ListNode* removeElements(struct ListNode* head, int val)
//{
//	struct ListNode* cur, * p;
//	cur = head;
//	if (head == NULL)
//		return NULL;
//	while (cur->next)
//	{
//		if (cur->next->val == val)
//		{
//			p = cur->next;
//			cur->next = p->next;
//			free(p);
//		}
//		else
//			cur = cur->next;
//	}
//	return head->val == val ? head->next:head;
//}



//哨兵法
struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* s;
	p->next = head;
	s = p;
	if (head == NULL)
		return NULL;
	while (s != NULL && (s->next) != NULL)
	{
		if (((s->next)->val) == val)
		{
			struct ListNode* pt = s->next;
			s->next = pt->next;
			pt->next = NULL;
			free(pt);
			head = p->next;
		}
		else
			s = s->next;
	}
	return head;
}