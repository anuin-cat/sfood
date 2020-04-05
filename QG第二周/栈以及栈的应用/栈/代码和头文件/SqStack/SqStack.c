#include "../stack/SqStack.h"
#include<stdio.h>
#include<stdlib.h>


//���������˳��ջ

//��ʼ��ջ
Status initStack(SqStack* s, int sizes) {

	s->size = sizes;
	s->top = -1;

	//��������
	int* Stack_Array = (int*)malloc(sizes * sizeof(int));
	if (Stack_Array == NULL) {
		return  ERROR;
	}

	s->elem = Stack_Array;

	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack* s) {
	if(s->top == -1)
	{
		return SUCCESS;
	}
	else
	{
		return ERROR;
	}
};

//�õ�ջ��Ԫ��
Status getTopStack(SqStack* s, ElemType* e) {
	if (s->top == -1) {
		printf("ջΪ�գ��޷���ȡ��");
		return ERROR;
	}
	else
	{
		*e = s->elem[s->top];
		return SUCCESS;
	}
};

//���ջ
Status clearStack(SqStack* s) {
	s->top = -1;
	return SUCCESS;
};

//����ջ
Status destroyStack(SqStack* s) {
	if (s->elem != NULL) {
		free(s->elem);
	}
	
	s->elem = NULL;
	return SUCCESS;
};

//���ջ����
Status stackLength(SqStack* s, int* length) {
	*length = s->top+1;
	return SUCCESS;
};

//��ջ
Status pushStack(SqStack* s, ElemType data) {
	s->elem[s->top+1] = data;
	s->top += 1;
	return SUCCESS;
};

//��ջ
Status popStack(SqStack* s, ElemType* data) {
	if (s->top == -1) {
		return ERROR;
	}
	data = s->elem[s->top];
	s->top -= 1;
	return SUCCESS;
};





