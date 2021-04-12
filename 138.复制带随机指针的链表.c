struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL)
        return NULL;
    struct Node* cur = head;
    struct Node* copynode;
    while (cur)//拷贝结点并插入
    {
        struct Node* curnext = cur->next;
        copynode = (struct Node*)malloc(sizeof(struct Node));
        copynode->val = cur->val;
        cur->next = copynode;
        copynode->next = curnext;
        cur = curnext;
    }
    //处理random指针
    struct Node* newnode = head->next, * tmpcur = head;
    while (tmpcur)
    {
        struct Node* copy = tmpcur->next;
        if (tmpcur->random == NULL)
            copy->random = NULL;
        else
            copy->random = tmpcur->random->next;
        tmpcur = copy->next;

    }
    //合并复制结点
    struct Node* newhead = (struct Node*)malloc(sizeof(struct Node)), * newtail = newhead;
    cur = head;
    while (cur)
    {
        struct Node* newcur = cur->next;
        struct Node* copynext = newcur->next;

        newtail->next = newcur;
        newtail = newtail->next;

        cur->next = copynext;
        cur = copynext;
    }
    struct Node* guard = newhead;
    newhead = newhead->next;
    free(guard);
    return newhead;
}