//struct ListNode* deleteDuplicates(struct ListNode* head) 
//{
//	if (head == NULL)
//		return NULL;
//	struct ListNode* p ;
//	struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
//	s->next = head;
//	p = s;
//	while (p->next && p->next->next)
//	{
//		if (p->next->val == p->next->next->val)
//		{
//			int x = p->next->val;
//			while (p->next && p->next->val == x)
//			{
//				p->next = p->next->next;
//			} 
//		}
//		else
//			p = p->next;           
//	}
//	return s->next;
//}
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	if (head == NULL)
		return NULL;
	struct ListNode* p;
	struct ListNode* s = (struct ListNode*)malloc(sizeof(struct ListNode));
	s->next = head;
	p = s->next;
	while (p && p->next)
	{
		if (p->val == p->next->val)
		{
			int x = p->next->val;
			while (p->next->next && p->next->next->val == x)
			{
				p = p->next;
			}
		}
		else
			p = p->next;
	}
	return s;
}