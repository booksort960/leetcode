struct ListNode* swapPairs(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* pnext = swapPairs(head->next->next);
    struct ListNode* newhead = head->next;
    newhead->next = head;
    head->next = pnext;
    return newhead;
}
//只有当只有一个结点或没有结点的时候就不会再次递归，否则就是每两个结点递归一次。每次递归就意味着要交换。
//同时要让每两个结点的新结点为这次头结点的next。
//同时返回为pnext也就是上一次递归的头结点。