#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define CAP 4
typedef int STData;
typedef struct Stack//结构体用于维护栈
{
    int top;//栈顶标记
    STData* arr;//栈的指针
    int capacity;//栈的容量
}STstack;
void InitStack(STstack* st);//栈的初始化
void StackPush(STstack* st, STData n);//元素入栈
STData StackPop(STstack* st);//元素退栈
void StackExpansion(STstack* st);//扩容
int StackEmpty(STstack* st);//判断栈是否为空
void StackDestory(STstack* st);//销毁栈，防止内存泄漏
//void StackPrint(STstack* st);//打印栈的元素，但前提是要退栈才能得到元素
void InitStack(STstack* st)//栈的初始化
{
    st->top = 0;
    st->arr = (STData*)malloc(CAP * sizeof(STData));
    st->capacity = CAP;
}
void StackPush(STstack* st, STData n)//元素入栈
{
    if (st->top == st->capacity)//判断是否需要扩容
    {
        StackExpansion(st);
    }
    st->arr[st->top++] = n;
}
STData StackPop(STstack* st)//元素退栈
{
    assert(st);
    assert(!StackEmpty(st));//判断是否为空栈
    return st->arr[--st->top];
}
int StackEmpty(STstack* st)//判断栈是否为空
{
    if (st->top == 0)
        return 1;
    return 0;
}
void StackDestory(STstack* st)//销毁栈，防止内存泄漏
{
    free(st->arr);
    st->arr = NULL;
}
void StackExpansion(STstack* st)//扩容
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
    while (size)//弹栈后，还要将栈还原
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