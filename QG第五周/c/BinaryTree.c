#include<stdio.h>
#include<stdlib.h>
#include"../BTree/BinaryTree.h"

//�������������ն�����T
Status InitBiTree(BiTree* T) {
	(*T) = (BiTree)malloc(sizeof(BiTNode));
	(*T)->data = '#';
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
	return SUCEESS;
};



//��ʼ������������T����
//����������ݻٶ�����T
Status DestroyBiTree(BiTree T) {
	//�ݻ�������
	if (T->lchild != NULL) {
		DestroyBiTree(T->lchild);
	}
	//�ݻ�������
	if (T->rchild != NULL) {
		DestroyBiTree(T->rchild);
	}
	//�ͷű���
	free(T);
	return SUCEESS;

};



//��ʼ������ definition�����������Ķ���
//�����������definition���������T
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



//���²��ֺ�������δָ����������
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
Status visit(BiTree T) {
	if (T == NULL) {
		return ERROR;
	}
	printf("%c ", T->data);
	return SUCEESS;
}


//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
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


//�������
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

//�������
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

//�������
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



//������Ķ�������ֵ
int Value(BiTNode T) {

};			
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/