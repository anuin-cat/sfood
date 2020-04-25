#include<stdio.h>
#include<stdlib.h>
#include"../BTree/BinaryTree.h"

void view();
void ent() {
	printf("\n");
}
int check(BiTree T) {
	if (T == NULL || T->data == '!') {
		printf("树未创建，不能操作!!");
		return 1;
	}
	return 0;
}

int main() {
	//创建并初始化
	BiTree* T0 = (BiTree*)malloc(sizeof(BiTree));//= (BiTree)malloc(sizeof(BiTNode));
	BiTree T = *T0;
	T = NULL;

	char c;
	char data;
	char a[20];

	while (1) {
		view();
		c = getch();
		switch (c)
		{
		case '1':
			InitBiTree(&T);
			if (T == NULL)
				printf("!!!");
			break;

		case '2':
			if (check(T))
				break;
			DestroyBiTree(T);
			T = NULL;
			break;
		case '3': {
			if (check(T))
				break;
			printf("请输入需要添加的数据：");
			scanf("%c", &data);
			gets(a);
			CreateBiTree(T, &data);
			break;
		}
		case '4':
			if (check(T))
				break;
			PreOrderTraverse(T, visit);
			break;

		case '5':
			if (check(T))
				break;
			InOrderTraverse(T, visit); 
			break;

		case '6':
			if (check(T))
				break;
			PostOrderTraverse(T, visit); 
			break;

		case '7':
			if (check(T))
				break;
			LevelOrderTraverse(T, visit); 
			break;

		default:
			break;
		}
		if (c == '8')
			break;
		ent();
		system("pause");
		system("cls");
	}
}

void view() {
	//L的界面
	printf("\n\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --构造二叉树\n\n");
	printf("\t\t\t\t\t\t   2 --销毁二叉树\n\n");
	printf("\t\t\t\t\t\t   3 --添加结点\n\n");
	printf("\t\t\t\t\t\t   4 --先序遍历\n\n");
	printf("\t\t\t\t\t\t   5 --中序遍历\n\n");
	printf("\t\t\t\t\t\t   6 --后序遍历\n\n");
	printf("\t\t\t\t\t\t   7 --层序遍历\n\n");
	printf("\t\t\t\t\t\t   8 --退出程序\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}