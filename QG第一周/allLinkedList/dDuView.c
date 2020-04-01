#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void dDuView() {
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
	printf("\t\t\t\t  1--摧毁链表    2--删除链表    3--退出\n\n");

	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}


void dDuFunction(DuLinkedList* L) {
	char choice;
	int position;

	//次界面判断
	while (1) {
		dDuView();

		choice = getch();
		if (choice == '3')
			break;

		system("cls");

		switch (choice)
		{
			//摧毁链表
		case '1': {
			TraverseList_DuL(*L, duPri);
			break;
		}
			//删除结点
		case '2': {
			int* e = (int*)malloc(sizeof(int));
			if (DeleteList_DuL((*L), e) == 1) {
				printf("删除成功\n");
				printf("被删除的结点数值：%d", *e);
			}
			else
			{
				printf("删除失败\n");
			}
			break;
		}
		default:
			break;
		}

		printf("\n按任意键退出......");
		getch();

		system("cls");
	}
}