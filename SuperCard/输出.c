#pragma once
#include"预处理定义.c"
#include <malloc.h>

//顺序输出 学号+交易次数
void out(stu *head,int n) {
	printf("\n----------out----------\n");
	printf("学号      消费日期  入账日期  交易额    交易余额  交易类型  交易次数  交易地点  \n");
	for (;;)
	{
		if (head != NULL) {
			printf("%-9d %-9d %-9d %-9d %-9d %-9d %-9d %-s\n", head->num, head->dateDeal, head->dateIn, head->sumDeal, head->sumLeft, head->typeDeal, head->numDeal, head->siteDeal);
			head = head->next;
		}
		else
			break;
	}
	printf("-----------------------\n\n");
}