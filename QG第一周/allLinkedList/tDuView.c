#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void tDuView() {
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
	printf("\t\t\t\t  1--��������    2--�˳�\n\n");

	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void tDuFunction(DuLinkedList* L) {

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
		tDuView();

		choice = getch();
		if (choice == '2')
			break;

		system("cls");

		switch (choice)
		{
			//��������
		case '1': {
			TraverseList_DuL(*L, duPri);
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