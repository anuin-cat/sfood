#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void aView() {
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
	printf("\t\t\t\t  1--����������     2--������    3--�˳�\n\n");

	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void aFunction(LinkedList *L) {
	char choice;
	int position;

	//�ν����ж�
	while (1) {
		aView();

		choice = getch();
		if (choice == '3')
			break;

		system("cls");

		switch (choice)
		{
			//����������
		case '1': {
			if (InitList(L) == 1) {
				printf("�����ɹ�\n");
			}
			else
			{
				printf("����ʧ��\n");
			}
			break;

		}
			//������
		case '2': {

			if (L == NULL || (*L) == NULL) {
				printf("����Ϊ�գ����ܽ��ã�����\n");
				break;
			}

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
					LinkedList q = (LinkedList)malloc(sizeof(LNode));
					q->data = A;

					if (InsertList(*L, q) == 1) {
						printf("����ɹ�\n");
					}
					else
					{
						printf("����ʧ��\n");
					}
					break;
				}
				else
				{
					printf("����Ĳ������֣�\n");
					gets_s(s, 20);
					break;
				};
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