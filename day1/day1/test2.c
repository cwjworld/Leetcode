#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Leetcode:662 --- ���ѭ������

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* pq);
// ��β����� 
void QueuePush(Queue* pq, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* pq);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* pq);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* pq);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* pq);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* pq);
// ���ٶ��� 
void QueueDestroy(Queue* pq);

// ��ʼ������ 
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
	}

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}

	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* del = pq->head;
		pq->head = pq->head->next;

		free(del);
		del = NULL;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}

	pq->head = pq->tail = NULL;
}

typedef struct {
	Queue q1;
	Queue q2;
}MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&obj->q1);
	QueueInit(&obj->q2);

	return obj;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* nonEmpty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonEmpty = &obj->q1;
	}

	//���ǿ����е�ǰN-1������ն��У�ʣ��һ������ջ��Ԫ��
	while (QueueSize(nonEmpty) > 1)
	{
		QueuePush(empty, QueueFront(nonEmpty));
		QueuePop(nonEmpty);
	}
	int top = QueueFront(nonEmpty);
	QueuePop(nonEmpty);
	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

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