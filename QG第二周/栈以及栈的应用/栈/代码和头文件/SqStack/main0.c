#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"

void view0();


int main0() {
	SqStack* s =  (SqStack*)malloc(sizeof(SqStack));
	s->elem = NULL;


	int* e = (int*)malloc(sizeof(int));
	int length;
	char a[20] = {'\0'};

	char choice;

	while (1)
	{
		view0();

		choice = getch();
		if (choice == '9')
			break;
		system("cls");
		switch (choice)
		{
		case '1': {
			if (s->elem!= NULL) {
				printf("ջ�ѳ�ʼ����");
			}
			else
			{
				printf("������ջ�ĳ��ȣ�");
				scanf("%d", &length);
				gets(a);
				if (initStack(s, length) == ERROR) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (isEmptyStack(s) == SUCCESS) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (getTopStack(s, e) == ERROR) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (clearStack == SUCCESS) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (destroyStack(s) == SUCCESS) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (stackLength(s, e) == SUCCESS) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				printf("��������ջ�����ݣ�");
				scanf("%d", e);
				printf("\n");
				gets(a);
				if (pushStack(s, *e) == SUCCESS) {
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
			if (s->elem == NULL) {
				printf("ջδ��ʼ�������ܽ���!\n");
			}
			else
			{
				if (popStack(s, e) == SUCCESS) {
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
void view0() {
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