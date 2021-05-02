#define _CRT_SECURE_NO_WARNINGS
typedef int QUData;
typedef struct queue
{
	QUData data;
	struct queue* next;
}queue;
typedef struct Queue//�ṹ������ά������
{
	queue* Dequeue;//��ͷָ��
	queue* Enqueue;//��βָ��
}QUqueue;
void InitQueue(QUqueue* qu);//ջ�ĳ�ʼ��
void QueuePush(QUqueue* qu, QUData n);//Ԫ�����
QUData QueuePop(QUqueue* qu);//Ԫ�س���
int QueueEmpty(QUqueue* qu);//�ж϶����Ƿ�Ϊ��
void QueueDestory(QUqueue* qu);//���ٶӣ���ֹ�ڴ�й©
//void QueuePrint(QUqueue* qu);//��ӡ�����е�Ԫ�أ���ǰ����Ҫ���Ӳ��ܵõ�Ԫ��

void InitQueue(QUqueue* qu)//ջ�ĳ�ʼ��
{
	qu->Dequeue = qu->Enqueue = NULL;
}
void QueuePush(QUqueue* qu, QUData n)//Ԫ�����
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
QUData QueuePop(QUqueue* qu)//Ԫ�س���
{
	if (QueueEmpty(qu))
	{
		return 0;
	}
	QUData ret = qu->Dequeue->data;
	qu->Dequeue = qu->Dequeue->next;
	return ret;
}
int QueueEmpty(QUqueue* qu)//�ж϶����Ƿ�Ϊ��
{
	return qu->Dequeue == NULL;
}
void QueueDestory(QUqueue* qu)//���ٶӣ���ֹ�ڴ�й©
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