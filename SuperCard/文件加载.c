#pragma once
#include"Ԥ������.c"
#include <malloc.h>
#include<stdlib.h>
#include<stdio.h>

stu* fcreateline(int n) {

	stu* head, * p, * q;
	FILE* fp;
	errno_t err;
	switch (n)
	{
	case 1:err = fopen_s(&fp, "ͨ������.txt", "r"); break;
	case 0:err = fopen_s(&fp, "��������.txt", "r"); break;
	default:
		break;
	}
		
	if (err != 0||fp==NULL) {
		printf("�ļ�����ʱ�ļ���ʧ��:121\n");
		return NULL;
	}
	for(int i = 0 ; 1 ; i++)
	{
		p = (stu*)malloc(sizeof(stu));
		if (fscanf(fp,"%d,%d,%d,%d,%d,%d,%d,%s\n",&p->num,&p->dateDeal,&p->dateIn,&p->sumDeal,&p->sumLeft,&p->typeDeal,&p->numDeal,p->siteDeal)!=8) {
			/*if (n == 0)
				printf("�������ݳ�ʼ��\n");
			else
				printf("ͨ�����ݳ�ʼ��\n");*/
			free(p); 
			break;
		}
		p->next = NULL;
		if (i == 0)
			head = p;
		else
			q->next = p;
		q = p;
	}
	if (fclose(fp)) {
		printf("�ر�ʧ��\n");
		exit(0);
	}
	return head;
}