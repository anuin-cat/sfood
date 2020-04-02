#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"

void tView(){
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
	printf("\t\t\t\t  1--遍历链表     2--查询结点     3--完全反转链表  \n");
	printf("\t\t\t\t  4--是否是环     5--中间结点     6--奇偶反转链表  \n");
	printf("\t\t\t\t  7--退出    \n\n");


	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void tFunction(LinkedList *L) {

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
		tView();

		choice = getch();
		if (choice == '7')
			break;

		system("cls");

		switch (choice)
		{
			//遍历链表
		case '1': {
			TraverseList(*L, pri);
			break;
		}
			//查询结点
		case '2': {
			printf("请输入需要查询的结点位置（数字）：\n");
			scanf_s("%d", &position,1);

			if (SearchList(*L, position) == 1) {
				printf("结点存在\n");
			}
			else
			{
				printf("结点不存在\n");
			}
			break;
		}
			//完全反转链表
		case '3': {
			if (ReverseList(L) == 1) {
				printf("反转成功\n");
			}
			else
			{
				printf("反转失败\n");
			}
			break;
		}
			//是否是环
		case '4': {
			if (IsLoopList(*L) == 1) {
				printf("是环\n");
			}
			else
			{
				printf("不是环\n");
			}
			break;
		}
			//中间结点
		case '5': {
			LinkedList A = FindMidNode(L);
			if (A == NULL) {
				printf("链表为空，无法查找");
			}
			else
			{
				printf("中间节点的数值是：%d\n中间节点的地址是%p\n", A->data, A);
			}
			break;
		}
			//奇偶反转链表
		case '6': {
			LinkedList A = ReverseEvenList(L);
			if (A == NULL) {
				printf("链表为空，无法反转\n");
			}
			else
			{
				printf("反转成功\n");
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