#pragma once
#include"Ԥ������.c"
#include<stdlib.h>
#include<stdio.h>


int store(stu* head, int s) {
	FILE* fp;
	errno_t err;		//�쳣���
	switch (s)
	{
	case 1: {err = fopen_s(&fp, "ͨ������.txt", "w+"); }break;
	case 0: {err = fopen_s(&fp, "��������.txt", "w+"); }break;
	default: break;
	}
	if (err != NULL||fp==NULL)	//�ļ���ʧ��
	{
		printf("����ʱ�ļ���ʧ��\n");
		return 0;
	}
	while (head != NULL) {
		fprintf(fp,"%d,%d,%d,%d,%d,%d,%d,%s\n",head->num,head->dateDeal,head->dateIn,head->sumDeal,head->sumLeft,head->typeDeal,head->numDeal,head->siteDeal);
		head = head->next;
	}
	if (fclose(fp)) {
		printf("�ر�ʧ��\n");
		exit(0);
	}
}