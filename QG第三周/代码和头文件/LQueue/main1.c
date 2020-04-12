#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

void LView();

int main() {
	int choice, i;
	LQueue Q;
	Q.front = NULL;
	Q.rear = NULL;
	Q.length = 0;
	int t;
	void* e = NULL;
	char c;


	while (1) {
		LView();
		printf("\nYour choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			InitLQueue(&Q);
			printf("�����ɹ�\n");
			printf("��������˳�\n");
			getch();
			break;
		}
		case 2: {
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			DestoryLQueue(&Q);
			printf("�ݻٳɹ�\n");
			printf("��������˳�\n");
			getch();
			break;
		}
		case 3: {
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			ClearLQueue(&Q);
			printf("����ɹ�\n");
			printf("��������˳�\n");
			getch();
			break;
		}
		case 4: {
			if (Q.front == NULL) {
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
				datatype = 'i';
				if (EnLQueue(&Q, &a)) {
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
				datatype = 'c';
				if (EnLQueue(&Q, &c)) {
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
				datatype = 'd';
				if (EnLQueue(&Q, &d)) {

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
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			if (DeLQueue(&Q)) {
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
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			if (IsEmptyLQueue(&Q)) {
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
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			printf("���г��ȣ� %d", LengthLQueue(&Q));
			printf("��������˳�\n");
			getch();
			break;
		}
		case 8: {
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			TraverseLQueue(&Q, LPrint);
			printf("��������˳�\n");
			getch();
			break;
		}
		case 9: {
			if (Q.front == NULL) {
				printf("���б��ݻ٣��޷�������\n");
				break;
			}
			datatype = Q.front->next->type;
			LPrint(Q.front->next->data);

			printf("��������˳�\n");
			getch();

			break;

		}
		case 10: {

			return 0;
		}
		default:printf("data error!\n");
		}

		system("cls");
	}
	return 0;
}

void LView() {
	//L�Ľ���
	printf("\n\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --���ɶ���\n\n");
	printf("\t\t\t\t\t\t   2 --���ٶ���\n\n");
	printf("\t\t\t\t\t\t   3 --��ն���\n\n");
	printf("\t\t\t\t\t\t   4 --��    ��\n\n");
	printf("\t\t\t\t\t\t   5 --��    ��\n\n");
	printf("\t\t\t\t\t\t   6 --�Ƿ�Ϊ��\n\n");
	printf("\t\t\t\t\t\t   7 --��ȡ����\n\n");
	printf("\t\t\t\t\t\t   8 --��������\n\n");
	printf("\t\t\t\t\t\t   9 --��ͷԪ��\n\n");
	printf("\t\t\t\t\t\t   10--��    ��\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}
