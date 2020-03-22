#include<stdio.h>

void statisticsInterface() {
	//上空地
	for (int i = 0; i < 12; i++)
		printf("\n");

	//上分界符 
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n\n");

	//目录
	printf("\t\t\t   1--统计一段时间内的消费总金额\n\n");

	//下分界符
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n");
}