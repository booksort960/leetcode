//struct ListNode* deleteDuplicates(struct ListNode* head) 
//{
//	struct ListNode* p = head,* s;
//	p = p->next;
//	s = p;
//	s -> val = p->val;
//	p = p->next;
//	while (p != NULL)
//	{
//		if (p->val != s->val)
//		{
//			s = s->next;
//			s->val = p->val;
//		}
//		p = p->next;
//	}
//	s->next = NULL;
//	return s;
//
//}
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* p = head, * s;
	s = p;
	s->val = p->val;
	p = p->next;
	while (p != NULL)
	{
		if (p->val != s->val)
		{
			s = s->next;
			s->val = p->val;
		}
		p = p->next;
	}
	s->next = NULL;
	return head;

}