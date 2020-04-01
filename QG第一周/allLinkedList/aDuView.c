#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void aDuView() {
	/***************************
	*			界面
	****************************/
	//上空地
	for (int i = 0; i < 12; i++)
		printf("\n");

	//上分界符 
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n\n");

	//目录
	printf("\t\t\t\t  1--创建空链表     2--插入结点前    3--插入结点后\n");
	printf("\t\t\t\t  4--退出\n\n");


	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
	
}

void aDuFunction(DuLinkedList* L) {
	char choice;
	int position;

	//次界面判断
	while (1) {
		aDuView();

		choice = getch();
		if (choice == '4')
			break;

		system("cls");

		switch (choice)
		{
			//创建空链表
		case '1': {
			if (InitList_DuL(L) == 1) {
				printf("创建成功\n");
			}
			else
			{
				printf("创建失败\n");
			}
			break;
		}
			//插入结点前
		case '2': {
			int A;
			char s[20];
			if (L == NULL || (*L) == NULL) {
				printf("头节点未创建!\n");
				break;
			}
			else
			{
				printf("请输入插入节点的(数字)值：\n");

				if (scanf("%d", &A) == 1) {
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
					q->data = A;

					if (InsertBeforeList_DuL((*L)->next, q) == 1) {
						printf("插入成功\n");
					}
					else
					{
						printf("插入失败\n");
					}
				}
				else
				{
					printf("输入的不是数字！\n");
					gets_s(s, 20);
				};
				break;
			}
		}
			//插入结点后
		case '3': {
			int A;
			char s[20];
			if (L == NULL || (*L) == NULL) {
				printf("头节点未创建!\n");
				break;
			}
			else
			{
				printf("请输入插入节点的(数字)值：\n");

				if (scanf("%d", &A) == 1) {
					DuLinkedList q = (DuLinkedList)malloc(sizeof(DuLNode));
					q->data = A;

					if (InsertAfterList_DuL(*L, q) == 1) {
						printf("插入成功\n");
					}
					else
					{
						printf("插入失败\n");
					}
				}
				else
				{
					printf("输入的不是数字！\n");
					gets_s(s, 20);
				};
				break;
			}
		}
		default:
			break;
		}

		printf("\n按任意键退出......");
		getch();

		system("cls");
	}
}