#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void tView(){
	/***************************
	*			����
	****************************/
	//�Ͽյ�
	for (int i = 0; i < 12; i++)
		printf("\n");

	//�Ϸֽ�� 
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n\n");

	//Ŀ¼
	printf("\t\t\t\t  1--��������     2--��ѯ���     3--��ȫ��ת����  \n");
	printf("\t\t\t\t  4--�Ƿ��ǻ�     5--�м���     6--��ż��ת����  \n");
	printf("\t\t\t\t  7--�˳�    \n\n");


	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void tFunction(LinkedList *L) {

	if (L == NULL || (*L) == NULL) {
		printf("����δ���������ܽ��ã�����\n");
		printf("����������ء�����\n");
		getch();
		return;
	}


	char choice;
	int position;

	//�ν����ж�
	while (1) {
		tView();

		choice = getch();
		if (choice == '7')
			break;

		system("cls");

		switch (choice)
		{
			//��������
		case '1': {
			TraverseList(*L, pri);
			break;
		}
			//��ѯ���
		case '2': {
			printf("��������Ҫ��ѯ�Ľ��λ�ã����֣���\n");
			scanf_s("%d", &position,1);

			if (SearchList(*L, position) == 1) {
				printf("������\n");
			}
			else
			{
				printf("��㲻����\n");
			}
			break;
		}
			//��ȫ��ת����
		case '3': {
			if (ReverseList(L) == 1) {
				printf("��ת�ɹ�\n");
			}
			else
			{
				printf("��תʧ��\n");
			}
			break;
		}
			//�Ƿ��ǻ�
		case '4': {
			if (IsLoopList(*L) == 1) {
				printf("�ǻ�\n");
			}
			else
			{
				printf("���ǻ�\n");
			}
			break;
		}
			//�м���
		case '5': {
			LinkedList A = FindMidNode(L);
			if (A == NULL) {
				printf("����Ϊ�գ��޷�����");
			}
			else
			{
				printf("�м�ڵ����ֵ�ǣ�%d\n�м�ڵ�ĵ�ַ��%p\n", A->data, A);
			}
			break;
		}
			//��ż��ת����
		case '6': {
			LinkedList A = ReverseEvenList(L);
			if (A == NULL) {
				printf("����Ϊ�գ��޷���ת\n");
			}
			else
			{
				printf("��ת�ɹ�\n");
			}
			break;
		}
		default:
			break;
		}
		printf("\n��������˳�......");
		getch();

		system("cls");

	}
}