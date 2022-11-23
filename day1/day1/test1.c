#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

// Leetcode:223 --- ��ջʵ�ֶ���

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;		// ջ��
	int capacity;  // ���� 
}ST;

// ��ʼ��ջ 
void StackInit(ST* ps);
// ��ջ 
void StackPush(ST* ps, STDataType data);
// ��ջ 
void StackPop(ST* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(ST* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(ST* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(ST* ps);
// ����ջ 
void StackDestroy(ST* ps);

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* cur = (STDataType*)realloc(ps->a, NewCapacity * sizeof(STDataType));
		if (cur == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = cur;
		ps->capacity = NewCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	--ps->top;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return  ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}


void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

typedef struct {
	ST pushST;
	ST popST;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&obj->pushST);
	StackInit(&obj->popST);

	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->pushST, x);
}

void PushSTTOPopST(MyQueue* obj)
{
	if (StackEmpty(&obj->popST))
	{
		while (!StackEmpty(&obj->pushST))
		{
			StackPush(&obj->popST, StackTop(&obj->pushST));
			StackPop(&obj->pushST);
		}
	}
}

int myQueuePop(MyQueue* obj) {
	PushSTTOPopST(obj);

	int front = StackTop(&obj->popST);
	StackPop(&obj->popST);
	return front;
}

int myQueuePeek(MyQueue* obj) {
	PushSTTOPopST(obj);

	return StackTop(&obj->popST);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->popST)
		&& StackEmpty(&obj->pushST);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->popST);
	StackDestroy(&obj->pushST);

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