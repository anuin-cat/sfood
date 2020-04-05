#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	s->count = 0;
	return SUCCESS;
};

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s->top == NULL) {
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
};

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL) {
		printf("栈为空！\n");
		return ERROR;
	}
	else
	{
		*e = s->top->data;
		return SUCCESS;
	}
};

//清空栈
Status clearLStack(LinkStack* s) {
	if (s->top == NULL) {
		printf("栈已经为空！\n");
		return SUCCESS;
	}
	else
	{
		StackNode* a = s->top;
		while (a!=NULL)
		{
			s->top = s->top->next;
			free(a);
			a = s->top;
		}
		return SUCCESS;
	}
};

//销毁栈
Status destroyLStack(LinkStack* s) {
	if (s->top == NULL) {
		s->count = -1;
		return SUCCESS;
	}
	else
	{
		StackNode* a = s->top;
		while (a != NULL)
		{
			s->top = s->top->next;
			free(a);
			a = s->top;
		}
		s->count = -1;
		return SUCCESS;
	}
};

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	if (s->top == NULL) {
		*length = 0;
		return SUCCESS;
	}
	else
	{
		int i=0;
		StackNode* a = s->top;
		for (i = 0; a != NULL; i++) {
			a = a->next;
		}
		*length = i;
		return SUCCESS;
	}
	
};

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* a = (StackNode*)malloc(sizeof(StackNode));
	a->data = data;
	a->next = s->top;
	s->top = a;
	return SUCCESS;
};

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == NULL) {
		return ERROR;
	}
	StackNode* a = s->top;
	s->top = a->next;
	*data = a->data;
	free(a);
	return SUCCESS;
};