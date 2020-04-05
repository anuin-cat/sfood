#include "four.h"

int InitStack(Stack** s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	*s = (Stack*)malloc(sizeof(Stack));
	if (NULL == *s)
	{
		return FAILURE;
	}
	(*s)->top = NULL;
	(*s)->length = 0;
	return SUCCESS;
}


int Push(Stack* s, int e)
{
	if (NULL == s)
	{
		return FAILURE;
	}

	Node* tmp = (Node*)malloc(sizeof(Node));
	if (NULL == tmp)
	{
		return FAILURE;
	}

	tmp->data = e;
	tmp->next = s->top;
	s->top = tmp;
	s->length++;

	return SUCCESS;
}

int EmptyStack(Stack* s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	return s->top == NULL ? TRUE : FALSE;
}

int GetTop(Stack* s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	if (NULL == s->top)
	{
		return FAILURE;
	}
	return s->top->data;
}

int Pop(Stack* s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	if (s->top == NULL)
	{
		return FAILURE;
	}

	int tmp;
	Node* stmp = s->top;
	tmp = s->top->data;
	s->top = stmp->next;
	free(stmp);
	stmp = NULL;
	s->length--;

	return tmp;

}

int ClearStack(Stack* s)
{
	if (NULL == s)
	{
		return FAILURE;
	}
	Node* tmp;
	while (s->top != NULL)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	s->length = 0;
	return SUCCESS;
}

int DestroyStack(Stack** s)
{
	if (NULL == s)
	{
		return FAILURE;
	}

	free(*s);
	*s = NULL;
	return SUCCESS;
}

