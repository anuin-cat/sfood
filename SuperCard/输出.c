#pragma once
#include"Ԥ������.c"
#include <malloc.h>

//˳����� ѧ��+���״���
void out(stu *head,int n) {
	printf("\n----------out----------\n");
	printf("ѧ��      ��������  ��������  ���׶�    �������  ��������  ���״���  ���׵ص�  \n");
	for (;;)
	{
		if (head != NULL) {
			printf("%-9d %-9d %-9d %-9d %-9d %-9d %-9d %-s\n", head->num, head->dateDeal, head->dateIn, head->sumDeal, head->sumLeft, head->typeDeal, head->numDeal, head->siteDeal);
			head = head->next;
		}
		else
			break;
	}
	printf("-----------------------\n\n");
}