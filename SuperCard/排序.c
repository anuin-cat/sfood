#include<stdio.h>

void sortInterface(void) {
	//上空地
	for (int i = 0; i < 12; i++)
		printf("\n");

	//上分界符 
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n\n");

	//目录
	printf("\t\t\t   1--交易日期  2--交易金额  3--交易次数  0--返回主界面\n\n\t\t\t   数字加上3是逆序\n\n");

	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n");
}