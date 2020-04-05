#include "four.h"

int Priority(char ch)	//�жϲ��������ȼ�
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
		printf("����������ʽ��");
		scanf("%s", opt);
		//�ж϶����
		if (Priority(opt[0]) == 1 || Priority(opt[0]) == 2) {
			printf("������ʽ�д���!\n");
			state = 1;
			continue;
		}
		for (int a = 0;opt[a]!='\0';a++) {
			if ((Priority(opt[a]) == 1 || Priority(opt[a]) == 2) && (Priority(opt[a + 1]) == 1 || Priority(opt[a + 1]) == 2)) {
				printf("������ʽ�д���!\n");
				state = 1;
				continue;
			}
			if (opt[a + 1] == '\0') {
				if (Priority(opt[a]) == 1 || Priority(opt[a]) == 2) {
					printf("����ı��ʽ�д���\n");
					state = 1;
					continue;
				}
			}
		}
		if (state == 1) {
			continue;
		}


		while (opt[i] != '\0' || EmptyStack(s_opt) != TRUE)	//���ʽû���� �� ��������Ϊ��
		{
			if (opt[i] >= '0' && opt[i] <= '9')	//�жϱ��ʽ�Ƿ�Ϊ���֣�����ֱ�ӽ�ջ
			{
				tmp = tmp * 10 + opt[i] - '0';	//��һ��Ϊ����ʱ ǰһ������10 ���Ϻ�һ��
				i++;
				if (opt[i] > '9' || opt[i] < '0')	//�жϺ�һ���Ƿ�Ϊ������
				{
					Push(s_num, tmp);	//��������ջ
					tmp = 0;	//���㣬���Լ�¼��һ��������
				}
			}
			else	//���ʽΪ������
			{
				//	1����������ջ������
				if (GetTop(s_opt) == '(' && opt[i] == ')')	//ֱ�ӳ�ջ�������㣬ջ��Ϊ'(' �����ʽΪ')'
				{
					Pop(s_opt);	//����ֱ�ӳ�ջ
					i++;
					continue;	//������һ��ѭ��
				}
				//	2����������ջ
				if ((EmptyStack(s_opt) == TRUE) 	//������ջΪ��
					|| (Priority(opt[i]) > Priority(GetTop(s_opt))) 	//���ʽ���������ȼ� > ջ�����������ȼ�
					|| (GetTop(s_opt) == '(' && opt[i] != ')')) 	//ջ��Ϊ'('  && ���ʽ��ǰֵ��Ϊ ')'
				{
					Push(s_opt, opt[i]);	//��������ջ
					i++;
					continue;	//������һ��ѭ��
				}
				//	2����������ջ����	
				if (Priority(opt[i]) <= Priority(GetTop(s_opt)) 	//���ʽ���������ȼ� <= ջ�����������ȼ�
					|| (opt[i] == '0' && EmptyStack(s_opt) != TRUE) 	//���ʽΪ�� && ������ջ��Ϊ��
					|| opt[i] == ')')	//���ʽΪ')'
				{
					num1 = Pop(s_num);	//����ջ����ջ
					num2 = Pop(s_num);	//����ջ�ڶ������ֳ�ջ
					switch (Pop(s_opt))	//�����������ǰ
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
						// i++;			//�ڲ�������ջʱ�Ѿ��Լ�
						// continue;
				}
			}
		}

		printf("Result = %d\n", GetTop(s_num));
	}
	return 0;
}
