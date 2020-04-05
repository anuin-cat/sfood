#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

void view1();

int main1() {
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = -1;

	int length;
	int* e = (int*)malloc(sizeof(int));
	char a[20] = { '\0' };

	char choice;

	while (1)
	{
		view1();

		choice = getch();
		if (choice == '9')
			break;
		system("cls");
		switch (choice)
		{
		case '1': {
			if (s->count!=-1) {
				printf("ջ�ѳ�ʼ����");
			}
			else
			{
				if (initLStack(s) == ERROR) {
					printf("��ʼ��ʧ�ܣ�\n");
				}
				else
				{
					printf("��ʼ���ɹ���\n");
				}

			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '2': {
			if (s->count == -1)
			{
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else if (s->top == NULL) {
				printf("����Ϊ��!\n");
			}
			else
			{
				if (isEmptyLStack(s) == SUCCESS) {
					printf("ջΪ�գ�\n");
				}
				else
				{
					printf("ջ��Ϊ�գ�\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '3': {
			if (s->count== -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (getTopLStack(s, e) == ERROR) {
					printf("��ȡʧ�ܣ�\n");
				}
				else
				{
					printf("ջ��Ԫ���ǣ�%d", *e);
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '4': {
			if (s->count == -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (clearLStack(s) == SUCCESS) {
					printf("����ɹ���\n");
				}
				else
				{
					printf("���ʧ�ܣ�\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '5': {
			if (s->count == -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (destroyLStack(s) == SUCCESS) {
					printf("���ٳɹ���\n");
				}
				else
				{
					printf("����ʧ�ܣ�\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '6': {
			if (s->count == -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (LStackLength(s, e) == SUCCESS) {
					printf("ջ�ĳ����ǣ�%d\n", *e);
				}
				else
				{
					printf("���ʧ�ܣ�\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '7': {
			if (s->count == -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				printf("��������ջ�����ݣ�");
				scanf("%d", e);
				printf("\n");
				gets(a);
				if (pushLStack(s, *e) == SUCCESS) {
					printf("��ջ�ɹ���\n");
				}
				else
				{
					printf("��ջʧ�ܣ�\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		case '8': {
			if (s->count == -1) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (popLStack(s, e) == SUCCESS) {
					printf("��ջ�����ǣ�%d\n", *e);
				}
				else
				{
					printf("��ջʧ��\n");
				}
			}
			printf("��������˳���\n");
			getch();
			system("cls");
		}break;
		default:
			break;
		}
	}

	return 0;

}

//������
void view1() {
	printf("\n\n\n");

	//��һ��
	for (int i = 0; i < 120; i++) {
		printf("*");
	}

	//�ڶ���
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//������
	for (int i = 0; i < 44; i++) {
		printf("*");
	}
	printf("�� �� �� �� ֮ �� ջ �� �� �� ��");
	for (int i = 0; i < 44; i++) {
		printf("*");
	}

	//������
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//������
	for (int i = 0; i < 44; i++) {
		printf("*");
	}
	printf("���ߣ�ţ����(3119004928) �ƿ�5��");
	for (int i = 0; i < 44; i++) {
		printf("*");
	}

	//������
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//������
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("1.  ��ʼ��ջ                  ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//�ڰ���
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//�ھ���
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("2.  �ж�ջ�Ƿ�Ϊ��            ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//��ʮ��
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//��ʮһ��
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("3.  �õ�ջ��Ԫ��              ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//��ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//��ʮ����
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("4.  ���ջ                    ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//��ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//��ʮ����
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("5.  ����ջ                    ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//��ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//��ʮ����
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("6.  ���ջ����                ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//��ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//��ʮ����
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("7.  ��ջ                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//�ڶ�ʮ��
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//�ڶ�ʮһ��
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("8.  ��ջ                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//�ڶ�ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//�ڶ�ʮ����
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("9.  �˳�                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//�ڶ�ʮ����
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//�ڶ�ʮ����
	for (int i = 0; i < 120; i++) {
		printf("*");
	}

}