#include <stdio.h>
struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->next = NULL;
    struct ListNode* last = phead, * newcell = head;

    while (newcell)
    {
        struct ListNode* tmp = last->next, * cur = newcell;
        newcell = newcell->next;
        if (phead == last)
        {
            last->next = cur;
            cur->next = tmp;
            last = last->next;//删除这行代码，就可以达到反转的效果
            continue;
        }
        if (last->val == cur->val)
        {
            continue;
        }
        cur->next = tmp;
        last->next = cur;
        last = last->next;
    }
    return phead->next;

}
int main(void)
{
    struct ListNode n1;
    struct ListNode n2;
    struct ListNode n3;
    struct ListNode n4;
    struct ListNode n5;
    struct ListNode n6;
    struct ListNode n7;
    n1.val = 1;
    n2.val = 2;
    n3.val = 2;
    n4.val = 3;
    n5.val = 4;
    n6.val = 5;
    n7.val = 7;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = NULL;
    deleteDuplicates(&n1);
}