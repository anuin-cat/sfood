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
			printf("创建成功\n");
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 2: {
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			DestoryLQueue(&Q);
			printf("摧毁成功\n");
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 3: {
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			ClearLQueue(&Q);
			printf("清除成功\n");
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 4: {
			if (Q.front == NULL) {
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
				datatype = 'i';
				if (EnLQueue(&Q, &a)) {
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
				datatype = 'c';
				if (EnLQueue(&Q, &c)) {
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
				datatype = 'd';
				if (EnLQueue(&Q, &d)) {

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
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			if (DeLQueue(&Q)) {
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
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			if (IsEmptyLQueue(&Q)) {
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
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			printf("队列长度： %d", LengthLQueue(&Q));
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 8: {
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			TraverseLQueue(&Q, LPrint);
			printf("按任意键退出\n");
			getch();
			break;
		}
		case 9: {
			if (Q.front == NULL) {
				printf("队列被摧毁，无法操作！\n");
				break;
			}
			datatype = Q.front->next->type;
			LPrint(Q.front->next->data);

			printf("按任意键退出\n");
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
	//L的界面
	printf("\n\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --生成队列\n\n");
	printf("\t\t\t\t\t\t   2 --销毁队列\n\n");
	printf("\t\t\t\t\t\t   3 --清空队列\n\n");
	printf("\t\t\t\t\t\t   4 --入    队\n\n");
	printf("\t\t\t\t\t\t   5 --出    队\n\n");
	printf("\t\t\t\t\t\t   6 --是否为空\n\n");
	printf("\t\t\t\t\t\t   7 --获取长度\n\n");
	printf("\t\t\t\t\t\t   8 --遍历队列\n\n");
	printf("\t\t\t\t\t\t   9 --查头元素\n\n");
	printf("\t\t\t\t\t\t   10--退    出\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}
