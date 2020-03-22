#pragma once
#include"预处理定义.c"
#include <malloc.h>
stu* insert(stu*, stu);		//插入
stu* fcreateline(int );		//文件加载 0.废除 1.目前
stu* store(stu*, int);		//链表储存：0.废弃 1.目前

//按照学号与次数删除
stu* delete(stu* head, int num,int numDeal) {
	//head空检测
	if (head == NULL) {
		printf("删除时输入的头表是空的:117\n");
		return NULL;
	}	 	
	//文件加载
	stu* head0 = fcreateline(0);

	//准备变量
	stu* p = head, * q;

	//单个数据
	if (head->next == NULL) {
		if (head->num == num && head->numDeal == numDeal) {
			printf("链表仅有的元素被删除:118\n");
			insert(head0, *head);		//插入删除项
			store(head0,0);				//储存删除项
			printf("删除成功\n");
			return NULL;
		}
		else {
			printf("删除失败：没有符合条件的数据:119\n");
			return head;
		}
	}
	//多个数据
	while (p->num != num || p->numDeal != numDeal) {
		q = p;
		p = p->next;
		if (p == NULL) {
			printf("删除失败：没有符合条件的数据:120\n");
			return head;
		}
	}
	//头尾检测
	if (p == head) {
		insert(head0, *head);		//插入删除项
		store(head0, 0);			//储存删除项
		printf("删除成功\n");
		return head->next;
	}
	if (p->next == NULL) {
		q->next = NULL;
		insert(head0, *p);			//插入删除项
		store(head0, 0);			//储存删除项
		printf("删除成功\n");
		return head;
	}
	//正常中间情况
	q->next = p->next;
	insert(head0, *p);				//插入删除项
	store(head0, 0);				//储存删除项
	printf("删除成功\n");
	return head;
}


