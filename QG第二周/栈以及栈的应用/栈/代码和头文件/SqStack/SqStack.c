#include "../stack/SqStack.h"
#include<stdio.h>
#include<stdlib.h>


//基于数组的顺序栈

//初始化栈
Status initStack(SqStack* s, int sizes) {

	s->size = sizes;
	s->top = -1;

	//开辟数组
	int* Stack_Array = (int*)malloc(sizes * sizeof(int));
	if (Stack_Array == NULL) {
		return  ERROR;
	}

	s->elem = Stack_Array;

	return SUCCESS;
}

//判断栈是否为空
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

//得到栈顶元素
Status getTopStack(SqStack* s, ElemType* e) {
	if (s->top == -1) {
		printf("栈为空，无法获取！");
		return ERROR;
	}
	else
	{
		*e = s->elem[s->top];
		return SUCCESS;
	}
};

//清空栈
Status clearStack(SqStack* s) {
	s->top = -1;
	return SUCCESS;
};

//销毁栈
Status destroyStack(SqStack* s) {
	if (s->elem != NULL) {
		free(s->elem);
	}
	
	s->elem = NULL;
	return SUCCESS;
};

//检测栈长度
Status stackLength(SqStack* s, int* length) {
	*length = s->top+1;
	return SUCCESS;
};

//入栈
Status pushStack(SqStack* s, ElemType data) {
	s->elem[s->top+1] = data;
	s->top += 1;
	return SUCCESS;
};

//出栈
Status popStack(SqStack* s, ElemType* data) {
	if (s->top == -1) {
		return ERROR;
	}
	data = s->elem[s->top];
	s->top -= 1;
	return SUCCESS;
};





