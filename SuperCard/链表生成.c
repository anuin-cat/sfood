#pragma once
#include"Ԥ������.c"
#include<time.h>
#include <malloc.h>

stu* createline(int n) {
	int gettime(int n);		//���ڻ�ȡ����

	stu* head, * p, * q;
	if (n <= 0)	return NULL;
	
	for (int i = 0; i < n; i++)
	{
		p = (stu*)malloc(sizeof(stu));

		//���������
		srand((i*88+5)/3);
		int a = rand()%10;

		//�����������ֵ
		p->num= 9004928+a;				//ѧ��

		p->dateDeal = gettime(a*3%10);	//��������
		p->dateIn = gettime(a*3%10);	//��������

		p->sumDeal = a * 2 + 6 + i;		//���׶�
		p->sumLeft = 1;					//���׺����

		p->typeDeal = a % 3+1;			//��������

		p->numDeal = 1+i%10;			//���״���
		p->siteDeal[0] = 'G';			//���׵ص�
		p->siteDeal[1] = '\0';


		//�������
		p->next = NULL;

		if (i == 0)
			head = p;
		else
			q->next = p;
		q = p;
	}

	return head;
}