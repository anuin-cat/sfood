#include "four.h"

int Priority(char ch)	//判断操作符优先级
{
	switch (ch)
	{
	case '(':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	default:
		return 0;
	}
}

int main()
{
	Stack* s_num, * s_opt;
	char opt[128] = { 0 };
	int i = 0, tmp = 0,state;
	int num1, num2;
	if ((InitStack(&s_num) == FAILURE) || (InitStack(&s_opt) == FAILURE))
	{
		printf("Init Failure !\n");
	}
	while (1)
	{
		i = 0;
		tmp = 0;
		state = 0;
		printf("输入四则表达式：");
		scanf("%s", opt);
		//判断多符号
		if (Priority(opt[0]) == 1 || Priority(opt[0]) == 2) {
			printf("输入表达式有错误!\n");
			state = 1;
			continue;
		}
		for (int a = 0;opt[a]!='\0';a++) {
			if ((Priority(opt[a]) == 1 || Priority(opt[a]) == 2) && (Priority(opt[a + 1]) == 1 || Priority(opt[a + 1]) == 2)) {
				printf("输入表达式有错误!\n");
				state = 1;
				continue;
			}
			if (opt[a + 1] == '\0') {
				if (Priority(opt[a]) == 1 || Priority(opt[a]) == 2) {
					printf("输入的表达式有错误！\n");
					state = 1;
					continue;
				}
			}
		}
		if (state == 1) {
			continue;
		}


		while (opt[i] != '\0' || EmptyStack(s_opt) != TRUE)	//表达式没结束 或 操作符不为空
		{
			if (opt[i] >= '0' && opt[i] <= '9')	//判断表达式是否为数字，数字直接进栈
			{
				tmp = tmp * 10 + opt[i] - '0';	//后一个为数字时 前一个乘以10 加上后一个
				i++;
				if (opt[i] > '9' || opt[i] < '0')	//判断后一个是否为操作符
				{
					Push(s_num, tmp);	//操作数进栈
					tmp = 0;	//清零，用以记录下一个操作数
				}
			}
			else	//表达式为操作符
			{
				//	1、操作符出栈不计算
				if (GetTop(s_opt) == '(' && opt[i] == ')')	//直接出栈，不计算，栈顶为'(' ，表达式为')'
				{
					Pop(s_opt);	//括号直接出栈
					i++;
					continue;	//继续下一次循环
				}
				//	2、操作符进栈
				if ((EmptyStack(s_opt) == TRUE) 	//操作符栈为空
					|| (Priority(opt[i]) > Priority(GetTop(s_opt))) 	//表达式操作符优先级 > 栈顶操作符优先级
					|| (GetTop(s_opt) == '(' && opt[i] != ')')) 	//栈顶为'('  && 表达式当前值不为 ')'
				{
					Push(s_opt, opt[i]);	//操作符进栈
					i++;
					continue;	//继续下一次循环
				}
				//	2、操作符出栈计算	
				if (Priority(opt[i]) <= Priority(GetTop(s_opt)) 	//表达式操作符优先级 <= 栈顶操作符优先级
					|| (opt[i] == '0' && EmptyStack(s_opt) != TRUE) 	//表达式为空 && 操作符栈不为空
					|| opt[i] == ')')	//表达式为')'
				{
					num1 = Pop(s_num);	//数字栈顶出栈
					num2 = Pop(s_num);	//数字栈第二个数字出栈
					switch (Pop(s_opt))	//后出的数字在前
					{
					case '+':
						Push(s_num, num2 + num1);
						break;
					case '-':
						Push(s_num, num2 - num1);
						break;
					case '*':
						Push(s_num, num2 * num1);
						break;
					case '/':
						Push(s_num, num2 / num1);
						break;
					}	//A
						// i++;			//在操作符进栈时已经自加
						// continue;
				}
			}
		}

		printf("Result = %d\n", GetTop(s_num));
	}
	return 0;
}
