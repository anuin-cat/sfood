#pragma once
#include"预处理定义.c"
#include <malloc.h>
stu* insert(stu* head, stu s);

stu* inserts(stu* head, stu s[],int n) {
	for (int i = 0; i < n; i++) {
		head=insert(head, s[i]);
	}
	return head;
}