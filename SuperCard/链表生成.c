#pragma once
#include"预处理定义.c"
#include<time.h>
#include <malloc.h>

stu* createline(int n) {
	int gettime(int n);		//日期获取函数

	stu* head, * p, * q;
	if (n <= 0)	return NULL;
	
	for (int i = 0; i < n; i++)
	{
		p = (stu*)malloc(sizeof(stu));

		//产生随机数
		srand((i*88+5)/3);
		int a = rand()%10;

		//数据域随机赋值
		p->num= 9004928+a;				//学号

		p->dateDeal = gettime(a*3%10);	//交易日期
		p->dateIn = gettime(a*3%10);	//入账日期

		p->sumDeal = a * 2 + 6 + i;		//交易额
		p->sumLeft = 1;					//交易后余额

		p->typeDeal = a % 3+1;			//交易类型

		p->numDeal = 1+i%10;			//交易次数
		p->siteDeal[0] = 'G';			//交易地点
		p->siteDeal[1] = '\0';


		//结点连接
		p->next = NULL;

		if (i == 0)
			head = p;
		else
			q->next = p;
		q = p;
	}

	return head;
}