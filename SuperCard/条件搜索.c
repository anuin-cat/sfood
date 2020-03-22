#pragma once
#include"预处理定义.c"
#include <malloc.h>
#include<stdlib.h>
#include<stdio.h>

//学号查询-----学号
stu* searchnum(stu *head,int num) {

	stu* sort(stu * head, int n);//排序 0学号 1日期 2金额 3次数 后加0为从小到大，加1从大到小


	//链表排序
	stu*p;
	sort(head, 00);

	//数据搜索
	if (head == NULL){
		printf("搜索失败，此人不存在\n");
		return NULL;
	}
		
	while (head->num != num) {
		head = head->next;
		if (head == NULL) {
			printf("搜索失败，此人不存在\n");
			return NULL;
		}
	}

	p = head;
	while (p->next!=NULL) {
		if (p->next->num != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}		//学号查找----参数为链表+学生学号

//日期查询-----参数：两个8位日期
stu* searchDateDeal(stu* head, int date1, int date2) {
	
	stu* sort(stu * head, int n);//排序 0学号 1日期 2金额 3次数 后加0为从小到大，加1从大到小

	//数据处理
	if (date1 < 10000000 || date1>99999999 || date2 < 10000000 || date2>99999999) {
		printf("数据输入有误\n");
		return NULL;
	}
	int swap;
	if (date1 < date2) {
		swap = date1;
		date1 = date2;
		date2 = swap;
	}

	//排序日期并搜索
	sort(head, 11);
	stu* p;
	if (head == NULL) {
		printf("搜索失败，此人不存在\n");
		return NULL;
	}

	while (head->dateDeal > date1) {
		head = head->next;
		if (head == NULL) {
			printf("搜索失败，此人不存在\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->dateDeal < date2)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}	//日期查找----参数必须8位数,否则返回空指针

//交易额查询-----金额
stu* searchSumDeal(stu* head, int num) {

	stu* sort(stu * head, int n);//排序 0学号 1日期 2金额 3次数 后加0为从小到大，加1从大到小

	//链表排序
	stu* p;
	sort(head, 20);

	//数据搜索
	if (head == NULL) {
		printf("搜索失败，此人不存在\n");
		return NULL;
	}

	while (head->sumDeal != num) {
		head = head->next;
		if (head == NULL) {
			printf("搜索失败，此人不存在\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->sumDeal != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}	  

//类型查询----参数一个类型代码
stu* searchTypeDeal(stu* head, int num) {

	stu* sort(stu * head, int n);//排序 0学号 1日期 2金额 3次数 后加0为从小到大，加1从大到小


	//链表排序
	stu* p;
	sort(head, 40);

	//数据搜索
	if (head == NULL) {
		printf("搜索失败，此人不存在\n");
		return NULL;
	}

	while (head->typeDeal != num) {
		head = head->next;
		if (head == NULL) {
			printf("搜索失败，此人不存在\n");
			return NULL;
		}
	}

	p = head;
	while (p->next != NULL) {
		if (p->next->typeDeal != num)
			break;
		p = p->next;
	}
	p->next = NULL;

	return head;
}