#include "LinkStack.h"
#include<stdio.h>
#include<stdlib.h>


//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	s->count = 0;
	return SUCCESS;
};

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->top == NULL) {
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
};

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL) {
		printf("ջΪ�գ�\n");
		return ERROR;
	}
	else
	{
		*e = s->top->data;
		return SUCCESS;
	}
};

//���ջ
Status clearLStack(LinkStack* s) {
	if (s->top == NULL) {
		printf("ջ�Ѿ�Ϊ�գ�\n");
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

//����ջ
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

//���ջ����
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

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	StackNode* a = (StackNode*)malloc(sizeof(StackNode));
	a->data = data;
	a->next = s->top;
	s->top = a;
	return SUCCESS;
};

//��ջ
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