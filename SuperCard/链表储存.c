#pragma once
#include"预处理定义.c"
#include<stdlib.h>
#include<stdio.h>


int store(stu* head, int s) {
	FILE* fp;
	errno_t err;		//异常检测
	switch (s)
	{
	case 1: {err = fopen_s(&fp, "通用链表.txt", "w+"); }break;
	case 0: {err = fopen_s(&fp, "废弃数据.txt", "w+"); }break;
	default: break;
	}
	if (err != NULL||fp==NULL)	//文件打开失败
	{
		printf("储存时文件打开失败\n");
		return 0;
	}
	while (head != NULL) {
		fprintf(fp,"%d,%d,%d,%d,%d,%d,%d,%s\n",head->num,head->dateDeal,head->dateIn,head->sumDeal,head->sumLeft,head->typeDeal,head->numDeal,head->siteDeal);
		head = head->next;
	}
	if (fclose(fp)) {
		printf("关闭失败\n");
		exit(0);
	}
}