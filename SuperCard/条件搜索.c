#pragma once
#include"Ԥ������.c"
#include <malloc.h>
#include<stdlib.h>
#include<stdio.h>

//ѧ�Ų�ѯ-----ѧ��
stu* searchnum(stu *head,int num) {

	stu* sort(stu * head, int n);//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С���󣬼�1�Ӵ�С


	//��������
	stu*p;
	sort(head, 00);

	//��������
	if (head == NULL){
		printf("����ʧ�ܣ����˲�����\n");
		return NULL;
	}
		
	while (head->num != num) {
		head = head->next;
		if (head == NULL) {
			printf("����ʧ�ܣ����˲�����\n");
			return NULL;
		}
	}

	p = head;
	while (p->next!=NULL) {
		if (p->next->num != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}		//ѧ�Ų���----����Ϊ����+ѧ��ѧ��

//���ڲ�ѯ-----����������8λ����
stu* searchDateDeal(stu* head, int date1, int date2) {
	
	stu* sort(stu * head, int n);//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С���󣬼�1�Ӵ�С

	//���ݴ���
	if (date1 < 10000000 || date1>99999999 || date2 < 10000000 || date2>99999999) {
		printf("������������\n");
		return NULL;
	}
	int swap;
	if (date1 < date2) {
		swap = date1;
		date1 = date2;
		date2 = swap;
	}

	//�������ڲ�����
	sort(head, 11);
	stu* p;
	if (head == NULL) {
		printf("����ʧ�ܣ����˲�����\n");
		return NULL;
	}

	while (head->dateDeal > date1) {
		head = head->next;
		if (head == NULL) {
			printf("����ʧ�ܣ����˲�����\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->dateDeal < date2)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}	//���ڲ���----��������8λ��,���򷵻ؿ�ָ��

//���׶��ѯ-----���
stu* searchSumDeal(stu* head, int num) {

	stu* sort(stu * head, int n);//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С���󣬼�1�Ӵ�С

	//��������
	stu* p;
	sort(head, 20);

	//��������
	if (head == NULL) {
		printf("����ʧ�ܣ����˲�����\n");
		return NULL;
	}

	while (head->sumDeal != num) {
		head = head->next;
		if (head == NULL) {
			printf("����ʧ�ܣ����˲�����\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->sumDeal != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}	  

//���Ͳ�ѯ----����һ�����ʹ���
stu* searchTypeDeal(stu* head, int num) {

	stu* sort(stu * head, int n);//���� 0ѧ�� 1���� 2��� 3���� ���0Ϊ��С���󣬼�1�Ӵ�С


	//��������
	stu* p;
	sort(head, 40);

	//��������
	if (head == NULL) {
		printf("����ʧ�ܣ����˲�����\n");
		return NULL;
	}

	while (head->typeDeal != num) {
		head = head->next;
		if (head == NULL) {
			printf("����ʧ�ܣ����˲�����\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->typeDeal != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}