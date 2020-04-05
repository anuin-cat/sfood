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
				printf("栈已初始化！");
			}
			else
			{
				printf("请输入栈的长度：");
				scanf("%d", &length);
				gets(a);
				if (initStack(s, length) == ERROR) {
					printf("初始化失败！\n");
				}
				else
				{
					printf("初始化成功！\n");
				}

			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '2': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (isEmptyStack(s) == SUCCESS) {
					printf("栈为空！\n");
				}
				else
				{
					printf("栈不为空！\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '3': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (getTopStack(s, e) == ERROR) {
					printf("获取失败！\n");
				}
				else
				{
					printf("栈顶元素是：%d", *e);
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '4': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (clearStack == SUCCESS) {
					printf("清除成功！\n");
				}
				else
				{
					printf("清除失败！\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '5': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (destroyStack(s) == SUCCESS) {
					printf("销毁成功！\n");
				}
				else
				{
					printf("销毁失败！\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '6': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (stackLength(s, e) == SUCCESS) {
					printf("栈的长度是：%d\n", *e);
				}
				else
				{
					printf("检测失败！\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '7': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				printf("请输入入栈的数据：");
				scanf("%d", e);
				printf("\n");
				gets(a);
				if (pushStack(s, *e) == SUCCESS) {
					printf("入栈成功！\n");
				}
				else
				{
					printf("入栈失败！\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		case '8': {
			if (s->elem == NULL) {
				printf("栈未初始化，功能禁用!\n");
			}
			else
			{
				if (popStack(s, e) == SUCCESS) {
					printf("出栈数据是：%d\n", *e);
				}
				else
				{
					printf("出栈失败\n");
				}
			}
			printf("按任意键退出！\n");
			getch();
			system("cls");
		}break;
		default:
			break;
		}
	}

	return 0;
}

//主界面
void view0() {
	printf("\n\n\n");

	//第一行
	for (int i = 0; i < 120; i++) {
		printf("*");
	}

	//第二行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第三行
	for (int i = 0; i < 44; i++) {
		printf("*");
	}
	printf("数 据 结 构 之 链 栈 程 序 设 计");
	for (int i = 0; i < 44; i++) {
		printf("*");
	}

	//第四行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第五行
	for (int i = 0; i < 44; i++) {
		printf("*");
	}
	printf("作者：牛增豪(3119004928) 计科5班");
	for (int i = 0; i < 44; i++) {
		printf("*");
	}

	//第六行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第七行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("1.  初始化栈                  ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第八行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第九行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("2.  判断栈是否为空            ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第十行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第十一行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("3.  得到栈顶元素              ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第十二行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第十三行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("4.  清空栈                    ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第十四行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第十五行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("5.  销毁栈                    ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第十六行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第十七行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("6.  检测栈长度                ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第十八行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第十九行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("7.  入栈                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第二十行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第二十一行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("8.  出栈                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第二十二行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第二十三行
	printf("*");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("9.  退出                      ");
	for (int i = 0; i < 44; i++) {
		printf(" ");
	}
	printf("*");

	//第二十四行
	printf("\n*");
	for (int i = 0; i < 118; i++) {
		printf(" ");
	}
	printf("*\n");

	//第二十五行
	for (int i = 0; i < 120; i++) {
		printf("*");
	}

}