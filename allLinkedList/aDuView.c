#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void aDuView() {
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
	printf("\t\t\t\t  1--����������     2--������ǰ    3--�������\n");
	printf("\t\t\t\t  4--�˳�\n\n");


	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
	
}

void aDuFunction(DuLinkedList* L) {
	char choice;
	int position;

	//�ν����ж�
	while (1) {
		aDuView();

		choice = getch();
		if (choice == '4')
			break;

		system("cls");

		switch (choice)
		{
			//����������
		case '1': {
			if (InitList_DuL(L) == 1) {
				printf("�����ɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			break;
		}
			//������ǰ
		case '2': {
			int A;
			char s[20];
			if (L == NULL || (*L) == NULL) {
				printf("ͷ�ڵ�δ����!\n");
				break;
			}
			else
			{
				printf("���������ڵ��(����)ֵ��\n");

				if (scanf("%d", &A) == 1) {
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
					q->data = A;

					if (InsertBeforeList_DuL((*L)->next, q) == 1) {
						printf("����ɹ�\n");
					}
					else
					{
						printf("����ʧ��\n");
					}
				}
				else
				{
					printf("����Ĳ������֣�\n");
					gets_s(s, 20);
				};
				break;
			}
		}
			//�������
		case '3': {
			int A;
			char s[20];
			if (L == NULL || (*L) == NULL) {
				printf("ͷ�ڵ�δ����!\n");
				break;
			}
			else
			{
				printf("���������ڵ��(����)ֵ��\n");

				if (scanf("%d", &A) == 1) {
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
					q->data = A;

					if (InsertAfterList_DuL(*L, q) == 1) {
						printf("����ɹ�\n");
					}
					else
					{
						printf("����ʧ��\n");
					}
				}
				else
				{
					printf("����Ĳ������֣�\n");
					gets_s(s, 20);
				};
				break;
			}
		}
		default:
			break;
		}

		printf("\n��������˳�......");
		getch();

		system("cls");
	}
}