#ifndef LINKSTACK_H
#define	LINKSTACK_H

#include <stdlib.h>
#include <stdio.h>
#define SUCCESS 10000
#define FAILURE 10001
#define	TRUE	10002
#define FALSE	10003

typedef struct StackNode
{
	int data;
	struct StackNode* next;
}Node;

typedef struct StackInfo
{
	struct StackNode* top;
	int length;
}Stack;

//��ʼ��
int InitStack(Stack** s);
//��ջ
int Push(Stack* s, int e);
//�Ƿ�Ϊ��
int EmptyStack(Stack* s);
//��ȡջ��Ԫ��
int GetTop(Stack* s);
//ȡ��ջ��Ԫ��
int Pop(Stack* s);
//���ջ
int ClearStack(Stack* s);
//�ݻ�ջ
int DestroyStack(Stack** s);
#endif