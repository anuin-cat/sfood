#pragma once
#include"Ԥ������.c"
#include <malloc.h>
stu* insert(stu*, stu);		//����
stu* fcreateline(int );		//�ļ����� 0.�ϳ� 1.Ŀǰ
stu* store(stu*, int);		//�����棺0.���� 1.Ŀǰ

//����ѧ�������ɾ��
stu* delete(stu* head, int num,int numDeal) {
	//head�ռ��
	if (head == NULL) {
		printf("ɾ��ʱ�����ͷ���ǿյ�:117\n");
		return NULL;
	}	 	
	//�ļ�����
	stu* head0 = fcreateline(0);

	//׼������
	stu* p = head, * q;

	//��������
	if (head->next == NULL) {
		if (head->num == num && head->numDeal == numDeal) {
			printf("������е�Ԫ�ر�ɾ��:118\n");
			insert(head0, *head);		//����ɾ����
			store(head0,0);				//����ɾ����
			printf("ɾ���ɹ�\n");
			return NULL;
		}
		else {
			printf("ɾ��ʧ�ܣ�û�з�������������:119\n");
			return head;
		}
	}
	//�������
	while (p->num != num || p->numDeal != numDeal) {
		q = p;
		p = p->next;
		if (p == NULL) {
			printf("ɾ��ʧ�ܣ�û�з�������������:120\n");
			return head;
		}
	}
	//ͷβ���
	if (p == head) {
		insert(head0, *head);		//����ɾ����
		store(head0, 0);			//����ɾ����
		printf("ɾ���ɹ�\n");
		return head->next;
	}
	if (p->next == NULL) {
		q->next = NULL;
		insert(head0, *p);			//����ɾ����
		store(head0, 0);			//����ɾ����
		printf("ɾ���ɹ�\n");
		return head;
	}
	//�����м����
	q->next = p->next;
	insert(head0, *p);				//����ɾ����
	store(head0, 0);				//����ɾ����
	printf("ɾ���ɹ�\n");
	return head;
}


