#pragma once
#include"预处理定义.c"
#include <malloc.h>
#include<time.h>
#include<stdio.h>
stu* fcreateline(int);		//文件加载 0.废除 1.目前



stu in() {
	int gettime(int n);			//获取当前时间参数为0，实验时日期加上参数值
	int gettimes(int num);		//获取最新的交易次数
	int getSumLeft(int num);	//获取最新的余额信息

	//输入数据读取
	stu p;
	while (1) {
		printf("请依次输入：1.学号，2.交易额，3.交易类型，4.交易地点（中间用空格隔开）\n");
		if (scanf("%d%d%d%s", &p.num, &p.sumDeal, &p.typeDeal, p.siteDeal) != 4) {
			printf("输入有误：116\n");
			continue;
		}
		else
			break;
	}
	//printf("%d,%d,%d,%s,%d", p.num, p.sumDeal, p.typeDeal, p.siteDeal,p.dateDeal);

	//自动生成数据读取
	p.dateDeal = gettime(0);					//交易日期
	p.dateIn = gettime(0);						//入账日期
	p.numDeal = gettimes(p.num)+1;				//交易次数
	p.sumLeft = getSumLeft(p.num)+p.sumDeal;	//交易余额
	return p;
}

//时间获取函数
int gettime(int n) {
	time_t timep;				//定义时间变量
	time(&timep);				//赋值秒数时间
	timep += n * 100000;
	struct tm* p = gmtime(&timep);	//得到标准时间
	int date;
	date = (p->tm_year + 1900) * 10000 + (p->tm_mon + 1) * 100 + (p->tm_mday);
	return date;
}

//交易次数获取
int gettimes(int num){
	stu* sort(stu * head, int n);	//排序 0学号 1日期 2金额 3次数 后加0为从小到达，加1从大到小
	stu* searchnum(stu*, int);		//学号搜索

	//现有链表读取
	stu* head;
	head = fcreateline(1);
	if (head == NULL) {
		printf("数据获取失败：114\n");
		return 0;
	}
	
	//单个学号搜索
	head = searchnum(head, num);
	if (head == NULL) {
		printf("尚无此人数据，重新加入123\n");
		return 1;
	}
	//按次数排序，从大到小
	sort(head, 31);
	return head->numDeal;
}

//交易余额获取
int getSumLeft(int num) {
	stu* sort(stu * head, int n);	//排序 0学号 1日期 2金额 3次数 后加0为从小到达，加1从大到小
	stu* searchnum(stu*, int);		//学号搜索

	//现有链表读取
	stu* head;
	head = fcreateline(1);
	if (head == NULL) {
		printf("数据获取失败：115\n");
		return 0;
	}

	//单个学号搜索
	head = searchnum(head, num);
	if (head == NULL) {
		printf("尚无此人数据，重新加入122\n");
		return 0;
	}
	//按次数排序，从大到小
	sort(head, 31);
	return head->sumLeft;
}