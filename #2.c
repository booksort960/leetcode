#include <stdio.h>
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
//{
//	int sum1 = 0;
//	int sum2 = 0;
//	struct ListNode* p = l1;
//	p = p->next;
//	int i = 0;
//	while (p != NULL)
//	{
//
//		sum1 += (p->val) * pow(10, i);
//		i++;
//	}
//	i = 0;
//	l2 = l2->next;
//	while (l2 != NULL)
//	{
//		sum2 += (l2->val) * pow(10, i);
//		i++;
//	}
//	int sum = aum1 + sum2;
//	struct ListNode* head,*node;
//	head = (struct ListNode*)malloc(sizeof(struct ListNode));
//	head->next = NULL;
//	i = 2;
//	while (sum&&i)
//	{
//		node = (struct ListNode*)malloc(sizeof(struct ListNode));
//		node->date = sum / pow(10, i);
//		node->next = head->next;
//		head->next = node;
//		sum %= pow(10, i);
//		i--;
//	}
//	return head;
//}
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
//{
//	int num;
//	struct ListNode* head = NULL,*p;
//	head = (struct ListNode*)mallloc(sizeof(struct ListNode));
//	head->next=NULL;
//	int carry=0;
//	while (l1 || l2)
//	{
//		int a = l1?l1->val:0;
//		int b = l2?l2->val:0;
//		p = (struct ListNode*)mallloc(sizeof(struct ListNode));
//		num = a + b + carry;
//		if (num >= 0) 
//		{
//			p->val = num - 10;
//			carry = num / 10;
//		}
//		else
//		{
//			p->val = num;
//			carry = 0;
//		}
//		l1 = l1->next;
//		l2 = l2->next;
//		head->next = p;
//		p->next = head->next;
//	}
//	return head;
//}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int num;
	struct ListNode* head = NULL, * p, * end;
	head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next = NULL;
	end = head;
	int carry = 0;
	while (l1 || l2 || carry)
	{
		int a = l1 ? l1->val : 0;
		int b = l2 ? l2->val : 0;
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		num = a + b + carry;
		p->val = num % 10;
		carry = num / 10;
		l1 = l1 == NULL ? NULL : l1->next;
		l2 = l2 == NULL ? NULL : l2->next;
		end->next = p;
		end = p;
	}
	end->next = NULL;
	return head->next;
}
