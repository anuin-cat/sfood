#include<stdio.h>
#include<stdlib.h>
#include"../BTree/BinaryTree.h"

//操作结果：构造空二叉树T
Status InitBiTree(BiTree* T) {
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = '#';
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return SUCEESS;
};



//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status DestroyBiTree(BiTree T) {
	//摧毁左子树
	if (T->lchild != NULL) {
		DestroyBiTree(T->lchild);
	}
	//摧毁右子树
	if (T->rchild != NULL) {
		DestroyBiTree(T->rchild);
	}
	//释放本根
	free(T);
	return SUCEESS;

};



//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T
Status CreateBiTree(BiTree T, char* definition) {
	if (T->data == '#') {
		T->data = *definition;
		T->lchild = (BiTree)malloc(sizeof(BiTNode));
		T->rchild = (BiTree)malloc(sizeof(BiTNode));
		T->lchild->data = '#';
		T->rchild->data = '#';
		T->lchild->lchild = NULL;
		T->lchild->rchild = NULL;
		T->rchild->lchild = NULL;
		T->rchild->rchild = NULL;
	}
	else
	{
		CreateBiTree(rand()%10 >= 5 ? T->lchild : T->rchild,definition);
	}
};



//以下部分函数定义未指定参数类型
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
Status visit(BiTree T) {
	if (T == NULL) {
		return ERROR;
	}
	printf("%c ", T->data);
	return SUCEESS;
}


//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status PreOrderTraverse(BiTree T, Status(*visit)(BiTree e)) {
	if (T == NULL||T->data == '!') {
		return ERROR;
	}
	else
	{
		if (visit(T) == ERROR) 
			return ERROR;
		PreOrderTraverse(T->lchild, visit);
		PreOrderTraverse(T->rchild, visit);
	}
};


//中序遍历
Status InOrderTraverse(BiTree T, Status(*visit)(BiTree e)) {
	if (T == NULL || T->data == '!') {
		return ERROR;
	}
	else
	{
		InOrderTraverse(T->lchild, visit);
		visit(T);
		InOrderTraverse(T->rchild, visit);
	}
};

//后序遍历
Status PostOrderTraverse(BiTree T, Status(*visit)(BiTree e)) {
	if (T == NULL || T->data == '!') {
		return ERROR;
	}
	else
	{	
		PostOrderTraverse(T->lchild, visit);
		PostOrderTraverse(T->rchild, visit);
		visit(T);
	}
};	

//层序遍历
Status LevelOrderTraverse(BiTree T, Status(*visit)(BiTree e)) {
	if (T) {
		BiTree b[1000];
		b[0] = T;
		int first = 0;
		int rear = 1;
		while (first < rear) {
			visit(b[first]);
			if (b[first]->lchild)
			{
				b[rear++] = b[first]->lchild;
			}
			if (b[first]->rchild) {
				b[rear++] = b[first]->rchild;
			}
			first++;
		}
	}
};	



//构造出的二叉树求值
int Value(BiTNode T) {

};			
/*
提示：可在结点结构体中设置个Tag值标志数字与操作符来构造二叉树，
可根据需要自行增加操作.
*/