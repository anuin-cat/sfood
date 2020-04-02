#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void tDuView() {
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
	printf("\t\t\t\t  1--遍历链表    2--退出\n\n");

	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void tDuFunction(DuLinkedList* L) {

	if (L == NULL || (*L) == NULL) {
		printf("链表未创建，功能禁用！！！\n");
		printf("按任意键返回。。。\n");
		getch();
		return;
	}


	char choice;
	int position;

	//次界面判断
	while (1) {
		tDuView();

		choice = getch();
		if (choice == '2')
			break;

		system("cls");

		switch (choice)
		{
			//遍历链表
		case '1': {
			TraverseList_DuL(*L, duPri);
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