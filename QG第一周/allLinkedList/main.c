#include<stdio.h>
#include<stdlib.h>
#include "../allLinkedList/allLinedList.h"


void mainView();
void view();
void duView();
int main() {
	//预创建二级指针
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	(*L) = NULL;
	

	/***************************
	*			逻辑
	****************************/
	char mainChoice;
	char choice;
	while (1) {
		mainView();

		mainChoice = getch();
		if (mainChoice == '3')
			break;

		system("cls");

		//main主界面判断
		switch (mainChoice)
		{
		case '1': {
			while (1) {
				view();

				choice = getch();
				if (choice == '4')
					break;

				system("cls");

				//主界面判断
				switch (choice) {
					//创建+录入
				case '1': aFunction(L); break;
					//反转+排序
				case '2': tFunction(L); break;
					//删除+摧毁
				case '3': dFunction(L); break;
				default:
					break;
				}

				system("cls");
			}
			DestroyList(L);
			break;
		}
		case '2': {
			while (1) {
				duView();

				choice = getch();
				if (choice == '4')
					break;

				system("cls");

				//主界面判断
				switch (choice) {
					//创建+录入
				case '1': aDuFunction(L); break;
					//反转+排序
				case '2': tDuFunction(L); break;
					//删除+摧毁
				case '3': dDuFunction(L); break;
				}

				system("cls");
			}
			DestroyList_DuL(L);
			break;
		}
		default:
			break;
		}
		
		system("cls");
	}



}

void mainView() {
	/***************************
	*			主界面
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
	printf("\t\t\t\t  1--单向链表操作     2--双向链表操作    3--退出\n\n");


	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void view() {
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
	printf("\t\t\t\t  1--创建+录入     2--反转+排序     3--删除+摧毁 \n");
	printf("\t\t\t\t  4--退出 \n\n");


	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}

void duView() {
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
	printf("\t\t\t\t  1--创建+录入     2--遍历     3--删除+摧毁 \n");
	printf("\t\t\t\t  4--退出 \n\n");


	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 66; i++)
		printf("*");
	printf("\n");
}
