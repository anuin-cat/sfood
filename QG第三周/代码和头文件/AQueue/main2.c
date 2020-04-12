#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>

void AView();

int main1() {
	int choice, i;
	AQueue Q;
	Q.front = 0;
	Q.rear = 0;
	Q.length = -1;
	int t;
	void* e = NULL;
	char c;
	char a[20];
	char* string = a[20];
	while (1) {
		AView();

		printf("\nYour choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			if (Q.length!=-1) {
				printf("�����ѱ��������޷�������\n");
				break;
			}
			InitAQueue(&Q);
			printf("�����ɹ�\n");
			printf("��������˳�\n");
			getch();
			break;
		}
		case 2: {
			if (Q.length==-1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			DestoryAQueue(&Q);
			printf("�ݻٳɹ�\n");
			printf("��������˳�\n");
			getch();
			break;
		}
		case 3: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			ClearAQueue(&Q);
			printf("����ɹ�\n");
			printf("��������˳�\n");
			getch();
			break;

		}
		case 4: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			printf("����Ҫ�������������?\n");
			printf("1.int  2.char  3.double \n");
			printf("ѡ��:");
			scanf("%d", &t);
			if (t != 1 && t != 2 && t != 3) {
				printf("�������ݴ���\n");
				printf("��������˳�\n");
				getch();
				break;
			}
			printf("��������:");

			switch (t)
			{
			case 1: {

				int a;
				scanf("%d", &a);
				datatype[Q.rear] = 'i';
				if (EnAQueue(&Q, &a)) {
					printf("�ɹ�\n");
				}
				else {
					printf("ʧ��\n");
				}
				break;

			}

			case 2: {

				getchar();
				c = getchar();
				datatype[Q.rear] = 'c';
				if (EnAQueue(&Q, &c)) {
					printf("�ɹ�\n");
				}
				else {
					printf("ʧ��\n");
				}
				break;

			}

			case 3: {

				double d;
				printf("enter (eg:3.89):");
				scanf("%f", &d);
				datatype[Q.rear] = 'd';
				if (EnAQueue(&Q, &d)) {

					printf("�ɹ�\n");
				}
				else {
					printf("ʧ��\n");
				}
				break;

			}

			default:printf("���ݴ���!\n");

			}
			printf("��������˳�\n");
			getch();
			break;

		}
		case 5: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			if (DeAQueue(&Q)) {
				printf("�ɹ�\n");
			}
			else {
				printf("ʧ��\n");
			}
			printf("��������˳�\n");
			getch();
			break;
		}
		case 6: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			if (IsEmptyAQueue(&Q)) {
				printf("Ϊ��\n");
			}
			else
			{
				printf("��Ϊ��");
			}
			printf("��������˳�\n");
			getch();
			break;
		}
		case 7: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			if (IsEmptyAQueue(&Q)) {
				printf("����\n");
			}
			else
			{
				printf("δ��");
			}
			printf("��������˳�\n");
			getch();
			break;
		}
		case 8: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			TraverseAQueue(&Q, APrint);
			printf("��������˳�\n");
			getch();
			break;
		}
		case 9: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			type = datatype[Q.front];
			APrint(Q.data[Q.front]);
			printf("��������˳�\n");
			getch();
			break;

		}
		case 10: {
			if (Q.length == -1) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			printf("������ �� %d", LengthAQueue(&Q));
			printf("��������˳�\n");
			getch();
			break;
		}
		case 11: {

			return 0;
		}
		default:printf("���ݴ���!\n");
		}
		system("cls");
	}
	return 0;
}

void AView() {
	//A�Ľ���
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --���ɶ���\n\n");
	printf("\t\t\t\t\t\t   2 --���ٶ���\n\n");
	printf("\t\t\t\t\t\t   3 --��ն���\n\n");
	printf("\t\t\t\t\t\t   4 --��    ��\n\n");
	printf("\t\t\t\t\t\t   5 --��    ��\n\n");
	printf("\t\t\t\t\t\t   6 --�Ƿ�Ϊ��\n\n");
	printf("\t\t\t\t\t\t   7 --�Ƿ�Ϊ��\n\n");
	printf("\t\t\t\t\t\t   8 --��������\n\n");
	printf("\t\t\t\t\t\t   9 --��ͷԪ��\n\n");
	printf("\t\t\t\t\t\t   10 --��ȡ����\n\n");
	printf("\t\t\t\t\t\t   11--��    ��\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}


