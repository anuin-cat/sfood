#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void dDuView() {
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
	printf("\t\t\t\t  1--�ݻ�����    2--ɾ������    3--�˳�\n\n");

	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}


void dDuFunction(DuLinkedList* L) {
	char choice;
	int position;

	//�ν����ж�
	while (1) {
		dDuView();

		choice = getch();
		if (choice == '3')
			break;

		system("cls");

		switch (choice)
		{
			//�ݻ�����
		case '1': {
			TraverseList_DuL(*L, duPri);
			break;
		}
			//ɾ�����
		case '2': {
			int* e = (int*)malloc(sizeof(int));
			if (DeleteList_DuL((*L), e) == 1) {
				printf("ɾ���ɹ�\n");
				printf("��ɾ���Ľ����ֵ��%d", *e);
			}
			else
			{
				printf("ɾ��ʧ��\n");
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