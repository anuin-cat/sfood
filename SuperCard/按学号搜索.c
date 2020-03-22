#pragma once
#include"预处理定义.c"
#include <malloc.h>

stu* search(stu * head,int num,int n) {
	if (head == NULL)return NULL;
	while (head->num != num|| head->numDeal != n)
	{
		head = head->next;
		if (head == NULL)break;
	}
	if (head == NULL)
		return NULL;
	else 
		return head;
}