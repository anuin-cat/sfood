#pragma once
#include"Ԥ������.c"
#include <malloc.h>
#include<time.h>
#include<stdio.h>
stu* fcreateline(int);		//�ļ����� 0.�ϳ� 1.Ŀǰ



stu in() {
	int gettime(int n);			//��ȡ��ǰʱ�����Ϊ0��ʵ��ʱ���ڼ��ϲ���ֵ
	int gettimes(int num);		//��ȡ���µĽ��״���
	int getSumLeft(int num);	//��ȡ���µ������Ϣ

	//�������ݶ�ȡ
	stu p;
	while (1) {
		printf("���������룺1.ѧ�ţ�2.���׶3.�������ͣ�4.���׵ص㣨�м��ÿո������\n");
		if (scanf("%d%d%d%s", &p.num, &p.sumDeal, &p.typeDeal, p.siteDeal) != 4) {
			printf("��������116\n");
			continue;
		}
		else
			break;
	}
	//printf("%d,%d,%d,%s,%d", p.num, p.sumDeal, p.typeDeal, p.siteDeal,p.dateDeal);

	//�Զ��������ݶ�ȡ
	p.dateDeal = gettime(0);					//��������
	p.dateIn = gettime(0);						//��������
	p.numDeal = gettimes(p.num)+1;				//���״���
	p.sumLeft = getSumLeft(p.num)+p.sumDeal;	//�������
	return p;
}

//ʱ���ȡ����
int gettime(int n) {
	time_t timep;				//����ʱ�����
	time(&timep);				//��ֵ����ʱ��
	timep += n * 100000;
	struct tm* p = gmtime(&timep);	//�õ���׼ʱ��
	int date;
	date = (p->tm_year + 1900) * 10000 + (p->tm_mon + 1) * 100 + (p->tm_mday);
	return date;
}

//���״�����ȡ
int gettimes(int num){
	stu* sort(stu * head, int n);	//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С�����1�Ӵ�С
	stu* searchnum(stu*, int);		//ѧ������

	//���������ȡ
	stu* head;
	head = fcreateline(1);
	if (head == NULL) {
		printf("���ݻ�ȡʧ�ܣ�114\n");
		return 0;
	}
	
	//����ѧ������
	head = searchnum(head, num);
	if (head == NULL) {
		printf("���޴������ݣ����¼���123\n");
		return 1;
	}
	//���������򣬴Ӵ�С
	sort(head, 31);
	return head->numDeal;
}

//��������ȡ
int getSumLeft(int num) {
	stu* sort(stu * head, int n);	//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С�����1�Ӵ�С
	stu* searchnum(stu*, int);		//ѧ������

	//���������ȡ
	stu* head;
	head = fcreateline(1);
	if (head == NULL) {
		printf("���ݻ�ȡʧ�ܣ�115\n");
		return 0;
	}

	//����ѧ������
	head = searchnum(head, num);
	if (head == NULL) {
		printf("���޴������ݣ����¼���122\n");
		return 0;
	}
	//���������򣬴Ӵ�С
	sort(head, 31);
	return head->sumLeft;
}