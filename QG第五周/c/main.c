#include<stdio.h>
#include<stdlib.h>
#include"../BTree/BinaryTree.h"

void view();
void ent() {
	printf("\n");
}
int check(BiTree T) {
	if (T == NULL || T->data == '!') {
		printf("��δ���������ܲ���!!");
		return 1;
	}
	return 0;
}

int main() {
	//��������ʼ��
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
			printf("��������Ҫ��ӵ����ݣ�");
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
	//L�Ľ���
	printf("\n\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n\t\t\t\t\t\t   1 --���������\n\n");
	printf("\t\t\t\t\t\t   2 --���ٶ�����\n\n");
	printf("\t\t\t\t\t\t   3 --��ӽ��\n\n");
	printf("\t\t\t\t\t\t   4 --�������\n\n");
	printf("\t\t\t\t\t\t   5 --�������\n\n");
	printf("\t\t\t\t\t\t   6 --�������\n\n");
	printf("\t\t\t\t\t\t   7 --�������\n\n");
	printf("\t\t\t\t\t\t   8 --�˳�����\n\n");
	printf("\t\t\t   ");
	for (int i = 0; i < 66; i++) {
		printf("*");
	}
	printf("\n");
}