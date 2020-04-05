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

//初始化
int InitStack(Stack** s);
//入栈
int Push(Stack* s, int e);
//是否为空
int EmptyStack(Stack* s);
//获取栈顶元素
int GetTop(Stack* s);
//取出栈顶元素
int Pop(Stack* s);
//清空栈
int ClearStack(Stack* s);
//摧毁栈
int DestroyStack(Stack** s);
#endif