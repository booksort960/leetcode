#define _CRT_SECURE_NO_WARNINGS
typedef int QUData;
typedef struct queue
{
	QUData data;
	struct queue* next;
}queue;
typedef struct Queue//结构体用于维护队列
{
	queue* Dequeue;//队头指针
	queue* Enqueue;//队尾指针
}QUqueue;
void InitQueue(QUqueue* qu);//栈的初始化
void QueuePush(QUqueue* qu, QUData n);//元素入队
QUData QueuePop(QUqueue* qu);//元素出队
int QueueEmpty(QUqueue* qu);//判断队列是否为空
void QueueDestory(QUqueue* qu);//销毁队，防止内存泄漏
//void QueuePrint(QUqueue* qu);//打印队列中的元素，但前提是要出队才能得到元素

void InitQueue(QUqueue* qu)//栈的初始化
{
	qu->Dequeue = qu->Enqueue = NULL;
}
void QueuePush(QUqueue* qu, QUData n)//元素入队
{
	queue* newcell = (queue*)malloc(sizeof(queue));
	newcell->data = n;
	newcell->next = NULL;
	if (qu->Dequeue == NULL)
	{
		qu->Enqueue = qu->Dequeue = newcell;
	}
	else
	{
		qu->Enqueue->next = newcell;
		qu->Enqueue = newcell;
	}
}
QUData QueuePop(QUqueue* qu)//元素出队
{
	if (QueueEmpty(qu))
	{
		return 0;
	}
	QUData ret = qu->Dequeue->data;
	qu->Dequeue = qu->Dequeue->next;
	return ret;
}
int QueueEmpty(QUqueue* qu)//判断队列是否为空
{
	return qu->Dequeue == NULL;
}
void QueueDestory(QUqueue* qu)//销毁队，防止内存泄漏
{
	queue* cur = qu->Dequeue;
	while (cur)
	{
		queue* pnext = cur->next;
		free(cur);
		cur = pnext;
	}
	qu->Dequeue = qu->Enqueue = NULL;
}
typedef struct {
	QUqueue q1;
	QUqueue q2;
} MyStack;
/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	InitQueue(&pst->q1);
	InitQueue(&pst->q2);
	return pst;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q2, x);
	}
	else
	{
		QueuePush(&obj->q1, x);
	}
}
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	QUqueue* empty = &obj->q1;
	QUqueue* noempty = &obj->q2;
	if (!QueueEmpty(empty))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	queue* cur = noempty->Dequeue;
	while (cur != noempty->Enqueue)
	{
		QueuePush(empty, QueuePop(noempty));
		cur = cur->next;
	}
	return QueuePop(noempty);
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (QueueEmpty(&obj->q1))
	{
		return obj->q2.Enqueue->data;
	}
	return obj->q1.Enqueue->data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestory(&obj->q1);
	QueueDestory(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/