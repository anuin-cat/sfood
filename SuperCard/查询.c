#include<stdio.h>

void searchInterface(void) {
	//上空地
	for (int i = 0; i < 12; i++)
		printf("\n");

	//上分界符 
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n\n");

	//目录
	printf("\t\t\t   1--按固定时间查询  2--按日期区间段查询  3--按交易金额查询\n\n\t\t\t   4--已删除记录查询（管理员才有此项功能)  5--返回主界面\n\n");

	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n");
}

