#include<stdio.h>

void searchInterface(void) {
	//�Ͽյ�
	for (int i = 0; i < 12; i++)
		printf("\n");

	//�Ϸֽ�� 
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n\n");

	//Ŀ¼
	printf("\t\t\t   1--���̶�ʱ���ѯ  2--����������β�ѯ  3--�����׽���ѯ\n\n\t\t\t   4--��ɾ����¼��ѯ������Ա���д����)  5--����������\n\n");

	//�·ֽ��
	printf("\t\t\t");
	for (int i = 0; i < 61; i++)
		printf("*");
	printf("\n");
}

