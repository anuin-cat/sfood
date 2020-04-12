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
				printf("队列已被创建，无法操作！\n");
				break;
			}
			InitAQueue(&Q);
			printf("创建成功\n");
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 2: {
			if (Q.length==-1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			DestoryAQueue(&Q);
			printf("摧毁成功\n");
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 3: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			ClearAQueue(&Q);
			printf("清除成功\n");
			printf("按任意键退出\n");
			getch();
			break;

		}
		case 4: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			printf("您想要输入何类型数据?\n");
			printf("1.int  2.char  3.double \n");
			printf("选择:");
			scanf("%d", &t);
			if (t != 1 && t != 2 && t != 3) {
				printf("输入数据错误！\n");
				printf("按任意键退出\n");
				getch();
				break;
			}
			printf("输入数据:");

			switch (t)
			{
			case 1: {

				int a;
				scanf("%d", &a);
				datatype[Q.rear] = 'i';
				if (EnAQueue(&Q, &a)) {
					printf("成功\n");
				}
				else {
					printf("失败\n");
				}
				break;

			}

			case 2: {

				getchar();
				c = getchar();
				datatype[Q.rear] = 'c';
				if (EnAQueue(&Q, &c)) {
					printf("成功\n");
				}
				else {
					printf("失败\n");
				}
				break;

			}

			case 3: {

				double d;
				printf("enter (eg:3.89):");
				scanf("%f", &d);
				datatype[Q.rear] = 'd';
				if (EnAQueue(&Q, &d)) {

					printf("成功\n");
				}
				else {
					printf("失败\n");
				}
				break;

			}

			default:printf("数据错误!\n");

			}
			printf("按任意键退出\n");
			getch();
			break;

		}
		case 5: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			if (DeAQueue(&Q)) {
				printf("成功\n");
			}
			else {
				printf("失败\n");
			}
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 6: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			if (IsEmptyAQueue(&Q)) {
				printf("为空\n");
			}
			else
			{
				printf("不为空");
			}
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 7: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			if (IsEmptyAQueue(&Q)) {
				printf("已满\n");
			}
			else
			{
				printf("未满");
			}
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 8: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			TraverseAQueue(&Q, APrint);
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 9: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			type = datatype[Q.front];
			APrint(Q.data[Q.front]);
			printf("按任意键退出\n");
			getch();
			break;

		}
		case 10: {
			if (Q.length == -1) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			printf("长度是 ： %d", LengthAQueue(&Q));
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 11: {

			return 0;
		}
		default:printf("数据错误!\n");
		}
		system("cls");
	}
	return 0;
}

void AView() {
	//A的界面
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --生成队列\n\n");
	printf("\t\t\t\t\t\t   2 --销毁队列\n\n");
	printf("\t\t\t\t\t\t   3 --清空队列\n\n");
	printf("\t\t\t\t\t\t   4 --入    队\n\n");
	printf("\t\t\t\t\t\t   5 --出    队\n\n");
	printf("\t\t\t\t\t\t   6 --是否为空\n\n");
	printf("\t\t\t\t\t\t   7 --是否为满\n\n");
	printf("\t\t\t\t\t\t   8 --遍历队列\n\n");
	printf("\t\t\t\t\t\t   9 --查头元素\n\n");
	printf("\t\t\t\t\t\t   10 --获取长度\n\n");
	printf("\t\t\t\t\t\t   11--退    出\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}


