#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define CAP 4
typedef int STData;
typedef struct Stack//�ṹ������ά��ջ
{
    int top;//ջ�����
    STData* arr;//ջ��ָ��
    int capacity;//ջ������
}STstack;
void InitStack(STstack* st);//ջ�ĳ�ʼ��
void StackPush(STstack* st, STData n);//Ԫ����ջ
STData StackPop(STstack* st);//Ԫ����ջ
void StackExpansion(STstack* st);//����
int StackEmpty(STstack* st);//�ж�ջ�Ƿ�Ϊ��
void StackDestory(STstack* st);//����ջ����ֹ�ڴ�й©
//void StackPrint(STstack* st);//��ӡջ��Ԫ�أ���ǰ����Ҫ��ջ���ܵõ�Ԫ��
void InitStack(STstack* st)//ջ�ĳ�ʼ��
{
    st->top = 0;
    st->arr = (STData*)malloc(CAP * sizeof(STData));
    st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//Ԫ����ջ
{
    if (st->top == st->capacity)//�ж��Ƿ���Ҫ����
    {
        StackExpansion(st);
    }
    st->arr[st->top++] = n;
}
STData StackPop(STstack* st)//Ԫ����ջ
{
    assert(st);
    assert(!StackEmpty(st));//�ж��Ƿ�Ϊ��ջ
    return st->arr[--st->top];
}
int StackEmpty(STstack* st)//�ж�ջ�Ƿ�Ϊ��
{
    if (st->top == 0)
        return 1;
    return 0;
}
void StackDestory(STstack* st)//����ջ����ֹ�ڴ�й©
{
    free(st->arr);
    st->arr = NULL;
}
void StackExpansion(STstack* st)//����
{
    STData* tmp = (STData*)realloc((STData*)st->arr, sizeof(STData) * (st->capacity) * 2);
    if (tmp == NULL)
    {
        printf("Exparsion Error\n");
        exit(-1);
    }
    st->arr = tmp;
    st->capacity *= 2;
}
typedef struct {
    STstack s1;
    STstack s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue* st = (MyQueue*)malloc(sizeof(MyQueue));
    InitStack(&st->s1);
    InitStack(&st->s2);
    return st;
}
/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    StackPush(&obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
    int size = obj->s1.top;
    while (size > 1)
    {
        StackPush(&obj->s2, StackPop(&obj->s1));
        --size;
    }
    int ret = StackPop(&obj->s1);
    size = obj->s2.top;
    while (size)//��ջ�󣬻�Ҫ��ջ��ԭ
    {
        StackPush(&obj->s1, StackPop(&obj->s2));
        size--;
    }
    return ret;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->s1))
    {
        return obj->s2.arr[0];
    }
    return obj->s1.arr[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->s1);
    StackDestory(&obj->s2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/